NAME := phonebook

RM    := rm -rf
CLEAR := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := main.cpp \
           PhoneBook.cpp \
           Contact.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	$(CLEAR)
	@./$(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all re run
.PHONY: clean fclean
