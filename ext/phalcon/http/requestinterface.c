
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
/**
 * Phalcon\Http\RequestInterface
 *
 * Interface for Phalcon\Http\Request
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, RequestInterface, phalcon, http_requestinterface, phalcon_http_requestinterface_method_entry);


	return SUCCESS;

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if needed
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, get);

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPost);

/**
 * Gets variable from $_GET superglobal applying filters if needed
 *
 * @param string name
 * @param string|array filters
 * @param mixed defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getQuery);

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServer);

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, has);

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasPost);

/**
 * Checks whether $_GET superglobal has certain index
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasQuery);

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasServer);

/**
 * Gets HTTP header from request data
 *
 * @param string header
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHeader);

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getScheme);

/**
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isAjax);

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSoapRequested);

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSecureRequest);

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getRawBody);

/**
 * Gets active server address IP
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerAddress);

/**
 * Gets active server name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerName);

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHttpHost);

/**
 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean trustForwardedHeader
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientAddress);

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getMethod);

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUserAgent);

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array methods
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isMethod);

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPost);

/**
 *
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isGet);

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPut);

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isHead);

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isDelete);

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isOptions);

/**
 * Checks whether request include attached files
 *
 * @param boolean notErrored
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasFiles);

/**
 * Gets attached files as Phalcon\Http\Request\FileInterface compatible instances
 *
 * @param boolean notErrored
 * @return Phalcon\Http\Request\FileInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUploadedFiles);

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHTTPReferer);

/**
 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getAcceptableContent);

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestAccept);

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientCharsets);

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestCharset);

/**
 * Gets languages array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getLanguages);

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestLanguage);

