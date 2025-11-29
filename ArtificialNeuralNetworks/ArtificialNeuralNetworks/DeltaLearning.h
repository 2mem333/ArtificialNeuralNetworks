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


class DeltaLearning_Neuron {
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
	DeltaLearning_Neuron(int d, int ic, float learningC)
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
			weights[d] = 0.5f;

		bias = 1;
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
		std::cout << "-------WEIGHTS-----\n";
		for (int ind = 0; ind < dimension; ind++)
		{
			std::cout << "W" << ind << ": " << weights[ind] << "\n";
		}
		std::cout << "BIAS: " << bias << "\n";
		std::cout << "-------------------\n";
	}


	float sigmoidBipolar(float x, float lambda = 1)
	{
		return (2.0f / (1.0f + exp(-x))) - 1;
	}

	float sigmoidBipolarDerivative(float y) {
		return 0.5f * (1.0f - y * y);
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

	int startLearning() {
		int iterationCycle = 1;
		bool isFinished = false;

		float* norm_Samples = normalizeInputs();

		while (iterationCycle < 100000 && !isFinished) {
			float global_error = 0.0f;

			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				//CALULATING NET
				float netValue = 0;
				for (int i = 0; i < dimension; i++)
					netValue += weights[i] * norm_Samples[inputInd + i * inputCount];

				netValue += bias;
				DLOG("net: " << netValue << "\n");

				//CALCULATING OUTPUT USING SIGMOID BIPOLAR
				float output = sigmoidBipolar(netValue);

				DLOG("Output: " << output << "\n");
				//CALCULATING OUTPUT OF USING SIGMOID BIPOLAR DERIVATIVE
				float doutput = sigmoidBipolarDerivative(output);

				//CALCULATING ERROR
				float desired;  //ETIKETLERI 0 ILE 1 ARASINA CEKER
				if (inputs[inputInd + dimension * inputCount] == 0)
					desired = 1;
				else
					desired = -1;

				float error = desired - output;

				DLOG("desi " << inputs[inputInd + (dimension)*inputCount] << "\n");
				DLOG("Error " << error << "\n");

				//UPDATING WEIGTHS
				for (int i = 0; i < dimension; i++)
					weights[i] += lc * error * doutput * norm_Samples[inputInd + i * inputCount];

				bias += lc * error * doutput;

				global_error += error * error * 0.5f;

			}

			DLOG("Iteration: " << iterationCycle << " Error: " << global_error << "\n");
			if (global_error < 0.01f) {
				DLOG("globalerr " << global_error << "\n");
				isFinished = true;
			}
			else {
				iterationCycle++;
			}
		}

		return iterationCycle;
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

	float *returnBias()
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
