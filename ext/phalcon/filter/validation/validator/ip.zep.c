
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Check for IP addresses
 *
 * ```php
 * use Phalcon\Filter\Validation\Validator\Ip as IpValidator;
 *
 * $validator->add(
 *     "ip_address",
 *     new IpValidator(
 *         [
 *             "message"       => ":field must contain only ip addresses",
 *             "version"       => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *             "allowReserved" => false,   // False if not specified. Ignored for v6
 *             "allowPrivate"  => false,   // False if not specified
 *             "allowEmpty"    => false,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "source_address",
 *         "destination_address",
 *     ],
 *     new IpValidator(
 *         [
 *             "message" => [
 *                 "source_address"      => "source_address must be a valid IP address",
 *                 "destination_address" => "destination_address must be a valid IP address",
 *             ],
 *             "version" => [
 *                  "source_address"      => Ip::VERSION_4 | IP::VERSION_6,
 *                  "destination_address" => Ip::VERSION_4,
 *             ],
 *             "allowReserved" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowPrivate" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowEmpty" => [
 *                  "source_address"      => false,
 *                  "destination_address" => true,
 *             ],
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Ip)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Ip, phalcon, filter_validation_validator_ip, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_ip_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_ip_ce, SL("template"), "Field :field must be a valid IP address", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_filter_validation_validator_ip_ce, SL("VERSION_4"), 1048576);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_filter_validation_validator_ip_ce, SL("VERSION_6"), 2097152);

	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Ip, __construct)
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_ip_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Ip, validate)
{
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, __$false, value, version, allowPrivate, allowReserved, options, _0, _1, _2, _5, _8, _9, _3$$4, _4$$5, _6$$6, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&allowPrivate);
	ZVAL_UNDEF(&allowReserved);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "allowempty", NULL, 0, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "version");
	ZVAL_LONG(&_2, (1048576 | 2097152));
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&version) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, &version, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Ip.zep", 111);
		ZEPHIR_CPY_WRT(&version, &_3$$4);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowPrivate");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&allowPrivate, this_ptr, "getoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&allowPrivate) == IS_ARRAY) {
		zephir_array_fetch(&_4$$5, &allowPrivate, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Ip.zep", 116);
		ZEPHIR_CPY_WRT(&allowPrivate, &_4$$5);
	}
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_is_true(&allowPrivate)) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, 0);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, 8388608);
	}
	ZEPHIR_CPY_WRT(&allowPrivate, &_5);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowReserved");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&allowReserved, this_ptr, "getoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&allowReserved) == IS_ARRAY) {
		zephir_array_fetch(&_6$$6, &allowReserved, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Ip.zep", 122);
		ZEPHIR_CPY_WRT(&allowReserved, &_6$$6);
	}
	ZEPHIR_INIT_NVAR(&_5);
	if (zephir_is_true(&allowReserved)) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, 0);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, 4194304);
	}
	ZEPHIR_CPY_WRT(&allowReserved, &_5);
	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 2, 0);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0);
	zephir_array_update_string(&_7, SL("default"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("options"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_8);
	zephir_bitwise_or_function(&_8, &version, &allowPrivate);
	ZEPHIR_INIT_NVAR(&_5);
	zephir_bitwise_or_function(&_5, &_8, &allowReserved);
	zephir_array_update_string(&options, SL("flags"), &_5, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_2, 275);
	ZEPHIR_CALL_FUNCTION(&_9, "filter_var", NULL, 0, &value, &_2, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		ZEPHIR_CALL_METHOD(&_10$$7, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_10$$7);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

