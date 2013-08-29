
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "main/SAPI.h"

#include "ext/standard/php_smart_str.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/hash.h"

/**
 * Phalcon\Http\Client
 *
 * <p>Request Client.</p>
 *
 *<code>
 *	$client = new Phalcon\Http\Client('http://localhost', Phalcon\Http\Client::METH_PUT);
 *	$http->setOptions(array(
 *		'httpauthtype' => HTTP_AUTH_DIGEST,
 *		'httpauth' => 'phalcon:phalcon'
 *	));
 *	if ($client->send() == true) {
 *		if ($client->getStatusCode() == 200) {
 *			echo $client->getRawBody();
 *			echo $client->getJsonRawBody();
 *		}
 *	}
 *</code>
 *
 */


/**
 * Phalcon\Http\Client initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Client){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Client, http_client, phalcon_http_client_method_entry, 0);

	zend_declare_property_null(phalcon_http_client_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_url"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_content_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_http_client_ce, SL("_method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_body"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_fields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_files"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_response_header"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_response_status"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_response_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_response_cookie"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_response_body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Http\Client constructor
 *
 * @param string $url
 * @param string $method
 * @param array $options
 */
PHP_METHOD(Phalcon_Http_Client, __construct){

	zval *url = NULL, *method = NULL, *options = NULL;

	phalcon_fetch_params(0, 0, 3, &url, &method, &options);
	
	if (url) {
		phalcon_update_property_this(this_ptr, SL("_url"), url TSRMLS_CC);
	}

	if (method) {
		phalcon_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);
	}

	if (options) {
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Client, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Client, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Set URL
 *
 * @param string $url
 */
PHP_METHOD(Phalcon_Http_Client, setUrl){

	zval *url;

	phalcon_fetch_params(0, 1, 0, &url);

	if (Z_TYPE_P(url) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "url parameter must be string");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_url"), url TSRMLS_CC);
}

/**
 * Get url
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getUrl){

	RETURN_MEMBER(this_ptr, "_url");
}

/**
 * Set cookies
 *
 * @param array $cookies
 */
PHP_METHOD(Phalcon_Http_Client, setCookies){

	zval *cookies;

	phalcon_fetch_params(0, 1, 0, &cookies);

	if (Z_TYPE_P(cookies) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "cookies parameter must be array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_cookies"), cookies TSRMLS_CC);
}

/**
 * Get cookies
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getCookies){

	RETURN_MEMBER(this_ptr, "_cookies");
}

/**
 * Set content type
 *
 * @param string $content_type
 */
PHP_METHOD(Phalcon_Http_Client, setContentType){

	zval *content_type;

	phalcon_fetch_params(0, 1, 0, &content_type);

	if (Z_TYPE_P(content_type) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "content_type parameter must be string");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_content_type"), content_type TSRMLS_CC);
}

/**
 * Get content type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getContentType){

	RETURN_MEMBER(this_ptr, "_content_type");
}

/**
 * Set headers
 *
 * @param array $headers
 */
PHP_METHOD(Phalcon_Http_Client, setHeaders){

	zval *headers;

	phalcon_fetch_params(0, 1, 0, &headers);

	if (Z_TYPE_P(headers) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "headers parameter must be array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_headers"), headers TSRMLS_CC);
}

/**
 * Get headers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getHeaders){

	RETURN_MEMBER(this_ptr, "_headers");
}

/**
 * Set method
 *
 * @param string $method
 */
PHP_METHOD(Phalcon_Http_Client, setMethod){

	zval *method;

	phalcon_fetch_params(0, 1, 0, &method);

	if (Z_TYPE_P(method) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "method parameter must be string");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);
}

/**
 * Get method
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getMethod){

	RETURN_MEMBER(this_ptr, "_method");
}

/**
 * Set options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Http_Client, setOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);

	if (Z_TYPE_P(options) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "options parameter must be array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
}

/**
 * Get options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getOptions){

	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Set request body to send, overwriting previously set request body.
 *
 * @param string $requestBody
 */
PHP_METHOD(Phalcon_Http_Client, setData){

	zval *body;

	phalcon_fetch_params(0, 1, 0, &body);

	if (Z_TYPE_P(body) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "body parameter must be string");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_body"), body TSRMLS_CC);
}

/**
 * Get data
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getBody){

	RETURN_MEMBER(this_ptr, "_body");
}

/**
 * Set data
 *
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Http_Client, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

/**
 * Get data
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Client, getData){

	RETURN_MEMBER(this_ptr, "_data");
}

/**
 * Set files
 *
 * @param array $files
 */
PHP_METHOD(Phalcon_Http_Client, setFiles){

	zval *files;

	phalcon_fetch_params(0, 1, 0, &files);

	if (Z_TYPE_P(files) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "files parameter must be array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_files"), files TSRMLS_CC);
}

/**
 * Get files
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getFiles){

	RETURN_MEMBER(this_ptr, "_files");
}

/**
 * Set response headers
 *
 * @param resource $ch
 * @param string $header
 */
