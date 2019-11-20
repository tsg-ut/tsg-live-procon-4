#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <experimental/filesystem>
#include <testlib/testlib.h>

namespace fs = std::experimental::filesystem::v1;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (size_t i = 0; i < 20; i++) {
        uint32_t a = rnd.next(1, 100);
        uint32_t b = rnd.next(1, 100);

        std::ostringstream filename_in, filename_out;
        filename_in << "testcases/input/input" << std::setfill('0') << std::setw(2) << i << ".txt";
        filename_out << "testcases/output/output" << std::setfill('0') << std::setw(2) << i << ".txt";

        std::ofstream file_in, file_out;

        fs::create_directories("testcases/input");
        file_in.open(filename_in.str());
        file_in << a << " " << b << std::endl;
        file_in.close();

        fs::create_directories("testcases/output");
        file_out.open(filename_out.str());
        file_out << a + b << std::endl;
        file_out.close();
    }

    return 0;
}