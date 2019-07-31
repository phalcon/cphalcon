#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

shopt -s nullglob

export LC_ALL=C

while IFS= read -r -d '' file
do
  (( count++ ))
  (>&1 printf ">>> START (%d)\n%s\n<<< END (%d)\n\n" $count "$(cat "$file")" $count)
done <   <(find ./tests/syntax -type f -name '*.out' -print0)

if [ -f ./compile-errors.log ]
then
  log_contents=$(cat ./compile-errors.log)
  [[ -z "${log_contents// }" ]] || {
    (>&1 printf "Compiler log:\n\n")
    (>&1 printf "%s\n" "$log_contents")
  }
fi

# for some reason Ubuntu 18.04 on Travis CI doesn't install gdb
function install_gcc() {
  if [ "${CI}" = "true" ] && [ "$(command -v gdb 2>/dev/null)" = "" ]
  then
    (>&1 printf "Install gdb...:\n\n")
    sudo apt-get install --no-install-recommends --quiet --assume-yes gdb
  fi
}

for i in /tmp/core.php.*; do
  install_gcc
  (>&1 printf "Found core dump file: %s\n\n" "$i")
  gdb -q "$(phpenv which php)" "$i" <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
done
