
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
/**
 * Derives elapsed milliseconds and seconds from the nanosecond total that the
 * using class exposes through getTotalElapsedNanoseconds().
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Traits_ElapsedTimeTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Db\\Traits, ElapsedTimeTrait, phalcon, db_traits_elapsedtimetrait, phalcon_db_traits_elapsedtimetrait_method_entry);

	return SUCCESS;
}

/**
 * Returns the total time in nanoseconds spent by the profiles. Implemented
 * by the using class.
 */
PHP_METHOD(Phalcon_Db_Traits_ElapsedTimeTrait, getTotalElapsedNanoseconds)
{
}

/**
 * Returns the total time in milliseconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Traits_ElapsedTimeTrait, getTotalElapsedMilliseconds)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettotalelapsednanoseconds", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_safe_div_zval_long(&_0, 1000000));
}

/**
 * Returns the total time in seconds spent by the profiles
 */
PHP_METHOD(Phalcon_Db_Traits_ElapsedTimeTrait, getTotalElapsedSeconds)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettotalelapsedmilliseconds", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_safe_div_zval_long(&_0, 1000));
}

