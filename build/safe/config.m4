PHP_ARG_ENABLE(phalcon, whether to enable phalcon framework, [ --enable-phalcon   Enable phalcon framework])

if test "$PHP_PHALCON" = "yes"; then
	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon Framework])
	PHP_NEW_EXTENSION(phalcon, phalcon.c, $ext_shared)

	PHP_ADD_EXTENSION_DEP([phalcon], [spl])

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_HEADERS(
		[ext/igbinary/igbinary.h],
		[
			PHP_ADD_EXTENSION_DEP([phalcon], [igbinary])
			AC_DEFINE([PHALCON_USE_PHP_IGBINARY], [1], [Whether PHP igbinary extension is present at compile time])
		],
		,
		[[#include "main/php.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([PHALCON_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [json])
					AC_DEFINE([PHALCON_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_PHP_SESSION],
		[
			AC_CHECK_HEADERS(
				[ext/session/php_session.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [session])
					AC_DEFINE([PHALCON_USE_PHP_SESSION], [1], [Whether PHP session extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	for i in /usr/local /usr; do
		if test -r $i/include/curl/easy.h; then
			CURL_DIR=$i
			if ${CURL_DIR}/bin/curl-config --libs > /dev/null 2>&1; then
				CURL_CONFIG=${CURL_DIR}/bin/curl-config
			else
				if ${CURL_DIR}/curl-config --libs > /dev/null 2>&1; then
					CURL_CONFIG=${CURL_DIR}/curl-config
				fi
			fi
			curl_version_full=`$CURL_CONFIG --version`
			AC_MSG_RESULT($curl_version_full)

			EXTRA_CFLAGS=`$CURL_CONFIG --cflags`
			EXTRA_LDFLAGS=`$CURL_CONFIG --libs`
			AC_MSG_RESULT($EXTRA_CFLAGS)
			AC_MSG_RESULT($EXTRA_LDFLAGS)

			AC_DEFINE([PHALCON_USE_CURL], [1], [Have CURL support])
			break
		fi
	done


	for i in /usr/local /usr; do
		if test -r $i/include/png.h; then
			PNG_DIR=$i
			AC_MSG_RESULT("libpng found")
			break
		fi
	done

	if test -r "$PNG_DIR"; then
		for i in /usr/local /usr; do
			if test -r $i/include/qrencode.h; then
				EXTRA_CFLAGS=`pkg-config --cflags libqrencode libpng`
				EXTRA_LDFLAGS=`pkg-config --libs libqrencode  libpng`

				AC_MSG_RESULT("libqrencode found")

				AC_DEFINE([PHALCON_USE_QRENCODE], [1], [Have libqrencode support])
				break
			fi
		done
	fi

	CPPFLAGS=$old_CPPFLAGS
fi
