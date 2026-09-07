#include <stdio.h>
#include <stdlib.h>

int main() {
    int in_single = 0, in_double = 0;
    int prev = '\n';
    int c;
    while ((c = getchar()) != EOF) {
        if (!in_single && !in_double && c == '#' &&
            (prev == '\n' || prev == ' ' || prev == '\t')) {
            while ((c = getchar()) != EOF && c != '\n');
            if (c == EOF) break;
            putchar('\n');
            prev = '\n';
            continue;
        }

        if (c == '\'' && in_single) {
            putchar(c);
            if ((c = getchar()) == EOF) break;
            putchar(c);
            prev = 'x';
            continue;
        }

        if (c == '\'' && !in_double)
            in_single = !in_single;
        else if (c == '"' && !in_single)
            in_double = !in_double;

        putchar(c);
        prev = c;
    }
    return EXIT_SUCCESS;
}
