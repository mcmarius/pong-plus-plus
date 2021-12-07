/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_JUCATOR_H
#define PONG_PLUS_PLUS_JUCATOR_H

#include <string>
#include "joc.h"

template <typename T>
class jucator {
    std::string nume;
    T scor;
public:
    jucator(const std::string &nume, T scor);
    void joaca(joc &joc);
};

#endif //PONG_PLUS_PLUS_JUCATOR_H
