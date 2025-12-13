#pragma once

struct NeuronStruct {
	int* LayerNeuronCounts;
	int layerCount;

	float* Neurons;
	float* bias;

	int* LayerSizes;
	int* LayerStartsInd; //neurons dizisi icinde her bir layerin start indeksi
	int* LayerBStartInd;

	float totalHnSize;
	float totalBiasSize;

	int dimension;

	float* mean;
	float* std;

	bool weightsLoaded = false;

	void initialize(int dim)
	{
		LayerSizes = new int[layerCount];
		LayerStartsInd = new int[layerCount];
		LayerBStartInd = new int[layerCount];

		LayerSizes[0] = dim * LayerNeuronCounts[0];
		totalHnSize = LayerSizes[0];
		totalBiasSize = LayerNeuronCounts[0];
		LayerStartsInd[0] = 0;
		LayerBStartInd[0] = 0;


		for (int layer = 1; layer < layerCount; layer++)
		{
			LayerSizes[layer] = LayerNeuronCounts[layer - 1] * LayerNeuronCounts[layer];

			LayerStartsInd[layer] = totalHnSize;
			totalHnSize += LayerSizes[layer];
			LayerBStartInd[layer] = totalBiasSize;
			totalBiasSize += LayerNeuronCounts[layer];

		}

		Neurons = new float[totalHnSize];
		bias = new float[totalBiasSize];

		mean = new float[dim];
		std = new float[dim];

		dimension = dim;
	}

	void deinit()
	{
		delete[] mean; mean = nullptr;
		delete[] std; std = nullptr;
		delete[] LayerSizes; LayerSizes = nullptr;
		delete[] LayerStartsInd; LayerStartsInd = nullptr;
		delete[] LayerBStartInd; LayerBStartInd = nullptr;
		delete[]LayerNeuronCounts; LayerNeuronCounts = nullptr;

		delete[] Neurons; Neurons = nullptr;
		delete[] bias; bias = nullptr;
	}

};