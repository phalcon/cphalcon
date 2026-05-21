
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by lcobucci/clock
 *
 * @link    https://github.com/lcobucci/clock
 * @license https://github.com/lcobucci/clock/blob/3.7.x/LICENSE
 */
ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Time\\Clock, Exception, phalcon, time_clock_exception, zend_ce_exception, phalcon_time_clock_exception_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Time_Clock_Exception, invalidModifier)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, *ex = NULL, ex_sub, __$null, _1;
	zend_string *message = NULL;

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&ex_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(ex, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		ex = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!ex) {
		ex = &ex_sub;
		ex = &__$null;
	}
	object_init_ex(return_value, phalcon_time_clock_exception_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Invalid modifier: \"", &message_zv, "\"");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 8, &_0, &_1, ex);
	zephir_check_call_status();
	RETURN_MM();
}

