#pragma once
#include <iostream>
#include "AutoEncoder.h"
#include "fstream"

#include <ctime>
#include <chrono>

#include "MultiLayerNetwork.h"

uint32_t readBE(std::ifstream& f) {
    uint8_t b[4];
    f.read((char*)b, 4);
    return (uint32_t(b[0]) << 24) |
        (uint32_t(b[1]) << 16) |
        (uint32_t(b[2]) << 8) |
        uint32_t(b[3]);
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

    //çýktýnýn þekli, giriþin þekli olmak zorunda.
    int LayerNeuronCounts[layerCount] = { 32, dimension };

    float lc = 0.01f;
    float minErr = 0.01f, maxEpoch = 100000;

    AutoEncoder autoencoder(layerCount, LayerNeuronCounts, dimension, inputCount);

    autoencoder.initializeBias();
    autoencoder.initializeWeights();


    std::ifstream dosya("inputs.txt");
    if (!dosya)
        return -5;

    autoencoder.giveInputs(pixels);

    std::cout << "Encoding started.\n";

    auto zamanbaslangic1 = std::chrono::high_resolution_clock::now();
    autoencoder.StartEncoding(minErr, maxEpoch, lc);
    auto zamanbitis1 = std::chrono::high_resolution_clock::now();
    auto toplam_zaman1 = std::chrono::duration_cast<std::chrono::nanoseconds>(zamanbitis1 - zamanbaslangic1);
    double islemsuresi1 = toplam_zaman1.count() * 0.000000001;
    std::cout << "Encoding completed in: " << islemsuresi1 << " seconds!\n";

    std::cout << "Compressing inputs.\n";
    float* compressedInputs = autoencoder.encodeInputsAll();

    //for (int i = 0; i < inputCount; i++)
    //{
    //    std::cout << "\nInput: " << i << "\n";
    //    for (int d = 0; d < 32; d++)
    //    {

    //        std::cout << compressedInputs[i + d * inputCount] << " ";
    //    }
    //    std::cout << compressedInputs[i + 32 * inputCount] << "\n\n";
    //}


    //BURADAN ITIBAREN, COMPRESSED INPUTLARI MULTI LAYER NETWORKUMUZDE EGITIRIZ..


    std::cout << "Setting up multi layer network.\n";
    int _dimension = 32;
    const int _layerCount = 2;

    int _LayerNeuronCounts[_layerCount] = { 64,10 };

    float _lc = 0.01f;
    float _minErr = 0.01f, _maxEpoch = 100000;

    MultiLayerNetwork network(_layerCount, _LayerNeuronCounts, _dimension, inputCount);
    network.giveInputs(compressedInputs);
    network.initializeBias();
    network.initializeWeights();
    std::cout << "Training started.\n";

    auto zamanbaslangic = std::chrono::high_resolution_clock::now();
    network.StartLearning(_minErr, _maxEpoch, _lc);
    auto zamanbitis = std::chrono::high_resolution_clock::now();
    auto toplam_zaman = std::chrono::duration_cast<std::chrono::nanoseconds>(zamanbitis - zamanbaslangic);
    double islemsuresi = toplam_zaman.count() * 0.000000001;
    std::cout << "Training completed in: " << islemsuresi << " seconds!\n";

    std::cout << "Saving all weights...\n";

    autoencoder.saveWeights();
    network.saveWeights();

}