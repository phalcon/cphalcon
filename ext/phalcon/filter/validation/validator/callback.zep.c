
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"
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
 * Calls user function for validation
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Callback as CallbackValidator;
 * use Phalcon\Filter\Validation\Validator\Numericality as NumericalityValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     ["user", "admin"],
 *     new CallbackValidator(
 *         [
 *             "message" => "There must be only an user or admin set",
 *             "callback" => function($data) {
 *                 if (!empty($data->getUser()) && !empty($data->getAdmin())) {
 *                     return false;
 *                 }
 *
 *                 return true;
 *             }
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     "amount",
 *     new CallbackValidator(
 *         [
 *             "callback" => function($data) {
 *                 if (!empty($data->getProduct())) {
 *                     return new NumericalityValidator(
 *                         [
 *                             "message" => "Amount must be a number."
 *                         ]
 *                     );
 *                 }
 *             }
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Callback)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Callback, phalcon, filter_validation_validator_callback, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_callback_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_callback_ce, SL("template"), "Field :field must match the callback function", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'callback' => null
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Callback, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_callback_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Callback, validate)
{
	zend_bool _3$$3, _5$$3;
	zend_class_entry *_2$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, callback, returnedValue, data, savedTemplate, savedChanged, savedTemplates, _0, _1$$5, _6$$3, _4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&savedTemplate);
	ZVAL_UNDEF(&savedChanged);
	ZVAL_UNDEF(&savedTemplates);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("template", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("templateChanged", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("templates", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "callback");
	ZEPHIR_CALL_METHOD(&callback, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_callable(&callback)) {
		ZEPHIR_CALL_METHOD(&data, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&data)) {
			ZEPHIR_CALL_METHOD(&data, validation, "getdata", NULL, 0);
			zephir_check_call_status();
		}
		zephir_memory_observe(&savedTemplate);
		zephir_read_property_cached(&savedTemplate, this_ptr, _zephir_prop_0, 753, PH_NOISY_CC);
		zephir_memory_observe(&savedChanged);
		zephir_read_property_cached(&savedChanged, this_ptr, _zephir_prop_1, 754, PH_NOISY_CC);
		zephir_memory_observe(&savedTemplates);
		zephir_read_property_cached(&savedTemplates, this_ptr, _zephir_prop_2, 755, PH_NOISY_CC);
		if (zephir_is_instance_of(&callback, SL("Closure"))) {
			_2$$5 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
			ZEPHIR_CALL_CE_STATIC(&_1$$5, _2$$5, "bind", NULL, 0, &callback, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&callback, &_1$$5);
		}
		ZEPHIR_CALL_FUNCTION(&returnedValue, "call_user_func", NULL, 80, &callback, &data);
		zephir_check_call_status();
		_3$$3 = ((Z_TYPE_P(&returnedValue) == IS_TRUE || Z_TYPE_P(&returnedValue) == IS_FALSE) == 1);
		if (_3$$3) {
			_3$$3 = !zephir_is_true(&returnedValue);
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "messagefactory", NULL, 0, validation, field);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_4$$6);
			zephir_check_call_status();
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 753, &savedTemplate);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 754, &savedChanged);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 755, &savedTemplates);
		if (((Z_TYPE_P(&returnedValue) == IS_TRUE || Z_TYPE_P(&returnedValue) == IS_FALSE) == 1)) {
			RETURN_CCTOR(&returnedValue);
		}
		_5$$3 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_5$$3) {
			_5$$3 = zephir_instance_of_ev(&returnedValue, phalcon_filter_validation_validatorinterface_ce);
		}
		if (_5$$3) {
			ZEPHIR_RETURN_CALL_METHOD(&returnedValue, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, phalcon_filter_validation_exceptions_invalidcallbackreturn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalcon/Filter/Validation/Validator/Callback.zep", 131);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);
}

