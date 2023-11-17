#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();

    // Check if terminal supports colors
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    // Start color mode
    start_color();

    // Set up colors (pair number, foreground, background)
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Set the current color to pair 1
    attron(COLOR_PAIR(1));

    // Get the dimensions of the terminal window
    int height, width;
    getmaxyx(stdscr, height, width);

    // Calculate the position for the "Hello, ncurses!" message
    int x = (width - 13) / 2;
    int y = height / 2;

    // Print the message in the center of the window
    mvprintw(y, x, "Hello, ncurses!");

    // Refresh the screen
    refresh();

    // Wait for a key press
    getch();

    // End ncurses
    endwin();

    return 0;
}
