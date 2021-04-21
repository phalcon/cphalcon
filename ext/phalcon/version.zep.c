
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class allows to get the installed version of the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Version) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Version, phalcon, version, phalcon_version_method_entry, 0);

	/**
	 * The constant referencing the major version. Returns 0
	 *
	 * ```php
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MAJOR
	 * );
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MAJOR"), 0);

	/**
	 * The constant referencing the major version. Returns 1
	 *
	 * ```php
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MEDIUM
	 * );
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MEDIUM"), 1);

	/**
	 * The constant referencing the major version. Returns 2
	 *
	 * ```php
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MINOR
	 * );
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MINOR"), 2);

	/**
	 * The constant referencing the major version. Returns 3
	 *
	 * ```php
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL
	 * );
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL"), 3);

	/**
	 * The constant referencing the major version. Returns 4
	 *
	 * ```php
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL_NUMBER
	 * );
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL_NUMBER"), 4);

	return SUCCESS;

}

/**
 * Area where the version number is set. The format is as follows:
 * ABBCCDE
 *
 * A - Major version
 * B - Med version (two digits)
 * C - Min version (two digits)
 * D - Special release: 1 = alpha, 2 = beta, 3 = RC, 4 = stable
 * E - Special release version i.e. RC1, Beta2 etc.
 *
 * @todo Remove in v5
 * @deprecated Use getVersion()
 */
PHP_METHOD(Phalcon_Version, _getVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_STATIC("getversion", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Area where the version number is set. The format is as follows:
 * ABBCCDE
 *
 * A - Major version
 * B - Med version (two digits)
 * C - Min version (two digits)
 * D - Special release: 1 = alpha, 2 = beta, 3 = RC, 4 = stable
 * E - Special release version i.e. RC1, Beta2 etc.
 */
PHP_METHOD(Phalcon_Version, getVersion) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 4);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 4);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * Translates a number to a special release.
 * @todo Remove in v5.0
 * @deprecated Use getSpecial()
 */
PHP_METHOD(Phalcon_Version, _getSpecial) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *special_param = NULL, _1;
	zend_long special, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &special_param);

	special = zephir_get_intval(special_param);


	ZVAL_LONG(&_1, special);
	ZEPHIR_RETURN_CALL_STATIC("getspecial", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Translates a number to a special release.
 */
PHP_METHOD(Phalcon_Version, getSpecial) {

	zval suffix;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *special_param = NULL;
	zend_long special;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&suffix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &special_param);

	special = zephir_get_intval(special_param);


	ZEPHIR_INIT_VAR(&suffix);
	ZVAL_STRING(&suffix, "");
	do {
		if (special == 1) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "alpha");
			break;
		}
		if (special == 2) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "beta");
			break;
		}
		if (special == 3) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "RC");
			break;
		}
	} while(0);

	RETURN_CTOR(&suffix);

}

/**
 * Returns the active version (string)
 *
 * ```php
 * echo Phalcon\Version::get();
 * ```
 */
PHP_METHOD(Phalcon_Version, get) {

	zval result;
	zval version, major, medium, minor, special, specialNumber, suffix, _0, _2$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&major);
	ZVAL_UNDEF(&medium);
	ZVAL_UNDEF(&minor);
	ZVAL_UNDEF(&special);
	ZVAL_UNDEF(&specialNumber);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&version, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/Version.zep", 152);
	ZEPHIR_OBS_VAR(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/Version.zep", 153);
	ZEPHIR_OBS_VAR(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/Version.zep", 154);
	ZEPHIR_OBS_VAR(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/Version.zep", 155);
	ZEPHIR_OBS_VAR(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/Version.zep", 156);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSV(&_0, &major, ".", &medium, ".", &minor);
	zephir_get_strval(&result, &_0);
	ZEPHIR_CALL_STATIC(&suffix, "_getspecial", &_1, 0, &special);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&suffix, "")) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "-", &suffix);
		zephir_concat_self(&result, &_2$$3);
		if (!ZEPHIR_IS_LONG(&specialNumber, 0)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, ".", &specialNumber);
			zephir_concat_self(&result, &_3$$4);
		}
	}
	RETURN_CTOR(&result);

}

/**
 * Returns the numeric active version
 *
 * ```php
 * echo Phalcon\Version::getId();
 * ```
 */
PHP_METHOD(Phalcon_Version, getId) {

	zval version, major, medium, minor, special, specialNumber, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&major);
	ZVAL_UNDEF(&medium);
	ZVAL_UNDEF(&minor);
	ZVAL_UNDEF(&special);
	ZVAL_UNDEF(&specialNumber);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&version, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/Version.zep", 190);
	ZEPHIR_OBS_VAR(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/Version.zep", 191);
	ZEPHIR_OBS_VAR(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/Version.zep", 192);
	ZEPHIR_OBS_VAR(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/Version.zep", 193);
	ZEPHIR_OBS_VAR(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/Version.zep", 194);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 193, &_0, &medium);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 193, &_0, &minor);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVV(return_value, &major, &_1, &_2, &special, &specialNumber);
	RETURN_MM();

}

/**
 * Returns a specific part of the version. If the wrong parameter is passed
 * it will return the full version
 *
 * ```php
 * echo Phalcon\Version::getPart(
 *     Phalcon\Version::VERSION_MAJOR
 * );
 * ```
 */
PHP_METHOD(Phalcon_Version, getPart) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *part_param = NULL, version, _0$$3, _2$$4;
	zend_long part, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &part_param);

	part = zephir_get_intval(part_param);


	ZEPHIR_CALL_STATIC(&version, "getversion", NULL, 0);
	zephir_check_call_status();
	do {
		if (part == 0 || part == 1 || part == 2 || part == 4) {
			zephir_array_fetch_long(&_0$$3, &version, part, PH_NOISY | PH_READONLY, "phalcon/Version.zep", 220);
			RETURN_CTOR(&_0$$3);
		}
		if (part == 3) {
			zephir_array_fetch_long(&_2$$4, &version, 3, PH_NOISY | PH_READONLY, "phalcon/Version.zep", 225);
			ZEPHIR_RETURN_CALL_STATIC("_getspecial", &_1, 0, &_2$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_RETURN_CALL_STATIC("get", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

