
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

#ifdef PHALCON_USE_CURL
#include <curl/curl.h>
#include <curl/easy.h>

int  le_curl;
int  le_curl_multi_handle;
#endif

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

#include "http/client.h"
#include "http/client/exception.h"

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
PHP_METHOD(Phalcon_Http_Client, setBody){

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
 * @param array $data
 */
PHP_METHOD(Phalcon_Http_Client, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);

	if (Z_TYPE_P(data) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_http_client_exception_ce, "data parameter must be array");
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

/**
 * Get data
 *
 * @return array
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

	zval *ch, *header, *response_header = NULL, *response_cookie = NULL;
	zval *pos, *key, *value, *trimmed, *cookies;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &ch, &header);

	response_header = phalcon_fetch_nproperty_this(this_ptr, SL("_response_header"), PH_NOISY_CC);
	response_cookie = phalcon_fetch_nproperty_this(this_ptr, SL("_response_cookie"), PH_NOISY_CC);
	if (Z_TYPE_P(response_header) != IS_ARRAY) {
		array_init(response_header);
	}
	if (Z_TYPE_P(response_cookie) != IS_ARRAY) {
		array_init(response_cookie);
	}

	PHALCON_INIT_VAR(pos);
	phalcon_fast_strpos_str(pos, header, SL(":"));
	if (Z_TYPE_P(pos) == IS_LONG && Z_LVAL_P(pos) > 0) {
		PHALCON_INIT_VAR(key);
		phalcon_substr(key, header, 0, Z_LVAL_P(pos));

		PHALCON_INIT_VAR(value);
		phalcon_substr(value, header, Z_LVAL_P(pos) + 1, Z_STRLEN_P(header) - Z_LVAL_P(pos) - 1);

		PHALCON_INIT_VAR(trimmed);
		phalcon_fast_trim(trimmed, value, PHALCON_TRIM_BOTH TSRMLS_CC);

		if (PHALCON_IS_STRING(key, "Set-Cookie")) {
			if (phalcon_array_isset(response_header, key)) {
				PHALCON_OBS_VAR(cookies);
				phalcon_array_fetch(&cookies, response_header, key, PH_NOISY);
			} else {
				PHALCON_INIT_VAR(cookies);
				array_init(cookies);
			}
			phalcon_array_append(&cookies, trimmed, PH_COPY | PH_SEPARATE);
			phalcon_array_update_zval(&response_header, key, &cookies, PH_COPY | PH_SEPARATE);

			PHALCON_INIT_NVAR(pos);
			phalcon_fast_strpos_str(pos, trimmed, SL(";"));
			if (Z_TYPE_P(pos) == IS_LONG && Z_LVAL_P(pos) > 0) {
				PHALCON_INIT_NVAR(value);
				phalcon_substr(value, trimmed, 0, Z_LVAL_P(pos));

				PHALCON_CPY_WRT(trimmed, value);
			} 

			PHALCON_INIT_NVAR(pos);
			phalcon_fast_strpos_str(pos, trimmed, SL("="));

			if (Z_TYPE_P(pos) == IS_LONG && Z_LVAL_P(pos) > 0) {
				PHALCON_INIT_NVAR(key);
				phalcon_substr(key, trimmed, 0, Z_LVAL_P(pos));

				PHALCON_INIT_NVAR(value);
				phalcon_substr(value, trimmed, Z_LVAL_P(pos) + 1, 0);

				phalcon_array_update_zval(&response_cookie, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			phalcon_array_update_zval(&response_header, key, &trimmed, PH_COPY | PH_SEPARATE);
		}
	}

	ZVAL_LONG(return_value, Z_STRLEN_P(header));

	PHALCON_MM_RESTORE();
}


/**
 * Get response headers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getResponseHeaders){

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
PHP_METHOD(Phalcon_Http_Client, getResponseBody) {

	RETURN_MEMBER(this_ptr, "_response_body");
}

#ifdef PHALCON_USE_CURL

#define CAAL(s, v) add_assoc_long_ex(return_value, s, sizeof(s), (long) v);
#define CAAD(s, v) add_assoc_double_ex(return_value, s, sizeof(s), (double) v);
#define CAAS(s, v) add_assoc_string_ex(return_value, s, sizeof(s), (char *) (v ? v : ""), 1);
#define CAAZ(s, v) add_assoc_zval_ex(return_value, s, sizeof(s), (zval *) v);

#define SAVE_CURL_ERROR(__handle, __err) (__handle)->err.no = (int) __err;

#ifndef HttpPost
#define HttpPost curl_httppost
#endif

static int php_curl_option_url(php_curl *ch, const char *url, const int len TSRMLS_DC) /* {{{ */
{
	CURLcode error = CURLE_OK;
	char *copystr = NULL;
	/* Disable file:// if open_basedir are used */
	if (PG(open_basedir) && *PG(open_basedir)) {
		error = curl_easy_setopt(ch->cp, CURLOPT_PROTOCOLS, CURLPROTO_ALL & ~CURLPROTO_FILE);
	}
	/* Strings passed to libcurl as 'char *' arguments, are copied by the library... NOTE: before 7.17.0 strings were not copied. */
	error = curl_easy_setopt(ch->cp, CURLOPT_URL, url);

	return (error == CURLE_OK ? 1 : 0);
}

static size_t curl_write(char *data, size_t size, size_t nmemb, void *ctx)
{
	php_curl       *ch     = (php_curl *) ctx;
	php_curl_write *t      = ch->handlers->write;
	size_t          length = size * nmemb;
	TSRMLS_FETCH_FROM_CTX(ch->thread_ctx);

	switch (t->method) {
		case PHP_CURL_STDOUT:
			PHPWRITE(data, length);
			break;
		case PHP_CURL_FILE:
			return fwrite(data, size, nmemb, t->fp);
		case PHP_CURL_RETURN:
			if (length > 0) {
				smart_str_appendl(&t->buf, data, (int) length);
			}
			break;
		case PHP_CURL_USER: {
			zval **argv[2];
			zval *retval_ptr = NULL;
			zval *handle = NULL;
			zval *zdata = NULL;
			int   error;
			zend_fcall_info fci;

			MAKE_STD_ZVAL(handle);
			ZVAL_RESOURCE(handle, ch->id);
			zend_list_addref(ch->id);
			argv[0] = &handle;

			MAKE_STD_ZVAL(zdata);
			ZVAL_STRINGL(zdata, data, length, 1);
			argv[1] = &zdata;

			fci.size = sizeof(fci);
			fci.function_table = EG(function_table);
			fci.object_ptr = NULL;
			fci.function_name = t->func_name;
			fci.retval_ptr_ptr = &retval_ptr;
			fci.param_count = 2;
			fci.params = argv;
			fci.no_separation = 0;
			fci.symbol_table = NULL;

			ch->in_callback = 1;
			error = zend_call_function(&fci, &t->fci_cache TSRMLS_CC);
			ch->in_callback = 0;
			if (error == FAILURE) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not call the CURLOPT_WRITEFUNCTION");
				length = -1;
			} else if (retval_ptr) {
				if (Z_TYPE_P(retval_ptr) != IS_LONG) {
					convert_to_long_ex(&retval_ptr);
				}
				length = Z_LVAL_P(retval_ptr);
				zval_ptr_dtor(&retval_ptr);
			}

			zval_ptr_dtor(argv[0]);
			zval_ptr_dtor(argv[1]);
			break;
		}
	}

	return length;
}

