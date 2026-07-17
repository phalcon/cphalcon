
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared validator collection state and combined validation for composite
 * validators.
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Traits_ValidatorCompositeTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Filter\\Validation\\Traits, ValidatorCompositeTrait, phalcon, filter_validation_traits_validatorcompositetrait, phalcon_filter_validation_traits_validatorcompositetrait_method_entry);

	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_filter_validation_traits_validatorcompositetrait_ce, SL("validators"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Filter_Validation_Traits_ValidatorCompositeTrait, getValidators)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("validators", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 700, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Traits_ValidatorCompositeTrait, validate)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, validator, _0, _3, *_4, _6, _1$$3, _2$$3, _5$$4, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_fast_count_int(&_0) == 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_validation_exceptions_novalidatorsincomposite_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 185, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Validation/Traits/ValidatorCompositeTrait.zep", 44);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Filter/Validation/Traits/ValidatorCompositeTrait.zep", 53);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _4);
			ZEPHIR_CALL_METHOD(&_5$$4, &validator, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &validator, "validate", NULL, 0, validation, field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$6)) {
					RETURN_MM_BOOL(0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_MM_BOOL(1);
}

