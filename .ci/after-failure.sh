#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

# -e  Exit immediately if a command exits with a non-zero status.
# -u  Treat unset variables as an error when substituting.
set -eu

shopt -s nullglob

export LC_ALL=C

while IFS= read -r -d '' file
do
  (( count++ ))
  (>&1 printf ">>> START (%d)\\n%s\\n<<< END (%d)\\n\\n" $count "$(cat "$file")" $count)
done <   <(find ./tests/syntax -type f -name '*.out' -print0)

if [ -f ./compile-errors.log ]
then
  log_contents=$(cat ./compile-errors.log)
  [[ -z "${log_contents// }" ]] || {
    (>&1 echo "Compiler log:")
    (>&1 printf "%s\\n" "$log_contents")
  }
fi

# for some reason Ubuntu 18.04 on Travis CI doesn't install gdb
function install_gdb() {
  if [ "${CI}" = "true" ] && [ "$(command -v gdb 2>/dev/null)" = "" ]
  then
    (>&1 echo "Install gdb...")
    sudo apt-get install --no-install-recommends --quiet --assume-yes gdb 1> /dev/null
  fi
}

for i in /tmp/core.php.*; do
  install_gdb
  (>&1 printf "Found core dump file: %s\\n\\n" "$i")
  gdb -q "$(phpenv which php)" "$i" <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
done
