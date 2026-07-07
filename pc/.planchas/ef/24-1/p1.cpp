#include <iostream>
#include <fstream>
#include <cstring>

typedef char string[32];

struct temp {
    float val;
    int occur;

    temp *l, *r;
};

struct day {
    string name;
    int id;

    day *l, *r;
    temp *t;
};

void newtemp(temp *&t, float val) {

    if (t == NULL) {
        t = new(temp);

        t->val = val;
        t->occur = 1;

        t->l = NULL; t->r = NULL;
    }
    else if (val < t->val) {
        newtemp(t->l, val);
    }
    else if (val == t->val) {
        t->occur++;
    }
    else {
        newtemp(t->r, val);
    }
}

void newnode(day *&p, string name, int id, float val) {

    if (p == NULL) {
        p = new(day);

        strcpy(p->name, name);
        p->id = id;
        p->l = NULL; p->r = NULL; p->t = NULL;

        newtemp(p->t, val);
    }
    else if (id == p->id) {
        newtemp(p->t, val);
    }
    else if (id < p->id) {
        newnode(p->l, name, id, val);
    }
    else {
        newnode(p->r, name, id, val);
    }
}

void get(day *&p) {

    p = NULL;

    std::ifstream file;
    file.open("temperaturas.txt");

    if (!file) {
        throw std::runtime_error("we ran into an oopsie whoopie");
    }

    while (!file.eof()) {

        string in;
        if (file >> in) {

            int len = strlen(in); // 12.5MA
            string s1, s2;

            for (int i = 0; i < strlen(in); i++) {

                if (i < strlen(in) - 2) {
                    s1[i] = in[i];
                }
                else {
                    s1[i] = 0;

                    s2[0] = in[i];
                    s2[1] = in[i+1];
                    s2[2] = 0;

                    break;
                }                
            }

            std::cout << s1 << " " << s2;
            
            float temp; string dayname; int dayid;
            temp = atof(s1);

            // parse
            if (strcmp(s2, "LU") == 0) {
                strcpy(dayname, "Lunes");
                dayid = 0;
            }
            else if (strcmp(s2, "MA") == 0) {
                strcpy(dayname, "Martes");
                dayid = 1;
            }
            else if (strcmp(s2, "MI") == 0) {
                strcpy(dayname, "Miércoles");
                dayid = 2;
            }
            else if (strcmp(s2, "JU") == 0) {
                strcpy(dayname, "Jueves");
                dayid = 3;
            }
            else if (strcmp(s2, "VI") == 0) {
                strcpy(dayname, "Viernes");
                dayid = 4;
            }
            else if (strcmp(s2, "SA") == 0) {
                strcpy(dayname, "Sábado");
                dayid = 5;
            }
            else if (strcmp(s2, "DO") == 0) {
                strcpy(dayname, "Domingo");
                dayid = 6;
            }
            else {
                strcpy(dayname, "???");
                dayid = 7;
            }
            
            std::cout << "\t" << dayname << std::endl; 
            newnode(p, dayname, dayid, temp);
        }
    }

    file.close();
}

void tempout(temp *p) {

    if (p != NULL) {
        tempout(p->l);
        std::cout << "\t" << p->val << "\t(" << p->occur << ")" << std::endl; 
        tempout(p->r);
    }
}

void print(day *p) {

    if (p != NULL) {

        print(p->l);

        std::cout << p->name << ":" << std::endl;   
        tempout(p->t);

        print(p->r);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {

    day *list;
    get(list);

    print(list);

    return 0;
}
