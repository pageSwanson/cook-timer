// Cooking timer CLI application
#define MAX_TIMERS 3
#define INVALID_TIME_LIMIT 60
#define MAX_LABEL_LENGTH 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "timers.h"
#include "parsers.h"

struct timer_struct {
  int countdown_seconds;
  int remaining_seconds;
  char label[MAX_LABEL_LENGTH + 1];
};

typedef struct timer_struct TimerStruct;

void parse_timer_label(char *argument, char *label) {
    strncpy(label, argument, MAX_LABEL_LENGTH);
    label[MAX_LABEL_LENGTH + 1] = '\0';
}

bool parse_timers(TimerStruct timer_array[], char *argv[], int num_timers) {
    int arg_index = 1;
    for (int i = 0; i < num_timers; i++) {
      parse_timer_label(argv[arg_index], timer_array[i].label);
      arg_index++;
      int hours = 0;
      int minutes = 0;
      int seconds = 0;
      sscanf(argv[arg_index], "%d:%d:%d", &hours, &minutes, &seconds);
      seconds += (minutes * 60) + (hours * 3600);
      timer_array[i].countdown_seconds = seconds;
      timer_array[i].remaining_seconds = seconds;
      arg_index++;
    }
    return true;
}

void init_display() {
  initscr();
}

void end_display() {
  getch();
  endwin();
}

void build_timer_string(TimerStruct timer_struct) {
  char *timer_format_string = malloc( 
    strlen("label: ") + MAX_LABEL_LENGTH +
    strlen(", seconds: ") + 6 + 1); // max value of seconds is 359999 for our program
  sprintf(timer_format_string, 
    "label: %s , seconds: %d", 
    timer_struct.label, timer_struct.countdown_seconds);
    printw("%s\n", timer_format_string);
}

void print_timers(TimerStruct timer_array[], int size) {
  addch('\n');
  for (int i = 0; i < size; i++) {
    build_timer_string(timer_array[i]);
  }
  refresh();
}

int main(int argc, char *argv[]) {
  TimerStruct * timer_array = malloc(MAX_TIMERS * sizeof(TimerStruct));

  if (argc > 7 || argc < 3) {
    printf("Maximum number of timers is 3\n Usage: cook-timer timerlabelnospaces 00:00:00 ...\n");
    return 0;
  }

  int num_timers = (argc - 1) / 2; // Timers are made up of arg pairs
  if (!parse_timers(timer_array, argv, num_timers)) {
    printf("Unable to parse timer input, closing early.\n");
    return 0;
  }

  init_display();
  // start timers
  // expire or update remaining time on timers (on separate thread)
  print_timers(timer_array, num_timers);
  // while (1) {
  // parse commands (pause, quit, pause <timer-label>, add <timer-label> xx:xx:xx)
  //  check for user input at each cycle
  // translation to functions
  // produce updated list
  // print curses from list
  // limit main thread loop per .25 seconds?
  // }
  // outside of loop
  end_display();
}
