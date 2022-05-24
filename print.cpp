#include <iostream>
#include <fstream>
#include "print.h"
#include "input.h"
#include "particle.h"

using namespace std;

void print_N_to_file(std::string filename, Variables params ,int N_z[]) {
	//sprawdzenie czy plik jest pusty
	bool file_header = true;
	ifstream input_file;
	input_file.open(filename);
	if(input_file.peek() == ifstream::traits_type::eof())
		file_header = false;
	input_file.close();

	//zapis do pliku
	ofstream output_file;
	output_file.open(filename, std::ofstream::out | std::ofstream::app);
	
	float dz = params.length/params.Num_of_slices;
	
	//jesli plik pusty, stworz naglowek
	if(!file_header) {
		output_file << "t [s]" << ",";
		float z = -params.length/2;
		for(int i = 0; i < params.Num_of_slices; i++) {
			z += dz;
			output_file << z << ",";
		}
		output_file << endl;
		file_header = true;
	}

	//wypisz dane do pliku
	output_file << params.Num_of_iterations << ","; // tu byl time
	for(int i = 0; i < params.Num_of_slices; i++) {
		output_file << N_z[i] << ",";
	}
	output_file << endl;
	output_file.close();
}

void print_positions_to_file(std::string filename, Variables params, const std::vector<Particle>& particles) {
	//sprawdzenie czy plik jest pusty
	bool file_header = true;
	ifstream input_file;
	input_file.open(filename);
	if(input_file.peek() == ifstream::traits_type::eof())
		file_header = false;
	input_file.close();

	//zapis do pliku
	ofstream output_file;
	output_file.open(filename, std::ofstream::out | std::ofstream::app);
	
	//jesli plik pusty, stworz naglowek
	if(!file_header) {
		output_file << "t [s]" << ",";
		for(int i = 0; i < params.Num_of_particles; i++) {
			output_file << "z" << i+1 << "," << "r" << i+1 << ",";
		}
		output_file << endl;
		file_header = true;
	}

	//wypisz dane do pliku
	output_file << params.Num_of_iterations << ",";
	for(int i = 0; i < params.Num_of_particles; i++) {
		output_file << particles[i].pos_Z << "," <<  particles[i].pos_R << ",";
	}
	output_file << endl;
	output_file.close();
}