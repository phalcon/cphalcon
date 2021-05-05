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
LANGS=(mvc/model/query mvc/view/engine/volt annotations)

function cleanup() {
  find . \( -name '*.o' -o -name '*.lo' -o -name '*.loT' \) -exec rm -f {} +
  find . \( -name lemon -o -name parser.c -o -name lempar.c \) -exec rm -f {} +
  find . \( -name scanner.c -o -name parser.c \) -exec rm -f {} +
  find . -name .libs -exec rm -rf {} +
}

function compile_lemon() {
  "$CC" -g "$BASE_PATH/3rdparty/lemon/lemon.c" -o "$BASE_PATH/.ci/lemon"
  chmod +x "$BASE_PATH/.ci/lemon"
}

function replace() {
  local re="$1"
  local file="$2"

  sed "$re" "$file" > xx && mv -f xx "$file"
}

function generate_lexer() {
  local uprefix="$1"
  local lprefix="$2"

  if [ -z "$(command -v re2c 2>/dev/null || true)" ]
  then
    (>&2 echo "No re2c found in the \$PATH.")
    (>&2 echo "Consider install re2c or/and add re2c executable to the \$PATH.")
    exit 1
  fi

  RE2C_VER="$(re2c --vernum 2>/dev/null)"

  if [ "$RE2C_VER" -gt "9999" ]
  then
    re2c -W --no-debug-info --no-generation-date -o scanner.c scanner.re
  else
    re2c --no-debug-info --no-generation-date -o scanner.c scanner.re
  fi

  replace "s/YY/$uprefix/g" scanner.c
  replace "s/yy/$lprefix/g" scanner.c
}

function generate_parser() {
  local uprefix="$1"
  local lprefix="$2"
  local tprefix="$3"

  cp "$BASE_PATH/3rdparty/lemon/lempar.c" .
  "$BASE_PATH/.ci/lemon" -s parser.php.lemon

  echo '#include "php_phalcon.h"' > parser.c
  cat parser.php.c >> parser.c
  cat base.c >> parser.c

  replace 's|#line|//|g' parser.c
  replace "s/define TOKEN/define ${tprefix}TOKEN/g" parser.c
  replace "s/YY/$uprefix/g" parser.c
  replace "s/yy/$lprefix/g" parser.c

  rm -f lempar.c
}

for lang in "${LANGS[@]}"
do
  pushd "$BASE_PATH/$EXT_DIR/$lang" > /dev/null 2>&1 || exit 1
    (>&1 printf "Regenerate language for: %s\\n" "$EXT_DIR/$lang")

    cleanup
    compile_lemon

    case "$lang" in
    "mvc/model/query")
        UPREFIX="PP"
        LPREFIX="pp"
        TPREFIX="PP"
        ;;
    "mvc/view/engine/volt")
        UPREFIX="VV"
        LPREFIX="vv"
        TPREFIX="V"
        ;;
    "annotations")
        UPREFIX="AA"
        LPREFIX="aa"
        TPREFIX="A"
        ;;
    *)
      (>&2 echo "Usupported language: $lang")
      exit 1
        ;;
    esac

    generate_lexer "$UPREFIX" "$LPREFIX"
    generate_parser "$UPREFIX" "$LPREFIX" "$TPREFIX"

    (>&1 printf "Done\\n\\n")
  popd > /dev/null 2>&1 || exit 1
done
