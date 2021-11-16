
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
 * @return $this
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Style, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0, _2;
	zval *url_param = NULL, *attributes_param = NULL, _1, _3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &attributes_param);
	zephir_get_strval(&url, url_param);
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
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getattributes", NULL, 0, &url, &attributes);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "indent", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_3);
	zephir_update_property_array_append(this_ptr, SL("store"), &_0);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	flag = zephir_get_boolval(flag_param);


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
	zval *url_param = NULL, *attributes_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&required);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(url)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &attributes_param);
	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&required);
	zephir_create_array(&required, 4, 0);
	add_assoc_stringl_ex(&required, SL("rel"), SL("stylesheet"));
	zephir_array_update_string(&required, SL("href"), &url, PH_COPY | PH_SEPARATE);
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


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isStyle"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZVAL_STRING(&_0, "style");
	} else {
		ZVAL_STRING(&_0, "link");
	}
	RETURN_CCTOR(&_0);
}

