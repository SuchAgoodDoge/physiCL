// Header Guard
#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include "setup.h"

const int ND = DIMENSIONS;

class Particle {
protected:
    char shape;
    //int id; // particle id
    int count; // number of particles that are alive

    double m {1.0}; // mass
    double b {0.0}; // damping
    double k {0.0}; // spring constant



public:
    double x[ND];
    double v[ND];

    double D {2.*m + b*dt};
    double A {2. * (2*m - k*dt*dt) / D};
    double B {(b*dt - 2.*m) / D};
    double C {2. * dt*dt / D};

    Particle();
    Particle(double x0[ND], double v0[ND], char shape);
    ~Particle() {count--;}

    void print();
    void get_count() {std::cout << "Number of particles: " << count << std::endl;}

    void update(double F[ND]);
};

#endif