static size_t curl_read(char *data, size_t size, size_t nmemb, void *ctx)
{
	php_curl       *ch = (php_curl *) ctx;
	php_curl_read  *t  = ch->handlers->read;
	int             length = 0;

	switch (t->method) {
		case PHP_CURL_DIRECT:
			if (t->fp) {
				length = fread(data, size, nmemb, t->fp);
			}
			break;
		case PHP_CURL_USER: {
			zval **argv[3];
			zval  *handle = NULL;
			zval  *zfd = NULL;
			zval  *zlength = NULL;
			zval  *retval_ptr;
			int   error;
			zend_fcall_info fci;
			TSRMLS_FETCH_FROM_CTX(ch->thread_ctx);

			MAKE_STD_ZVAL(handle);
			MAKE_STD_ZVAL(zfd);
			MAKE_STD_ZVAL(zlength);

			ZVAL_RESOURCE(handle, ch->id);
			zend_list_addref(ch->id);
			ZVAL_RESOURCE(zfd, t->fd);
			zend_list_addref(t->fd);
			ZVAL_LONG(zlength, (int) size * nmemb);

			argv[0] = &handle;
			argv[1] = &zfd;
			argv[2] = &zlength;

			fci.size = sizeof(fci);
			fci.function_table = EG(function_table);
			fci.function_name = t->func_name;
			fci.object_ptr = NULL;
			fci.retval_ptr_ptr = &retval_ptr;
			fci.param_count = 3;
			fci.params = argv;
			fci.no_separation = 0;
			fci.symbol_table = NULL;

			ch->in_callback = 1;
			error = zend_call_function(&fci, &t->fci_cache TSRMLS_CC);
			ch->in_callback = 0;
			if (error == FAILURE) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Cannot call the CURLOPT_READFUNCTION");
				length = CURL_READFUNC_ABORT;
			} else if (retval_ptr) {
				if (Z_TYPE_P(retval_ptr) == IS_STRING) {
					length = MIN((int) (size * nmemb), Z_STRLEN_P(retval_ptr));
					memcpy(data, Z_STRVAL_P(retval_ptr), length);
				}
				zval_ptr_dtor(&retval_ptr);
			}

			zval_ptr_dtor(argv[0]);
			zval_ptr_dtor(argv[1]);
			zval_ptr_dtor(argv[2]);
			break;
		}
	}

	return length;
}

static size_t curl_write_header(char *data, size_t size, size_t nmemb, void *ctx)
{
	php_curl       *ch  = (php_curl *) ctx;
	php_curl_write *t   = ch->handlers->write_header;
	size_t          length = size * nmemb;
	TSRMLS_FETCH_FROM_CTX(ch->thread_ctx);

	switch (t->method) {
		case PHP_CURL_STDOUT:
			/* Handle special case write when we're returning the entire transfer
			 */
			if (ch->handlers->write->method == PHP_CURL_RETURN && length > 0) {
				smart_str_appendl(&ch->handlers->write->buf, data, (int) length);
			} else {
				PHPWRITE(data, length);
			}
			break;
		case PHP_CURL_FILE:
			return fwrite(data, size, nmemb, t->fp);
		case PHP_CURL_USER: {
			zval **argv[2];
			zval  *handle = NULL;
			zval  *zdata = NULL;
			zval  *retval_ptr;
			int   error;
			zend_fcall_info fci;

			MAKE_STD_ZVAL(handle);
			MAKE_STD_ZVAL(zdata);

			ZVAL_RESOURCE(handle, ch->id);
			zend_list_addref(ch->id);
			ZVAL_STRINGL(zdata, data, length, 1);

			argv[0] = &handle;
			argv[1] = &zdata;

			fci.size = sizeof(fci);
			fci.function_table = EG(function_table);
			fci.function_name = t->func_name;
			fci.symbol_table = NULL;
			fci.object_ptr = NULL;
			fci.retval_ptr_ptr = &retval_ptr;
			fci.param_count = 2;
			fci.params = argv;
			fci.no_separation = 0;

			ch->in_callback = 1;
			error = zend_call_function(&fci, &t->fci_cache TSRMLS_CC);
			ch->in_callback = 0;
			if (error == FAILURE) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not call the CURLOPT_HEADERFUNCTION");
				length = -1;
			} else if (retval_ptr) {
				if (Z_TYPE_P(retval_ptr) != IS_LONG) {
					convert_to_long_ex(&retval_ptr);
				}
				length = Z_LVAL_P(retval_ptr);
				zval_ptr_dtor(&retval_ptr);
			}
			zval_ptr_dtor(argv[0]);
			zval_ptr_dtor(argv[1]);
			break;
		}

		case PHP_CURL_IGNORE:
			return length;

		default:
			return -1;
	}

	return length;
}

void curl_init(zval *return_value) {
	php_curl *ch;
	CURL *cp;
	zval *clone;
	char *cainfo;

	cp = curl_easy_init();
	if (!cp) {
		return;
	}

	alloc_curl_handle(&ch);
	TSRMLS_SET_CTX(ch->thread_ctx);

	ch->cp = cp;

	ch->handlers->write->method = PHP_CURL_STDOUT;
	ch->handlers->write->type   = PHP_CURL_ASCII;
	ch->handlers->read->method  = PHP_CURL_DIRECT;
	ch->handlers->write_header->method = PHP_CURL_IGNORE;

	ch->uses = 0;

	MAKE_STD_ZVAL(clone);
	ch->clone = clone;

	curl_easy_setopt(ch->cp, CURLOPT_NOPROGRESS,        1);
	curl_easy_setopt(ch->cp, CURLOPT_VERBOSE,           0);
	curl_easy_setopt(ch->cp, CURLOPT_ERRORBUFFER,       ch->err.str);
	curl_easy_setopt(ch->cp, CURLOPT_WRITEFUNCTION,     curl_write);
	curl_easy_setopt(ch->cp, CURLOPT_FILE,              (void *) ch);
	curl_easy_setopt(ch->cp, CURLOPT_READFUNCTION,      curl_read);
	curl_easy_setopt(ch->cp, CURLOPT_INFILE,            (void *) ch);
	curl_easy_setopt(ch->cp, CURLOPT_HEADERFUNCTION,    curl_write_header);
	curl_easy_setopt(ch->cp, CURLOPT_WRITEHEADER,       (void *) ch);
	curl_easy_setopt(ch->cp, CURLOPT_DNS_USE_GLOBAL_CACHE, 1);
	curl_easy_setopt(ch->cp, CURLOPT_DNS_CACHE_TIMEOUT, 120);
	curl_easy_setopt(ch->cp, CURLOPT_MAXREDIRS, 20); /* prevent infinite redirects */

	cainfo = INI_STR("curl.cainfo");
	if (cainfo && strlen(cainfo) > 0) {
		curl_easy_setopt(ch->cp, CURLOPT_CAINFO, cainfo);
	}

#if defined(ZTS)
	curl_easy_setopt(ch->cp, CURLOPT_NOSIGNAL, 1);
#endif

	ZEND_REGISTER_RESOURCE(return_value, ch, le_curl);
	ch->id = Z_LVAL_P(return_value);
}

