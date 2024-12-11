NAME := harlFilter

RM    := rm -rf
CLEAR := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := main.cpp \
           Harl.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	@$(SCREENCLEAR)
	@./$(NAME) "INFO"
	@./$(NAME) "ERROR"
	@./$(NAME) "NOPE"

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
