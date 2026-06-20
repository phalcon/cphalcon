
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
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared consumer base. Implements the blocking `receive()` as a polling loop
 * on top of the abstract `receiveNoWait()`; concrete consumers provide the
 * transport-specific `receiveNoWait`, `acknowledge`, `reject` and `getQueue`.
 *
 * Transports with a native blocking receive (Redis BRPOP, Beanstalk reserve)
 * override `receive()` instead of polling.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractConsumer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, AbstractConsumer, phalcon, queue_adapter_abstractconsumer, phalcon_queue_adapter_abstractconsumer_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Milliseconds slept between poll attempts.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_abstractconsumer_ce, SL("pollInterval"), 200, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_abstractconsumer_ce, 1, phalcon_contracts_queue_consumer_ce);
	return SUCCESS;
}

/**
 * Acknowledges the message; the transport may then discard it.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, acknowledge)
{
}

/**
 * Returns the queue this consumer reads from.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, getQueue)
{
}

/**
 * Receives a message, blocking up to timeout milliseconds (0 = block
 * until one is available), by polling `receiveNoWait()` every
 * `pollInterval` milliseconds. Returns null when none arrives in time.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, receive)
{
	zend_bool _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zval *timeout_param = NULL, __$true, message, _0, _1, _4$$3, _5$$3;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS, startTime = 0, sleep = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &timeout_param);
	if (!timeout_param) {
		timeout = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	sleep = (zephir_get_numberval(&_0) * 1000);
	ZEPHIR_INIT_VAR(&_1);
	zephir_microtime(&_1, &__$true);
	startTime = (zephir_get_numberval(&_1) * 1000);
	while (1) {
		ZEPHIR_CALL_METHOD(&message, this_ptr, "receivenowait", &_2, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&message) != IS_NULL) {
			RETURN_CCTOR(&message);
		}
		_3$$3 = timeout > 0;
		if (_3$$3) {
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_microtime(&_4$$3, &__$true);
			_3$$3 = ((zephir_get_numberval(&_4$$3) * 1000) - startTime) >= timeout;
		}
		if (_3$$3) {
			RETURN_MM_NULL();
		}
		ZVAL_LONG(&_5$$3, sleep);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_6, 127, &_5$$3);
		zephir_check_call_status();
	}
	RETURN_MM_NULL();
}

/**
 * Receives a message without blocking, or null when none is ready.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, receiveNoWait)
{
}

/**
 * Rejects the message. When requeue is true the transport redelivers it.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, reject)
{
}

/**
 * Sets the poll interval (in milliseconds) used by `receive()`.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, setPollInterval)
{
	zval *pollInterval_param = NULL, _0;
	zend_long pollInterval;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pollInterval_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pollInterval"), &_0);
}

