#ifndef ANDREEV_KNFK_SIMULATION_H
#define ANDREEV_KNFK_SIMULATION_H

class Variables;
class Particle;
#include <vector>


void verlet(std::vector<Particle>& particles, Variables params);






#endif //ANDREEV_KNFK_SIMULATION_H
