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
    const int id;
    static int id_max;
protected:
    std::string nume;
    std::string gama;
    float durata;
    virtual void afis(std::ostream &os) const;
public:
    cantec(const std::string &nume, float durata, const std::string &gama);
    cantec(const cantec &);

    friend std::ostream &operator<<(std::ostream &os, const cantec &cantec);
    const std::string &getNume() const;
    virtual void play() const = 0;
    void setDurata(float durata);
    virtual std::shared_ptr <cantec> clone() const = 0;
    virtual ~cantec() = 0;
    static int getIdMax();
};

#endif //PONG_PLUS_PLUS_CANTEC_H
