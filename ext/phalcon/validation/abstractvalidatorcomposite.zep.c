
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is a base class for combined fields validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_AbstractValidatorComposite) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation, AbstractValidatorComposite, phalcon, validation_abstractvalidatorcomposite, phalcon_validation_abstractvalidator_ce, phalcon_validation_abstractvalidatorcomposite_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_validation_abstractvalidatorcomposite_ce, SL("validators"), ZEND_ACC_PROTECTED);

	phalcon_validation_abstractvalidatorcomposite_ce->create_object = zephir_init_properties_Phalcon_Validation_AbstractValidatorComposite;

	zend_class_implements(phalcon_validation_abstractvalidatorcomposite_ce, 1, phalcon_validation_validatorcompositeinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Validation_AbstractValidatorComposite, getValidators) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "validators");

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_AbstractValidatorComposite, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, validator, _0, _4, *_5, _6, _1$$3, _2$$3, _3$$3, _7$$4, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_fast_count_int(&_0) == 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_validation_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VS(&_3$$3, &_2$$3, " does not have any validator added");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/AbstractValidatorComposite.zep", 33);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/AbstractValidatorComposite.zep", 42);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _5);
			ZEPHIR_CALL_METHOD(&_7$$4, &validator, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$4)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &validator, "validate", NULL, 0, validation, field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$6)) {
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_MM_BOOL(1);

}

zend_object *zephir_init_properties_Phalcon_Validation_AbstractValidatorComposite(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("templates"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("templates"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("validators"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

