NAME := sed

RM    := rm -rf
CLEAR := printf "\033c"

CC     := c++
CFLAGS := -Wall -Werror -Wextra

SOURCES := main.cpp \
           Sed.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

re: fclean all

run: all
	@$(CLEAR)
	@./$(NAME) main.cpp int ZZZ && cat main.replace

clean:
	$(RM) $(OBJECTS) main.replace

fclean: clean
	$(RM) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all re run
.PHONY: clean fclean
