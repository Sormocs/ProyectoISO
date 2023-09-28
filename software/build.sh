# Correr como sudo
clear

SOFTWARE_DIR=$(pwd)

export QUARTUS_ROOTDIR=/opt/intelFPGA/20.1/quartus/
export SOPC_KIT_NIOS2=/opt/intelFPGA/20.1/nios2eds

export PATH="/opt/intelFPGA/20.1/nios2eds/bin/:$PATH"
export PATH="/opt/intelFPGA/20.1/nios2eds/sdk2/bin/:$PATH"
export PATH="/opt/intelFPGA/20.1/nios2eds/bin/gnu/H-x86_64-pc-linux-gnu/bin/:$PATH"


nios2-bsp-generate-files --settings=./proyecto_iso_bsp/settings.bsp --bsp-dir=./proyecto_iso_bsp

cd $SOFTWARE_DIR/proyecto_iso_bsp
make all

cd $SOFTWARE_DIR/proyecto_iso
make all

make mem_init_generate