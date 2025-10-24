CC = gcc
CFLAGS = -Wall -Wextra -O0 -g -mavx2 \
	-I/home/anderson/openairinterface5g \
	-I/home/anderson/openairinterface5g/openair1 \
	-I/home/anderson/openairinterface5g/openair1/PHY \
	-I/home/anderson/openairinterface5g/openair1/PHY/NR_TRANSPORT \
	-I/home/anderson/openairinterface5g/openair1/PHY/TOOLS \
	-I/home/anderson/openairinterface5g/common/utils \
	-I/home/anderson/openairinterface5g/common/utils/nr \
	-I/home/anderson/openairinterface5g/executables

all: teste

teste: main.c mock_defs.h
	@echo "[*] Compiling test..."
	$(CC) $(CFLAGS) main.c -o teste -lm -lpthread

clean:
	rm -f teste

