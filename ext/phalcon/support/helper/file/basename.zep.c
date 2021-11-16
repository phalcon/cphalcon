
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Gets the filename from a given path, Same as PHP's `basename()` but has
 * non-ASCII support. PHP's `basename()` does not properly support streams or
 * filenames beginning with a non-US-ASCII character.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_File_Basename)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\File, Basename, phalcon, support_helper_file_basename, phalcon_support_helper_file_basename_method_entry, 0);

	return SUCCESS;
}

/**
 * @see https://bugs.php.net/bug.php?id=37738
 *
 * @param string      $uri
 * @param string|null $suffix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_File_Basename, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *suffix_param = NULL, fileName, matches, _0, _1, _2, _3, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3;
	zval uri, suffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&fileName);
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
		Z_PARAM_STR_OR_NULL(suffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &suffix_param);
	zephir_get_strval(&uri, uri_param);
	if (!suffix_param) {
		ZEPHIR_INIT_VAR(&suffix);
	} else {
		zephir_get_strval(&suffix, suffix_param);
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
	ZEPHIR_CALL_FUNCTION(&_4, "preg_quote", NULL, 398, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "@[^", &_4, "]+$@");
	ZEPHIR_INIT_NVAR(&_2);
	zephir_preg_match(&_2, &_5, &uri, &matches, 0, 0 , 0 );
	if (zephir_is_true(&_2)) {
		ZEPHIR_OBS_VAR(&fileName);
		zephir_array_fetch_long(&fileName, &matches, 0, PH_NOISY, "phalcon/Support/Helper/File/Basename.zep", 39);
	} else {
		ZEPHIR_INIT_NVAR(&fileName);
		ZVAL_STRING(&fileName, "");
	}
	if (1 != ZEPHIR_IS_EMPTY(&suffix)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "@");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_quote", NULL, 398, &suffix, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "@", &_7$$3, "$@");
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "preg_replace", NULL, 49, &_8$$3, &_6$$3, &fileName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&fileName, &_9$$3);
	}
	RETURN_CCTOR(&fileName);
}

