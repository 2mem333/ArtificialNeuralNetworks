#pragma once
#include <iostream>
#include <math.h>
#include <fstream>

/*
!!!!!!!!!!!! WARNING !!!!!!!!!!!!!

PERPECTION OGRENME KURALI EGER ORNEK LABELLAR
-1 VEYA 1 ISE ÇALIÞIR...

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


/*
MATRIS TEMSILI

eleman sayisi (hucre) boyutunda matris acilir.
inputlari sutun þeklinde tek bir matris halinde gosteririrz.

dimension kadar satir.
input kadar sutun olur.

a indeksli matrise erismek icin, ornegin 2 boyutlu ise

matris[a] , matris[a + inputSayisi] //bi satir asagi ineriz.

boyut
*/

//#define DEBUG

#ifdef DEBUG
#define DLOG(msg) std::cout << msg 
#else
#define DLOG(msg)
#endif

class PERPECTION_Neuron {
private:
	float* weights;
	float* inputs;
	int inputCount;
	float bias = 0;
	int dimension;
	float lc = 0.5;


public:
	//FIRST ONE SHOWS DIMENSION
	//SECONDE ONE SHOWS INPUT COUNTS
	//LAST ONE IS LEARNING CONSTANT
	PERPECTION_Neuron(int d, int ic, float learningC)
	{
		dimension = d;
		inputCount = ic;
		weights = new float[d];
		lc = learningC;
	}
	void initializeWeights()
	{
		for(int d = 0; d < dimension; d++)
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

	int functionSGN(float net)
	{
		return net > 0 ? 1 : -1;
	}
	int startLearning()
	{
		int iterationCycle = 0;
		bool isFinished = false;

		while (iterationCycle < 10000 && !isFinished) {
			DLOG("! Iteration: " << iterationCycle + 1 << "\n");
			int global_error = 0;
			for (int inputInd = 0; inputInd < inputCount; inputInd++)
			{
				DLOG("! Selected input: " << inputInd << "\n");
				//CALCULATING NET 
				float netValue = 0;
				for (int i = 0; i < dimension; i++)
					netValue += weights[i] * inputs[inputInd + i * inputCount];

				netValue += bias;

				DLOG("! Net value: " << netValue << "\n");

				//OBTAINING OUTPUT
				float output = functionSGN(netValue);
				DLOG("! Output: " << output << "\n");

				//CALCULATING ERROR
				int desired;  //ETIKETLERI 0 ILE 1 ARASINA CEKER
				if (inputs[inputInd + dimension * inputCount] == 0)
					desired = 1;
				else
					desired = -1;

				int error = desired - output; //DESIRED - OUTPUT olmak zorunda

				DLOG("! Desired: " << inputs[inputInd + (dimension)*inputCount] << "\n");
				DLOG("! Error: " << error << "\n");

				//UPDATE WEIGHTS & BIAS
				for (int i = 0; i < dimension; i++)
					weights[i] += lc * error * inputs[inputInd + i * inputCount];

				bias += lc * error;

				global_error += abs(error);
			}

			if (global_error == 0)
				isFinished = true;
			else
				iterationCycle++;
		}

		return iterationCycle;
	}

	float *returnWeights()
	{
		return weights;
	}
	float *returnBias()
	{
		float* b = new float; //heapda yeni pointer oluþturur.
		*b = bias;

		return b;
	}
};
