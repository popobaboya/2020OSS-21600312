CC=gcc
TARGET = Product
DTARGET = Product_debug
DEPEND = market.c product.o manager.o

$(TARGET) : $(DEPEND)
	$(CC) -o $@ $^

$(DTARGET) : $(DEPEND)
	$(CC) -DDEBUG -o $@ $^

clean : 
	rm *.o $(TARGET) $(DTARGET)
