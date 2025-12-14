#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "dataStruct.h"

//#define DEBUG
#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif


class Regression {
public:

	float* hiddenNeuron;
	int hnCount; //hidden neuron count
	float* hbias; //hidden neuron bias
	float hLC;

	float* outputNeuron;
	float* obias; //output neuron bias
	int onCount; //output neuron count
	float oLC;

	int dimension = 1;
	int inputCount;

	info i;

	float* mean;
	float* std;

	float* inputs;

	//BOYUT, GIRIS SAYISI, ARA KATMAN NORON SAYISI, CIKIS NORON SAYISI
	Regression(int ic, int ak, float hlc, float olc)
	{

		hiddenNeuron = new float[ak * dimension];
		hnCount = ak;
		hbias = new float[ak];
		hLC = hlc;

		outputNeuron = new float[1 * ak]; //her output nöronu, hidden layerdaki nöron sayýsý kadar aðýrlýk alýr.
		onCount = 1;
		obias = new float[1];
		oLC = olc;

		dimension = dimension; //input dimension
		inputCount = ic;


		mean = new float[dimension + 1]; //Y DEGERINI DE NORMALIZE ETMEK ICIN EKLEDIK
		std = new float[dimension + 1];

		inputs = new float[ic * (3)]; //X Y VE DESIRED DEGER OLARAK INPUT'LARI MAINFORM'DAN ALIRIZ.
		//not (desired degerler kullanilmayacak)
	}

	int addedInputCount = 0;
	void addInput(float* inp)
	{
		if (addedInputCount == inputCount)
			return;

		for (int i = 0; i < dimension + 1; i++)
		{
			inputs[i * inputCount + addedInputCount] = inp[i];
		}
		addedInputCount++;
	}

	void readInputs(std::ifstream& file)
	{
		float* input = new float[dimension + 1]; //last one is for label.
		std::string line;

		while (std::getline(file, line)) {
			std::stringstream ss(line);

			for (int d = 0; d < dimension + 1; d++)
			{
				ss >> input[d];
			}

			addInput(input);
		}
		delete[] input;

	}

