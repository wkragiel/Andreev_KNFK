#ifndef PARTICLE_H_
#define PARTICLE_H_
#define NO_BINS 10000
#include <cstring>
#include "input.h"

class Particle{

    public:

    double particle_energy, momentum_z, momentum_r;
    bool is_hole;
    double pos_Z, pos_R;

    Particle(Variables var);


    friend double gen_energy(double kt, double e_fermi);
    friend double gen_momentum_z(double energy);
    friend double gen_momentum_r(double energy, double momentum_z);
};

//void gen_energy_e(Particle); //generate electron energy
double gen_energy(double kt,double e_fermi);
double gen_momentum_z(double energy);
double gen_momentum_r(double energy,double momentum_z);


#endif