// Cooking timer CLI application
#define MAX_TIMERS 3
#define INVALID_TIME_LIMIT 60

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "timers.h"
#include "parsers.h"

struct TimerInfoStruct {
  int countdown_seconds;
  int remaining_seconds;
  char label[];
};

typedef struct TimerInfoStruct TimerInfo;

void init_display() {
  initscr();
}

void end_program() {
  getch();
  endwin();
}

void print_timers(TimerInfo *timers[], int size) {
  printw("cooking timers coming soon ...\n");
  refresh();
}

bool parse_timers(TimerInfo *timers[], char * argv[], int argc) {
    int numTimers = (argc - 1) / 2;
    int argIndex = 0;
    for (int i = 0; i < numTimers; i++) {
        strcpy(timers[i]->label, argv[argIndex]);
        argIndex++;
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        sscanf(argv[argIndex], "%d%*c%d%*c%d", &hours, &minutes, &seconds);
        // if (seconds >= INVALID_TIME_LIMIT) {
        //     return -1;
        // }
        seconds += (minutes * 60) + (hours * 3600);
        timers[i]->countdown_seconds = seconds;
        timers[i]->remaining_seconds = seconds;
    }
    return true;
}

int main (int argc, char *argv[]) {
  TimerInfo *timer_info_array[MAX_TIMERS];

  
  if (argc > 7 || argc < 2) {
      fprintf(stdout, "Maximum number of timers is 3\n Usage: ./cook-timer timerlabelnospaces 00:00:00 ...\n");
      end_program();
  }
  parse_timers(timer_info_array, argv, argc);

  
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
