
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

#include "http/client/adapter.h"
#include "http/client/adapterinterface.h"
#include "http/client/exception.h"
#include "http/uri.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"

/**
 * Phalcon\Http\Client\Adapter
 */
zend_class_entry *phalcon_http_client_adapter_ce; 

PHP_METHOD(Phalcon_Http_Client_Adapter, setUserAgent);
PHP_METHOD(Phalcon_Http_Client_Adapter, setAuth);
PHP_METHOD(Phalcon_Http_Client_Adapter, setHeader);
PHP_METHOD(Phalcon_Http_Client_Adapter, setHeaders);
PHP_METHOD(Phalcon_Http_Client_Adapter, setData);
PHP_METHOD(Phalcon_Http_Client_Adapter, setFile);
PHP_METHOD(Phalcon_Http_Client_Adapter, getPath);
PHP_METHOD(Phalcon_Http_Client_Adapter, get);
PHP_METHOD(Phalcon_Http_Client_Adapter, head);
PHP_METHOD(Phalcon_Http_Client_Adapter, post);
PHP_METHOD(Phalcon_Http_Client_Adapter, put);
PHP_METHOD(Phalcon_Http_Client_Adapter, delete);
PHP_METHOD(Phalcon_Http_Client_Adapter, setUri);
PHP_METHOD(Phalcon_Http_Client_Adapter, setBaseUri);
PHP_METHOD(Phalcon_Http_Client_Adapter, setMethod);
PHP_METHOD(Phalcon_Http_Client_Adapter, setTimeOut);
PHP_METHOD(Phalcon_Http_Client_Adapter, send);

static const zend_function_entry phalcon_http_client_adapter_method_entry[] = {
	PHP_ME(Phalcon_Http_Client_Adapter, setUserAgent, arginfo_phalcon_http_client_adapterinterface_setuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setAuth, arginfo_phalcon_http_client_adapterinterface_setauth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setHeader, arginfo_phalcon_http_client_adapterinterface_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setHeaders, arginfo_phalcon_http_client_adapterinterface_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setData, arginfo_phalcon_http_client_adapterinterface_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setFile, arginfo_phalcon_http_client_adapterinterface_setfile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, get, arginfo_phalcon_http_client_adapterinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, head, arginfo_phalcon_http_client_adapterinterface_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, post, arginfo_phalcon_http_client_adapterinterface_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, put, arginfo_phalcon_http_client_adapterinterface_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, delete, arginfo_phalcon_http_client_adapterinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setUri, arginfo_phalcon_http_client_adapterinterface_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setBaseUri, arginfo_phalcon_http_client_adapterinterface_setbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setMethod, arginfo_phalcon_http_client_adapterinterface_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, setTimeOut, arginfo_phalcon_http_client_adapterinterface_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter, send, NULL, ZEND_ACC_PUBLIC)

	ZEND_FENTRY(sendInternal, NULL, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)

	PHP_FE_END
};

