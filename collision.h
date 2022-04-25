#ifndef COLLISION_H
#define COLLISION_H


#include "particle.h"






bool collision_detection(Particle& particle, const double& radius, const double& height);
void andreev_reflection(Particle& particle, const double& radius, const double& fermi_energy, const double& timestep);

// propozycja uzycia funkcji w kodzie
//
// if(collision_detection(p, r, h))
//     andreev_reflection(p, radius, fermi_energy, dt);
// else {
//     zwykle calkowanie rownania ruchu...
// }





#endif //COLLISION_H
