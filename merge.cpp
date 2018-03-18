#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout
            << "Merge by @dungwinux" << std::endl
            << "This program can merge files continuously and skip any file if it's not available." << std::endl
            << "merge [output] [input_1] ..."
            << std::endl
            << std::endl
            << "[output] \tOutput file's name" << std::endl
            << "[input_n]\tInput file's name" << std::endl;
        return 0;
    }
    if (argc < 3)
    {
        std::cout << "Wrong paramter(s)" << std::endl;
        return 1;
    }

    // Merge
    unsigned int err = 0;
    std::ofstream of_out(argv[1], std::ios_base::binary);
    if (of_out.is_open())
    {
        for (int itr = 2; itr < argc; itr++)
        {
            std::ifstream if_inp(argv[itr], std::ios_base::binary);
            if (!if_inp.is_open())
            {
                err++;
                std::cout << "Can't find " << argv[itr] << std::endl;
                continue;
            }
            of_out << if_inp.rdbuf();
            if_inp.close();
        }
        of_out.close();
        if (err < argc - 2)
        {
            std::cout << "DONE" << std::endl;
            if (err > 0)
                std::cout << "ERR " << err << "/" << argc - 2 << std::endl;
        }    
        else
            std::cout << "FAILED" << std::endl;
    }
    else
        std::cout << "Can't Create/Open Output File";
    return 0;
}