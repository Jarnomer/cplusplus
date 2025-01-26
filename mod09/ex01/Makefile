NAME   := RPN

RM     := rm -rf
CLEAR  := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := main.cpp \
           RPN.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	@$(CLEAR)
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

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
