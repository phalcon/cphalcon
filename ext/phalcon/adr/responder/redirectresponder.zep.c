
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"


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
 * Applies a `Redirect` value object carried on the payload result: sets the
 * status code and the `Location` header. A no-op when the result is not a
 * redirect.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_RedirectResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, RedirectResponder, phalcon, adr_responder_redirectresponder, phalcon_adr_responder_redirectresponder_method_entry, 0);

	zend_class_implements(phalcon_adr_responder_redirectresponder_ce, 1, phalcon_contracts_adr_responder_responder_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_RedirectResponder, __invoke)
{
	zend_bool _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, *payload, payload_sub, result, url, _1$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(payload, phalcon_contracts_adr_payload_payload_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &payload);
	ZEPHIR_CALL_METHOD(&result, payload, "getresult", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&result) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(&result, phalcon_adr_responder_redirect_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&url, &result, "url", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, &result, "external", NULL, 0);
		zephir_check_call_status();
		_2$$3 = !zephir_is_true(&_1$$3);
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "~^(?:[a-z][a-z0-9+.\\-]*:|//)~i");
			ZEPHIR_INIT_VAR(&_5$$3);
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "~^(?:[a-z][a-z0-9+.\\-]*:|//)~i");
			zephir_preg_match(&_5$$3, &_6$$3, &url, &_3$$3, 0, 0 , 0 );
			_2$$3 = zephir_is_true(&_5$$3);
		}
		if (_2$$3) {
			ZEPHIR_INIT_NVAR(&url);
			ZVAL_STRING(&url, "/");
		}
		ZEPHIR_CALL_METHOD(&_8$$3, &result, "status", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, response, "setstatuscode", NULL, 0, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "Location");
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "setheader", NULL, 0, &_9$$3, &url);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();
}

