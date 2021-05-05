
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
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
 * Class for exceptions thrown by Phalcon\Mvc\View
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt, Exception, phalcon, mvc_view_engine_volt_exception, phalcon_mvc_view_exception_ce, phalcon_mvc_view_engine_volt_exception_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_exception_ce, SL("statement"), ZEND_ACC_PROTECTED);
	phalcon_mvc_view_engine_volt_exception_ce->create_object = zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Exception;

	return SUCCESS;
}

/**
 * @param string message
 * @param array statement
 * @param int code
 * @param \Exception|null previous
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval statement;
	zval *message_param = NULL, *statement_param = NULL, *code_param = NULL, *previous = NULL, previous_sub, __$null, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&statement);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(message)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_LONG(code)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(previous, zend_ce_exception)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &message_param, &statement_param, &code_param, &previous);
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!statement_param) {
		ZEPHIR_INIT_VAR(&statement);
		array_init(&statement);
	} else {
		zephir_get_arrval(&statement, statement_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!previous) {
		previous = &previous_sub;
		previous = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("statement"), &statement);
	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_view_engine_volt_exception_ce, getThis(), "__construct", NULL, 0, &message, &_0, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets currently parsed statement (if any).
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement)
{
	zval statement, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("statement"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&statement, &_0);
	if (Z_TYPE_P(&statement) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&statement);
		array_init(&statement);
	}
	RETURN_CCTOR(&statement);
}

zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Exception(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("statement"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("statement"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

