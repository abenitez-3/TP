# ==============================
# Compiladores y flags
# ==============================
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -g
CXXFLAGS = -Wall -Wextra -g

# "all" compila TODO el TP
all: Capitulo_1 Capitulo_2 Capitulo_3 Capitulo_4 Capitulo_5
clean:
	rm -rf bin

# ==============================
# Capítulo 1
# ==============================
# Directorios CAPITULO 1
SRC_DIR = src/Capitulo_1
BIN_DIR = bin/Capitulo_1

# Archivos fuente CAPITULO 1
LISTING1_1_SRCS = $(SRC_DIR)/Listing1.1/main.c $(SRC_DIR)/Listing1.2/reciprocal.cpp
LISTING1_1_HDRS = $(SRC_DIR)/Listing1.3/reciprocal.hpp

# Agrupador: compila todo el capítulo 1
Capitulo_1: Listing1.1
	@echo "Compilados todos los listados del Capítulo 1"

# Targets CAPITULO 1
.PHONY: all clean Listing1.1 listing1.1 clean-Capitulo_1

Listing1.1: listing1.1

listing1.1: $(LISTING1_1_SRCS) $(LISTING1_1_HDRS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LISTING1_1_SRCS) -I$(SRC_DIR)/Listing1.3 \
		-o $(BIN_DIR)/Listing1.1.exe

clean-Capitulo_1:
	rm -rf $(BIN_DIR)

# ==============================
# Capítulo 2
# ==============================
# Directorios CAPITULO 2
SRC_DIR_2 = src/Capitulo_2
BIN_DIR_2 = bin/Capitulo_2

# Agrupador: compila todos los listados del Capítulo 2
Capitulo_2: Listing2.1 Listing2.2 Listing2.3 Listing2.4 Listing2.5 Listing2.6 Listing2.7 Listing2.8 Listing2.9
	@echo "Compilados todos los listados del Capítulo 2"

# Targets CAPITULO 2
.PHONY: Listing2.1 Listing2.2 Listing2.3 Listing2.4 Listing2.5 Listing2.6 Listing2.7 Listing2.8 Listing2.9 clean-Capitulo_2

# -------- Listing 2.1 --------
Listing2.1: $(SRC_DIR_2)/Listing2.1/arglist.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.1..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_2)/Listing2.1.exe

# -------- Listing 2.2 --------
Listing2.2: $(SRC_DIR_2)/Listing2.2/getopt_long.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.2..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_2)/Listing2.2.exe

# -------- Listing 2.3 --------
Listing2.3: $(SRC_DIR_2)/Listing2.3/print-env.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.3..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_2)/Listing2.3.exe

# -------- Listing 2.4 --------
Listing2.4: $(SRC_DIR_2)/Listing2.4/client.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.4..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_2)/Listing2.4.exe

# -------- Listing 2.5 --------
Listing2.5: $(SRC_DIR_2)/Listing2.5/main.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.5..."
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR_2)/Listing2.5.exe

# -------- Listing 2.6 --------
Listing2.6: $(SRC_DIR_2)/Listing2.6/readfile.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.6..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_2)/Listing2.6.exe

# -------- Listing 2.7 --------
# Es una sola funcion para el Listing2.8

# -------- Listing 2.8 --------
Listing2.8: $(SRC_DIR_2)/Listing2.8/app.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.8..."
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR_2)/Listing2.8.exe

# -------- Listing 2.9 --------
Listing2.9: $(SRC_DIR_2)/Listing2.9/tifftest.c
	@mkdir -p $(BIN_DIR_2)
	@echo "Compilando Listing2.9..."
	$(CC) $(CFLAGS) $< -ltiff -o $(BIN_DIR_2)/Listing2.9.exe

# -------- Limpieza solo Capítulo 2 --------
clean-Capitulo_2:
	rm -rf $(BIN_DIR_2)

# ==============================
# Capítulo 3
# ==============================
# Directorios CAPITULO 3
SRC_DIR_3 = src/Capitulo_3
BIN_DIR_3 = bin/Capitulo_3

