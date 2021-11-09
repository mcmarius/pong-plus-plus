/*
test
*/
//
// Created by marius on 2021-11-02.
//

#include "colind.h"

colind::colind(const std::string &nume, float durata) : cantec(nume, durata, "do major") {}

void colind::play() const {
    //cantec::play();
    std::cout << "colind play\n";
    for(int i = 0; i < 6 * durata; ++i) {
        std::cout << '\a' << '\a';
    }
}

colind::~colind() {
    std::cout << "destr colind\n";
}

std::shared_ptr <cantec> colind::clone() const {
    return std::make_shared <colind>(*this);
}

void colind::afis(std::ostream &os) const {
    os << "nr: " << nr << ", ";
    cantec::afis(os);
}
