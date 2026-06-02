
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
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
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
	zend_bool _3$$3, _4$$4;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, __$true, intersect, key, result, results, value, *_0, _8$$4, _9$$4, _10$$4, _12$$4, _5$$5, _6$$5;
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
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
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
	zephir_is_iterable(&results, 0, "phalcon/Html/Attributes.zep", 85);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&results), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		_3$$3 = Z_TYPE_P(&key) == IS_STRING;
		if (_3$$3) {
			_3$$3 = Z_TYPE_P(&value) != IS_NULL;
		}
		if (_3$$3) {
			_4$$4 = Z_TYPE_P(&value) == IS_ARRAY;
			if (!(_4$$4)) {
				_4$$4 = Z_TYPE_P(&value) == IS_RESOURCE;
			}
			if (_4$$4) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				object_init_ex(&_5$$5, phalcon_html_exceptions_attributenotrenderable_ce);
				ZEPHIR_INIT_NVAR(&_6$$5);
				zephir_gettype(&_6$$5, &value);
				ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", &_7, 0, &key, &_6$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$5, "phalcon/Html/Attributes.zep", 76);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_8$$4, 3);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "utf-8");
			ZEPHIR_CALL_FUNCTION(&_10$$4, "htmlspecialchars", &_11, 0, &value, &_8$$4, &_9$$4, &__$true);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZEPHIR_CONCAT_VSVS(&_12$$4, &key, "=\"", &_10$$4, "\" ");
			zephir_concat_self(&result, &_12$$4);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