PHP_METHOD(Phalcon_Http_Client, setResponseHeader){

	zval *ch, *header, *response_header = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &ch, &header);

	PHALCON_OBS_VAR(response_header);
	phalcon_read_property_this(&im, this_ptr, SL("_response_header"), PH_NOISY_CC);

	response_header = phalcon_fetch_nproperty_this(this_ptr, SL("_response_header"), PH_NOISY_CC);
	if (Z_TYPE_P(response_header) == IS_NULL) {
		array_init(response_header)
	}

	phalcon_array_append(&response_header, header, PH_COPY | PH_SEPARATE);

	phalcon_update_property_this(this_ptr, SL("_response_header"), response_header TSRMLS_CC);

	PHALCON_MM_RESTORE();
}


/**
 * Get response headers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getResponseHeader){

	RETURN_MEMBER(this_ptr, "_response_header");
}

/**
 * Get response status
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getResponseStatus){

	RETURN_MEMBER(this_ptr, "_response_status");
}

/**
 * Get response cookies
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getResponseCookies){

	RETURN_MEMBER(this_ptr, "_response_cookie");
}

/**
 * Get response body
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getResponseBody){

	RETURN_MEMBER(this_ptr, "_response_body");
}

/**
 * Get files
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, send){

	zval *url, *method, *options, *data, *files, *cookies, *content_type, *body, *headers;
	zval *ch, *constant0, *constant1, *httphead, *httpcookie, *key = NULL, *value = NULL, *tmp = NULL;
	zval *timeout, *connecttimeout, *cookiesession, *maxfilesize, *protocol, *httpauth, *httpauthtype, *upper_method, *query_string, *boundary, *mpboundary, *endmpboundary, *multipartbody, *filename, *type, *filecontent;
	zval *response_body, *response_status;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	url = phalcon_fetch_nproperty_this(this_ptr, SL("_url"), PH_NOISY_CC);
	method = phalcon_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY_CC);
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	files = phalcon_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
	cookies = phalcon_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	content_type = phalcon_fetch_nproperty_this(this_ptr, SL("_content_type"), PH_NOISY_CC);
	body = phalcon_fetch_nproperty_this(this_ptr, SL("_body"), PH_NOISY_CC);
	headers = phalcon_fetch_nproperty_this(this_ptr, SL("_headers"), PH_NOISY_CC);

	phalcon_update_property_null(this_ptr, SL("_response_header") TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_response_status") TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_response_cookie") TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_response_body") TSRMLS_CC);

	if (PHALCON_IS_EMPTY(url)) {
		ZVAL_FALSE(return_value);
		RETURN_MM();
	}
	PHALCON_INIT_VAR(ch);
	phalcon_call_func(ch, "curl_init");

	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HTTP_VERSION"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_VAR(constant1);
	if (zend_get_constant(SL("CURL_HTTP_VERSION_NONE"), constant1 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, constant1);

	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLOPT_ENCODING"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_NVAR(tmp);
	ZVAL_STRING(tmp, "", 1);

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);

	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLOPT_RETURNTRANSFER"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_NVAR(tmp);
	ZVAL_TRUE(tmp);

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);

	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLINFO_HEADER_OUT"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);

	// Set header function
	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HEADER"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_NVAR(tmp);
	ZVAL_FALSE(tmp);

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);

	PHALCON_INIT_VAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HEADERFUNCTION"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_NVAR(tmp);
	array_init(tmp);

	phalcon_array_append(&tmp, this_ptr, 0);
	phalcon_array_append_string(&tmp, SL("setResponseHeader"), 0);

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);

	curl_setopt($ci, , array($this, 'getHeader'));

	// Cookies
	if (Z_TYPE_P(cookies) == IS_ARRAY) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_COOKIE"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_VAR(httpcookie);
		ZVAL_STRING(httpcookie, "Cookie: ", 1);

		phalcon_is_iterable(headers, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			PHALCON_SCONCAT_SVSV(httpcookie, key, "=", value, "; ");

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, httpcookie);
	}

	// Options
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string_fetch(&timeout, options, SS("timeout"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_TIMEOUT_MS"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, timeout);
		}

		if (phalcon_array_isset_string_fetch(&connecttimeout, options, SS("connecttimeout"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_CONNECTTIMEOUT_MS"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, connecttimeout);
		}

		if (phalcon_array_isset_string_fetch(&cookiesession, options, SS("cookiesession"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_COOKIESESSION"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, cookiesession);
		}

		if (phalcon_array_isset_string_fetch(&maxfilesize, options, SS("maxfilesize"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_MAXFILESIZE"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, maxfilesize);
		}

		if (phalcon_array_isset_string_fetch(&protocol, options, SS("protocol"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_HTTP_VERSION"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, protocol);
		}

		/* auth */
		if (phalcon_array_isset_string_fetch(&httpauth, options, SS("httpauth"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_USERPWD"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, httpauth);
		}

		if (phalcon_array_isset_string_fetch(&httpauthtype, options, SS("httpauthtype"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_HTTPAUTH"), constant0 TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, httpauthtype);
		}
	}

	/* request method */
	PHALCON_INIT_VAR(upper_method);
	phalcon_fast_strtoupper(upper_method, method);

	if (PHALCON_IS_STRING(upper_method, "GET")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_HTTPGET"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);
	} else if (PHALCON_IS_STRING(upper_method, "HEAD")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_NOBODY"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);
	} else if (PHALCON_IS_STRING(upper_method, "POST")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POST"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);
	} else if (PHALCON_IS_STRING(upper_method, "PUT")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_UPLOAD"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, tmp);
	} else {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_CUSTOMREQUEST"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, upper_method);
	}

	if (PHALCON_IS_NOT_EMPTY(body)) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, body);
	} else if (phalcon_fast_count_ev(files TSRMLS_CC) > 0) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, "---------------------------", 1);

		PHALCON_INIT_VAR(boundary);
		phalcon_call_func_p1(boundary, "uniqid", tmp);

		PHALCON_INIT_NVAR(tmp);
		PHALCON_CONCAT_VS(tmp, "multipart/form-data; boundary=", boundary);

		if (Z_TYPE_P(headers) != IS_ARRAY) {
			PHALCON_INIT_VAR(headers);
			array_init(headers);
		}

		phalcon_array_update_string(&headers, SL("Content-Type"), &tmp, PH_COPY | PH_SEPARATE));

		PHALCON_INIT_VAR(mpboundary);
		PHALCON_CONCAT_VS(mpboundary, "--", boundary);

		PHALCON_INIT_VAR(endmpboundary);
		PHALCON_CONCAT_SV(endmpboundary, mpboundary, "--");

		PHALCON_INIT_VAR(multipartbody);
		ZVAL_STRING(multipartbody, "", 1);

		if (Z_TYPE_P(data) == IS_ARRAY || Z_TYPE_P(data) == IS_OBJECT) {
			phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HKEY(key, ah0, hp0);
				PHALCON_GET_HVALUE(value);

				PHALCON_SCONCAT_SV(multipartbody, mpboundary, "\r\n");
				PHALCON_SCONCAT_VSV(multipartbody, "Content-Disposition: form-data; name=\"", key, "\"\r\n\r\n");
				PHALCON_SCONCAT_VS(multipartbody, value, "\r\n");

				zend_hash_move_forward_ex(ah0, &hp0);
			}
		} else if (PHALCON_IS_NOT_EMPTY(data)) {
			PHALCON_SCONCAT_SV(multipartbody, mpboundary, "\r\n");
			PHALCON_SCONCAT_VSV(multipartbody, "Content-Disposition: form-data; \r\n\r\n", data, "\r\n");
		}

		phalcon_is_iterable(files, &ah0, &hp0, 0, 0);
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			PHALCON_INIT_NVAR(constant);
			if (zend_get_constant(SL("PATHINFO_BASENAME"), constant TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			PHALCON_INIT_VAR(filename);
			phalcon_call_func_p2(filename, "pathinfo", value, constant);

			PHALCON_INIT_VAR(type);
			phalcon_call_func_p1(type, "mime_content_type", value);

			PHALCON_SCONCAT_SV(multipartbody, mpboundary, "\r\n");
			PHALCON_SCONCAT_VSV(multipartbody, "Content-Disposition: form-data; name=\"", key, "\"; filename=\"", filename, "\" \r\n");
			PHALCON_SCONCAT_VSV(multipartbody, "Content-Type: ", type, "\r\n\r\n");

			PHALCON_INIT_VAR(filecontent);
			phalcon_call_func_p1(filecontent, "file_get_contents", filename);

			PHALCON_SCONCAT_VS(multipartbody, filecontent, "\r\n");

			zend_hash_move_forward_ex(ah0, &hp0);
		}		

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, multipartbody);
	} else if (PHALCON_IS_NOT_EMPTY(data)) {
		if (Z_TYPE_P(data) == IS_ARRAY || Z_TYPE_P(data) == IS_OBJECT) {		
			PHALCON_INIT_VAR(query_string);
			phalcon_http_build_query(query_string, data, "&" TSRMLS_CC);

			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, query_string);
		} else {
			phalcon_call_func_p2_noret("curl_setopt", ch, constant0, data);
		}
	}

	// Set headers
	if (Z_TYPE_P(headers) == IS_ARRAY) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_HTTPHEADER"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

		PHALCON_INIT_VAR(httphead);
		array_init(httphead);

		phalcon_is_iterable(headers, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			PHALCON_INIT_NVAR(tmp);
			PHALCON_CONCAT_SVS(tmp, key, ": ", value);

			phalcon_array_append(&httphead, tmp, PH_COPY | PH_SEPARATE);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		phalcon_call_func_p2_noret("curl_setopt", ch, constant0, httphead);
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_URL"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	phalcon_call_func_p2_noret("curl_setopt", ch, constant0, url);

	PHALCON_INIT_VAR(response_body);
	phalcon_call_func_p1(response_body, "curl_exec", ch);

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLINFO_HTTP_CODE"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}

	PHALCON_INIT_VAR(response_status);
	phalcon_call_func_p2(response_status, "curl_getinfo", ch, constant0);
	
	ZVAL_TRUE(return_value);

	PHALCON_MM_RESTORE();
}

