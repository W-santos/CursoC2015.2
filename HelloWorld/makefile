SRC = src
INC = inc
OBJ = obj
DIST = dist
EXE = hello_world.exe
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o,$(SRCS))

all:$(DIST)/$(EXE)
	@echo Compilado!

$(DIST)/$(EXE): $(OBJS)
	@echo Compilando $(EXE)
	@gcc $(OBJS) -o $(DIST)/$(EXE)

$(OBJ)/%.o:$(SRC)/%.c
	@echo compilando $<
	@gcc -c $< -I ./$(INC) -o $@

clean:
	@echo limpando
	@rm -rf $(OBJ)/*.o
	@rm -rf $(DIST)/$(EXE)

remake: clean all
	@echo feito