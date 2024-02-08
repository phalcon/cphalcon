
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Support_Version)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support, Version, phalcon, support_version, phalcon_support_version_method_entry, 0);

	/**
	 * The constant referencing the major version. Returns 0
	 *
	 * ```php
	 * echo (new Phalcon\Support\Version())
	 *          ->getPart(Phalcon\Support\Version::VERSION_MAJOR);
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_support_version_ce, SL("VERSION_MAJOR"), 0);

	/**
	 * The constant referencing the major version. Returns 1
	 *
	 * ```php
	 * echo (new Phalcon\Support\Version())
	 *          ->getPart(Phalcon\Support\Version::VERSION_MEDIUM);
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_support_version_ce, SL("VERSION_MEDIUM"), 1);

	/**
	 * The constant referencing the major version. Returns 2
	 *
	 * ```php
	 * echo (new Phalcon\Support\Version())
	 *          ->getPart(Phalcon\Support\Version::VERSION_MINOR);
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_support_version_ce, SL("VERSION_MINOR"), 2);

	/**
	 * The constant referencing the major version. Returns 3
	 *
	 * ```php
	 * echo (new Phalcon\Support\Version())
	 *          ->getPart(Phalcon\Support\Version::VERSION_SPECIAL);
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_support_version_ce, SL("VERSION_SPECIAL"), 3);

	/**
	 * The constant referencing the major version. Returns 4
	 *
	 * ```php
	 * echo (new Phalcon\Support\Version())
	 *          ->getPart(Phalcon\Support\Version::VERSION_SPECIAL_NUMBER);
	 * ```
	 */
	zephir_declare_class_constant_long(phalcon_support_version_ce, SL("VERSION_SPECIAL_NUMBER"), 4);

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
 */
PHP_METHOD(Phalcon_Support_Version, getVersion)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 5);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 6);
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
 */
PHP_METHOD(Phalcon_Support_Version, getSpecial)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *special_param = NULL, suffix;
	zend_long special;

	ZVAL_UNDEF(&suffix);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(special)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &special_param);
	do {
		if (special == 1) {
			ZEPHIR_INIT_VAR(&suffix);
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
		ZEPHIR_INIT_NVAR(&suffix);
		ZVAL_STRING(&suffix, "");
		break;
	} while(0);

	RETURN_CCTOR(&suffix);
}

/**
 * Returns the active version (string)
 *
 * ```php
 * echo (new Phalcon\Version())->get();
 * ```
 */
PHP_METHOD(Phalcon_Support_Version, get)
{
	zval result;
	zval version, major, medium, minor, special, specialNumber, suffix, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&result);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&version, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/Support/Version.zep", 122);
	zephir_memory_observe(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/Support/Version.zep", 123);
	zephir_memory_observe(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/Support/Version.zep", 124);
	zephir_memory_observe(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/Support/Version.zep", 125);
	zephir_memory_observe(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/Support/Version.zep", 126);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSV(&_0, &major, ".", &medium, ".", &minor);
	zephir_get_strval(&result, &_0);
	ZEPHIR_CALL_METHOD(&suffix, this_ptr, "getspecial", NULL, 0, &special);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&suffix, "")) {
		zephir_concat_self(&result, &suffix);
		if (!ZEPHIR_IS_LONG(&specialNumber, 0)) {
			zephir_concat_self(&result, &specialNumber);
		}
	}
	RETURN_CTOR(&result);
}

/**
 * Returns the numeric active version
 *
 * ```php
 * echo (new Phalcon\Version())->getId();
 * ```
 */
PHP_METHOD(Phalcon_Support_Version, getId)
{
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&version, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/Support/Version.zep", 160);
	zephir_memory_observe(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/Support/Version.zep", 161);
	zephir_memory_observe(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/Support/Version.zep", 162);
	zephir_memory_observe(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/Support/Version.zep", 163);
	zephir_memory_observe(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/Support/Version.zep", 164);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 117, &_0, &medium);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 117, &_0, &minor);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVV(return_value, &major, &_1, &_2, &special, &specialNumber);
	RETURN_MM();
}

/**
 * Returns a specific part of the version. If the wrong parameter is passed
 * it will return the full version
 *
 * ```php
 * echo (new Phalcon\Version())->getPart(Phalcon\Version::VERSION_MAJOR);
 * ```
 */
PHP_METHOD(Phalcon_Support_Version, getPart)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *part_param = NULL, version, _0$$3, _2$$4;
	zend_long part, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(part)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &part_param);
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	do {
		if (part == 0 || part == 1 || part == 2 || part == 4) {
			zephir_memory_observe(&_0$$3);
			zephir_array_fetch_long(&_0$$3, &version, part, PH_NOISY, "phalcon/Support/Version.zep", 192);
			zephir_cast_to_string(&_1$$3, &_0$$3);
			RETURN_CTOR(&_1$$3);
		}
		if (part == 3) {
			zephir_array_fetch_long(&_2$$4, &version, 3, PH_NOISY | PH_READONLY, "phalcon/Support/Version.zep", 195);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getspecial", NULL, 0, &_2$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

