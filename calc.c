#include <stdio.h>

extern int mystery(int a, int b);

typedef struct operation {
    char type;
    int a;
    int b;
} op;

/*
Takes as input a pointer to the starting element of an array of operations and
an integer length of the array.

Calc returns the final value of performing all the operations, in order, assuming the starting value is `0`.
If the operation "type" == ?, the final value should increment by the result of a call to "mystery" on a,b.
If the operation "type" == +, the final value should increment by the result of a + b.
If the operation "type" == -, the final value should increment by the result of a - b.
*/
int calc(op* ops, int op_len) {
    int val = 0;

    for (int i = 0; i < op_len; i++) {
        int a = ops[i].a;
        int b = ops[i].b;
        char type = ops[i].type;
        
        if (type == '?') {
            val += mystery(a, b);
        } else if (type == '+') {
            val += (a + b);
        } else if (type == '-') {
            val += (a - b);
        }
    }

    return val;
}

int main(void) {
    op cmd[] = {{'?',12,123}, {'+', 10,30}, {'-', 10,30}};
    printf("%d\n", calc(cmd, 3));
}