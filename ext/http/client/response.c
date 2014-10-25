
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

#include "http/client/response.h"
#include "http/client/header.h"
#include "http/client/exception.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "kernel/string.h"

/**
 * Phalcon\Http\Client\Response
 */
zend_class_entry *phalcon_http_client_response_ce;

PHP_METHOD(Phalcon_Http_Client_Response, __construct);
PHP_METHOD(Phalcon_Http_Client_Response, setHeader);
PHP_METHOD(Phalcon_Http_Client_Response, getHeader);
PHP_METHOD(Phalcon_Http_Client_Response, setBody);
PHP_METHOD(Phalcon_Http_Client_Response, getBody);
PHP_METHOD(Phalcon_Http_Client_Response, setStatusCode);
PHP_METHOD(Phalcon_Http_Client_Response, getStatusCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, header)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_response_setheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_response_setbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, status_code)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_client_response_method_entry[] = {
	PHP_ME(Phalcon_Http_Client_Response, __construct, arginfo_phalcon_http_client_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Client_Response, setHeader, arginfo_phalcon_http_client_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Response, getHeader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Response, setBody, arginfo_phalcon_http_client_response_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Response, setStatusCode, arginfo_phalcon_http_client_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Http\Client\Request initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_Response){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Client, Response, http_client_response, phalcon_http_client_response_method_entry, 0);

	zend_declare_property_null(phalcon_http_client_response_ce, SL("_header"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_response_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Http_Client_Response, __construct){

	zval *header, *headers = NULL, *body = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &headers, &body);

	PHALCON_INIT_VAR(header);
	object_init_ex(header, phalcon_http_client_header_ce);
	PHALCON_CALL_METHOD(NULL, header, "__construct");

	phalcon_update_property_this(this_ptr, SL("_header"), header TSRMLS_CC);

	if (headers) {
		PHALCON_CALL_SELF(NULL, "setheader", headers);
	}

	if (body) {
		PHALCON_CALL_SELF(NULL, "setbody", body);
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Client_Response, setHeader){

	zval *headers, *header;

	phalcon_fetch_params(0, 1, 0, &headers);

	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_METHODW(NULL, header, "parse", headers);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_Http_Client_Response, getHeader){

	RETURN_MEMBER(this_ptr, "_header");
}

PHP_METHOD(Phalcon_Http_Client_Response, setBody){
	
	zval *body;

	phalcon_fetch_params(0, 1, 0, &body);

	phalcon_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_Http_Client_Response, getBody){

	RETURN_MEMBER(this_ptr, "_body");
}

PHP_METHOD(Phalcon_Http_Client_Response, setStatusCode){
	
	zval *status_code, *header;

	phalcon_fetch_params(0, 1, 0, &status_code);

	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHODW(NULL, header, "setstatuscode", status_code);

	RETURN_THISW();
}

PHP_METHOD(Phalcon_Http_Client_Response, getStatusCode){

	zval *header;
	
	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);

	PHALCON_RETURN_CALL_METHODW(header, "getstatuscode");
}

