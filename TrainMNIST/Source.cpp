#include <iostream>
#include <fstream>

#include <vector>
#include "MultiLayerNetwork.h"

#include <ctime>
#include <chrono>

#include <csignal>

uint32_t readBE(std::ifstream& f) {
    uint8_t b[4];
    f.read((char*)b, 4);
    return (uint32_t(b[0]) << 24) |
        (uint32_t(b[1]) << 16) |
        (uint32_t(b[2]) << 8) |
        uint32_t(b[3]);
}

volatile bool MultiLayerNetwork::stopTraining = false;

void MultiLayerNetwork::handleCtrlC(int s) {
    stopTraining = true;
    std::cout << "\nCTRL+C detected, stopping training...\n";
}


int main()
{
    std::ifstream img("C:\\Users\\negan\\Desktop\\mnist_dataset\\t10k-images.idx3-ubyte", std::ios::binary);
    std::ifstream lbl("C:\\Users\\negan\\Desktop\\mnist_dataset\\t10k-labels.idx1-ubyte", std::ios::binary);

    if (!img || !lbl) {
        std::cout << "Dosya acilamadi\n";
        return 1;
    }

    // ---- HEADERLAR ----
    uint32_t magic_img = readBE(img);
    uint32_t count_img = readBE(img);
    uint32_t rows = readBE(img);
    uint32_t cols = readBE(img);

    uint32_t magic_lbl = readBE(lbl);
    uint32_t count_lbl = readBE(lbl);

    std::cout << "magic_img =" << magic_img << "\n";
    std::cout << "count_img =" << count_img << "\n";
    std::cout << "rows      =" << rows << "\n";
    std::cout << "cols      =" << cols << "\n";
    std::cout << "magic_lbl =" << magic_lbl << "\n";
    std::cout << "count_lbl =" << count_lbl << "\n\n";

    // -----------------------------
    if (magic_img != 2051) { std::cout << "images magic wrong\n"; return 1; }
    if (magic_lbl != 2049) { std::cout << "labels magic wrong\n"; return 1; }
    // -----------------------------

    uint32_t imageSize = rows * cols; // 784 byte

    std::vector<uint8_t> pixels;
    uint8_t pixelBuf[784];
    uint8_t label;

    int inputCount = 10000;

    for (int readedInput = 0; readedInput < inputCount; readedInput++)
    {
        lbl.read((char*)&label, 1);
        if (!lbl) { std::cout << "label read fail\n"; break; }

        img.read((char*)&pixelBuf, 784);
        if (!img) { std::cout << "img read fail\n"; break; }

        for (int p = 0; p < 784; p++) //kendi matris yapýma göre inputu düzenliyorum
            pixels.push_back(pixelBuf[p]);

        pixels.push_back(label);
    }

    int dimension = 784;
    const int layerCount = 2;

    int LayerNeuronCounts[layerCount] = { 64,10};

    float lc = 0.01f;
    float minErr = 0.01f, maxEpoch = 100000;

    //std::ifstream weights("C:\\Users\\negan\\Desktop\\TrainMNIST\\TrainMNIST\\weight_values,64,10.txt");

    //if (!weights)
    //    return -1;

    //std::ifstream inputtxt("C:\\Users\\negan\\Desktop\\TrainMNIST\\TrainMNIST\\input5.txt");

    //if (!inputtxt)
    //    return -1;

    //float input[784];

    //for (int d = 0; d < dimension; d++)
    //{
    //    inputtxt >> input[d];
    //}


    MultiLayerNetwork network(layerCount,LayerNeuronCounts,dimension,inputCount);

    //network.readWeightsFromTxt(weights);
    //network.predict(input);


    network.giveInputs(pixels);
    network.initializeBias();
    network.initializeWeights();

    std::signal(SIGINT, MultiLayerNetwork::handleCtrlC);

    std::cout << "Training has started with values; min error: " << minErr << ",  max epoch: " << maxEpoch << ",  sample count: " << inputCount << "\n";
    auto zamanbaslangic = std::chrono::high_resolution_clock::now();
    network.StartLearning(minErr, maxEpoch,lc);
    auto zamanbitis = std::chrono::high_resolution_clock::now();
    auto toplam_zaman = std::chrono::duration_cast<std::chrono::nanoseconds>(zamanbitis - zamanbaslangic);
    double islemsuresi = toplam_zaman.count() * 0.000000001;
    std::cout << "Training completed in: " << islemsuresi << " seconds!";
    network.saveWeights();

    //BELLEK KULLANIMI OPTIMIZE EDILECEK!!!
}