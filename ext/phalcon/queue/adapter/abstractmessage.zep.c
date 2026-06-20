
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
 */
/**
 * Shared implementation of every Message getter/setter, plus the
 * correlation-id / message-id / timestamp / reply-to header conveniences.
 * Concrete adapter messages extend this base.
 *
 * The convenience accessors are stored as transport headers under fixed keys
 * for binary compatibility with the wider interop ecosystem.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractMessage)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, AbstractMessage, phalcon, queue_adapter_abstractmessage, phalcon_queue_adapter_abstractmessage_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_abstractmessage_ce, SL("body"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_abstractmessage_ce, SL("headers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_abstractmessage_ce, SL("properties"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_queue_adapter_abstractmessage_ce, SL("redelivered"), 0, ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_abstractmessage_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_AbstractMessage;

	zend_class_implements(phalcon_queue_adapter_abstractmessage_ce, 1, phalcon_contracts_queue_message_ce);
	return SUCCESS;
}

/**
 * AbstractMessage constructor.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval properties, headers;
	zval body_zv, *properties_param = NULL, *headers_param = NULL;
	zend_string *body = NULL;
	zval *this_ptr = getThis();

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
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), &body_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("properties"), &properties);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &headers);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the message body.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getBody)
{

	RETURN_MEMBER_TYPED(getThis(), "body", IS_STRING);
}

/**
 * Returns the correlation id used to correlate request/reply messages.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getCorrelationId)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getHeader)
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/AbstractMessage.zep", 77);
		RETURN_CTORW(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Returns all transport headers.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getHeaders)
{

	RETURN_MEMBER_TYPED(getThis(), "headers", IS_ARRAY);
}

/**
 * Returns the message id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getMessageId)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getProperties)
{

	RETURN_MEMBER_TYPED(getThis(), "properties", IS_ARRAY);
}

/**
 * Returns a single property value, or the default when it is not set.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getProperty)
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("properties"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &name_zv)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("properties"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/AbstractMessage.zep", 113);
		RETURN_CTORW(&_2$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

/**
 * Returns the reply-to destination name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getReplyTo)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getTimestamp)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, isRedelivered)
{

	RETURN_MEMBER(getThis(), "redelivered");
}

/**
 * Sets the message body.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setBody)
{
	zval body_zv;
	zend_string *body = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(body)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&body_zv, body);
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), &body_zv);
}

/**
 * Sets the correlation id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setCorrelationId)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setHeader)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setHeaders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *headers_param = NULL;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &headers_param);
	zephir_get_arrval(&headers, headers_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &headers);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the message id.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setMessageId)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *properties_param = NULL;
	zval properties;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&properties);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(properties, properties_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &properties_param);
	zephir_get_arrval(&properties, properties_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("properties"), &properties);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a single application property.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setProperty)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setRedelivered)
{
	zval *redelivered_param = NULL, __$true, __$false;
	zend_bool redelivered;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(redelivered)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &redelivered_param);
	if (redelivered) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("redelivered"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("redelivered"), &__$false);
	}
}

/**
 * Sets the reply-to destination name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setReplyTo)
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
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setTimestamp)
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

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_AbstractMessage(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("properties"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("properties"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("headers"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

