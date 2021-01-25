all:
	gcc -c function1.c -o function1.o
	gcc -c function2.c -o function2.o
	gcc -c function3.c -o function3.o 
	gcc -c function4.c -o function4.o 
	
	gcc hw0501.c function1.o -o hw0501
	gcc hw0502.c function2.o -o hw0502
	gcc hw0503.c function3.o -o hw0503 -lm
	gcc hw0504.c function4.o -o hw0504 -lm

	
clean:
	rm -f function1.o
	rm -f function2.o
	rm -f function3.o
	rm -f function4.o
	rm -f hw0501
	rm -f hw0502
	rm -f hw0503
	rm -f hw0504
