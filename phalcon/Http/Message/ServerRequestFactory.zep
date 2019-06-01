
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Collection\Collection;
use Phalcon\Helper\Arr;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\UploadedFile;
use Phalcon\Http\Message\Uri;
use Psr\Http\Message\ServerRequestFactoryInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\UriInterface;
use Psr\Http\Message\UploadedFileInterface;

/**
 * PSR-17 ServerRequestFactory
 */
class ServerRequestFactory implements ServerRequestFactoryInterface
{
    /**
     * Create a new server request.
     *
     * Note that server-params are taken precisely as given - no
     * parsing/processing of the given values is performed, and, in particular,
     * no attempt is made to determine the HTTP method or URI, which must be
     * provided explicitly.
     *
     * @param string              $method       The HTTP method associated with
     *                                          the request.
     * @param UriInterface|string $uri          The URI associated with the
     *                                          request. If the value is a
     *                                          string, the factory MUST create
     *                                          a UriInterface instance based
     *                                          on it.
     * @param array               $serverParams Array of SAPI parameters with
     *                                          which to seed the generated
     *                                          request instance.
     *
     * @return ServerRequestInterface
     */
    public function createServerRequest(string method, var uri, array serverParams = []) -> <ServerRequestInterface>
    {
        return new ServerRequest(method, uri, serverParams);
    }

    /**
     * Create a request from the supplied superglobal values.
     *
     * If any argument is not supplied, the corresponding superglobal value will
     * be used.
     *
     * The ServerRequest created is then passed to the fromServer() method in
     * order to marshal the request URI and headers.
     *
     * @param array $server  $_SERVER superglobal
     * @param array $get     $_GET superglobal
     * @param array $post    $_POST superglobal
     * @param array $cookies $_COOKIE superglobal
     * @param array $files   $_FILES superglobal
     *
     * @return ServerRequest
     */
    public function load(
        array! server = null,
        array! get = null,
        array! post = null,
        array! cookies = null,
        array! files = null) -> <ServerRequest>
    {
        var cookiesArray, filesArray, getArray, headers, method,
            postArray, protocol, serverArray;

        let serverArray  = server,
            getArray     = get,
            postArray    = post,
            cookiesArray = cookies,
            filesArray   = files;

        if unlikely null === serverArray {
            let serverArray = _SERVER;
        }

        if unlikely null === filesArray {
            let filesArray = _FILES;
        }

        if unlikely null === cookiesArray {
            let cookiesArray = _COOKIE;
        }

        if unlikely null === getArray {
            let getArray = _GET;
        }

        if unlikely null === postArray {
            let postArray = _POST;
        }

        let method      = Arr::get(server, "REQUEST_METHOD", "GET"),
            protocol    = Arr::get(server, "SERVER_PROTOCOL", "1.1"),
            serverArray = this->parseServer(serverArray),
            headers     = this->parseHeaders(serverArray),
            filesArray  = $this->parseUploadedFiles(filesArray);

        if unlikely (true === empty(cookiesArray) && headers->has("cookie")) {
            let cookiesArray = this->parseCookieHeader(headers->get("cookie"));
        }

        return new ServerRequest(
            method,
            this->parseUri(serverArray, headers),
            serverArray->toArray(),
            "php://input",
            headers->toArray(),
            cookies,
            getArray,
            filesArray->toArray(),
            postArray,
            protocol
        );
    }


    /**
     * Returns the apache_request_headers if it exists
     *
     * @return array|false
     */
    protected function getHeaders() -> array | bool
    {
        if likely (true === function_exists("apache_request_headers")) {
            return apache_request_headers();
        }

        return false;
    }

    /**
     * Calculates the host and port from the headers or the server superglobal
     *
     * @param Collection $server
     * @param Collection $headers
     *
     * @return array
     */
    private function calculateUriHost(<Collection> server, <Collection> headers) -> array
    {
        var host, port;
        array defaults;

        let defaults = ["", null];

        if unlikely  (false !== this->getHeader(headers, "host", false)) {
            let host = this->getHeader(headers, "host");
            return this->calculateUriHostFromHeader(host);
        }

        if unlikely (true !== server->has("SERVER_NAME")) {
            return defaults;
        }

        let host = server->get("SERVER_NAME"),
            port = server->get("SERVER_PORT", null);

        return [host, port];
    }

