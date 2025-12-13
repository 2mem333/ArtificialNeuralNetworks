#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <csignal>

//#define DEBUG
#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif

#define euler 2.718281828459045


class MultiLayerNetwork {
public:

	static volatile bool stopTraining;
	static void handleCtrlC(int s);

	int layerCount; //SHOWS HOW MANY H.LAYER THERE WILL BE
	int* LayerNeuronCounts; // ALSO HOW MUCH NEURON WILL BE USED FOR EACH LAYER.

	int* LayerSizes;
	int* LayerStartsInd; //neurons dizisi icinde her bir layerin start indeksi
	int* LayerBStartInd;

	float totalHnSize;
	float totalBiasSize;

	float* Neurons;
	float* bias;

	std::vector<uint8_t> inputs; //DAHA AZ YER KAPLAMASI ICIN UINT_8 formatýnda tutuyorum
	int dimension;
	int inputCount;
	int addedInputCount = 0;

	float* mean;
	float* std;

	//BOYUT, GIRIS SAYISI, ARA KATMAN NORON SAYISI, CIKIS NORON SAYISI
	MultiLayerNetwork(int hlCount, int* hNCounts, int dim, int ic)
	{
		layerCount = hlCount;
		LayerNeuronCounts = hNCounts;
		LayerSizes = new int[hlCount];
		LayerStartsInd = new int[hlCount];
		LayerBStartInd = new int[hlCount];

		LayerSizes[0] = dim * hNCounts[0];
		totalHnSize = LayerSizes[0];
		totalBiasSize = hNCounts[0];
		LayerStartsInd[0] = 0;
		LayerBStartInd[0] = 0;


		for (int layer = 1; layer < layerCount; layer++)
		{
			LayerSizes[layer] = hNCounts[layer - 1] * hNCounts[layer];

			LayerStartsInd[layer] = totalHnSize;
			totalHnSize += LayerSizes[layer];

			LayerBStartInd[layer] = totalBiasSize;
			totalBiasSize += hNCounts[layer];

		}

		Neurons = new float[totalHnSize];
		bias = new float[totalBiasSize];

		dimension = dim;
		inputCount = ic;
		mean = new float[dim];
		std = new float[dim];
	}

	~MultiLayerNetwork()
	{
		delete[] LayerSizes;
		delete[] LayerStartsInd;
		delete[] LayerBStartInd;
		delete[] Neurons;
		delete[] bias;
		delete[] mean;
		delete[] std;
	}

	void showStatus()
	{
		std::cout << "Hidden layer count: " << layerCount << "\n";
		std::cout << "Bias array size: " << totalBiasSize << "\n";
		std::cout << "Neuron array size: " << totalHnSize << "\n\n";

		for (int layer = 0; layer < layerCount; layer++)
		{
			std::cout << "Layer " << layer << ": " << LayerStartsInd[layer] << "   " <<
				LayerSizes[layer] + LayerStartsInd[layer] - 1 << "\n";
			std::cout << "Neuron Count: " << LayerNeuronCounts[layer] << "\n";
			std::cout << "Bias start ind: " << LayerBStartInd[layer] << "\n\n";
		}

	}

	//AÐIRLIKLARIN DEÐERLERÝ RANDOM BAÞLATILMALI
	//EÐER HEPSÝ AYNI KALIRSA, AYNI INPUT,TUREV,GRADYANT YUZUNDEN NORONLARIN AGIRLIKLARI HEP AYNI OLUR
	void initializeWeights()
	{
		for (int i = 0; i < totalHnSize; i++)
		{
			Neurons[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;
		}
	}
	void initializeBias()
	{
		for (int i = 0; i < totalBiasSize; i++)
		{
			bias[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;
		}
	}

	void giveInputs(std::vector<uint8_t> inp)
	{
		inputs = inp;
	}
	void printInputs()
	{
		std::cout << "-------INPUTS-----\n";
		for (int ind = 0; ind < inputCount; ind++)
		{
			for (int d = 0; d < dimension + 1; d++)
			{
				std::cout << inputs[ind + d * inputCount] << "  ";
			}
			std::cout << "\n";
		}
		std::cout << "-------------------\n";
	}

	float* normalizeInputs()
	{
		float* normalized = new float[inputCount * dimension];

		//CALCULATE MEAN
		for (int i = 0; i < dimension; i++)
		{
			mean[i] = 0.0f;
			for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++)
			{
				mean[i] += (int)inputs[i + inputIndeks * (dimension + 1)];
			}
			mean[i] /= inputCount;
		}

		//CALCULATE STANDART VARIATION
		for (int i = 0; i < dimension; i++) {
			std[i] = 0.0f;
			for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++) {
				float diff = (int)inputs[i + inputIndeks * (dimension + 1)] - mean[i];
				std[i] += diff * diff;
			}
			std[i] = sqrt(std[i] / inputCount);
			if (std[i] < 0.0001f) std[i] = 1.0f; // Sýfýr bölme hatasýný önle
		}

		//APPLY NORMALIZATION
		for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++) {
			for (int i = 0; i < dimension; i++) {
				//burada normalized inputunu kendi veri yapýmýz olan matrise çeviririz...
				normalized[inputIndeks + i * inputCount] = ((int)inputs[i + inputIndeks * (dimension + 1)] - mean[i]) / std[i];
			}
		}

