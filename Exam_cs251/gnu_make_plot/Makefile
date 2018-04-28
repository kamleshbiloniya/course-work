all:app
app:prog.o thread_function.o common.h
	gcc -o app prog.o thread_function.o -lm -lpthread
prog.o:prog.c common.h
	gcc -c prog.c -o prog.o -lm -lpthread

thread_function.o:thread_function.c common.h
	gcc -c thread_function.c -o thread_function.o -lm -lpthread
runtest:
	./runtest.sh
clean:
	rm -f *.o app file.txt avgfile
