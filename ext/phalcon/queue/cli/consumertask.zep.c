
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
 * Optional CLI runner for a queue worker - the only class coupled to
 * Phalcon\Cli. A thin adapter: it resolves the context from the `queueFactory`
 * service, binds one queue to one processor (both given as command arguments),
 * and runs a Worker whose lifetime bounds come from CLI options. Users not on
 * Phalcon\Cli use Worker directly.
 *
 * Usage:
 *     <task> <queueName> <processorServiceId> \
 *         [--max-messages=N] [--max-time=SECONDS] \
 *         [--max-memory=MB] [--jitter=SECONDS]
 *
 * Register it in your own Phalcon\Cli\Console; it is not auto-wired into
 * FactoryDefault.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Cli_ConsumerTask)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Cli, ConsumerTask, phalcon, queue_cli_consumertask, phalcon_cli_task_ce, phalcon_queue_cli_consumertask_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, mainAction)
{
	zval consumer, context, di, dispatcher, options, params, processor, queueName, worker, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&consumer);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&queueName);
	ZVAL_UNDEF(&worker);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&params, &dispatcher, "getparams", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_value_long(&params, 0)) {
		zephir_memory_observe(&queueName);
		zephir_array_fetch_long(&queueName, &params, 0, PH_NOISY, "phalcon/Queue/Cli/ConsumerTask.zep", 54);
	} else {
		ZEPHIR_INIT_NVAR(&queueName);
		ZVAL_STRING(&queueName, "");
	}
	if (zephir_array_isset_value_long(&params, 1)) {
		zephir_memory_observe(&processor);
		zephir_array_fetch_long(&processor, &params, 1, PH_NOISY, "phalcon/Queue/Cli/ConsumerTask.zep", 55);
	} else {
		ZEPHIR_INIT_NVAR(&processor);
		ZVAL_STRING(&processor, "");
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "queueFactory");
	ZEPHIR_CALL_METHOD(&_1, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_3, &_2, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&context, &_1, "load", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&consumer);
	object_init_ex(&consumer, phalcon_queue_consumer_queueconsumer_ce);
	ZEPHIR_CALL_METHOD(NULL, &consumer, "__construct", NULL, 0, &context);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &context, "createqueue", NULL, 0, &queueName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &di, "get", NULL, 0, &processor);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &consumer, "bind", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&options);
	object_init_ex(&options, phalcon_queue_consumer_workeroptions_ce);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-messages");
	ZVAL_NULL(&_7);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_METHOD(&_6, &dispatcher, "getoption", NULL, 0, &_0, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-time");
	ZVAL_NULL(&_7);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_METHOD(&_9, &dispatcher, "getoption", NULL, 0, &_0, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-memory");
	ZVAL_NULL(&_7);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_METHOD(&_10, &dispatcher, "getoption", NULL, 0, &_0, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "jitter");
	ZVAL_NULL(&_7);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_METHOD(&_11, &dispatcher, "getoption", NULL, 0, &_0, &_7, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_7, zephir_get_intval(&_6));
	ZVAL_LONG(&_8, zephir_get_intval(&_9));
	ZVAL_LONG(&_12, zephir_get_intval(&_10));
	ZVAL_LONG(&_13, zephir_get_intval(&_11));
	ZEPHIR_CALL_METHOD(NULL, &options, "__construct", NULL, 0, &_7, &_8, &_12, &_13);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&worker);
	object_init_ex(&worker, phalcon_queue_consumer_worker_ce);
	ZEPHIR_CALL_METHOD(NULL, &worker, "__construct", NULL, 0, &consumer, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &worker, "run", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(0);
}

