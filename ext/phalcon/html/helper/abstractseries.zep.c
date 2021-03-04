
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class AbstractSeries
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractSeries) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, AbstractSeries, phalcon, html_helper_abstractseries, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_abstractseries_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractseries_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractseries_ce, SL("store"), ZEND_ACC_PROTECTED);

	phalcon_html_helper_abstractseries_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_AbstractSeries;
	return SUCCESS;

}

/**
 * @param string $indent
 * @param string $delimiter
 *
 * @return AbstractSeries
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *indent_param = NULL, *delimiter_param = NULL, _0;
	zval indent, delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &indent_param, &delimiter_param);

	if (!indent_param) {
		ZEPHIR_INIT_VAR(&indent);
		ZVAL_STRING(&indent, "");
	} else {
		zephir_get_strval(&indent, indent_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	if (UNEXPECTED(!(ZEPHIR_IS_EMPTY(&delimiter)))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &delimiter);
	}
	if (UNEXPECTED(!(ZEPHIR_IS_EMPTY(&indent)))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("indent"), &indent);
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("store"), &_0);
	RETURN_THIS();

}

/**
 * Generates and returns the HTML for the list.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __toString) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderarrayelements", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the tag name.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, getTag) {

}

zend_object *zephir_init_properties_Phalcon_Html_Helper_AbstractSeries(zend_class_entry *class_type) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("store"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

