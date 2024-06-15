// Header Guard
#ifndef PARTICLE_H
#define PARTICLE_H

#include "setup.h"

const int ND = DIMENSIONS;

class Particle {
protected:
    double x[ND];
    double v[ND];
    char shape;

public:
    Particle();
    Particle(double x0[ND], double v0[ND], char shape);

    void print();
    //void update(double dt, double F[ND]);
};

#endif
