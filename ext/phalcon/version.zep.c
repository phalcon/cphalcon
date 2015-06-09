
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Version
 *
 * This class allows to get the installed version of the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Version) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Version, phalcon, version, phalcon_version_method_entry, 0);

	/**
	 * The constant referencing the major version. Returns 0
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MAJOR);
	 * </code>
	 */
	zend_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MAJOR"), 0 TSRMLS_CC);

	/**
	 * The constant referencing the major version. Returns 1
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MEDIUM);
	 * </code>
	 */
	zend_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MEDIUM"), 1 TSRMLS_CC);

	/**
	 * The constant referencing the major version. Returns 2
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MINOR);
	 * </code>
	 */
	zend_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MINOR"), 2 TSRMLS_CC);

	/**
	 * The constant referencing the major version. Returns 3
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_SPECIAL);
	 * </code>
	 */
	zend_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL"), 3 TSRMLS_CC);

	/**
	 * The constant referencing the major version. Returns 4
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_SPECIAL_NUMBER);
	 * </code>
	 */
	zend_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL_NUMBER"), 4 TSRMLS_CC);

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

	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 3);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 4);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_array_fast_append(return_value, _0);
	RETURN_MM();

}

/**
 * Translates a number to a special release
 *
 * If Special release = 1 this function will return ALPHA
 */
PHP_METHOD(Phalcon_Version, _getSpecial) {

	zval *special_param = NULL, *suffix = NULL;
	int special;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &special_param);

	special = zephir_get_intval(special_param);
	ZEPHIR_INIT_VAR(suffix);
	ZVAL_STRING(suffix, "", 1);


	do {
		if (special == 1) {
			ZEPHIR_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "ALPHA", 1);
			break;
		}
		if (special == 2) {
			ZEPHIR_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "BETA", 1);
			break;
		}
		if (special == 3) {
			ZEPHIR_INIT_NVAR(suffix);
			ZVAL_STRING(suffix, "RC", 1);
			break;
		}
	} while(0);

	RETURN_CCTOR(suffix);

}

/**
 * Returns the active version (string)
 *
 * <code>
 * echo Phalcon\Version::get();
 * </code>
 */
PHP_METHOD(Phalcon_Version, get) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *major, *medium, *minor, *special, *specialNumber, *result, *suffix = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(major);
	zephir_array_fetch_long(&major, version, 0, PH_NOISY, "phalcon/version.zep", 124 TSRMLS_CC);
	ZEPHIR_OBS_VAR(medium);
	zephir_array_fetch_long(&medium, version, 1, PH_NOISY, "phalcon/version.zep", 125 TSRMLS_CC);
	ZEPHIR_OBS_VAR(minor);
	zephir_array_fetch_long(&minor, version, 2, PH_NOISY, "phalcon/version.zep", 126 TSRMLS_CC);
	ZEPHIR_OBS_VAR(special);
	zephir_array_fetch_long(&special, version, 3, PH_NOISY, "phalcon/version.zep", 127 TSRMLS_CC);
	ZEPHIR_OBS_VAR(specialNumber);
	zephir_array_fetch_long(&specialNumber, version, 4, PH_NOISY, "phalcon/version.zep", 128 TSRMLS_CC);
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CONCAT_VSVSVS(result, major, ".", medium, ".", minor, " ");
	ZEPHIR_CALL_SELF(&suffix, "_getspecial", &_0, 429, special);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(suffix, "")) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSV(_1, suffix, " ", specialNumber);
		zephir_concat_self(&result, _1 TSRMLS_CC);
	}
	zephir_fast_trim(return_value, result, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns the numeric active version
 *
 * <code>
 * echo Phalcon\Version::getId();
 * </code>
 */
PHP_METHOD(Phalcon_Version, getId) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *major, *medium, *minor, *special, *specialNumber, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_SELF(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(major);
	zephir_array_fetch_long(&major, version, 0, PH_NOISY, "phalcon/version.zep", 154 TSRMLS_CC);
	ZEPHIR_OBS_VAR(medium);
	zephir_array_fetch_long(&medium, version, 1, PH_NOISY, "phalcon/version.zep", 155 TSRMLS_CC);
	ZEPHIR_OBS_VAR(minor);
	zephir_array_fetch_long(&minor, version, 2, PH_NOISY, "phalcon/version.zep", 156 TSRMLS_CC);
	ZEPHIR_OBS_VAR(special);
	zephir_array_fetch_long(&special, version, 3, PH_NOISY, "phalcon/version.zep", 157 TSRMLS_CC);
	ZEPHIR_OBS_VAR(specialNumber);
	zephir_array_fetch_long(&specialNumber, version, 4, PH_NOISY, "phalcon/version.zep", 158 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "%02s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", &_2, 161, &_0, medium);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "%02s", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_2, 161, &_0, minor);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVV(return_value, major, _1, _3, special, specialNumber);
	RETURN_MM();

}

/**
 * Returns a specific part of the version. If the wrong parameter is passed
 * it will return the full version
 *
 * <code>
 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MAJOR);
 * </code>
 */
PHP_METHOD(Phalcon_Version, getPart) {

	zephir_fcall_cache_entry *_0 = NULL;
	zval *part_param = NULL, *version = NULL, *result = NULL, *_1;
	int part, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &part_param);

	part = zephir_get_intval(part_param);


	ZEPHIR_CALL_SELF(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	do {
		if (part == 0 || part == 1 || part == 2 || part == 4) {
			ZEPHIR_OBS_VAR(result);
			zephir_array_fetch_long(&result, version, part, PH_NOISY, "phalcon/version.zep", 183 TSRMLS_CC);
			break;
		}
		if (part == 3) {
			zephir_array_fetch_long(&_1, version, 3, PH_NOISY | PH_READONLY, "phalcon/version.zep", 187 TSRMLS_CC);
			ZEPHIR_CALL_SELF(&result, "_getspecial", &_0, 429, _1);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_CALL_SELF(&result, "get", NULL, 0);
		zephir_check_call_status();
		break;
	} while(0);

	RETURN_CCTOR(result);

}

