#include <stdio.h>
int main () {
    int c, nl, nw;
    nl = nw = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' ) {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
            ++nw;
    }
    printf ("%d %d\n", nl, nw);
    return 0;
}
