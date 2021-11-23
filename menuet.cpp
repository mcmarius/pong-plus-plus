/*
test
*/
//
// Created by marius on 2021-11-23.
//

#include "menuet.h"

std::shared_ptr <cantec> menuet::clone() const {
    return std::make_shared <menuet>(*this);
}

void menuet::play() const {
    std::cout << "lalala: ";
    cantec::play();
}

menuet::menuet(const std::string &nume, float durata, const std::string &gama) : cantec(nume, durata, gama) {}
