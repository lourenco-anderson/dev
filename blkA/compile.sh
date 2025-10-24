

OAI=$HOME/openairinterface5g
BLD=$OAI/cmake_targets/ran_build/build
FILES_TO_INCLUDE=$(cat include_dirs.txt)
LIBS_TO_INCLUDE=$(cat static_libs.txt)

EXTRA_SRC="$OAI/openair1/PHY/TOOLS/nr_gold.c \
           $OAI/common/utils/minimal_stub.c"

# Build
echo "[*] Compiling main.c..."
gcc -O3 -std=c11 -Wall -Wextra \
  -I"$OAI" $FILES_TO_INCLUDE \
  -DSIMDE_ENABLE_NATIVE_ALIASES \
  -mavx2 -msse4.2 -mpclmul \
  -c main.c -o main.o

gcc -O3 -std=c11 -Wall -Wextra \
  -c $OAI/common/utils/minimal_stub.c\
  -o minimal_stub.o

echo "[*] Compiling extras..."
gcc -O2 -std=c11 -Wall -Wextra -I"$OAI" $FILES_TO_INCLUDE \
  -c $EXTRA_SRC

# Link (use same CPU flags)
echo "[*] Linking..."
gcc main.o minimal_stub.o \
  -mavx2 -msse4.2 -mpclmul \
  -Wl,--start-group $LIBS_TO_INCLUDE -Wl,--end-group \
  -lpthread  -lm \
  -o teste

echo "[*] Build finished: ./teste"