static int php_curl_setopt(php_curl *ch, long option, zval **zvalue, int files, zval *return_value TSRMLS_DC) /* {{{ */
{
	CURLcode     error=CURLE_OK;

	switch (option) {
		/* Long options */
		case CURLOPT_SSL_VERIFYHOST:
			if(Z_TYPE_PP(zvalue)==IS_BOOL && Z_BVAL_PP(zvalue)) {
				php_error_docref(NULL TSRMLS_CC, E_NOTICE, "CURLOPT_SSL_VERIFYHOST set to true which disables common name validation (setting CURLOPT_SSL_VERIFYHOST to 2 enables common name validation)");
			}
		case CURLOPT_INFILESIZE:
		case CURLOPT_VERBOSE:
		case CURLOPT_HEADER:
		case CURLOPT_NOPROGRESS:
		case CURLOPT_NOBODY:
		case CURLOPT_FAILONERROR:
		case CURLOPT_UPLOAD:
		case CURLOPT_POST:
		case CURLOPT_FTPLISTONLY:
		case CURLOPT_FTPAPPEND:
		case CURLOPT_NETRC:
		case CURLOPT_PUT:
		case CURLOPT_TIMEOUT:
		case CURLOPT_TIMEOUT_MS:
		case CURLOPT_FTP_USE_EPSV:
		case CURLOPT_LOW_SPEED_LIMIT:
		case CURLOPT_SSLVERSION:
		case CURLOPT_LOW_SPEED_TIME:
		case CURLOPT_RESUME_FROM:
		case CURLOPT_TIMEVALUE:
		case CURLOPT_TIMECONDITION:
		case CURLOPT_TRANSFERTEXT:
		case CURLOPT_HTTPPROXYTUNNEL:
		case CURLOPT_FILETIME:
		case CURLOPT_MAXREDIRS:
		case CURLOPT_MAXCONNECTS:
		case CURLOPT_CLOSEPOLICY:
		case CURLOPT_FRESH_CONNECT:
		case CURLOPT_FORBID_REUSE:
		case CURLOPT_CONNECTTIMEOUT:
		case CURLOPT_CONNECTTIMEOUT_MS:
		case CURLOPT_SSL_VERIFYPEER:
		case CURLOPT_DNS_USE_GLOBAL_CACHE:
		case CURLOPT_NOSIGNAL:
		case CURLOPT_PROXYTYPE:
		case CURLOPT_BUFFERSIZE:
		case CURLOPT_HTTPGET:
		case CURLOPT_HTTP_VERSION:
		case CURLOPT_CRLF:
		case CURLOPT_DNS_CACHE_TIMEOUT:
		case CURLOPT_PROXYPORT:
		case CURLOPT_FTP_USE_EPRT:
		case CURLOPT_HTTPAUTH:
		case CURLOPT_PROXYAUTH:
		case CURLOPT_FTP_CREATE_MISSING_DIRS:
		case CURLOPT_FTPSSLAUTH:
		case CURLOPT_FTP_SSL:
		case CURLOPT_UNRESTRICTED_AUTH:
		case CURLOPT_PORT:
		case CURLOPT_AUTOREFERER:
		case CURLOPT_COOKIESESSION:
		case CURLOPT_TCP_NODELAY:
		case CURLOPT_REDIR_PROTOCOLS:
		case CURLOPT_PROTOCOLS:
		case CURLOPT_IPRESOLVE:
		case CURLOPT_FTP_FILEMETHOD:
		case CURLOPT_FTP_SKIP_PASV_IP:
		case CURLOPT_CERTINFO:
			convert_to_long_ex(zvalue);
			if ((option == CURLOPT_PROTOCOLS || option == CURLOPT_REDIR_PROTOCOLS) &&
				(PG(open_basedir) && *PG(open_basedir)) && (Z_LVAL_PP(zvalue) & CURLPROTO_FILE)) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLPROTO_FILE cannot be activated when an open_basedir is set");
					RETVAL_FALSE;
					return 1;
			}
			error = curl_easy_setopt(ch->cp, option, Z_LVAL_PP(zvalue));
			break;
		case CURLOPT_MAX_RECV_SPEED_LARGE:
		case CURLOPT_MAX_SEND_SPEED_LARGE:
			convert_to_long_ex(zvalue);
			error = curl_easy_setopt(ch->cp, option, (curl_off_t)Z_LVAL_PP(zvalue));
			break;
		case CURLOPT_FOLLOWLOCATION:
			convert_to_long_ex(zvalue);
			if (PG(open_basedir) && *PG(open_basedir)) {
				if (Z_LVAL_PP(zvalue) != 0) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLOPT_FOLLOWLOCATION cannot be activated when an open_basedir is set");
					RETVAL_FALSE;
					return 1;
				}
			}
			error = curl_easy_setopt(ch->cp, option, Z_LVAL_PP(zvalue));
			break;
		case CURLOPT_POSTREDIR:
			convert_to_long_ex(zvalue);
			error = curl_easy_setopt(ch->cp, CURLOPT_POSTREDIR, Z_LVAL_PP(zvalue) & CURL_REDIR_POST_ALL);
			break;
		case CURLOPT_PRIVATE:
		case CURLOPT_URL:
		case CURLOPT_PROXY:
		case CURLOPT_USERPWD:
		case CURLOPT_PROXYUSERPWD:
		case CURLOPT_RANGE:
		case CURLOPT_CUSTOMREQUEST:
		case CURLOPT_USERAGENT:
		case CURLOPT_FTPPORT:
		case CURLOPT_COOKIE:
		case CURLOPT_REFERER:
		case CURLOPT_INTERFACE:
		case CURLOPT_KRB4LEVEL:
		case CURLOPT_EGDSOCKET:
		case CURLOPT_CAINFO:
		case CURLOPT_CAPATH:
		case CURLOPT_SSL_CIPHER_LIST:
		case CURLOPT_SSLKEY:
		case CURLOPT_SSLKEYTYPE:
		case CURLOPT_SSLKEYPASSWD:
		case CURLOPT_SSLENGINE:
		case CURLOPT_SSLENGINE_DEFAULT:
		case CURLOPT_SSLCERTTYPE:
		case CURLOPT_ENCODING:
		case CURLOPT_SSH_PUBLIC_KEYFILE:
		case CURLOPT_SSH_PRIVATE_KEYFILE:
		{
			char *copystr = NULL;

			convert_to_string_ex(zvalue);
			if (
				option == CURLOPT_SSH_PUBLIC_KEYFILE || option == CURLOPT_SSH_PRIVATE_KEYFILE

			) {
				if (php_check_open_basedir(Z_STRVAL_PP(zvalue) TSRMLS_CC)) {
					RETVAL_FALSE;
					return 1;
				}
			}
			if (option == CURLOPT_URL) {
				if (!php_curl_option_url(ch, Z_STRVAL_PP(zvalue), Z_STRLEN_PP(zvalue) TSRMLS_CC)) {
					RETVAL_FALSE;
					return 1;
				}
			} else {
				if (option == CURLOPT_PRIVATE) {
					char *copystr;
string_copy:
					copystr = estrndup(Z_STRVAL_PP(zvalue), Z_STRLEN_PP(zvalue));
					error = curl_easy_setopt(ch->cp, option, copystr);
					zend_llist_add_element(&ch->to_free->str, &copystr);
				} else {
					/* Strings passed to libcurl as ¡¯char *¡¯ arguments, are copied by the library... NOTE: before 7.17.0 strings were not copied. */
					error = curl_easy_setopt(ch->cp, option, Z_STRVAL_PP(zvalue));
					goto string_copy;
				}
			}
			break;
		}
		case CURLOPT_FILE:
		case CURLOPT_INFILE:
		case CURLOPT_WRITEHEADER:
		case CURLOPT_STDERR: {
			FILE *fp = NULL;
			int type;
			void * what;

			what = zend_fetch_resource(zvalue TSRMLS_CC, -1, "File-Handle", &type, 1, php_file_le_stream(), php_file_le_pstream());
			if (!what) {
				RETVAL_FALSE;
				return 1;
			}

			if (FAILURE == php_stream_cast((php_stream *) what, PHP_STREAM_AS_STDIO, (void *) &fp, REPORT_ERRORS)) {
				RETVAL_FALSE;
				return 1;
			}

			if (!fp) {
				RETVAL_FALSE;
				return 1;
			}

			error = CURLE_OK;
			switch (option) {
				case CURLOPT_FILE:
					if (((php_stream *) what)->mode[0] != 'r' || ((php_stream *) what)->mode[1] == '+') {
						if (ch->handlers->write->stream) {
							Z_DELREF_P(ch->handlers->write->stream);
						}
						Z_ADDREF_PP(zvalue);
						ch->handlers->write->fp = fp;
						ch->handlers->write->method = PHP_CURL_FILE;
						ch->handlers->write->stream = *zvalue;
					} else {
						php_error_docref(NULL TSRMLS_CC, E_WARNING, "the provided file handle is not writable");
						RETVAL_FALSE;
						return 1;
					}
					break;
				case CURLOPT_WRITEHEADER:
					if (((php_stream *) what)->mode[0] != 'r' || ((php_stream *) what)->mode[1] == '+') {
						if (ch->handlers->write_header->stream) {
							Z_DELREF_P(ch->handlers->write_header->stream);
						}
						Z_ADDREF_PP(zvalue);
						ch->handlers->write_header->fp = fp;
						ch->handlers->write_header->method = PHP_CURL_FILE;
						ch->handlers->write_header->stream = *zvalue;
					} else {
						php_error_docref(NULL TSRMLS_CC, E_WARNING, "the provided file handle is not writable");
						RETVAL_FALSE;
						return 1;
					}
					break;
				case CURLOPT_INFILE:
					if (ch->handlers->read->stream) {
						Z_DELREF_P(ch->handlers->read->stream);
					}
					Z_ADDREF_PP(zvalue);
					ch->handlers->read->fp = fp;
					ch->handlers->read->fd = Z_LVAL_PP(zvalue);
					ch->handlers->read->stream = *zvalue;
					break;
				case CURLOPT_STDERR:
					if (((php_stream *) what)->mode[0] != 'r' || ((php_stream *) what)->mode[1] == '+') {
						if (ch->handlers->std_err) {
							zval_ptr_dtor(&ch->handlers->std_err);
						}
						zval_add_ref(zvalue);
						ch->handlers->std_err = *zvalue;
					} else {
						php_error_docref(NULL TSRMLS_CC, E_WARNING, "the provided file handle is not writable");
						RETVAL_FALSE;
						return 1;
					}
					/* break omitted intentionally */
				default:
					error = curl_easy_setopt(ch->cp, option, fp);
					break;
			}

			break;
		}
		case CURLOPT_RETURNTRANSFER:
			convert_to_long_ex(zvalue);

			if (Z_LVAL_PP(zvalue)) {
				ch->handlers->write->method = PHP_CURL_RETURN;
			} else {
				ch->handlers->write->method = PHP_CURL_STDOUT;
			}
			break;
		case CURLOPT_BINARYTRANSFER:
			convert_to_long_ex(zvalue);

			if (Z_LVAL_PP(zvalue)) {
				ch->handlers->write->type = PHP_CURL_BINARY;
			} else {
				ch->handlers->write->type = PHP_CURL_ASCII;
			}
			break;
		case CURLOPT_WRITEFUNCTION:
			if (ch->handlers->write->func_name) {
				zval_ptr_dtor(&ch->handlers->write->func_name);
				ch->handlers->write->fci_cache = empty_fcall_info_cache;
			}
			zval_add_ref(zvalue);
			ch->handlers->write->func_name = *zvalue;
			ch->handlers->write->method = PHP_CURL_USER;
			break;
		case CURLOPT_READFUNCTION:
			if (ch->handlers->read->func_name) {
				zval_ptr_dtor(&ch->handlers->read->func_name);
				ch->handlers->read->fci_cache = empty_fcall_info_cache;
			}
			zval_add_ref(zvalue);
			ch->handlers->read->func_name = *zvalue;
			ch->handlers->read->method = PHP_CURL_USER;
			break;		
		case CURLOPT_HEADERFUNCTION:
			if (ch->handlers->write_header->func_name) {
				zval_ptr_dtor(&ch->handlers->write_header->func_name);
				ch->handlers->write_header->fci_cache = empty_fcall_info_cache;
			}
			zval_add_ref(zvalue);
			ch->handlers->write_header->func_name = *zvalue;
			ch->handlers->write_header->method = PHP_CURL_USER;
			break;
		case CURLOPT_POSTFIELDS:
			if (Z_TYPE_PP(zvalue) == IS_ARRAY || Z_TYPE_PP(zvalue) == IS_OBJECT) {
				zval            **current;
				HashTable        *postfields;
				struct HttpPost  *first = NULL;
				struct HttpPost  *last  = NULL;

				postfields = HASH_OF(*zvalue);
				if (!postfields) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Couldn't get HashTable in CURLOPT_POSTFIELDS");
					RETVAL_FALSE;
					return 1;
				}

				for (zend_hash_internal_pointer_reset(postfields);
					 zend_hash_get_current_data(postfields, (void **) &current) == SUCCESS;
					 zend_hash_move_forward(postfields)
				) {
					char *postval;
					char *string_key = NULL;
					uint  string_key_len;
					ulong num_key;
					int numeric_key;

					SEPARATE_ZVAL(current);
					convert_to_string_ex(current);

					zend_hash_get_current_key_ex(postfields, &string_key, &string_key_len, &num_key, 0, NULL);

					/* Pretend we have a string_key here */
					if(!string_key) {
						spprintf(&string_key, 0, "%ld", num_key);
						string_key_len = strlen(string_key)+1;
						numeric_key = 1;
					} else {
						numeric_key = 0;
					}

					postval = Z_STRVAL_PP(current);

					/* The arguments after _NAMELENGTH and _CONTENTSLENGTH
					 * must be explicitly cast to long in curl_formadd
					 * use since curl needs a long not an int. */
					if (*postval == '@') {
						char *type, *filename;
						++postval;

						if ((type = php_memnstr(postval, ";type=", sizeof(";type=") - 1, postval + Z_STRLEN_PP(current)))) {
							*type = '\0';
						}
						if ((filename = php_memnstr(postval, ";filename=", sizeof(";filename=") - 1, postval + Z_STRLEN_PP(current)))) {
							*filename = '\0';
						}
						/* open_basedir check */
						if (php_check_open_basedir(postval TSRMLS_CC)) {
							RETVAL_FALSE;
							return 1;
						}
						error = curl_formadd(&first, &last,
										CURLFORM_COPYNAME, string_key,
										CURLFORM_NAMELENGTH, (long)string_key_len - 1,
										CURLFORM_FILENAME, filename ? filename + sizeof(";filename=") - 1 : postval,
										CURLFORM_CONTENTTYPE, type ? type + sizeof(";type=") - 1 : "application/octet-stream",
										CURLFORM_FILE, postval,
										CURLFORM_END);
						if (type) {
							*type = ';';
						}
						if (filename) {
							*filename = ';';
						}
					} else {
						error = curl_formadd(&first, &last,
											 CURLFORM_COPYNAME, string_key,
											 CURLFORM_NAMELENGTH, (long)string_key_len - 1,
											 CURLFORM_COPYCONTENTS, postval,
											 CURLFORM_CONTENTSLENGTH, (long)Z_STRLEN_PP(current),
											 CURLFORM_END);
					}

					if (numeric_key) {
						efree(string_key);
					}
				}

				SAVE_CURL_ERROR(ch, error);
				if (error != CURLE_OK) {
					RETVAL_FALSE;
					return 1;
				}

				zend_llist_add_element(&ch->to_free->post, &first);
				error = curl_easy_setopt(ch->cp, CURLOPT_HTTPPOST, first);

			} else {
#if LIBCURL_VERSION_NUM >= 0x071101
				convert_to_string_ex(zvalue);
				/* with curl 7.17.0 and later, we can use COPYPOSTFIELDS, but we have to provide size before */
				error = curl_easy_setopt(ch->cp, CURLOPT_POSTFIELDSIZE, Z_STRLEN_PP(zvalue));
				error = curl_easy_setopt(ch->cp, CURLOPT_COPYPOSTFIELDS, Z_STRVAL_PP(zvalue));
#else
				char *post = NULL;

				convert_to_string_ex(zvalue);
				post = estrndup(Z_STRVAL_PP(zvalue), Z_STRLEN_PP(zvalue));
				zend_llist_add_element(&ch->to_free->str, &post);

				error = curl_easy_setopt(ch->cp, CURLOPT_POSTFIELDS, post);
				error = curl_easy_setopt(ch->cp, CURLOPT_POSTFIELDSIZE, Z_STRLEN_PP(zvalue));
#endif
			}
			break;
		case CURLOPT_HTTPHEADER:
		case CURLOPT_QUOTE:
		case CURLOPT_HTTP200ALIASES:
		case CURLOPT_POSTQUOTE: {
			zval              **current;
			HashTable          *ph;
			struct curl_slist  *slist = NULL;

			ph = HASH_OF(*zvalue);
			if (!ph) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "You must pass either an object or an array with the CURLOPT_HTTPHEADER, CURLOPT_QUOTE, CURLOPT_HTTP200ALIASES and CURLOPT_POSTQUOTE arguments");
				RETVAL_FALSE;
				return 1;
			}

			for (zend_hash_internal_pointer_reset(ph);
				 zend_hash_get_current_data(ph, (void **) &current) == SUCCESS;
				 zend_hash_move_forward(ph)
			) {
				SEPARATE_ZVAL(current);
				convert_to_string_ex(current);

				slist = curl_slist_append(slist, Z_STRVAL_PP(current));
				if (!slist) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Could not build curl_slist");
					RETVAL_FALSE;
					return 1;
				}
			}
			zend_llist_add_element(&ch->to_free->slist, &slist);

			error = curl_easy_setopt(ch->cp, option, slist);

			break;
		}
		/* the following options deal with files, therefore the open_basedir check
		 * is required.
		 */
		case CURLOPT_COOKIEJAR:
		case CURLOPT_SSLCERT:
		case CURLOPT_RANDOM_FILE:
		case CURLOPT_COOKIEFILE: {
#if LIBCURL_VERSION_NUM < 0x071100
			char *copystr = NULL;
#endif

			convert_to_string_ex(zvalue);

			if (Z_STRLEN_PP(zvalue) && php_check_open_basedir(Z_STRVAL_PP(zvalue) TSRMLS_CC)) {
				RETVAL_FALSE;
				return 1;
			}

#if LIBCURL_VERSION_NUM >= 0x071100
			error = curl_easy_setopt(ch->cp, option, Z_STRVAL_PP(zvalue));
#else
			copystr = estrndup(Z_STRVAL_PP(zvalue), Z_STRLEN_PP(zvalue));

			error = curl_easy_setopt(ch->cp, option, copystr);
			zend_llist_add_element(&ch->to_free->str, &copystr);
#endif
			break;
		}
	}

	SAVE_CURL_ERROR(ch, error);
	if (error != CURLE_OK) {
		return 1;
	} else {
		return 0;
	}
}

