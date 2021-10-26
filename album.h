/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_ALBUM_H
#define PONG_PLUS_PLUS_ALBUM_H

#include <vector>
#include "cantec.h"

class album {
    std::string nume;
    std::vector<cantec> cantece;
public:
    friend std::ostream &operator<<(std::ostream &os, const album &album);

    void adauga(const cantec& cantec);

    album(const std::string &nume);
    album(const std::string &nume, const std::vector <cantec> &cantece);
    album(const album& copie);
    album() = default;

    album& operator=(const album& copie);
    ~album();
};


#endif //PONG_PLUS_PLUS_ALBUM_H
