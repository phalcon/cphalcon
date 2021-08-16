
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

use Phalcon\Http\Request\FileInterface;
use stdClass;

/**
 * Interface for Phalcon\Http\Request
 */
interface RequestInterface
{
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
    public function get(
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var;

    /**
     * Gets an array with mime/types and their quality accepted by the
     * browser/client from _SERVER["HTTP_ACCEPT"]
     */
    public function getAcceptableContent() -> array;

    /**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_USER"]
     */
    public function getBasicAuth() -> array | null;

    /**
     * Gets best mime/type accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT"]
     */
    public function getBestAccept() -> string;

    /**
     * Gets best charset accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_CHARSET"]
     */
    public function getBestCharset() -> string;

    /**
     * Gets best language accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_LANGUAGE"]
     */
    public function getBestLanguage() -> string;

    /**
     * Gets most possible client IPv4 Address. This method searches in
     * $_SERVER["REMOTE_ADDR"] and optionally in
     * $_SERVER["HTTP_X_FORWARDED_FOR"]
     */
    public function getClientAddress(bool trustForwardedHeader = false) -> string | bool;

    /**
     * Gets a charsets array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_CHARSET"]
     */
    public function getClientCharsets() -> array;

    /**
     * Gets content type which request has been made
     */
    public function getContentType() -> string | null;

    /**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_DIGEST"]
     */
    public function getDigestAuth() -> array;

    /**
     * Gets HTTP header from request data
     */
    public function getHeader(string! header) -> string;

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
    public function getHeaders() -> array;

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
    public function getHttpHost() -> string;

    /**
     * Gets web page that refers active request. ie: http://www.google.com
     */
    public function getHTTPReferer() -> string;

    /**
     * Gets decoded JSON HTTP raw request body
     */
    public function getJsonRawBody(bool associative = false) -> <stdClass> | array | bool;

    /**
     * Gets languages array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
     */
    public function getLanguages() -> array;

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
    public function getMethod() -> string;

    /**
     * Gets information about the port on which the request is made
     */
    public function getPort() -> int;

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
    public function getURI(bool onlyPath = false) -> string;

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
    public function getPost(
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var;

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
    public function getPut(
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var;

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
    public function getQuery(
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var;

    /**
     * Gets HTTP raw request body
     */
    public function getRawBody() -> string;

    /**
     * Gets HTTP schema (http/https)
     */
    public function getScheme() -> string;


    /**
     * Gets variable from $_SERVER superglobal
     */
    public function getServer(string! name) -> string | null;

    /**
     * Gets active server address IP
     */
    public function getServerAddress() -> string;

    /**
     * Gets active server name
     */
    public function getServerName() -> string;

    /**
     * Gets attached files as Phalcon\Http\Request\FileInterface compatible
     * instances
     */
    public function getUploadedFiles(
        bool onlySuccessful = false,
        bool namedKeys = false
    ) -> <FileInterface[]>;

    /**
     * Gets HTTP user agent used to made the request
     */
    public function getUserAgent() -> string;

    /**
     * Checks whether $_REQUEST superglobal has certain index
     */
    public function has(string! name) -> bool;

    /**
     * Checks whether request include attached files
     */
    public function hasFiles() -> bool;

    /**
     * Checks whether headers has certain index
     */
    public function hasHeader(string! header) -> bool;

    /**
     * Checks whether $_GET superglobal has certain index
     */
    public function hasQuery(string! name) -> bool;

    /**
     * Checks whether $_POST superglobal has certain index
     */
    public function hasPost(string! name) -> bool;

    /**
     * Checks whether the PUT data has certain index
     */
    public function hasPut(string! name) -> bool;

    /**
     * Checks whether $_SERVER superglobal has certain index
     */
    public function hasServer(string! name) -> bool;

    /**
     * Checks whether request has been made using ajax. Checks if $_SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest"
     */
    public function isAjax() -> bool;

    /**
     * Checks whether HTTP method is CONNECT. if $_SERVER["REQUEST_METHOD"] === "CONNECT"
     */
    public function isConnect() -> bool;

    /**
     * Checks whether HTTP method is DELETE. if $_SERVER["REQUEST_METHOD"] === "DELETE"
     */
    public function isDelete() -> bool;

    /**
     * Checks whether HTTP method is GET. if $_SERVER["REQUEST_METHOD"] === "GET"
     */
    public function isGet() -> bool;

    /**
     * Checks whether HTTP method is HEAD. if $_SERVER["REQUEST_METHOD"] === "HEAD"
     */
    public function isHead() -> bool;

    /**
     * Check if HTTP method match any of the passed methods
     *
     * @param string|array methods
     */
    public function isMethod(var methods, bool strict = false) -> bool;

    /**
     * Checks whether HTTP method is OPTIONS. if $_SERVER["REQUEST_METHOD"] === "OPTIONS"
     */
    public function isOptions() -> bool;

    /**
     * Checks whether HTTP method is POST. if $_SERVER["REQUEST_METHOD"] === "POST"
     */
    public function isPost() -> bool;

    /**
     * Checks whether HTTP method is PURGE (Squid and Varnish support). if $_SERVER["REQUEST_METHOD"] === "PURGE"
     */
    public function isPurge() -> bool;

    /**
     * Checks whether HTTP method is PUT. if $_SERVER["REQUEST_METHOD"] === "PUT"
     */
    public function isPut() -> bool;

    /**
     * Checks whether request has been made using any secure layer
     */
    public function isSecure() -> bool;

    /**
     * Checks whether request has been made using SOAP
     */
    public function isSoap() -> bool;

    /**
     * Checks whether HTTP method is TRACE.
     * if $_SERVER["REQUEST_METHOD"] === "TRACE"
     */
    public function isTrace() -> bool;

    /**
     * Returns the number of files available
     */
    public function numFiles(bool onlySuccessful = false) -> long;
}
