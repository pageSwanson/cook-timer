// Cooking timer CLI application
#include <stdio.h>
#include <ncurses.h>

typedef struct Timer {
  int countdown;
} Timer;

void init_display() {
  initscr();
}

void close() {
  getch();
  endwin();
}

void print_timers(Timer *timers[], int size) {
  printw("cooking timers coming soon ...\n");
  refresh();
}

int main (int argc, char *argv[]) {
  Timer *timers[3]; // arbitrary timer maximum

  // parse args (flags)
  //  translation from user flags to functions
  // return if invalid
  // produce init structure (array of timers with labels, durations)
  //  use function instructions from translation to populate list
  init_display();
  // start timers
  print_timers(timers, 0);
  // while (1) {
  // manage + update timers (update graphics from countdown value)
  // parse commands (pause, quit, pause <timer-label>, add <timer-label> xx:xx:xx)
  //  check for user input at each cycle
  // translation to functions
  // produce updated list
  // print curses from list
  // limit main thread loop per .25 seconds?
  // }
  // outside of loop
  close();
}
