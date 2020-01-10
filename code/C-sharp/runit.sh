#!/bin/bash

docker container run -u $(id -u):$(id -g) -v $PWD/TicTacToeBoard.exe:/usr/src/TicTacToeBoard.exe -w /usr/src mono mono ./TicTacToeBoard.exe
