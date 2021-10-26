/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include "grupare_artistica.h"

grupare_artistica::grupare_artistica(const std::string &nume, const std::vector <cantaret> &membri) : nume(nume), membri(membri) {}

std::ostream &operator<<(std::ostream &os, const grupare_artistica &grupare) {
    os << "nume: " << grupare.nume << "\n\tmembri: ";
    for(const auto& membru : grupare.membri)
        os << membru;
    os << "\talbume: ";
    for(const auto& album: grupare.albume)
        os << album;
    return os;
}

void grupare_artistica::adauga(const album &album) {
    albume.push_back(album);
}

void grupare_artistica::adauga(const cantaret &cantaret) {
    membri.push_back(cantaret);
}
