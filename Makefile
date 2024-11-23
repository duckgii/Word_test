CC = c++
NAME = Tester
CFLAGS = -fsanitize=address -g3
SRCS = main.cpp Voca.cpp
SRCS_OBJS = main.o Voca.o
SRCS_HPPS =  Voca.hpp

all : $(NAME)

clean :
	rm -f $(SRCS_OBJS)

fclean : clean
	rm -f $(NAME)

re:
	make fclean
	make all

$(NAME) : $(SRCS_OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(SRCS_HPPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re