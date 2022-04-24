#include "particle.h"

Particle::Particle() {
    /*
     if (parametr uruchumienia programu, ze mamy tez dziury == false){
        this->particle_energy = gen_energy_e(kt z pliku)
      }
      else this.particle_enery = gen_enregy_e_h();
     */

    this->momentum_z = gen_momentum_z(this->particle_energy);
    this->momentum_per = gen_momentum_per();
    this->is_hole = false; // na razie tylko false, potem to na szybko przekminie i zmienie
    this->pos_X = 0.0; // to się zmieni, żaden problem
    this->pos_Y = 0.0; // tak jak powyżej


}

double gen_energy_e(double kt) {

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
