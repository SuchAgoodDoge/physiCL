#include <iostream>
#include "particle.h"
#include "verlet.h"
#include "setup.h"



Particle::Particle() {
    //init x, v.
    for (int i = 0; i < ND; i++) {
        x[i] = 0;
        v[i] = 0;
    }
    char shape = 'o'; // sphere!
}

Particle::Particle(double x0[ND], double v0[ND], char shape) {
    //init x, v.
    for (int i = 0; i < ND; i++) {
        x[i] = x0[i];
        v[i] = v0[i];
    }
    this->shape = shape;
}

void Particle::print() {
    std::cout << "Particle: x{";
    for (int i = 0; i < ND; i++) {
        std::cout << x[i] << " ";
    }
    std::cout<< "}, v{";
    for (int i = 0; i < ND; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "}" << std::endl;
}
