/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include <algorithm>
#include "album.h"
#include "erori_cantec.h"

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

//album::album(const album &copie) : nume(copie.nume) {
//    std::cout << "cc album " << nume <<"\n";
//    for(const auto &cantec: copie.cantece)
//        cantece.push_back(cantec->clone());
//}
//
//album &album::operator=(album copie) {
//    swap(*this, copie);
//    return *this;
//}

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

album::album(album &&copie) {
    std::cout << "move constr album\n";
    nume = std::move(copie.nume);
    cantece = std::move(copie.cantece);
}

void album::ordoneaza_nume() {
    std::sort(cantece.begin(), cantece.end(), [](const auto &a, const auto &b)->bool
    {
      return a->getNume() < b->getNume();
    });
}

void album::ordoneaza_durata() {
    std::sort(cantece.begin(), cantece.end(), [](const auto &a, const auto &b)
    {
      return a->getDurata() < b->getDurata();
    });
}

std::shared_ptr <cantec> album::gaseste(const std::string &nume_cantec) {
    auto it = std::find_if(cantece.begin(), cantece.end(), [&nume_cantec](const std::shared_ptr <cantec> &c)
    {
      return c->getNume() == nume_cantec;
    });
    if(it != cantece.end())
        //return (*it)->clone();
        return *it;
    throw cantec_not_found(nume_cantec);
}
