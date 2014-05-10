
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

#include "http/client/adapter/curl.h"
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
 * Phalcon\Http\Client\Adapter\Curl
 */
zend_class_entry *phalcon_http_client_adapter_curl_ce;

PHP_METHOD(Phalcon_Http_Client_Adapter_Curl, __construct);
PHP_METHOD(Phalcon_Http_Client_Adapter_Curl, sendInternal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_client_adapter_curl___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_client_adapter_curl_method_entry[] = {
	PHP_ME(Phalcon_Http_Client_Adapter_Curl, __construct, arginfo_phalcon_http_client_adapter_curl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Client_Adapter_Curl, sendInternal, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

/**
 * Phalcon\Http\Client\Adapter\Curl initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client_Adapter_Curl){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Http\\Client\\Adapter, Curl, http_client_adapter_curl, phalcon_http_client_adapter_ce,  phalcon_http_client_adapter_curl_method_entry, 0);

	zend_declare_property_null(phalcon_http_client_adapter_curl_ce, SL("_curl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_client_adapter_curl_ce TSRMLS_CC, 1, phalcon_http_client_adapterinterface_ce);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Curl, __construct){

	zval *uri = NULL, *method = NULL, *upper_method, *header, *curl = NULL, *options, *constant;

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

	phalcon_update_property_this(this_ptr, SL("_header"), header TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&curl, "curl_init");

	PHALCON_INIT_VAR(options);
	array_init(options);

	PHALCON_INIT_VAR(constant);
	if (zend_get_constant(SL("CURLOPT_RETURNTRANSFER"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_bool(&options, constant, 1, 0);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_AUTOREFERER"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_bool(&options, constant, 1, 0);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_FOLLOWLOCATION"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_bool(&options, constant, 1, 0);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_MAXREDIRS"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_long(&options, constant, 20, 0);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_HEADER"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_bool(&options, constant, 1, 0);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_USERAGENT"), constant TSRMLS_CC)) {
		phalcon_array_update_zval_string(&options, constant, SL("Phalcon HTTP Client(Curl)"), PH_COPY);
	}

	PHALCON_CALL_FUNCTION(NULL, "curl_setopt_array", curl, options);

	phalcon_update_property_this(this_ptr, SL("_curl"), curl TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Http_Client_Adapter_Curl, sendInternal){

	zval *base_uri, *url = NULL, *method, *useragent, *data, *file, *timeout, *curl, *username, *password, *authtype;
	zval *fp = NULL, *filesize = NULL, *constant, *header, *headers = NULL;
	zval *content = NULL, *errorno = NULL, *error = NULL, *headersize = NULL, *httpcode = NULL, *headerstr, *bodystr, *response, *tmp = NULL;

	PHALCON_MM_GROW();

	base_uri = phalcon_fetch_nproperty_this(this_ptr, SL("_base_uri"), PH_NOISY TSRMLS_CC);
	method = phalcon_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY TSRMLS_CC);
	useragent = phalcon_fetch_nproperty_this(this_ptr, SL("_useragent"), PH_NOISY TSRMLS_CC);
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	file = phalcon_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY TSRMLS_CC);
	timeout = phalcon_fetch_nproperty_this(this_ptr, SL("_timeout"), PH_NOISY TSRMLS_CC);
	curl = phalcon_fetch_nproperty_this(this_ptr, SL("_curl"), PH_NOISY TSRMLS_CC);
	username = phalcon_fetch_nproperty_this(this_ptr, SL("_username"), PH_NOISY TSRMLS_CC);
	password = phalcon_fetch_nproperty_this(this_ptr, SL("_password"), PH_NOISY TSRMLS_CC);
	authtype = phalcon_fetch_nproperty_this(this_ptr, SL("_authtype"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&url, base_uri, "build");

	PHALCON_INIT_VAR(constant);
	if (!zend_get_constant(SL("CURLOPT_URL"), constant TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, url);

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_CONNECTTIMEOUT"), constant TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, timeout);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_TIMEOUT"), constant TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, timeout);
	}

	PHALCON_INIT_NVAR(constant);
	if (PHALCON_IS_NOT_EMPTY(method) && zend_get_constant(SL("CURLOPT_CUSTOMREQUEST"), constant TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, method);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_USERAGENT"), constant TSRMLS_CC) && PHALCON_IS_NOT_EMPTY(useragent)) {
		PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, useragent);
	}

	header = phalcon_fetch_nproperty_this(this_ptr, SL("_header"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLOPT_HTTPHEADER"), constant TSRMLS_CC)) {
		PHALCON_CALL_METHOD(&headers, header, "build");
		phalcon_array_append_string(&headers, SL("Expect:"), 0);

		if (phalcon_fast_count_ev(headers TSRMLS_CC)) {
			PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, headers);
		}
	}

	if (PHALCON_IS_NOT_EMPTY(username)) {
		if (PHALCON_IS_STRING(authtype, "any")) {
			PHALCON_INIT_NVAR(constant);
			PHALCON_INIT_NVAR(tmp);
			if (zend_get_constant(SL("CURLOPT_HTTPAUTH"), constant TSRMLS_CC) && zend_get_constant(SL("CURLAUTH_ANY"), tmp TSRMLS_CC)) {
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);

				PHALCON_INIT_NVAR(constant);
				if (zend_get_constant(SL("CURLOPT_USERPWD"), constant TSRMLS_CC)) {
					PHALCON_INIT_NVAR(tmp);
					PHALCON_CONCAT_VSV(tmp, username, ":", password);
					PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);
				}
			}
		} else if (PHALCON_IS_STRING(authtype, "basic")) {
			PHALCON_INIT_NVAR(constant);
			PHALCON_INIT_NVAR(tmp);
			if (zend_get_constant(SL("CURLOPT_HTTPAUTH"), constant TSRMLS_CC) && zend_get_constant(SL("CURLAUTH_BASIC"), tmp TSRMLS_CC)) {
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);

				PHALCON_INIT_NVAR(constant);
				if (zend_get_constant(SL("CURLOPT_USERPWD"), constant TSRMLS_CC)) {
					PHALCON_INIT_NVAR(tmp);
					PHALCON_CONCAT_VSV(tmp, username, ":", password);
					PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);
				}
			}
		} else if (PHALCON_IS_STRING(authtype, "digest")) {
			PHALCON_INIT_NVAR(constant);
			PHALCON_INIT_NVAR(tmp);
			if (zend_get_constant(SL("CURLOPT_HTTPAUTH"), constant TSRMLS_CC) && zend_get_constant(SL("CURLAUTH_DIGEST"), tmp TSRMLS_CC)) {
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);

				PHALCON_INIT_NVAR(constant);
				if (zend_get_constant(SL("CURLOPT_USERPWD"), constant TSRMLS_CC)) {
					PHALCON_INIT_NVAR(tmp);
					PHALCON_CONCAT_VSV(tmp, username, ":", password);
					PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);
				}
			}
		}
	}

	PHALCON_INIT_NVAR(constant);
	if (PHALCON_IS_NOT_EMPTY(file) && zend_get_constant(SL("CURLOPT_INFILE"), constant TSRMLS_CC)) {
		if (Z_TYPE_P(data) == IS_ARRAY && zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant TSRMLS_CC)) {
			PHALCON_INIT_NVAR(tmp);
			PHALCON_CONCAT_SV(tmp, "@", file);

			phalcon_array_append(&data, tmp, 0);

			PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, data);
		} else {
			PHALCON_INIT_NVAR(tmp);
			ZVAL_STRING(tmp, "r", 1);
			PHALCON_CALL_FUNCTION(&fp, "fopen", file, tmp);
			PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, fp);

			PHALCON_INIT_NVAR(constant);
			if (PHALCON_IS_NOT_EMPTY(file) && zend_get_constant(SL("CURLOPT_INFILESIZE"), constant TSRMLS_CC)) {
				PHALCON_CALL_FUNCTION(&filesize, "filesize", file);
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, filesize);
			}

			PHALCON_INIT_NVAR(constant);
			if (zend_get_constant(SL("CURLOPT_UPLOAD"), constant TSRMLS_CC)) {
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, PHALCON_GLOBAL(z_true));
			}
		}
	} else {
		if (PHALCON_IS_NOT_EMPTY(data) && zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant TSRMLS_CC)) {
			if (Z_TYPE_P(data) == IS_ARRAY) {
				PHALCON_CALL_FUNCTION(&tmp, "http_build_query", data);
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, tmp);
			} else {
				PHALCON_CALL_FUNCTION(NULL, "curl_setopt", curl, constant, data);
			}
		}
	}

	PHALCON_CALL_FUNCTION(&content, "curl_exec", curl);
	PHALCON_CALL_FUNCTION(&errorno, "curl_errno", curl);

	if (PHALCON_IS_TRUE(errorno)) {
		PHALCON_CALL_FUNCTION(&error, "curl_error", curl);

		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_http_client_exception_ce, error);
		return;
	}

	PHALCON_INIT_VAR(response);
	object_init_ex(response, phalcon_http_client_response_ce);
	PHALCON_CALL_METHOD(NULL, response, "__construct");

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLINFO_HTTP_CODE"), constant TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(&httpcode, "curl_getinfo", curl, constant);
		PHALCON_CALL_METHOD(NULL, response, "setstatuscode", httpcode);
	}

	PHALCON_INIT_NVAR(constant);
	if (zend_get_constant(SL("CURLINFO_HEADER_SIZE"), constant TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(&headersize, "curl_getinfo", curl, constant);

		PHALCON_INIT_VAR(headerstr);
		phalcon_substr(headerstr, content, 0 , Z_LVAL_P(headersize));

		PHALCON_INIT_VAR(bodystr);
		phalcon_substr(bodystr, content, Z_LVAL_P(headersize) , Z_STRLEN_P(content));

		PHALCON_CALL_METHOD(NULL, response, "setheader", headerstr);
		PHALCON_CALL_METHOD(NULL, response, "setbody", bodystr);
	}

	RETURN_CTOR(response);
}

