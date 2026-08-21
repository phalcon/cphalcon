
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
#include "kernel/object.h"
#include "kernel/memory.h"
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
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Negotiates a formatter against the request `Accept` header and renders the
 * payload as the response body + content type.
 *
 * If no formatter accepts the header it falls back to the first (default)
 * formatter, so the content type and body are never left unset.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_FormatResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, FormatResponder, phalcon, adr_responder_formatresponder, phalcon_adr_responder_formatresponder_method_entry, 0);

	/**
	 * @var array
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_responder_formatresponder_ce, SL("formatters"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_adr_responder_formatresponder_ce, 1, phalcon_contracts_adr_responder_responder_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_FormatResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *formatters_param = NULL;
	zval formatters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatters);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("formatters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(formatters, formatters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &formatters_param);
	if (!formatters_param) {
		ZEPHIR_INIT_VAR(&formatters);
		array_init(&formatters);
	} else {
		zephir_get_arrval(&formatters, formatters_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 360, &formatters);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Responder_FormatResponder, __invoke)
{
	zend_bool _8;
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, *payload, payload_sub, accept, chosen, formatter, _0, _1, _2, _4, *_5, _7, _11, _12, _13, _6$$4, _9$$6, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&accept);
	ZVAL_UNDEF(&chosen);
	ZVAL_UNDEF(&formatter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("formatters", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(payload, phalcon_contracts_adr_payload_payload_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &payload);
	ZEPHIR_INIT_VAR(&chosen);
	ZVAL_NULL(&chosen);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETVAL_ZVAL(response, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Accept");
	ZEPHIR_CALL_METHOD(&_1, request, "getheader", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_cast_to_string(&_3, &_1);
	ZEPHIR_CPY_WRT(&accept, &_3);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/ADR/Responder/FormatResponder.zep", 60);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&formatter);
			ZVAL_COPY(&formatter, _5);
			ZEPHIR_CALL_METHOD(&_6$$4, &formatter, "accepts", NULL, 0, &accept);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$4)) {
				ZEPHIR_CPY_WRT(&chosen, &formatter);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&formatter, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$6, &formatter, "accepts", NULL, 0, &accept);
				zephir_check_call_status();
				if (zephir_is_true(&_9$$6)) {
					ZEPHIR_CPY_WRT(&chosen, &formatter);
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&formatter);
	if (Z_TYPE_P(&chosen) == IS_NULL) {
		zephir_read_property_cached(&_10$$8, this_ptr, _zephir_prop_0, 360, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&chosen);
		zephir_array_fetch_long(&chosen, &_10$$8, 0, PH_NOISY, "phalcon/ADR/Responder/FormatResponder.zep", 61);
	}
	ZEPHIR_CALL_METHOD(&_12, &chosen, "contenttype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, response, "setcontenttype", NULL, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &chosen, "format", NULL, 0, payload);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_11, "setcontent", NULL, 0, &_13);
	zephir_check_call_status();
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();
}

