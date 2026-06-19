#include <iostream>

struct node {
    int code;
    float avg;

    node* ptr;
};

void newnode(node* &p, int code, float avg) {
    p = new(node);

    p->code = code;
    p->avg = avg;
    p->ptr = NULL;
}


void queuein(node* &p) {
    node *q, *r;

    int n;
    do { std::cin >> n; } while (n < 1);

    p = NULL;

    int code; float avg;
    
    for (int i = 0; i < n; i++) {
        std::cin >> code >> avg;

        if (p == NULL) {
            newnode(p, code, avg);
            q = p;
        }
        else {
            newnode(r, code, avg);
            q->ptr = r;
            q = r;
        }
    }
}

void llout(node* p) {
    while (p != NULL) {
        std::cout << p->code << '\t' << p->avg << std::endl;
        p = p->ptr;
    }
}

void llsort(node* p) {
    int code; float avg;
    node* q;

    while (p != NULL) {
        q = p->ptr;
        while (q != NULL) {
            if (p->avg < q->avg) {
                code = p->code;
                avg = p->avg;

                p->code = q->code;
                p->avg = q->avg;
            
                q->code = code;
                q->avg = avg;
            }

            q=q->ptr;
        }

        p = p->ptr;
    }
}

int main() {

    node* queue;
    queuein(queue);

    llout(queue);

    llsort(queue);
    llout(queue);

    return 0;
}