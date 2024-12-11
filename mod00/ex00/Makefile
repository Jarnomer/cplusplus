NAME := megaphone

RM    := rm -rf
CLEAR := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := megaphone.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	@$(CLEAR)
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

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
