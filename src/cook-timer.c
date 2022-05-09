// Cooking timer CLI application
#define MAX_TIMERS 3

#include <stdio.h>
#include <ncurses.h>

#include "timers.h"
#include "parsers.h"

struct TimerInfo {
  int countdown_seconds;
  int remaining_seconds;
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
  struct TimerInfo *timer_info_array[MAX_TIMERS];

  // parse input arguments (flags)
    // produce init data structure (array of timers with labels, durations)
    // use translation function from argv to populate list
    // timer_info_array
  // return if invalid (do not start program)

  init_display();
  // start timers
  // expire or update remaining time on timers (on separate thread)
  print_timers(timer_info_array, 0);
  // while (1) {
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
