NAME   := PmergeMe

NUMCOUNT := 10
INT_MAX  := 1000

RM     := rm -rf
CLEAR  := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := main.cpp \
           PmergeMe.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	@$(CLEAR)
	./$(NAME) $(shell shuf -i 0-$(INT_MAX) -n $(NUMCOUNT))

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
