clear

WORK_DIR=$(pwd)
COMPILER_DIR=/home/rijegaro/Downloads/armv7l-linux-musleabihf-cross/bin/

cd $COMPILER_DIR
./armv7l-linux-musleabihf-gcc -static -lm -o $WORK_DIR/proyecto_iso_hps/hps_main $WORK_DIR/proyecto_iso_hps/hps_main.c

# echo 0 >/sys/class/fpga-bridge/hps2fpga/enable
# echo 1 >/sys/class/fpga-bridge/hps2fpga/enable