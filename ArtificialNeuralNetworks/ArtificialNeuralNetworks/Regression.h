#pragma once
#include <iostream>
#include <math.h>
#include <fstream>

//#define DEBUG
#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif

#define euler 2.718281828459045


class Regression_Neuron {
private:
	float* weights;
	float* inputs;
	int inputCount;
	float bias = 0;
	int dimension;
	float lc = 0.1f;

	float* mean;
	float* std;

public:
	Regression_Neuron(int d, int ic, float learningC)
	{
		dimension = d;
		inputCount = ic;
		weights = new float[d];
		inputs = new float[ic * (d + 1)];
		lc = learningC;

		mean = new float[dimension];
		std = new float[dimension];
	}

	void initializeWeights()
	{
		for (int d = 0; d < dimension; d++)
			weights[d] = ((float)rand() / RAND_MAX) * 0.2f - 0.1f;

		bias = 0.4f;
	}

	void giveInputs(float* inp)
	{
		inputs = inp;
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

	int startRegression(float maxEpoch,float minErr ) {
		std::cout << "Starting regression!\n";
		float totalErr = 0.0f;
		bool isFinished = false;
		int cycle = 0;

		float *normalizedInputs = normalizeInputs();

		while (!isFinished && cycle < maxEpoch)
		{
			totalErr = 0.0f;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				float net = 0.0f;
				for (int d = 0; d < dimension; d++) {
					//std::cout << "d: " << weights[d] << "  " << inputs[inputInd + d * inputCount] << "\n";
					net += weights[d] * normalizedInputs[inputInd + d * inputCount];
				}
				net += bias;

				float output = net; //lineer aktivasyon
				float error = inputs[inputInd + dimension * inputCount] - output;
		
				//std::cout << "derror: " << error << "\n";
				totalErr += error * error;

				for (int d = 0; d < dimension; d++)
					weights[d] += lc * error * normalizedInputs[inputInd + d * inputCount];
				bias += lc * error;
			}
			totalErr /= (2.0f * inputCount);
			std::cout << "T: " << totalErr << "\n";
			if (totalErr < minErr) //min err < 0.0001f olmali etkili sonuclar icin.
			{
				isFinished = true;
				std::cout << "finished!  " << cycle << "\n";
				return cycle;
			}
			else {
				cycle++;
			}
		}
	}

	float* returnWeights()
	{
		//MEVCUT AGIRLIKLAR NORMALIZE EDILMIS UZAY ICIN OLDUGUNDAN
		//AGIRLIRKLARI DENORMALIZE UZAYA GORE AYARLAR..

		float* orgWeights = new float[dimension];
		for (int d = 0; d < dimension; d++)
		{
			orgWeights[d] = weights[d] / std[d];
			std::cout << "org weigth " << orgWeights[d] << "\n";
		}

		return orgWeights;
	}

	float* returnBias()
	{
		float* orgBias = new float;
		*orgBias = bias;
		for (int d = 0; d < dimension; d++)
		{
			*orgBias -= weights[d] * mean[d] / std[d];
		}
		std::cout << "new bias: " << *orgBias << "\n";
		return orgBias;
	}
};
