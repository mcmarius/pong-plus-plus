/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_CANTARET_H
#define PONG_PLUS_PLUS_CANTARET_H

#include <iostream>

class cantaret {
    std::string nume;
    std::string instrument;
public:
    cantaret(const std::string &nume, const std::string &instrument);

    friend std::ostream &operator<<(std::ostream &os, const cantaret &cantaret);
};

#endif //PONG_PLUS_PLUS_CANTARET_H
