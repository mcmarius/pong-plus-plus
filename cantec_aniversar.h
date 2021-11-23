/*
test
*/
//
// Created by marius on 2021-11-16.
//

#ifndef PONG_PLUS_PLUS_CANTEC_ANIVERSAR_H
#define PONG_PLUS_PLUS_CANTEC_ANIVERSAR_H

#include "cantec.h"

class cantec_aniversar : public cantec {
public:
    cantec_aniversar(const std::string &nume, float durata, const std::string &gama);
    std::shared_ptr <cantec> clone() const override;
    void play() const override;
};

#endif //PONG_PLUS_PLUS_CANTEC_ANIVERSAR_H
