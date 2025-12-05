#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
#include "dataStruct.h"

//#define DEBUG
#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif

#define euler 2.718281828459045



class SingleLayerNetwork {
public:
	float* weights;

	float* inputs;
	int inputCount;
	float* bias;
	int dimension;

	int classCount = 1;

	float lc = 0.05f;

	float* mean;
	float* std;

	SingleLayerNetwork(int d, int ic, int cc)
	{
		classCount = cc;
		dimension = d;
		inputCount = ic;
		inputs = new float[ic * (d + 1)]; //EKSTRADAN 1 BOSLUK, LABEL ÝÇÝN
		weights = new float[cc * d]; //TOPLAMDA CLASS COUNT KADAR NÖRON OLUR
		bias = new float[cc];
	}

	void initializeWeights()
	{
		for (int i = 0; i < classCount * dimension; i++)
			weights[i] = 0.5f;
	}
	void initializeBias()
	{
		for (int i = 0; i < classCount; i++)
			bias[i] = 1;
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
		for (int neuronInd = 0; neuronInd < classCount; neuronInd++) {
			std::cout << "-------WEIGHTS-----\n";
			for (int ind = 0; ind < dimension; ind++)
			{
				std::cout << "W" << ind << ": " << weights[neuronInd + ind * classCount] << "\n";
			}
			std::cout << "BIAS: " << bias[neuronInd] << "\n";
			std::cout << "-------------------\n";
		}
	}


	void giveInputs(float* inp)
	{
		inputs = inp;
	}


	float* normalizeInputs()
	{
		float* normalized = new float[inputCount * dimension];
		mean = new float[dimension];
		std = new float[dimension];

		//CALCULATE MEAN

		for (int i = 0; i < dimension; i++)
		{
			mean[i] = 0.0f;
			for (int inputIndeks = 0; inputIndeks < inputCount; inputIndeks++)
			{
				mean[i] += inputs[inputIndeks + i * inputCount];
			}
			mean[i] /= inputCount;
		}

		//CALCULATE STANDART VARIATION
		for (int i = 0; i < dimension; i++) {
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
			for (int i = 0; i < dimension; i++) {
				normalized[inputIndeks + i * inputCount] = (inputs[inputIndeks + i * inputCount] - mean[i]) / std[i];
			}
		}

		return normalized;
	}

	info StartLearning(float minError, float maxEpoch)
	{

		float* norm_Samples = normalizeInputs();

		float* net = new float[classCount]; //calculate net for every neuron
		float* fnet = new float[classCount]; //calculate net for every neuron
		float* fnetDer = new float[classCount]; //calculate net for every neuron
		float* err = new float[classCount];
		float* delta = new float[classCount];
		float* desired = new float[classCount];


		bool isFinished = false;

		int cycleCount = 0;
		float total_err;

		while (!isFinished) {
			cycleCount++;
			total_err = 0;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				//feedforward
				for (int neuronInd = 0; neuronInd < classCount; neuronInd++)
				{
					net[neuronInd] = 0.0f;
					for (int d = 0; d < dimension; d++)
						net[neuronInd] += norm_Samples[inputCount * d + inputInd] * weights[classCount * d + neuronInd];

					net[neuronInd] += bias[neuronInd];
					fnet[neuronInd] = ((2.0f / ((float)1.0f + exp(-net[neuronInd]))) - 1.0f); //HATALI INFINITY DONDURUYOR
					//fnet[neuronInd] = tanh(net[neuronInd]);

					fnetDer[neuronInd] = (0.5f * (1.0f - fnet[neuronInd] * fnet[neuronInd]));
					//fnetDer[neuronInd] = 1 - fnet[neuronInd] * fnet[neuronInd];
				}

				//backward
				for (int neuronInd = 0; neuronInd < classCount; neuronInd++)
				{
					if (inputs[inputInd + dimension * inputCount] == neuronInd)
						desired[neuronInd] = 1;
					else
						desired[neuronInd] = -1;

					err[neuronInd] = desired[neuronInd] - fnet[neuronInd];
					delta[neuronInd] = lc * err[neuronInd] * fnetDer[neuronInd];

					for (int d = 0; d < dimension; d++)
						weights[classCount * d + neuronInd] += (delta[neuronInd] * norm_Samples[inputInd + d * inputCount]);

					bias[neuronInd] += delta[neuronInd];
					total_err += (0.5f * (err[neuronInd] * err[neuronInd]));

				}
			}
			total_err /= float(classCount * inputCount);

			if (total_err <= minError || cycleCount > maxEpoch)
				isFinished = true;

		}

		return info{ total_err / float(classCount * inputCount), cycleCount, };
	}


	float* returnWeights()
	{
		//MEVCUT AGIRLIKLAR NORMALIZE EDILMIS UZAY ICIN OLDUGUNDAN
		//AGIRLIRKLARI DENORMALIZE UZAYA GORE AYARLAR..

		float* orgWeights = new float[classCount * dimension];
		for (int neuronInd = 0; neuronInd < classCount; neuronInd++) {
			for (int d = 0; d < dimension; d++)
			{
				orgWeights[neuronInd + classCount*d] = weights[neuronInd + classCount * d] / std[d];
			}
		}

		return orgWeights;
	}

	float *returnBias()
	{
		float *orgBias = new float[classCount];
		for (int neuronInd = 0; neuronInd < classCount; neuronInd++) {
			orgBias[neuronInd] = bias[neuronInd];
			for (int d = 0; d < dimension; d++) //[HATA_FIX] normalde inputlarda kayma olabiliyordu nedeni buradaki bias denormalize hatasindanmis.
			{
				orgBias[neuronInd] -= weights[neuronInd + classCount * d] * mean[d] / std[d];
			}
		}
		return orgBias;
	}
};