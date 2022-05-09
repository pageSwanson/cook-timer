## requirements
- command line entry point
  - '[--start, -s] \<timer-label\> xx:xx:xx'
  - no arguments or '--help, -h'
- command line user interaction
  - add new timer
  - add time to existing
  - cancel timer
  - save timer
  - load timer
- main view for timer(s)
  - display timer label(s)
  - display clock graphic
  - display countdown
- play sound repeating on elapsed timer
  - play sound at 10th of timer remaining (or sub 10 seconds)
- help output
  - on help flag '[--help, -h]', list available functions
- countdown back-end
  - decrement timer progress
  - update clock view
- clock display graphics
  - move 'hand' relative to countdown progress
  - blink clock slowly on remaining 10th of timer (or sub 10 seconds)
  - blink rapidly on 0 value countdown
  
## function groups
- command parsing
- graphics
- clock
- timers
- file management
- sound

## dependencies (what we'll likely outsource)
- console graphics library
- sound functions library

## eventualities
- file command options
  - load a timer group
  - save a timer group
  - line-separated file
    - "\<group-label\> \<timer-label\> xx:xx:xx [...]"
- file i/o
  - on load, update timers
  - on save, dump timer data to file
