# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2018/02/12 17:11:50 by mcanal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= libshvm
CFLAGS += -Werror -Wextra -Wall
RCFLAGS = -O2 -fomit-frame-pointer
DCFLAGS = -g3 -DDEBUG
SCFLAGS = $(DCFLAGS) -fsanitize=address,undefined -ferror-limit=5
CC ?= gcc

INC_PATH = include
SRC_PATH = src
OBJ_DIR ?= obj
OBJ_PATH ?= $(OBJ_DIR)/rel
3TH_PATH =

LIBS =
ifneq (,$(findstring dev,$(NAME)))
LIB_NAME = $(addsuffix .dev, $(LIBS))
else ifneq (,$(findstring san,$(NAME)))
LIB_NAME = $(addsuffix .san, $(LIBS))
else
LIB_NAME = $(LIBS)
endif
3TH_NAME =
SRC_NAME = \
	bi.c bi/bg.c bi/env.c bi/export.c bi/fg.c bi/jobs.c bi/setenv.c bi/unset.c \
	bi/unsetenv.c \
	env.c \
	job.c job/completed.c job/cont.c job/mark.c job/stopped.c job/wait \
	op.c op/exec.c op/fork.c op/jump.c op/pipe.c op/term.c op/wait.c op/word.c \
	proc.c \
	var.c \
	vm.c

3TH = $(addprefix $(3TH_PATH)/, $(3TH_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LNK = $(addprefix -L, $(3TH))
INC = $(addprefix -I, $(INC_PATH) $(addsuffix /include, $(3TH)))
LIB = $(addprefix -l, $(LIB_NAME))
DEP = $(OBJ:%.o=%.d)

all:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) &&) true
endif
	+$(MAKE) $(NAME).a "CFLAGS = $(RCFLAGS)" "OBJ_PATH = $(OBJ_DIR)/rel"

dev:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) dev &&) true
endif
	+$(MAKE) $(NAME).dev.a "NAME = $(NAME).dev" "CFLAGS = $(DCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/dev"

san:
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) san &&) true
endif
	+$(MAKE) $(NAME).san.a "NAME = $(NAME).san" "CFLAGS = $(SCFLAGS)" \
	  "OBJ_PATH = $(OBJ_DIR)/san" "CC = clang"

$(NAME).a: $(OBJ)
	ar -rc $(NAME).a $(OBJ)
	ranlib $(NAME).a
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): lib"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(shell dirname $@)
	@printf "\r%-20s$<\n" "$(NAME):"
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@
	@printf "\033[A\033[2K"

clean:
	rm -f $(OBJ) $(DEP)
	rm -f $(OBJ:$(OBJ_DIR)/rel%=$(OBJ_DIR)/dev%) $(DEP:$(OBJ_DIR)/rel%=$(OBJ_DIR)/dev%)
	rm -f $(OBJ:$(OBJ_DIR)/rel%=$(OBJ_DIR)/san%) $(DEP:$(OBJ_DIR)/rel%=$(OBJ_DIR)/san%)
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

fclean: clean
ifneq ($(3TH_NAME),)
	+$(foreach 3th,$(3TH_NAME),$(MAKE) -C $(3TH_PATH)/$(3th) fclean &&) true
endif
	test -d $(OBJ_DIR) && find $(OBJ_DIR) -type d | sort -r | xargs rmdir || true
	rm -f $(NAME){,.san,.dev}.a
	@printf  "%-20s\033[32m✔\033[0m\n" "$(NAME): $@"

re: clean all

-include $(DEP)

ifndef VERBOSE
.SILENT:
endif

test: all
	echo OK !

.PHONY: all, dev, san, $(NAME).a, clean, fclean, re