static int curl_setopt(zval* return_value, zval *zid, zval* options, zval *zvalue, int files)
{
	php_curl *ch;
	long op = Z_LVAL_P(options);

	ZEND_FETCH_RESOURCE(ch, php_curl *, &zid, -1, le_curl_name, le_curl);

	if (options <= 0) {
		return 0;
	}

	if (!php_curl_setopt(ch, op, &zvalue, files, return_value TSRMLS_CC)) {
		return 1;
	} else {
		return 0;
	}
}

static void curl_getinfo(zval *return_value, zval *zid, zval* option)
{
	php_curl *ch;
	long op = Z_LVAL_P(option);

	ZEND_FETCH_RESOURCE(ch, php_curl *, &zid, -1, le_curl_name, le_curl);

	if (op <= 0) {
		char   *s_code;
		long    l_code;
		double  d_code;
		struct curl_certinfo *ci = NULL;
		zval *listcode;

		array_init(return_value);

		if (curl_easy_getinfo(ch->cp, CURLINFO_EFFECTIVE_URL, &s_code) == CURLE_OK) {
			CAAS("url", s_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_CONTENT_TYPE, &s_code) == CURLE_OK) {
			if (s_code != NULL) {
				CAAS("content_type", s_code);
			} else {
				zval *retnull;
				MAKE_STD_ZVAL(retnull);
				ZVAL_NULL(retnull);
				CAAZ("content_type", retnull);
			}
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_HTTP_CODE, &l_code) == CURLE_OK) {
			CAAL("http_code", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_HEADER_SIZE, &l_code) == CURLE_OK) {
			CAAL("header_size", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_REQUEST_SIZE, &l_code) == CURLE_OK) {
			CAAL("request_size", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_FILETIME, &l_code) == CURLE_OK) {
			CAAL("filetime", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_SSL_VERIFYRESULT, &l_code) == CURLE_OK) {
			CAAL("ssl_verify_result", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_REDIRECT_COUNT, &l_code) == CURLE_OK) {
			CAAL("redirect_count", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_TOTAL_TIME, &d_code) == CURLE_OK) {
			CAAD("total_time", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_NAMELOOKUP_TIME, &d_code) == CURLE_OK) {
			CAAD("namelookup_time", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_CONNECT_TIME, &d_code) == CURLE_OK) {
			CAAD("connect_time", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_PRETRANSFER_TIME, &d_code) == CURLE_OK) {
			CAAD("pretransfer_time", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_SIZE_UPLOAD, &d_code) == CURLE_OK) {
			CAAD("size_upload", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_SIZE_DOWNLOAD, &d_code) == CURLE_OK) {
			CAAD("size_download", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_SPEED_DOWNLOAD, &d_code) == CURLE_OK) {
			CAAD("speed_download", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_SPEED_UPLOAD, &d_code) == CURLE_OK) {
			CAAD("speed_upload", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &d_code) == CURLE_OK) {
			CAAD("download_content_length", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_CONTENT_LENGTH_UPLOAD, &d_code) == CURLE_OK) {
			CAAD("upload_content_length", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_STARTTRANSFER_TIME, &d_code) == CURLE_OK) {
			CAAD("starttransfer_time", d_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_REDIRECT_TIME, &d_code) == CURLE_OK) {
			CAAD("redirect_time", d_code);
		}

		if (curl_easy_getinfo(ch->cp, CURLINFO_PRIMARY_IP, &s_code) == CURLE_OK) {
			CAAS("primary_ip", s_code);
		}

		if (curl_easy_getinfo(ch->cp, CURLINFO_PRIMARY_PORT, &l_code) == CURLE_OK) {
			CAAL("primary_port", l_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_LOCAL_IP, &s_code) == CURLE_OK) {
			CAAS("local_ip", s_code);
		}
		if (curl_easy_getinfo(ch->cp, CURLINFO_LOCAL_PORT, &l_code) == CURLE_OK) {
			CAAL("local_port", l_code);
		}

		if (curl_easy_getinfo(ch->cp, CURLINFO_REDIRECT_URL, &s_code) == CURLE_OK) {
			CAAS("redirect_url", s_code);
		}

		if (ch->header.str_len > 0) {
			CAAS("request_header", ch->header.str);
		}
	} else {
		switch (op) {
			/* string variable types */
			case CURLINFO_PRIMARY_IP:
			case CURLINFO_LOCAL_IP:
			case CURLINFO_PRIVATE:
			case CURLINFO_EFFECTIVE_URL:
			case CURLINFO_CONTENT_TYPE:
			case CURLINFO_REDIRECT_URL:
			{
				char *s_code = NULL;

				if (curl_easy_getinfo(ch->cp, op, &s_code) == CURLE_OK && s_code) {
					ZVAL_STRING(return_value, s_code, 1);
				} else {
					ZVAL_FALSE(return_value);
				}
				break;
			}
			/* Long variable types */
			case CURLINFO_PRIMARY_PORT:
			case CURLINFO_LOCAL_PORT:
			case CURLINFO_HTTP_CODE:
			case CURLINFO_HEADER_SIZE:
			case CURLINFO_REQUEST_SIZE:
			case CURLINFO_FILETIME:
			case CURLINFO_SSL_VERIFYRESULT:
			case CURLINFO_REDIRECT_COUNT: {
				long code = 0;

				if (curl_easy_getinfo(ch->cp, op, &code) == CURLE_OK) {
					ZVAL_LONG(return_value, code);
				} else {
					ZVAL_FALSE(return_value);
				}
				break;
			}
			/* Double variable types */
			case CURLINFO_TOTAL_TIME:
			case CURLINFO_NAMELOOKUP_TIME:
			case CURLINFO_CONNECT_TIME:
			case CURLINFO_PRETRANSFER_TIME:
			case CURLINFO_SIZE_UPLOAD:
			case CURLINFO_SIZE_DOWNLOAD:
			case CURLINFO_SPEED_DOWNLOAD:
			case CURLINFO_SPEED_UPLOAD:
			case CURLINFO_CONTENT_LENGTH_DOWNLOAD:
			case CURLINFO_CONTENT_LENGTH_UPLOAD:
			case CURLINFO_STARTTRANSFER_TIME:
			case CURLINFO_REDIRECT_TIME: {
				double code = 0.0;

				if (curl_easy_getinfo(ch->cp, op, &code) == CURLE_OK) {
					ZVAL_DOUBLE(return_value, code);
				} else {
					ZVAL_FALSE(return_value);
				}
				break;
			}
		}
	}
}

