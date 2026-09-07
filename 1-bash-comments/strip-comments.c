// PID: 730844590
// I pledge the Comp211 honor code.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int in_quote = 0;
    int c;

    while ((c = getchar()) != EOF) {
        /* a double quote toggles whether we're inside a string literal;
           the quote character itself is still printed verbatim */
        if (c == '"') {
            in_quote = !in_quote;
            putchar(c);
            continue;
        }

        /* outside a string literal, '#' begins a comment */
        if (!in_quote && c == '#') {
            while ((c = getchar()) != EOF &&
                   c != '\n');   /* suppress output, extra '#'s included */
            if (c == EOF) break; /* never putchar(EOF) */
            putchar('\n');       /* output resumes at end of line */
            continue;
        }

        putchar(c);
    }
    return EXIT_SUCCESS;
}
