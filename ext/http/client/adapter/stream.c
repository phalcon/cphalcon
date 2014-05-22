
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

#include "http/client/adapter/stream.h"
#include "http/client/adapter.h"
#include "http/client/adapterinterface.h"
#include "http/client/header.h"
#include "http/client/response.h"
#include "http/client/exception.h"
#include "http/uri.h"

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
 * Phalcon\Http\Client\Adapter\Stream
 */
zend_class_entry *phalcon_http_client_adapter_stream_ce;

PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, buildBody);
PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, errorHandler);
PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, sendInternal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapter_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapter_stream_errorhandler, 0, 0, 5)
	ZEND_ARG_INFO(0, errno)
	ZEND_ARG_INFO(0, errstr)
	ZEND_ARG_INFO(0, errfile)
	ZEND_ARG_INFO(0, errline)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_client_adapter_stream_method_entry[] = {
	PHP_ME(Phalcon_Http_Client_Adapter_Stream, __construct, arginfo_phalcon_http_client_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Client_Adapter_Stream, buildBody, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Client_Adapter_Stream, errorHandler, arginfo_phalcon_http_client_adapter_stream_errorhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Client_Adapter_Stream, sendInternal, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

/**
 * Phalcon\Http\Client\Adapter\Stream initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_Adapter_Stream){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Http\\Client\\Adapter, Stream, http_client_adapter_stream, phalcon_http_client_adapter_ce,  phalcon_http_client_adapter_stream_method_entry, 0);

	zend_declare_property_null(phalcon_http_client_adapter_stream_ce, SL("_stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_client_adapter_stream_ce TSRMLS_CC, 1, phalcon_http_client_adapterinterface_ce);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, __construct){

	zval *uri = NULL, *method = NULL, *upper_method, *header, *stream = NULL, *http, *option, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &uri, &method);

	PHALCON_CALL_SELF(NULL, "setbaseuri", uri);

	if (method) {
		PHALCON_INIT_VAR(upper_method);
		phalcon_fast_strtoupper(upper_method, method);
		phalcon_update_property_this(this_ptr, SL("_method"), upper_method TSRMLS_CC);
	}

	PHALCON_INIT_VAR(header);
	object_init_ex(header, phalcon_http_client_header_ce);
	PHALCON_CALL_METHOD(NULL, header, "__construct");

	PHALCON_CALL_FUNCTION(&stream, "stream_context_create");

	PHALCON_INIT_VAR(http);
	ZVAL_STRING(http, "http", 1);

	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "user_agent", 1);

	PHALCON_INIT_VAR(value);
	ZVAL_STRING(value, "Phalcon HTTP Client(Stream)", 1);

	PHALCON_CALL_METHOD(NULL, header, "set", option, value);

	phalcon_update_property_this(this_ptr, SL("_header"), header TSRMLS_CC);

	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "follow_location", 1);

	PHALCON_INIT_NVAR(value);
	ZVAL_LONG(value, 1);

	PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, value);

	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "max_redirects", 1);

	PHALCON_INIT_NVAR(value);
	ZVAL_LONG(value, 20);

	PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, value);

	phalcon_update_property_this(this_ptr, SL("_stream"), stream TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, buildBody){

	zval *stream, *header, *data, *file, *username, *password, *authtype, *digest, *method, *entity_body;
	zval *key = NULL, *value = NULL, *realm, *qop, *nonce, *nc, *cnonce, *qoc, *ha1 = NULL, *path = NULL, *md5_entity_body = NULL, *ha2 = NULL;
	zval *http, *option = NULL, *body, *headers = NULL, *uniqid = NULL, *boundary;
	zval *path_parts = NULL, *filename, *basename, *filedata = NULL, *tmp = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	stream = phalcon_fetch_nproperty_this(this_ptr, SL("_stream"), PH_NOISY TSRMLS_CC);
	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	file = phalcon_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY TSRMLS_CC);
	username = phalcon_fetch_nproperty_this(this_ptr, SL("_username"), PH_NOISY TSRMLS_CC);
	password = phalcon_fetch_nproperty_this(this_ptr, SL("_password"), PH_NOISY TSRMLS_CC);
	authtype = phalcon_fetch_nproperty_this(this_ptr, SL("_authtype"), PH_NOISY TSRMLS_CC);
	digest = phalcon_fetch_nproperty_this(this_ptr, SL("_digest"), PH_NOISY TSRMLS_CC);
	method = phalcon_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY TSRMLS_CC);
	entity_body = phalcon_fetch_nproperty_this(this_ptr, SL("_entity_body"), PH_NOISY TSRMLS_CC);

	if (PHALCON_IS_NOT_EMPTY(username)) {
		if (PHALCON_IS_STRING(authtype, "basic")) {
			PHALCON_INIT_NVAR(key);
			ZVAL_STRING(key, "Authorization", 1);

			PHALCON_INIT_NVAR(value);
			PHALCON_CONCAT_SVSV(value, "Basic ", username, ":", password);

			PHALCON_CALL_METHOD(NULL, header, "set", key, value);
		} else if (PHALCON_IS_STRING(authtype, "digest") && PHALCON_IS_NOT_EMPTY(digest)) {
			if (phalcon_array_isset_string_fetch(&realm, digest, SS("realm"))) {
				PHALCON_INIT_VAR(realm);
				ZVAL_NULL(realm);
			}

			PHALCON_INIT_NVAR(tmp);
			PHALCON_CONCAT_VSVSV(tmp, username, ":", realm, ":", password);

			PHALCON_CALL_FUNCTION(&ha1, "md5", tmp);

			if (!phalcon_array_isset_string_fetch(&qop, digest, SS("qop"))) {
				PHALCON_INIT_VAR(qop);
				ZVAL_NULL(qop);
			}

			if (PHALCON_IS_EMPTY(qop) || phalcon_memnstr_str(qop, SL("auth"))) {
				PHALCON_CALL_SELF(&path, "getpath");

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_VSV(tmp, method, ":", path);

				PHALCON_CALL_FUNCTION(&ha2, "md5", tmp);
				
			} else if (phalcon_memnstr_str(qop, SL("auth-int"))) {
				PHALCON_CALL_SELF(&path, "getpath");

				PHALCON_CALL_FUNCTION(&md5_entity_body, "md5", entity_body);

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_VSVSV(tmp, method, ":", path, ":", md5_entity_body);

				PHALCON_CALL_FUNCTION(&ha2, "md5", tmp);
			}

			PHALCON_INIT_NVAR(key);
			ZVAL_STRING(key, "Authorization", 1);

			if (phalcon_array_isset_string_fetch(&nonce, digest, SS("nonce"))) {
				PHALCON_INIT_VAR(nonce);
				ZVAL_NULL(nonce);
			}


			if (PHALCON_IS_EMPTY(qop)) {
				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_VSVSV(tmp, ha1, ":", nonce, ":", ha2);

				PHALCON_CALL_FUNCTION(&value, "md5", tmp);

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_SV(tmp, "Digest ", value);

				PHALCON_CALL_METHOD(NULL, header, "set", key, tmp);
			} else {			
				if (phalcon_array_isset_string_fetch(&nc, digest, SS("nc"))) {
					PHALCON_INIT_VAR(nc);
					ZVAL_NULL(nc);
				}
				
				if (phalcon_array_isset_string_fetch(&cnonce, digest, SS("cnonce"))) {
					PHALCON_INIT_VAR(cnonce);
					ZVAL_NULL(cnonce);
				}
				
				if (phalcon_array_isset_string_fetch(&qoc, digest, SS("qoc"))) {
					PHALCON_INIT_VAR(qoc);
					ZVAL_NULL(qoc);
				}
				
				if (phalcon_array_isset_string_fetch(&qoc, digest, SS("qoc"))) {
					PHALCON_INIT_VAR(qoc);
					ZVAL_NULL(qoc);
				}

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_VSVSVS(tmp, ha1, ":", nonce, ":", nc, ":");

				PHALCON_SCONCAT_VSVSV(tmp, cnonce, ":", qoc, ":", ha2);

				PHALCON_CALL_FUNCTION(&value, "md5", tmp);

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_SV(tmp, "Digest ", value);

				PHALCON_CALL_METHOD(NULL, header, "set", key, tmp);
			}
		}
	}

	PHALCON_INIT_VAR(http);
	ZVAL_STRING(http, "http", 1);

	PHALCON_CALL_FUNCTION(&uniqid, "uniqid");

	PHALCON_INIT_VAR(boundary);
	PHALCON_CONCAT_SV(boundary, "--------------", uniqid);

	PHALCON_INIT_VAR(body);

	if (PHALCON_IS_NOT_EMPTY(data) && Z_TYPE_P(data) == IS_STRING){
		PHALCON_INIT_NVAR(key);
		ZVAL_STRING(key, "Content-Type", 1);

		PHALCON_INIT_NVAR(value);
		ZVAL_STRING(value, "application/x-www-form-urlencoded", 1);

		PHALCON_CALL_METHOD(NULL, header, "set", key, value);

		PHALCON_INIT_NVAR(option);
		ZVAL_LONG(option, PHALCON_HTTP_CLIENT_HEADER_BUILD_FIELDS);
		
		PHALCON_CALL_METHOD(&headers, header, "build", option);

		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "header", 1);

		PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, headers);

		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "content", 1);

		PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, data);
		RETURN_MM();
	}
	
	if (Z_TYPE_P(data) == IS_ARRAY) {
		phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			PHALCON_SCONCAT_SVS(body, "--", boundary, "\r\n");
			PHALCON_SCONCAT_SVSVS(body, "Content-Disposition: form-data; name=\"", key, "\"\r\n\r\n", value, "\r\n");

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	if (PHALCON_IS_NOT_EMPTY(file)) {
		PHALCON_CALL_FUNCTION(&path_parts, "pathinfo", file);

		if (phalcon_array_isset_string_fetch(&filename, path_parts, SS("filename")) && phalcon_array_isset_string_fetch(&basename, path_parts, SS("basename"))) {
			PHALCON_CALL_FUNCTION(&filedata, "file_get_contents", file);

			PHALCON_SCONCAT_SVS(body, "--", boundary, "\r\n");
			PHALCON_SCONCAT_SVSVS(body, "Content-Disposition: form-data; name=\"", filename, "\"; filename=\"", basename, "\"\r\n");
			PHALCON_SCONCAT_SVS(body, "Content-Type: application/octet-stream\r\n\r\n", filedata, "\r\n");
		}
	}

	if (!PHALCON_IS_EMPTY(body)) {
		PHALCON_SCONCAT_SVS(body, "--", boundary, "--\r\n");

		PHALCON_INIT_NVAR(key);
		ZVAL_STRING(key, "Content-Type", 1);

		PHALCON_INIT_NVAR(value);
		PHALCON_CONCAT_SV(value, "multipart/form-data; boundary=", boundary);

		PHALCON_CALL_METHOD(NULL, header, "set", key, value);

		PHALCON_INIT_NVAR(key);
		ZVAL_STRING(key, "Content-Length", 1);		

		PHALCON_INIT_NVAR(value);
		ZVAL_LONG(value, Z_STRLEN_P(body));

		PHALCON_CALL_METHOD(NULL, header, "set", key, value);

		PHALCON_INIT_NVAR(option);
		ZVAL_LONG(option, PHALCON_HTTP_CLIENT_HEADER_BUILD_FIELDS);
		
		PHALCON_CALL_METHOD(&headers, header, "build", option);

		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "header", 1);

		PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, headers);

		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "content", 1);
		
		PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, body);
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, errorHandler){

	zval *no, *message, *file, *line, *data;

	phalcon_fetch_params(0, 5, 0, &no, &message, &file, &line, &data);

	PHALCON_THROW_EXCEPTION_ZVALW(phalcon_http_client_exception_ce, message);
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Stream, sendInternal){

	zval *stream, *http, *option = NULL, *header, *handler, *base_uri, *url = NULL, *method, *useragent, *timeout;
	zval *fp = NULL, *meta = NULL, *wrapper_data, *bodystr = NULL, *response;

	PHALCON_MM_GROW();

	stream = phalcon_fetch_nproperty_this(this_ptr, SL("_stream"), PH_NOISY TSRMLS_CC);
	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);
	method = phalcon_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY TSRMLS_CC);
	base_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_base_uri"), PH_NOISY TSRMLS_CC);
	useragent = phalcon_fetch_nproperty_this(this_ptr, SL("_useragent"), PH_NOISY TSRMLS_CC);
	timeout = phalcon_fetch_nproperty_this(this_ptr, SL("_timeout"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(http);
	ZVAL_STRING(http, "http", 1);
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "method", 1);

	PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, method);

	if (PHALCON_IS_NOT_EMPTY(useragent)) {
		PHALCON_INIT_NVAR(option);
		ZVAL_STRING(option, "User-Agent", 1);

		PHALCON_CALL_METHOD(NULL, header, "set", option, useragent);
	}

	PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, useragent);
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "timeout", 1);

	PHALCON_CALL_FUNCTION(NULL, "stream_context_set_option", stream, http, option, timeout);

	PHALCON_CALL_METHOD(&url, base_uri, "build");

	PHALCON_CALL_SELF(NULL, "buildBody");

	PHALCON_INIT_VAR(handler);
	array_init_size(handler, 2);
	phalcon_array_append(&handler, this_ptr, PH_SEPARATE);
	add_next_index_stringl(handler, SL("errorHandler"), 1);

	PHALCON_CALL_FUNCTION(NULL, "set_error_handler", handler);

	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "r", 1);

	PHALCON_CALL_FUNCTION(&fp, "fopen", url, option, PHALCON_GLOBAL(z_false), stream);

	PHALCON_CALL_FUNCTION(NULL, "restore_error_handler");

	PHALCON_CALL_FUNCTION(&meta, "stream_get_meta_data", fp);
	PHALCON_CALL_FUNCTION(&bodystr, "stream_get_contents", fp);
	PHALCON_CALL_FUNCTION(NULL, "fclose", fp);

	PHALCON_INIT_VAR(response);
	object_init_ex(response, phalcon_http_client_response_ce);
	PHALCON_CALL_METHOD(NULL, response, "__construct");

	if (phalcon_array_isset_string_fetch(&wrapper_data, meta, SS("wrapper_data"))) {
		PHALCON_CALL_METHOD(NULL, response, "setHeader", wrapper_data);
	}

	PHALCON_CALL_METHOD(NULL, response, "setbody", bodystr);

	RETURN_CTOR(response);
}

