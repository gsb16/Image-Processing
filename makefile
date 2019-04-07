
# GRR 20166812 -- Gabriel de Souza Barreto

CFLAGS = -Wall
objects = funcoespgm.o parametros.o

all: filtronegativo filtrolimiar filtromedia #filtromediana


filtromedia: filtromedia.o ${objects}
	gcc filtromedia.c ${objects} -o filtromedia ${CFLAGS}

filtromediana: filtromediana.o ${objects}
	gcc filtromediana.c ${objects} -o filtromediana ${CFLAGS}

filtronegativo: filtronegativo.o ${objects}
	gcc filtronegativo.c ${objects} -o filtronegativo ${CFLAGS}

filtrolimiar: filtrolimiar.o ${objects}
	gcc filtrolimiar.c ${objects} -o filtrolimiar ${CFLAGS}

filtromedia.o: filtromedia.c
	gcc -c filtromedia.c ${CFLAGS}

filtromediana.o: filtromediana.c
	gcc -c filtromediana.c ${CFLAGS}

filtronegativo.o: filtronegativo.c
	gcc -c filtronegativo.c ${CFLAGS}

filtrolimiar.o: filtrolimiar.c
	gcc -c filtrolimiar.c ${CFLAGS}

parametros.o: parametros.c parametros.h
	gcc -c parametros.c ${CFLAGS}

funcoespgm.o: funcoespgm.c estrutfuncpgm.h
	gcc -c funcoespgm.c ${CFLAGS}

clean:
	-rm -f *.o

purge: clean
	-rm -f filtromediana filtromedia filtrolimiar filtronegativo
	