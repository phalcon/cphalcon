
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
  +------------------------------------------------------------------------+
*/

#include "http/client.h"
#include "http/client/adapter/curl.h"
#include "http/client/adapter/stream.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"

/**
 * Phalcon\Http\Client
 *
 * Creates a new request object for the given URI.
 *
 *<code>
 *	$client = Phalcon\Http\Client::factory();
 *</code>
 *
 */
zend_class_entry *phalcon_http_client_ce;

PHP_METHOD(Phalcon_Http_Client, factory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_factory, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_client_method_entry[] = {
	PHP_ME(Phalcon_Http_Client, factory, arginfo_phalcon_http_client_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Http\Client initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Client, http_client, phalcon_http_client_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Http_Client, factory){
	zval *uri = NULL, *method = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &uri, &method);

	if (!uri) {
		uri = PHALCON_GLOBAL(z_null);
	}

	if (!method) {
		PHALCON_INIT_NVAR(method);
		ZVAL_STRING(method, "GET", 1);
	}

	if (phalcon_function_exists_ex(SS("curl_init") TSRMLS_CC) != FAILURE) {
		object_init_ex(return_value, phalcon_http_client_adapter_curl_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", uri, method);
	} else {
		object_init_ex(return_value, phalcon_http_client_adapter_stream_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", uri, method);
	}

	PHALCON_MM_RESTORE();
}