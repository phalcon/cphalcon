
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

#include "jsonrpc/client/response.h"

#include "kernel/main.h"
#include "kernel/object.h"

/**
 * Phalcon\JsonRpc\Client\Response
 */
zend_class_entry *phalcon_jsonrpc_client_response_ce;

PHP_METHOD(Phalcon_JsonRpc_Client_Response, __construct);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, setId);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, getId);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, setResult);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, getResult);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, setError);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, getError);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, setCode);
PHP_METHOD(Phalcon_JsonRpc_Client_Response, getCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_response_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_response_setresult, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_response_seterror, 0, 0, 1)
	ZEND_ARG_INFO(0, error)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_jsonrpc_client_response_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_jsonrpc_client_response_method_entry[] = {
	PHP_ME(Phalcon_JsonRpc_Client_Response, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_JsonRpc_Client_Response, setId, arginfo_phalcon_jsonrpc_client_response_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, setResult, arginfo_phalcon_jsonrpc_client_response_setresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, getResult, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, setError, arginfo_phalcon_jsonrpc_client_response_seterror, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, setCode, arginfo_phalcon_jsonrpc_client_response_setcode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_JsonRpc_Client_Response, getCode, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\JsonRpc\Client\Response initializer
 */
PHALCON_INIT_CLASS(Phalcon_JsonRpc_Client_Response){

	PHALCON_REGISTER_CLASS(Phalcon\\JsonRPc\\Client, Response, jsonrpc_client_response, phalcon_jsonrpc_client_response_method_entry, 0);

	zend_declare_property_null(phalcon_jsonrpc_client_response_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_jsonrpc_client_response_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_jsonrpc_client_response_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_jsonrpc_client_response_ce, SL("_error"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_jsonrpc_client_response_ce, SL("_code"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, __construct){

	zval *body = NULL;

	phalcon_fetch_params(0, 0, 1, &body);

	if (body) {
		phalcon_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);
	}
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, setId){

	zval *id;

	phalcon_fetch_params(0, 1, 0, &id);

	phalcon_update_property_this(this_ptr, SL("_id"), id TSRMLS_CC);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, getId){

	RETURN_MEMBER(this_ptr, "_id");
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, setResult){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, getResult){

	RETURN_MEMBER(this_ptr, "_data");
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, setError){

	zval *error;

	phalcon_fetch_params(0, 1, 0, &error);

	phalcon_update_property_this(this_ptr, SL("_error"), error TSRMLS_CC);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, getError){

	RETURN_MEMBER(this_ptr, "_error");
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, setCode){

	zval *code;

	phalcon_fetch_params(0, 1, 0, &code);

	phalcon_update_property_this(this_ptr, SL("_code"), code TSRMLS_CC);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_JsonRpc_Client_Response, getCode){

	RETURN_MEMBER(this_ptr, "_code");
}

