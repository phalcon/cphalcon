
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Nikolaos Dimopoulos <nikos@niden.net>                         |
 +------------------------------------------------------------------------+
*/
/**
 * Phalcon\Version
 *
 * This class allows to get the installed version of the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Version) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Version, phalcon, version, phalcon_version_method_entry, 0);


	return SUCCESS;

}

/**
 * Area where the version number is set. The format is as follows:
 * ABBCCDE
 *
 * A - Major version
 * B - Med version (two digits)
 * C - Min version (two digits)
 * D - Special release: 1 = Alpha, 2 = Beta, 3 = RC, 4 = Stable
 * E - Special release version i.e. RC1, Beta2 etc.
 */
PHP_METHOD(Phalcon_Version, _getVersion) {

	zval *_0;

	ZEPHIR_MM_GROW();

	array_init(return_value);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	zephir_array_append(&return_value, _0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_array_append(&return_value, _0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_array_append(&return_value, _0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_append(&return_value, _0, 0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_append(&return_value, _0, 0);
	RETURN_MM();

}

/**
 * Returns the active version (string)
 *
 * <code>
 * echo Phalcon\Version::get();
 * </code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Version, get) {

	zval *version, *major, *medium, *minor, *special, *specialNumber, *result, *suffix = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(version);
	zephir_call_self(version, this_ptr, "_getversion");
	ZEPHIR_OBS_VAR(major);
	zephir_array_fetch_long(&major, version, 0, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(medium);
	zephir_array_fetch_long(&medium, version, 1, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(minor);
	zephir_array_fetch_long(&minor, version, 2, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(special);
	zephir_array_fetch_long(&special, version, 3, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(specialNumber);
	zephir_array_fetch_long(&specialNumber, version, 4, PH_NOISY TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	concat_function(_0, major, medium);
	ZEPHIR_INIT_VAR(_1);
	concat_function(_1, _0, minor);
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CONCAT_VS(result, _1, " ");
	do {
		if (ZEPHIR_IS_LONG(special, 1)) {
			ZEPHIR_INIT_VAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "ALPHA ", specialNumber);
			break;
		}
		if (ZEPHIR_IS_LONG(special, 2)) {
			ZEPHIR_INIT_NVAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "BETA ", specialNumber);
			break;
		}
		if (ZEPHIR_IS_LONG(special, 3)) {
			ZEPHIR_INIT_NVAR(suffix);
			ZEPHIR_CONCAT_SV(suffix, "RC ", specialNumber);
			break;
		}
		ZEPHIR_INIT_NVAR(suffix);
		ZVAL_STRING(suffix, "", 1);
		break;
	} while(0);

	zephir_concat_self(&result, suffix);
	zephir_call_func_p1(return_value, "trim", result);
	RETURN_MM();

}

/**
 * Returns the numeric active version
 *
 * <code>
 * echo Phalcon\Version::getId();
 * </code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Version, getId) {

	zval *version, *major, *medium, *minor, *special, *specialNumber, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(version);
	zephir_call_self(version, this_ptr, "_getversion");
	ZEPHIR_OBS_VAR(major);
	zephir_array_fetch_long(&major, version, 0, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(medium);
	zephir_array_fetch_long(&medium, version, 1, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(minor);
	zephir_array_fetch_long(&minor, version, 2, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(special);
	zephir_array_fetch_long(&special, version, 3, PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(specialNumber);
	zephir_array_fetch_long(&specialNumber, version, 4, PH_NOISY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "%02s", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p2(_1, "sprintf", &_0, medium);
	ZEPHIR_INIT_VAR(_2);
	concat_function(_2, major, _1);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "%02s", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p2(_3, "sprintf", &_0, minor);
	ZEPHIR_INIT_VAR(_4);
	concat_function(_4, _2, _3);
	ZEPHIR_INIT_VAR(_5);
	concat_function(_5, _4, special);
	concat_function(return_value, _5, specialNumber);
	RETURN_MM();

}

