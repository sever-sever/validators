VALIDATORS_C_DIR := src/validators-c

.PHONY: clean validators all
	# Remove prviousl compiled files
	rm -f src/validators/*

validators:
	@for module in $(shell ls $(VALIDATORS_C_DIR)); do \
		# Assuming each module is a C file, adjust if necessary for directories \
		$(CC) -Wall -Wextra -O3 -o src/validators/$$module $(VALIDATORS_C_DIR)/$$module/$$module.c; \
	done

all: clean validators
