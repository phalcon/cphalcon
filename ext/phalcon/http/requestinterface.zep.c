
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
 *
 * @phpstan-import-type http_basic_auth from HttpTypes
 * @phpstan-import-type http_digest_auth from HttpTypes
 * @phpstan-import-type http_quality_part from HttpTypes
 * @phpstan-import-type http_request_headers from HttpTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface)
{
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
 *
 * @todo check the filters here
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, get);
/**
 * Return an array with mime/types and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT"]
 *
 * @phpstan-return list<http_quality_part>
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getAcceptableContent);
/**
 * Gets auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_USER"]
 *
 * @phpstan-return http_basic_auth|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBasicAuth);
/**
 * Return the best mime/type accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestAccept);
/**
 * Return the best charset accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_CHARSET"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestCharset);
/**
 * Return the best language accepted by the browser/client from
 * _SERVER["HTTP_ACCEPT_LANGUAGE"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getBestLanguage);
/**
 * Return the most possible client IPv4 Address. This method searches in
 * $_SERVER["REMOTE_ADDR"] and optionally in
 * $_SERVER["HTTP_X_FORWARDED_FOR"]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientAddress);
/**
 * Return a charset array and their quality accepted by the browser/client
 * from _SERVER["HTTP_ACCEPT_CHARSET"]
 *
 * @phpstan-return list<http_quality_part>
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getClientCharsets);
/**
 * Return the content type which request has been made
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getContentType);
/**
 * Return the auth info accepted by the browser/client from
 * $_SERVER["PHP_AUTH_DIGEST"]
 *
 * @phpstan-return http_digest_auth
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getDigestAuth);
/**
 * Return the HTTP header from request data
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
 *
 * @phpstan-return http_request_headers
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHeaders);
/**
 * Return the host name used by the request.
 *
 * `Request::getHttpHost` trying to find host name in following order:
 *
 * - `$_SERVER["HTTP_HOST"]`
 * - `$_SERVER["SERVER_NAME"]`
 * - `$_SERVER["SERVER_ADDR"]`
 *
 * Optionally `Request::getHttpHost` validates and clean host name.
 * The `Request::$strictHostCheck` can be used to validate host name.
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
 * Return the web page that refers active request. ie: https://phalcon.io
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getHTTPReferer);
/**
 * Return the decoded JSON HTTP raw request body
 *
 * @phpstan-return array<array-key, mixed>|bool|stdClass
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getJsonRawBody);
/**
 * Return the languages array and their quality accepted by the
 * browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
 *
 * @phpstan-return list<http_quality_part>
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getLanguages);
/**
 * Return the HTTP method which request has been made
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
 * Return the information about the port on which the request is made
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPort);
/**
 * Return a variable from the $_POST superglobal applying filters if needed.
 * If no parameters are given the $_POST superglobal is returned
 *
 *```php
 * // Returns value from $_POST["user_email"] without sanitizing
 * $userEmail = $request->getPost("user_email");
 *
 * // Returns value from $_POST["user_email"] with sanitizing
 * $userEmail = $request->getPost("user_email", "email");
 *```
 *
 * @todo check the filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPost);
/**
 * Return a variable from put request
 *
 *```php
 * // Returns value from PUT stream without sanitizing
 * $userEmail = $request->getPut("user_email");
 *
 * // Returns value from PUT stream with sanitizing
 * $userEmail = $request->getPut("user_email", "email");
 *```
 *
 * @todo check the filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getPut);
/**
 * Return a variable from $_GET superglobal applying filters if needed.
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
 *
 * @todo check the filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getQuery);
/**
 * Return the HTTP raw request body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getRawBody);
/**
 * Return the HTTP schema (http/https)
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getScheme);
/**
 * Return a variable from $_SERVER superglobal
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServer);
/**
 * Return the active server address IP
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerAddress);
/**
 * Return the active server name
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getServerName);
/**
 * Return the attached files as Phalcon\Http\Request\FileInterface
 * compatible instances
 *
 * @return FileInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUploadedFiles);
/**
 * Return the HTTP URI which request has been made to
 *
 *```php
 * // Returns /some/path?with=queryParams
 * $uri = $request->getURI();
 *
 * // Returns /some/path
 * $uri = $request->getURI(true);
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getURI);
/**
 * Return the HTTP user agent used to make the request
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, getUserAgent);
/**
 * Return whether the $_REQUEST superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, has);
/**
 * Return whether the request includes attached files
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasFiles);
/**
 * Return whether the headers have a certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasHeader);
/**
 * Return whether the $_POST superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasPost);
/**
 * Return whether the PUT data has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasPut);
/**
 * Return whether the $_GET superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasQuery);
/**
 * Return whether the $_SERVER superglobal has certain index
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, hasServer);
/**
 * Return whether the request has been made using ajax. Checks if
 * $_SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isAjax);
/**
 * Return whether the HTTP method is CONNECT. if
 * $_SERVER["REQUEST_METHOD"] === "CONNECT"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isConnect);
/**
 * Return whether the HTTP method is DELETE. if
 * $_SERVER["REQUEST_METHOD"] === "DELETE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isDelete);
/**
 * Return whether the HTTP method is GET. if
 * $_SERVER["REQUEST_METHOD"] === "GET"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isGet);
/**
 * Return whether the HTTP method is HEAD. if
 * $_SERVER["REQUEST_METHOD"] === "HEAD"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isHead);
/**
 * Return if the current HTTP method matches any of the passed methods
 *
 * @param array<array-key, mixed>|string $methods
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isMethod);
/**
 * Return whether the HTTP method is OPTIONS. if
 * $_SERVER["REQUEST_METHOD"] === "OPTIONS"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isOptions);
/**
 * Return whether the HTTP method is POST. if
 * $_SERVER["REQUEST_METHOD"] === "POST"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPost);
/**
 * Return whether the HTTP method is PURGE (Squid and Varnish support). if
 * $_SERVER["REQUEST_METHOD"] === "PURGE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPurge);
/**
 * Return whether the HTTP method is PUT. if
 * $_SERVER["REQUEST_METHOD"] === "PUT"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isPut);
/**
 * Return whether the request has been made using any secure layer
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSecure);
/**
 * Return whether the request has been made using SOAP
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isSoap);
/**
 * Return whether the HTTP method is TRACE.
 * if $_SERVER["REQUEST_METHOD"] === "TRACE"
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, isTrace);
/**
 * Returns the number of files available
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_RequestInterface, numFiles);
