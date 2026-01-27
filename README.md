# FSM Kernel – AutoExample

This repository contains a message-driven **Finite State Machine (FSM) kernel**
with support for:
- multiple automates
- message boxes
- timers
- configurable memory buffers
- file-based logging

The project demonstrates the kernel usage through a simple example automate
called **AutoExample**, running inside a separate system thread.

---

## Project Structure

```

.
├── kernel/
│   ├── kernelTypes.h
│   ├── fsmsystem.h
│   ├── fsmsystem.cpp
│   ├── timer.h
│   ├── messagebox.h
│   └── ...
├── autoexample/
│   ├── AutoExample.h
│   └── AutoExample.cpp
├── log/
│   ├── logfile.h
│   ├── logfile.cpp
│   └── log.ini
├── main.cpp
├── log.log
└── README.md

````

> Kernel and logging files are provided, while `AutoExample` and `main.cpp`
represent user-modified / example code.

---

##  System Overview

- **FSMSystem**  
  Central kernel responsible for:
  - kernel initialization
  - automate registration
  - message dispatching
  - system lifecycle management

- **Automates**
  - Implement protocol logic as FSMs
  - Communicate exclusively via messages
  - Can use timers to trigger events

- **Message Boxes**
  - Identified by numeric IDs
  - Used for asynchronous communication

- **Timers**
  - Timer expiration generates messages
  - Used to model time-dependent behavior

- **Logging**
  - File-based logging (`log.log`)
  - Message translation via `log.ini`

---

##  AutoExample

The `AutoExample` automate demonstrates:
- FSM state transitions
- handling of messages such as:
  - `MSG_CHANGE_STATE`
  - `TIMER1_EXPIRED`
- interaction with kernel timers
- logging of state changes and events

Multiple instances of the same automate type can be created and executed
concurrently.

---

## How It Works

1. Kernel is initialized with configurable memory buffers
2. Automates are registered to the system
3. System thread is started
4. FSM system dispatches messages
5. Automates process events and change states
6. System runs until user stops it (keypress)

---

##  Notes

* Only automates can send messages
* FSM system must be initialized before use
* Logging configuration is defined in `log.ini`
* The system is designed for protocol and embedded-style simulations

---



