# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:53:35 by amerlon-          #+#    #+#              #
#    Updated: 2019/04/09 20:38:43 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	=	asm
DISASM_NAME	=	disassemble
VM_NAME		=	corewar
# VIS_NAME	=	visual

ASM_DIR		=	./Assembler
DISASM_DIR	=	./Disassembler
VM_DIR		=	./Virtual\ Machine
# VIS_DIR		=	./Visualisation

all: $(ASM_NAME) $(DISASM_NAME) $(VM_NAME)
# all: $(ASM_NAME) $(DISASM_NAME) $(VM_NAME) $(VIS_NAME)

$(ASM_NAME):
	@make -C $(ASM_DIR)
	@cp $(ASM_DIR)/$(ASM_NAME) .

$(DISASM_NAME):
	@make -C $(DISASM_DIR)
	@cp $(DISASM_DIR)/$(DISASM_NAME) .

$(VM_NAME):
	@make -C $(VM_DIR)
	@cp $(VM_DIR)/$(VM_NAME) .

# $(VIS_NAME):
# 	@make -C $(VIS_DIR)
# 	@cp $(VIS_DIR)/$(VIS_NAME) .

clean:
	@make -C $(ASM_DIR) clean
	@make -C $(DISASM_DIR) clean
	@make -C $(VM_DIR) clean
	# @make -C $(VIS_DIR) clean

fclean:
	@make -C $(ASM_DIR) fclean
	@make -C $(DISASM_DIR) fclean
	@make -C $(VM_DIR) fclean
	# @make -C $(VIS_DIR) fclean
	@rm -rf $(ASM_NAME) $(DISASM_NAME) $(VM_NAME)
	# @rm -rf $(ASM_NAME) $(DISASM_NAME) $(VM_NAME) $(VIS_NAME)

re: fclean all
