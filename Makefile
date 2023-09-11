CCFLAGS=-Wall -Werror
CC=g++
HFILES=bankAccount.h transaction.h
OBFILES=bankAccount.o
all: bank

bankAccount.o: $(HFILES) bankAccount.cc
	$(CC) $(CFLAGS) -c bankAccount.cc

bank: $(HFILES) $(OBFILES) main.cc 
	$(CC) $(CFLAGS) -o $@ $(OBFILES) main.cc

clean:
	rm *.o bank