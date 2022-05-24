#include "particle.h"
#include "collision.h"
#include "simulation.h"
#include <vector>

void verlet(std::vector<Particle>& particles, Variables params){
    int timestep=1;//musi być albo zafiksowane albo czytane z pliku inputowego
    int stepsMade=0;
    int simSteps=100;//musi być albo zafiksowane albo czytane z pliku inputowego
    //pętla symulacji
    while (stepsMade<=simSteps)
    {
        //pętla po wszystkich cząstkach
        for (int idx = 0; idx < params.Num_of_particles; idx++)
        {   
            //sprawdzanie czy cząstka ma kolizję ze ścianą
            if (collision_detection(particles[idx], params.radius, params.length)){
                andreev_reflection(particles[idx], params.radius, params.E_fermi, timestep);
            }
            else{
                //zalozenie ze mass=1
                // particles[idx].pos_R = particles[idx].pos_R + particles[idx].momentum_r*timestep/particles[idx].mass;
                particles[idx].pos_R += particles[idx].momentum_r*timestep;
                // particles[idx].pos_Z = particles[idx].pos_Z + particles[idx].momentum_z*timestep/particles[idx].mass;
                particles[idx].pos_Z += particles[idx].momentum_z*timestep;
            }   
        }
        stepsMade++;   
    }    
}