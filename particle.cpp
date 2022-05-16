#include "particle.h"
#include <random>
#include <chrono>

Particle::Particle(const double &kt){
    this->particle_energy = gen_energy_e(kt);
    this->momentum_z = gen_momentum_z(this->particle_energy);
    this->momentum_r = gen_momentum_r(this->particle_energy,this->momentum_z);
    this->is_hole = false;
    this->pos_R = 0.0; // to się zmieni, żaden problem
    this->pos_Z = 0.0; // to ma być zero
}
Particle::Particle(const double &kt, const double &probability) {
    if(((double)rand())/RAND_MAX <= probability){
        this->particle_energy = gen_energy_e_h();
        this->is_hole = true;
    }
    else{
        this->particle_energy = gen_energy_e(kt);
        this->is_hole =false;
    }
    this->momentum_z = gen_momentum_z(this->particle_energy);
    this->momentum_r = gen_momentum_r(this->particle_energy,this->momentum_z);
    this->pos_R = 0.0; // to się zmieni, żaden problem
    this->pos_Z = 0.0; // to ma być zero
}

double gen_energy_e(double kt, double e_fermi) {
    double emax = e_fermi/2;
    double energy;
    unsigned seed= std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::exponential_distribution<double> distribution(kt);
    energy = distribution(generator);
    if(energy > emax) energy = emax;

    return energy;
}

double gen_momentum_z(double energy){

    double min = -std::sqrt(2.0*energy);
    double max = std::sqrt(2.0*energy);

    double x[NO_BINS], y[NO_BINS];
    memset(x,0.0,sizeof(double)*NO_BINS);
    memset(y,0.0,sizeof(double)*NO_BINS);


    for (int i = 0; i < NO_BINS; i++) {
        x[i] = min + (max-min)*((double) i/(double) NO_BINS);
        y[i] = ((2.0*energy - std::sqrt(x[i]*x[i]))*x[i]/2.0 + energy*((x[i]/((2.0*energy - std::atan(std::sqrt(x[i]*x[i]))))))+energy*M_PI/2.0)/(M_PI*energy);
    }

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    double y_random = distribution(generator);

    double diff = 0.0;
    int k = 0;

    for (int i = 0; i < NO_BINS; i++) {
        double diff_tmp = std::abs((y_random - y[NO_BINS-1-i]));
        if (diff_tmp < diff){
            k = i;
            diff = diff_tmp;
        }
        else
            break;

    }

    return x[k];

}
double gen_momentum_r(double energy,double momentum_z){

    double momentum_r = sqrt(2.0*energy-momentum_z*momentum_z);
    // tutaj trzeba napisać tą funkcję

}
