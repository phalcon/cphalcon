
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
ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_Exceptions_InvalidModifier)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Time\\Clock\\Exceptions, InvalidModifier, phalcon, time_clock_exceptions_invalidmodifier, phalcon_time_clock_exception_ce, phalcon_time_clock_exceptions_invalidmodifier_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Time_Clock_Exceptions_InvalidModifier, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval modifier_zv, *ex = NULL, ex_sub, __$null, _1;
	zend_string *modifier = NULL;

	ZVAL_UNDEF(&modifier_zv);
	ZVAL_UNDEF(&ex_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(modifier)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(ex, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		ex = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	if (!ex) {
		ex = &ex_sub;
		ex = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Invalid modifier: \"", &modifier_zv, "\"");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_time_clock_exceptions_invalidmodifier_ce, getThis(), "__construct", NULL, 0, &_0, &_1, ex);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

