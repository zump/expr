#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double arg_to_int(char *arg, char *ints, int len) {
    char *sc = ints;
    sprintf(sc, "%c", 0);
    for (int i=0; i<len; i++) {
        if (isdigit(arg[i]) || arg[i] == '.') {
            sprintf(sc, "%s%c", sc, arg[i]);
        };
    };
    return atof(sc);
}

int main(int argc, char *argv[]){
    if (argv[1] == NULL) {
        printf("Expression invalid.\n");
        exit(1);
    } else if (argv[2] == NULL) {
        printf("Expression invalid.\n");
        exit(1);
    } else if (argv[3] == NULL) {
        printf("Expression invalid.\n");
        exit(1);
    } else if (strlen(argv[2]) != 1) {
        printf("Expression invalid.\n");
        exit(1);
    };
    char *m1 = malloc(strlen(argv[1])+1);
    long double one = arg_to_int(argv[1], m1, strlen(argv[1]));
    char sym = (char)*argv[2];
    char *m2 = malloc(strlen(argv[3])+1);
    long double two =  arg_to_int(argv[3], m2, strlen(argv[3]));
    switch (sym) {
        case '+':
        printf("%.16Lg\n", one+two); break;
        case '-':
        printf("%.16Lg\n", one-two); break;
        case '*':
        printf("%.16Lg\n", one*two); break;
        case '/':
        printf("%.16Lg\n", one/two); break;
        case '%':
        printf("%.16g\n", remainder(one, two)); break;
    }
    free(m1);
    free(m2);
    exit(0);
}
