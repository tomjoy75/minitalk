#include <stdio.h>

int utf8_octet_count(unsigned char c) {
    if ((c & 0x80) == 0x00) { // 0xxxxxxx
        return 1;
    } else if ((c & 0xE0) == 0xC0) { // 110xxxxx
        return 2;
    } else if ((c & 0xF0) == 0xE0) { // 1110xxxx
        return 3;
    } else if ((c & 0xF8) == 0xF0) { // 11110xxx
        return 4;
    }
    return 0; // Caractère non valide ou continuation octet (10xxxxxx)
}

int main() {
    unsigned char test1 = 'a'; // ASCII, donc 1 octet
    unsigned char test2[] = {0xC3, 0xA9}; // 'é', 2 octets en UTF-8
    unsigned char test3[] = {0xF0, 0x9F, 0x98, 0x81}; // Emoji 😁, 4 octets en UTF-8

    printf("Octets pour 'a': %d\n", utf8_octet_count(test1));
    printf("Octets pour 'é': %d\n", utf8_octet_count(test2[0]));
    printf("Octets pour 😁: %d\n", utf8_octet_count(test3[0]));

    return 0;
}
