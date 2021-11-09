/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include "album.h"

std::ostream &operator<<(std::ostream &os, const album &album) {
    os << "nume: " << album.nume << " cantece:\n";
    for(const auto & cantec : album.cantece)
        os << "\t" << *cantec;
    return os;
}

void album::adauga(const cantec &cantec_) {
//    cantec_.play();
    cantece.push_back(cantec_.clone());
}

album::album(const std::string &nume) : nume(nume) {}

album::album(const std::string &nume, const std::vector <std::shared_ptr <cantec>> &cantece)
: nume(nume), cantece(cantece) {}

album::album(const album &copie) : nume(copie.nume) {
    for(const auto &cantec: copie.cantece)
        cantece.push_back(cantec->clone());
}

album &album::operator=(album copie) {
    swap(*this, copie);
    return *this;
}

album::~album() {
    std::cout << "destructor album\n";
}

void album::play() {
    for(const auto &cantec: cantece) {
        std::cout << "acum se reda melodia " << cantec->getNume() << "\n";
        cantec->play();
    }
}

void album::modifica() {
    for(auto &cantec: cantece) {
        cantec->setDurata(5);
    }
}

void swap(album &a1, album &a2) {
    using std::swap;
    swap(a1.cantece, a2.cantece);
    swap(a1.nume, a2.nume);
}
