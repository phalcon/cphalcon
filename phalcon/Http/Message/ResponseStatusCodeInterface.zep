
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Message;

/**
 * Interface for Request methods
 *
 * Implementation of this file has been influenced by PHP FIG
 * @link    https://github.com/php-fig/http-message-util/
 * @license https://github.com/php-fig/http-message-util/blob/master/LICENSE
 *
 * Defines constants for common HTTP status code.
 *
 * @see https://tools.ietf.org/html/rfc2295#section-8.1
 * @see https://tools.ietf.org/html/rfc2324#section-2.3
 * @see https://tools.ietf.org/html/rfc2518#section-9.7
 * @see https://tools.ietf.org/html/rfc2774#section-7
 * @see https://tools.ietf.org/html/rfc3229#section-10.4
 * @see https://tools.ietf.org/html/rfc4918#section-11
 * @see https://tools.ietf.org/html/rfc5842#section-7.1
 * @see https://tools.ietf.org/html/rfc5842#section-7.2
 * @see https://tools.ietf.org/html/rfc6585#section-3
 * @see https://tools.ietf.org/html/rfc6585#section-4
 * @see https://tools.ietf.org/html/rfc6585#section-5
 * @see https://tools.ietf.org/html/rfc6585#section-6
 * @see https://tools.ietf.org/html/rfc7231#section-6
 * @see https://tools.ietf.org/html/rfc7238#section-3
 * @see https://tools.ietf.org/html/rfc7725#section-3
 * @see https://tools.ietf.org/html/rfc7540#section-9.1.2
 * @see https://tools.ietf.org/html/rfc8297#section-2
 * @see https://tools.ietf.org/html/rfc8470#section-7
 */
interface ResponseStatusCodeInterface
{
    // Informational 1xx
    /**
     * @var int
     */
    const STATUS_CONTINUE                        = 100;
    /**
     * @var int
     */
    const STATUS_SWITCHING_PROTOCOLS             = 101;
    /**
     * @var int
     */
    const STATUS_PROCESSING                      = 102;
    /**
     * @var int
     */
    const STATUS_EARLY_HINTS                     = 103;

    // Successful 2xx
    /**
     * @var int
     */
    const STATUS_OK                              = 200;
    /**
     * @var int
     */
    const STATUS_CREATED                         = 201;
    /**
     * @var int
     */
    const STATUS_ACCEPTED                        = 202;
    /**
     * @var int
     */
    const STATUS_NON_AUTHORITATIVE_INFORMATION   = 203;
    /**
     * @var int
     */
    const STATUS_NO_CONTENT                      = 204;
    /**
     * @var int
     */
    const STATUS_RESET_CONTENT                   = 205;
    /**
     * @var int
     */
    const STATUS_PARTIAL_CONTENT                 = 206;
    /**
     * @var int
     */
    const STATUS_MULTI_STATUS                    = 207;
    /**
     * @var int
     */
    const STATUS_ALREADY_REPORTED                = 208;
    /**
     * @var int
     */
    const STATUS_IM_USED                         = 226;

    // Redirection 3xx
    /**
     * @var int
     */
    const STATUS_MULTIPLE_CHOICES                = 300;
    /**
     * @var int
     */
    const STATUS_MOVED_PERMANENTLY               = 301;
    /**
     * @var int
     */
    const STATUS_FOUND                           = 302;
    /**
     * @var int
     */
    const STATUS_SEE_OTHER                       = 303;
    /**
     * @var int
     */
    const STATUS_NOT_MODIFIED                    = 304;
    /**
     * @var int
     */
    const STATUS_USE_PROXY                       = 305;
    /**
     * @var int
     */
    const STATUS_RESERVED                        = 306;
    /**
     * @var int
     */
    const STATUS_TEMPORARY_REDIRECT              = 307;
    /**
     * @var int
     */
    const STATUS_PERMANENT_REDIRECT              = 308;

