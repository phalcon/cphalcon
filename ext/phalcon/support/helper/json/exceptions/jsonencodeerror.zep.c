
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Exceptions_JsonEncodeError)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Json\\Exceptions, JsonEncodeError, phalcon, support_helper_json_exceptions_jsonencodeerror, spl_ce_InvalidArgumentException, phalcon_support_helper_json_exceptions_jsonencodeerror_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Support_Helper_Json_Exceptions_JsonEncodeError, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, *code_param = NULL, *previous = NULL, previous_sub, __$null, _1;
	zend_string *message = NULL;

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(message)
		Z_PARAM_LONG(code)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(previous, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		code_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		previous = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!message) {
		message = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&message_zv);
		ZVAL_STR(&message_zv, message);
	} else {
		zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	}
	if (!code_param) {
		code = 0;
	} else {
		}
	if (!previous) {
		previous = &previous_sub;
		previous = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "json_encode error: ", &message_zv);
	ZVAL_LONG(&_1, code);
	ZEPHIR_CALL_PARENT(NULL, phalcon_support_helper_json_exceptions_jsonencodeerror_ce, getThis(), "__construct", NULL, 0, &_0, &_1, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

