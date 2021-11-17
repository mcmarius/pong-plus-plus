/*
test
*/
//
// Created by marius on 2021-11-16.
//

#ifndef PONG_PLUS_PLUS_ERORI_CANTEC_H
#define PONG_PLUS_PLUS_ERORI_CANTEC_H

#include <stdexcept>

class eroare_cantec : public std::runtime_error {
public:
    eroare_cantec(const std::string &arg);
};

class cantec_prea_scurt : public eroare_cantec {
public:
    cantec_prea_scurt();
};

class eroare_gama : public eroare_cantec {
public:
    eroare_gama();
};

#endif //PONG_PLUS_PLUS_ERORI_CANTEC_H
