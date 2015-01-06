/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "version.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"

/**
 * Phalcon\Version
 *
 * This class allows to get the installed version of the framework
 */
zend_class_entry *phalcon_version_ce;

PHP_METHOD(Phalcon_Version, _getVersion);
PHP_METHOD(Phalcon_Version, get);
PHP_METHOD(Phalcon_Version, getId);

static const zend_function_entry phalcon_version_method_entry[] = {
	PHP_ME(Phalcon_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Version initializer
 */
PHALCON_INIT_CLASS(Phalcon_Version){

	PHALCON_REGISTER_CLASS(Phalcon, Version, version, phalcon_version_method_entry, 0);

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
PHP_METHOD(Phalcon_Version, _getVersion){

	array_init_size(return_value, 5);
	add_next_index_long(return_value, 1);
	add_next_index_long(return_value, 3);
	add_next_index_long(return_value, 4);
	add_next_index_long(return_value, PHALCON_VERSION_STABLE);
	add_next_index_long(return_value, 1);
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
PHP_METHOD(Phalcon_Version, get){

	zval *version = NULL, *major, *medium, *minor, *special, *special_number;
	zval *result, *suffix;

	PHALCON_MM_GROW();

	PHALCON_CALL_SELF(&version, "_getversion");

	PHALCON_OBS_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY);

	PHALCON_OBS_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY);

	PHALCON_OBS_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY);

	PHALCON_OBS_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY);

	PHALCON_OBS_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY);

	PHALCON_INIT_VAR(result);
	PHALCON_CONCAT_VSVSVS(result, major, ".", medium, ".", minor, " ");

	PHALCON_INIT_VAR(suffix);
	switch (phalcon_get_intval(special)) {

		case PHALCON_VERSION_ALPHA:
			PHALCON_CONCAT_SV(suffix, "ALPHA ", special_number);
			break;

		case PHALCON_VERSION_BETA:
			PHALCON_CONCAT_SV(suffix, "BETA ", special_number);
			break;

		case PHALCON_VERSION_RC:
			PHALCON_CONCAT_SV(suffix, "RC ", special_number);
			break;

		default:
			ZVAL_STRING(suffix, "", 1);
			break;

	}
	phalcon_concat_self(&result, suffix TSRMLS_CC);
	phalcon_fast_trim(return_value, result, PHALCON_TRIM_BOTH TSRMLS_CC);
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
PHP_METHOD(Phalcon_Version, getId){

	zval *version = NULL, *major, *medium, *minor, *special, *special_number;
	zval *format, *real_medium = NULL, *real_minor = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_SELF(&version, "_getversion");

	PHALCON_OBS_VAR(major);
	phalcon_array_fetch_long(&major, version, 0, PH_NOISY);

	PHALCON_OBS_VAR(medium);
	phalcon_array_fetch_long(&medium, version, 1, PH_NOISY);

	PHALCON_OBS_VAR(minor);
	phalcon_array_fetch_long(&minor, version, 2, PH_NOISY);

	PHALCON_OBS_VAR(special);
	phalcon_array_fetch_long(&special, version, 3, PH_NOISY);

	PHALCON_OBS_VAR(special_number);
	phalcon_array_fetch_long(&special_number, version, 4, PH_NOISY);

	PHALCON_INIT_VAR(format);
	ZVAL_STRING(format, "%02s", 1);

	PHALCON_CALL_FUNCTION(&real_medium, "sprintf", format, medium);

	PHALCON_CALL_FUNCTION(&real_minor, "sprintf", format, minor);
	PHALCON_CONCAT_VVVVV(return_value, major, real_medium, real_minor, special, special_number);
	RETURN_MM();
}
