#pragma once
#pragma once
#include <iostream>


//#define DEBUG
#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif

#define euler 2.718281828459045


class MultiLayerNetwork {
public:

	int layerCount; //SHOWS HOW MANY H.LAYER THERE WILL BE
	int* LayerNeuronCounts; // ALSO HOW MUCH NEURON WILL BE USED FOR EACH LAYER.

	int* LayerSizes;
	int* LayerStartsInd; //neurons dizisi icinde her bir layerin start indeksi
	int* LayerBStartInd;

	float totalHnSize;
	float totalBiasSize;

	float* Neurons;
	float* bias;

	float* inputs;
	int dimension;
	int inputCount;
	int addedInputCount = 0;

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

		inputs = new float[ic * (dim + 1)];
		dimension = dim;
		inputCount = ic;
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

	void saveWeights()
	{
		std::ofstream file("weight_values(multilayer).txt");
		for (int i = 0; i < totalHnSize; i++)
			file << Neurons[i] << "\n";
		file << "END\n";

		for (int i = 0; i < totalBiasSize; i++)
			file << bias[i] << "\n";
		file << "END\n";

		file.close();
	}

	void giveInputs(float* inp)
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

	void initializeArray(float* array, int size)
	{
		for (int i = 0; i < size; i++)
			array[i] = 0;
	}

	int predict(float* input)
	{

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

		int minVal = LayerBStartInd[0];
		int min = 0;

		for (int o = 1; o < LayerNeuronCounts[outputLayer]; o++) {
			int indeks = o + LayerBStartInd[outputLayer];
			if (fnet[indeks] > minVal)
			{
				min = o;
				minVal = fnet[indeks];
			}
			std::cout << o << ": " << fnet[indeks] << "\n";
		}
		return min;

	}

	int StartLearning(float minErr, float maxEpoch, float lc)
	{
		if (layerCount < 2)
			return -1;

		bool isFinished = false;
		float totalErr = 0;

		float* net = new float[totalBiasSize];
		float* fnet = new float[totalBiasSize];
		float* fnetDer = new float[totalBiasSize];
		float* errors = new float[totalBiasSize];

		int cycle = 0;
		while (cycle < maxEpoch && !isFinished) //error fix.
		{
			totalErr = 0;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{

				//FIRST LAYER FF
				for (int ni = 0; ni < LayerNeuronCounts[0]; ni++)
				{
					int indeks = ni + LayerBStartInd[0]; //ilk layerin bias indeksi

					net[indeks] = 0;
					for (int d = 0; d < dimension; d++)
						net[indeks] += inputs[inputInd + inputCount * d] * Neurons[ni + LayerNeuronCounts[0] * d];

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

					//outputtaki cikis noronlari targetleri vermeli. 2 class varsa 2 output noronu olcak
					float desired = -1;
					if (inputs[inputInd + dimension * inputCount] == ni) //ERROR FIX
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
							errors[ind] += errors[nn + LayerBStartInd[layer + 1]] *
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
							inputs[inputInd + inputCount * d] *
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
				std::cout << totalErr / inputCount << " err\n";
				cycle++;
			}
		}

		std::cout << "Finished in " << cycle << " cycle, with " << totalErr / inputCount << " error.\n";
		return cycle;
	}

	void loadWeights(std::ifstream& file) {
		if (!file.is_open()) {
			std::cout << "File could not be opened!\n";
			return;
		}

		std::string line;
		float value;

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
};