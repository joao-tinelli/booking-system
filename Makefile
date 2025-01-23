APPS = ./apps
OUTPUT = ./output
INCLUDE = ./includes
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -o3 -Wall

all: libed app 

create: 
	mkdir output
	mkdir obj
	mkdir lib

libed: \
	$(OBJ)/avl.o \
	$(OBJ)/hash.o \
	$(OBJ)/heap.o \
	$(OBJ)/log.o \


app: clean_apps \
	$(OUTPUT)/main 

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

run:
	$(OUTPUT)/main.out

$(OUTPUT)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@.out

export_lib:libed
	ar -rcs $(LIB)/libed.a $(OBJ)/*

clean:
	rm $(OUTPUT)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(OUTPUT)/*