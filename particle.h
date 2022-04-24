#ifndef PARTICLE_H_
#define PARTICLE_H_
#define NO_BINS 10000
#include <cstring>

class Particle{

    public:

    double particle_energy, momentum_z, momentum_r;
    bool is_hole;
    double pos_Z, pos_R;

    Particle();

    friend double gen_energy_e(double kt);
    friend double gen_momentum_z(double energy);
    friend double gen_momentum_r();
    friend double gen_energy_e_h();
};

//void gen_energy_e(Particle); //generate electron energy
double gen_energy_e(double kt);
double gen_momentum_z(double energy);
double gen_momentum_r();
double gen_energy_e_h();

#endif