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
#include "cantec_aniversar.h"
#include "erori_cantec.h"
#include "menuet.h"
#include <stack>

void f1();
void f2();
using namespace std::string_literals;

class baza {
protected:
    int x;
public:
    virtual void f() {}

    baza() = default;
};

class der1 : virtual public baza {
public:
    void f() override {}
};
class der2 : public virtual baza {
public:
    void f() override {}
};
//class der3 : public baza {};

class der_complicata : public der1, public der2 {
//private:
//    void f() override {}
    void f() override {
        der1::f();
        der2::f();
    }

    void g() {
        f();
    }
};

class baza1 {
    int x;
};
class baza2 {
    int x;
};

class der_ceva : public baza1, public baza2 {};

template <typename T, typename U>
void adauga(T &obiect1, U &obiect2) {
    return obiect1.adauga(obiect2);
}

class baza0 {
    std::string tip;
public:
    virtual void functie_virtuala1() = 0;

    const std::string &getTip() { return tip; }
};

class ceva : public baza0 {
    void g() {}

public:
    void functie_virtuala1() override {
        g();
    }
};

class abc {
    std::shared_ptr <baza0> b;

//    baza0 b;
    void g() {}

    void h() {}

    void hh() {}

public:
    void f() {
        b->functie_virtuala1();
        if(b->getTip() == "ceva") {
            g();
        }
        else if(b->getTip() == "altceva")
            h();
        else if(b->getTip() == "altceva 2")
            hh();
    }
};

template <int Min = 20, int Max = 50>
class armor;

template <int Min = 20, int Max = 50>
std::ostream &operator<<(std::ostream &o, const armor <Min, Max> &c);

template <int Min, int Max>
class armor {
    const static int MIN = Min;
    const static int MAX = Max;
public:
    friend std::ostream &operator<< <>(std::ostream &os, const armor <Min, Max> &armor);
};

template <int Min, int Max>
std::ostream &operator<<(std::ostream &os, const armor <Min, Max> &armor) {
    return os;
}

template
std::ostream &operator<< <>(std::ostream &o, const armor <20, 30> &x);
template
std::ostream &operator<< <>(std::ostream &o, const armor <20, 50> &x);

class player {
    armor <> a;
};

int main() {
//    auto stiva = std::stack <std::unique_ptr <baza>>();
//    stiva.push(std::unique_ptr <der1>(new der1));
    baza *b = new baza[20];
    delete[] b;

    int x;
    const int z1 = 6;
    int const z2 = 16;
    int *adr;
    const int *adr2;  // pointer catre constanta
    int const *adr3;  // pointer catre constanta
    int *const adr4 = &x;  // pointer constant catre int; initializare la definire
    int const *const adr5 = &z1;  // pointer constant catre int constant
    const int *const adr6 = &z1;  // pointer constant catre int constant
    adr = &x;
    adr2 = &z1;
    adr2 = &z2;
//    z1++;
    x = 5;

    std::cout << cantec::getIdMax() << "\n";

    colind col{"jingle bells", 2.3};
    const colind col0 = colind{"asd", 2.3};
//    colind const col1 = colind{"asd", 2.3};
//    col0.setDurata(4);
    colind *cadr;
    cadr = &col;
//    cadr = &col0;
    cadr->setDurata(5);
    const colind *cadr2;
    colind const *cadr3;
    cadr2 = &col;
//    cadr2->setDurata(6);
    cadr2 = &col0;
//    cadr2->setDurata(6);
    colind *const &cadr4 = &col;
//    colind * const &cadr5 = &col0;
    cadr4->setDurata(2);
//    cadr4 = &col;
    colind const *const &cadr6 = &col0;
    colind const *const &cadr7 = &col;
    const colind *const &cadr8 = &col0;
    const colind *const &cadr9 = &col;

    // ce face new:
    // aloca memorie in heap, apoi
    // apeleaza constructorul
    cantec *ptr_col = new colind{"asd", 6};
//    ptr_col->tralala();

    // ce face delete:
    // apeleaza destructorul
    // elibereaza memoria
    delete ptr_col;

    menuet men{"abc", 4.3, "la"};

    std::cout << colind::getIdMax() << "\n";
    col.play();
    cantec_aniversar la_multi_ani{"LMA"s, 1.3, "la_major"s};
//    la_multi_ani.play();


    auto c2 = cantec_aniversar{"gaudeamus igitur"s, 4.2, "sol_major"s};
    auto c3 = cantec_aniversar{"abc"s, 2.2, "sol_minor"s};
    auto c4 = std::make_shared <cantec_aniversar>("abc", 3.4, "sol");
    album a1("clasice");
    a1.adauga(c2);
    a1.adauga(la_multi_ani);
    a1.adauga(col);
    a1.adauga(men);
    a1.play();

    album a2 = album("experimental", {std::make_shared <cantec_aniversar>(c3)});
    a2.adauga(la_multi_ani);
    a2.adauga(col);
//    album a3;
//    a3.operator=(a1.operator=(a2));
//    a1 = a2;
    std::cout << "---------------------------\n";
    std::cout << a1 << a2;
    std::cout << "---------------------------\n";
    a1.adauga(col);
    a1.modifica();
    std::cout << "---------------------------\n";
    std::cout << a1 << a2;
    std::cout << "---------------------------\n";

    try {
        f1();
        auto alt_cantec_ok = cantec_aniversar("asde", 5, "sol");
    }
    catch(eroare_cantec &error) {
        std::cout << error.what() << "\n";
        //throw eroare_cantec("");
        //throw;
        //throw error;
    }
//    catch (...) {
//        throw;
//    }






    //    a3 = (a1 = a2); // echivalent cu mai sus
//    a3 = a1 = a2;
//    (a3 = a1) = a2; // daca chiar vrem asta, trebuie paranteze
    cantaret viorel("c1", "vioara");
    cantaret petru("c1", "pian");
    grupare_artistica grup("lautari", {viorel, petru});

//    adauga<grupare_artistica, album>(grup, std::move(a1));
    adauga <grupare_artistica, cantaret>(grup, viorel);

    grup.adauga(std::move(a1));
    std::cout << grup;
    std::vector <album> aaa;
//    aaa.emplace_back(std::move(a1));

    joc joc_simplu(std::move(grup), dificultate::USOR);
    jucator <int> j("gigel", 0);
    //j.joaca(joc_simplu);
    std::cout << colind::getIdMax() << "\n";
    std::cout << "--------------\n";
    std::cout << a2;
    std::cout << "--------------\n";
    a2.ordoneaza_nume();
    std::cout << a2;
    std::cout << "--------------\n";
    a2.ordoneaza_durata();
    std::cout << a2;
    return 0;
}

void f1() {
    try {
        std::cout << "f1 inainte\n";
        f2();
        std::cout << "f1 dupa\n";
    }
    catch(std::logic_error &err) {
        std::cout << "in catch f1: " << err.what() << "\n";
    }
}

void f2() {
    auto cantec_ok = cantec_aniversar("asd", 4, "la");
    auto cantec_prea_scurt = cantec_aniversar("asdf", 0.4, "fa");
    std::cout << "dupa cantec_prea_scurt\n";
}
