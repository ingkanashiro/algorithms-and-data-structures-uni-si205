#include <iostream>
#include <fstream>
#include <cstring>

typedef char codestr[6];
typedef char string[32];

struct course {
    codestr code;
    string name, area;

    int p1, p2, p3, p4;

    course *ptr;
};

struct student {
    int code;
    string lname, fname;

    student *ptr;
    course *list;
};

void newnode(course *&c, codestr code, string name, string area, int p1, int p2, int p3, int p4) {
    if (c == NULL) {
        c = new(course);

        strcpy(c->code, code);
        strcpy(c->name, name);
        strcpy(c->area, area);
        
        c->p1 = p1;
        c->p2 = p2;
        c->p3 = p3;
        c->p4 = p4;

        c->ptr = NULL;
    }
    else {
        newnode(c->ptr, code, name, area, p1, p2, p3, p4);
    }
}

void newnode(student *&s, int code, string lname, string fname, codestr ccode, string cname, string carea, int p1, int p2, int p3, int p4) {
    if (s == NULL) {
        s = new(student);

        s->code = code;
        strcpy(s->lname, lname);
        strcpy(s->fname, fname);

        s->ptr = NULL; s->list = NULL;
        newnode(s->list, ccode, cname, carea, p1, p2, p3, p4);
    }
    else if (s->code == code) {
        newnode(s->list, ccode, cname, carea, p1, p2, p3, p4);
    }
    else {
        newnode(s->ptr, code, lname, fname, ccode, cname, carea, p1, p2, p3, p4);
    }
}

void readf(student *&dest) {

    std::ifstream scores;
    scores.open("notas.txt");

    if (!scores) {
        throw std::runtime_error("couldn't open notas.txt");
    }

    dest = NULL;

    while (!scores.eof()) {
        int code; codestr ccode; int p1, p2, p3, p4; string ln, fn, desc, area;
        if (scores >> code >> ccode >> p1 >> p2 >> p3 >> p4) {

            // search student and course
            std::ifstream students, courses;
            students.open("alumnos.txt");

            if (!students) {
                throw std::runtime_error("couldn't open alumnos.txt");
            }

            while (!students.eof()) {
                int v;
                if (students >> v >> ln >> fn) {
                    if (code == v) {
                        break;
                    }
                }
            }

            students.close();
            courses.open("cursos.txt");

            if (!courses) {
                throw std::runtime_error("couldn't open cursos.txt");
            }

            while (!courses.eof()) {
                codestr c;
                if (courses >> c >> desc >> area) {
                    if (strcmpi(ccode, c) == 0) {
                        break;
                    }
                }
            }

            courses.close();
            
            newnode(dest, code, ln, fn, ccode, desc, area, p1, p2, p3, p4);    
        }
    }

    scores.close();
}

void llout(course *&c) {
    if (c != NULL) {
        float avg = c->p1 + c->p2 + c->p3 + c->p4; avg /= 4;
        std::cout << "\t" << c->code << "\t" << c->name << "\t\t" << avg << std::endl;
        llout(c->ptr);
    }
    else {
        std::cout << std::endl;
    }
}

void llout(student *&s) {
    if (s != NULL) {
        std::cout << s->code << "\t" << s->lname << ", " << s->fname << ":" << std::endl;
        llout(s->list);
        llout(s->ptr);
    }
}

int main() {

    student *list;

    readf(list);
    llout(list);
}