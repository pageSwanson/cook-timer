// Cooking timer CLI application
#define MAX_TIMERS 3
#define INVALID_TIME_LIMIT 60
#define MAX_LABEL_LENGTH 20

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "timers.h"
#include "parsers.h"

struct timer_struct {
  int countdown_seconds;
  int remaining_seconds;
  char label[];
};

typedef struct timer_struct TimerStruct;

void init_display() {
  initscr();
}

void end_program() {
  getch();
  endwin();
}

void print_timers(TimerStruct *timer_array[], int size) {
  printw("cooking timers coming soon ...\n");
  refresh();
}

char * parse_timer_label (char * argument) {
    char label[MAX_LABEL_LENGTH + 1];
    strncpy(label, argument, MAX_LABEL_LENGTH);
    label[MAX_LABEL_LENGTH + 1] = '\0';

    return label;
}

bool parse_timers(TimerStruct *timer_array[], char * argv[], int argc) {
    int num_timers = (argc - 1) / 2; //Timers are every two arguments
    int arg_index = 1;
    for (int i = 0; i < num_timers; i++) {
        timer_array[i]->label = parse_timer_label(argv[arg_index]);
        arg_index++;
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        sscanf(argv[arg_index], "%d%*c%d%*c%d", &hours, &minutes, &seconds);
        // if (seconds >= INVALID_TIME_LIMIT) {
        //     return -1;
        // }
        seconds += (minutes * 60) + (hours * 3600);
        timer_array[i]->countdown_seconds = seconds;
        timer_array[i]->remaining_seconds = seconds;
    }
    return true;
}

int main (int argc, char *argv[]) {
  TimerStruct *timer_info_array[MAX_TIMERS];

  
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
