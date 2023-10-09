CC = gcc 
CFLAGS = -g -Wall -Wextra -Werror
SOURCES = my_printf.c 
TARGET = my_printf 
 
$(TARGET):$(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) 
 
.PHONY: fclean 
 
fclean: 
	rm -rf $(TARGET)
