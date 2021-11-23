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

void f1();
void f2();
using namespace std::string_literals;

class baza {
public:
    baza() = default;
};

int main() {
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
    album a1("clasice");
    a1.adauga(c2);
    a1.adauga(la_multi_ani);
    a1.adauga(col);
    a1.adauga(men);
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
        //throw eroare_cantec("");
        //throw;
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
