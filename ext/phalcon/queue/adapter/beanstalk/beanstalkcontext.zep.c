
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
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
 * Beanstalkd transport session. A queue maps to a Beanstalkd tube. Producers
 * share the context connection (`use` + `put`); each consumer owns its own
 * connection, because Beanstalkd only lets the reserving connection delete,
 * release, bury or touch a job.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkContext, phalcon, queue_adapter_beanstalk_beanstalkcontext, phalcon_queue_adapter_beanstalk_beanstalkcontext_method_entry, 0);

	/**
	 * Shared connection used by producers and purges.
	 *
	 * @var BeanstalkConnection | null
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("host"), "127.0.0.1", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("persistent"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Milliseconds slept between poll passes by a subscription consumer.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("pollInterval"), 200, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("port"), 11300, ZEND_ACC_PROTECTED);
	/**
	 * Default time-to-run (seconds) applied to every put.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, SL("ttr"), 86400, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_beanstalk_beanstalkcontext_ce, 1, phalcon_contracts_queue_context_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, __construct)
{
	zend_bool persistent;
	zend_long port, ttr, pollInterval;
	zval host_zv, *port_param = NULL, *persistent_param = NULL, *ttr_param = NULL, *pollInterval_param = NULL, __$true, __$false, _0;
	zend_string *host = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_STR(host)
		Z_PARAM_LONG(port)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(persistent)
		Z_PARAM_LONG(ttr)
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	port_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		persistent_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		ttr_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		pollInterval_param = ZEND_CALL_ARG(execute_data, 5);
	}
	ZVAL_STR(&host_zv, host);
	if (!persistent_param) {
		persistent = 0;
	} else {
		}
	if (!ttr_param) {
		ttr = 86400;
	} else {
		}
	if (!pollInterval_param) {
		pollInterval = 200;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &host_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, port);
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_0);
	if (persistent) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("persistent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("persistent"), &__$false);
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, ttr);
	zephir_update_property_zval(this_ptr, ZEND_STRL("ttr"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pollInterval"), &_0);
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, close)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "disconnect", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), &__$null);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createConsumer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &destination);
	if (UNEXPECTED(!((zephir_instance_of_ev(destination, phalcon_contracts_queue_queue_ce))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_invaliddestinationexception_ce, "The Beanstalk transport can only consume from a Queue destination", "phalcon/Queue/Adapter/Beanstalk/BeanstalkContext.zep", 104);
		return;
	}
	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0, destination);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval properties, headers;
	zval body_zv, *properties_param = NULL, *headers_param = NULL;
	zend_string *body = NULL;

	ZVAL_UNDEF(&body_zv);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&headers);
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(body)
		ZEPHIR_Z_PARAM_ARRAY(properties, properties_param)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		properties_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		headers_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!body) {
		body = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&body_zv);
		ZVAL_STR(&body_zv, body);
	} else {
		zephir_memory_observe(&body_zv);
	ZVAL_STR_COPY(&body_zv, body);
	}
	if (!properties_param) {
		ZEPHIR_INIT_VAR(&properties);
		array_init(&properties);
	} else {
		zephir_get_arrval(&properties, properties_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkmessage_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &body_zv, &properties, &headers);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createProducer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkproducer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv;
	zend_string *queueName = NULL;

	ZVAL_UNDEF(&queueName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkqueue_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createSubscriptionConsumer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalksubscriptionconsumer_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createTemporaryQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkqueue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "phalcon_queue_");
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 0, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createTopic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval topicName_zv;
	zend_string *topicName = NULL;

	ZVAL_UNDEF(&topicName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(topicName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&topicName_zv);
	ZVAL_STR_COPY(&topicName_zv, topicName);
	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalktopic_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &topicName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Default time-to-run (seconds) for new jobs. Used by BeanstalkProducer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getTtr)
{

	RETURN_MEMBER_TYPED(getThis(), "ttr", IS_LONG);
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, purgeQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, connection, tube, job, _0$$3, _1$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&job);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &queue);
	ZEPHIR_CALL_METHOD(&tube, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "newconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "watchtube", NULL, 0, &tube);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&tube, "default")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "default");
		ZEPHIR_CALL_METHOD(NULL, &connection, "ignoretube", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	while (1) {
		ZVAL_LONG(&_1$$4, 0);
		ZEPHIR_CALL_METHOD(&job, &connection, "reserve", &_2, 0, &_1$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&job) == IS_NULL) {
			break;
		}
		zephir_array_fetch_long(&_3$$4, &job, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkContext.zep", 168);
		ZEPHIR_CALL_METHOD(NULL, &connection, "deletejob", &_4, 0, &_3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "disconnect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Puts a serialized payload on a tube via the shared connection.
 * Internal transport API used by BeanstalkProducer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, putMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, delay, ttr, ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, payload_zv, *priority_param = NULL, *delay_param = NULL, *ttr_param = NULL, connection, _0, _1, _2;
	zend_string *tube = NULL, *payload = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(tube)
		Z_PARAM_STR(payload)
		Z_PARAM_LONG(priority)
		Z_PARAM_LONG(delay)
		Z_PARAM_LONG(ttr)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	priority_param = ZEND_CALL_ARG(execute_data, 3);
	delay_param = ZEND_CALL_ARG(execute_data, 4);
	ttr_param = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&tube_zv);
	ZVAL_STR_COPY(&tube_zv, tube);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "usetube", NULL, 0, &tube_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_0, priority);
	ZVAL_LONG(&_1, delay);
	ZVAL_LONG(&_2, ttr);
	ZEPHIR_CALL_METHOD(NULL, &connection, "put", NULL, 0, &payload_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the shared producer/purge connection, connecting on first use.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getConnection)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "newconnection", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "connection");
}

/**
 * Builds and connects a fresh Beanstalkd connection.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, newConnection)
{
	zval connection, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&connection);
	object_init_ex(&connection, phalcon_queue_adapter_beanstalk_beanstalkconnection_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("persistent"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &connection, "__construct", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "connect", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&connection);
}