    /**
     * Get the host and calculate the port if present from the header
     *
     * @param string $host
     *
     * @return array
     */
    private function calculateUriHostFromHeader(string host) -> array
    {
        var matches, port;

        let port = null;

        // works for regname, IPv4 & IPv6
        if (preg_match("|:(\d+)$|", host, matches)) {
            let host = substr(host, 0, -1 * (strlen(matches[1]) + 1)),
                port = (int) matches[1];
        }

        return [host, port];
    }

    /**
     * Get the path from the request from IIS7/Rewrite, REQUEST_URL or
     * ORIG_PATH_INFO
     *
     * @param Collection $server
     *
     * @return string
     */
    private function calculateUriPath(<Collection> server) -> string
    {
        var iisRewrite, origPathInfo, requestUri, unencodedUrl;
        /**
         * IIS7 with URL Rewrite - double slash
         */
        let iisRewrite   = server->get("IIS_WasUrlRewritten", null),
            unencodedUrl = server->get("UNENCODED_URL", "");

        if unlikely ("1" === $iisRewrite && true !== empty(unencodedUrl)) {
            return unencodedUrl;
        }

        /**
         * REQUEST_URI
         */
        let requestUri = server->get("REQUEST_URI", null);

        if unlikely (null !== $requestUri) {
            return preg_replace("#^[^/:]+://[^/]+#", "", $requestUri);
        }

        /**
         * ORIG_PATH_INFO
         */
        let origPathInfo = server->get("ORIG_PATH_INFO", null);
        if unlikely (true === empty(origPathInfo)) {
            return "/";
        }

        return origPathInfo;
    }

    /**
     * Get the query string from the server array
     *
     * @param Collection $server
     *
     * @return string
     */
    private function calculateUriQuery(<Collection> server) -> string
    {
        return ltrim(server->get("QUERY_STRING", ""), "?");
    }

    /**
     * Calculates the scheme from the server variables
     *
     * @param Collection $server
     * @param Collection $headers
     *
     * @return string
     */
    private function calculateUriScheme(<Collection> server, <Collection> headers) -> string
    {
        var header, isHttps;
        string scheme;

        // URI scheme
        let scheme  = "https",
            isHttps = true;
        if likely (true === server->has("HTTPS")) {
            /** @var mixed $isHttps */
            let isHttps = (string) server->get("HTTPS", "on"),
                isHttps = "off" !== strtolower(isHttps);
        }

        let header = this->getHeader(headers, "x-forwarded-proto", "https");
        if (true !== isHttps || "https" !== header) {
            let scheme = "http";
        }

        return scheme;
    }

    /**
     * Create an UploadedFile object from an $_FILES array element
     *
     * @param array $file The $_FILES element
     *
     * @return UploadedFile
     *
     * @throws InvalidArgumentException If one of the elements is missing
     */
    private function createUploadedFile(array file) -> <UploadedFile>
    {
        if unlikely (true !== isset(file["tmp_name"]) ||
            true !== isset(file["size"]) ||
            true !== isset(file["error"])
        ) {
            throw new InvalidArgumentException(
                "The file array must contain tmp_name, size and error; " .
                "one or more are missing"
            );
        }

        return new UploadedFile(
            file["tmp_name"],
            file["size"],
            file["error"],
            isset(file["name"]) ? file["name"] : null,
            isset(file["type"]) ? file["type"] : null
        );
    }

    /**
     * Returns a header
     *
     * @param <Collection> $headers
     * @param string     $name
     * @param mixed|null $defaultValue
     *
     * @return mixed|string
     */
    private function getHeader(<Collection> headers, string name, var defaultValue = null) -> var
    {
        var value;

        let value = headers->get(name, defaultValue);

        if unlikely true === is_array(value) {
            let value = implode(",", value);
        }

        return value;
    }

    /**
     * Parse a cookie header according to RFC 6265.
     *
     * @param string $cookieHeader A string cookie header value.
     *
     * @return array key/value cookie pairs.
     *
     */
    private function parseCookieHeader(string cookieHeader) -> array
    {
        var cookies;

        let cookies = [];

        parse_str(
            strtr(
                cookieHeader,
                [
                    "&" : "%26",
                    "+" : "%2B",
                    ";" : "&"
                ]
            ),
            cookies
        );

        return cookies;
    }

