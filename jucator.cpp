/*
test
*/
//
// Created by marius on 2021-10-26.
//

#include "jucator.h"

template <typename T>
jucator <T>::jucator(const std::string &nume, T scor) : nume(nume), scor(scor) {}

template <typename T>
void jucator <T>::joaca(joc &joc) {
    scor += joc.rulare();
}
