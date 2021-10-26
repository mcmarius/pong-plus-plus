/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include "jucator.h"

jucator::jucator(const std::string &nume, int scor) : nume(nume), scor(scor) {}

void jucator::joaca(joc &joc) {
    joc.rulare();
}
