#include "neuronStruct.h"
#include "math.h"

class PREDICT{
public:
	NeuronStruct* neuron;
	float* input;

	void initialize(float* inp,NeuronStruct* neu)
	{
		input = inp;
		neuron = neu;
	}
	
	float* start_predict()
	{
		float* net = new float[neuron->totalBiasSize];
		float* fnet = new float[neuron->totalBiasSize];

		//FIRST LAYER FF
		for (int ni = 0; ni < neuron->LayerNeuronCounts[0]; ni++)
		{
			int indeks = ni + neuron->LayerBStartInd[0]; //ilk layerin bias indeksi

			net[indeks] = 0;
			for (int d = 0; d < neuron->dimension; d++)
				net[indeks] += input[d] * neuron->Neurons[ni + neuron->LayerNeuronCounts[0] * d];

			net[indeks] += neuron->bias[indeks];

			fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
		}

		//NEXT LAYERS FF
		for (int layer = 1; layer < neuron->layerCount; layer++)
		{
			for (int ni = 0; ni < neuron->LayerNeuronCounts[layer]; ni++)
			{
				int indeks = ni + neuron->LayerBStartInd[layer];

				net[indeks] = 0;
				for (int d = 0; d < neuron->LayerNeuronCounts[layer - 1]; d++) //ERROR FIX
					net[indeks] += fnet[d + neuron->LayerBStartInd[layer - 1]] //onceki katmanin aktivasyonu
					*
					neuron->Neurons[ni + neuron->LayerNeuronCounts[layer] * d + neuron->LayerStartsInd[layer]];//ni + neuroncount*d + baþlangýç offset

				net[indeks] += neuron->bias[indeks];
				fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
			}
		}
		return fnet;
	}
};

float* EncodeInput(float*inp, NeuronStruct* neuron)
{
	int bottleneckLayer = 0; //BUNU NEURON ICERISINDEN CEKMEK GEREKIYOR!!

	float* encodedInput = new float[neuron->LayerNeuronCounts[bottleneckLayer]];

	float* net = new float[neuron->totalBiasSize];
	float* fnet = new float[neuron->totalBiasSize];


	if (bottleneckLayer == 0)
	{
		for (int ni = 0; ni < neuron->LayerNeuronCounts[0]; ni++)
		{
			int indeks = ni + neuron->LayerBStartInd[0]; //ilk layerin bias indeksi

			net[indeks] = 0;
			for (int d = 0; d < neuron->dimension; d++)
				net[indeks] += inp[d] * neuron->Neurons[ni + neuron->LayerNeuronCounts[0] * d];

			net[indeks] += neuron->bias[indeks];
			fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
			encodedInput[ni] = fnet[indeks];

			//std::cout << fnet[indeks] << " ";
		}
	}
	else {
		//FIRST LAYER FF
		for (int ni = 0; ni < neuron->LayerNeuronCounts[0]; ni++)
		{
			int indeks = ni + neuron->LayerBStartInd[0]; //ilk layerin bias indeksi

			net[indeks] = 0;
			for (int d = 0; d < neuron->dimension; d++)
				net[indeks] += inp[d] * neuron->Neurons[ni + neuron->LayerNeuronCounts[0] * d];

			net[indeks] += neuron->bias[indeks];

			fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
		}

		//NEXT LAYERS FF
		for (int layer = 1; layer < bottleneckLayer; layer++) //en son bottleneck layeri alicaz.
		{
			for (int ni = 0; ni < neuron->LayerNeuronCounts[layer]; ni++)
			{
				int indeks = ni + neuron->LayerBStartInd[layer];

				net[indeks] = 0;
				for (int d = 0; d < neuron->LayerNeuronCounts[layer - 1]; d++)
					net[indeks] += fnet[d + neuron->LayerBStartInd[layer - 1]]
					*
					neuron->Neurons[ni + neuron->LayerNeuronCounts[layer] * d + neuron->LayerStartsInd[layer]];

				net[indeks] += neuron->bias[indeks];
				fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
			}
		}

		//BOTTLENECK LAYER FF
		for (int ni = 0; ni < neuron->LayerNeuronCounts[bottleneckLayer]; ni++)
		{
			int indeks = ni + neuron->LayerBStartInd[bottleneckLayer]; //ilk layerin bias indeksi

			net[indeks] = 0;
			for (int d = 0; d < neuron->LayerNeuronCounts[bottleneckLayer - 1]; d++)
				net[indeks] += fnet[d + neuron->LayerBStartInd[bottleneckLayer - 1]]
				*
				neuron->Neurons[ni + neuron->LayerNeuronCounts[bottleneckLayer] * d + neuron->LayerStartsInd[bottleneckLayer]];

			net[indeks] += neuron->bias[indeks];
			fnet[indeks] = ((2.0f / ((float)1.0f + exp(-net[indeks]))) - 1.0f);
			encodedInput[ni] = fnet[indeks];
			//std::cout << fnet[indeks] << " ";
		}
	}

	delete[] net;
	delete[] fnet;
	return encodedInput;
}