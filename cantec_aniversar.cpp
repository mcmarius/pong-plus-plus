/*
test
*/
//
// Created by marius on 2021-11-16.
//

#include "cantec_aniversar.h"

std::shared_ptr <cantec> cantec_aniversar::clone() const {
    return std::make_shared <cantec_aniversar>(*this);
}

cantec_aniversar::cantec_aniversar(const std::string &nume, float durata, const std::string &gama)
: cantec(nume, durata, gama) {}

void cantec_aniversar::play() const {
    cantec::play();
    std::cout << "tada!\n";
}
