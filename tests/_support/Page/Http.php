<?php

declare(strict_types=1);

namespace Page;

class Http
{
    public const HTTP_103_EARLY_HINTS  = 'HTTP/1.1 103 Early Hints';
    public const HTTP_200_OK           = 'HTTP/1.1 200 OK';
    public const HTTP_302_FOUND        = 'HTTP/1.1 302 Found';
    public const HTTP_304_NOT_MODIFIED = 'HTTP/1.1 304 Not modified';
    public const HTTP_404_NOT_FOUND    = 'HTTP/1.1 404 Not Found';
    public const HTTP_409_CONFLICT     = 'HTTP/1.1 409 Conflict';
    public const HTTP_418_IM_A_TEAPOT  = "HTTP/1.1 418 I'm a teapot";

    public const CODE_103 = 103;
    public const CODE_200 = 200;
    public const CODE_301 = 301;
    public const CODE_304 = 304;
    public const CODE_404 = 404;
    public const CODE_409 = 409;
    public const CODE_418 = 418;

    public const CACHE_CONTROL             = 'Cache-Control';
    public const CACHE_MAX_AGE             = 'max-age=3600';
    public const CONFLICT                  = 'Conflict';
    public const CONTENT_ENCODING          = 'Content-Encoding';
    public const CONTENT_ENCODING_GZIP     = 'gzip';
    public const CONTENT_LENGTH            = 'Content-Length';
    public const CONTENT_TYPE              = 'Content-Type';
    public const CONTENT_TYPE_CSV          = 'text/csv';
    public const CONTENT_TYPE_HTML         = 'text/html';
    public const CONTENT_TYPE_HTML_CHARSET = 'text/html; charset=UTF-8';
    public const CONTENT_TYPE_HTML_RAW     = 'Content-Type: text/html';
    public const CONTENT_TYPE_JSON         = 'application/json';
    public const CONTENT_TYPE_JSON_UTF8    = 'application/json; charset=UTF-8';
    public const CONTENT_TYPE_PLAIN        = 'text/plain';
    public const CONTENT_TYPE_PLAIN_RAW    = 'Content-Type: text/plain';
    public const CONTENT_TYPE_XHTML_XML    = 'application/xhtml+xml';
    public const ETAG                      = 'Etag';
    public const EXPIRES                   = 'Expires';
    public const LAST_MODIFIED             = 'Last-Modified';
    public const LOCATION                  = 'Location';
    public const NO_CACHE                  = 'no-cache';
    public const NOT_FOUND                 = 'Not Found';
    public const NOT_MODIFIED              = 'Not modified';
    public const OK                        = 'OK';
    public const REDIRECT_URI              = 'new/place';
    public const SERVER                    = 'Server';
    public const STATUS                    = 'Status';
    public const UTF8                      = 'UTF-8';

    public const DATETIME_FORMAT = 'D, d M Y H:i:s';

    public const HOST_LOCALHOST = 'localhost';

    public const METHOD_CONNECT = 'CONNECT';
    public const METHOD_DELETE  = 'DELETE';
    public const METHOD_GET     = 'GET';
    public const METHOD_HEAD    = 'HEAD';
    public const METHOD_OPTIONS = 'OPTIONS';
    public const METHOD_PATCH   = 'PATCH';
    public const METHOD_POST    = 'POST';
    public const METHOD_PURGE   = 'PURGE';
    public const METHOD_PUT     = 'PUT';
    public const METHOD_TRACE   = 'TRACE';

    public const MESSAGE_103_EARLY_HINTS       = '103 Early Hints';
    public const MESSAGE_200_OK                = '200 OK';
    public const MESSAGE_200_SUCCESS           = '200 Success';
    public const MESSAGE_301_MOVED_PERMANENTLY = '301 Moved Permanently';
    public const MESSAGE_302_FOUND             = '302 Found';
    public const MESSAGE_304_NOT_MODIFIED      = '304 Not modified';
    public const MESSAGE_404_NOT_FOUND         = '404 Not Found';
    public const MESSAGE_409_CONFLICT          = '409 Conflict';
    public const MESSAGE_418_IM_A_TEAPOT       = "418 I'm a teapot";

    public const STREAM        = 'php://input';
    public const STREAM_MEMORY = 'php://memory';
    public const STREAM_NAME   = 'php';
    public const STREAM_TEMP   = 'php://temp';

    public const TEST_CONTENT    = '<h1>Money Doesn\'t Grow On Trees</h1>';
    public const TEST_DOMAIN     = 'phalcon.io';
    public const TEST_IP_IPV6    = '2a00:8640:1::224:36ff:feef:1d89';
    public const TEST_IP_ONE     = '10.4.6.1';
    public const TEST_IP_TWO     = '10.4.6.2';
    public const TEST_IP_THREE   = '10.4.6.3';
    public const TEST_IP_MULTI   = '10.4.6.4,10.4.6.5';
    public const TEST_URI        = 'https://phalcon.io';
    public const TEST_USER_AGENT = 'Chrome/Other 1.0.0';
}
