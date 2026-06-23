
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
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Concatenates strings using the separator only once without duplication in
 * places concatenation
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Concat)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, Concat, phalcon, support_helper_str_concat, phalcon_support_helper_str_abstractstr_ce, phalcon_support_helper_str_concat_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $delimiter
 * @param string $first
 * @param string $second
 * @param string ...$arguments
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Concat, __invoke)
{
	zend_bool _6;
	zval argument, arguments, delimiter, data, first, last, prefix, suffix, _1, _2, *_3, _5, _8, _0$$3, _4$$6, _7$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$7);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&arguments);
	zephir_get_args(&arguments);
	if (UNEXPECTED(zephir_fast_count_int(&arguments) < 3)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_support_helper_str_exceptions_insufficientarguments_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Support/Helper/Str/Concat.zep", 37);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(&arguments);
	ZEPHIR_CALL_FUNCTION(&delimiter, "reset", NULL, 0, &arguments);
	ZEPHIR_UNREF(&arguments);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_slice", NULL, 254, &arguments, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arguments, &_2);
	ZEPHIR_MAKE_REF(&arguments);
	ZEPHIR_CALL_FUNCTION(&first, "reset", NULL, 0, &arguments);
	ZEPHIR_UNREF(&arguments);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&arguments);
	ZEPHIR_CALL_FUNCTION(&last, "end", NULL, 0, &arguments);
	ZEPHIR_UNREF(&arguments);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_STRING(&prefix, "");
	ZEPHIR_INIT_VAR(&suffix);
	ZVAL_STRING(&suffix, "");
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	if (zephir_start_with(&first, &delimiter, NULL)) {
		ZEPHIR_CPY_WRT(&prefix, &delimiter);
	}
	if (zephir_end_with(&last, &delimiter, NULL)) {
		ZEPHIR_CPY_WRT(&suffix, &delimiter);
	}
	zephir_is_iterable(&arguments, 0, "phalcon/Support/Helper/Str/Concat.zep", 61);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _3)
		{
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _3);
			ZEPHIR_INIT_NVAR(&_4$$6);
			zephir_fast_trim(&_4$$6, &argument, &delimiter, ZEPHIR_TRIM_BOTH);
			zephir_array_append(&data, &_4$$6, PH_SEPARATE, "phalcon/Support/Helper/Str/Concat.zep", 58);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$7);
				zephir_fast_trim(&_7$$7, &argument, &delimiter, ZEPHIR_TRIM_BOTH);
				zephir_array_append(&data, &_7$$7, PH_SEPARATE, "phalcon/Support/Helper/Str/Concat.zep", 58);
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join(&_8, &delimiter, &data);
	ZEPHIR_CONCAT_VVV(return_value, &prefix, &_8, &suffix);
	RETURN_MM();
}