static void curl_free_string(void **string)
{
	efree(*string);
}

static void curl_free_post(void **post)
{
	curl_formfree((struct HttpPost *) *post);
}

static void curl_free_slist(void **slist)
{
	curl_slist_free_all((struct curl_slist *) *slist);
}

void alloc_curl_handle(php_curl **ch)
{
	*ch                           = emalloc(sizeof(php_curl));
	(*ch)->to_free                = ecalloc(1, sizeof(struct _php_curl_free));
	(*ch)->handlers               = ecalloc(1, sizeof(php_curl_handlers));
	(*ch)->handlers->write        = ecalloc(1, sizeof(php_curl_write));
	(*ch)->handlers->write_header = ecalloc(1, sizeof(php_curl_write));
	(*ch)->handlers->read         = ecalloc(1, sizeof(php_curl_read));
	(*ch)->handlers->progress     = ecalloc(1, sizeof(php_curl_progress));

	(*ch)->in_callback = 0;
	(*ch)->header.str_len = 0;

	memset(&(*ch)->err, 0, sizeof((*ch)->err));
	(*ch)->handlers->write->stream = NULL;
	(*ch)->handlers->write_header->stream = NULL;
	(*ch)->handlers->read->stream = NULL;

	zend_llist_init(&(*ch)->to_free->str,   sizeof(char *),            (llist_dtor_func_t) curl_free_string, 0);
	zend_llist_init(&(*ch)->to_free->slist, sizeof(struct curl_slist), (llist_dtor_func_t) curl_free_slist,  0);
	zend_llist_init(&(*ch)->to_free->post,  sizeof(struct HttpPost),   (llist_dtor_func_t) curl_free_post,   0);
}

