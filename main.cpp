#include <vector>
#include <string>
#include <iostream>
#include "cantec.h"
#include "album.h"
#include "cantaret.h"
#include "grupare_artistica.h"
#include "jucator.h"
#include "joc.h"
#include "colind.h"

using namespace std::string_literals;

class baza {
public:
    baza() {
        std::cout << "constr baza\n";
    }

    ~baza() {
        std::cout << "destr baza\n";
    }
};
class derivata : public baza {
public:
    derivata() {
        std::cout << "constr derivata\n";
    }

    ~derivata() {
        std::cout << "destr derivata\n";
    }
};

class baza_v {
    int x;
public:
    void setX(int x) {
        baza_v::x = x;
    }

    int getX() const {
        return x;
    }

    baza_v(int x = 0) : x(x) {
        std::cout << "constr baza_v\n";
    }

    virtual ~baza_v() {
        std::cout << "destr baza_v\n";
    }

    virtual baza_v *clone() = 0;
};
class derivata_v1 : public baza_v {
public:
    derivata_v1(int x) : baza_v(x) {
        std::cout << "constr derivata_v1\n";
    }

    ~derivata_v1() {
        std::cout << "destr derivata_v1\n";
    }

    baza_v *clone() override {
        return new derivata_v1(*this);
    }
};

class derivata_v2 : public baza_v {
public:
    derivata_v2(int x) : baza_v(x) {
        std::cout << "constr derivata_v2\n";
    }

    ~derivata_v2() {
        std::cout << "destr derivata_v2\n";
    }

    baza_v *clone() override {
        return new derivata_v2(*this);
    }
};

int main() {
//    baza b;
//    derivata d;
    // new aloca dinamic spatiu de memorie si apeleaza constructorul
//    baza *b1 = new baza;
    baza *der = new derivata;
//    derivata *der2 = new derivata;
    //derivata *der3 = new baza;

    // delete apeleaza destructorul si apoi se dezaloca spatiul
//    delete b1;
    delete der;
//    delete der2;


    baza_v *der_v1 = new derivata_v1(1);
    baza_v *der_v2 = new derivata_v2(2);
    auto vec = std::vector <baza_v *>();
    vec.push_back(der_v1);
    vec.push_back(der_v2);

    for(const auto &item: vec)
        std::cout << item->getX() << " ";
    std::cout << "\n";
    auto vec2 = std::vector <baza_v *>();
    for(const auto &item: vec)
        vec2.push_back(item->clone());
    for(const auto &item: vec)
        std::cout << item->getX() << " ";
    std::cout << "\n";
    for(const auto &item: vec2)
        std::cout << item->getX() << " ";
    std::cout << "\n";
    vec[0]->setX(3);

    for(const auto &item: vec)
        std::cout << item->getX() << " ";
    std::cout << "\n";
    for(const auto &item: vec2)
        std::cout << item->getX() << " ";
    std::cout << "\n";
    delete der_v1;
    delete der_v2;
    for(auto &item: vec2)
        delete item;

    std::cout << sizeof(baza) << " " << sizeof(derivata) << "\n";
    std::cout << sizeof(baza_v) << " " << sizeof(derivata_v1) << "\n";
    std::cout << sizeof(void *) << "\n";
    return 0;
    std::cout << cantec::getIdMax() << "\n";

    colind col{"jingle bells", 2.3};
    std::cout << colind::getIdMax() << "\n";
    col.play();
    cantec la_multi_ani{"LMA"s, 1.3, "la_major"s};
//    la_multi_ani.play();


    cantec c2 = cantec{"gaudeamus igitur"s, 4.2, "sol_major"s};
    cantec c3 = cantec{"abc"s, 2.2, "sol_minor"s};
    album a1("clasice");
    a1.adauga(c2);
    a1.adauga(la_multi_ani);
    a1.adauga(col);
    a1.play();

    album a2 = album("experimental", {std::make_shared <cantec>(c3)});
    album a3;
//    a3.operator=(a1.operator=(a2));
    a1 = a2;
    std::cout << "---------------------------\n";
    std::cout << a1 << a2;
    std::cout << "---------------------------\n";
    a1.adauga(col);
    a1.modifica();
    std::cout << "---------------------------\n";
    std::cout << a1 << a2;
    std::cout << "---------------------------\n";

    //    a3 = (a1 = a2); // echivalent cu mai sus
//    a3 = a1 = a2;
//    (a3 = a1) = a2; // daca chiar vrem asta, trebuie paranteze
    cantaret viorel("c1", "vioara");
    cantaret petru("c1", "pian");
    grupare_artistica grup("lautari", {viorel, petru});
    grup.adauga(a1);
    std::cout << grup;

    joc joc_simplu(grup, dificultate::USOR);
    jucator j("gigel", 0);
    //j.joaca(joc_simplu);
    std::cout << colind::getIdMax() << "\n";
    return 0;
}
