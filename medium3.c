#include <stdio.h>
#include <string.h>
#include <ctype.h>

char decrypt_char(char ch, int shift) {
    ch = toupper(ch);
    int pos = ch - 'A';
    int new_pos = (pos - shift + 26) % 26;  // wrap around
    return 'A' + new_pos;
}

void decode_message(const char* input, char* output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = decrypt_char(input[i], i + 1);
    }
    output[len] = '\0';  // null-terminate the string
}

int main() {
    char input[100];
    char output[100];

    printf("Enter the encrypted message: ");
    scanf("%s", input);

    decode_message(input, output);
    printf("Decoded message: %s\n", output);

    return 0;
}
