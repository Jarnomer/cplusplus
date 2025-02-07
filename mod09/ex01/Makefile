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

#	✅ Valid Test Cases
	@./$(NAME) "9 9 *"            # 81
	@./$(NAME) "9 9 9 * *"        # 729
	@./$(NAME) "1 2 +"            # 3
	@./$(NAME) "8 3 -"            # 5
	@./$(NAME) "6 3 /"            # 2
	@./$(NAME) "9 1 - 2 *"        # 16
	@./$(NAME) "0 9 +"            # 9
	@./$(NAME) "9 9 9 - -"        # 9
	@./$(NAME) "3 3 * 2 * 2 *"    # 36
	@./$(NAME) "5 4 + 3 -"        # 6

#	❌ Invalid Test Cases
	@./$(NAME) "10 9 *"           # Error: Syntax error (Numbers must be between 0 and 9)
	@./$(NAME) "9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * * * * *"  # Error: Arithmetic overflow
	@./$(NAME) "9 0 /"            # Error: Arithmetic overflow (Division by zero)
	@./$(NAME) "3 +"              # Error: Syntax error (not enough operands)
	@./$(NAME) "3 3"              # Error: Syntax error (stack has more than one number at the end)
	@./$(NAME) "a b +"            # Error: Syntax error (invalid characters)
	@./$(NAME) "9 9 @ *"          # Error: Syntax error (invalid operator)
	@./$(NAME) ""                 # Error: Syntax error (empty input)
	@./$(NAME) " "                # Error: Syntax error (only spaces)
	@./$(NAME) "3 3 + 2 2 +"      # Error: Syntax error (leftover values in stack)

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
