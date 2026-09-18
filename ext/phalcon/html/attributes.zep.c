
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
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
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * This class helps to work with HTML Attributes
 *
 * @extends Collection<mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, Attributes, phalcon, html_attributes, phalcon_support_collection_ce, phalcon_html_attributes_method_entry, 0);

	zend_class_implements(phalcon_html_attributes_ce, 1, phalcon_html_attributes_renderinterface_ce);
	return SUCCESS;
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
 * @todo remove this when we refactor forms. Maybe remove this class? Put it into traits
 *
 * @phpstan-param array<array-key, mixed> $attributes
 */
PHP_METHOD(Phalcon_Html_Attributes, renderAttributes)
{
	zval _15$$4;
	zend_bool _6$$3, _7$$4;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_14 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, escaper, intersect, key, result, results, value, _0, *_1, _2, *_3, _11$$4, _12$$4, _13$$4, _17$$4, _18$$4, _8$$5, _9$$5;
	zval attributes, order;

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&order);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_15$$4);
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
	ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect_key", NULL, 8, &order, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	zephir_fast_array_merge(&results, &intersect, &attributes);
	zephir_array_unset_string(&results, SL("escape"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&escaper);
	object_init_ex(&escaper, phalcon_html_escaper_attributeescaper_ce);
	if (zephir_has_constructor(&escaper)) {
		ZEPHIR_CALL_METHOD(NULL, &escaper, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_LONG(&_0, 3);
	ZEPHIR_CALL_METHOD(NULL, &escaper, "setflags", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	if (Z_TYPE_P(&results) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &results);
		_1 = &_2;
	} else {
		_1 = &results;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Attributes.zep", 102);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&key, _5);
		} else {
			ZVAL_LONG(&key, _4);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _3);
		_6$$3 = Z_TYPE_P(&key) == IS_STRING;
		if (_6$$3) {
			_6$$3 = Z_TYPE_P(&value) != IS_NULL;
		}
		if (_6$$3) {
			_7$$4 = Z_TYPE_P(&value) == IS_ARRAY;
			if (!(_7$$4)) {
				_7$$4 = Z_TYPE_P(&value) == IS_RESOURCE;
			}
			if (_7$$4) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				object_init_ex(&_8$$5, phalcon_html_exceptions_attributenotrenderable_ce);
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_gettype(&_9$$5, &value);
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_10, 0, &key, &_9$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$5, "phalcon/Html/Attributes.zep", 89);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "~[\\s/=]~");
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "");
			ZEPHIR_CALL_FUNCTION(&_13$$4, "preg_replace", &_14, 6, &_11$$4, &_12$$4, &key);
			zephir_check_call_status();
			zephir_cast_to_string(&_15$$4, &_13$$4);
			ZEPHIR_CALL_METHOD(&key, &escaper, "escape", &_16, 0, &_15$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$4, &escaper, "escape", &_16, 0, &value);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_18$$4);
			ZEPHIR_CONCAT_VSVS(&_18$$4, &key, "=\"", &_17$$4, "\" ");
			zephir_concat_self(&result, &_18$$4);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

