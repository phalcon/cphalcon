
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
    const STATUS_CONTINUE                        = 100;
    const STATUS_SWITCHING_PROTOCOLS             = 101;
    const STATUS_PROCESSING                      = 102;
    const STATUS_EARLY_HINTS                     = 103;

    // Successful 2xx
    const STATUS_OK                              = 200;
    const STATUS_CREATED                         = 201;
    const STATUS_ACCEPTED                        = 202;
    const STATUS_NON_AUTHORITATIVE_INFORMATION   = 203;
    const STATUS_NO_CONTENT                      = 204;
    const STATUS_RESET_CONTENT                   = 205;
    const STATUS_PARTIAL_CONTENT                 = 206;
    const STATUS_MULTI_STATUS                    = 207;
    const STATUS_ALREADY_REPORTED                = 208;
    const STATUS_IM_USED                         = 226;

    // Redirection 3xx
    const STATUS_MULTIPLE_CHOICES                = 300;
    const STATUS_MOVED_PERMANENTLY               = 301;
    const STATUS_FOUND                           = 302;
    const STATUS_SEE_OTHER                       = 303;
    const STATUS_NOT_MODIFIED                    = 304;
    const STATUS_USE_PROXY                       = 305;
    const STATUS_RESERVED                        = 306;
    const STATUS_TEMPORARY_REDIRECT              = 307;
    const STATUS_PERMANENT_REDIRECT              = 308;

    // Client Errors 4xx
    const STATUS_BAD_REQUEST                     = 400;
    const STATUS_UNAUTHORIZED                    = 401;
    const STATUS_PAYMENT_REQUIRED                = 402;
    const STATUS_FORBIDDEN                       = 403;
    const STATUS_NOT_FOUND                       = 404;
    const STATUS_METHOD_NOT_ALLOWED              = 405;
    const STATUS_NOT_ACCEPTABLE                  = 406;
    const STATUS_PROXY_AUTHENTICATION_REQUIRED   = 407;
    const STATUS_REQUEST_TIMEOUT                 = 408;
    const STATUS_CONFLICT                        = 409;
    const STATUS_GONE                            = 410;
    const STATUS_LENGTH_REQUIRED                 = 411;
    const STATUS_PRECONDITION_FAILED             = 412;
    const STATUS_PAYLOAD_TOO_LARGE               = 413;
    const STATUS_URI_TOO_LONG                    = 414;
    const STATUS_UNSUPPORTED_MEDIA_TYPE          = 415;
    const STATUS_RANGE_NOT_SATISFIABLE           = 416;
    const STATUS_EXPECTATION_FAILED              = 417;
    const STATUS_IM_A_TEAPOT                     = 418;
    const STATUS_MISDIRECTED_REQUEST             = 421;
    const STATUS_UNPROCESSABLE_ENTITY            = 422;
    const STATUS_LOCKED                          = 423;
    const STATUS_FAILED_DEPENDENCY               = 424;
    const STATUS_TOO_EARLY                       = 425;
    const STATUS_UPGRADE_REQUIRED                = 426;
    const STATUS_PRECONDITION_REQUIRED           = 428;
    const STATUS_TOO_MANY_REQUESTS               = 429;
    const STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE = 431;
    const STATUS_UNAVAILABLE_FOR_LEGAL_REASONS   = 451;

    // Server Errors 5xx
    const STATUS_INTERNAL_SERVER_ERROR           = 500;
    const STATUS_NOT_IMPLEMENTED                 = 501;
    const STATUS_BAD_GATEWAY                     = 502;
    const STATUS_SERVICE_UNAVAILABLE             = 503;
    const STATUS_GATEWAY_TIMEOUT                 = 504;
    const STATUS_VERSION_NOT_SUPPORTED           = 505;
    const STATUS_VARIANT_ALSO_NEGOTIATES         = 506;
    const STATUS_INSUFFICIENT_STORAGE            = 507;
    const STATUS_LOOP_DETECTED                   = 508;
    const STATUS_NOT_EXTENDED                    = 510;
    const STATUS_NETWORK_AUTHENTICATION_REQUIRED = 511;

    // Unofficial
    const STATUS_THIS_IS_FINE                         = 218; // Unofficial - Apache Web Server
    const STATUS_PAGE_EXPIRED                         = 419; // Unofficial - Laravel Framework
    const STATUS_METHOD_FAILURE                       = 420; // Unofficial - Spring Framework
    const STATUS_LOGIN_TIMEOUT                        = 440; // Unofficial - IIS
    const STATUS_NO_RESPONSE                          = 444; // Unofficial - nginx
    const STATUS_RETRY_WITH                           = 449; // Unofficial - IIS
    const STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS = 450; // Unofficial - nginx
    const STATUS_REQUEST_HEADER_TOO_LARGE             = 494; // Unofficial - nginx
    const STATUS_SSL_CERTIFICATE_ERROR                = 495; // Unofficial - nginx
    const STATUS_SSL_CERTIFICATE_REQUIRED             = 496; // Unofficial - nginx
    const STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT      = 497; // Unofficial - nginx
    const STATUS_INVALID_TOKEN_ESRI                   = 498; // Unofficial - ESRI
    const STATUS_CLIENT_CLOSED_REQUEST                = 499; // Unofficial - nginx
    const STATUS_BANDWIDTH_LIMIT_EXCEEDED             = 509; // Unofficial - Apache/cPanel
    const STATUS_UNKNOWN_ERROR                        = 520; // Unofficial - Cloudflare
    const STATUS_WEB_SERVER_IS_DOWN                   = 521; // Unofficial - Cloudflare
    const STATUS_CONNECTION_TIMEOUT                   = 522; // Unofficial - Cloudflare
    const STATUS_ORIGIN_IS_UNREACHABLE                = 523; // Unofficial - Cloudflare
    const STATUS_TIMEOUT_OCCURRED                     = 524; // Unofficial - Cloudflare
    const STATUS_SSL_HANDSHAKE_FAILED                 = 525; // Unofficial - Cloudflare
    const STATUS_INVALID_SSL_CERTIFICATE              = 526; // Unofficial - Cloudflare
    const STATUS_RAILGUN_ERROR                        = 527; // Unofficial - Cloudflare
    const STATUS_ORIGIN_DNS_ERROR                     = 530; // Unofficial - Cloudflare
    const STATUS_NETWORK_READ_TIMEOUT_ERROR           = 598; // Unofficial
    const STATUS_NETWORK_CONNECT_TIMEOUT_ERROR        = 599; // Unofficial
}
