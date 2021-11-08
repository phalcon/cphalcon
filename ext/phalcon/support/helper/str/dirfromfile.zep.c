
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
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
 * Accepts a file name (without extension) and returns a calculated
 * directory structure with the filename in the end
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_DirFromFile)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, DirFromFile, phalcon, support_helper_str_dirfromfile, phalcon_support_helper_str_dirfromfile_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_DirFromFile, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, name, start, _0, _1, _4, _5, _2$$3, _3$$3;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);


	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(&name, "pathinfo", NULL, 115, &file, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, -2);
	ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 226, &name, &_0, &_1);
	zephir_check_call_status();
	if (!zephir_is_true(&start)) {
		ZVAL_LONG(&_2$$3, 0);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 226, &name, &_2$$3, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&_5, "mb_str_split", NULL, 0, &start, &_0);
	zephir_check_call_status();
	zephir_fast_join_str(&_4, SL("/"), &_5);
	ZEPHIR_CONCAT_VS(return_value, &_4, "/");
	RETURN_MM();
}

