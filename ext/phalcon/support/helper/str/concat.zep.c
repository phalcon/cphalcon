
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/main.h"
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
 * @param string ...$many
 *
 * @return string
 *
 * @throws InsufficientArguments
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Concat, __invoke)
{
	zend_bool _7;
	zval prefix, suffix;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval delimiter_zv, many, item, first, last, _1, _2, _3, *_4, _6, _9, _0$$3, _5$$6, _8$$7;
	zend_string *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&many);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&suffix);
	ZEND_PARSE_PARAMETERS_START(1, -1)
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	ZEPHIR_INIT_VAR(&many);
	zephir_get_args_from(&many, 1);
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_STRING(&prefix, "");
	ZEPHIR_INIT_VAR(&suffix);
	ZVAL_STRING(&suffix, "");
	if (UNEXPECTED(zephir_fast_count_int(&many) < 2)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_support_helper_str_exceptions_insufficientarguments_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Support/Helper/Str/Concat.zep", 36);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(&many);
	ZEPHIR_CALL_FUNCTION(&first, "reset", NULL, 0, &many);
	ZEPHIR_UNREF(&many);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&many);
	ZEPHIR_CALL_FUNCTION(&last, "end", NULL, 0, &many);
	ZEPHIR_UNREF(&many);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "tostartswith", NULL, 0, &first, &delimiter_zv, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CPY_WRT(&prefix, &delimiter_zv);
	}
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "toendswith", NULL, 0, &last, &delimiter_zv, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CPY_WRT(&suffix, &delimiter_zv);
	}
	zephir_is_iterable(&many, 0, "phalcon/Support/Helper/Str/Concat.zep", 54);
	if (Z_TYPE_P(&many) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&many), _4)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _4);
			ZEPHIR_INIT_NVAR(&_5$$6);
			zephir_fast_trim(&_5$$6, &item, &delimiter_zv, ZEPHIR_TRIM_BOTH);
			zephir_array_append(&data, &_5$$6, PH_SEPARATE, "phalcon/Support/Helper/Str/Concat.zep", 51);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &many, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &many, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &many, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &many, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$7);
				zephir_fast_trim(&_8$$7, &item, &delimiter_zv, ZEPHIR_TRIM_BOTH);
				zephir_array_append(&data, &_8$$7, PH_SEPARATE, "phalcon/Support/Helper/Str/Concat.zep", 51);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join(&_9, &delimiter_zv, &data);
	ZEPHIR_CONCAT_VVV(return_value, &prefix, &_9, &suffix);
	RETURN_MM();
}

