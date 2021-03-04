
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Http\Request
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, RequestInterface, phalcon, http_requestinterface, phalcon_http_requestinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets a variable from the $_REQUEST superglobal applying filters if
 * needed. If no parameters are given the $_REQUEST superglobal is returned
 *
 *```php
 * // Returns value from $_REQUEST["user_email"] without sanitizing
 * $userEmail = $request->get("user_email");
 *
 * // Returns value from $_REQUEST["user_email"] with sanitizing
 * $userEmail = $request->get("user_email", "email");
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, get);
/**
 * Gets an array with mime/types and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getAcceptableContent);
/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_USER"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBasicAuth);
/**
 * Gets best mime/type accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestAccept);
/**
 * Gets best charset accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_CHARSET"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestCharset);
/**
 * Gets best language accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestLanguage);
/**
 * Gets most possible client IPv4 Address. This method searches in
 * $_SERVER["REMOTE_ADDR"] and optionally in
 * $_SERVER["HTTP_X_FORWARDED_FOR"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientAddress);
/**
 * Gets a charsets array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_CHARSET"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientCharsets);
/**
 * Gets content type which request has been made
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getContentType);
/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_DIGEST"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getDigestAuth);
/**
 * Gets HTTP header from request data
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHeader);
/**
 * Returns the available headers in the request
 *
 * ```php
 * $_SERVER = [
 *     "PHP_AUTH_USER" => "phalcon",
 *     "PHP_AUTH_PW"   => "secret",
 * ];
 *
 * $headers = $request->getHeaders();
 *
 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
 * ```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHeaders);
/**
 * Gets host name used by the request.
 *
 * `Request::getHttpHost` trying to find host name in following order:
 *
 * - `$_SERVER["HTTP_HOST"]`
 * - `$_SERVER["SERVER_NAME"]`
 * - `$_SERVER["SERVER_ADDR"]`
 *
 * Optionally `Request::getHttpHost` validates and clean host name.
 * The `Request::$_strictHostCheck` can be used to validate host name.
 *
 * Note: validation and cleaning have a negative performance impact because
 * they use regular expressions.
 *
 * ```php
 * use Phalcon\Http\Request;
 *
 * $request = new Request;
 *
 * $_SERVER["HTTP_HOST"] = "example.com";
 * $request->getHttpHost(); // example.com
 *
 * $_SERVER["HTTP_HOST"] = "example.com:8080";
 * $request->getHttpHost(); // example.com:8080
 *
 * $request->setStrictHostCheck(true);
 * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
 * $request->getHttpHost(); // UnexpectedValueException
 *
 * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
 * $request->getHttpHost(); // example.com
 * ```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHttpHost);
/**
 * Gets web page that refers active request. ie: http://www.google.com
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHTTPReferer);
/**
 * Gets decoded JSON HTTP raw request body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getJsonRawBody);
/**
 * Gets languages array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getLanguages);
/**
 * Gets HTTP method which request has been made
 *
 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
 * then it is used to determine the "real" intended HTTP method.
 *
 * The _method request parameter can also be used to determine the HTTP
 * method, but only if setHttpMethodParameterOverride(true) has been called.
 *
 * The method is always an uppercased string.
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getMethod);
/**
 * Gets information about the port on which the request is made
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPort);
/**
 * Gets HTTP URI which request has been made to
 *
 *```php
 * // Returns /some/path?with=queryParams
 * $uri = $request->getURI();
 *
 * // Returns /some/path
 * $uri = $request->getURI(true);
 *```
 *
 * @param bool onlyPath If true, query part will be omitted
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getURI);
/**
 * Gets a variable from the $_POST superglobal applying filters if needed
 * If no parameters are given the $_POST superglobal is returned
 *
 *```php
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPost);
/**
 * Gets a variable from put request
 *
 *```php
 * // Returns value from $_PUT["user_email"] without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from $_PUT["user_email"] with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPut);
/**
 * Gets variable from $_GET superglobal applying filters if needed
 * If no parameters are given the $_GET superglobal is returned
 *
 *```php
 * // Returns value from $_GET["id"] without sanitizing
 * $id = $request->getQuery("id");
 *
 * // Returns value from $_GET["id"] with sanitizing
 * $id = $request->getQuery("id", "int");
 *
 * // Returns value from $_GET["id"] with a default value
 * $id = $request->getQuery("id", null, 150);
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getQuery);
/**
 * Gets HTTP raw request body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getRawBody);
/**
 * Gets HTTP schema (http/https)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getScheme);
/**
 * Gets variable from $_SERVER superglobal
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServer);
/**
 * Gets active server address IP
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerAddress);
/**
 * Gets active server name
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerName);
/**
 * Gets attached files as Phalcon\Http\Request\FileInterface compatible
 * instances
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUploadedFiles);
/**
 * Gets HTTP user agent used to made the request
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUserAgent);
/**
 * Checks whether $_REQUEST superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, has);
/**
 * Checks whether request include attached files
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasFiles);
/**
 * Checks whether headers has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasHeader);
/**
 * Checks whether $_GET superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasQuery);
/**
 * Checks whether $_POST superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasPost);
/**
 * Checks whether the PUT data has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasPut);
/**
 * Checks whether $_SERVER superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasServer);
/**
 * Checks whether request has been made using ajax. Checks if $_SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isAjax);
/**
 * Checks whether HTTP method is CONNECT. if $_SERVER["REQUEST_METHOD"] === "CONNECT"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isConnect);
/**
 * Checks whether HTTP method is DELETE. if $_SERVER["REQUEST_METHOD"] === "DELETE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isDelete);
/**
 * Checks whether HTTP method is GET. if $_SERVER["REQUEST_METHOD"] === "GET"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isGet);
/**
 * Checks whether HTTP method is HEAD. if $_SERVER["REQUEST_METHOD"] === "HEAD"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isHead);
/**
 * Check if HTTP method match any of the passed methods
 *
 * @param string|array methods
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isMethod);
/**
 * Checks whether HTTP method is OPTIONS. if $_SERVER["REQUEST_METHOD"] === "OPTIONS"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isOptions);
/**
 * Checks whether HTTP method is POST. if $_SERVER["REQUEST_METHOD"] === "POST"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPost);
/**
 * Checks whether HTTP method is PURGE (Squid and Varnish support). if $_SERVER["REQUEST_METHOD"] === "PURGE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPurge);
/**
 * Checks whether HTTP method is PUT. if $_SERVER["REQUEST_METHOD"] === "PUT"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPut);
/**
 * Checks whether request has been made using any secure layer
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSecure);
/**
 * Checks whether request has been made using SOAP
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSoap);
/**
 * Checks whether HTTP method is TRACE.
 * if $_SERVER["REQUEST_METHOD"] === "TRACE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isTrace);
/**
 * Returns the number of files available
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, numFiles);
