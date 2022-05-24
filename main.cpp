#include "vector.h"
#include "input.h"
#include "collision.h"
#include "particle.h"
#include "print.h"
#include "simulation.h"
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <vector>


int main(int argc, char* argv[])
{
    Variables params{std::string(argv[1])};
    std::vector<Particle> particles;
    int* N_z = new int[params.Num_of_slices];


    for(int i = 0; i < params.Num_of_particles; ++i){
        particles.push_back(Particle(params));

    }


    for(int i = 0; i < params.Num_of_iterations; ++i){
        memset(N_z, 0, sizeof(int) * params.Num_of_slices);
        verlet(particles, params);
        for(const auto& particle : particles){
            N_z[static_cast<int>(particle.pos_Z / params.length * params.Num_of_slices)]++;
        }

        print_N_to_file(std::string(argv[1]) + "_Nslices.csv", params, N_z);
        print_positions_to_file(std::string(argv[1]) + "_positions.csv", params, particles);
    }




    return 0;
}
