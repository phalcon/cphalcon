
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
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_ValidatorFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation, ValidatorFactory, phalcon, filter_validation_validatorfactory, phalcon_factory_abstractfactory_ce, phalcon_filter_validation_validatorfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * TagFactory constructor.
 */
PHP_METHOD(Phalcon_Filter_Validation_ValidatorFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Filter_Validation_ValidatorFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &definition);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Validation_ValidatorFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Validation\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Filter_Validation_ValidatorFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 21, 0);
	add_assoc_stringl_ex(return_value, SL("alnum"), SL("Phalcon\\Filter\\Validation\\Validator\\Alnum"));
	add_assoc_stringl_ex(return_value, SL("alpha"), SL("Phalcon\\Filter\\Validation\\Validator\\Alpha"));
	add_assoc_stringl_ex(return_value, SL("between"), SL("Phalcon\\Filter\\Validation\\Validator\\Between"));
	add_assoc_stringl_ex(return_value, SL("callback"), SL("Phalcon\\Filter\\Validation\\Validator\\Callback"));
	add_assoc_stringl_ex(return_value, SL("confirmation"), SL("Phalcon\\Filter\\Validation\\Validator\\Confirmation"));
	add_assoc_stringl_ex(return_value, SL("creditCard"), SL("Phalcon\\Filter\\Validation\\Validator\\CreditCard"));
	add_assoc_stringl_ex(return_value, SL("date"), SL("Phalcon\\Filter\\Validation\\Validator\\Date"));
	add_assoc_stringl_ex(return_value, SL("digit"), SL("Phalcon\\Filter\\Validation\\Validator\\Digit"));
	add_assoc_stringl_ex(return_value, SL("email"), SL("Phalcon\\Filter\\Validation\\Validator\\Email"));
	add_assoc_stringl_ex(return_value, SL("exception"), SL("Phalcon\\Filter\\Validation\\Validator\\Exception"));
	add_assoc_stringl_ex(return_value, SL("exclusionIn"), SL("Phalcon\\Filter\\Validation\\Validator\\ExclusionIn"));
	add_assoc_stringl_ex(return_value, SL("file"), SL("Phalcon\\Filter\\Validation\\Validator\\File"));
	add_assoc_stringl_ex(return_value, SL("identical"), SL("Phalcon\\Filter\\Validation\\Validator\\Identical"));
	add_assoc_stringl_ex(return_value, SL("inclusionIn"), SL("Phalcon\\Filter\\Validation\\Validator\\InclusionIn"));
	add_assoc_stringl_ex(return_value, SL("ip"), SL("Phalcon\\Filter\\Validation\\Validator\\Ip"));
	add_assoc_stringl_ex(return_value, SL("numericality"), SL("Phalcon\\Filter\\Validation\\Validator\\Numericality"));
	add_assoc_stringl_ex(return_value, SL("presenceOf"), SL("Phalcon\\Filter\\Validation\\Validator\\PresenceOf"));
	add_assoc_stringl_ex(return_value, SL("regex"), SL("Phalcon\\Filter\\Validation\\Validator\\Regex"));
	add_assoc_stringl_ex(return_value, SL("stringLength"), SL("Phalcon\\Filter\\Validation\\Validator\\StringLength"));
	add_assoc_stringl_ex(return_value, SL("uniqueness"), SL("Phalcon\\Filter\\Validation\\Validator\\Uniqueness"));
	add_assoc_stringl_ex(return_value, SL("url"), SL("Phalcon\\Filter\\Validation\\Validator\\Url"));
	return;
}

