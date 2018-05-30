cd ../.build
cmake ..
make
cp packages/common/common.out ../scripts/bin
cp packages/tachometer/tachometer.out ../scripts/bin
cp packages/timer/timer.out ../scripts/bin
cp packages/serial/serial.out ../scripts/bin
cp packages/jetsonTX2/jetsonTX2.out ../scripts/bin
cd ../scripts
