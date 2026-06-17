
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/date/php_date.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_FrozenClock)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Time\\Clock, FrozenClock, phalcon, time_clock_frozenclock, phalcon_time_clock_frozenclock_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var DateTimeImmutable
	 */
	zend_declare_property_null(phalcon_time_clock_frozenclock_ce, SL("now"), ZEND_ACC_PRIVATE);
	zend_class_implements(phalcon_time_clock_frozenclock_ce, 1, phalcon_time_clock_clockinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Time_Clock_FrozenClock, __construct)
{
	zval *now, now_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&now_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(now, php_date_get_immutable_ce())
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &now);
	zephir_update_property_zval(this_ptr, ZEND_STRL("now"), now);
}

/**
 * Mutates the clock to a new value. All consumers receive the same modification
 *
 * @throws InvalidModifier
 */
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, adjust)
{
	zend_bool failed = 0, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval modifier_zv, __$false, ex, modified, priorWarning, _0, _1, _2, _3, _4$$4, _5$$3, _6$$5, _7$$6, _8$$6, _10$$7;
	zend_string *modifier = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modifier_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&modified);
	ZVAL_UNDEF(&priorWarning);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	failed = 0;
	ZEPHIR_CALL_FUNCTION(&_0, "phpversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8.3");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ">=");
	ZEPHIR_CALL_FUNCTION(&_3, "version_compare", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {

		/* try_start_1: */

			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("now"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&modified, &_4$$4, "modify", NULL, 0, &modifier_zv);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_5$$3);
			ZVAL_OBJ(&_5$$3, EG(exception));
			Z_ADDREF_P(&_5$$3);
			if (zephir_is_instance_of(&_5$$3, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&ex, &_5$$3);
				ZEPHIR_INIT_VAR(&_6$$5);
				object_init_ex(&_6$$5, phalcon_time_clock_exceptions_invalidmodifier_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 0, &modifier_zv, &ex);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$5, "phalcon/Time/Clock/FrozenClock.zep", 51);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&priorWarning);
		ZVAL_BOOL(&priorWarning, ZEPHIR_GLOBAL(warning).enable);
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZEPHIR_INIT_NVAR(&_7$$6);
		zephir_create_closure_ex(&_7$$6, NULL, phalcon_91__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_8$$6, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 235, &_7$$6, &_8$$6);
		zephir_check_call_status();
		zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("now"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&modified, &_8$$6, "modify", NULL, 0, &modifier_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 236);
		zephir_check_call_status();
		failed = ZEPHIR_GLOBAL(warning).enable;
		ZEPHIR_GLOBAL(warning).enable = zend_is_true(&priorWarning);
	}
	_9 = failed;
	if (!(_9)) {
		_9 = ZEPHIR_IS_FALSE_IDENTICAL(&modified);
	}
	if (UNEXPECTED(_9)) {
		ZEPHIR_INIT_VAR(&_10$$7);
		object_init_ex(&_10$$7, phalcon_time_clock_exceptions_invalidmodifier_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 0, &modifier_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$7, "phalcon/Time/Clock/FrozenClock.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("now"), &modified);
	RETURN_THIS();
}

/**
 * Return a new object of now with the current timezone
 */
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, fromSystemTimezone)
{
	zval _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_time_clock_frozenclock_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_immutable_ce());
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, php_date_get_timezone_ce());
	ZEPHIR_CALL_FUNCTION(&_2, "date_default_timezone_get", NULL, 187);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "now");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return a new object of now with UTC
 */
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, fromUTC)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_time_clock_frozenclock_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_immutable_ce());
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UTC");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "now");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the current clock
 */
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, now)
{

	RETURN_MEMBER(getThis(), "now");
}

/**
 * Sets the clock to a new value. All consumers receive the same modification
 */
PHP_METHOD(Phalcon_Time_Clock_FrozenClock, set)
{
	zval *now, now_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&now_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(now, php_date_get_immutable_ce())
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &now);
	zephir_update_property_zval(this_ptr, ZEND_STRL("now"), now);
	RETURN_THISW();
}

