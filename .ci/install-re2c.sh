#!/usr/bin/env bash
#
# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view the
# LICENSE.txt file that was distributed with this source code.

if [ -z ${RE2C_VERSION+x} ]
then
  (>&2 echo "The RE2C_VERSION is unset.")
  (>&2 echo "Aborting.")
  exit 1
fi

if [ "${RE2C_VERSION}" == "system" ]
then
  (>&2 echo "Use system re2c.")
  (>&2 echo "Skip.")
  exit 0
fi

pkgname=re2c
source="https://github.com/skvadrik/${pkgname}/releases/download/${RE2C_VERSION}/${pkgname}-${RE2C_VERSION}.tar.gz"
downloaddir="${HOME}/.cache/${pkgname}/${pkgname}-${RE2C_VERSION}"
prefix="${HOME}/.local/opt/${pkgname}/${pkgname}-${RE2C_VERSION}"
bindir="${prefix}/bin"

if [ ! -f "${bindir}/re2c" ]
then
  if [ ! -d "$(dirname "$downloaddir")" ]
  then
    mkdir -p "$(dirname "$downloaddir")"
  fi

  cd "$(dirname "$downloaddir")" || exit 1

  if [ ! -f "${pkgname}-${RE2C_VERSION}.tar.gz" ]
  then
    curl -sSL "$source" -o "${pkgname}-${RE2C_VERSION}.tar.gz"
  fi

  if [ ! -f "${pkgname}-${RE2C_VERSION}.tar.gz" ]
  then
    (>&2 printf "Unable to locate %s-%s .tar.gz file.\\n" "$pkgname" "$RE2C_VERSION")
    (>&2 echo "Stop.")
    exit 1
  fi

  if [ ! -d "$downloaddir" ]
  then
    mkdir -p "$downloaddir"
    tar -zxf "${pkgname}-${RE2C_VERSION}.tar.gz"
  fi

  if [ ! -d "$downloaddir" ]
  then
    (>&2 echo "Unable to locate re2c source.")
    (>&2 echo "Stop.")
    exit 1
  fi

  if [ ! -d "$prefix" ]
  then
    mkdir -p "$prefix"
  fi

  cd "$downloaddir" || exit 1
  ./configure --silent --prefix="${prefix}"

  make --silent -j"$(getconf _NPROCESSORS_ONLN)"
  make --silent install
fi

if [ ! -x "$bindir/re2c" ]; then
  (>&2 echo "Unable to locate re2c executable.")
  (>&2 echo "Stop.")
  exit 1
fi

mkdir -p "$HOME/bin"
ln -s "$bindir/re2c" "$HOME/bin/re2c"

re2c --version
exit 0
