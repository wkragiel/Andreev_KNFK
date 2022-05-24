#ifndef INPUT_H_ 
#define INPUT_H_

#include <string>

class Variables {

public:
    int Num_of_particles, Num_of_slices, Num_of_iterations;
    double kT, E_fermi, alpha, length, radius;
    Variables(std::string filename);
};



#endif