		return normalized;
	}

	void initializeArray(float* array, int size)
	{
		for (int i = 0; i < size; i++)
			array[i] = 0;
	}

	void saveWeights()
	{
		std::ofstream file("weight_values.txt");

		file << dimension << "\n";
		file << layerCount << "\n";
		for (int i = 0; i < layerCount; i++)
		{
			file << LayerNeuronCounts[i] << "\n";
		}

		for (int d = 0; d < dimension; d++)
		{
			file << mean[d] << "\n";
			file << std[d] << "\n";
		}
		file << "END\n";

		for (int i = 0; i < totalHnSize; i++)
			file << Neurons[i] << "\n";
		file << "END\n";

		for (int i = 0; i < totalBiasSize; i++)
			file << bias[i] << "\n";
		file << "END\n";

		file.close();
	}

	void loadWeights(std::ifstream& file) {
		if (!file.is_open()) {
			std::cout << "File could not be opened!\n";
			return;
		}

		std::string line;
		float value;

		//SKIP LAYER,DIM INFORMATIONS
		std::getline(file, line);
		std::getline(file, line);
		int layerCount = std::stof(line);

		for (int i = 0; i < layerCount; i++) {
			std::getline(file, line);
		}

		// ---- WEIGHTS ----
		for (int i = 0; i < totalHnSize; i++) {
			if (!std::getline(file, line)) break;
			value = std::stof(line);
			Neurons[i] = value;
		}

		// Skip END line
		std::getline(file, line);
		if (line == "END")
			std::cout << "Weights read.\n";

		// ---- BIASES ----
		for (int i = 0; i < totalBiasSize; i++) {
			if (!std::getline(file, line)) break;
			value = std::stof(line);
			bias[i] = value;
		}

		// Skip END line
		std::getline(file, line);
		if (line == "END")
			std::cout << "Bias read.\n";

		std::cout << "Done reading weights!\n";
	}

	/*
!!!!!!!!!!!!! WARNING  !!!!!!!!!!!!
THE INPUT'S MATRIS DESIGN WHICH GIVEN TO THE PREDICT FUNCTION IS DIFFERENT THAN THIS CLASS'S.
		*/
	void predict(float* input)
	{

		for (int d = 0; d < dimension; d++) //normalize input
			input[d] = (input[d] - mean[d]) / std[d];


		float* net = new float[totalBiasSize];
		float* fnet = new float[totalBiasSize];

		//FIRST LAYER FF
		for (int ni = 0; ni < LayerNeuronCounts[0]; ni++)
		{
			int indeks = ni + LayerBStartInd[0]; //ilk layerin bias indeksi

			net[indeks] = 0;
			for (int d = 0; d < dimension; d++)
				net[indeks] += input[d] * Neurons[ni + LayerNeuronCounts[0] * d];

			net[indeks] += bias[indeks];

			fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
		}

		//NEXT LAYERS FF
		for (int layer = 1; layer < layerCount; layer++)
		{
			for (int ni = 0; ni < LayerNeuronCounts[layer]; ni++)
			{
				int indeks = ni + LayerBStartInd[layer];

				net[indeks] = 0;
				for (int d = 0; d < LayerNeuronCounts[layer - 1]; d++) //ERROR FIX
					net[indeks] += fnet[d + LayerBStartInd[layer - 1]] //onceki katmanin aktivasyonu
					*
					Neurons[ni + LayerNeuronCounts[layer] * d + LayerStartsInd[layer]];//ni + neuroncount*d + baþlangýç offset

				net[indeks] += bias[indeks];
				fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
			}
		}


		int outputLayer = layerCount - 1;

		for (int o = 0; o < LayerNeuronCounts[outputLayer]; o++) {
			int indeks = o + LayerBStartInd[outputLayer];
			std::cout << o << ": " << fnet[indeks] << "\n";
		}

	}

	int StartLearning(float minErr, float maxEpoch, float lc) 
	{
		if (layerCount < 2)
			return -1;

		float* normalizedSamples = normalizeInputs();

		bool isFinished = false;
		float totalErr = 0;

		float* net = new float[totalBiasSize];
		float* fnet = new float[totalBiasSize];
		float* fnetDer = new float[totalBiasSize];
		float* errors = new float[totalBiasSize];

		int cycle = 0;

		while (cycle < 10000 && cycle < maxEpoch && !isFinished && !stopTraining)
		{
			totalErr = 0;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				//initializeArray(errors, totalBiasSize);
				//initializeArray(fnetDer, totalBiasSize);
				//initializeArray(fnet, totalBiasSize);
				//initializeArray(net, totalBiasSize);

				//FIRST LAYER FF
				for (int ni = 0; ni < LayerNeuronCounts[0]; ni++)
				{
					int indeks = ni + LayerBStartInd[0]; //ilk layerin bias indeksi

					net[indeks] = 0;
					for (int d = 0; d < dimension; d++)
						net[indeks] += normalizedSamples[inputInd + d * inputCount] * Neurons[ni + LayerNeuronCounts[0] * d];

					net[indeks] += bias[indeks];


					fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
					fnetDer[indeks] = (0.5f * (1.0f - fnet[indeks] * fnet[indeks]));
				}

				//NEXT LAYERS FF
				for (int layer = 1; layer < layerCount; layer++)
				{
					for (int ni = 0; ni < LayerNeuronCounts[layer]; ni++)
					{
						int indeks = ni + LayerBStartInd[layer];

						net[indeks] = 0;
						for (int d = 0; d < LayerNeuronCounts[layer - 1]; d++) //ERROR FIX
							net[indeks] += fnet[d + LayerBStartInd[layer - 1]] //onceki katmanin aktivasyonu
							*
							Neurons[ni + LayerNeuronCounts[layer] * d + LayerStartsInd[layer]];//ni + neuroncount*d + baþlangýç offset

						net[indeks] += bias[indeks];
						fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
						fnetDer[indeks] = (0.5f * (1.0f - fnet[indeks] * fnet[indeks]));
					}
				}

				////CALCULATE ERROR
				int outLayer = layerCount - 1; //select the output layer
				for (int ni = 0; ni < LayerNeuronCounts[outLayer]; ni++)
				{
					int ind = ni + LayerBStartInd[outLayer];

					float desired = -1;
					if ((int)inputs[784 + inputInd * (dimension+1)] == ni) //ERROR FIX, //ERROR FIX2
						desired = 1;

					errors[ind] = desired - fnet[ind];
					totalErr += errors[ind] * errors[ind] * 0.5f;
				}


				//CALCULATE ERROR FOR REMAINING LAYERS
				for (int layer = layerCount - 2; layer > -1; layer--)
				{
					for (int ni = 0; ni < LayerNeuronCounts[layer]; ni++)
					{
						int ind = ni + LayerBStartInd[layer];
						errors[ind] = 0;

						for (int nn = 0; nn < LayerNeuronCounts[layer + 1]; nn++) //next neuron
						{
							errors[ind] += errors[nn + LayerBStartInd[layer + 1]] * //chatgpt buraya hatali dedi
								fnetDer[nn + LayerBStartInd[layer + 1]] *
								Neurons[nn + LayerNeuronCounts[layer + 1] * ni + LayerStartsInd[layer + 1]];
						}

					}
				}


				//OUTPUT LAYER FB
				for (int ni = 0; ni < LayerNeuronCounts[outLayer]; ni++)
				{
					int ind = ni + LayerBStartInd[outLayer];

					for (int pn = 0; pn < LayerNeuronCounts[outLayer - 1]; pn++) //previous neuron indekses
					{
						Neurons[ni + pn * LayerNeuronCounts[outLayer] + LayerStartsInd[outLayer]] +=
							lc *
							errors[ind] *
							fnet[pn + LayerBStartInd[outLayer - 1]] *  //previous neuron's activation
							fnetDer[ind];
					}
					bias[ind] += lc * errors[ind] * fnetDer[ind];
				}

				//REMANINING LAYERS FB
				for (int layer = layerCount - 2; layer != 0; layer--)
				{
					for (int ni = 0; ni < LayerNeuronCounts[layer]; ni++)
					{
						int ind = ni + LayerBStartInd[layer];

						for (int pn = 0; pn < LayerNeuronCounts[layer - 1]; pn++) //previous neuron indekses
						{
							Neurons[ni + pn * LayerNeuronCounts[layer] + LayerStartsInd[layer]] +=
								lc *
								errors[ind] *
								fnet[pn + LayerBStartInd[layer - 1]] *  //previous neuron's activation
								fnetDer[ind];
						}
						bias[ind] += lc * errors[ind] * fnetDer[ind];
					}
				}

				//FIRST LAYER FB
				for (int ni = 0; ni < LayerNeuronCounts[0]; ni++)
				{
					int ind = ni + LayerBStartInd[0];
					for (int d = 0; d < dimension; d++)
					{
						Neurons[ni + LayerNeuronCounts[0] * d] +=
							lc *
							normalizedSamples[inputInd + inputCount * d] *
							fnetDer[ind] *
							errors[ind];
					}
					bias[ind] += lc * errors[ind] * fnetDer[ind];
				}

			}

			if (totalErr / inputCount < minErr)
				isFinished = true;
			else
			{
				std::cout << "Error: " << totalErr / inputCount << "\n";
				cycle++;
			}
		}

		std::cout <<"Finished with error: " << totalErr / inputCount << "\n";
		std::cout << "Total cycle: " << cycle << "\n";

		delete[] net;
		delete[] fnet;
		delete[] fnetDer;
		delete[] errors;

		return cycle;
	}
};