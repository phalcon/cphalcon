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

	CPPFLAGS=$old_CPPFLAGS

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

			AC_MSG_RESULT("libcurl found")

			AC_DEFINE([PHALCON_USE_CURL], [1], [Have CURL support])
			break
		fi
	done

	if test "$enable_qrcode" != "no"; then
		for i in /usr /usr/local; do
			if test -r $i/include/png.h; then
				PNG_DIR=$i
				PNG_CFLAGS=`pkg-config --cflags libpng`
				PNG_LDFLAGS=`pkg-config --libs libpng`

				CPPFLAGS="${CPPFLAGS} ${PNG_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${PNG_LDFLAGS}"

				AC_MSG_RESULT("libpng found")

				AC_DEFINE([PHALCON_USE_PNG], [1], [Have libpng support])
				break
			fi
		done

		if test -z $PNG_DIR; then
			AC_MSG_RESULT("libpng not found")
			AC_MSG_ERROR("Please check your libpng-dev installation.")
		fi

		for i in /usr /usr/local; do
			if test -r $i/include/qrencode.h; then
				QR_DIR=$i
				QR_CFLAGS=`pkg-config --cflags libqrencode`
				QR_LDFLAGS=`pkg-config --libs libqrencode`

				CPPFLAGS="${CPPFLAGS} ${QR_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${QR_LDFLAGS}"

				AC_MSG_RESULT("libqrencode found")

				AC_DEFINE([PHALCON_USE_QRENCODE], [1], [Have libqrencode support])
				break
			fi
		done

		if test -z $QR_DIR; then
			AC_MSG_RESULT("libqrencode not found")
			AC_MSG_ERROR("Please check your libqrencode-dev installation.")
		fi

		for i in /usr /usr/local; do
			if test -r $i/bin/MagickWand-config; then
				WAND_BINARY=$i/bin/MagickWand-config

				WAND_CFLAGS=`$WAND_BINARY --cflags`
				WAND_LDFLAGS=`$WAND_BINARY --libs`

				CPPFLAGS="${CPPFLAGS} ${WAND_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${WAND_LDFLAGS}"

				AC_DEFINE([PHALCON_USE_MAGICKWAND], [1], [Have ImageMagick MagickWand support])
				break
			fi
		done

		if test -z $WAND_BINARY; then
			AC_MSG_RESULT("libmagickwand not found")
			AC_MSG_ERROR("Please check your libmagickwand-dev installation.")
		fi

		for i in /usr /usr/local; do
			if test -r $i/include/zbar.h; then
				ZBAR_DIR=$i
				ZBAR_CFLAGS=`pkg-config --cflags zbar`
				ZBAR_LDFLAGS=`pkg-config --libs zbar`

				CPPFLAGS="${CPPFLAGS} ${ZBAR_CFLAGS}"
				EXTRA_LDFLAGS="${EXTRA_LDFLAGS} ${ZBAR_LDFLAGS}"

				AC_MSG_RESULT("libzbar found")

				AC_DEFINE([PHALCON_USE_ZBAR], [1], [Have libzbar support])
				break
			fi
		done

		if test -z $ZBAR_DIR; then
			AC_MSG_RESULT("libzbar not found")
			AC_MSG_ERROR("Please check your libzbar-dev installation.")
		fi
	fi

fi
