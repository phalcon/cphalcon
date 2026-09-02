
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
#include "kernel/array.h"
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Callback)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Callback, phalcon, filter_validation_validator_callback, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_callback_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_callback_ce, SL("template"), "Field :field must match the callback function", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
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
	zend_bool _2$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, arguments, callback, returnedValue, data, reflection, savedTemplate, savedChanged, savedTemplates, _0, _1$$5, _5$$3, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&savedTemplate);
	ZVAL_UNDEF(&savedChanged);
	ZVAL_UNDEF(&savedTemplates);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$7);
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
		zephir_read_property_cached(&savedTemplate, this_ptr, _zephir_prop_0, 762, PH_NOISY_CC);
		zephir_memory_observe(&savedChanged);
		zephir_read_property_cached(&savedChanged, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC);
		zephir_memory_observe(&savedTemplates);
		zephir_read_property_cached(&savedTemplates, this_ptr, _zephir_prop_2, 764, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&arguments);
		zephir_create_array(&arguments, 1, 0);
		zephir_array_fast_append(&arguments, &data);
		if (zephir_is_instance_of(&callback, SL("Closure"))) {
			ZEPHIR_INIT_VAR(&reflection);
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 246, &callback);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1$$5, &reflection, "getnumberofparameters", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_1$$5, 1)) {
				zephir_array_append(&arguments, this_ptr, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Callback.zep", 123);
			}
		}
		ZEPHIR_INIT_VAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &callback, &arguments);
		zephir_check_call_status();
		_2$$3 = ((Z_TYPE_P(&returnedValue) == IS_TRUE || Z_TYPE_P(&returnedValue) == IS_FALSE) == 1);
		if (_2$$3) {
			_2$$3 = !zephir_is_true(&returnedValue);
		}
		if (_2$$3) {
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "messagefactory", NULL, 0, validation, field);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$7);
			zephir_check_call_status();
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 762, &savedTemplate);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 763, &savedChanged);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 764, &savedTemplates);
		if (((Z_TYPE_P(&returnedValue) == IS_TRUE || Z_TYPE_P(&returnedValue) == IS_FALSE) == 1)) {
			RETURN_CCTOR(&returnedValue);
		}
		_4$$3 = Z_TYPE_P(&returnedValue) == IS_OBJECT;
		if (_4$$3) {
			_4$$3 = zephir_instance_of_ev(&returnedValue, phalcon_filter_validation_validatorinterface_ce);
		}
		if (_4$$3) {
			ZEPHIR_RETURN_CALL_METHOD(&returnedValue, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_filter_validation_exceptions_invalidcallbackreturn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Filter/Validation/Validator/Callback.zep", 147);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);
}

