## requirements
- command line entry point
  - '[--start, -s] \<timer-label\> xx:xx:xx'
  - no arguments or 
  - '--help, -h'
- command line user interaction
  - add new timer
  - add time to existing
  - pause timer
  - restart timer
- main view for timer(s)
  - display timer label(s)
  - display clock graphic
  - display countdown
  - click to restart, pause
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

## Application architecture
- A C module system
- published with compile instructions for WebAssembly

### initial target
- compile tested with [Emscripten](https://github.com/emscripten-core/emscripten)
  - tasks for [visual studio code](https://github.com/dcodeIO/webassembly/blob/master/.vscode/c_cpp_properties.json)
- consumed via a WebAssembly runtime
  - tested with [wasmtime](https://wasmtime.dev/)
  - via the [Rust API](https://crates.io/crates/wasmtime)
  - tui.rs frontend

### eventual test targets:
- tested with [firefox](https://developer.mozilla.org/en-US/docs/WebAssembly/Loading_and_running)
  - elm frontend
  - ClojureScript frontend
- [wasmer](https://wasmer.io/) runtime
  - via the [Rust API](https://github.com/wasmerio/wasmer/blob/master/examples/README.md)
- [Go](https://docs.wasmtime.dev/lang-go.html)
  - bubbletea tui
- tested with the [deno](https://deno.land/manual@v1.26.2/webassembly/using_wasm)
  - serving module via web server to site
    - compiled server-side along with deno, served with deno
  - possibly svelte w/ [snel](https://github.com/crewdevio/Snel)
  - https://kit.svelte.dev/
  - abstracted away as requests when updating the page

## C module groups
- command parsing
- timers
- update events

## interface groups
- clock
- file management
- sound

## dependencies (what we'll likely outsource)
- console graphics library

## eventualities
- file command options
  - load a timer group
  - save a timer / timer group (definition, not state)
  - line-separated file
    - "\<group-label\> \<timer-label\> xx:xx:xx [...]"
- file i/o
  - on load, update timers
  - on save, dump timer data to file
- define a sequence of events along with the timer group definition
  - on load, fire the timers in sequence
  - timer sequence definition syntax
