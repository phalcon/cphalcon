#! /bin/bash

EXT_DIR=$(readlink -enq "$(dirname $0)/../../ext")

shopt -s nullglob
export NO_INTERACTION=1
export REPORT_EXIT_STATUS1
make -C "$EXT_DIR" test
for i in $EXT_DIR/tests/*.log; do
	echo "====== $i ======";
	cat "$i";
done
[ -n "$(echo $EXT_DIR/tests/*.log)" ] && exit 1
exit 0
