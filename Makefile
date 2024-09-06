NAME = so_long

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Fichiers source
SOURCES = main.c $(wildcard $(SRC_DIR)/**/*.c)

# Générer les fichiers objets correspondants
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS := $(OBJECTS:main.c=$(OBJ_DIR)/main.o)  # Ajout pour corriger le problème de compilation

FLAGS = -Wall -Wextra -fPIC -I$(INC_DIR) -I$(LIBFT_DIR)/includes # Ajout du chemin vers includes de Libft
LINKS = -Lminilibx-linux -Lmlx -lmlx -lX11 -lXext -lm -lXrandr -L$(LIBFT_DIR) -lft # Correction du lien vers la Libft

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règle principale pour construire l'exécutable
$(NAME): $(LIBFT) $(OBJECTS)
	gcc $(OBJECTS) -o $(NAME) $(FLAGS) $(LINKS)

# Règle de compilation des fichiers .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

# Règle de compilation spécifique pour main.c
$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

# Compilation de la Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJECTS)
	rm -f $(OBJ_DIR)/main.o
	make -C $(LIBFT_DIR) clean

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ_DIR)/*.o
	make -C $(LIBFT_DIR) fclean

# Règle pour recompiler entièrement
re: fclean $(NAME)

# Règle pour compiler avec les symboles de débogage
debug: FLAGS += -g
debug: re
