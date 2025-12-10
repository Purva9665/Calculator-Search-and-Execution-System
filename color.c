#include <windows.h>
#include <stdio.h>

int main() {
int i;
    int h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (i = 0; i < 16; i++) {
        SetConsoleTextAttribute(h, i);
        printf("Color code %d sample text\n", i);
    }

    // Reset to normal gray on black
    SetConsoleTextAttribute(h, 7);
    return 0;
}
