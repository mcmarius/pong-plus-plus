/*
test
*/
//
// Created by marius on 2021-10-26.
//
#include "cantec.h"

#include <utility>
#include "erori_cantec.h"

int cantec::id_max = 1;

cantec::cantec(std::string nume, float durata, const std::string &gama)
: nume(std::move(nume)), gama(gama), durata(durata),
  id(id_max) {
    id_max++;
    if(durata < 0.5)
        throw cantec_prea_scurt();
    if(gama == "sol_")
        throw eroare_gama();
}

std::ostream &operator<<(std::ostream &os, const cantec &cantec) {
    cantec.afis(os);
//    os << "nume: " << cantec.nume << " gama: " << cantec.gama << " durata: " << cantec.durata;
    os << "\n";
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
    std::cout << "destr cantec " << nume << "\n";
}

void cantec::setDurata(float durata) {
    cantec::durata = durata;
}

void cantec::afis(std::ostream &os) const {
//    os << "nume: " << nume << " gama: " << gama << " durata: " << durata;
    const auto &cantec = *this;
    os << "id: " << id << "nume: " << cantec.nume << " gama: " << cantec.gama << " durata: " << cantec.durata;
}

cantec::cantec(const cantec &copie) : id(id_max), durata(copie.durata), nume(copie.nume), gama(copie.gama) {
    id_max++;
}

int cantec::getIdMax() {
    return id_max;
}
