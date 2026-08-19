
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Shared producer base. Defaults every optional capability (delivery delay,
 * priority, time to live) to "unsupported": the getter returns null and the
 * setter throws the matching exception for any non-null value. A concrete
 * producer overrides only the capabilities its transport actually supports,
 * and implements `send()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractProducer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, AbstractProducer, phalcon, queue_adapter_abstractproducer, phalcon_queue_adapter_abstractproducer_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_queue_adapter_abstractproducer_ce, 1, phalcon_contracts_queue_producer_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getDeliveryDelay)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getPriority)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getTimeToLive)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, send)
{
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setDeliveryDelay)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deliveryDelay = NULL, deliveryDelay_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&deliveryDelay_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(deliveryDelay)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &deliveryDelay);
	if (!deliveryDelay) {
		deliveryDelay = &deliveryDelay_sub;
		deliveryDelay = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(deliveryDelay) != IS_NULL)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_queue_exceptions_deliverydelaynotsupportedexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 78);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Queue/Adapter/AbstractProducer.zep", 58);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setPriority)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *priority = NULL, priority_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&priority_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(priority)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &priority);
	if (!priority) {
		priority = &priority_sub;
		priority = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(priority) != IS_NULL)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_queue_exceptions_prioritynotsupportedexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 79);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Queue/Adapter/AbstractProducer.zep", 67);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setTimeToLive)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *timeToLive = NULL, timeToLive_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeToLive_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(timeToLive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &timeToLive);
	if (!timeToLive) {
		timeToLive = &timeToLive_sub;
		timeToLive = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(timeToLive) != IS_NULL)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_queue_exceptions_timetolivenotsupportedexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 80);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Queue/Adapter/AbstractProducer.zep", 76);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

