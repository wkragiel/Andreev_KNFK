#ifndef _PRINT_H_
#define _PRINT_H_

//zapisywanie do pliku stanu ukladu w danej chwili czasu
void print_to_file(char* filename, double time, int N_z[], int no_slices, float lenght);
//filename - nazwa pliku (z rozszerzeniem .csv)
//N_z[] - tablica zawierajaca liczbe czastek w poszczegolnych binach
//no_slices - liczba binow (kawalkow, na ktore podzielony jest torus)
//lenght - dlugosc torusa

#endif