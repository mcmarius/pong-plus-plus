/*
test
*/
//
// Created by marius on 2021-11-16.
//

#include "erori_cantec.h"
#include <string>

eroare_cantec::eroare_cantec(const std::string &arg) : runtime_error("Eroare cantec: " + arg) {}

cantec_prea_scurt::cantec_prea_scurt() : eroare_cantec("Cantec prea scurt") {}

eroare_gama::eroare_gama() : eroare_cantec("Eroare gama") {
}

cantec_not_found::cantec_not_found(const std::string &arg) : eroare_cantec("Cantecul nu a fost gasit: " + arg) {
}
