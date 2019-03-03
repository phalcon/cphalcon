
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
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\ip
 *
 * Check for ip addresses
 *
 * <code>
 * use Phalcon\Validation\Validator\Ip as IpValidator;
 *
 * $validator->add(
 *     "ip_address",
 *     new IpValidator(
 *         [
 *             "message" => ":field must contain only ip addresses",
 *             "version" => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *             "allowReserved" => false,   // False if not specified. Ignored for v6
 *             "allowPrivate" => false,   // False if not specified
 *             "allowEmpty" => false,
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
 *                 "source_address" => "source_address must contain only ip addresses",
 *                 "destination_address" => "destination_address must contain only ip addresses",
 *             ],
 *             "version" => [
 *                  "source_address" => Ip::VERSION_4 | IP::VERSION_6,
 *                  "destination_address" => Ip::VERSION_4,
 *             ],
 *             "allowReserved" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowPrivate" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *             "allowEmpty" => [
 *                  "source_address" => false,
 *                  "destination_address" => true,
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Ip) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Ip, phalcon, validation_validator_ip, phalcon_validation_validator_ce, phalcon_validation_validator_ip_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_validation_validator_ip_ce, SL("VERSION_4"), 1048576);

	zephir_declare_class_constant_long(phalcon_validation_validator_ip_ce, SL("VERSION_6"), 2097152);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Ip, validate) {

	zval _12;
	zend_bool _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, __$false, value, version, allowPrivate, allowReserved, allowEmpty, message, label, replacePairs, options, _0, _4, _6, _8, _13, _14, _15, _1$$3, _2$$5, _3$$6, _5$$7, _7$$8, _9$$9, _10$$10, _16$$12, _17$$12, _18$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&allowPrivate);
	ZVAL_UNDEF(&allowReserved);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "label");
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&label) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/ip.zep", 86 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&label, &_1$$3);
	}
	if (ZEPHIR_IS_EMPTY(&label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "message");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&message) == IS_ARRAY) {
		zephir_array_fetch(&_2$$5, &message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/ip.zep", 94 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&message, &_2$$5);
	}
	if (ZEPHIR_IS_EMPTY(&message)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "Ip");
		ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "version");
	ZVAL_LONG(&_4, (1048576 | 2097152));
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getoption", NULL, 0, &_0, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&version) == IS_ARRAY) {
		zephir_array_fetch(&_5$$7, &version, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/ip.zep", 102 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&version, &_5$$7);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowPrivate");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_INIT_VAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 8388608);
	}
	if (Z_TYPE_P(&allowPrivate) == IS_ARRAY) {
		zephir_array_fetch(&_7$$8, &allowPrivate, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/ip.zep", 107 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&allowPrivate, &_7$$8);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowReserved");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_VAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 4194304);
	}
	if (Z_TYPE_P(&allowReserved) == IS_ARRAY) {
		zephir_array_fetch(&_9$$9, &allowReserved, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/ip.zep", 112 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&allowReserved, &_9$$9);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZVAL_BOOL(&_4, 0);
	ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "getoption", NULL, 0, &_0, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_10$$10);
		if (zephir_array_isset(&allowEmpty, field)) {
			ZEPHIR_OBS_NVAR(&_10$$10);
			zephir_array_fetch(&_10$$10, &allowEmpty, field, PH_NOISY, "phalcon/validation/validator/ip.zep", 117 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_10$$10);
			ZVAL_BOOL(&_10$$10, 0);
		}
		ZEPHIR_CPY_WRT(&allowEmpty, &_10$$10);
	}
	_11 = zephir_is_true(&allowEmpty);
	if (_11) {
		_11 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_11) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("default"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("options"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_13);
	zephir_bitwise_or_function(&_13, &version, &allowPrivate TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_14);
	zephir_bitwise_or_function(&_14, &_13, &allowReserved TSRMLS_CC);
	zephir_array_update_string(&options, SL("flags"), &_14, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_15, "filter_var", NULL, 188, &value, &_4, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&_15))) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_16$$12);
		object_init_ex(&_16$$12, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_17$$12, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$12);
		ZVAL_STRING(&_18$$12, "Ip");
		ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", NULL, 300, &_17$$12, field, &_18$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_16$$12);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

