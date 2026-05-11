
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
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
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *position_param = NULL, _1, _3, _4;
	zval attributes, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &attributes_param, &position_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!position_param) {
		position = -1;
	} else {
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
	ZVAL_LONG(&_4, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pushorplace", NULL, 0, &_0, &_4);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param string $httpEquiv
 * @param string $content
 * @param int    $position
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addHttp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval httpEquiv_zv, content_zv, *position_param = NULL, _0, _1;
	zend_string *httpEquiv = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpEquiv_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(httpEquiv)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&httpEquiv_zv, httpEquiv);
	ZVAL_STR_COPY(&content_zv, content);
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http-equiv");
	ZVAL_LONG(&_1, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addelement", NULL, 354, &_0, &httpEquiv_zv, &content_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 * @param string $content
 * @param int    $position
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, content_zv, *position_param = NULL, _0, _1;
	zend_string *name = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_STR_COPY(&content_zv, content);
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "name");
	ZVAL_LONG(&_1, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelement", NULL, 354, &_0, &name_zv, &content_zv, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param string $name
 * @param string $content
 * @param int    $position
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, content_zv, *position_param = NULL, _0, _1;
	zend_string *name = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_STR_COPY(&content_zv, content);
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "property");
	ZVAL_LONG(&_1, position);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelement", NULL, 354, &_0, &name_zv, &content_zv, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, getTag)
{

	RETURN_STRING("meta");
}

/**
 * @param string $element
 * @param string $value
 * @param string $content
 * @param int    $position
 *
 * @return Meta
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Meta, addElement)
{
	zval attributes;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval element_zv, value_zv, content_zv, *position_param = NULL, _0;
	zend_string *element = NULL, *value = NULL, *content = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&content_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(element)
		Z_PARAM_STR(value)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		position_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR_COPY(&element_zv, element);
	ZVAL_STR_COPY(&value_zv, value);
	ZVAL_STR_COPY(&content_zv, content);
	if (!position_param) {
		position = -1;
	} else {
		}
	ZEPHIR_INIT_VAR(&attributes);
	zephir_create_array(&attributes, 2, 0);
	zephir_array_update_zval(&attributes, &element_zv, &value_zv, PH_COPY);
	zephir_array_update_string(&attributes, SL("content"), &content_zv, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_0, position);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, &attributes, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

