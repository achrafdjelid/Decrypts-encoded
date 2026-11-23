#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NAME_COUNT 8
#define MAX_NAME_LENGTH 64

static const char alphabet[5][6] = {
    "TYGER",
    "ABCDF",
    "HIKLM",
    "NOPQS",
    "UVWXZ"
};

static const int row_move[] = {-1, 2, -3, 0};
static const int col_move[] = { 2,-1,  0, 3};

static char names[NAME_COUNT][MAX_NAME_LENGTH] = {
    "UANLZ KDB MAYG",
    "XWGFZUF YZR",
    "UQISS ROEZMM",
    "SIYMKW KSOEDI",
    "ZSI LARTE",
    "WDTMUQ UAILRDK",
    "UQVKAYQSB MKSSHZZMU",
    "LUEXSS TLPFUEGK"
};

static int wrap(int value)
{
    value %= 5;
    return value < 0 ? value + 5 : value;
}

static void decrypt_name(char *text)
{
    size_t i = 0;
    size_t length = strlen(text);
    int move = 0;

    while (i < length) {
        size_t start;
        size_t end;

        if (isspace((unsigned char)text[i])) {
            move = (move + 1) % 4;
            ++i;
            continue;
        }

        start = i;
        while (i < length && !isspace((unsigned char)text[i])) {
            ++i;
        }
        end = i;

        {
            size_t left = start;
            size_t right = end;

            while (left < right) {
                char temp = text[left];
                text[left] = text[right - 1];
                text[right - 1] = temp;
                ++left;
                --right;
            }
        }

        {
            size_t j;
            for (j = start; j < end; ++j) {
                int row;
                int col;
                int found = 0;
                int was_lower = islower((unsigned char)text[j]);
                char letter = (char)toupper((unsigned char)text[j]);

                for (row = 0; row < 5 && !found; ++row) {
                    for (col = 0; col < 5; ++col) {
                        if (alphabet[row][col] == letter) {
                            found = 1;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }

                if (found) {
                    row = wrap(row - row_move[move]);
                    col = wrap(col - col_move[move]);
                    letter = alphabet[row][col];
                    text[j] = was_lower ? (char)tolower((unsigned char)letter) : letter;
                }
                move = (move + 1) % 4;
            }
        }
    }
}

int main(void)
{
    int i;

    for (i = 0; i < NAME_COUNT; ++i) {
        decrypt_name(names[i]);
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}
