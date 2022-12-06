FROM mono:latest
ADD . /home/martin/ttt
RUN mcs /home/martin/ttt/*cs
CMD [ "mono", "/home/martin/ttt/TicTacToe.exe" ]
