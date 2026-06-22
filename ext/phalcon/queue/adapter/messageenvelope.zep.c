
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


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
 * Encodes and decodes the {body, properties, headers} envelope shared by every
 * transport that persists a message as a serialized string (Stream, Redis,
 * Beanstalk). Centralizes the wire shape, the object-injection-safe
 * `allowed_classes => false` guard, and the missing-key defaults, so each
 * adapter only supplies its own concrete message factory around `decode()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_MessageEnvelope)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, MessageEnvelope, phalcon, queue_adapter_messageenvelope, phalcon_queue_adapter_messageenvelope_method_entry, 0);

	return SUCCESS;
}

/**
 * Decodes a serialized payload into a normalized {body, properties,
 * headers} array, or null when the payload is not a valid envelope.
 */
PHP_METHOD(Phalcon_Queue_Adapter_MessageEnvelope, decode)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval payload_zv, __$false, data, body, properties, headers;
	zend_string *payload = NULL;

	ZVAL_UNDEF(&payload_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(payload)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("allowed_classes"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 28, &payload_zv, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	ZEPHIR_INIT_VAR(&properties);
	array_init(&properties);
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	if (zephir_array_isset_value_string(&data, SL("body"))) {
		ZEPHIR_OBS_NVAR(&body);
		zephir_array_fetch_string(&body, &data, SL("body"), PH_NOISY, "phalcon/Queue/Adapter/MessageEnvelope.zep", 52);
	}
	if (zephir_array_isset_value_string(&data, SL("properties"))) {
		ZEPHIR_OBS_NVAR(&properties);
		zephir_array_fetch_string(&properties, &data, SL("properties"), PH_NOISY, "phalcon/Queue/Adapter/MessageEnvelope.zep", 56);
	}
	if (zephir_array_isset_value_string(&data, SL("headers"))) {
		ZEPHIR_OBS_NVAR(&headers);
		zephir_array_fetch_string(&headers, &data, SL("headers"), PH_NOISY, "phalcon/Queue/Adapter/MessageEnvelope.zep", 60);
	}
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("body"), &body, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("properties"), &properties, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("headers"), &headers, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Serializes a message into its wire envelope.
 */
PHP_METHOD(Phalcon_Queue_Adapter_MessageEnvelope, encode)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _1;

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
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
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 23, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

