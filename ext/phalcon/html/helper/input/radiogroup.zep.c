
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
 * Renders a group of `<input type="radio">` elements from an options array.
 *
 * The $checked parameter should be a single scalar value matching the selected
 * option's value attribute.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_RadioGroup)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper\\Input, RadioGroup, phalcon, html_helper_input_radiogroup, phalcon_html_helper_input_abstractgroup_ce, phalcon_html_helper_input_radiogroup_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_input_radiogroup_ce, SL("type"), "radio", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns true when $value loosely equals the checked scalar.
 *
 * @param string $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Html_Helper_Input_RadioGroup, isChecked)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value_zv, _0, _1;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	zephir_cast_to_string(&_2, &_1);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_2, &value_zv));
}