/**
 * Phalcon\Http\Client\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Client, Adapter, http_client_adapter, phalcon_http_client_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_header"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_base_uri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_http_client_adapter_ce, SL("_method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_useragent"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_username"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_password"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_authtype"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_digest"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_entity_body"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_http_client_adapter_ce, SL("_timeout"), 30, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_stringl(phalcon_http_client_adapter_ce, SL("VERSION"), SL("0.0.1") TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_http_client_adapter_ce, SL("AUTH_TYPE_ANY"), SL("any") TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_http_client_adapter_ce, SL("AUTH_TYPE_BASIC"), SL("basic") TSRMLS_CC);
	zend_declare_class_constant_stringl(phalcon_http_client_adapter_ce, SL("AUTH_TYPE_DIGEST"), SL("digest") TSRMLS_CC);

	zend_class_implements(phalcon_http_client_adapter_ce TSRMLS_CC, 1, phalcon_http_client_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Sets the value of the userAgent property
 *
 * @param string $useragent
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setUserAgent){

	zval *useragent;

	phalcon_fetch_params(0, 1, 0, &useragent);

	phalcon_update_property_this(this_ptr, SL("_useragent"), useragent TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Set authentication credential
 *
 * @param string $username
 * @param string $password
 * @param string $authtype
 * @param array $digest
 * @param string $entityBody
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setAuth){

	zval *username, *password, *authtype = NULL, *digest = NULL, *entity_body = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 3, &username, &password, &authtype, &digest, &entity_body);

	phalcon_update_property_this(this_ptr, SL("_username"), username TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_password"), password TSRMLS_CC);

	if (!authtype) {
		PHALCON_INIT_NVAR(authtype);
		ZVAL_STRING(authtype, "any", 1);
	}

	phalcon_update_property_this(this_ptr, SL("_authtype"), authtype TSRMLS_CC);

	if (digest && Z_TYPE_P(digest) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_digest"), digest TSRMLS_CC);
	}

	if (entity_body) {
		phalcon_update_property_this(this_ptr, SL("_entity_body"), entity_body TSRMLS_CC);
	}

	RETURN_THIS();
}

/**
 * Set header
 *
 * @param string $name
 * @param string $value
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setHeader){

	zval *name, *value, *header;

	phalcon_fetch_params(0, 2, 0, &name, &value);

	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHODW(NULL, header, "set", name, value);

	RETURN_THISW();
}

/**
 * Set headers
 *
 * @param array $headers
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setHeaders){

	zval *headers, *header;

	phalcon_fetch_params(0, 1, 0, &headers);

	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHODW(NULL, header, "setMultiple", headers);

	RETURN_THISW();
}

/**
 * Set data
 *
 * @param array|string $data
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	if (Z_TYPE_P(data) != IS_NULL && Z_TYPE_P(data) != IS_STRING && Z_TYPE_P(data) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "data must be string or array");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Set send file
 *
 * @param string $file
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setFile){

	zval *file;

	phalcon_fetch_params(0, 1, 0, &file);

	phalcon_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Retrieve the URI path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, getPath){

	zval *base_uri;

	base_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_base_uri"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHODW(&return_value, base_uri, "getpath");
}

/**
 * Send GET request
 *
 * @param string $uri
 * @param string $data
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, get){

	zval *uri = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 2, &uri, &data);

	if (uri) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "seturi", uri);
	}

	if (data) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdata", data);
	}

	phalcon_update_property_string(this_ptr, SL("_method"), SL("GET") TSRMLS_CC);
	
	PHALCON_RETURN_CALL_METHODW(this_ptr, "send");
}

/**
 * Send HEAD request
 *
 * @param string $uri
 * @param string $data
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, head){

	zval *uri = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 2, &uri, &data);

	if (uri) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "seturi", uri);
	}

	if (data) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdata", data);
	}

	phalcon_update_property_string(this_ptr, SL("_method"), SL("HEAD") TSRMLS_CC);

	PHALCON_RETURN_CALL_METHODW(this_ptr, "send");
}

/**
 * Send POST request
 *
 * @param string $uri
 * @param string $data
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, post){

	zval *uri = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 2, &uri, &data);

	if (uri) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "seturi", uri);
	}

	if (data) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdata", data);
	}

	phalcon_update_property_string(this_ptr, SL("_method"), SL("POST") TSRMLS_CC);

	PHALCON_RETURN_CALL_METHODW(this_ptr, "send");
}

/**
 * Send PUT request
 *
 * @param string $uri
 * @param string $data
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, put){

	zval *uri = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 2, &uri, &data);

	if (uri) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "seturi", uri);
	}

	if (data) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdata", data);
	}

	phalcon_update_property_string(this_ptr, SL("_method"), SL("PUT") TSRMLS_CC);

	PHALCON_RETURN_CALL_METHODW(this_ptr, "send");
}

/**
 * Send DELETE request
 *
 * @param string $uri
 * @param string $data
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, delete){

	zval *uri = NULL, *data = NULL;

	phalcon_fetch_params(0, 0, 2, &uri, &data);

	if (uri) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "seturi", uri);
	}

	if (data) {
		PHALCON_CALL_METHODW(NULL, this_ptr, "setdata", data);
	}

	phalcon_update_property_string(this_ptr, SL("_method"), SL("DELETE") TSRMLS_CC);

	PHALCON_RETURN_CALL_METHODW(this_ptr, "send");
}

/**
 * Set URI
 *
 * @param string $uri
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setUri){

	zval *uri, *base_uri;

	phalcon_fetch_params(0, 1, 0, &uri);

	base_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_base_uri"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHODW(NULL, base_uri, "extend", uri);

	phalcon_update_property_this(this_ptr, SL("_base_uri"), base_uri TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Set base URI
 *
 * @param string $uri
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setBaseUri){

	zval *uri, *base_uri;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &uri);

	PHALCON_INIT_VAR(base_uri);
	object_init_ex(base_uri, phalcon_http_uri_ce);
	PHALCON_CALL_METHOD(NULL, base_uri, "__construct", uri);

	phalcon_update_property_this(this_ptr, SL("_base_uri"), base_uri TSRMLS_CC);

	RETURN_THIS();
}

/**
 * Set method
 *
 * @param string $uri
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setMethod){

	zval *method;

	phalcon_fetch_params(0, 1, 0, &method);

	phalcon_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Set the request timeout
 *
 * @param string $uri
 * @return Phalcon\Http\Client\Adapter
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, setTimeOut){

	zval *time;

	phalcon_fetch_params(0, 1, 0, &time);

	phalcon_update_property_this(this_ptr, SL("_timeout"), time TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Send request
 *
 * @return Phalcon\Http\Client\Response
 */
PHP_METHOD(Phalcon_Http_Client_Adapter, send){

	PHALCON_RETURN_CALL_METHODW(this_ptr, "sendinternal");
}

