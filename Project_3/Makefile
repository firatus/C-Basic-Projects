compile:program run 
program:lib ana
	@g++ test.o -o test
lib:
	@g++ -c Store.h Person.h Customer.h Film.h
ana:
	@g++ -c test.cpp Store.h Person.h Customer.h Film.h
run:
	@./test