    /**
     * Processes headers from SAPI
     *
     * @param Collection $server
     *
     * @return Collection
     */
    private function parseHeaders(<Collection> server) -> <Collection>
    {
        var headers, key, name, value;

        let headers = new Collection();
        for key, value in server {
            if likely "" !== $value {
                /**
                 * Apache prefixes environment variables with REDIRECT_
                 * if they are added by rewrite rules
                 */
                if unlikely strpos(key, "REDIRECT_") === 0 {
                    let key = substr(key, 9);
                    /**
                     * We will not overwrite existing variables with the
                     * prefixed versions, though
                     */
                    if unlikely (true === server->has(key)) {
                        continue;
                    }
                }

                if likely strpos(key, "HTTP_") === 0 {
                    let name = str_replace(
                        "_",
                        "-",
                        strtolower(substr(key, 5))
                    );
                    headers->set(name, value);
                    continue;
                }

                if unlikely strpos(key, "CONTENT_") === 0 {
                    let name = "content-" . strtolower(substr(key, 8));
                    headers->set(name, value);
                    continue;
                }
            }
        }

        return headers;
    }

    /**
     * Parse the $_SERVER array amd return it back after looking for the
     * authorization header
     *
     * @param array $server Either verbatim, or with an added
     *                      HTTP_AUTHORIZATION header.
     *
     * @return Collection
     */
    private function parseServer(array server) -> <Collection>
    {
        var collection, headers;

        let collection = new Collection(server),
            headers    = this->getHeaders();

        if unlikely !isset server["HTTP_AUTHORIZATION"] && false !== headers {
            let headers = new Collection(headers);
            if unlikely true === headers->has("Authorization") {
                collection->set("HTTP_AUTHORIZATION", headers->get("Authorization"));
            }
        }

        return collection;
    }

    /**
     * Traverses a $_FILES and creates UploadedFile objects from it. It is used
     * recursively
     *
     * @param array $files
     *
     * @return Collection
     */
    private function parseUploadedFiles(array files) -> <Collection>
    {
        var collection, data, file, key;

        let $collection = new Collection();

        /**
         * Loop through the files and check them recursively
         */
         for key, file in files {
            let key = (string) key;

            /**
             * UriInterface
             */
            if unlikely file instanceof UploadedFileInterface {
                collection->set(key, file);
                continue;
            }

            /**
             * file is array with 'tmp_name'
             */
            if  likely typeof file === "array" && isset file["tmp_name"] {
                collection->set(key, this->createUploadedFile(file));
                continue;
            }

            /**
             * file is array of elements - recursion
             */
            if unlikely typeof file === "array" {
                let data = this->parseUploadedFiles(file);
                collection->set(key, data->toArray());
                continue;
            }
        }

        return collection;
    }

    /**
     * Calculates the Uri from the server superglobal or the headers
     *
     * @param Collection $server
     * @param Collection $headers
     *
     * @return Uri
     */
    private function parseUri(<Collection> server, <Collection> headers) -> <Uri>
    {
        var path, query, scheme, split, uri;

        let uri = new Uri();

        /**
         * Scheme
         */
        let scheme = this->calculateUriScheme(server, headers),
            $uri   = uri->withScheme(scheme);

        /**
         * Host/Port
         */
        let split = this->calculateUriHost(server, headers);
        if likely true !== empty(split[0]) {
            let uri = uri->withHost(split[0]);
            if unlikely true !== empty(split[1]) {
                let uri = uri->withPort(split[1]);
            }
        }

        /**
         * Path
         */
        let path  = $this->calculateUriPath(server),
            split = explode("#", path),
            path  = explode("?", split[0]),
            uri   = uri->withPath(path[0]);

        /**
         * Fragment
         */
        if unlikely count(split) > 1 {
            let uri = uri->withFragment(split[1]);
        }

        /**
         * Query
         */
        let query = this->calculateUriQuery(server),
            uri   = uri->withQuery(query);

        return uri;
    }
}
