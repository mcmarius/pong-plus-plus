/*
test
*/
//
// Created by marius on 2021-10-26.
//
#include "cantec.h"

cantec::cantec(const std::string &nume, float durata, const std::string &gama) : nume(nume), gama(gama), durata(durata) {}

std::ostream &operator<<(std::ostream &os, const cantec &cantec) {
    os << "nume: " << cantec.nume << " gama: " << cantec.gama << " durata: " << cantec.durata << "\n";
    return os;
}

void cantec::play() const {
    std::cout << "cantec play\n";
    for(int i = 0; i < 5 * durata; ++i) {
        std::cout << '\a';
    }
}

const std::string &cantec::getNume() const {
    return nume;
}

cantec::~cantec() {
    std::cout << "destr cantec " << nume <<"\n";
}

cantec *cantec::clone() const {
    return new cantec(*this);
}
