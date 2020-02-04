
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
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
 * Check for IP addresses
 *
 * ```php
 * use Phalcon\Validation\Validator\Ip as IpValidator;
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Ip) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Ip, phalcon, validation_validator_ip, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_ip_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_ip_ce, SL("template"), "Field :field must be a valid IP address", ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(phalcon_validation_validator_ip_ce, SL("VERSION_4"), 1048576);

	zephir_declare_class_constant_long(phalcon_validation_validator_ip_ce, SL("VERSION_6"), 2097152);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'allowPrivate' => false,
 *     'allowReserved' => false,
 *     'allowEmpty' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_Ip, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_ip_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Ip, validate) {

	zval _9;
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, __$false, value, version, allowPrivate, allowReserved, allowEmpty, options, _0, _1, _3, _5, _10, _11, _12, _2$$3, _4$$4, _6$$5, _7$$6, _13$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&allowPrivate);
	ZVAL_UNDEF(&allowReserved);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "version");
	ZVAL_LONG(&_1, (1048576 | 2097152));
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getoption", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&version) == IS_ARRAY) {
		zephir_array_fetch(&_2$$3, &version, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Ip.zep", 102);
		ZEPHIR_CPY_WRT(&version, &_2$$3);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowPrivate");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 8388608);
	}
	if (Z_TYPE_P(&allowPrivate) == IS_ARRAY) {
		zephir_array_fetch(&_4$$4, &allowPrivate, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Ip.zep", 108);
		ZEPHIR_CPY_WRT(&allowPrivate, &_4$$4);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowReserved");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 4194304);
	}
	if (Z_TYPE_P(&allowReserved) == IS_ARRAY) {
		zephir_array_fetch(&_6$$5, &allowReserved, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Ip.zep", 114);
		ZEPHIR_CPY_WRT(&allowReserved, &_6$$5);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "getoption", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_7$$6);
		if (zephir_array_isset(&allowEmpty, field)) {
			ZEPHIR_OBS_NVAR(&_7$$6);
			zephir_array_fetch(&_7$$6, &allowEmpty, field, PH_NOISY, "phalcon/Validation/Validator/Ip.zep", 120);
		} else {
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_BOOL(&_7$$6, 0);
		}
		ZEPHIR_CPY_WRT(&allowEmpty, &_7$$6);
	}
	_8 = zephir_is_true(&allowEmpty);
	if (_8) {
		_8 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_8) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 2, 0);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 1, 0);
	zephir_array_update_string(&_9, SL("default"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("options"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_10);
	zephir_bitwise_or_function(&_10, &version, &allowPrivate);
	ZEPHIR_INIT_VAR(&_11);
	zephir_bitwise_or_function(&_11, &_10, &allowReserved);
	zephir_array_update_string(&options, SL("flags"), &_11, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_1, 275);
	ZEPHIR_CALL_FUNCTION(&_12, "filter_var", NULL, 242, &value, &_1, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_CALL_METHOD(&_13$$8, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_13$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

