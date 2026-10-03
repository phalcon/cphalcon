
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


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
	zval config, context, consumer, di, dispatcher, queueConfig, queueName, queueFactory, options, params, processor, processorService, _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&consumer);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&queueConfig);
	ZVAL_UNDEF(&queueName);
	ZVAL_UNDEF(&queueFactory);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&processorService);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&di, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "dispatcher");
	ZEPHIR_CALL_METHOD(&dispatcher, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "queueFactory");
	ZEPHIR_CALL_METHOD(&queueFactory, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZEPHIR_CALL_METHOD(&config, &di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&params, &dispatcher, "getparams", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(&queueName, this_ptr, "stringparam", NULL, 0, &params, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&processor, this_ptr, "stringparam", NULL, 0, &params, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "queue");
	ZEPHIR_CALL_METHOD(&queueConfig, &config, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&context, &queueFactory, "load", NULL, 0, &queueConfig);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&consumer);
	object_init_ex(&consumer, phalcon_queue_consumer_queueconsumer_ce);
	ZEPHIR_CALL_METHOD(NULL, &consumer, "__construct", NULL, 0, &context);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&processorService, &di, "get", NULL, 0, &processor);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &context, "createqueue", NULL, 0, &queueName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &consumer, "bind", NULL, 0, &_2, &processorService);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&options);
	object_init_ex(&options, phalcon_queue_consumer_workeroptions_ce);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-messages");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "intoption", NULL, 0, &dispatcher, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-time");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "intoption", NULL, 0, &dispatcher, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max-memory");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "intoption", NULL, 0, &dispatcher, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "jitter");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "intoption", NULL, 0, &dispatcher, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &options, "__construct", NULL, 0, &_3, &_4, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, phalcon_queue_consumer_worker_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &consumer, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "run", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(0);
}

/**
 * Reads a CLI option as an int, defaulting to 0 when it is absent or
 * cannot be expressed as a number.
 */
PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, intOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *dispatcher, dispatcher_sub, name_zv, value, _0, _1, _2;

	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(dispatcher, phalcon_cli_dispatcher_ce)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	dispatcher = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZVAL_NULL(&_0);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(&value, dispatcher, "getoption", NULL, 0, &name_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_is_scalar(&value)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, zephir_get_intval(&value));
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, 0);
	}
	RETURN_CCTOR(&_2);
}

/**
 * Reads a positional CLI argument as a string, defaulting to an empty
 * string when it is absent or cannot be expressed as one.
 *
 * @param array<int|string, mixed> $params
 */
PHP_METHOD(Phalcon_Queue_Cli_ConsumerTask, stringParam)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index;
	zval *params_param = NULL, *index_param = NULL, value, _0;
	zval params;

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &params_param, &index_param);
	zephir_get_arrval(&params, params_param);
	if (zephir_array_isset_value_long(&params, index)) {
		zephir_memory_observe(&value);
		zephir_array_fetch_long(&value, &params, index, PH_NOISY, "phalcon/Queue/Cli/ConsumerTask.zep", 119);
	} else {
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_STRING(&value, "");
	}
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_scalar(&value)) {
		zephir_cast_to_string(&_1, &value);
		ZEPHIR_CPY_WRT(&_0, &_1);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	RETURN_CCTOR(&_0);
}

