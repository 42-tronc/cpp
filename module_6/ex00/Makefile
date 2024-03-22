# --------- GLOBAL VARIABLES ----------
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c # strict bash mode
# MAKEFLAGS += --warn-undefined-variables # warn about Make variables that don’t exist
MAKEFLAGS += --no-print-directory # don’t print the directory name before executing a recipe
.DELETE_ON_ERROR:


# ------------ AFormATTING -------------
# see https://misc.flogisoft.com/bash/tip_colors_and_AFormatting
FG_BLACK 			:= \033[30m
FG_RED 				:= \033[31m
FG_GREEN 			:= \033[32m
FG_YELLOW 			:= \033[33m
FG_BLUE 			:= \033[34m
FG_MAGENTA 			:= \033[35m
FG_CYAN 			:= \033[36m
FG_LIGHT_GRAY 		:= \033[37m
FG_DEFAULT 			:= \033[39m
FG_DARK_GRAY 		:= \033[90m
FG_LIGHT_RED 		:= \033[91m
FG_LIGHT_GREEN 		:= \033[92m
FG_LIGHT_YELLOW 	:= \033[93m
FG_LIGHT_BLUE 		:= \033[94m
FG_LIGHT_MAGENTA 	:= \033[95m
FG_LIGHT_CYAN 		:= \033[96m
FG_WHITE 			:= \033[97m

BG_BLACK 			:= \033[40m
BG_RED 				:= \033[41m
BG_GREEN 			:= \033[42m
BG_YELLOW 			:= \033[43m
BG_BLUE 			:= \033[44m
BG_MAGENTA 			:= \033[45m
BG_CYAN 			:= \033[46m
BG_LIGHT_GRAY 		:= \033[47m
BG_DEFAULT 			:= \033[49m
BG_DARK_GRAY 		:= \033[100m
BG_LIGHT_RED 		:= \033[101m
BG_LIGHT_GREEN 		:= \033[102m
BG_LIGHT_YELLOW 	:= \033[103m
BG_LIGHT_BLUE 		:= \033[104m
BG_LIGHT_MAGENTA 	:= \033[105m
BG_LIGHT_CYAN 		:= \033[106m
BG_WHITE 			:= \033[107m

BOLD		:= \033[1m
DIM			:= \033[2m
ITALIC		:= \033[3m
UNDERLINE	:= \033[4m
STRIKED		:= \033[9m
RESET		:= \033[0m


# ---------- BASIC VARIABLES ----------
CC := c++
C_FLAGS := -Wall -Wextra -Werror -std=c++98 -g3
FSANITIZE = -fsanitize=address
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes

RM := rm -rf
USER := $(shell whoami)

SRC_FOLDER := ./
OBJ_DIR := obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))


# --------- PROJECT VARIABLES ---------
NAME := convert
HEADER := ScalarConverter.hpp
SRC := main.cpp ScalarConverter.cpp

# -------------- RECIPES --------------
all: $(NAME) | $(OBJ_DIR)

$(NAME): $(OBJ)
	@echo -e "\n$(BOLD)Hello $(FG_ORANGE)$(USER)$(RESET)"
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)
	@echo -e "$(BG_LIGHT_GREEN)Compiled:\t$(RESET) $(FG_WHITE)$(UNDERLINE)$(NAME)$(RESET) has been created."

$(OBJ_DIR)%.o : $(SRC_FOLDER)%.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(C_FLAGS) -o $@ -c $<

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	$(RM) *_shrubbery
	@echo -e "$(FG_RED)Clean:\t\t $(FG_LIGHT_GRAY)$(ITALIC)$(NAME) object files$(RESET) have been deleted"

fclean: clean
	$(RM) $(NAME)
	@echo -e "$(FG_RED)FClean:\t\t $(FG_LIGHT_GRAY)$(UNDERLINE)$(NAME)$(RESET) has been deleted."

re: fclean
	@$(MAKE) all

debug: C_FLAGS += $(FSANITIZE)
debug: fclean $(NAME)

valgrind: VALGRIND = valgrind $(VALGRIND_FLAGS)
valgrind: run

run: all
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME) 0
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME) nan
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME) 42.0f
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME) -inf
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME) 2147483649
	@echo -e "\e[30m"
	$(VALGRIND) ./$(NAME)
# $(VALGRIND) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re debug valgrind test
