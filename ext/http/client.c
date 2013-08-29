
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
#include "ext/json/php_json.h"

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
	zend_declare_property_null(phalcon_http_client_ce, SL("_method"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_fields"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_files"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_statuscode"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_client_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
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
 * @param int $method
 */
PHP_METHOD(Phalcon_Http_Client, setMethod){

	zval *method;

	phalcon_fetch_params(0, 1, 0, &method);
	
	phalcon_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);
}

/**
 * Get method
 *
 * @return int
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
 * Set data
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Http_Client, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

/**
 * Get data
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Client, getData){

	RETURN_MEMBER(this_ptr, "_data");
}

/**
 * Set fields
 *
 * @param array $fields
 */
PHP_METHOD(Phalcon_Http_Client, setFields){

	zval *fields;

	phalcon_fetch_params(0, 1, 0, &fields);
	
	phalcon_update_property_this(this_ptr, SL("_fields"), fields TSRMLS_CC);
}

/**
 * Get fields
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Client, getFields){

	RETURN_MEMBER(this_ptr, "_fields");
}

/**
 * Set files
 *
 * @param array $files
 */
PHP_METHOD(Phalcon_Http_Client, setFiles){

	zval *files;

	phalcon_fetch_params(0, 1, 0, &files);
	
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


#ifdef PHALCON_USE_PHP_CURL
#endif