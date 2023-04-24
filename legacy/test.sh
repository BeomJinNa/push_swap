#!/bin/bash

make
mv push_swap ../tester_push_swap/.
cd ../tester_push_swap
./tester.sh . 100 50
./tester.sh . 500 10
cd ../push_swap
