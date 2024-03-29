#!/bin/bash


TARGET="load build/stm32_f411xe_min_require.elf"

run_gdb_server.sh > debug_service.log &

arm-none-eabi-gdb -ex "target remote localhost:61234" \
                  -ex ${TARGET} \
                  -ex "break main"
