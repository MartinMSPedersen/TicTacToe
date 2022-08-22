#!/bin/bash

docker container run -u $(id -u):$(id -g) \
       -v $PWD:/root \
       -w /root mono mcs ./TicTacToe.cs ./TicTacToeBoard.cs
