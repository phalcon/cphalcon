
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AbstractInjectionAware;
use Phalcon\Events\ManagerInterface;
use Phalcon\Filter\FilterInterface;
use Phalcon\Http\Message\RequestMethodInterface;
use Phalcon\Http\Request\File;
use Phalcon\Http\Request\FileInterface;
use Phalcon\Http\Request\Exception;
use Phalcon\Support\Helper\Json\Decode;
use UnexpectedValueException;
use stdClass;

/**
 * Encapsulates request information for easy and secure access from application
 * controllers.
 *
 * The request object is a simple value object that is passed between the
 * dispatcher and controller classes. It packages the HTTP request environment.
 *
 *```php
 * use Phalcon\Http\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * // Retrieve SERVER variables
 * $request->getServer("HTTP_HOST");
 *
 * // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getMethod();
 *
 * // An array of languages the client accepts
 * $request->getLanguages();
 *```
 */
class Request extends AbstractInjectionAware implements RequestInterface, RequestMethodInterface
{
    /**
     * @var FilterInterface|null
     */
    private filterService = null;

    /**
     * @var bool
     */
    private httpMethodParameterOverride = false;

    /**
     * @var array
     */
    private queryFilters = [];

    /**
     * @var array|null
     */
    private patchCache = null;

    /**
     * @var array|null
     */
    private putCache = null;

    /**
     * @var string
     */
    private rawBody = "";

