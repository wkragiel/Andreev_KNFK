#ifndef _PRINT_H_
#define _PRINT_H_

//zapisywanie do pliku liczby czastek w poszczegolnych kawalkach torusa w danej chwili czasu
void print_N_to_file(char* filename, double time, int N_z[], int no_slices, float lenght);
//filename - nazwa pliku (z rozszerzeniem .csv)
//N_z[] - tablica zawierajaca liczbe czastek w poszczegolnych binach
//no_slices - liczba binow (kawalkow, na ktore podzielony jest torus)
//lenght - dlugosc torusa

//zapisywanie do pliku polozen czastek w danej chwili czasu
void print_positions_to_file(char* filename, double time, double z[], double r[], int no_particles);
//z - pozycje z
//r - pozycje r

#endif