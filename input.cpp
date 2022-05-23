#include "input.h"
#include <iostream>
#include <fstream>
#include <algorithm>




Variables read(std::string filename){

    Variables var;
    std::ifstream cFile (filename);

    if(cFile.is_open()){

        std:string line;
        while(getline(cFile,line)){
            line.erase(std::remove_if(line.begin(),line.end(),isspace)),line.end());
            if (line[0] == '#' || line.empty())
                continue;
            else if(line[0] == "Num_of_particles") {
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "Num_of_slices"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "kT"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "E_fermi"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "alpha"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "length"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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
            else if(line[0] == "radius"){
                auto delimiterPos = line.find("=");
                std::string value = line.substr(delimeterPos + 1);
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