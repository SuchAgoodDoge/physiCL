#include <iostream>
#include <vector>
#include <fstream>

#include "particle.h"
#include "setup.h"

void output(double (&xvec)[N_STEPS][N_PARTICLES][ND]) {
    // Cast xvec back to its original form
    double (*arr)[N_STEPS][N_PARTICLES][ND] = (double (*)[N_STEPS][N_PARTICLES][ND])xvec;

    std::ofstream file;
    file.open("output.dat");
    for (int i = 0; i < N_STEPS; i++) {
        for (int j = 0; j < N_PARTICLES; j++) {
            for (int k = 0; k < ND; k++) {
                file << xvec[i][j][k] << " ";
            }
            file << ", ";
        }
        file << std::endl;
    }
    file.close();
}

int main() {
    std::cout << "Running..." << std::endl;
    Particle p1;
    p1.print();

    double F[ND] = {0, -9.8};

    double xvec[N_STEPS][N_PARTICLES][ND];

    for (int i = 0; i < N_STEPS; i++) {
        p1.update(F);
        p1.print();
        xvec[i][0][0] = p1.x[0];
        xvec[i][0][1] = p1.x[1];
    }

    std::cout<<"Done"<<std::endl;

    output(xvec);



    return 0;
}