# Agrupador: compila todos los listados del Capítulo 3
Capitulo_3: Listing3.1 Listing3.2 Listing3.3 Listing3.4 Listing3.5 Listing3.6 Listing3.7
	@echo "Compilados todos los listados del Capítulo 3"

# Targets CAPITULO 3
.PHONY: Listing3.1 Listing3.2 Listing3.3 Listing3.4 Listing3.5 Listing3.6 Listing3.7 clean-Capitulo_3

# -------- Listing 3.1 --------
Listing3.1: $(SRC_DIR_3)/Listing3.1/print-pid.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.1..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.1.exe

# -------- Listing 3.2 --------
Listing3.2: $(SRC_DIR_3)/Listing3.2/system.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.2..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.2.exe

# -------- Listing 3.3 --------
Listing3.3: $(SRC_DIR_3)/Listing3.3/fork.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.3..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.3.exe

# -------- Listing 3.4 --------
Listing3.4: $(SRC_DIR_3)/Listing3.4/fork-exec.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.4..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.4.exe

# -------- Listing 3.5 --------
Listing3.5: $(SRC_DIR_3)/Listing3.5/sigusr1.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.5..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.5.exe

# -------- Listing 3.6 --------
Listing3.6: $(SRC_DIR_3)/Listing3.6/zombie.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.6..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.6.exe

# -------- Listing 3.7 --------
Listing3.7: $(SRC_DIR_3)/Listing3.7/sigchld.c
	@mkdir -p $(BIN_DIR_3)
	@echo "Compilando Listing3.7..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_3)/Listing3.7.exe

# -------- Limpieza solo Capítulo 3 --------
clean-Capitulo_3:
	rm -rf $(BIN_DIR_3)

# ==============================
# Capítulo 4
# ==============================
# Directorios CAPITULO 4
SRC_DIR_4 = src/Capitulo_4
BIN_DIR_4 = bin/Capitulo_4

# Agrupador: compila todos los listados del Capítulo 4
Capitulo_4: Listing4.1 Listing4.2 Listing4.3 Listing4.4 Listing4.5 Listing4.6 Listing4.7 Listing4.8 Listing4.9 Listing4.10 Listing4.11 Listing4.12 Listing4.13 Listing4.14 Listing4.15
	@echo "Compilados todos los listados del Capítulo 4"

# Targets CAPITULO 4
.PHONY: Listing4.1 Listing4.2 Listing4.3 Listing4.4 Listing4.5 Listing4.6 Listing4.7 Listing4.8 Listing4.9 Listing4.10 Listing4.11 Listing4.12 Listing4.13 Listing4.14 Listing4.15 clean-Capitulo_4

# -------- Listing 4.1 --------
Listing4.1: $(SRC_DIR_4)/Listing4.1/thread-create.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.1..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.1.exe -lpthread

# -------- Listing 4.2 --------
Listing4.2: $(SRC_DIR_4)/Listing4.2/thread-create2.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.2..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.2.exe -lpthread

# -------- Listing 4.3 --------
Listing4.3: $(SRC_DIR_4)/Listing4.3/thread-create2.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.3..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.3.exe -lpthread

# -------- Listing 4.4 --------
Listing4.4: $(SRC_DIR_4)/Listing4.4/primes.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.4..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.4.exe -lpthread

# -------- Listing 4.5 --------
Listing4.5: $(SRC_DIR_4)/Listing4.5/detached.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.5..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.5.exe -lpthread

# -------- Listing 4.6 --------
Listing4.6: $(SRC_DIR_4)/Listing4.6/primes.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.6..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.6.exe -lpthread

# -------- Listing 4.7 --------
Listing4.7: $(SRC_DIR_4)/Listing4.7/tsd.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.7..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.7.exe -lpthread

# -------- Listing 4.8 --------
Listing4.8: $(SRC_DIR_4)/Listing4.8/cleanup.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.8..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.8.exe -lpthread

# -------- Listing 4.9 --------
Listing4.9: $(SRC_DIR_4)/Listing4.9/cxx-exit.cpp
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.9..."
	$(CXX) $(CXXFLAGS) $< -o $(BIN_DIR_4)/Listing4.9.exe -lpthread

