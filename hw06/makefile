all:
	gcc hw0601.c -o hw0601
	gcc -c function2.c -o function2.o
	gcc hw0602.c function2.o -o hw0602
	gcc -c function3.c -o function3.o
	gcc hw0603.c function3.o -o hw0603 -lm
	gcc -c function4.c -o function4.o
	gcc hw0604.c function4.o -o hw0604
	gcc -c function5.c -o function5.o
	gcc hw0605.c function5.o -o hw0605
	
clean:
	rm -rf hw0601
	rm -rf function2.o
	rm -rf hw0602
	rm -rf function3.o
	rm -rf hw0603
	rm -rf function4.o
	rm -rf hw0604
	rm -rf function5.o
	rm -rf hw0605
