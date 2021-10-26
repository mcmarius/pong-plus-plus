/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include "cantaret.h"

cantaret::cantaret(const std::string &nume, const std::string &instrument) : nume(nume), instrument(instrument) {}

std::ostream &operator<<(std::ostream &os, const cantaret &cantaret) {
    os << "nume: " << cantaret.nume << " instrument: " << cantaret.instrument << "\n";
    return os;
}
