
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Shared implementation of every Message getter/setter, plus the
 * correlation-id / message-id / timestamp / reply-to header conveniences.
 * Concrete adapter messages use this trait.
 *
 * The convenience accessors are stored as transport headers under fixed keys
 * for binary compatibility with the wider interop ecosystem.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Traits_MessageTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Queue\\Adapter\\Traits, MessageTrait, phalcon, queue_adapter_traits_messagetrait, phalcon_queue_adapter_traits_messagetrait_method_entry);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_traits_messagetrait_ce, SL("body"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_queue_adapter_traits_messagetrait_ce, SL("headers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_queue_adapter_traits_messagetrait_ce, SL("properties"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_queue_adapter_traits_messagetrait_ce, SL("redelivered"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Message constructor.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval properties, headers;
	zval body_zv, *properties_param = NULL, *headers_param = NULL;
	zend_string *body = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_zv);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&headers);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("body", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("properties", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("headers", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1270, &body_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1271, &properties);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1272, &headers);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the message body.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getBody)
{

	RETURN_MEMBER_TYPED(getThis(), "body", IS_STRING);
}

/**
 * Returns the correlation id used to correlate request/reply messages.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getCorrelationId)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "correlation_id");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a single header value, or the default when it is not set.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeader)
{
	zval name_zv, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR(&name_zv, name);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1272, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1272, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Traits/MessageTrait.zep", 88);
		RETURN_CTORW(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Returns all transport headers.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaders)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1272, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Returns the message id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getMessageId)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "message_id");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns all application properties.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperties)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("properties", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1271, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Returns a single property value, or the default when it is not set.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperty)
{
	zval name_zv, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("properties", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR(&name_zv, name);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1271, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1271, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Traits/MessageTrait.zep", 124);
		RETURN_CTORW(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Returns the reply-to destination name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getReplyTo)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "reply_to");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the timestamp (in milliseconds) or null when it is not set.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getTimestamp)
{
	zval value, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "timestamp");
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	RETURN_MM_LONG(zephir_get_intval(&value));
}

/**
 * Whether the message has been redelivered.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, isRedelivered)
{

	RETURN_MEMBER(getThis(), "redelivered");
}

/**
 * Sets the message body.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setBody)
{
	zval body_zv;
	zend_string *body = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("body", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(body)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&body_zv, body);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1270, &body_zv);
}

/**
 * Sets the correlation id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setCorrelationId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval correlationId_zv, _0;
	zend_string *correlationId = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&correlationId_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(correlationId)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&correlationId_zv);
	ZVAL_STR_COPY(&correlationId_zv, correlationId);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "correlation_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &correlationId_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a single transport header.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeader)
{
	zval name_zv, *value, value_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("headers"), &name_zv, value);
}

/**
 * Replaces all transport headers.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeaders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *headers_param = NULL;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("headers", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_arrval(&headers, headers_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1272, &headers);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the message id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setMessageId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval messageId_zv, _0;
	zend_string *messageId = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messageId_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(messageId)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&messageId_zv);
	ZVAL_STR_COPY(&messageId_zv, messageId);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "message_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &messageId_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Replaces all application properties.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *properties_param = NULL;
	zval properties;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&properties);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("properties", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(properties, properties_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &properties_param);
	zephir_get_arrval(&properties, properties_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1271, &properties);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a single application property.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperty)
{
	zval name_zv, *value, value_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("properties"), &name_zv, value);
}

/**
 * Marks the message as redelivered.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setRedelivered)
{
	zval *redelivered_param = NULL, __$true, __$false;
	zend_bool redelivered;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("redelivered", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(redelivered)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &redelivered_param);
	if (redelivered) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1273, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1273, &__$false);
	}
}

/**
 * Sets the reply-to destination name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setReplyTo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval replyTo_zv, _0;
	zend_string *replyTo = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&replyTo_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(replyTo)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&replyTo_zv);
	ZVAL_STR_COPY(&replyTo_zv, replyTo);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "reply_to");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &replyTo_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the timestamp (in milliseconds).
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setTimestamp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timestamp_param = NULL, _0, _1;
	zend_long timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &timestamp_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "timestamp");
	ZVAL_LONG(&_1, timestamp);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

