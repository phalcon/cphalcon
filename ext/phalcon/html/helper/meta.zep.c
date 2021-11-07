
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Meta
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Meta)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Meta, phalcon, html_helper_meta, phalcon_html_helper_abstractseries_ce, phalcon_html_helper_meta_method_entry, 0);

	return SUCCESS;
}

/**
 * Add an element to the list
 *
 * @param array $attributes
 *
 * @return Meta
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, _1, _3;
	zval attributes, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "renderTag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, &attributes);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_3);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
	RETURN_THIS();
}

/**
 * @param string $httpEquiv
 * @param string $content
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addHttp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpEquiv_param = NULL, *content_param = NULL, _0;
	zval httpEquiv, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpEquiv);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(httpEquiv)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpEquiv_param, &content_param);
	zephir_get_strval(&httpEquiv, httpEquiv_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http-equiv");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addelement", NULL, 325, &_0, &httpEquiv, &content);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 * @param string $content
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *content_param = NULL, _0;
	zval name, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &content_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "name");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelement", NULL, 325, &_0, &name, &content);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param string $name
 * @param string $content
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *content_param = NULL, _0;
	zval name, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &content_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "property");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelement", NULL, 325, &_0, &name, &content);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, getTag)
{
	zval *this_ptr = getThis();



	RETURN_STRING("meta");
}

/**
 * @param string $element
 * @param string $value
 * @param string $content
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addElement)
{
	zval attributes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, *value_param = NULL, *content_param = NULL;
	zval element, value, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(element)
		Z_PARAM_STR(value)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &element_param, &value_param, &content_param);
	zephir_get_strval(&element, element_param);
	zephir_get_strval(&value, value_param);
	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&attributes);
	zephir_create_array(&attributes, 2, 0);
	zephir_array_update_zval(&attributes, &element, &value, PH_COPY);
	zephir_array_update_string(&attributes, SL("content"), &content, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

