#!/bin/bash

docker container run -t -u $(id -u):$(id -g) \
       -v $PWD/TicTacToe.exe:/usr/src/TicTacToe.exe \
       -w /usr/src mono mono ./TicTacToe.exe