    /**
     * @var bool
     */
    private strictHostCheck = false;

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
    ) -> var {
        return this->getHelper(
            _REQUEST,
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Gets an array with mime/types and their quality accepted by the
     * browser/client from _SERVER["HTTP_ACCEPT"]
     */
    public function getAcceptableContent() -> array
    {
        return this->getQualityHeader("HTTP_ACCEPT", "accept");
    }

    /**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_USER"]
     */
    public function getBasicAuth() -> array | null
    {
        if !this->hasServer("PHP_AUTH_USER") || !this->hasServer("PHP_AUTH_PW") {
            return null;
        }

        return [
            "username": this->getServer("PHP_AUTH_USER"),
            "password": this->getServer("PHP_AUTH_PW")
        ];
    }

    /**
     * Gets best mime/type accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT"]
     */
    public function getBestAccept() -> string
    {
        return this->getBestQuality(this->getAcceptableContent(), "accept");
    }

    /**
     * Gets best charset accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_CHARSET"]
     */
    public function getBestCharset() -> string
    {
        return this->getBestQuality(this->getClientCharsets(), "charset");
    }

    /**
     * Gets best language accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_LANGUAGE"]
     */
    public function getBestLanguage() -> string
    {
        return this->getBestQuality(this->getLanguages(), "language");
    }

    /**
     * Return the HTTP method parameter override flag
     *
     * @return bool
     */
    public function getHttpMethodParameterOverride() -> bool
    {
        return this->httpMethodParameterOverride;
    }

    /**
     * Gets the preferred ISO locale variant.
     *
     * Gets the preferred locale accepted by the client from the
     * "Accept-Language" request HTTP header and returns the
     * base part of it i.e. `en` instead of `en-US`.
     *
     * Note: This method relies on the `$_SERVER["HTTP_ACCEPT_LANGUAGE"]` header.
     *
     * @link https://www.iso.org/standard/50707.html
     */
    public function getPreferredIsoLocaleVariant() -> string
    {
        var language;

        let language = this->getBestLanguage(),
            language = explode("-", language),
            language = language[0],
            language = "*" === language ? "" : language;

        return language;
    }

    /**
     * Gets most possible client IPv4 Address. This method searches in
     * `$_SERVER["REMOTE_ADDR"]` and optionally in
     * `$_SERVER["HTTP_X_FORWARDED_FOR"]`
     */
    public function getClientAddress(bool trustForwardedHeader = false) -> string | bool
    {
        var address = null, server;

        let server = this->getServerArray();

        /**
         * Proxies uses this IP
         */
        if trustForwardedHeader {
            fetch address, server["HTTP_X_FORWARDED_FOR"];

            if address === null {
                fetch address, server["HTTP_CLIENT_IP"];
            }
        }

        if address === null {
            fetch address, server["REMOTE_ADDR"];
        }

        if typeof address != "string" {
            return false;
        }

        if memstr(address, ",") {
            /**
             * The client address has multiples parts, only return the first
             * part
             */
            return explode(",", address)[0];
        }

        return address;
    }

    /**
     * Gets a charsets array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_CHARSET"]
     */
    public function getClientCharsets() -> array
    {
        return this->getQualityHeader("HTTP_ACCEPT_CHARSET", "charset");
    }

    /**
     * Gets content type which request has been made
     */
    public function getContentType() -> string | null
    {
        var contentType, server;

        let server = this->getServerArray();

        if !fetch contentType, server["CONTENT_TYPE"] {
            return null;
        }

        return contentType;
    }

    /**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_DIGEST"]
     */
    public function getDigestAuth() -> array
    {
        var digest, matches, match, server;
        array auth;

        let auth   = [],
            server = this->getServerArray();

        if fetch digest, server["PHP_AUTH_DIGEST"] {
            let matches = [];

            if !preg_match_all("#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", digest, matches, 2) {
                return auth;
            }

            if typeof matches == "array" {
                for match in matches {
                    let auth[match[1]] = match[3];
                }
            }
        }

        return auth;
    }

    /**
     * Retrieves a query/get value always sanitized with the preset filters
     */
    public function getFilteredQuery(
        string name = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        return this->getFilteredData(
            self::METHOD_GET,
            "getQuery",
            name,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Retrieves a patch value always sanitized with the preset filters
     */
    public function getFilteredPatch(
        string name = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        return this->getFilteredData(
            self::METHOD_PATCH,
            "getPatch",
            name,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Retrieves a post value always sanitized with the preset filters
     */
    public function getFilteredPost(
        string name = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        return this->getFilteredData(
            self::METHOD_POST,
            "getPost",
            name,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Retrieves a put value always sanitized with the preset filters
     */
    public function getFilteredPut(
        string name = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        return this->getFilteredData(
            self::METHOD_PUT,
            "getPut",
            name,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Gets HTTP header from request data
     */
    final public function getHeader(string! header) -> string
    {
        var value, name, server;

        let name = strtoupper(
            strtr(header, "-", "_")
        );

        let server = this->getServerArray();

        if fetch value, server[name] {
            return value;
        }

        if fetch value, server["HTTP_" . name] {
            return value;
        }

        return "";
    }

    /**
     * Returns the available headers in the request
     *
     * <code>
     * $_SERVER = [
     *     "PHP_AUTH_USER" => "phalcon",
     *     "PHP_AUTH_PW"   => "secret",
     * ];
     *
     * $headers = $request->getHeaders();
     *
     * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
     * </code>
     */
    public function getHeaders() -> array
    {
        var name, value, authHeaders, server;

        array headers = [];

        array contentHeaders = [
            "CONTENT_TYPE":   true,
            "CONTENT_LENGTH": true,
            "CONTENT_MD5":    true
        ];

        let server = this->getServerArray();

        for name, value in server {
            // Note: The starts_with uses case insensitive search here
            if starts_with(name, "HTTP_") {
                let name = ucwords(
                    strtolower(
                        str_replace(
                            "_",
                            " ",
                            substr(name, 5)
                        )
                    )
                );

                let name = str_replace(" ", "-", name);

                let headers[name] = value;

                continue;
            }

            // The "CONTENT_" headers are not prefixed with "HTTP_".
            let name = strtoupper(name);

            if isset contentHeaders[name] {
                let name = ucwords(
                    strtolower(
                        str_replace("_", " ", name)
                    )
                );

                let name = str_replace(" ", "-", name);

                let headers[name] = value;
            }
        }

        let authHeaders = this->resolveAuthorizationHeaders();

        // Protect for future (child classes) changes
        let headers = array_merge(headers, authHeaders);

        return headers;
    }

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
    public function getHttpHost() -> string
    {
        var host, strict, cleanHost;

        let strict = this->strictHostCheck;

        /**
         * Get the server name from $_SERVER["HTTP_HOST"]
         */
        let host = this->getServer("HTTP_HOST");

        if !host {
            /**
             * Get the server name from $_SERVER["SERVER_NAME"]
             */
            let host = this->getServer("SERVER_NAME");
            if !host {
                /**
                 * Get the server address from $_SERVER["SERVER_ADDR"]
                 */
                let host = this->getServer("SERVER_ADDR");
            }
        }

        if host && strict {
            /**
             * Cleanup. Force lowercase as per RFC 952/2181
             */
            let cleanHost = strtolower(
                trim(host)
            );

            if memstr(cleanHost, ":") {
                let cleanHost = preg_replace("/:[[:digit:]]+$/", "", cleanHost);
            }

            /**
             * Host may contain only the ASCII letters 'a' through 'z'
             * (in a case-insensitive manner), the digits '0' through '9', and
             * the hyphen ('-') as per RFC 952/2181
             */
            if unlikely ("" !== preg_replace("/[a-z0-9-]+\.?/", "", cleanHost)) {
                throw new UnexpectedValueException("Invalid host " . host);
            }
        } else {
            let cleanHost = host;
        }

        return (string) cleanHost;
    }

    /**
     * Gets web page that refers active request. ie: http://www.google.com
     */
    public function getHTTPReferer() -> string
    {
        var httpReferer, server;

        let server = this->getServerArray();

        if !fetch httpReferer, server["HTTP_REFERER"] {
            return "";
        }

        return httpReferer;
    }

    /**
     * Gets decoded JSON HTTP raw request body
     */
    public function getJsonRawBody(bool associative = false) -> <\stdClass> | array | bool
    {
        var rawBody;

        let rawBody = this->getRawBody();

        if typeof rawBody != "string" {
            return false;
        }

        if rawBody == "" {
            let rawBody = "{}";
        }

        return (new Decode())->__invoke(rawBody, associative);
    }

    /**
     * Gets languages array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
     */
    public function getLanguages() -> array
    {
        return this->getQualityHeader("HTTP_ACCEPT_LANGUAGE", "language");
    }

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
    final public function getMethod() -> string
    {
        var overridedMethod, spoofedMethod, requestMethod, server;
        string returnMethod = "";

        let server = this->getServerArray();

        if likely fetch requestMethod, server["REQUEST_METHOD"] {
            let returnMethod = strtoupper(requestMethod);
        } else {
            return self::METHOD_GET;
        }

        if self::METHOD_POST === returnMethod {
            let overridedMethod = this->getHeader("X-HTTP-METHOD-OVERRIDE");

            if !empty overridedMethod {
                let returnMethod = strtoupper(overridedMethod);
            } elseif this->httpMethodParameterOverride {
                if fetch spoofedMethod, _REQUEST["_method"] {
                    let returnMethod = strtoupper(spoofedMethod);
                }
            }
        }

        if !this->isValidHttpMethod(returnMethod) {
            return self::METHOD_GET;
        }

        return returnMethod;
    }

    /**
     * Gets a variable from put request
     *
     *```php
     * // Returns value from $_PATCH["user_email"] without sanitizing
     * $userEmail = $request->getPatch("user_email");
     *
     * // Returns value from $_PATCH["user_email"] with sanitizing
     * $userEmail = $request->getPatch("user_email", "email");
     *```
     */
    public function getPatch(
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        return this->getPatchPut(
            "patchCache",
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Gets information about the port on which the request is made.
     */
    public function getPort() -> int
    {
        var host, pos;

        /**
         * Get the server name from $_SERVER["HTTP_HOST"]
         */
        let host = this->getServer("HTTP_HOST");

        if !host {
            return (int) this->getServer("SERVER_PORT");
        }

        if memstr(host, ":") {
            let pos = strrpos(host, ":");

            if false !== pos {
                return (int) substr(host, pos + 1);
            }
        }

        return "https" === this->getScheme() ? 443 : 80;
    }

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
    ) -> var {
        return this->getHelper(
            _POST,
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

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
    ) -> var {
        return this->getPatchPut(
            "putCache",
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

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
    ) -> var {
        return this->getHelper(
            _GET,
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Gets HTTP raw request body
     */
    public function getRawBody() -> string
    {
        var rawBody, contents;

        let rawBody = this->rawBody;

        if empty rawBody {
            let contents = file_get_contents("php://input");

            /**
             * We need store the read raw body because it can't be read again
             */
            let this->rawBody = contents;

            return contents;
        }

        return rawBody;
    }

    /**
     * Gets HTTP schema (http/https)
     */
    public function getScheme() -> string
    {
        var https;

        let https = this->getServer("HTTPS");

        if https && https != "off" {
            return "https";
        }

        return "http";
    }

    /**
     * Gets variable from $_SERVER superglobal
     */
    public function getServer(string! name) -> string | null
    {
        var serverValue, server;

        let server = this->getServerArray();

        if !fetch serverValue, server[name] {
            return null;
        }

        return serverValue;
    }

    /**
     * Gets active server address IP
     */
    public function getServerAddress() -> string
    {
        var serverAddr;

        let serverAddr = this->getServer("SERVER_ADDR");

        if null === serverAddr {
            return gethostbyname("localhost");
        }

        return serverAddr;
    }

    /**
     * Gets active server name
     */
    public function getServerName() -> string
    {
        var serverName;

        let serverName = this->getServer("SERVER_NAME");

        if null === serverName {
            return "localhost";
        }

        return serverName;
    }

    /**
     * Gets attached files as Phalcon\Http\Request\File instances
     */
    public function getUploadedFiles(
        bool onlySuccessful = false,
        bool namedKeys = false
    ) -> <FileInterface[]> {
        var superFiles, prefix, input, smoothInput, file, dataFile;
        array files = [];

        let superFiles = _FILES;

        if count(superFiles) > 0 {
            for prefix, input in superFiles {
                if typeof input["name"] == "array" {
                    let smoothInput = this->smoothFiles(
                        input["name"],
                        input["type"],
                        input["tmp_name"],
                        input["size"],
                        input["error"],
                        prefix
                    );

                    for file in smoothInput {
                        if onlySuccessful == false || file["error"] == UPLOAD_ERR_OK {
                            let dataFile = [
                                "name":     file["name"],
                                "type":     file["type"],
                                "tmp_name": file["tmp_name"],
                                "size":     file["size"],
                                "error":    file["error"]
                            ];

                            if namedKeys == true {
                                let files[file["key"]] = new File(
                                    dataFile,
                                    file["key"]
                                );
                            } else {
                                let files[] = new File(
                                    dataFile,
                                    file["key"]
                                );
                            }
                        }
                    }
                } else {
                    if onlySuccessful == false || input["error"] == UPLOAD_ERR_OK {
                        if namedKeys == true {
                            let files[prefix] = new File(input, prefix);
                        } else {
                            let files[] = new File(input, prefix);
                        }
                    }
                }
            }
        }

        return files;
    }

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
    final public function getURI(bool onlyPath = false) -> string
    {
        var requestURI;

        let requestURI = this->getServer("REQUEST_URI");
        if null === requestURI {
            return "";
        }

        if onlyPath {
            let requestURI = explode('?', requestURI)[0];
        }

        return requestURI;
    }

    /**
     * Gets HTTP user agent used to made the request
     */
    public function getUserAgent() -> string
    {
        var userAgent;

        let userAgent = this->getServer("HTTP_USER_AGENT");
        if null === userAgent {
            return "";
        }

        return userAgent;
    }

    /**
     * Checks whether $_REQUEST superglobal has certain index
     */
    public function has(string! name) -> bool
    {
        return isset _REQUEST[name];
    }

    /**
     * Returns if the request has files or not
     */
    public function hasFiles() -> bool
    {
        return this->numFiles(true) > 0;
    }

    /**
     * Checks whether headers has certain index
     */
    final public function hasHeader(string! header) -> bool
    {
        var name;

        let name = strtoupper(strtr(header, "-", "_"));

        return this->hasServer(name) || this->hasServer("HTTP_" . name);
    }

    /**
     * Checks whether the PATCH data has certain index
     */
    public function hasPatch(string! name) -> bool
    {
        var patch;

        let patch = this->getPatch();

        return isset patch[name];
    }

    /**
     * Checks whether $_POST superglobal has certain index
     */
    public function hasPost(string! name) -> bool
    {
        return isset _POST[name];
    }

    /**
     * Checks whether the PUT data has certain index
     */
    public function hasPut(string! name) -> bool
    {
        var put;

        let put = this->getPut();

        return isset put[name];
    }

    /**
     * Checks whether $_GET superglobal has certain index
     */
    public function hasQuery(string! name) -> bool
    {
        return isset _GET[name];
    }

    /**
     * Checks whether $_SERVER superglobal has certain index
     */
    final public function hasServer(string! name) -> bool
    {
        var server;

        let server = this->getServerArray();

        return isset server[name];
    }

    /**
     * Checks whether request has been made using ajax
     */
    public function isAjax() -> bool
    {
        return this->hasServer("HTTP_X_REQUESTED_WITH") &&
            this->getServer("HTTP_X_REQUESTED_WITH") === "XMLHttpRequest";
    }

    /**
     * Checks whether HTTP method is CONNECT.
     * if _SERVER["REQUEST_METHOD"]==="CONNECT"
     */
    public function isConnect() -> bool
    {
        return this->getMethod() === self::METHOD_CONNECT;
    }

    /**
     * Checks whether HTTP method is DELETE.
     * if _SERVER["REQUEST_METHOD"]==="DELETE"
     */
    public function isDelete() -> bool
    {
        return this->getMethod() === self::METHOD_DELETE;
    }

    /**
     * Checks whether HTTP method is GET.
     * if _SERVER["REQUEST_METHOD"]==="GET"
     */
    public function isGet() -> bool
    {
        return this->getMethod() === self::METHOD_GET;
    }

    /**
     * Checks whether HTTP method is HEAD.
     * if _SERVER["REQUEST_METHOD"]==="HEAD"
     */
    public function isHead() -> bool
    {
        return this->getMethod() === self::METHOD_HEAD;
    }

    /**
     * Check if HTTP method match any of the passed methods
     * When strict is true it checks if validated methods are real HTTP methods
     */
    public function isMethod(var methods, bool strict = false) -> bool
    {
        var httpMethod, method;

        let httpMethod = this->getMethod();

        if typeof methods == "string" {
            if unlikely (strict && !this->isValidHttpMethod(methods)) {
                throw new Exception("Invalid HTTP method: " . methods);
            }

            return methods == httpMethod;
        }

        if typeof methods == "array" {
            for method in methods {
                if this->isMethod(method, strict) {
                    return true;
                }
            }

            return false;
        }

        if unlikely strict {
            throw new Exception("Invalid HTTP method: non-string");
        }

        return false;
    }

    /**
     * Checks whether HTTP method is OPTIONS.
     * if _SERVER["REQUEST_METHOD"]==="OPTIONS"
     */
    public function isOptions() -> bool
    {
        return this->getMethod() === self::METHOD_OPTIONS;
    }

    /**
     * Checks whether HTTP method is PATCH.
     * if _SERVER["REQUEST_METHOD"]==="PATCH"
     */
    public function isPatch() -> bool
    {
        return this->getMethod() === self::METHOD_PATCH;
    }

    /**
     * Checks whether HTTP method is POST.
     * if _SERVER["REQUEST_METHOD"]==="POST"
     */
    public function isPost() -> bool
    {
        return this->getMethod() === self::METHOD_POST;
    }

    /**
     * Checks whether HTTP method is PUT.
     * if _SERVER["REQUEST_METHOD"]==="PUT"
     */
    public function isPut() -> bool
    {
        return this->getMethod() === self::METHOD_PUT;
    }

    /**
     * Checks whether HTTP method is PURGE (Squid and Varnish support).
     * if _SERVER["REQUEST_METHOD"]==="PURGE"
     */
    public function isPurge() -> bool
    {
        return this->getMethod() === self::METHOD_PURGE;
    }

    /**
     * Checks whether request has been made using any secure layer
     */
    public function isSecure() -> bool
    {
        return this->getScheme() === "https";
    }

    /**
     * Checks if the `Request::getHttpHost` method will be use strict validation
     * of host name or not
     */
    public function isStrictHostCheck() -> bool
    {
        return this->strictHostCheck;
    }

    /**
     * Checks whether request has been made using SOAP
     */
    public function isSoap() -> bool
    {
        var contentType;

        if this->hasServer("HTTP_SOAPACTION") {
            return true;
        }

        let contentType = this->getContentType();

        if empty contentType {
            return false;
        }

        return memstr(contentType, "application/soap+xml");
    }

    /**
     * Checks whether HTTP method is TRACE.
     * if _SERVER["REQUEST_METHOD"]==="TRACE"
     */
    public function isTrace() -> bool
    {
        return this->getMethod() === self::METHOD_TRACE;
    }

    /**
     * Checks if a method is a valid HTTP method
     */
    public function isValidHttpMethod(string method) -> bool
    {
        switch strtoupper(method) {
            case self::METHOD_CONNECT:
            case self::METHOD_DELETE:
            case self::METHOD_GET:
            case self::METHOD_HEAD:
            case self::METHOD_OPTIONS:
            case self::METHOD_PATCH:
            case self::METHOD_POST:
            case self::METHOD_PURGE:  // Squid and Varnish support
            case self::METHOD_PUT:
            case self::METHOD_TRACE:
                return true;
        }

        return false;
    }

    /**
     * Returns the number of files available
     */
    public function numFiles(bool onlySuccessful = false) -> long
    {
        var files, file, error;
        int numberFiles = 0;

        let files = _FILES;

        if typeof files != "array" {
            return 0;
        }

        for file in files {
            if fetch error, file["error"] {
                if typeof error != "array" {
                    if !error || !onlySuccessful {
                        let numberFiles++;
                    }
                }

                if typeof error == "array" {
                    let numberFiles += this->hasFileHelper(
                        error,
                        onlySuccessful
                    );
                }
            }
        }

        return numberFiles;
    }

    /**
     * Set the HTTP method parameter override flag
     *
     * @param bool $override
     *
     * @return Request
     */
    public function setHttpMethodParameterOverride(bool override) -> <Request>
    {
        let this->httpMethodParameterOverride = override;

        return this;
    }

    /**
     * Sets automatic sanitizers/filters for a particular field and for
     * particular methods
     */
    public function setParameterFilters(
        string! name,
        array filters = [],
        array scope = []
    ) -> <RequestInterface> {
        var filterService, sanitizer, localScope, scopeMethod;

        if unlikely count(filters) < 1 {
            throw new Exception(
                "Filters have not been defined for '" . name . "'"
            );
        }

        let filterService = this->getFilterService();

        for sanitizer in filters {
            if unlikely true !== filterService->has(sanitizer) {
                throw new Exception(
                    "Sanitizer '" . sanitizer . "' does not exist in the filter locator"
                );
            }
        }

        if count(scope) < 1 {
            let localScope = [
                self::METHOD_GET,
                self::METHOD_PATCH,
                self::METHOD_POST,
                self::METHOD_PUT
            ];
        } else {
            let localScope = scope;
        }

        for scopeMethod in localScope {
            let this->queryFilters[strtoupper(scopeMethod)][name] = filters;
        }

        return this;
    }

    /**
     * Sets if the `Request::getHttpHost` method must be use strict validation
     * of host name or not
     */
    public function setStrictHostCheck(bool flag = true) -> <RequestInterface>
    {
        let this->strictHostCheck = flag;

        return this;
    }

    /**
     * Process a request header and return the one with best quality
     */
    final protected function getBestQuality(array qualityParts, string! name) -> string
    {
        int i;
        double quality, acceptQuality;
        var selectedName, accept;

        let i = 0,
            quality = 0.0,
            selectedName = "";

        for accept in qualityParts {
            if i == 0 {
                let quality = (double) accept["quality"],
                    selectedName = accept[name];
            } else {
                let acceptQuality = (double) accept["quality"];

                if acceptQuality > quality {
                    let quality = acceptQuality,
                        selectedName = accept[name];
                }
            }

            let i++;
        }

        return selectedName;
    }

    /**
     * Helper to get data from superglobals, applying filters if needed.
     * If no parameters are given the superglobal is returned.
     */
    final protected function getHelper(
        array source,
        string! name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        var value, filterService;

        if name === null {
            return source;
        }

        if !fetch value, source[name] {
            return defaultValue;
        }

        if !is_numeric(value) && empty value && notAllowEmpty {
            return defaultValue;
        }

        if filters !== null {
            let filterService = this->getFilterService(),
                value         = filterService->sanitize(value, filters, noRecursive);

            /**
             * @todo Leave this here for PHP 7.4/8.0. Remove when appropriate.
             * Some filters use filter_var which can return `false`
             */
            if value === false {
                return defaultValue;
            }
        }

        return value;
    }

    /**
     * Recursively counts file in an array of files
     */
    final protected function hasFileHelper(var data, bool onlySuccessful) -> long
    {
        var value;
        int numberFiles = 0;

        if typeof data !== "array" {
            return 1;
        }

        for value in data {
            if typeof value !== "array" {
                if !value || !onlySuccessful {
                    let numberFiles++;
                }
            }

            if typeof value === "array" {
                let numberFiles += this->hasFileHelper(value, onlySuccessful);
            }
        }

        return numberFiles;
    }

    /**
     * Process a request header and return an array of values with their qualities
     */
    final protected function getQualityHeader(string! serverIndex, string! name) -> array
    {
        var headerPart, headerParts, headerSplit, part, parts, returnedParts, serverValue, split;

        let returnedParts = [],
            serverValue   = this->getServer(serverIndex);

        let serverValue = (null === serverValue) ? "" : serverValue;

        let parts = preg_split(
            "/,\\s*/",
            serverValue,
            -1,
            PREG_SPLIT_NO_EMPTY
        );

        for part in parts {
            let headerParts = [],
                headerSplit = preg_split("/\s*;\s*/", trim(part), -1, PREG_SPLIT_NO_EMPTY);

            for headerPart in headerSplit {
                if strpos(headerPart, "=") !== false {
                    let split = explode("=", headerPart, 2);

                    if split[0] === "q" {
                        let headerParts["quality"] = (double) split[1];
                    } else {
                        let headerParts[split[0]] = split[1];
                    }
                } else {
                    let headerParts[name] = headerPart;
                    let headerParts["quality"] = 1.0;
                }
            }

            let returnedParts[] = headerParts;
        }

        return returnedParts;
    }

    /**
     * Resolve authorization headers.
     */
    protected function resolveAuthorizationHeaders() -> array
    {
        var resolved, eventsManager, hasEventsManager, container, exploded,
            digest, authHeader = null, server;
        array headers = [];

        let container = <DiInterface> this->getDI(),
            server    = this->getServerArray();

        // TODO: Make Request implements EventsAwareInterface for v4.0.0
        if container !== null {
            let hasEventsManager = container->has("eventsManager");

            if hasEventsManager {
                let eventsManager = <ManagerInterface> container->getShared("eventsManager");
            }
        }

        if hasEventsManager && typeof eventsManager === "object" {
            let resolved = eventsManager->fire(
                "request:beforeAuthorizationResolve",
                this,
                [
                    "server": server
                ]
            );

            if typeof resolved === "array" {
                let headers = array_merge(headers, resolved);
            }
        }

        if this->hasServer("PHP_AUTH_USER") && this->hasServer("PHP_AUTH_PW") {
            let headers["Php-Auth-User"] = this->getServer("PHP_AUTH_USER"),
                headers["Php-Auth-Pw"]   = this->getServer("PHP_AUTH_PW");
        } else {
            if this->hasServer("HTTP_AUTHORIZATION") {
                let authHeader = this->getServer("HTTP_AUTHORIZATION");
            } elseif this->hasServer("REDIRECT_HTTP_AUTHORIZATION") {
                let authHeader = this->getServer("REDIRECT_HTTP_AUTHORIZATION");
            }

            if authHeader {
                if stripos(authHeader, "basic ") === 0 {
                    let exploded = explode(
                        ":",
                        base64_decode(
                            substr(authHeader, 6)
                        ),
                        2
                    );

                    if count(exploded) == 2 {
                        let headers["Php-Auth-User"] = exploded[0],
                            headers["Php-Auth-Pw"]   = exploded[1];
                    }
                } elseif stripos(authHeader, "digest ") === 0 && !this->hasServer("PHP_AUTH_DIGEST") {
                    let headers["Php-Auth-Digest"] = authHeader;
                } elseif stripos(authHeader, "bearer ") === 0 {
                    let headers["Authorization"] = authHeader;
                }
            }
        }

        if !isset headers["Authorization"] {
            if isset headers["Php-Auth-User"] {
                let headers["Authorization"] = "Basic " . base64_encode(headers["Php-Auth-User"] . ":" . headers["Php-Auth-Pw"]);
            } elseif fetch digest, headers["Php-Auth-Digest"] {
                let headers["Authorization"] = digest;
            }
        }

        if hasEventsManager && typeof eventsManager === "object" {
            let resolved = eventsManager->fire(
                "request:afterAuthorizationResolve",
                this,
                [
                    "headers": headers,
                    "server":  server
                ]
            );

            if typeof resolved === "array" {
                let headers = array_merge(headers, resolved);
            }

        }

        return headers;
    }

    /**
     * Smooth out $_FILES to have plain array with all files uploaded
     */
    final protected function smoothFiles(array! names, array! types, array! tmp_names, array! sizes, array! errors, string prefix) -> array
    {
        var idx, name, file, files, parentFiles, p;

        let files = [];

        for idx, name in names {
            let p = prefix . "." . idx;

            if typeof name === "string" {
                let files[] = [
                    "name":     name,
                    "type":     types[idx],
                    "tmp_name": tmp_names[idx],
                    "size":     sizes[idx],
                    "error":    errors[idx],
                    "key":      p
                ];
            }

            if typeof name === "array" {
                let parentFiles = this->smoothFiles(
                    names[idx],
                    types[idx],
                    tmp_names[idx],
                    sizes[idx],
                    errors[idx],
                    p
                );

                for file in parentFiles {
                    let files[] = file;
                }
            }
        }

        return files;
    }

    /**
     * Checks the filter service and assigns it to the class parameter
     */
    private function getFilterService() -> <FilterInterface>
    {
        var container, filterService;

        let filterService = this->filterService;

        if typeof filterService != "object" {
            let container = <DiInterface> this->container;

            if container === null {
                throw new Exception(
                    "A dependency injection container is required to access the 'filter' service"
                );
            }

            let filterService       = <FilterInterface> container->getShared("filter"),
                this->filterService = filterService;
        }

        return this->filterService;
    }

    private function getServerArray() -> array
    {
        if _SERVER {
            return _SERVER;
        }

        return [];
    }

    /**
     * Gets filtered data
     */
    public function getFilteredData(
        string methodKey,
        string method,
        string name = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        var filters;

        if !fetch filters, this->queryFilters[methodKey][name] {
            let filters = [];
        }

        return this->{method}(
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * Gets a variable from put request
     *
     *```php
     * // Returns value from $_PATCH["user_email"] without sanitizing
     * $userEmail = $request->getPatch("user_email");
     *
     * // Returns value from $_PATCH["user_email"] with sanitizing
     * $userEmail = $request->getPatch("user_email", "email");
     *```
     */
    private function getPatchPut(
        string collection,
        string name = null,
        var filters = null,
        var defaultValue = null,
        bool notAllowEmpty = false,
        bool noRecursive = false
    ) -> var {
        var cached, contentType;

        let cached = this->{collection};

        if null === cached {
            let contentType = this->getContentType();

            if (
                typeof contentType == "string" &&
                (
                    stripos(contentType, "json") != false ||
                    stripos(contentType, "multipart/form-data") !== false
                )
            ) {
                if (stripos(contentType, "json") != false) {
                    let cached = this->getJsonRawBody(true);
                }

                if (stripos(contentType, "multipart/form-data") !== false) {
                    let cached = this->getFormData();
                }

                if typeof cached != "array" {
                    let cached = [];
                }

            } else {
                let cached = [];

                parse_str(this->getRawBody(), cached);
            }

            let this->{collection} = cached;
        }

        return this->getHelper(
            cached,
            name,
            filters,
            defaultValue,
            notAllowEmpty,
            noRecursive
        );
    }

    /**
     * parse multipart/form-data from raw data
     */
    private function getFormData() -> array
    {
        var boundary, matches;

        preg_match("/boundary=(.*)$/is", this->getContentType(), matches);

        let boundary = matches[1];

        var bodyParts;

        let bodyParts = preg_split("/\\R?-+" . preg_quote(boundary, "/") . "/s", this->getRawBody());

        array_pop(bodyParts);

        array dataset = [];
        var bodyPart;

        for bodyPart in bodyParts {
            if empty(bodyPart) {
                continue;
            }

            var splited;
            let splited = preg_split("/\\R\\R/", bodyPart, 2);

            array headers = [];
            var headerParts, headerPart;

            let headerParts = preg_split("/\\R/s", splited[0], -1, PREG_SPLIT_NO_EMPTY);

            for headerPart in headerParts {
                if (strpos(headerPart, ":") === false) {
                    continue;
                }

                var exploded, headerName, headerValue;

                let exploded = explode(":", headerPart, 2),
                    headerName = strtolower(trim(exploded[0])),
                    headerValue = trim(exploded[1]);

                if strpos(headerValue, ";") !== false {
                    var explodedHeader, part;
                    let explodedHeader = explode(";", headerValue);

                    for part in explodedHeader  {
                        let part = preg_replace("/\"/", "", trim(part));

                        if strpos(part, "=") !== false {
                             var explodedPart, namePart, valuePart;
                             let explodedPart = explode("=", part, 2),
                                 namePart = strtolower(trim(explodedPart[0])),
                                 valuePart =  trim(trim(explodedPart[1]), '"'),
                                 headers[headerName][namePart] = valuePart;

                        } else {
                            let headers[headerName][] = part;
                        }
                    }
                } else {
                    let headers[headerName] = headerValue;
                }
            }

            let dataset[headers["content-disposition"]["name"]] = splited[1];
        }

        return dataset;
    }
}
