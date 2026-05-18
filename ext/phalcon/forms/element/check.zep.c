
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
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Component INPUT[type=check] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Check)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Check, phalcon, forms_element_check, phalcon_forms_element_abstractelement_ce, phalcon_forms_element_check_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_forms_element_check_ce, SL("method"), "inputCheckbox", ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_forms_element_check_ce, SL("uncheckedValue"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_forms_element_check_ce, SL("uncheckedValueSet"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns the value to bind when the checkbox is absent from submitted
 * data. Only meaningful when hasUncheckedValue() is true.
 */
PHP_METHOD(Phalcon_Forms_Element_Check, getUncheckedValue)
{

	RETURN_MEMBER(getThis(), "uncheckedValue");
}

/**
 * Whether an "unchecked value" has been explicitly registered.
 */
PHP_METHOD(Phalcon_Forms_Element_Check, hasUncheckedValue)
{

	RETURN_MEMBER(getThis(), "uncheckedValueSet");
}

/**
 * Registers a value to bind when the checkbox is absent from submitted
 * data (the typical browser behavior for an unchecked input). Without
 * this opt-in, an unchecked checkbox leaves the entity property
 * untouched. See cphalcon issue #16982.
 */
PHP_METHOD(Phalcon_Forms_Element_Check, setUncheckedValue)
{
	zval *value, value_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("uncheckedValue"), value);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uncheckedValueSet"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uncheckedValueSet"), &__$false);
	}
	RETURN_THISW();
}

