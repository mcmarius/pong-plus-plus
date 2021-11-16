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

int main() {
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
