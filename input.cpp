#include "input.h"
#include <iostream>
#include <fstream>
#include <algorithm>




Variables read(std::string filename){

    Variables var;
    std::ifstream cFile (filename);

    if(cFile.is_open()){

        std::string line;
        while(getline(cFile,line)){
            line.erase(std::remove_if(line.begin(),line.end(),isspace)),line.end());
            if (line[0] == '#' || line.empty())
                continue;
            else if(line.find("Num_of_particle") != std::string::npos) {
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.Num_of_particles = std::stoi(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Integer overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("Num_of_slices") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.Num_of_slices = std::stoi(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Integer overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("kT") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.kT = std::stod(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Double overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("kT") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.E_fermi= std::stod(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Double overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("alpha") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.alpha= std::stod(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Double overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("length") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.length= std::stod(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Double overflow: std:out_of_range thrown" << std:endl;
                }
            }
            else if(line.find("radius") != std::string::npos){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimiterPos + 1);
                try {
                    var.radius= std::stod(value);
                }
                catch (std::invalid_argument const &e){
                    std::cout << "Bad input: std::invalid_argument thrown" << std::endl;
                }
                catch (std::out_of_range const &e){
                    std::cout << "Double overflow: std:out_of_range thrown" << std:endl;
                }
            }
        }

        return var;

    }
    else{
        std::cerr << "Couldn't open config file for reading.\n";
    }

}