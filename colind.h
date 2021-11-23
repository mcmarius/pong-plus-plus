/*
test
*/
//
// Created by marius on 2021-11-02.
//

#ifndef PONG_PLUS_PLUS_COLIND_H
#define PONG_PLUS_PLUS_COLIND_H

#include <ostream>
#include "cantec.h"

class colind : public cantec {
    int nr = 3;
public:
    colind(const std::string &nume, float durata);
    void play() const;
    ~colind();
    std::shared_ptr <cantec> clone() const override;
    void tralala() {}
protected:
    void afis(std::ostream &os) const override;
};

#endif //PONG_PLUS_PLUS_COLIND_H
