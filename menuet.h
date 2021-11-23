/*
test
*/
//
// Created by marius on 2021-11-23.
//

#ifndef PONG_PLUS_PLUS_MENUET_H
#define PONG_PLUS_PLUS_MENUET_H

#include "cantec.h"

class menuet : public cantec {
public:
    menuet(const std::string &nume, float durata, const std::string &gama);
    std::shared_ptr <cantec> clone() const override;
    void play() const override;
};

#endif //PONG_PLUS_PLUS_MENUET_H
