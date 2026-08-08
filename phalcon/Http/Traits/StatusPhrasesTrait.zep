
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Nyholm/psr7 and Laminas
 *
 * @link    https://github.com/Nyholm/psr7
 * @license https://github.com/Nyholm/psr7/blob/master/LICENSE
 * @link    https://github.com/laminas/laminas-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Traits;

use Phalcon\Http\Message\ResponseStatusCodeInterface;

/**
 * Status Phrases trait
 */
trait StatusPhrasesTrait
{
    /**
     * Returns the list of status codes available
     *
     * @return string[]
     */
    protected function getPhrases() -> array
    {
        return [
            // Informational 1xx
            // Information - RFC 7231, 6.2.1
            ResponseStatusCodeInterface::STATUS_CONTINUE                             : "Continue",
            // Information - RFC 7231, 6.2.2
            ResponseStatusCodeInterface::STATUS_SWITCHING_PROTOCOLS                  : "Switching Protocols",
            // Information - RFC 2518, 10.1
            ResponseStatusCodeInterface::STATUS_PROCESSING                           : "Processing",
            ResponseStatusCodeInterface::STATUS_EARLY_HINTS                          : "Early Hints",

            // Successful 2xx
            // Success - RFC 7231, 6.3.1
            ResponseStatusCodeInterface::STATUS_OK                                   : "OK",
            // Success - RFC 7231, 6.3.2
            ResponseStatusCodeInterface::STATUS_CREATED                              : "Created",
            // Success - RFC 7231, 6.3.3
            ResponseStatusCodeInterface::STATUS_ACCEPTED                             : "Accepted",
            // Success - RFC 7231, 6.3.4
            ResponseStatusCodeInterface::STATUS_NON_AUTHORITATIVE_INFORMATION        : "Non-Authoritative Information",
            // Success - RFC 7231, 6.3.5
            ResponseStatusCodeInterface::STATUS_NO_CONTENT                           : "No Content",
            // Success - RFC 7231, 6.3.6
            ResponseStatusCodeInterface::STATUS_RESET_CONTENT                        : "Reset Content",
            // Success - RFC 7233, 4.1
            ResponseStatusCodeInterface::STATUS_PARTIAL_CONTENT                      : "Partial Content",
            // Success - RFC 4918, 11.1
            ResponseStatusCodeInterface::STATUS_MULTI_STATUS                         : "Multi-status",
            // Success - RFC 5842, 7.1
            ResponseStatusCodeInterface::STATUS_ALREADY_REPORTED                     : "Already Reported",
            // Success - RFC 3229, 10.4.1
            ResponseStatusCodeInterface::STATUS_IM_USED                              : "IM Used",

            // Redirection 3xx
            // Redirection - RFC 7231, 6.4.1
            ResponseStatusCodeInterface::STATUS_MULTIPLE_CHOICES                     : "Multiple Choices",
            // Redirection - RFC 7231, 6.4.2
            ResponseStatusCodeInterface::STATUS_MOVED_PERMANENTLY                    : "Moved Permanently",
            // Redirection - RFC 7231, 6.4.3
            ResponseStatusCodeInterface::STATUS_FOUND                                : "Found",
            // Redirection - RFC 7231, 6.4.4
            ResponseStatusCodeInterface::STATUS_SEE_OTHER                            : "See Other",
            // Redirection - RFC 7232, 4.1
            ResponseStatusCodeInterface::STATUS_NOT_MODIFIED                         : "Not Modified",
            // Redirection - RFC 7231, 6.4.5
            ResponseStatusCodeInterface::STATUS_USE_PROXY                            : "Use Proxy",
            // Redirection - RFC 7231, 6.4.6 (Deprecated)
            ResponseStatusCodeInterface::STATUS_RESERVED                             : "Switch Proxy",
            // Redirection - RFC 7231, 6.4.7
            ResponseStatusCodeInterface::STATUS_TEMPORARY_REDIRECT                   : "Temporary Redirect",
            // Redirection - RFC 7538, 3
            ResponseStatusCodeInterface::STATUS_PERMANENT_REDIRECT                   : "Permanent Redirect",

            // Client Errors 4xx
            // Client Error - RFC 7231, 6.5.1
            ResponseStatusCodeInterface::STATUS_BAD_REQUEST                          : "Bad Request",
            // Client Error - RFC 7235, 3.1
            ResponseStatusCodeInterface::STATUS_UNAUTHORIZED                         : "Unauthorized",
            // Client Error - RFC 7231, 6.5.2
            ResponseStatusCodeInterface::STATUS_PAYMENT_REQUIRED                     : "Payment Required",
            // Client Error - RFC 7231, 6.5.3
            ResponseStatusCodeInterface::STATUS_FORBIDDEN                            : "Forbidden",
            // Client Error - RFC 7231, 6.5.4
            ResponseStatusCodeInterface::STATUS_NOT_FOUND                            : "Not Found",
            // Client Error - RFC 7231, 6.5.5
            ResponseStatusCodeInterface::STATUS_METHOD_NOT_ALLOWED                   : "Method Not Allowed",
            // Client Error - RFC 7231, 6.5.6
            ResponseStatusCodeInterface::STATUS_NOT_ACCEPTABLE                       : "Not Acceptable",
            // Client Error - RFC 7235, 3.2
            ResponseStatusCodeInterface::STATUS_PROXY_AUTHENTICATION_REQUIRED        : "Proxy Authentication Required",
            // Client Error - RFC 7231, 6.5.7
            ResponseStatusCodeInterface::STATUS_REQUEST_TIMEOUT                      : "Request Time-out",
            // Client Error - RFC 7231, 6.5.8
            ResponseStatusCodeInterface::STATUS_CONFLICT                             : "Conflict",
            // Client Error - RFC 7231, 6.5.9
            ResponseStatusCodeInterface::STATUS_GONE                                 : "Gone",
            // Client Error - RFC 7231, 6.5.10
            ResponseStatusCodeInterface::STATUS_LENGTH_REQUIRED                      : "Length Required",
            // Client Error - RFC 7232, 4.2
            ResponseStatusCodeInterface::STATUS_PRECONDITION_FAILED                  : "Precondition Failed",
            // Client Error - RFC 7231, 6.5.11
            ResponseStatusCodeInterface::STATUS_PAYLOAD_TOO_LARGE                    : "Request Entity Too Large",
            // Client Error - RFC 7231, 6.5.12
            ResponseStatusCodeInterface::STATUS_URI_TOO_LONG                         : "Request-URI Too Large",
            // Client Error - RFC 7231, 6.5.13
            ResponseStatusCodeInterface::STATUS_UNSUPPORTED_MEDIA_TYPE               : "Unsupported Media Type",
            // Client Error - RFC 7233, 4.4
            ResponseStatusCodeInterface::STATUS_RANGE_NOT_SATISFIABLE                : "Requested range not satisfiable",
            // Client Error - RFC 7231, 6.5.14
            ResponseStatusCodeInterface::STATUS_EXPECTATION_FAILED                   : "Expectation Failed",
            // Client Error - RFC 7168, 2.3.3
            ResponseStatusCodeInterface::STATUS_IM_A_TEAPOT                          : "I'm a teapot",
            ResponseStatusCodeInterface::STATUS_MISDIRECTED_REQUEST                  : "Misdirected Request",
            // Client Error - RFC 4918, 11.2
            ResponseStatusCodeInterface::STATUS_UNPROCESSABLE_ENTITY                 : "Unprocessable Entity",
            // Client Error - RFC 4918, 11.3
            ResponseStatusCodeInterface::STATUS_LOCKED                               : "Locked",
            // Client Error - RFC 4918, 11.4
            ResponseStatusCodeInterface::STATUS_FAILED_DEPENDENCY                    : "Failed Dependency",
            ResponseStatusCodeInterface::STATUS_TOO_EARLY                            : "Unordered Collection",
            // Client Error - RFC 7231, 6.5.15
            ResponseStatusCodeInterface::STATUS_UPGRADE_REQUIRED                     : "Upgrade Required",
            // Client Error - RFC 6585, 3
            ResponseStatusCodeInterface::STATUS_PRECONDITION_REQUIRED                : "Precondition Required",
            // Client Error - RFC 6585, 4
            ResponseStatusCodeInterface::STATUS_TOO_MANY_REQUESTS                    : "Too Many Requests",
            // Client Error - RFC 6585, 5
            ResponseStatusCodeInterface::STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE      : "Request Header Fields Too Large",
            // Client Error - RFC 7725, 3
            ResponseStatusCodeInterface::STATUS_UNAVAILABLE_FOR_LEGAL_REASONS        : "Unavailable For Legal Reasons",

            // Server Errors 5xx
            // Server Error - RFC 7231, 6.6.1
            ResponseStatusCodeInterface::STATUS_INTERNAL_SERVER_ERROR                : "Internal Server Error",
            // Server Error - RFC 7231, 6.6.2
            ResponseStatusCodeInterface::STATUS_NOT_IMPLEMENTED                      : "Not Implemented",
            // Server Error - RFC 7231, 6.6.3
            ResponseStatusCodeInterface::STATUS_BAD_GATEWAY                          : "Bad Gateway",
            // Server Error - RFC 7231, 6.6.4
            ResponseStatusCodeInterface::STATUS_SERVICE_UNAVAILABLE                  : "Service Unavailable",
            // Server Error - RFC 7231, 6.6.5
            ResponseStatusCodeInterface::STATUS_GATEWAY_TIMEOUT                      : "Gateway Time-out",
            // Server Error - RFC 7231, 6.6.6
            ResponseStatusCodeInterface::STATUS_VERSION_NOT_SUPPORTED                : "HTTP Version not supported",
            // Server Error - RFC 2295, 8.1
            ResponseStatusCodeInterface::STATUS_VARIANT_ALSO_NEGOTIATES              : "Variant Also Negotiates",
            // Server Error - RFC 4918, 11.5
            ResponseStatusCodeInterface::STATUS_INSUFFICIENT_STORAGE                 : "Insufficient Storage",
            // Server Error - RFC 5842, 7.2
            ResponseStatusCodeInterface::STATUS_LOOP_DETECTED                        : "Loop Detected",
            // Server Error - RFC 2774, 7
            ResponseStatusCodeInterface::STATUS_NOT_EXTENDED                         : "Not Extended",
            // Server Error - RFC 6585, 6
            ResponseStatusCodeInterface::STATUS_NETWORK_AUTHENTICATION_REQUIRED      : "Network Authentication Required",

            // Unofficial
            // Unofficial - Apache Web Server
            ResponseStatusCodeInterface::STATUS_THIS_IS_FINE                         : "This is fine",
            // Unofficial - Laravel Framework
            ResponseStatusCodeInterface::STATUS_PAGE_EXPIRED                         : "Page Expired",
            // Unofficial - Spring Framework
            ResponseStatusCodeInterface::STATUS_METHOD_FAILURE                       : "Method Failure",
            // Unofficial - IIS
            ResponseStatusCodeInterface::STATUS_LOGIN_TIMEOUT                        : "Login Time-out",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_NO_RESPONSE                          : "No Response",
            // Unofficial - IIS
            ResponseStatusCodeInterface::STATUS_RETRY_WITH                           : "Retry With",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS : "Blocked by Windows Parental Controls (Microsoft)",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_REQUEST_HEADER_TOO_LARGE             : "Request header too large",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_SSL_CERTIFICATE_ERROR                : "SSL Certificate Error",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_SSL_CERTIFICATE_REQUIRED             : "SSL Certificate Required",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT      : "HTTP Request Sent to HTTPS Port",
            // Unofficial - ESRI
            ResponseStatusCodeInterface::STATUS_INVALID_TOKEN_ESRI                   : "Invalid Token (Esri)",
            // Unofficial - nginx
            ResponseStatusCodeInterface::STATUS_CLIENT_CLOSED_REQUEST                : "Client Closed Request",
            // Unofficial - Apache/cPanel
            ResponseStatusCodeInterface::STATUS_BANDWIDTH_LIMIT_EXCEEDED             : "Bandwidth Limit Exceeded",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_UNKNOWN_ERROR                        : "Unknown Error",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_WEB_SERVER_IS_DOWN                   : "Web Server Is Down",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_CONNECTION_TIMEOUT                   : "Connection Timed Out",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_ORIGIN_IS_UNREACHABLE                : "Origin Is Unreachable",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_TIMEOUT_OCCURRED                     : "A Timeout Occurred",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_SSL_HANDSHAKE_FAILED                 : "SSL Handshake Failed",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_INVALID_SSL_CERTIFICATE              : "Invalid SSL Certificate",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_RAILGUN_ERROR                        : "Railgun Error",
            // Unofficial - Cloudflare
            ResponseStatusCodeInterface::STATUS_ORIGIN_DNS_ERROR                     : "Origin DNS Error",
            // Unofficial
            ResponseStatusCodeInterface::STATUS_NETWORK_READ_TIMEOUT_ERROR           : "Network read timeout error",
            // Unofficial
            ResponseStatusCodeInterface::STATUS_NETWORK_CONNECT_TIMEOUT_ERROR        : "Network Connect Timeout Error"
        ];
    }
}
