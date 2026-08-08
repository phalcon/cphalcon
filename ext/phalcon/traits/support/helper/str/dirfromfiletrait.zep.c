
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Accepts a file name (without extension) and returns a calculated
 * directory structure with the filename in the end
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_DirFromFileTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Support\\Helper\\Str, DirFromFileTrait, phalcon, traits_support_helper_str_dirfromfiletrait, phalcon_traits_support_helper_str_dirfromfiletrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $file
 * @param bool   $filesystemSafe
 *
 * @return string
 */
PHP_METHOD(Phalcon_Traits_Support_Helper_Str_DirFromFileTrait, toDirFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filesystemSafe, _2;
	zval file_zv, *filesystemSafe_param = NULL, name, start, _0, _1, _8, _9, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filesystemSafe)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filesystemSafe_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!filesystemSafe_param) {
		filesystemSafe = 0;
	} else {
		}
	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(&name, "pathinfo", NULL, 199, &file_zv, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, -2);
	ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 301, &name, &_0, &_1);
	zephir_check_call_status();
	_2 = filesystemSafe == 1;
	if (_2) {
		_2 = !(ZEPHIR_IS_EMPTY(&start));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ".");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "-");
		zephir_fast_str_replace(&_3$$3, &_4$$3, &_5$$3, &start);
		ZEPHIR_CPY_WRT(&start, &_3$$3);
	}
	if (!zephir_is_true(&start)) {
		ZVAL_LONG(&_6$$4, 0);
		ZVAL_LONG(&_7$$4, 1);
		ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 301, &name, &_6$$4, &_7$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&_9, "mb_str_split", NULL, 302, &start, &_0);
	zephir_check_call_status();
	zephir_fast_join_str(&_8, SL("/"), &_9);
	ZEPHIR_CONCAT_VS(return_value, &_8, "/");
	RETURN_MM();
}

