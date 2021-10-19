#include <vector>
#include <string>
#include <iostream>

using namespace std::string_literals;

class cantec {
    std::string nume;
    std::string gama;
    float durata;
public:
    cantec(const std::string &nume, float durata, const std::string &gama) : nume(nume), gama(gama), durata(durata) {}

    friend std::ostream &operator<<(std::ostream &os, const cantec &cantec) {
        os << "nume: " << cantec.nume << " gama: " << cantec.gama << " durata: " << cantec.durata << "\n";
        return os;
    }
};

class album {
    std::string nume;
    std::vector<cantec> cantece;
public:
    friend std::ostream &operator<<(std::ostream &os, const album &album) {
        os << "nume: " << album.nume << " cantece:\n";
        for(const auto & cantec : album.cantece)
            os << "\t" << cantec;
        return os;
    }

public:
    void adauga(cantec cantec) {
        cantece.push_back(cantec);
    }

    album(const std::string &nume) : nume(nume) {}

    album(const std::string &nume, const std::vector <cantec> &cantece) : nume(nume), cantece(cantece) {}

    album(const album& copie) {
        this->nume = copie.nume;
//        this->cantece = copie.cantece;
//        for(int i = 0; i < copie.cantece.size(); i++) {
//            this->cantece.push_back(copie.cantece[i]);
//        }
        for(const auto & cantec : copie.cantece) {
            this->cantece.push_back(cantec);
        }
    }

    album& operator=(const album& copie) {
        if(this != &copie) {
            this->nume = copie.nume;
            this->cantece = copie.cantece;
            //std::copy(copie.cantece.begin(), copie.cantece.end(), std::back_inserter(cantece));
        }
        return *this;
    }

    album() = default;

    ~album() {
        std::cout << "destructor album\n";
    }
};

class cantaret {
    std::string nume;
    std::string instrument;
public:
    cantaret(const std::string &nume, const std::string &instrument) : nume(nume), instrument(instrument) {}

    friend std::ostream &operator<<(std::ostream &os, const cantaret &cantaret) {
        os << "nume: " << cantaret.nume << " instrument: " << cantaret.instrument << "\n";
        return os;
    }
};

class grupare_artistica {
    std::string nume;
    std::vector<cantaret> membri;
    std::vector<album> albume;
public:
    grupare_artistica(const std::string &nume, const std::vector <cantaret> &membri) : nume(nume), membri(membri) {}

    friend std::ostream &operator<<(std::ostream &os, const grupare_artistica &grupare) {
        os << "nume: " << grupare.nume << "\n\tmembri: ";
        for(const auto& membru : grupare.membri)
            os << membru;
        os << "\talbume: ";
        for(const auto& album: grupare.albume)
            os << album;
        return os;
    }

    void adauga(album album) {
        albume.push_back(album);
    }
};

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
