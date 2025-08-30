

OAI=$HOME/openairinterface5g
BLD=$OAI/cmake_targets/ran_build/build
FILES_TO_INCLUDE=$(cat include_dirs.txt)
LIBS_TO_INCLUDE=$(cat static_libs.txt)

# Build
gcc -O3 -std=c11 -Wall -Wextra \
  -I"$OAI" $FILES_TO_INCLUDE \
  -DSIMDE_ENABLE_NATIVE_ALIASES \
  -mavx2 -msse4.2 -mpclmul \
  -c main.c -o main.o

# Link (use same CPU flags)
gcc main.o \
  -mavx2 -msse4.2 -mpclmul \
  -Wl,--start-group \
    $LIBS_TO_INCLUDE \
  -Wl,--end-group \
  -o teste

  #-lpthread -lm \
#    "$BLD/libPHY_NR.a" \
#    "$BLD/libPHY_NR_COMMON.a" \
#    "$BLD/libPHY_NR_UE.a" \
#    "$BLD/libUTIL.a" \
#    "$BLD/libPHY_COMMON.a" \
