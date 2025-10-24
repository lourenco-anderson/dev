#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define tipos e constantes ausentes da OAI
typedef unsigned int uint;
#define NB_ANTENNAS_TX 1
#define NB_ANTENNAS_RX 1
#define MAX_NUM_CCs 1

// Define placeholders vazios para estruturas que não usamos
typedef struct {} PHY_VARS_NR_UE;
typedef struct {} PHY_VARS_gNB;

// Mock do log
#define LOG_I(a, b, ...) printf(b "\n", ##__VA_ARGS__)
#define LOG_D(a, b, ...) printf(b "\n", ##__VA_ARGS__)
#define LOG_E(a, b, ...) printf("ERROR: " b "\n", ##__VA_ARGS__)

