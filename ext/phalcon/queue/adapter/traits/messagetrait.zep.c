
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
 *
 * @phpstan-import-type queue_message_headers from QueueTypes
 * @phpstan-import-type queue_message_properties from QueueTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Traits_MessageTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Queue\\Adapter\\Traits, MessageTrait, phalcon, queue_adapter_traits_messagetrait, phalcon_queue_adapter_traits_messagetrait_method_entry);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_messagetrait_ce, SL("body"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * @phpstan-var queue_message_headers
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_messagetrait_ce, SL("headers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var queue_message_properties
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_messagetrait_ce, SL("properties"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_messagetrait_ce, SL("redelivered"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Message constructor.
 *
 * @phpstan-param queue_message_properties $properties
 * @phpstan-param queue_message_headers    $headers
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1290, &body_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1291, &properties);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1292, &headers);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheaderasstring", NULL, 0, &_0);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1292, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1292, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Traits/MessageTrait.zep", 83);
		RETURN_CTORW(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Returns all transport headers.
 *
 * @phpstan-return queue_message_headers
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaders)
{

	RETURN_MEMBER_TYPED(getThis(), "headers", IS_ARRAY);
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
 *
 * @phpstan-return queue_message_properties
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperties)
{

	RETURN_MEMBER_TYPED(getThis(), "properties", IS_ARRAY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1291, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1291, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Traits/MessageTrait.zep", 123);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheaderasstring", NULL, 0, &_0);
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
	if (!(zephir_is_scalar(&value))) {
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1290, &body_zv);
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
 *
 * @phpstan-param queue_message_headers $headers
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1292, &headers);
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
 *
 * @phpstan-param queue_message_properties $properties
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1291, &properties);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1293, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1293, &__$false);
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

/**
 * Reads a header that is declared as a nullable string. Headers arrive
 * from the transport as arbitrary values, so anything that cannot be
 * expressed as a string (an array, an object) reads back as null.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaderAsString)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, value;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "getheader", NULL, 0, &name_zv);
	zephir_check_call_status();
	if (!(zephir_is_scalar(&value))) {
		RETURN_MM_NULL();
	}
	zephir_cast_to_string(&_0, &value);
	RETURN_CTOR(&_0);
}

