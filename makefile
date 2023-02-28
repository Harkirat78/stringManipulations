stringMe: soomalHarkiratA2.o soomalHarkiratA2Main.o
        gcc -Wall -std=c99 soomalHarkiratA2.o soomalHarkiratA2Main.o -o bin/str$
soomalHarkiratA2.o: src/soomalHarkiratA2.c include/soomalHarkiratA2.h
        gcc -Wall -std=c99 -c src/soomalHarkiratA2.c
soomalHarkiratA2Main.o: src/soomalHarkiratA2Main.c include/soomalHarkiratA2.h
        gcc -Wall -std=c99 -c src/soomalHarkiratA2Main.c
clean:
        rm *.o bin/stringMe

