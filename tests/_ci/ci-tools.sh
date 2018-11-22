#!/usr/bin/env bash

PHP_VERNUM="$(`phpenv which php-config` --vernum)"

install_ext_from_src () {
	pkgname=$1
	source=$2
	cfgflags=$3
	downloaddir="${HOME}/.cache/${pkgname}/${pkgname}-${PHP_VERNUM}"
	prefix="${HOME}/.local/opt/${pkgname}/${pkgname}-${PHP_VERNUM}"
	libdir="${prefix}/lib"

	if [ ! -f "${libdir}/pkgname.so" ]; then
		if [ ! -d `dirname ${downloaddir}` ]; then
			mkdir -p `dirname ${downloaddir}`
		fi

		cd `dirname ${downloaddir}`

		if [ ! -d "${pkgname}-${PHP_VERNUM}" ]; then
			git clone --depth=1 -v -b master "${source}" "${pkgname}-${PHP_VERNUM}"
		fi

		if [ ! -f "${pkgname}-${PHP_VERNUM}/LICENSE" ]; then
			echo "Unable to locate ${pkgname}-${PHP_VERNUM}/LICENSE file. Stop."
			exit 1
		fi

		if [ ! -d "${downloaddir}" ]; then
			echo "Unable to locate php-${pkgname} source. Stop."
			exit 1
		fi

		if [ ! -d "${libdir}" ]; then
			mkdir -p "${libdir}"
		fi

		cd "${downloaddir}"
		phpize
		printf "\n" | ./configure "${cfgflags}"

		make --silent -j"$(getconf _NPROCESSORS_ONLN)"
		make --silent install

		if [ -f `$(phpenv which php-config) --extension-dir`/${pkgname}.so ]; then
			cp `$(phpenv which php-config) --extension-dir`/${pkgname}.so "${libdir}/${pkgname}.so"
		elif [ -f "${downloaddir}/modules/${pkgname}.so" ]; then
			cp "${downloaddir}/modules/${pkgname}.so" "${libdir}/${pkgname}.so"
		fi
	fi

	if [ ! -x "${libdir}/${pkgname}.so" ]; then
		echo "Unable to locate ${libdir}/${pkgname}.so. Stop."
		exit 1
	fi

	echo "extension=${libdir}/${pkgname}.so" > "$(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/${pkgname}.ini"
}
