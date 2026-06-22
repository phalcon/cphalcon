
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
ZEPHIR_INIT_CLASS(Phalcon_Time_Clock_SystemClock)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Time\\Clock, SystemClock, phalcon, time_clock_systemclock, phalcon_time_clock_systemclock_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var DateTimeZone
	 */
	zend_declare_property_null(phalcon_time_clock_systemclock_ce, SL("timezone"), ZEND_ACC_PRIVATE);
	zend_class_implements(phalcon_time_clock_systemclock_ce, 1, phalcon_time_clock_clockinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Time_Clock_SystemClock, __construct)
{
	zval *timezone, timezone_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timezone_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(timezone, php_date_get_timezone_ce())
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &timezone);
	zephir_update_property_zval(this_ptr, ZEND_STRL("timezone"), timezone);
}

/**
 * Return a new object of now with the current timezone
 */
PHP_METHOD(Phalcon_Time_Clock_SystemClock, fromSystemTimezone)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_time_clock_systemclock_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_CALL_FUNCTION(&_1, "date_default_timezone_get", NULL, 206);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 207, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return a new object of now with UTC
 */
PHP_METHOD(Phalcon_Time_Clock_SystemClock, fromUTC)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_time_clock_systemclock_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTC");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 207, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the current clock
 */
PHP_METHOD(Phalcon_Time_Clock_SystemClock, now)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, php_date_get_immutable_ce());
	zephir_read_property(&_0, this_ptr, ZEND_STRL("timezone"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "now");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

