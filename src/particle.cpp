#include <iostream>
#include "particle.h"
#include "setup.h"


void verlet(Particle &p, double F[ND]);


Particle::Particle() {
    //init x, v.
    for (int i = 0; i < ND; i++) {
        x[i] = 0;
        v[i] = 0;
    }
    char shape = 'o'; // sphere!
    count++;
}

Particle::Particle(double x0[ND], double v0[ND], char shape) {
    //init x, v.
    for (int i = 0; i < ND; i++) {
        x[i] = x0[i];
        v[i] = v0[i];
    }
    this->shape = shape;
    count++;
}

void Particle::print() {
    std::cout << "Particle: x { ";
    for (int i = 0; i < ND; i++) {
        std::cout << x[i] << " ";
    }
    std::cout<< "}, v { ";
    for (int i = 0; i < ND; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void Particle::update(double F[ND]) {
    verlet(*this, F);
}




void verlet(Particle &p, double F[ND]){
    double x_new[ND];
    double v_new[ND];

    for (int i = 0; i < ND; i++) {
        x_new[i] = p.A*p.x[i] + p.B*p.v[i] + p.C*F[i];
        v_new[i] = (x_new[i] - p.x[i]) / dt;

        p.x[i] = x_new[i];
        p.v[i] = v_new[i];
    }
}