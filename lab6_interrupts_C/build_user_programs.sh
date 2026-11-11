#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -std=c11 01_basic_C/MyCode.c -o 01_basic_C/MyProg
gcc -Wall -Wextra -std=c11 02_system_calls/sys_call.c -o 02_system_calls/sys_call
gcc -Wall -Wextra -std=c11 03_signals/signal_test.c -o 03_signals/signal_test
gcc -Wall -Wextra -std=c11 03_signals/producer.c -o 03_signals/producer
gcc -Wall -Wextra -std=c11 03_signals/consumer.c -o 03_signals/consumer
echo "User-space programs compiled. Kernel module is intentionally excluded."
