

CPPFLAGS=-I../interfaces -Wno-write-strings -fpermissive
BIN_DIR=../bin
COMPONENTS_NEEDED=Composant1 Composant2
COMPONENTS_DIR=../lib
COMPONENTS_FILES=${COMPONENTS_NEEDED:%=${COMPONENTS_DIR}/lib%.so}
LD_COMPONENTS=
LDFLAGS= ${LD_COMPONENTS}
EXE = main
OBJS = main.o

include ../gcc.mk

all: ${COMPONENTS_FILES} ${EXE}

${COMPONENTS_FILES}:
	for component in ${COMPONENTS_NEEDED}; do \
		cd ../$$component; \
		${MAKE} install;  \
	done

clean:
	rm -f ${OBJS} ${EXE} ${COMPONENTS_FILES}; \
	for component in ${COMPONENTS_NEEDED}; do \
                cd ../$$component; \
                ${MAKE} clean;  \
        done; \
	rm -fr ${COMPONENTS_DIR}
	rm -fr ${BIN_DIR}

install: ${BIN_DIR} all
	cp ${EXE} ${BIN_DIR}; \
	cp ${COMPONENTS_FILES} ${BIN_DIR}

${BIN_DIR}:
	mkdir $@

