Just type "make" to compile server , file_reader
It might have errors with different kinds of browsers. The Chrome and Safari is somehow not working. The Firefox is good.




Can:

Multiplexing
Info
died child is changed to add when request is freeed

P.S.
when a child exit , the main program receive the signal , and turn wait the pid then turn the client pid to -1 , just do this only.

whether a request is freed is based on 
1.The CGI running is 0 (be set when "read" part , the ret is 0 , or the info mode in "write" part , handle specifically.)

2.buf_len = 0 

3.request status != 0