	//ARA KATMAN AÐIRLIKLARI RANDOM BAÞLATILMALI
	//EÐER HEPSÝ AYNI KALIRSA, AYNI INPUT,TUREV,GRADYANT YUZUNDEN NORONLARIN AGIRLIKLARI HEP AYNI OLUR
	void initializeWeights()
	{
		for (int i = 0; i < hnCount * dimension; i++)
			hiddenNeuron[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;

		for (int i = 0; i < onCount * hnCount; i++)
			outputNeuron[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;
	}
	void initializeBias()
	{
		for (int i = 0; i < hnCount; i++)
			hbias[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;

		for (int i = 0; i < onCount; i++)
			obias[i] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;
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

	void printWeights()
	{
		std::cout << "-------HIDDEN LAYER WEIGHTS-----\n";
		for (int HneuronIndeks = 0; HneuronIndeks < hnCount; HneuronIndeks++)
		{
			for (int ind = 0; ind < dimension; ind++)
			{
				std::cout << "W" << ind << ": " << hiddenNeuron[HneuronIndeks + ind * hnCount] << "   ";
			}
			std::cout << "BIAS: " << hbias[HneuronIndeks] << "\n";
		}
		std::cout << "-------------------\n";

		std::cout << "-------OUTPUT LAYER WEIGHTS-----\n";
		for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
		{
			for (int ind = 0; ind < hnCount; ind++)
			{
				std::cout << "W" << ind << ": " << outputNeuron[OneuronIndeks + ind * onCount] << "   ";
			}
			std::cout << "BIAS: " << obias[OneuronIndeks] << "\n";
		}
		std::cout << "-------------------\n";
	}

	void denormalizeWeights()
	{
		for (int neuronInd = 0; neuronInd < hnCount; neuronInd++) {
			for (int d = 0; d < dimension; d++)
			{
				hbias[neuronInd] -= hiddenNeuron[neuronInd + hnCount * d] * mean[d] / std[d];
				hiddenNeuron[neuronInd + hnCount * d] = hiddenNeuron[neuronInd + hnCount * d] / std[d];
			}
		}
		std::cout << "Hidden layer weigths are denormalized\n";
	}

	float* normalizeInputs()
	{
		int tempDim = dimension + 1; //X VE Y DEGERLERINI NORMALIZE ETMEK ICIN, NORMALDE DIM = 1 oluyor.

		float* normalized = new float[inputCount * tempDim];

		for (int i = 0; i < tempDim; i++)
		{
			mean[i] = 0.0f;
			for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++)
			{
				mean[i] += inputs[inputIndeks + i * inputCount];
			}
			mean[i] /= inputCount;
		}

		//CALCULATE STANDART VARIATION
		for (int i = 0; i < tempDim; i++) {
			std[i] = 0.0f;
			for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++) {
				float diff = inputs[inputIndeks + i * inputCount] - mean[i];
				std[i] += diff * diff;
			}
			std[i] = sqrt(std[i] / inputCount);
			if (std[i] < 0.0001f) std[i] = 1.0f; // Sýfýr bölme hatasýný önle
		}

		//APPLY NORMALIZATION
		for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++) {
			for (int i = 0; i < tempDim; i++) {
				normalized[inputIndeks + i * inputCount] = (inputs[inputIndeks + i * inputCount] - mean[i]) / std[i];
			}
		}

		return normalized;
	}

	void initializeArray(float* array, int size)
	{
		for (int i = 0; i < size; i++)
			array[i] = 0;
	}

	int predict(int x)
	{
		float* Hnet = new float[hnCount];
		float* Hfnet = new float[hnCount];

		float* Onet = new float[onCount];

		for (int hNeuronIndeks = 0; hNeuronIndeks < hnCount; hNeuronIndeks++)
		{
			Hnet[hNeuronIndeks] = 0.0f;

			for (int d = 0; d < dimension; d++)
				Hnet[hNeuronIndeks] += hiddenNeuron[hNeuronIndeks + d * hnCount] * x;

			Hnet[hNeuronIndeks] += hbias[hNeuronIndeks];
			Hfnet[hNeuronIndeks] = (2.0f / (1.0f + exp(-Hnet[hNeuronIndeks]))) - 1.0f;
		}

		for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
		{
			Onet[OneuronIndeks] = 0.0f;

			for (int h = 0; h < hnCount; h++)
				Onet[OneuronIndeks] += outputNeuron[OneuronIndeks + h * onCount] * Hfnet[h];

			Onet[OneuronIndeks] += obias[OneuronIndeks];
		}


		return Onet[0] * std[1] + mean[1];
	}

	info StartLearning(float minErr, float maxEpoch)
	{
		float* HNnet = new float[hnCount];
		float* HNfnet = new float[hnCount];
		float* HNfnetDer = new float[hnCount];

		float* ONnet = new float[onCount];
		float* ONfnet = new float[onCount];
		float* ONfnetDer = new float[onCount];
		float* errors = new float[onCount];
		
		float* errorList = new float[maxEpoch];

		float* normalizedSamples = normalizeInputs();


		int cycle = 0;
		bool isFinished = false;
		float totalErr = 0;
		auto zamanbaslangic = std::chrono::high_resolution_clock::now();
		while (!isFinished && cycle != maxEpoch) {
			totalErr = 0;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				initializeArray(errors, onCount);
				initializeArray(HNnet, hnCount);
				initializeArray(ONnet, onCount);
				for (int HneuronIndeks = 0; HneuronIndeks < hnCount; HneuronIndeks++)
				{
					for (int d = 0; d < dimension; d++)
						HNnet[HneuronIndeks] += normalizedSamples[inputInd + inputCount * d] * hiddenNeuron[hnCount * d + HneuronIndeks];

					HNnet[HneuronIndeks] += hbias[HneuronIndeks];

					//Tanh(x) activation function
					HNfnet[HneuronIndeks] = ((2.0f / ((float)1.0f + exp(-HNnet[HneuronIndeks]))) - 1.0f);
					HNfnetDer[HneuronIndeks] = (0.5f * (1.0f - HNfnet[HneuronIndeks] * HNfnet[HneuronIndeks]));
				}

				for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
				{
					for (int HneuronIndeks = 0; HneuronIndeks < hnCount; HneuronIndeks++) //??? bir ustte olabilir.
						ONnet[OneuronIndeks] += HNfnet[HneuronIndeks] * outputNeuron[onCount * HneuronIndeks + OneuronIndeks];

					ONnet[OneuronIndeks] += obias[OneuronIndeks];

					ONfnet[OneuronIndeks] = ONnet[OneuronIndeks];
					ONfnetDer[OneuronIndeks] = 1;
				}

				//CALCULATE ERROR
				for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
				{
					float desired = normalizedSamples[inputInd + 1 * inputCount];
					errors[OneuronIndeks] = desired - ONfnet[OneuronIndeks];
					totalErr += errors[OneuronIndeks] * errors[OneuronIndeks] * 0.5f;
				}

				//UPDATE WEIGHTS FOR OUTPUT NEURON
				for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
				{
					for (int d = 0; d < hnCount; d++)
					{
						// d burada hidden neuron indeksi!
						outputNeuron[OneuronIndeks + d * onCount] +=
							oLC *
							errors[OneuronIndeks] *
							ONfnetDer[OneuronIndeks] *
							HNfnet[d];
					}

					obias[OneuronIndeks] +=
						oLC *
						errors[OneuronIndeks] *
						ONfnetDer[OneuronIndeks];
				}

				//UPDATE WEIGHTS FOR HIDDEN LAYER NEURON
				for (int HneuronIndeks = 0; HneuronIndeks < hnCount; HneuronIndeks++)
				{
					float sum = 0.0f;

					// Sadece output loop (dimension burada YANLIÞ olurdu)
					for (int OneuronIndeks = 0; OneuronIndeks < onCount; OneuronIndeks++)
						sum += errors[OneuronIndeks] * ONfnetDer[OneuronIndeks] * outputNeuron[OneuronIndeks + HneuronIndeks * onCount];


					for (int d = 0; d < dimension; d++)
					{
						hiddenNeuron[HneuronIndeks + d * hnCount] +=
							hLC *
							sum *
							HNfnetDer[HneuronIndeks] *
							normalizedSamples[inputInd + d * inputCount];
					}

					hbias[HneuronIndeks] +=
						hLC *
						sum *
						HNfnetDer[HneuronIndeks];
				}

			}

			if (totalErr / inputCount < minErr) {
				isFinished = true;
				std::cout << "Finished in " << cycle << " cycle!!\n";
				std::cout << "Error: " << totalErr / inputCount << "\n";
			}
			else
			{
				errorList[cycle] = totalErr / inputCount;
				cycle++;
			}
		}

		std::cout << "Unsucessfully finished in " << cycle << " cycle!!\n";
		std::cout << "Error: " << totalErr / inputCount << "\n";
		auto zamanbitis = std::chrono::high_resolution_clock::now();
		auto toplam_zaman = std::chrono::duration_cast<std::chrono::nanoseconds>(zamanbitis - zamanbaslangic);
		double islemsuresi = toplam_zaman.count() * 0.000000001;

		i.error = totalErr / inputCount;
		i.cycle = cycle;
		i.time = islemsuresi;
		i.errorList = errorList;
		return i;
	}
};