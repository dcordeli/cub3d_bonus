SRCS    	=       parser.c tsinit.c init.c pixel.c loop.c dda.c draw.c sprite.c sort.c \
					keyloop.c pars_map.c pars_ct.c pars_file.c pars_help.c screenshot.c

SRCSB		=		parser_bonus.c tsinit_bonus.c init_bonus.c pixel.c loop_bonus.c dda.c \
					draw_bonus.c sprite_bonus.c sort.c floor_bonus.c \
               		keyloop_bonus.c pars_map_bonus.c pars_ct_bonus.c pars_file_bonus.c \
					pars_help_bonus.c screenshot.c mouse_bonus.c shape_bonus.c \
					loop_hook_bonus.c

INCLUDE		=		cub3d.h

INCBONUS	=		cub3d_bonus.h

OBJC    	=       ${SRCS:.c=.o}

OBJCB    	=		${SRCSB:.c=.o}

LIBS		=		libft.a libmlx.dylib

NAME		=       cub3D

CC      	=       gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=       rm -rf

%.o:			%.c $(INCBONUS) $(INCLUDE)
				$(CC) -Wall -Wextra -Werror -g -Imlx -I. -c $< -o ${<:.c=.o}

all:            $(NAME)

$(NAME):        $(OBJC)
				make -C libft/
				make -C minilibx/
				cp minilibx/libmlx.dylib .
				$(CC) $(OBJC) -L. -lmlx -Llibft -lft -I. -framework OpenGL -framework AppKit -o $(NAME)

bonus:			$(OBJCB)
				make -C libft/
				make -C minilibx/
				cp minilibx/libmlx.dylib .
				$(CC) $(OBJCB) -L. -lmlx -Llibft -lft -I. -framework OpenGL -framework AppKit -o $(NAME)

clean:		
				${RM} ${OBJC} ${OBJCB}
				make clean -C libft/
				make clean -C minilibx/

fclean:			clean
				${RM} ${NAME} ${LIBS}
				make fclean -C libft/

re:				fclean	all

.PHONY:			all clean fclean re
