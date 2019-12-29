
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
#include "kernel/operators.h"
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
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * PSR-7 Request
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Message, Request, phalcon, http_message_request, phalcon_http_message_abstractrequest_ce, phalcon_http_message_request_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(phalcon_http_message_request_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestinterface")));
	return SUCCESS;

}

/**
 * Request constructor.
 *
 * @param string                          $method
 * @param UriInterface|string|null        $uri
 * @param StreamInterface|resource|string $body
 * @param array                           $headers
 */
PHP_METHOD(Phalcon_Http_Message_Request, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri = NULL, uri_sub, *body = NULL, body_sub, *headers = NULL, headers_sub, __$null, _0, _1, _2, _3, _4, _5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &method_param, &uri, &body, &headers);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "GET");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://memory");
	} else {
		ZEPHIR_SEPARATE_PARAM(body);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://input");
	if (UNEXPECTED(ZEPHIR_IS_IDENTICAL(&_0, body))) {
		ZEPHIR_INIT_NVAR(body);
		object_init_ex(body, phalcon_http_message_stream_input_ce);
		ZEPHIR_CALL_METHOD(NULL, body, "__construct", NULL, 281);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "processuri", NULL, 282, uri);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("uri"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "processheaders", NULL, 283, headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "processmethod", NULL, 101, &method);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("method"), &_3);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "w+b");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "processbody", NULL, 36, body, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("body"), &_4);
	ZEPHIR_MM_RESTORE();

}

