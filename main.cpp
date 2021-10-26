#include <vector>
#include <string>
#include <iostream>
#include "cantec.h"
#include "album.h"
#include "cantaret.h"
#include "grupare_artistica.h"

using namespace std::string_literals;

int main() {
    cantec la_multi_ani{"LMA"s, 1.3, "la_major"s};
    cantec c2 = cantec{"gaudeamus igitur"s, 4.2, "sol_major"s};
    cantec c3 = cantec{"abc"s, 2.2, "sol_minor"s};
    album a1("clasice");
    a1.adauga(c2);
    a1.adauga(la_multi_ani);
    album a2 = album("experimental", {c3});
    album a3;
//    a3.operator=(a1.operator=(a2));
//    a3 = (a1 = a2); // echivalent cu mai sus
//    a3 = a1 = a2;
//    (a3 = a1) = a2; // daca chiar vrem asta, trebuie paranteze
    cantaret viorel("c1", "vioara");
    cantaret petru("c1", "pian");
    grupare_artistica grup("lautari", {viorel, petru});
    grup.adauga(a1);
    std::cout << grup;
    return 0;
}
