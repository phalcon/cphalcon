
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
ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation, ValidatorFactory, phalcon, validation_validatorfactory, phalcon_factory_abstractfactory_ce, phalcon_validation_validatorfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * TagFactory constructor.
 */
PHP_METHOD(Phalcon_Validation_ValidatorFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Creates a new instance
 */
PHP_METHOD(Phalcon_Validation_ValidatorFactory, newInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&definition);
	zephir_array_fetch(&definition, &_0, &name, PH_NOISY, "phalcon/Validation/ValidatorFactory.zep", 35);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &definition);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Validation_ValidatorFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 21, 0);
	add_assoc_stringl_ex(return_value, SL("alnum"), SL("Phalcon\\Validation\\Validator\\Alnum"));
	add_assoc_stringl_ex(return_value, SL("alpha"), SL("Phalcon\\Validation\\Validator\\Alpha"));
	add_assoc_stringl_ex(return_value, SL("between"), SL("Phalcon\\Validation\\Validator\\Between"));
	add_assoc_stringl_ex(return_value, SL("callback"), SL("Phalcon\\Validation\\Validator\\Callback"));
	add_assoc_stringl_ex(return_value, SL("confirmation"), SL("Phalcon\\Validation\\Validator\\Confirmation"));
	add_assoc_stringl_ex(return_value, SL("creditCard"), SL("Phalcon\\Validation\\Validator\\CreditCard"));
	add_assoc_stringl_ex(return_value, SL("date"), SL("Phalcon\\Validation\\Validator\\Date"));
	add_assoc_stringl_ex(return_value, SL("digit"), SL("Phalcon\\Validation\\Validator\\Digit"));
	add_assoc_stringl_ex(return_value, SL("email"), SL("Phalcon\\Validation\\Validator\\Email"));
	add_assoc_stringl_ex(return_value, SL("exception"), SL("Phalcon\\Validation\\Validator\\Exception"));
	add_assoc_stringl_ex(return_value, SL("exclusionIn"), SL("Phalcon\\Validation\\Validator\\ExclusionIn"));
	add_assoc_stringl_ex(return_value, SL("file"), SL("Phalcon\\Validation\\Validator\\File"));
	add_assoc_stringl_ex(return_value, SL("identical"), SL("Phalcon\\Validation\\Validator\\Identical"));
	add_assoc_stringl_ex(return_value, SL("inclusionIn"), SL("Phalcon\\Validation\\Validator\\InclusionIn"));
	add_assoc_stringl_ex(return_value, SL("ip"), SL("Phalcon\\Validation\\Validator\\Ip"));
	add_assoc_stringl_ex(return_value, SL("numericality"), SL("Phalcon\\Validation\\Validator\\Numericality"));
	add_assoc_stringl_ex(return_value, SL("presenceOf"), SL("Phalcon\\Validation\\Validator\\PresenceOf"));
	add_assoc_stringl_ex(return_value, SL("regex"), SL("Phalcon\\Validation\\Validator\\Regex"));
	add_assoc_stringl_ex(return_value, SL("stringLength"), SL("Phalcon\\Validation\\Validator\\StringLength"));
	add_assoc_stringl_ex(return_value, SL("uniqueness"), SL("Phalcon\\Validation\\Validator\\Uniqueness"));
	add_assoc_stringl_ex(return_value, SL("url"), SL("Phalcon\\Validation\\Validator\\Url"));
	return;

}

