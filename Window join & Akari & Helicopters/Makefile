# Copyright PCLP Team, 2025

# Compiler setup.
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# Define targets, e.g., ninel, codeinvim, vectsecv, nomogram.
TARGETS=window_join akari helicopters

# Manually define all targets.
build: $(TARGETS)

window_join: window_join.c
	$(CC) $(CFLAGS) window_join.c -o window_join

akari: akari.c
	$(CC) $(CFLAGS) akari.c -o akari

helicopters: helicopters.c
	$(CC) $(CFLAGS) helicopters.c -o helicopters

# Pack the solution into a zip file.
pack:
	zip -FSr 311CB_TiepacAnduena_Tema1.zip README Makefile *.c *.h

# Clean the solution.
clean:
	rm -f $(TARGETS)

.PHONY: pack clean
