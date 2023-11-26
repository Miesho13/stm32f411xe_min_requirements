#!/bin/bash
st-flash write build/stm32_f411xe_min_require.bin 0x8000000
st-flash reset