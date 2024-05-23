#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(const unsigned char *input, size_t input_len, char *output) {
    for (size_t i = 0, j = 0; i < input_len; i += 3, j += 4) {
        unsigned char b1 = input[i];
        unsigned char b2 = (i + 1 < input_len) ? input[i + 1] : 0;
        unsigned char b3 = (i + 2 < input_len) ? input[i + 2] : 0;

        output[j] = base64_chars[b1 >> 2];
        output[j + 1] = base64_chars[((b1 & 0x03) << 4) | (b2 >> 4)];
        output[j + 2] = (i + 1 < input_len) ? base64_chars[((b2 & 0x0F) << 2) | (b3 >> 6)] : '=';
        output[j + 3] = (i + 2 < input_len) ? base64_chars[b3 & 0x3F] : '=';
    }
}

int main() {
    char *s = (char *)malloc(sizeof(char) * 100);
    char *b = (char *)malloc(sizeof(char) * 100);

    scanf("%99s", s);
    const unsigned char *src = (const unsigned char *)s;
    base64_encode(src, strlen(s), b);

    printf("!!!%99s", b);

    free(b);
    free(s);

    return 0;
}