    // Client Errors 4xx
    /**
     * @var int
     */
    const STATUS_BAD_REQUEST                     = 400;
    /**
     * @var int
     */
    const STATUS_UNAUTHORIZED                    = 401;
    /**
     * @var int
     */
    const STATUS_PAYMENT_REQUIRED                = 402;
    /**
     * @var int
     */
    const STATUS_FORBIDDEN                       = 403;
    /**
     * @var int
     */
    const STATUS_NOT_FOUND                       = 404;
    /**
     * @var int
     */
    const STATUS_METHOD_NOT_ALLOWED              = 405;
    /**
     * @var int
     */
    const STATUS_NOT_ACCEPTABLE                  = 406;
    /**
     * @var int
     */
    const STATUS_PROXY_AUTHENTICATION_REQUIRED   = 407;
    /**
     * @var int
     */
    const STATUS_REQUEST_TIMEOUT                 = 408;
    /**
     * @var int
     */
    const STATUS_CONFLICT                        = 409;
    /**
     * @var int
     */
    const STATUS_GONE                            = 410;
    /**
     * @var int
     */
    const STATUS_LENGTH_REQUIRED                 = 411;
    /**
     * @var int
     */
    const STATUS_PRECONDITION_FAILED             = 412;
    /**
     * @var int
     */
    const STATUS_PAYLOAD_TOO_LARGE               = 413;
    /**
     * @var int
     */
    const STATUS_URI_TOO_LONG                    = 414;
    /**
     * @var int
     */
    const STATUS_UNSUPPORTED_MEDIA_TYPE          = 415;
    /**
     * @var int
     */
    const STATUS_RANGE_NOT_SATISFIABLE           = 416;
    /**
     * @var int
     */
    const STATUS_EXPECTATION_FAILED              = 417;
    /**
     * @var int
     */
    const STATUS_IM_A_TEAPOT                     = 418;
    /**
     * @var int
     */
    const STATUS_MISDIRECTED_REQUEST             = 421;
    /**
     * @var int
     */
    const STATUS_UNPROCESSABLE_ENTITY            = 422;
    /**
     * @var int
     */
    const STATUS_LOCKED                          = 423;
    /**
     * @var int
     */
    const STATUS_FAILED_DEPENDENCY               = 424;
    /**
     * @var int
     */
    const STATUS_TOO_EARLY                       = 425;
    /**
     * @var int
     */
    const STATUS_UPGRADE_REQUIRED                = 426;
    /**
     * @var int
     */
    const STATUS_PRECONDITION_REQUIRED           = 428;
    /**
     * @var int
     */
    const STATUS_TOO_MANY_REQUESTS               = 429;
    /**
     * @var int
     */
    const STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE = 431;
    /**
     * @var int
     */
    const STATUS_UNAVAILABLE_FOR_LEGAL_REASONS   = 451;

    // Server Errors 5xx
    /**
     * @var int
     */
    const STATUS_INTERNAL_SERVER_ERROR           = 500;
    /**
     * @var int
     */
    const STATUS_NOT_IMPLEMENTED                 = 501;
    /**
     * @var int
     */
    const STATUS_BAD_GATEWAY                     = 502;
    /**
     * @var int
     */
    const STATUS_SERVICE_UNAVAILABLE             = 503;
    /**
     * @var int
     */
    const STATUS_GATEWAY_TIMEOUT                 = 504;
    /**
     * @var int
     */
    const STATUS_VERSION_NOT_SUPPORTED           = 505;
    /**
     * @var int
     */
    const STATUS_VARIANT_ALSO_NEGOTIATES         = 506;
    /**
     * @var int
     */
    const STATUS_INSUFFICIENT_STORAGE            = 507;
    /**
     * @var int
     */
    const STATUS_LOOP_DETECTED                   = 508;
    /**
     * @var int
     */
    const STATUS_NOT_EXTENDED                    = 510;
    /**
     * @var int
     */
    const STATUS_NETWORK_AUTHENTICATION_REQUIRED = 511;

    // Unofficial
    /**
     * @var int
     */
    const STATUS_THIS_IS_FINE                         = 218; // Unofficial - Apache Web Server
    /**
     * @var int
     */
    const STATUS_PAGE_EXPIRED                         = 419; // Unofficial - Laravel Framework
    /**
     * @var int
     */
    const STATUS_METHOD_FAILURE                       = 420; // Unofficial - Spring Framework
    /**
     * @var int
     */
    const STATUS_LOGIN_TIMEOUT                        = 440; // Unofficial - IIS
    /**
     * @var int
     */
    const STATUS_NO_RESPONSE                          = 444; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_RETRY_WITH                           = 449; // Unofficial - IIS
    /**
     * @var int
     */
    const STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS = 450; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_REQUEST_HEADER_TOO_LARGE             = 494; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_SSL_CERTIFICATE_ERROR                = 495; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_SSL_CERTIFICATE_REQUIRED             = 496; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT      = 497; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_INVALID_TOKEN_ESRI                   = 498; // Unofficial - ESRI
    /**
     * @var int
     */
    const STATUS_CLIENT_CLOSED_REQUEST                = 499; // Unofficial - nginx
    /**
     * @var int
     */
    const STATUS_BANDWIDTH_LIMIT_EXCEEDED             = 509; // Unofficial - Apache/cPanel
    /**
     * @var int
     */
    const STATUS_UNKNOWN_ERROR                        = 520; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_WEB_SERVER_IS_DOWN                   = 521; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_CONNECTION_TIMEOUT                   = 522; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_ORIGIN_IS_UNREACHABLE                = 523; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_TIMEOUT_OCCURRED                     = 524; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_SSL_HANDSHAKE_FAILED                 = 525; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_INVALID_SSL_CERTIFICATE              = 526; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_RAILGUN_ERROR                        = 527; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_ORIGIN_DNS_ERROR                     = 530; // Unofficial - Cloudflare
    /**
     * @var int
     */
    const STATUS_NETWORK_READ_TIMEOUT_ERROR           = 598; // Unofficial
    /**
     * @var int
     */
    const STATUS_NETWORK_CONNECT_TIMEOUT_ERROR        = 599; // Unofficial
}
