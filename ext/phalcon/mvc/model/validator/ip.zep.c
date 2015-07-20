
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
#include "kernel/object.h"


/**
 * Phalcon\Mvc\Model\Validator\IP
 *
 * Validates that a value is ipv4 address in valid range
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Ip;
 *
 *class Data extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      // Any pubic IP
 *      $this->validate(new IP(array(
 *          'field'             => 'server_ip',
 *          'version'           => IP::VERSION_4 | IP::VERSION_6, // v6 and v4. The same if not specified
 *          'allowReserved'     => false,   // False if not specified. Ignored for v6
 *          'allowPrivate'      => false,   // False if not specified
 *          'message'           => 'IP address has to be correct'
 *      )));
 *
 *      // Any public v4 address
 *      $this->validate(new IP(array(
 *          'field'             => 'ip_4',
 *          'version'           => IP::VERSION_4,
 *          'message'           => 'IP address has to be correct'
 *      )));
 *
 *      // Any v6 address
 *      $this->validate(new IP(array(
 *          'field'             => 'ip6',
 *          'version'           => IP::VERSION_6,
 *          'allowPrivate'      => true,
 *          'message'           => 'IP address has to be correct'
 *      )));
 *
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Ip) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Ip, phalcon, mvc_model_validator_ip, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_ip_method_entry, 0);

	phalcon_mvc_model_validator_ip_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Validator_Ip;
	zend_declare_class_constant_long(phalcon_mvc_model_validator_ip_ce, SL("VERSION_4"), 1048576 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_validator_ip_ce, SL("VERSION_6"), 2097152 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_validator_ip_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Ip, validate) {

	zval *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *value = NULL, *message = NULL, *version = NULL, *allowPrivate = NULL, *allowReserved = NULL, *options, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, _5 = zval_used_for_init, *_6, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/ip.zep", 87);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "version", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (1048576 | 2097152));
	ZEPHIR_CALL_METHOD(&version, this_ptr, "getoption", NULL, 0, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowPrivate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(allowPrivate);
		ZVAL_LONG(allowPrivate, 0);
	} else {
		ZEPHIR_INIT_NVAR(allowPrivate);
		ZVAL_LONG(allowPrivate, 8388608);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowReserved", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(allowReserved);
		ZVAL_LONG(allowReserved, 0);
	} else {
		ZEPHIR_INIT_NVAR(allowReserved);
		ZVAL_LONG(allowReserved, 4194304);
	}
	ZEPHIR_INIT_VAR(options);
	zephir_create_array(options, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_4, SL("default"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&options, SL("options"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_5);
	zephir_bitwise_or_function(&_5, version, allowPrivate TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_bitwise_or_function(_6, &_5, allowReserved TSRMLS_CC);
	zephir_array_update_string(&options, SL("flags"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 275);
	ZEPHIR_CALL_FUNCTION(&_7, "filter_var", NULL, 191, value, &_5, options);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "IP address is incorrect", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _0, _1);
		zephir_check_temp_parameter(_0);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		zephir_create_array(_4, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_4, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_8, "strtr", NULL, 53, message, _4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "IP", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _8, field, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

static zend_object_value zephir_init_properties_Phalcon_Mvc_Model_Validator_Ip(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_messages"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

