# Minitalk

{EPITECH.} first year project.

This project consists of:
 - A server that receives data in binary format
 - A client that takes a string as argument, translates it to binary & sends it to the server

The data is sent from the client to the server using [UNIX signals SIGUSR1 & SIGUSR2](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html).

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `./server/server` & `./client/client` executable files.

You can run `make client` to compile the client only, or `make server` to compile the server only.

## How to use Minitalk?

 - Compile the 2 executable files (see **Compilation** above).
 - Run the server inside the `server/` directory:
 ```
 ./server/server
 ```
 - The server outputs its [PID](http://www.linfo.org/pid.html), note it down: the client needs it to connect to the server.
 - Send messages to the server using the client under the `client/` directory:
 ```
 ./client/client [SERVER PID] [MESSAGE]
 ```
