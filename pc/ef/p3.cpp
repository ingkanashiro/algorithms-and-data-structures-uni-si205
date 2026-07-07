#include <iostream>
#include <string.h>

typedef char string[64];

void build(string postorder, string preorder, string inorder) {

    if (strlen(preorder) == 1) {
        strcpy(postorder, preorder);
        return;
    }

    string left, right, center;
    // the left goes until a char exceeds the center
    
    int c = 0, r = 0;
    for (int i = 0; i < strlen(preorder); i++) {
    
        while (preorder[0] != inorder[c]) c++; r = c+1;
        while (preorder[r] < preorder[0]) r++;

    }

    center[0] = preorder[0]; center[1] = 0;
    int ll = 0, rr = 0;
    for (int i = 1; i < strlen(preorder); i++) {
        if (i < r) {
            left[ll] = preorder[i];
            ll++;
        }
        else {
            right[rr] = preorder[i];
            rr++;
        }
    }

    left[ll] = 0;
    right[rr] = 0;

    string leftn, rightn;
    build(leftn, left, inorder);
    build(rightn, right, inorder);

    strcpy(postorder, left);
    strcat(postorder, right);
    strcat(postorder, center);
}

int main() {

    string preorder, inorder;

    std::cout << "Preorden: "; gets(preorder);  fflush(stdin);
    std::cout << "En orden: "; gets(inorder);   fflush(stdin);

    string postorder;
    build(postorder, preorder, inorder);



}