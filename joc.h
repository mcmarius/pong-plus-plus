//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_JOC_H
#define PONG_PLUS_PLUS_JOC_H

#include "grupare_artistica.h"

enum class dificultate {
    USOR, MEDIU, GREU
};

std::ostream& operator<<(std::ostream& os, const dificultate& dif);

class joc {
public:
    int rulare();
    joc(const grupare_artistica &grup, dificultate dif);
private:
    grupare_artistica grup;
    dificultate dif;
};

#endif //PONG_PLUS_PLUS_JOC_H
