//
// Created by marius on 2021-10-26.
//

#include "joc.h"
#include "rlutil.h"
#include <cstdlib>

std::ostream &operator<<(std::ostream &os, const dificultate &dif) {
    switch(dif) {
        case dificultate::USOR:
            os << "Usor";
            break;
        case dificultate::MEDIU:
            os << "Mediu";
            break;
        case dificultate::GREU:
            os << "Greu";
            break;
    }
    return os;
}

int joc::rulare() {
    int scor = 0, scor_anterior;
    int iteratii = 0;
    while(iteratii < 10) {
        if(kbhit()) {
            scor_anterior = scor;
            //std::cout << "aici\n";
            char c = rlutil::getkey();
            int rand_nr = std::rand() % 4;
            switch(c) {
                case rlutil::KEY_DOWN:
                    if(rand_nr == 0)
                        scor++;
                    break;
                case rlutil::KEY_UP:
                    if(rand_nr == 1)
                        scor++;
                    break;
                case rlutil::KEY_LEFT:
                    if(rand_nr == 2)
                        scor++;
                    break;
                case rlutil::KEY_RIGHT:
                    if(rand_nr == 3)
                        scor++;
                    break;
            }
            if(scor == scor_anterior)
                std::cout << "miss!\n";
            else
                std::cout << "hit!\n";
            iteratii++;
        }

    }
    return scor;
}

joc::joc(grupare_artistica &&grup, dificultate dif) : grup(std::move(grup)), dif(dif) {}
