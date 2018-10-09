main: server filereader delayFileReader termEarlyFileReader abort_file_reader nonzero_exitCode_file_reader

server: server.c
	gcc  -g server.c -o server

filereader: file_reader.c
	gcc -Wall file_reader.c -o file_reader

delayFileReader:delay_file_reader.c
	gcc -Wall delay_file_reader.c -o delay_file_reader

termEarlyFileReader: term_early_file_reader.c
	gcc -Wall term_early_file_reader.c -o term_early_file_reader

abort_file_reader: abort_file_reader.c
	gcc -Wall abort_file_reader.c -o abort_file_reader

nonzero_exitCode_file_reader:nonzeroExitCode_file_reader.c
	gcc -Wall nonzeroExitCode_file_reader.c -o nonzeroExitCode_file_reader

clean:
	rm term_early_file_reader
	rm file_reader
	rm delay_file_reader
	rm server
	rm abort_file_reader
	rm nonzeroExitCode_file_reader
