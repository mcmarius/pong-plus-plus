/*
test
*/
//
// Created by marius on 2021-10-26.
//

#ifndef PONG_PLUS_PLUS_CANTEC_H
#define PONG_PLUS_PLUS_CANTEC_H

#include <string>
#include <iostream>
#include <memory>

class cantec {
protected:
    std::string nume;
    std::string gama;
    float durata;
public:
    cantec(const std::string &nume, float durata, const std::string &gama);

    friend std::ostream &operator<<(std::ostream &os, const cantec &cantec);
    const std::string &getNume() const;
    virtual void play() const;
    void setDurata(float durata);
    virtual std::shared_ptr <cantec> clone() const;
    virtual ~cantec();
};

#endif //PONG_PLUS_PLUS_CANTEC_H