void _php_curl_cleanup_handle(php_curl *ch)
{
	if (ch->handlers->write->buf.len > 0) {
		smart_str_free(&ch->handlers->write->buf);
	}
	if (ch->header.str_len) {
		efree(ch->header.str);
		ch->header.str_len = 0;
	}

	memset(ch->err.str, 0, CURL_ERROR_SIZE + 1);
	ch->err.no = 0;
}

int _php_curl_verify_handlers(php_curl *ch, int reporterror TSRMLS_DC) /* {{{ */
{
	php_stream *stream;
	if (!ch || !ch->handlers) {
		return 0;
	}

	if (ch->handlers->std_err) {
		stream = (php_stream *) zend_fetch_resource(&ch->handlers->std_err TSRMLS_CC, -1, NULL, NULL, 2, php_file_le_stream(), php_file_le_pstream());
		if (stream == NULL) {
			if (reporterror) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLOPT_STDERR resource has gone away, resetting to stderr");
			}
			zval_ptr_dtor(&ch->handlers->std_err);
			ch->handlers->std_err = NULL;

			curl_easy_setopt(ch->cp, CURLOPT_STDERR, stderr);
		}
	}
	if (ch->handlers->read && ch->handlers->read->stream) {
		stream = (php_stream *) zend_fetch_resource(&ch->handlers->read->stream TSRMLS_CC, -1, NULL, NULL, 2, php_file_le_stream(), php_file_le_pstream());
		if (stream == NULL) {
			if (reporterror) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLOPT_INFILE resource has gone away, resetting to default");
			}
			zval_ptr_dtor(&ch->handlers->read->stream);
			ch->handlers->read->fd = 0;
			ch->handlers->read->fp = 0;
			ch->handlers->read->stream = NULL;

			curl_easy_setopt(ch->cp, CURLOPT_INFILE, (void *) ch);
		}
	}
	if (ch->handlers->write_header && ch->handlers->write_header->stream) {
		stream = (php_stream *) zend_fetch_resource(&ch->handlers->write_header->stream TSRMLS_CC, -1, NULL, NULL, 2, php_file_le_stream(), php_file_le_pstream());
		if (stream == NULL) {
			if (reporterror) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLOPT_WRITEHEADER resource has gone away, resetting to default");
			}
			zval_ptr_dtor(&ch->handlers->write_header->stream);
			ch->handlers->write_header->fp = 0;
			ch->handlers->write_header->stream = NULL;

			ch->handlers->write_header->method = PHP_CURL_IGNORE;
			curl_easy_setopt(ch->cp, CURLOPT_WRITEHEADER, (void *) ch);
		}
	}
	if (ch->handlers->write && ch->handlers->write->stream) {
		stream = (php_stream *) zend_fetch_resource(&ch->handlers->write->stream TSRMLS_CC, -1, NULL, NULL, 2, php_file_le_stream(), php_file_le_pstream());
		if (stream == NULL) {
			if (reporterror) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "CURLOPT_FILE resource has gone away, resetting to default");
			}
			zval_ptr_dtor(&ch->handlers->write->stream);
			ch->handlers->write->fp = 0;
			ch->handlers->write->stream = NULL;

			ch->handlers->write->method = PHP_CURL_STDOUT;
			ch->handlers->write->type   = PHP_CURL_ASCII;
			curl_easy_setopt(ch->cp, CURLOPT_FILE, (void *) ch);
		}
	}
	return 1;
}

