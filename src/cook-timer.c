// Cooking timer CLI application
#define MAX_TIMERS 3

#include <stdio.h>
#include <ncurses.h>

#include "timers.h"
#include "parsers.h"

struct Timer {
  int countdown;
};

struct TimerDetails {
  int countdown_seconds;
  char label[];
};

void init_display() {
  initscr();
}

void end_program() {
  getch();
  endwin();
}

void print_timers(struct Timer *timers[], int size) {
  printw("cooking timers coming soon ...\n");
  refresh();
}

int main (int argc, char *argv[]) {
  int (*(*timer_generators)(struct TimerDetails))[MAX_TIMERS];
  struct Timer *timers[MAX_TIMERS]; // arbitrary timer count maximum

  // parse input arguments (flags)
  //  translation from user flags to TimerDetails
  // return if invalid
  // produce init structure (array of timers with labels, durations)
  //  use TimerDetails from translation to populate list
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
  end_program();
}
