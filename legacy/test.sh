#!/bin/bash

make
mv push_swap ../push_swap_tester/.
cd ../push_swap_tester
./push_swap_test.sh
cd ../push_swap
