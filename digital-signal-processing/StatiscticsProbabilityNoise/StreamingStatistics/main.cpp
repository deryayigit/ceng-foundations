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
        return 1; // Terminate the program if the file cannot be opened
    }

    
    std::cout << std::fixed << std::setprecision(6);  // Print numeric outputs in fixed-point format with 6-digit precision

    std::string line;   
    size_t n = 0;       // Number of processed samples
    double mean = 0.0;  // Running mean value
    double M2 = 0.0;    // Accumulated squared deviation term (used in Welford's algorithm)

    // Read the file line by line (streaming approach)
    while (std::getline(file, line)) {
        try {
            double x = std::stod(line); // Convert the read line to a double value
            n++;

            double delta = x - mean;
            mean += delta / n;

            double delta2 = x - mean;

            M2 += delta * delta2;


            double variance = (n > 1) ? M2 / (n - 1) : 0.0;
            double stddev = std::sqrt(variance);

            std::cout << "sample: " << x
                      << "\tmean: " << mean
                      << "\tstddev: " << stddev
                      << "\tvariance: " << variance
                      << "\n";

        } catch (...) {
            // Invalid or non-numeric lines are safely skipped, allowing the streaming process to continue without interruption
            std::cerr << "Invalid input line skipped.\n";
        }
    }

    file.close();
    return 0; 
}