static void curl_exec(zval *return_value, zval *zid)
{
	CURLcode	error;
	php_curl	*ch;

	ZEND_FETCH_RESOURCE(ch, php_curl *, &zid, -1, le_curl_name, le_curl);

	_php_curl_verify_handlers(ch, 1 TSRMLS_CC);

	_php_curl_cleanup_handle(ch);

	error = curl_easy_perform(ch->cp);
	SAVE_CURL_ERROR(ch, error);
	/* CURLE_PARTIAL_FILE is returned by HEAD requests */
	if (error != CURLE_OK && error != CURLE_PARTIAL_FILE) {
		if (ch->handlers->write->buf.len > 0) {
			smart_str_free(&ch->handlers->write->buf);
		}
		RETURN_FALSE;
	}

	if (ch->handlers->std_err) {
		php_stream  *stream;
		stream = (php_stream*)zend_fetch_resource(&ch->handlers->std_err TSRMLS_CC, -1, NULL, NULL, 2, php_file_le_stream(), php_file_le_pstream());
		if (stream) {
			php_stream_flush(stream);
		}
	}

	if (ch->handlers->write->method == PHP_CURL_RETURN && ch->handlers->write->buf.len > 0) {
		smart_str_0(&ch->handlers->write->buf);
		RETURN_STRINGL(ch->handlers->write->buf.c, ch->handlers->write->buf.len, 1);
	}

	/* flush the file handle, so any remaining data is synched to disk */
	if (ch->handlers->write->method == PHP_CURL_FILE && ch->handlers->write->fp) {
		fflush(ch->handlers->write->fp);
	}
	if (ch->handlers->write_header->method == PHP_CURL_FILE && ch->handlers->write_header->fp) {
		fflush(ch->handlers->write_header->fp);
	}

	if (ch->handlers->write->method == PHP_CURL_RETURN) {
		RETURN_EMPTY_STRING();
	} else {
		RETURN_TRUE;
	}
}

static void curl_close(zval *return_value, zval *zid)
{
	php_curl *ch;

	ZEND_FETCH_RESOURCE(ch, php_curl *, &zid, -1, le_curl_name, le_curl);

	if (ch->in_callback) {
		return;
	}

	if (ch->uses) {
		ch->uses--;
	} else {
		zend_list_delete(Z_LVAL_P(zid));
	}
}
#endif

/**
 * Send request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Client, send){

	zval *url, *method, *options, *data, *files, *cookies, *content_type, *body, *headers;
	zval *ch, *constant0 = NULL, *constant1 = NULL, *httphead, *httpcookie, *key = NULL, *value = NULL, *tmp = NULL;
	zval *timeout, *connecttimeout, *cookiesession, *maxfilesize, *protocol, *useragent, *httpauth, *httpauthtype, *upper_method, *prefixfiles, *postfields;
	zval *response_body, *response_status;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
#ifdef PHALCON_USE_CURL
	zval *number_files;
	php_curl *pch;
#endif

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

	PHALCON_INIT_VAR(ch);
#ifdef PHALCON_USE_CURL
	curl_init(return_value);
#else
	phalcon_call_func(ch, "curl_init");
#endif

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HTTP_VERSION"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(constant1);
		if (zend_get_constant(SL("CURL_HTTP_VERSION_NONE"), constant1 TSRMLS_CC) != FAILURE) {
#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, constant1, 0);
#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, constant1);
#endif
		}
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_ENCODING"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_STRING(tmp, "", 1);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_FOLLOWLOCATION"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_AUTOREFERER"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	/* Header */
	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HEADER"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_FALSE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLINFO_HEADER_OUT"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	/* Body */
	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_NOBODY"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_FALSE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_HEADERFUNCTION"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		array_init(tmp);

		phalcon_array_append(&tmp, this_ptr, 0);
		phalcon_array_append_string(&tmp, SL("setResponseHeader"), 0);

