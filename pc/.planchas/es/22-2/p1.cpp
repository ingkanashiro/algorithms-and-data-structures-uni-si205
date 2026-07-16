#include <iostream>
#include <fstream>

/*
    [notas.txt]
        Cod     PP      EP  EF
        333     10.0    08  11
        111     08.5    12  12
        444     12.5    10  09
.
   [sustitutorio.txt]
        Cod     ES
        333     12
        444     19

*/

struct entry {
    int code;
    float pp, ep, ef;

    entry *ptr;
};

void newnode(entry *&p, int code, float pp, float ep, float ef) {
    if (p == NULL) {
        p = new(entry);

        p->code = code;
        p->pp = pp;
        p->ep = ep;
        p->ef = ef;

        p->ptr = NULL;
    }
    else {
        newnode(p->ptr, code, pp, ep, ef);
    }
}

void substitute(entry *&p, int code, float es) {

    if (p == NULL) {
        return;
    }
    
    if (p->code == code) {

        float sp, sf;
        sp = (p->pp + es + (2 * p->ef)) / 4;
        sf = (p->pp + p->ep + (2 * es)) / 4;

        if (sp > sf) {
            p->ep = es;
        }
        else {
            p->ef = es;
        }
    }
    else {
        substitute(p->ptr, code, es);
    }
}

void fget(entry *&p) {

    p = NULL;

    std::ifstream scores;
    scores.open("notas.txt");

    if (!scores) {
        throw std::runtime_error("couldn't resolve file 'notas.txt'.");
    }

    while (!scores.eof()) {
        int code; float pp, ep, ef;
        if (scores >> code >> pp >> ep >> ef) {
            newnode(p, code, pp, ep, ef);
        }
    }

    scores.close();

    std::ifstream sub;
    sub.open("sustitutorio.txt");

    if (!sub) {
        throw std::runtime_error("couldn't resolve file 'sustitutorio.txt'.");
    }

    while (!sub.eof()) {

        int code; float es;
        if (sub >> code >> es) {
            substitute(p, code, es);   
        }
    }

    sub.close();
}

void fout(entry *p) {

    std::ofstream file;
    file.open("notas.txt");

    if (!file) {
        throw std::runtime_error("couldn't resolve file 'notas.txt'.");
    }

    while (p != NULL) {
        file << p->code << "\t\t" << p->pp << "\t\t" << p->ep << "\t" << p->ef << std::endl;
        p = p->ptr;   
    }

    file.close();
}

int main() {

    entry *LIST;

    // read notas.txt and store in LIST
    // read sustis.txt and substitute values in LIST
    fget(LIST);

    // overwrite notas.txt with new values in LIST
    fout(LIST);

    return 0;
}