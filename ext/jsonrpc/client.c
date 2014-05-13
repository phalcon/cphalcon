
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "jsonrpc/client.h"
#include "jsonrpc/client/exception.h"
#include "jsonrpc/client/response.h"
#include "http/client/adapterinterface.h"
#include "http/client/response.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/hash.h"

/**
 * Phalcon\JsonRpc\Client
 *
 *<code>
 *	$httpclient = new Phalcon\Http\Client\Adapter\Stream('http://rpc.edu.local');
 *	$rpc = new Phalcon\JsonRpc\Client($httpclient);
 *	$rpc->call('auth/sigup', array('username' => 'phalcon', 'password' => 'Hello:)'));
 *</code>
 *
 */
zend_class_entry *phalcon_jsonrpc_client_ce;

PHP_METHOD(Phalcon_JsonRpc_Client, __construct);
PHP_METHOD(Phalcon_JsonRpc_Client, call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, httpclient)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_jsonrpc_client_method_entry[] = {
	PHP_ME(Phalcon_JsonRpc_Client, __construct, arginfo_phalcon_jsonrpc_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_JsonRpc_Client, call, arginfo_phalcon_jsonrpc_client_call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\JsonRpc\Client initializer
 */
PHALCON_INIT_CLASS(Phalcon_JsonRpc_Client){

	PHALCON_REGISTER_CLASS(Phalcon\\JsonRpc, Client, jsonrpc_client, phalcon_jsonrpc_client_method_entry, 0);

	zend_declare_property_null(phalcon_jsonrpc_client_ce, SL("_httpclient"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_jsonrpc_client_ce, SL("_id"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_JsonRpc_Client, __construct){

	zval *httpclient;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &httpclient);

	PHALCON_VERIFY_INTERFACE_EX(httpclient, phalcon_http_client_adapterinterface_ce, phalcon_jsonrpc_client_exception_ce, 1);

	phalcon_update_property_this(this_ptr, SL("_httpclient"), httpclient TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Rpc call
 *
 * @param string $method
 * @param string $data
 * @return Phalcon\JsonRpc\Response
 */
PHP_METHOD(Phalcon_JsonRpc_Client, call){

	zval *method = NULL, *data = NULL, *httpclient, *id, *jsonrpc_message, *json_message = NULL, *response = NULL;
	zval *code = NULL, *body = NULL, *json = NULL, *jsonrpc_response, *result, *error;
	int i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &method, &data);

	httpclient = phalcon_fetch_nproperty_this(this_ptr, SL("_httpclient"), PH_NOISY TSRMLS_CC);
	id = phalcon_fetch_nproperty_this(this_ptr, SL("_id"), PH_NOISY TSRMLS_CC);
	i = Z_LVAL_P(id) + 1;
	ZVAL_LONG(id, i);

	phalcon_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);

	PHALCON_INIT_VAR(jsonrpc_message);
	array_init(jsonrpc_message);

	phalcon_array_update_string_string(&jsonrpc_message, SL("jsonrpc"), SL("2.0"), 0);
	phalcon_array_update_string(&jsonrpc_message, SL("method"), method, PH_COPY);
	
	if (data) {
		phalcon_array_update_string(&jsonrpc_message, SL("params"), data, PH_COPY);
	}
	
	phalcon_array_update_string(&jsonrpc_message, SL("id"), id, PH_COPY);

	PHALCON_CALL_FUNCTION(&json_message, "json_encode", jsonrpc_message);

	PHALCON_CALL_METHOD(NULL, httpclient, "setdata", json_message);
	PHALCON_CALL_METHOD(&response, httpclient, "post");

	PHALCON_VERIFY_CLASS_EX(response, phalcon_http_client_response_ce, phalcon_jsonrpc_client_exception_ce, 1);

	PHALCON_CALL_METHOD(&code, response, "getstatuscode");
	PHALCON_CALL_METHOD(&body, response, "getbody");

	PHALCON_INIT_VAR(jsonrpc_response);
	object_init_ex(jsonrpc_response, phalcon_jsonrpc_client_response_ce);
	PHALCON_CALL_METHOD(NULL, jsonrpc_response, "__construct", body);

	PHALCON_CALL_METHOD(NULL, jsonrpc_response, "setcode", code);

	if (PHALCON_IS_NOT_EMPTY(body)) {
		PHALCON_CALL_FUNCTION(&json, "json_decode", body, PHALCON_GLOBAL(z_true));

		if (Z_TYPE_P(json) == IS_ARRAY) {
			if (phalcon_array_isset_string(json, SS("id"))) {
				PHALCON_OBS_VAR(id);
				phalcon_array_fetch_string(&id, json, SL("id"), PH_NOISY);

				PHALCON_CALL_METHOD(NULL, jsonrpc_response, "setid", id);
			}

			if (phalcon_array_isset_string(json, SS("result"))) {
				PHALCON_OBS_VAR(result);
				phalcon_array_fetch_string(&result, json, SL("result"), PH_NOISY);

				PHALCON_CALL_METHOD(NULL, jsonrpc_response, "setresult", result);
			}

			if (phalcon_array_isset_string(json, SS("error"))) {
				PHALCON_OBS_VAR(error);
				phalcon_array_fetch_string(&error, json, SL("error"), PH_NOISY);

				PHALCON_CALL_METHOD(NULL, jsonrpc_response, "seterror", error);
			}
		}
	}

	RETURN_CTOR(jsonrpc_response);
}

