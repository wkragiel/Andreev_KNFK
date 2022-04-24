#include "input.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void data_setup()
{
    ifstream plik("variables.txt", ios::in);
	string line;
	float tab[9];
	int i = 0 ;
	bool b;
	while (getline(plik, line)){ 
    if (line[0] != '#' ){ 
        istringstream iss(line);
        float num;
        if((iss >> num))
        {
			tab[i] = num;
			i++;
        }
    }
	if (line == "true")
		b=1;
			
	if (line == "false")
		b=0;		
	}
	Variables(tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7],tab[8],b);
    plik.close();
}


