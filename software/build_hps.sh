WORK_DIR=$(pwd)
COMPILER_DIR=/home/rijegaro/Downloads/armv7l-linux-musleabihf-cross/bin/

cd $COMPILER_DIR
./armv7l-linux-musleabihf-gcc -static -o $WORK_DIR/proyecto_iso_hps/leds_test $WORK_DIR/proyecto_iso_hps/leds_test.c

# echo 0 >/sys/class/fpga-bridge/hps2fpga/enable
# echo 1 >/sys/class/fpga-bridge/hps2fpga/enable