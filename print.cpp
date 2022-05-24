#include <iostream>
#include <fstream>
#include "print.h"

using namespace std;

void print_N_to_file(char* filename, double time, int N_z[], int no_slices, float length) {
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
	
	float dz = length/no_slices;
	
	//jesli plik pusty, stworz naglowek
	if(!file_header) {
		output_file << "t [s]" << ",";
		float z = -length/2;in
		for(int i = 0; i < no_slices; i++) {
			z += dz;
			output_file << z << ",";
		}
		output_file << endl;
		file_header = true;
	}

	//wypisz dane do pliku
	output_file << time << ",";
	for(int i = 0; i < no_slices; i++) {
		output_file << N_z[i] << ",";
	}
	output_file << endl;
	output_file.close();
}

void print_positions_to_file(char* filename, double time, double z[], double r[], int no_particles) {
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
		for(int i = 0; i < no_particles; i++) {
			output_file << "z" << i+1 << "," << "r" << i+1 << ",";
		}
		output_file << endl;
		file_header = true;
	}

	//wypisz dane do pliku
	output_file << time << ",";
	for(int i = 0; i < no_particles; i++) {
		output_file << z[i] << "," << r[i] << ",";
	}
	output_file << endl;
	output_file.close();
}