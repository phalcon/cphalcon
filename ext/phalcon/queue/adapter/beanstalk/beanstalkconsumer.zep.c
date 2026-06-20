
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Receives messages from a single Beanstalkd tube over its own connection.
 * `receive()` is overridden to use the native blocking reserve. Implements
 * VisibilityAware: a reserved job has a time-to-run window that `touch()`
 * extends; acknowledging deletes the job, rejecting releases it (requeue) or
 * buries it.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkConsumer, phalcon, queue_adapter_beanstalk_beanstalkconsumer, phalcon_queue_adapter_abstractconsumer_ce, phalcon_queue_adapter_beanstalk_beanstalkconsumer_method_entry, 0);

	/**
	 * @var BeanstalkConnection
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * @var QueueInterface
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce, SL("queue"), ZEND_ACC_PROTECTED);
	/**
	 * Default Beanstalkd priority used when releasing or burying.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce, SL("DEFAULT_PRIORITY"), 100);

	zend_class_implements(phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce, 1, phalcon_contracts_queue_visibilityaware_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *queue, queue_sub, tube, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_queue_adapter_beanstalk_beanstalkconnection_ce)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &connection, &queue);
	zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), connection);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queue"), queue);
	ZEPHIR_CALL_METHOD(&tube, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, connection, "watchtube", NULL, 0, &tube);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&tube, "default")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "default");
		ZEPHIR_CALL_METHOD(NULL, connection, "ignoretube", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, acknowledge)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvejobid", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "deletejob", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, getQueue)
{

	RETURN_MEMBER(getThis(), "queue");
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receive)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timeout_param = NULL, seconds, _0, _1;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&seconds);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZEPHIR_INIT_VAR(&seconds);
	if (timeout <= 0) {
		ZVAL_NULL(&seconds);
	} else {
		ZVAL_LONG(&seconds, (int) (zephir_safe_div_long_long(((timeout + 999)), 1000)));
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "reserve", NULL, 0, &seconds);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "buildmessage", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receiveNoWait)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, &_0, "reserve", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "buildmessage", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, reject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool requeue;
	zval *message, message_sub, *requeue_param = NULL, id, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(requeue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &message, &requeue_param);
	if (!requeue_param) {
		requeue = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&id, this_ptr, "resolvejobid", NULL, 0, message);
	zephir_check_call_status();
	if (requeue) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 100);
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "releasejob", NULL, 0, &id, &_1$$3, &_2$$3);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$4, 100);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "buryjob", NULL, 0, &id, &_4$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Extends the time-to-run window of a reserved job (VisibilityAware).
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, touch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvejobid", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "touchjob", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a BeanstalkMessage from a reserved [id, body] pair, or null.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, buildMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *job, job_sub, data, message, _0, _1, _2, _3, _4;

	ZVAL_UNDEF(&job_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(job)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &job);
	if (Z_TYPE_P(job) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_long(&_0, job, 1, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConsumer.zep", 128);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 28, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&message);
	object_init_ex(&message, phalcon_queue_adapter_beanstalk_beanstalkmessage_ce);
	zephir_array_fetch_string(&_1, &data, SL("body"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConsumer.zep", 134);
	zephir_array_fetch_string(&_2, &data, SL("properties"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConsumer.zep", 134);
	zephir_array_fetch_string(&_3, &data, SL("headers"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConsumer.zep", 134);
	ZEPHIR_CALL_METHOD(NULL, &message, "__construct", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, job, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConsumer.zep", 136);
	ZEPHIR_CALL_METHOD(NULL, &message, "setjobid", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&message);
}

/**
 * Resolves a message's Beanstalkd job id. The `message` parameter is typed
 * `var` so the call is dynamic; this avoids Zephir resolving getJobId()
 * against the Message interface, which does not declare it.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, resolveJobId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub;

	ZVAL_UNDEF(&message_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	ZEPHIR_RETURN_CALL_METHOD(message, "getjobid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

