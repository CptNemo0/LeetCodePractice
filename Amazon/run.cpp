#include<iostream>
#include<string>

int main(int argc, char** argv)
{
    std::string cpp_file = argv[1];
    std::string file = std::string(cpp_file.begin(), cpp_file.end() - 3);
    std::string exe_file = file + "exe";

    std::string compile_command = "clang++ -std=c++23 -O2 -pedantic-errors " + cpp_file + " -o " + exe_file;
    std::string run_command = ".\\" + exe_file;
    system(compile_command.c_str());
    system(run_command.c_str());
}