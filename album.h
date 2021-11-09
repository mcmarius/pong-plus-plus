/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_ALBUM_H
#define PONG_PLUS_PLUS_ALBUM_H

#include <vector>
#include <memory>
#include "cantec.h"

class album {
    std::string nume;
    std::vector <std::shared_ptr <cantec>> cantece;
public:
    friend std::ostream &operator<<(std::ostream &os, const album &album);

    void adauga(const cantec &cantec);

    album(const std::string &nume);
    album(const std::string &nume, const std::vector <std::shared_ptr <cantec>> &cantece);
    album(const album &copie);
    album &operator=(album copie);
    friend void swap(album &a1, album &a2);
    album() = default;
    ~album();

    void play();
    void modifica();
};


#endif //PONG_PLUS_PLUS_ALBUM_H
