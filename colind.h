/*
test
*/
//
// Created by marius on 2021-11-02.
//

#ifndef PONG_PLUS_PLUS_COLIND_H
#define PONG_PLUS_PLUS_COLIND_H

#include "cantec.h"

class colind : public cantec {
public:
    colind(const std::string &nume, float durata);
    void play() const;
    ~colind();
    cantec *clone() const override;
};

#endif //PONG_PLUS_PLUS_COLIND_H
