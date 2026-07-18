
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
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Immutable payload produced by the domain layer.
 *
 * Every `with*()` method returns a new instance, leaving the receiver
 * unchanged. Named factories provide a concise way to create a payload for the
 * commonly used statuses.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Payload_Payload)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Payload, Payload, phalcon, adr_payload_payload, phalcon_adr_payload_payload_method_entry, 0);

	/**
	 * @var Throwable|null
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("exception"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("extras"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("input"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("result"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_adr_payload_payload_ce, SL("status"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_adr_payload_payload_ce, 1, phalcon_contracts_adr_payload_payload_ce);
	return SUCCESS;
}

/**
 * Creates a payload with the `ACCEPTED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, accepted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ACCEPTED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `CREATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, created)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "CREATED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `DELETED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, deleted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "DELETED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `ERROR` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages);
	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ERROR");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withmessages", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_AUTHORIZED` status (authenticated but
 * not allowed - HTTP 403).
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, forbidden)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages);
	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "NOT_AUTHORIZED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withmessages", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `FOUND` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, found)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "FOUND");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the exception thrown in the domain layer, if any.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getException)
{

	RETURN_MEMBER(getThis(), "exception");
}

/**
 * Gets the arbitrary extra domain information.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getExtras)
{

	RETURN_MEMBER(getThis(), "extras");
}

/**
 * Gets the domain input.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getInput)
{

	RETURN_MEMBER(getThis(), "input");
}

/**
 * Gets the domain messages.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getMessages)
{

	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Gets the domain result.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getResult)
{

	RETURN_MEMBER(getThis(), "result");
}

/**
 * Gets the payload status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, getStatus)
{

	RETURN_MEMBER(getThis(), "status");
}

/**
 * Creates a payload with the `NOT_VALID` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, invalid)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages);
	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "NOT_VALID");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withmessages", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_FOUND` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, notFound)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages);
	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "NOT_FOUND");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withmessages", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `PROCESSING` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, processing)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "PROCESSING");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `SUCCESS` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "SUCCESS");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_AUTHENTICATED` status (identity not
 * established - HTTP 401).
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, unauthenticated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages);
	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "NOT_AUTHENTICATED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withmessages", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `UPDATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, updated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null, _0, _1, _2;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &result);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_get_called_scope(execute_data));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UPDATED");
	ZEPHIR_CALL_METHOD(&_1, &_0, "withstatus", NULL, 310, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "withresult", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a copy of the payload with the given exception.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withException)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *exception, exception_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("exception", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, exception);
	RETURN_CCTOR(&cloned);
}

/**
 * Returns a copy of the payload with the given extras.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withExtras)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *extras, extras_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extras_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extras", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(extras)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &extras);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, extras);
	RETURN_CCTOR(&cloned);
}

/**
 * Returns a copy of the payload with the given input.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withInput)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input, input_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("input", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, input);
	RETURN_CCTOR(&cloned);
}

/**
 * Returns a copy of the payload with the given messages.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages, messages_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &messages);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, messages);
	RETURN_CCTOR(&cloned);
}

/**
 * Returns a copy of the payload with the given result.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withResult)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *result, result_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("result", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &result);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, result);
	RETURN_CCTOR(&cloned);
}

/**
 * Returns a copy of the payload with the given status.
 */
PHP_METHOD(Phalcon_ADR_Payload_Payload, withStatus)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *status, status_sub, cloned;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status_sub);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("status", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(status)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &status);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, status);
	RETURN_CCTOR(&cloned);
}

