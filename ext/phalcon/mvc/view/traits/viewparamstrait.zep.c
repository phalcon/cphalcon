
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared view parameter and content accessors
 *
 * @todo v7 - inspect the View/Simple interfaces (ViewInterface vs ViewBaseInterface) to see whether these accessors can be unified behind a shared contract
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Traits_ViewParamsTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Mvc\\View\\Traits, ViewParamsTrait, phalcon, mvc_view_traits_viewparamstrait, phalcon_mvc_view_traits_viewparamstrait_method_entry);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_traits_viewparamstrait_ce, SL("content"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_traits_viewparamstrait_ce, SL("registeredEngines"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_mvc_view_traits_viewparamstrait_ce, SL("viewParams"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns output from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, getContent)
{

	RETURN_MEMBER_TYPED(getThis(), "content", IS_STRING);
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, getParamsToView)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1223, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, getRegisteredEngines)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("registeredEngines", 17, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1224, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Returns a parameter previously set in the view
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, getVar)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("viewParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1223, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key_zv, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&value);
}

/**
 * Externally sets the view content
 *
 *```php
 * $this->view->setContent("<h1>hello</h1>");
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, setContent)
{
	zval content_zv;
	zend_string *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("content", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&content_zv, content);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1225, &content_zv);
	RETURN_THISW();
}

/**
 * Set a single view parameter
 *
 *```php
 * $this->view->setVar("products", $products);
 *```
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Traits_ViewParamsTrait, setVar)
{
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&key_zv, key);
	zephir_update_property_array(this_ptr, SL("viewParams"), &key_zv, value);
	RETURN_THISW();
}

