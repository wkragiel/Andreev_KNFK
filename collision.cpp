#include "collision.h"
#include <cmath>

bool collision_detection(Particle &particle, const double &radius, const double &height) {
    // zakladam, ze czastki poruszaja sie w zakresie
    // (0, height) - w osi z
    // (-radius, radius) - w osi r
    // ponadto zgodnie z poleceniem nakladam periodyczne warunki brzegowe


    // warunki brzegowe
    if(particle.pos_Z < 0) particle.pos_Z = height;
    if(particle.pos_Z > height) particle.pos_Z = 0;


    // wykrywanie i zwracanie informacji, czy doszlo do kolizji
    return particle.pos_R > radius || particle.pos_R < -radius;

}




// funkcja musi byc przetestowana i uzgodniona z fizyczna czescia ekipy projektu
// po prostu sie na tym nie znam do konca xd

void andreev_reflection(Particle &particle, const double& radius, const double &fermi_energy, const double& timestep) {
    // sinus kata padania:
    double sin_a = particle.momentum_z / std::sqrt(particle.momentum_z * particle.momentum_z + particle.momentum_r * particle.momentum_r);
    // sinus kata odbicia, wedle wzoru (jak dziura to ujemna energia?):
    double sin_b = std::sqrt((fermi_energy - particle.is_hole * particle.particle_energy) / (fermi_energy + particle.is_hole * particle.particle_energy)) * sin_a;
    // przydalo by sie tutaj cos w stylu assert(-1 <= sin_b <= 1), ale chyba ta fizyka dziala tak ze nic nie powinno sie zepsuc


    auto sign = [](double x){
        return x < 0 ? -1 : 1;
    };




    // zakladam, ze ped przy odbiciu sie nie zmienia, czy to tak ma byc?
    double momentum = particle.momentum_z * particle.momentum_z + particle.momentum_r * particle.momentum_r;


    // obliczanie nowych wartosci pedu:
    particle.momentum_z = -sign(particle.momentum_z) * momentum * std::abs(sin_b);
    particle.momentum_r = -sign(particle.momentum_r) * momentum * std::sqrt(1 - sin_b * sin_b);


    // zmiana polozenia po odbiciu
    double deltatime = timestep - (radius - std::abs(particle.pos_R)) / particle.momentum_r;
    particle.pos_R += particle.momentum_r * deltatime;
    particle.pos_Z += particle.momentum_z * deltatime;
}
