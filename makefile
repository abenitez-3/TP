# Makefile para TP de Lenguajes de Programación III
# Variables
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -g
CXXFLAGS = -Wall -Wextra -g
BUILD_DIR = bin
SRC_DIR = src

# Directorios por capítulos
CHAPTERS := 1 2 3 4 5
LISTINGS := 3 9 7 15 12  # adaptá según lo que tengas

# Generar objetivos listing-X.Y
LISTING_TARGETS := $(foreach chap,$(CHAPTERS),$(foreach list,$(LISTINGS),listing-$(chap).$(list)))

# Objetivos por archivo
.PHONY: all clean $(LISTING_TARGETS)

all: $(LISTING_TARGETS)

$(LISTING_TARGETS):
	@echo "Compilando $@..."
	$(eval CHAP := $(word 2,$(subst ., ,$@)))
	$(eval LIST := $(word 3,$(subst ., ,$@)))
	$(eval SRC := $(SRC_DIR)/Capitulo$(CHAP)/Listing$(CHAP).$(LIST).c)
	$(eval OUT := $(BUILD_DIR)/Capitulo_$(CHAP)/Listing$(CHAP).$(LIST).exe)
	@mkdir -p $(dir $(OUT))
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf $(BUILD_DIR)