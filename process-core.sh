#! /bin/sh

apt-get -qq install gdb
for i in core.*; do gdb -q ./makecore $i <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
done
