#!/bin/bash

docker container run -v $PWD:/usr/src -w /usr/src mono mcs TicTacToeBoard.cs 

