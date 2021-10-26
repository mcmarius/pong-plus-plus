/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_GRUPARE_ARTISTICA_H
#define PONG_PLUS_PLUS_GRUPARE_ARTISTICA_H

#include "cantaret.h"
#include "album.h"

class grupare_artistica {
    std::string nume;
    std::vector<cantaret> membri;
    std::vector<album> albume;
public:
    grupare_artistica(const std::string &nume, const std::vector <cantaret> &membri);

    friend std::ostream &operator<<(std::ostream &os, const grupare_artistica &grupare);

    void adauga(const album& album);
};

#endif //PONG_PLUS_PLUS_GRUPARE_ARTISTICA_H
