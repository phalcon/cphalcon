#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

if [ -z ${RE2C_VERSION+x} ]; then
	echo "The RE2C_VERSION is unset. Stop."
	exit 1
fi

if [ "${RE2C_VERSION}" == "system" ]; then
	echo "Use system re2c. Skip."
	exit 0
fi

pkgname=re2c
source="https://github.com/skvadrik/${pkgname}/releases/download/${RE2C_VERSION}/${pkgname}-${RE2C_VERSION}.tar.gz"
downloaddir="${HOME}/.cache/${pkgname}/${pkgname}-${RE2C_VERSION}"
prefix="${HOME}/.local/opt/${pkgname}/${pkgname}-${RE2C_VERSION}"
bindir="${prefix}/bin"

if [ ! -f "${bindir}/re2c" ]; then
	if [ ! -d `dirname ${downloaddir}` ]; then
		mkdir -p `dirname ${downloaddir}`
	fi

	cd `dirname ${downloaddir}`

	if [ ! -f "${pkgname}-${RE2C_VERSION}.tar.gz" ]; then
		curl -sSL "$source" -o "${pkgname}-${RE2C_VERSION}.tar.gz"
	fi

	if [ ! -f "${pkgname}-${RE2C_VERSION}.tar.gz" ]; then
		echo "Unable to locate ${pkgname}-${RE2C_VERSION}.tar.gz file. Stop."
		exit 1
	fi

	if [ ! -d "${downloaddir}" ]; then
		mkdir -p "${downloaddir}"
		tar -zxf "${pkgname}-${RE2C_VERSION}.tar.gz"
	fi

	if [ ! -d "${downloaddir}" ]; then
		echo "Unable to locate re2c source. Stop."
		exit 1
	fi

	if [ ! -d "${prefix}" ]; then
		mkdir -p "${prefix}"
	fi

	cd "${downloaddir}"
	./configure --silent --prefix="${prefix}"

	make --silent -j"$(getconf _NPROCESSORS_ONLN)"
	make --silent install
fi

if [ ! -x "${bindir}/re2c" ]; then
	echo "Unable to locate re2c executable. Stop."
	exit 1
fi

mkdir -p ${HOME}/bin
ln -s "${bindir}/re2c" ${HOME}/bin/re2c

re2c --version
exit 0
