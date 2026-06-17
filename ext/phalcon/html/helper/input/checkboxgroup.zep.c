
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


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
 * Renders a group of `<input type="checkbox">` elements from an options array.
 *
 * The $checked parameter should be an array of selected values, or a single
 * scalar value (treated as a one-element array).
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_CheckboxGroup)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, CheckboxGroup, phalcon, html_helper_input_checkboxgroup, phalcon_html_helper_input_abstractgroup_ce, phalcon_html_helper_input_checkboxgroup_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_checkboxgroup_ce, SL("type"), "checkbox", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns true when $value appears in the checked list.
 *
 * @param string $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Html_Helper_Input_CheckboxGroup, isChecked)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, __$false, selected, _0, _1, _2$$5, _3$$5;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&selected);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("checked"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("checked"), PH_NOISY_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		zephir_memory_observe(&selected);
		zephir_read_property(&selected, this_ptr, ZEND_STRL("checked"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_2$$5);
		zephir_create_array(&_2$$5, 1, 0);
		zephir_memory_observe(&_3$$5);
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("checked"), PH_NOISY_CC);
		zephir_array_fast_append(&_2$$5, &_3$$5);
		ZEPHIR_CPY_WRT(&selected, &_2$$5);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 76, &value_zv, &selected, &__$false);
	zephir_check_call_status();
	RETURN_MM();
}

