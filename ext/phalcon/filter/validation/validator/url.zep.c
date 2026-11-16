
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Checks if a value has a url format
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Url as UrlValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "url",
 *     new UrlValidator(
 *         [
 *             "message" => ":field must be a url",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "url",
 *         "homepage",
 *     ],
 *     new UrlValidator(
 *         [
 *             "message" => [
 *                 "url"      => "url must be a url",
 *                 "homepage" => "homepage must be a url",
 *             ]
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Url)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Url, phalcon, filter_validation_validator_url, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_url_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_url_ce, SL("template"), "Field :field must be a url", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Url, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_url_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Url, validate)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, options, result, value, _0, _1, _3$$4, _5$$5, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD_CACHED(&value, validation, "getValue", &_zephir_call_cache[0], field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "allowEmpty", &_zephir_call_cache[1], field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	zephir_memory_observe(&options);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 784, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_string_fetch(&options, &_1, SL("options"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		ZVAL_LONG(&_3$$4, 273);
		ZEPHIR_CALL_FUNCTION(&result, "filter_var", &_4, 148, &value, &_3$$4, &options);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_5$$5, 273);
		ZEPHIR_CALL_FUNCTION(&result, "filter_var", &_4, 148, &value, &_5$$5);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&result))) {
		ZEPHIR_CALL_METHOD_CACHED(&_6$$6, this_ptr, "messageFactory", &_zephir_call_cache[2], validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[3], &_6$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

