#include <iostream>   // Standard input and output operations
#include <fstream>    // File input operations (ifstream)
#include <iomanip>    // Numeric output formatting (setprecision, fixed)
#include <cmath>      // Mathematical functions (sqrt)
#include <string>     

int main(int argc, char** argv)
{
    // Check whether the program is invoked correctly, the expected usage is: program_name <input_file>
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1; 
    }

    std::ifstream file(argv[1]); // Open the input file
    if (!file.is_open()) {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(6);  // Fixed-point format with 6-digit precision

    std::string line;   
    size_t nSamples = 0;     // Number of processed samples
    double meanRun = 0.0;    // Running mean
    double sqDevSum = 0.0;   // Sum of squared deviations (Welford M2)

    // Read the file line by line (streaming approach)
    while (std::getline(file, line)) {
        try {
            double sample = std::stod(line); // Convert the read line to a double value
            nSamples++;

            double delta = sample - meanRun;
            meanRun += delta / nSamples;

            double delta2 = sample - meanRun;
            sqDevSum += delta * delta2;

            double variance = (nSamples > 1) ? sqDevSum / (nSamples - 1) : 0.0;
            double stddev = std::sqrt(variance);

            std::cout << "sample: " << sample
                      << "\tmean: " << meanRun
                      << "\tstddev: " << stddev
                      << "\tvariance: " << variance
                      << "\n";

        } catch (...) {
            // Invalid or non-numeric lines are safely skipped
            std::cerr << "Invalid input line skipped.\n";
        }
    }

    file.close();
    return 0; 
}
