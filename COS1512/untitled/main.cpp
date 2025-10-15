#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<double> loadCSV(const std::string &filename) {
    std::vector<double> samples;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        samples.push_back(std::stod(line));
    }
    return samples;
}

#include <cmath>

std::string decodeUART(const std::vector<double> &samples, double sampleRate, double baudRate) {
    std::string result;
    int samplesPerBit = static_cast<int>(std::round(sampleRate / baudRate));
    double threshold = (3.2 + 0.0) / 2; // midpoint threshold between high & low

    for (size_t i = 0; i < samples.size(); i++) {
        // Detect start bit (line goes low)
        if (samples[i] < threshold) {
            // Align to middle of start bit
            size_t bitStart = i + samplesPerBit / 2;

            unsigned char byte = 0;
            for (int bit = 0; bit < 8; bit++) {
                size_t sampleIndex = bitStart + (bit + 1) * samplesPerBit;
                if (sampleIndex >= samples.size()) break;

                bool bitValue = samples[sampleIndex] > threshold;
                byte |= (bitValue << bit); // LSB first
            }

            result.push_back(static_cast<char>(byte));

            // Skip ahead to end of stop bit
            i = bitStart + (10 * samplesPerBit);
        }
    }
    return result;
}