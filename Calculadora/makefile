include cfg.mak

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