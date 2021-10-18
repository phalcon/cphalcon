
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This class offers file operation helper
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Fs)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Fs, phalcon, helper_fs, phalcon_helper_fs_method_entry, 0);

	return SUCCESS;
}

/**
 * Gets the filename from a given path, Same as PHP's basename() but has non-ASCII support.
 * PHP's basename() does not properly support streams or filenames beginning with a non-US-ASCII character.
 * see https://bugs.php.net/bug.php?id=37738
 *
 * @param string $uri
 * @param string $suffix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Helper_Fs, basename)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *suffix = NULL, suffix_sub, __$null, filename, matches, _0, _1, _2, _3, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(uri)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(suffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &suffix);
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
	}
	if (!suffix) {
		suffix = &suffix_sub;
		suffix = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_RIGHT);
	zephir_get_strval(&uri, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "@");
	ZEPHIR_CALL_FUNCTION(&_4, "preg_quote", NULL, 269, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "@[^", &_4, "]+$@");
	ZEPHIR_INIT_NVAR(&_2);
	zephir_preg_match(&_2, &_5, &uri, &matches, 0, 0 , 0 );
	if (zephir_is_true(&_2)) {
		ZEPHIR_OBS_VAR(&filename);
		zephir_array_fetch_long(&filename, &matches, 0, PH_NOISY, "phalcon/Helper/Fs.zep", 37);
	} else {
		ZEPHIR_INIT_NVAR(&filename);
		ZVAL_STRING(&filename, "");
	}
	if (zephir_is_true(suffix)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "@");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_quote", NULL, 269, suffix, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "@", &_7$$3, "$@");
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "preg_replace", NULL, 50, &_8$$3, &_6$$3, &filename);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&filename, &_9$$3);
	}
	RETURN_CCTOR(&filename);
}

