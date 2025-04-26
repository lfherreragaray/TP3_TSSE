SRC_DIR = ./src
INC_DIR = ./inc
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

clean:
	@rm -r $(OUT_DIR)

doc:
	@mkdir -p $(OUT_DIR)
	@doxygen doxyfile
