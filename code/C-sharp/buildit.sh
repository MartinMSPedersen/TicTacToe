#!/bin/bash

docker container run -u $(id -u):$(id -g) \
       -v $PWD:/usr/src \
       -w /usr/src mono mcs ./TicTacToe.cs ./TicTacToeBoard.cs
