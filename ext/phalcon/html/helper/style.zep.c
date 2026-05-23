
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
 * Class Style
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Style)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Style, phalcon, html_helper_style, phalcon_html_helper_abstractseries_ce, phalcon_html_helper_style_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_helper_style_ce, SL("isStyle"), 0, ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Add an element to the list
 *
 * @param string $url
 * @param array  $attributes
 *
 * @return static
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Style, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0, _2;
	zval url_zv, *attributes_param = NULL, *position_param = NULL, _1, _3, _4;
	zend_string *url = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(url)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		position_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
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
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getattributes", NULL, 0, &url_zv, &attributes);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_2, &_1);
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
 * Sets if this is a style or link tag
 *
 * @param bool $flag
 */
PHP_METHOD(Phalcon_Html_Helper_Style, setStyle)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isStyle"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isStyle"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns the necessary attributes
 *
 * @param string $url
 * @param array  $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Style, getAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, required;
	zval url_zv, *attributes_param = NULL, _0;
	zend_string *url = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&required);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(url)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&required);
	zephir_create_array(&required, 4, 0);
	add_assoc_stringl_ex(&required, SL("rel"), SL("stylesheet"));
	zephir_array_update_string(&required, SL("href"), &url_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&required, SL("type"), SL("text/css"));
	add_assoc_stringl_ex(&required, SL("media"), SL("screen"));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isStyle"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_array_unset_string(&required, SL("rel"), PH_SEPARATE);
	}
	zephir_array_unset_string(&attributes, SL("href"), PH_SEPARATE);
	zephir_fast_array_merge(return_value, &required, &attributes);
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Style, getTag)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isStyle"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "style");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "link");
	}
	RETURN_CCTOR(&_0);
}

