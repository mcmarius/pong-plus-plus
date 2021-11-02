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

album::album(const std::string &nume, const std::vector <cantec*> &cantece) : nume(nume), cantece(cantece) {}

album::album(const album &copie) {
    this->nume = copie.nume;
//        this->cantece = copie.cantece;
//        for(int i = 0; i < copie.cantece.size(); i++) {
//            this->cantece.push_back(copie.cantece[i]);
//        }
    for(const auto & cantec : copie.cantece) {
        this->cantece.push_back(cantec);
    }
}

album &album::operator=(const album &copie) {
    if(this != &copie) {
        this->nume = copie.nume;
        this->cantece = copie.cantece;
        //std::copy(copie.cantece.begin(), copie.cantece.end(), std::back_inserter(cantece));
    }
    return *this;
}

album::~album() {
    std::cout << "destructor album\n";
    for(auto& cantec : cantece) {
        delete cantec;
    }
}

void album::play() {
    for(const auto& cantec : cantece) {
        std::cout << "acum se reda melodia " << cantec->getNume() << "\n";
        cantec->play();
    }
}
