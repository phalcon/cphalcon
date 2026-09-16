
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
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
 *
 * @phpstan-import-type mvc_volt_node from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine\\Volt, Exception, phalcon, mvc_view_engine_volt_exception, phalcon_mvc_view_exception_ce, phalcon_mvc_view_engine_volt_exception_method_entry, 0);

	/**
	 * @phpstan-var mvc_volt_node
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_exception_ce, SL("statement"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @param string message
 * @param array statement
 * @param int code
 * @param \Exception|null previous
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval statement;
	zval message_zv, *statement_param = NULL, *code_param = NULL, *previous = NULL, previous_sub, __$null, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&statement);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("statement", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(message)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_LONG(code)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(previous, zend_ce_exception)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		statement_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		code_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		previous = ZEND_CALL_ARG(execute_data, 4);
	}
	if (!message) {
		message = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&message_zv);
		ZVAL_STR(&message_zv, message);
	} else {
		zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
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
		}
	if (!previous) {
		previous = &previous_sub;
		previous = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 10, &statement);
	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_view_engine_volt_exception_ce, getThis(), "__construct", NULL, 0, &message_zv, &_0, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Gets currently parsed statement (if any).
 *
 * @phpstan-return mvc_volt_node
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement)
{
	zval statement, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("statement", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 10, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&statement, &_0);
	if (Z_TYPE_P(&statement) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&statement);
		array_init(&statement);
	}
	RETURN_CCTOR(&statement);
}

