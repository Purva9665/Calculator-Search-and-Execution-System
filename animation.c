#include <windows.h>
#include <stdio.h>

void setColor(int attr) {
    int h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, attr);
}

void gotoxy(int x, int y) {
    int h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

void clear() {
    system("cls");
}

void drawBox(int left, int top, int right, int bottom, int color) {
    setColor(color);
    int x,y;
    // top and bottom
    for (x = left; x <= right; x++) {
        gotoxy(x, top);
        printf("#");
        gotoxy(x, bottom);
        printf("#");
    }
    // sides
    for (y = top; y <= bottom; y++) {
        gotoxy(left, y);
        printf("#");
        gotoxy(right, y);
        printf("#");
    }
}

void drawTunnel() {
    int midX = 40;
    int midY = 12;
int i;
    for (i = 0; i < 8; i++) {
        clear();
        int left   = midX - 4 - i * 2;
        int right  = midX + 4 + i * 2;
        int top    = midY - 2 - i;
        int bottom = midY + 2 + i;

        // nearer boxes brighter, inner ones dim
        int colorOuter = 10;  // green
        int colorInner = 2;   // dark green

        drawBox(left, top, right, bottom, colorOuter);
        if (i > 1) {
            drawBox(left + 2, top + 1, right - 2, bottom - 1, colorInner);
        }

        Sleep(120);
    }
}

void drawClacLogo() {
    int x = 34;
    int y = 9;

    // shadow
    setColor(8); // gray
    gotoxy(x + 1, y + 1);     printf(" ______________ ");
    gotoxy(x + 1, y + 2);     printf("|              |");
    gotoxy(x + 1, y + 3);     printf("|______________|");

    // small “loading” text
    setColor(14); // yellow
    gotoxy(x + 2, y + 5);
    printf("Initializing rates...");

    Sleep(1000);
}

int main() {
    // optional: hide cursor
    int
 h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(h, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(h, &ci);

    drawTunnel();
    clear();
    drawClacLogo();

    // pause before you clear to your real menu
    Sleep(1500);
    clear();

    // here you would show your main menu

    // restore cursor
    ci.bVisible = TRUE;
    SetConsoleCursorInfo(h, &ci);
    setColor(7);
    return 0;
}
