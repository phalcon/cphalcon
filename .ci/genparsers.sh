#!/bin/bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

set -e

: "${CC:=gcc}"

BASE_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." >/dev/null 2>&1 && pwd )"
EXT_DIR=ext/phalcon
LANGS=(mvc/model/query mvc/view/engine/volt)

for lang in "${LANGS[@]}"
do
  pushd "$BASE_PATH/$EXT_DIR/$lang" > /dev/null 2>&1 || exit 1
    (>&1 printf "Regenerate language for: %s\\n" "$EXT_DIR/$lang")

    find . \( -name '*.o' -o -name '*.lo' -o -name '*.loT' \) -exec rm -f {} +
    find . \( -name lemon -o -name parser.c \) -exec rm -f {} +
    find . -name .libs -exec rm -rf {} +

    if [ ! -f "$(pwd)/lemon" ]
    then
      "$CC" -g lemon.c -o ./lemon
      chmod +x ./lemon
    fi

    if [ -z "$(command -v re2c 2>/dev/null || true)" ]
    then
      (>&2 echo "No re2c found in the \$PATH.")
      (>&2 echo "Consider install re2c or/and add re2c executable to the \$PATH.")
      exit 1
    fi

    RE2C_VER="$(re2c --vernum 2>/dev/null)"

    if [ "$RE2C_VER" -gt "9999" ]
    then
      re2c --no-debug-info --no-generation-date -o scanner.c scanner.re
    else
      re2c -W --no-debug-info --no-generation-date -o scanner.c scanner.re
    fi

    case "$lang" in
    "mvc/model/query")
        UPREFIX="PP"
        LPREFIX="pp"
        ;;
    "mvc/view/engine/volt")
        UPREFIX="VV"
        LPREFIX="vv"
        ;;
    *)
      (>&2 echo "Usupported language: $lang")
      exit 1
        ;;
    esac

    sed -i '' "s/YY/$UPREFIX/g" scanner.c
    sed -i '' "s/yy/$LPREFIX/g" scanner.c

    ./lemon -s parser.php7.lemon

    echo '#include "php_phalcon.h"' > parser.c
    cat parser.php7.c >> parser.c
    cat base.c >> parser.c

    sed -i '' 's|#line|//|g' parser.c
    sed -i '' 's/define TOKEN/define VTOKEN/g' parser.c
    sed -i '' "s/YY/$UPREFIX/g" parser.c
    sed -i '' "s/yy/$LPREFIX/g" parser.c

  popd > /dev/null 2>&1 || exit 1
done
