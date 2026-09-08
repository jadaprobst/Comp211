// PID: 730844590
// I pledge the COMP211 honor code.

#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS 26
#define CHART_HEIGHT 10

void count_letter(int c, int counts[]) {
    if (c >= 'a' && c <= 'z') {
        counts[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
        counts[c - 'A']++;
    }
}

void process_input(int counts[]) {
    int c;
    while ((c = getchar()) != EOF) {
        count_letter(c, counts);
    }
}

void display_counts(const int counts[]) {
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }
}

int total_letters(const int counts[]) {
    int total = 0;
    for (int i = 0; i < NUM_LETTERS; i++) {
        total += counts[i];
    }
    return total;
}

double percentage(int count, int total) {
    if (total == 0) {
        return 0.0;
    }
    return 100.0 * count / total;
}

void display_percentage(const int counts[]) {
    int total = total_letters(counts);
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (counts[i] > 0) {
            printf("%c: %.1f%%\n", 'a' + i, percentage(counts[i], total));
        }
    }
}

int max_count(const int counts[]) {
    int max = 0;
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (counts[i] > max) {
            max = counts[i];
        }
    }
    return max;
}

int bar_height(int count, int max) {
    if (max == 0) {
        return 0;
    }
    return count * CHART_HEIGHT / max;
}

void display_chart(const int counts[]) {
    int max = max_count(counts);
    for (int row = CHART_HEIGHT; row >= 1; row--) {
        for (int i = 0; i < NUM_LETTERS; i++) {
            if (bar_height(counts[i], max) >= row) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < NUM_LETTERS; i++) {
        printf("%c", 'a' + i);
    }
    printf("\n");
}

int main(void) {
    int counts[NUM_LETTERS] = {0};
    printf("%s\n", "Counts:");
    process_input(counts);
    display_counts(counts);

    printf("\n");
    printf("%s\n", "Percents:");
    display_percentage(counts);

    printf("\n");
    printf("%s\n", "Chart:");
    display_chart(counts);

    return EXIT_SUCCESS;
}