# -------- Listing 4.10 --------
Listing4.10: $(SRC_DIR_4)/Listing4.10/job-queue1.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.10..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.10.exe -lpthread

# -------- Listing 4.11 --------
Listing4.11: $(SRC_DIR_4)/Listing4.11/job-queue2.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.11..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.11.exe -lpthread

# -------- Listing 4.12 --------
Listing4.12: $(SRC_DIR_4)/Listing4.12/job-queue3.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.12..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.12.exe -lpthread

# -------- Listing 4.13 --------
Listing4.13: $(SRC_DIR_4)/Listing4.13/spin-condvar.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.13..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.13.exe -lpthread

# -------- Listing 4.14 --------
Listing4.14: $(SRC_DIR_4)/Listing4.14/condvar.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.14..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.14.exe -lpthread

# -------- Listing 4.15 --------
Listing4.15: $(SRC_DIR_4)/Listing4.15/thread-pid.c
	@mkdir -p $(BIN_DIR_4)
	@echo "Compilando Listing4.15..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_4)/Listing4.15.exe -lpthread

# -------- Limpieza solo Capítulo 4 --------
clean-Capitulo_4:
	rm -rf $(BIN_DIR_4)


# ==============================
# Capítulo 5
# ==============================
# Directorios CAPITULO 5
SRC_DIR_5 = src/Capitulo_5
BIN_DIR_5 = bin/Capitulo_5

# Agrupador: compila todos los listados del Capítulo 5
Capitulo_5: Listing5.1 Listing5.2 Listing5.3 Listing5.4 Listing5.5 Listing5.6 Listing5.7 Listing5.8 Listing5.9 Listing5.10 Listing5.11 Listing5.12
	@echo "Compilados todos los listados del Capítulo 5"

# Targets CAPITULO 5
.PHONY: Listing5.1 Listing5.2 Listing5.3 Listing5.4 Listing5.5 Listing5.6 Listing5.7 Listing5.8 Listing5.9 Listing5.10 Listing5.11 Listing5.12 clean-Capitulo_5

# -------- Listing 5.1 --------
Listing5.1: $(SRC_DIR_5)/Listing5.1/shm.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.1..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.1.exe

# -------- Listing 5.2 --------
Listing5.2: $(SRC_DIR_5)/Listing5.2/sem_all_deall.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.2..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.2.exe

# -------- Listing 5.3 --------
Listing5.3: $(SRC_DIR_5)/Listing5.3/sem_init.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.3..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.3.exe

# -------- Listing 5.4 --------
Listing5.4: $(SRC_DIR_5)/Listing5.4/sem_pv.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.4..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.4.exe

# -------- Listing 5.5 --------
Listing5.5: $(SRC_DIR_5)/Listing5.5/mmap-write.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.5..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.5.exe

# -------- Listing 5.6 --------
Listing5.6: $(SRC_DIR_5)/Listing5.6/mmap-read.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.6..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.6.exe

# -------- Listing 5.7 --------
Listing5.7: $(SRC_DIR_5)/Listing5.7/pipe.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.7..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.7.exe

# -------- Listing 5.8 --------
Listing5.8: $(SRC_DIR_5)/Listing5.8/dup2.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.8..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.8.exe

# -------- Listing 5.9 --------
Listing5.9: $(SRC_DIR_5)/Listing5.9/popen.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.9..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.9.exe

# -------- Listing 5.10 --------
Listing5.10: $(SRC_DIR_5)/Listing5.10/socket-server.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.10..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.10.exe

# -------- Listing 5.11 --------
Listing5.11: $(SRC_DIR_5)/Listing5.11/socket-client.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.11..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.11.exe

# -------- Listing 5.12 --------
Listing5.12: $(SRC_DIR_5)/Listing5.12/socket-inet.c
	@mkdir -p $(BIN_DIR_5)
	@echo "Compilando Listing5.12..."
	$(CC) $(CFLAGS) $< -o $(BIN_DIR_5)/Listing5.12.exe

# -------- Limpieza solo Capítulo 5 --------
clean-Capitulo_5:
	rm -rf $(BIN_DIR_5)