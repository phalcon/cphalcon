
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


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
 * Wraps a plain PHP array as a SELECT data provider.
 *
 * Keys are option values; string values are labels;
 * array values define optgroups.
 *
 * @phpstan-import-type html_select_attributes from HtmlTypes
 * @phpstan-import-type html_select_options from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select_ArrayData)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper\\Input\\Select, ArrayData, phalcon, html_helper_input_select_arraydata, phalcon_html_helper_input_select_arraydata_method_entry, 0);

	/**
	 * @param html_select_attributes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_arraydata_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @param html_select_options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_arraydata_ce, SL("data"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_html_helper_input_select_arraydata_ce, 1, phalcon_contracts_html_helper_input_selectdata_ce);
	return SUCCESS;
}

/**
 * @param html_select_options    $data
 * @param html_select_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ArrayData, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, *attributes_param = NULL;
	zval data, attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &data_param, &attributes_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 844, &data);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 845, &attributes);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return html_select_attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ArrayData, getAttributes)
{

	RETURN_MEMBER_TYPED(getThis(), "attributes", IS_ARRAY);
}

/**
 * @return html_select_options
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ArrayData, getOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "data", IS_ARRAY);
}

