NAME = login

SRC = main.cpp User.cpp DataBase.cpp

all : ${NAME}

${NAME} : ${SRC}
	c++ -Wall -Wextra -Werror ${SRC} -o ${NAME}

clean : 
	rm -f ${NAME}

fclean : clean

re : fclean all