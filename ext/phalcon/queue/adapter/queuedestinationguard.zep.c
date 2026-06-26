
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
 * Shared "destination must be a queue" guard. Producers (on send) and contexts
 * (on createConsumer) both reject any non-queue destination with the same typed
 * exception; this keeps that single rule in one place. The `action` verb
 * ("send to", "consume from") tailors the message to the caller.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_QueueDestinationGuard)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, QueueDestinationGuard, phalcon, queue_adapter_queuedestinationguard, phalcon_queue_adapter_queuedestinationguard_method_entry, 0);

	return SUCCESS;
}

/**
 * Throws InvalidDestinationException unless the destination is a queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_QueueDestinationGuard, assertQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *action = NULL;
	zval *destination, destination_sub, action_zv, _0$$3;

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&action_zv);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	destination = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&action_zv);
	ZVAL_STR_COPY(&action_zv, action);
	if (UNEXPECTED(!((zephir_instance_of_ev(destination, phalcon_contracts_queue_queue_ce))))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_queue_exceptions_invaliddestinationexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &action_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Queue/Adapter/QueueDestinationGuard.zep", 40);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

