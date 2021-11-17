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

void f1();
void f2();
using namespace std::string_literals;

int main() {
    std::cout << cantec::getIdMax() << "\n";

    colind col{"jingle bells", 2.3};
    std::cout << colind::getIdMax() << "\n";
    col.play();
    cantec_aniversar la_multi_ani{"LMA"s, 1.3, "la_major"s};
//    la_multi_ani.play();


    auto c2 = cantec_aniversar{"gaudeamus igitur"s, 4.2, "sol_major"s};
    auto c3 = cantec_aniversar{"abc"s, 2.2, "sol_minor"s};
    album a1("clasice");
    a1.adauga(c2);
    a1.adauga(la_multi_ani);
    a1.adauga(col);
    a1.play();

    album a2 = album("experimental", {std::make_shared <cantec_aniversar>(c3)});
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

    try {
        f1();
        auto alt_cantec_ok = cantec_aniversar("asde", 5, "sol");
    }
    catch(eroare_cantec &error) {
        std::cout << error.what() << "\n";
    }






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
