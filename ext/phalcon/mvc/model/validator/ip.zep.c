
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\Validator\IP
 *
 * Validates that a value is ipv4 address in valid range
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\Ip;
 *
 * class Data extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         // Any pubic IP
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"         => "server_ip",
 *                     "version"       => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *                     "allowReserved" => false,   // False if not specified. Ignored for v6
 *                     "allowPrivate"  => false,   // False if not specified
 *                     "message"       => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         // Any public v4 address
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"   => "ip_4",
 *                     "version" => IP::VERSION_4,
 *                     "message" => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         // Any v6 address
 *         $this->validate(
 *             new IP(
 *                 [
 *                     "field"        => "ip6",
 *                     "version"      => IP::VERSION_6,
 *                     "allowPrivate" => true,
 *                     "message"      => "IP address has to be correct",
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Ip) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Ip, phalcon, mvc_model_validator_ip, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_ip_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_validator_ip_ce, SL("VERSION_4"), 1048576);

	zephir_declare_class_constant_long(phalcon_mvc_model_validator_ip_ce, SL("VERSION_6"), 2097152);

	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Ip, validate) {

	zval _6, _12$$5;
	zend_bool _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *record, record_sub, __$false, field, value, message, version, allowPrivate, allowReserved, options, _0, _1, _2, _3, _4, _7, _8, _9, _10$$5, _11$$5, _13$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&allowPrivate);
	ZVAL_UNDEF(&allowReserved);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/ip.zep", 101);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "version");
	ZVAL_LONG(&_1, (1048576 | 2097152));
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getoption", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowPrivate");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowPrivate);
		ZVAL_LONG(&allowPrivate, 8388608);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowReserved");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 0);
	} else {
		ZEPHIR_INIT_NVAR(&allowReserved);
		ZVAL_LONG(&allowReserved, 4194304);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (_5) {
		_5 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_5) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("default"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("options"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_7);
	zephir_bitwise_or_function(&_7, &version, &allowPrivate TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	zephir_bitwise_or_function(&_8, &_7, &allowReserved TSRMLS_CC);
	zephir_array_update_string(&options, SL("flags"), &_8, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_1, 275);
	ZEPHIR_CALL_FUNCTION(&_9, "filter_var", NULL, 189, &value, &_1, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "message");
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "IP address is incorrect");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_10$$5, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_create_array(&_12$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_12$$5, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_13$$5, "strtr", NULL, 22, &message, &_12$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "IP");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_13$$5, &field, &_10$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

