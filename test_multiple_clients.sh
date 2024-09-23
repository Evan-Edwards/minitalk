#!/bin/bash

SERVER_PID=$1

if [ -z "$SERVER_PID" ]; then
    echo "Usage: $0 <server_pid>"
    exit 1
fi

# Function to send a message from a client
send_message() {
    local message=$1
    echo "Sending message: $message"
    ./client $SERVER_PID "$message"
    if [ $? -ne 0 ]; then
        echo "Error: ./client exited with status $?"
    fi
}

# Launch multiple clients in the background
send_message "Hello from client 1" &
send_message "Hello from client 2" &
send_message "Hello from client 3" &
send_message "Hello from client 4" &
send_message "Hello from client 5" &

# Wait for all background jobs to finish
wait

echo "All messages sent."