#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_URL"), constant0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
#ifdef PHALCON_USE_CURL
	curl_setopt(return_value, ch, constant0, url, 0);
#else
	phalcon_call_func_p3_noret("curl_setopt", ch, constant0, url);
#endif


	/* Return response */
	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLOPT_RETURNTRANSFER"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_NVAR(tmp);
		ZVAL_TRUE(tmp);
#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	}

	/* Cookies */
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

			PHALCON_SCONCAT_VSVS(httpcookie, key, "=", value, "; ");

			zend_hash_move_forward_ex(ah0, &hp0);
		}

#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, httpcookie, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, httpcookie);
#endif
	}

	/* Options */
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string_fetch(&timeout, options, SS("timeout"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_TIMEOUT_MS"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, timeout, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, timeout);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&connecttimeout, options, SS("connecttimeout"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_CONNECTTIMEOUT_MS"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, connecttimeout, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, connecttimeout);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&cookiesession, options, SS("cookiesession"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_COOKIESESSION"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, cookiesession, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, cookiesession);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&maxfilesize, options, SS("maxfilesize"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_MAXFILESIZE"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, maxfilesize, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, maxfilesize);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&protocol, options, SS("protocol"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_HTTP_VERSION"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, protocol, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, protocol);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&useragent, options, SS("useragent"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_USERAGENT"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, useragent, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, useragent);
		#endif
			}
		}

		/* auth */
		if (phalcon_array_isset_string_fetch(&httpauth, options, SS("httpauth"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_USERPWD"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, httpauth, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, httpauth);
		#endif
			}
		}

		if (phalcon_array_isset_string_fetch(&httpauthtype, options, SS("httpauthtype"))) {
			PHALCON_INIT_NVAR(constant0);
			if (zend_get_constant(SL("CURLOPT_HTTPAUTH"), constant0 TSRMLS_CC) != FAILURE) {
		#ifdef PHALCON_USE_CURL
				curl_setopt(return_value, ch, constant0, httpauthtype, 0);
		#else
				phalcon_call_func_p3_noret("curl_setopt", ch, constant0, httpauthtype);
		#endif
			}
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

#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, tmp, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
#endif
	} else if (PHALCON_IS_STRING(upper_method, "HEAD")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_NOBODY"), constant0 TSRMLS_CC) != FAILURE) {
			PHALCON_INIT_NVAR(tmp);
			ZVAL_TRUE(tmp);

	#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, tmp, 0);
	#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
	#endif
		}

	} else if (PHALCON_IS_STRING(upper_method, "POST")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POST"), constant0 TSRMLS_CC) != FAILURE) {
			PHALCON_INIT_NVAR(tmp);
			ZVAL_TRUE(tmp);

	#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, tmp, 0);
	#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
	#endif
		}
	} else if (PHALCON_IS_STRING(upper_method, "PUT")) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_UPLOAD"), constant0 TSRMLS_CC) != FAILURE) {
			PHALCON_INIT_NVAR(tmp);
			ZVAL_TRUE(tmp);

	#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, tmp, 0);
	#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, tmp);
	#endif
		}
	} else {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_CUSTOMREQUEST"), constant0 TSRMLS_CC) != FAILURE) {
	#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, upper_method, 0);
	#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, upper_method);
	#endif
		}
	}

	if (PHALCON_IS_NOT_EMPTY(body)) {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant0 TSRMLS_CC) != FAILURE) {
	#ifdef PHALCON_USE_CURL
			curl_setopt(return_value, ch, constant0, body, 0);
	#else
			phalcon_call_func_p3_noret("curl_setopt", ch, constant0, body);
	#endif
		}
	} else {
		PHALCON_INIT_NVAR(constant0);
		if (zend_get_constant(SL("CURLOPT_POSTFIELDS"), constant0 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}

#ifdef PHALCON_USE_CURL
		zend_printf("test\n");
		if (Z_TYPE_P(data) == IS_ARRAY && Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_CPY_WRT_CTOR(postfields, data);
			phalcon_merge_append(postfields, files);
		} else if (Z_TYPE_P(data) == IS_ARRAY) {
			PHALCON_CPY_WRT(postfields, data);
		} else if (Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_CPY_WRT(postfields, files);
		}

		int num = 0;
		if (Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_CPY_WRT_CTOR(postfields, data);

			PHALCON_INIT_VAR(number_files);
			phalcon_fast_count(number_files, files TSRMLS_CC);
			num = Z_LVAL_P(number_files);
		}

		curl_setopt(return_value, ch, constant0, postfields, num);
#else		
		if (Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_INIT_VAR(prefixfiles);
			array_init(prefixfiles);

			phalcon_is_iterable(files, &ah0, &hp0, 0, 0);
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HKEY(key, ah0, hp0);
				PHALCON_GET_HVALUE(value);

				PHALCON_INIT_NVAR(tmp);
				PHALCON_CONCAT_SV(tmp, "@", value);

				phalcon_array_update_zval(&prefixfiles, key, &tmp, PH_COPY | PH_SEPARATE);

				zend_hash_move_forward_ex(ah0, &hp0);
			}
		}

		if (Z_TYPE_P(data) == IS_ARRAY && Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_CPY_WRT_CTOR(postfields, data);
			phalcon_merge_append(postfields, prefixfiles);
		} else if (Z_TYPE_P(data) == IS_ARRAY) {
			PHALCON_CPY_WRT(postfields, data);
		} else if (Z_TYPE_P(files) == IS_ARRAY) {
			PHALCON_CPY_WRT(postfields, prefixfiles);
		}
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, postfields);
#endif
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
			PHALCON_CONCAT_VSV(tmp, key, ": ", value);

			phalcon_array_append(&httphead, tmp, PH_COPY | PH_SEPARATE);

			zend_hash_move_forward_ex(ah0, &hp0);
		}

#ifdef PHALCON_USE_CURL
		curl_setopt(return_value, ch, constant0, httphead, 0);
#else
		phalcon_call_func_p3_noret("curl_setopt", ch, constant0, httphead);
#endif
	}

	PHALCON_INIT_VAR(response_body);
#ifdef PHALCON_USE_CURL
	curl_exec(response_body, ch);
#else
	phalcon_call_func_p1(response_body, "curl_exec", ch);
#endif

	phalcon_update_property_this(this_ptr, SL("_response_body"), response_body TSRMLS_CC);

	PHALCON_INIT_NVAR(constant0);
	if (zend_get_constant(SL("CURLINFO_HTTP_CODE"), constant0 TSRMLS_CC) != FAILURE) {
		PHALCON_INIT_VAR(response_status);
#ifdef PHALCON_USE_CURL
		curl_getinfo(response_status, ch, constant0);
#else
		phalcon_call_func_p2(response_status, "curl_getinfo", ch, constant0);
#endif
	}

	phalcon_update_property_this(this_ptr, SL("_response_status"), response_status TSRMLS_CC);
	
#ifdef PHALCON_USE_CURL
	curl_close(return_value, ch);
#else
	phalcon_call_func_p1_noret("curl_close", ch);
#endif

	ZVAL_TRUE(return_value);

	PHALCON_MM_RESTORE();
}

