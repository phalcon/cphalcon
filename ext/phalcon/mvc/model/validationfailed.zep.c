
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, ValidationFailed, phalcon, mvc_model_validationfailed, phalcon_mvc_model_exception_ce, phalcon_mvc_model_validationfailed_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_validationfailed_ce, SL("model"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Mvc\\ModelInterface"));
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_validationfailed_ce, SL("validationMessages"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\ValidationFailed constructor
 *
 * @param ModelInterface model
 * @param Message[] validationMessages
 *
 * @phpstan-param list<MessageInterface> $validationMessages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validationMessages;
	zval *model, model_sub, *validationMessages_param = NULL, messageStr, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messageStr);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validationMessages);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("model", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("validationMessages", 18, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(validationMessages, validationMessages_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &model, &validationMessages_param);
	zephir_get_arrval(&validationMessages, validationMessages_param);
	if (!(ZEPHIR_IS_EMPTY(&validationMessages))) {
		zephir_memory_observe(&message);
		zephir_array_fetch_long(&message, &validationMessages, 0, PH_NOISY, "phalcon/Mvc/Model/ValidationFailed.zep", 45);
		ZEPHIR_CALL_METHOD(&messageStr, &message, "getmessage", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&messageStr);
		ZVAL_STRING(&messageStr, "Validation failed");
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1137, model);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1138, &validationMessages);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_validationfailed_ce, getThis(), "__construct", NULL, 0, &messageStr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the complete group of messages produced in the validation
 *
 * @phpstan-return list<MessageInterface>
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages)
{

	RETURN_MEMBER_TYPED(getThis(), "validationMessages", IS_ARRAY);
}

/**
 * Returns the model that generated the messages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel)
{

	RETURN_MEMBER(getThis(), "model");
}

