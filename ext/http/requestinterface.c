
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

#include "http/requestinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_http_requestinterface_ce;

static const zend_function_entry phalcon_http_requestinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPut, arginfo_phalcon_http_requestinterface_getput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPut, arginfo_phalcon_http_requestinterface_hasput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoapRequested, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecureRequest, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Http\RequestInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_RequestInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http, RequestInterface, http_requestinterface, phalcon_http_requestinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, get);

/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getPost);

/**
 * Gets variable from $_GET superglobal applying filters if needed
 *
 * @param string $name
 * @param string|array $filters
 * @param mixed $defaultValue
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getQuery);

/**
 * Gets variable from $_SERVER superglobal
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getServer);

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, has);

/**
 * Checks whether $_POST superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, hasPost);

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, hasQuery);

/**
 * Checks whether $_SERVER superglobal has certain index
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, hasServer);

/**
 * Gets HTTP header from request data
 *
 * @param string $header
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getHeader);

/**
 * Gets HTTP schema (http/https)
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getScheme);

/**
 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']=='XMLHttpRequest'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isAjax);

/**
 * Checks whether request has been made using SOAP
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isSoapRequested);

/**
 * Checks whether request has been made using any secure layer
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isSecureRequest);

/**
 * Gets HTTP raws request body
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getRawBody);

/**
 * Gets active server address IP
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getServerAddress);

/**
 * Gets active server name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getServerName);

/**
 * Gets information about schema, host and port used by the request
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getHttpHost);

/**
 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
 *
 * @param boolean $trustForwardedHeader
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getClientAddress);

/**
 * Gets HTTP method which request has been made
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getMethod);

/**
 * Gets HTTP user agent used to made the request
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getUserAgent);

/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array $methods
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isMethod);

/**
 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isPost);

/**
 *
 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isGet);

/**
 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isPut);

/**
 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isHead);

/**
 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isDelete);

/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, isOptions);

/**
 * Checks whether request include attached files
 *
 * @param boolean $notErrored
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, hasFiles);

/**
 * Gets attached files as Phalcon\Http\Request\FileInterface compatible instances
 *
 * @param boolean $notErrored
 * @return Phalcon\Http\Request\FileInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getUploadedFiles);

/**
 * Gets web page that refers active request. ie: http://www.google.com
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getHTTPReferer);

/**
 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getAcceptableContent);

/**
 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getBestAccept);

/**
 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getClientCharsets);

/**
 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getBestCharset);

/**
 * Gets languages array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getLanguages);

/**
 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_RequestInterface, getBestLanguage);
