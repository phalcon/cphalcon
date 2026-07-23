
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
 * Thin, injectable factory mirroring the `Payload` named factories.
 *
 * It exists so that payload creation can be registered as a service in the DI
 * container and substituted in tests, rather than calling the static factories
 * directly.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Payload_PayloadFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Payload, PayloadFactory, phalcon, adr_payload_payloadfactory, phalcon_adr_payload_payloadfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * Creates a payload with the `ACCEPTED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, accepted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "accepted", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `AUTHENTICATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, authenticated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "authenticated", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `AUTHORIZED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, authorized)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "authorized", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `CREATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, created)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "created", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `DELETED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, deleted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "deleted", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `ERROR` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "error", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_AUTHORIZED` status (HTTP 403).
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, forbidden)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "forbidden", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `FOUND` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, found)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "found", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_VALID` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, invalid)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "invalid", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_ACCEPTED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notAccepted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "notaccepted", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_CREATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notCreated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "notcreated", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_DELETED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notDeleted)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "notdeleted", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_FOUND` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notFound)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "notfound", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_UPDATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, notUpdated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "notupdated", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `PROCESSING` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, processing)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "processing", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `SUCCESS` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "success", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `NOT_AUTHENTICATED` status (HTTP 401).
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, unauthenticated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages = NULL, messages_sub, __$null;

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "unauthenticated", NULL, 0, messages);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `UPDATED` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, updated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "updated", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a payload with the `VALID` status.
 */
PHP_METHOD(Phalcon_ADR_Payload_PayloadFactory, valid)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, result_sub, __$null;

	ZVAL_UNDEF(&result_sub);
	ZVAL_NULL(&__$null);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_adr_payload_payload_ce, "valid", NULL, 0, result);
	zephir_check_call_status();
	RETURN_MM();
}

