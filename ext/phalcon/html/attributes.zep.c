
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
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
 * This class helps to work with HTML Attributes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, Attributes, phalcon, html_attributes, phalcon_support_collection_ce, phalcon_html_attributes_method_entry, 0);

	zend_class_implements(phalcon_html_attributes_ce, 1, phalcon_html_attributes_renderinterface_ce);
	return SUCCESS;
}

/**
 * Render attributes as HTML attributes
 */
PHP_METHOD(Phalcon_Html_Attributes, render)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderattributes", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of the render method
 */
PHP_METHOD(Phalcon_Html_Attributes, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo remove this when we refactor forms. Maybe remove this class? Put it into traits
 */
PHP_METHOD(Phalcon_Html_Attributes, renderAttributes)
{
	zend_bool _4$$3, _5$$4, _15$$6, _16$$7;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, __$true, intersect, key, result, results, value, *_0, _1, _10$$4, _11$$4, _12$$4, _14$$4, _6$$5, _7$$5, _8$$5, _20$$7, _21$$7, _22$$7, _23$$7, _17$$8, _18$$8, _19$$8;
	zval attributes, order;

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&order);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 10, 0);
	zephir_array_update_string(&order, SL("rel"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("type"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("for"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("src"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("href"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("action"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("value"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("class"), &__$null, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect_key", NULL, 2, &order, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	zephir_fast_array_merge(&results, &intersect, &attributes);
	zephir_array_unset_string(&results, SL("escape"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&results, 0, "phalcon/Html/Attributes.zep", 83);
	if (Z_TYPE_P(&results) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&results), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_4$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_4$$3) {
				_4$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_4$$3) {
				_5$$4 = Z_TYPE_P(&value) == IS_ARRAY;
				if (!(_5$$4)) {
					_5$$4 = Z_TYPE_P(&value) == IS_RESOURCE;
				}
				if (_5$$4) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_html_exception_ce);
					ZEPHIR_INIT_NVAR(&_7$$5);
					zephir_gettype(&_7$$5, &value);
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZEPHIR_CONCAT_SVSVS(&_8$$5, "Value at index: \"", &key, "\" type: \"", &_7$$5, "\" cannot be rendered");
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_9, 32, &_8$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$5, "phalcon/Html/Attributes.zep", 74);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_10$$4, 3);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, "utf-8");
				ZEPHIR_CALL_FUNCTION(&_12$$4, "htmlspecialchars", &_13, 289, &value, &_10$$4, &_11$$4, &__$true);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZEPHIR_CONCAT_VSVS(&_14$$4, &key, "=\"", &_12$$4, "\" ");
				zephir_concat_self(&result, &_14$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &results, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &results, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &results, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &results, "current", NULL, 0);
			zephir_check_call_status();
				_15$$6 = Z_TYPE_P(&key) == IS_STRING;
				if (_15$$6) {
					_15$$6 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_15$$6) {
					_16$$7 = Z_TYPE_P(&value) == IS_ARRAY;
					if (!(_16$$7)) {
						_16$$7 = Z_TYPE_P(&value) == IS_RESOURCE;
					}
					if (_16$$7) {
						ZEPHIR_INIT_NVAR(&_17$$8);
						object_init_ex(&_17$$8, phalcon_html_exception_ce);
						ZEPHIR_INIT_NVAR(&_18$$8);
						zephir_gettype(&_18$$8, &value);
						ZEPHIR_INIT_NVAR(&_19$$8);
						ZEPHIR_CONCAT_SVSVS(&_19$$8, "Value at index: \"", &key, "\" type: \"", &_18$$8, "\" cannot be rendered");
						ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", &_9, 32, &_19$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$8, "phalcon/Html/Attributes.zep", 74);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_LONG(&_20$$7, 3);
					ZEPHIR_INIT_NVAR(&_21$$7);
					ZVAL_STRING(&_21$$7, "utf-8");
					ZEPHIR_CALL_FUNCTION(&_22$$7, "htmlspecialchars", &_13, 289, &value, &_20$$7, &_21$$7, &__$true);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZEPHIR_CONCAT_VSVS(&_23$$7, &key, "=\"", &_22$$7, "\" ");
					zephir_concat_self(&result, &_23$$7);
				}
			ZEPHIR_CALL_METHOD(NULL, &results, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

