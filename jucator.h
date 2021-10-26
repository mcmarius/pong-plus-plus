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

class jucator {
    std::string nume;
    int scor;
public:
    jucator(const std::string &nume, int scor);
    void joaca(joc& joc);
};

#endif //PONG_PLUS_PLUS_JUCATOR_H
