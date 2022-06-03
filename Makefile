NAME				=	containers

STD					=	std_
FT					=	ft_
PERF				=	perf
DEF_ALL				=	-DFT_VEC -DFT_MAP -DFT_STACK -DFT_SET

CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror --std=c++98
RM					=	rm -rf

HEADERS				=	vector/vector.hpp\
						vector/vectorIterator.hpp\
						vector/vectorConstIterator.hpp\
						stack/stack.hpp\
						map/map.hpp\
						map/RBT.hpp\
						map/rbt_iterator.hpp\
						map/rbt_const_iterator.hpp\
						set/set.hpp\
						enableIf.hpp\
						equal.hpp\
						isIntegral.hpp\
						iteratorTraits.hpp\
						lexicographicalCompare.hpp\
						pair.hpp\
						reverse_iterator.hpp\

SRCS_DIR			=	tests/

SRC_PERF			=	perf.cpp
SRCS				=	main.cpp\
						utils.cpp\
						vector_tests.cpp\
						map_tests.cpp\
						set_tests.cpp\
						stack_tests.cpp\

INC					=	-Itests/ -Ivector/ -Istack/ -Imap/ -Iset/

OBJS_DIR			=	$(SRCS_DIR)objs/

OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
OBJS_PERF			=	$(addprefix $(OBJS_DIR), $(SRC_PERF:.cpp=.o))

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.cpp
					@mkdir -p $(OBJS_DIR)
					$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

BIN_DIR				=	tests/bin/
STD_BIN				=	$(BIN_DIR)$(STD)$(NAME)
FT_BIN				=	$(BIN_DIR)$(FT)$(NAME)
STD_PERF			=	$(BIN_DIR)$(STD)$(PERF)
FT_PERF				=	$(BIN_DIR)$(FT)$(PERF)

all:				$(NAME)

$(NAME):			$(FT_BIN) $(STD_BIN) $(FT_PERF) $(STD_PERF)
					@echo "Done !"

$(FT_BIN):			$(OBJS) $(HEADERS)
					@mkdir -p $(BIN_DIR)
					@echo "Building ft tests ..."
					@$(CXX) $(CXXFLAGS) $(OBJS) $(DEF_ALL) -D__FT__ -o $(FT_BIN)

$(STD_BIN):			$(OBJS) $(HEADERS)
					@mkdir -p $(BIN_DIR)
					@echo "Building stl tests ..."
					@$(CXX) $(CXXFLAGS) $(OBJS) $(DEF_ALL) -o $(STD_BIN)

$(STD_PERF):		$(OBJS_PERF) $(HEADERS)
					@mkdir -p $(BIN_DIR)
					@echo "Building stl perf tests ..."
					@$(CXX) $(CXXFLAGS) $(OBJS_PERF) -o $(STD_PERF)

$(FT_PERF):			$(OBJS_PERF) $(HEADERS)
					@mkdir -p $(BIN_DIR)
					@echo "Building ft perf tests ..."
					@$(CXX) $(CXXFLAGS) $(OBJS_PERF) -D__FT__ -o $(FT_PERF)


clean:
					@echo "Removing objs/"
					@$(RM) $(OBJS_DIR)

fclean:				clean
					@echo "Removing bin/"
					@$(RM) $(BIN_DIR)

re:					fclean all

.PHONY:				all clean fclean re
