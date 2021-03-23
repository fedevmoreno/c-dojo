CC = gcc

FLAGS = -Wall -Wextra -Werror

NAMEENC = enc

NAMEDEC = dec

EN = rotoneorwtf_encry.c

DE = rotoneorwtf_decry.c

SEEDPHRASE =

encry:
	$(CC) $(FLAGS) $(EN) -o $(NAMEENC) && ./$(NAMEENC) "$(SEEDPHRASE)"

decry:
	$(CC) $(FLAGS) $(DE) -o $(NAMEDEC) && ./$(NAMEDEC) "$(SEEDPHRASE)"
