/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_CANTEC_H
#define PONG_PLUS_PLUS_CANTEC_H

#include <string>
#include <iostream>

class cantec {
    std::string nume;
    std::string gama;
    float durata;
public:
    cantec(const std::string &nume, float durata, const std::string &gama);

    friend std::ostream &operator<<(std::ostream &os, const cantec &cantec);
};

#endif //PONG_PLUS_PLUS_CANTEC_H
