#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle{
    double particle_energy;
    bool is_hole;
    double pos_X, pos_Y;

    public:
    friend void gen_energy_e(Particle);
};

void gen_energy_e(Particle); //generate electron energy

#endif