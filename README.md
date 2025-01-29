# minitalk

## Description
A small data exchange program using UNIX signals. This project consists of a client and server that communicate with each other using SIGUSR1 and SIGUSR2 signals. Developed as part of the 42 curriculum.

## Features

### Communication System
- Server displays its PID on launch
- Client can send strings to server
- Server accurately receives and displays the messages
- Support for all ASCII characters
- Handles multiple client connections

### Signal Handling
- SIGUSR1 and SIGUSR2 for binary communication
- Efficient signal acknowledgment
- Error handling for lost signals

## Getting Started

### Installation
Clone and compile the project:
```bash
git clone https://github.com/Evan-Edwards/minitalk.git
cd minitalk
make
```

### Usage
First, start the server:
```bash
./server
```

Then, in another terminal, run the client:
```bash
./client [server_pid] [message]
```

## Technical Details

### Server
- PID display on startup
- Signal handling setup
- Binary to ASCII conversion
- Message reconstruction
- Signal acknowledgment system

### Client
- Command-line argument validation
- ASCII to binary conversion
- Signal-based transmission
- Transmission confirmation

## Error Handling
- Invalid PID handling
- Signal transmission failures
- Memory allocation errors
- Invalid input validation
- Process termination handling

## Performance
The program is designed for reliable communication:
- Efficient signal handling
- Proper synchronization between client and server
- Minimal system resource usage
- Stable multi-client support

---
This project is part of the 42 School curriculum.