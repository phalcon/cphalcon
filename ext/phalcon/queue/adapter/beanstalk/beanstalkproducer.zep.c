
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Sends messages to a Beanstalkd tube. Delivery delay (rounded down to whole
 * seconds) and message priority are supported natively; Beanstalkd has no
 * message expiry, so time to live is not.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkProducer, phalcon, queue_adapter_beanstalk_beanstalkproducer, phalcon_queue_adapter_beanstalk_beanstalkproducer_method_entry, 0);

	/**
	 * @var BeanstalkContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkproducer_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * Delivery delay in milliseconds, or null when not set.
	 *
	 * @var int | null
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkproducer_ce, SL("deliveryDelay"), ZEND_ACC_PROTECTED);
	/**
	 * Job priority, or null when not set.
	 *
	 * @var int | null
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkproducer_ce, SL("priority"), ZEND_ACC_PROTECTED);
	/**
	 * Default Beanstalkd priority (0 = most urgent).
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_queue_adapter_beanstalk_beanstalkproducer_ce, SL("DEFAULT_PRIORITY"), 100);

	zend_class_implements(phalcon_queue_adapter_beanstalk_beanstalkproducer_ce, 1, phalcon_contracts_queue_producer_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_beanstalk_beanstalkcontext_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, getDeliveryDelay)
{

	RETURN_MEMBER(getThis(), "deliveryDelay");
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, getPriority)
{

	RETURN_MEMBER(getThis(), "priority");
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, getTimeToLive)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, send)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, priority = 0, delay = 0;
	zval *destination, destination_sub, *message, message_sub, payload, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&payload);
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
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &destination, &message);
	if (UNEXPECTED(!((zephir_instance_of_ev(destination, phalcon_contracts_queue_queue_ce))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_invaliddestinationexception_ce, "The Beanstalk transport can only send to a Queue destination", "phalcon/Queue/Adapter/Beanstalk/BeanstalkProducer.zep", 81);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_CALL_METHOD(&_1, message, "getbody", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("body"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, message, "getproperties", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("properties"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, message, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("headers"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&payload, "serialize", NULL, 23, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, 100);
	} else {
		zephir_memory_observe(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("priority"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, zephir_get_intval(&_4));
	}
	priority = zephir_get_numberval(&_2);
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, 0);
	} else {
		zephir_read_property(&_7, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, (int) (zephir_safe_div_zval_long(&_7, 1000)));
	}
	delay = zephir_get_numberval(&_5);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, destination, "getqueuename", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_10, &_9, "getttr", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_11, priority);
	ZVAL_LONG(&_12, delay);
	ZEPHIR_CALL_METHOD(NULL, &_8, "putmessage", NULL, 0, &_1, &payload, &_11, &_12, &_10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, setDeliveryDelay)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *deliveryDelay = NULL, deliveryDelay_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&deliveryDelay_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
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
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(deliveryDelay) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, zephir_get_intval(deliveryDelay));
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("deliveryDelay"), &_0);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, setPriority)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *priority = NULL, priority_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&priority_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
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
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(priority) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, zephir_get_intval(priority));
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("priority"), &_0);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkProducer, setTimeToLive)
{
	zval *timeToLive = NULL, timeToLive_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeToLive_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(timeToLive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &timeToLive);
	if (!timeToLive) {
		timeToLive = &timeToLive_sub;
		timeToLive = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(timeToLive) != IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_queue_exceptions_timetolivenotsupportedexception_ce, "The Beanstalk transport does not support a time to live", "phalcon/Queue/Adapter/Beanstalk/BeanstalkProducer.zep", 123);
		return;
	}
	RETURN_THISW();
}

