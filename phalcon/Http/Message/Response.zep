
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\AbstractMessage;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use PsrExt\Http\Message\ResponseInterface;

/**
 * PSR-7 Response
 */
final class Response extends AbstractMessage implements ResponseInterface, ResponseStatusCodeInterface
{
    /**
     * Gets the response reason phrase associated with the status code.
     *
     * Because a reason phrase is not a required element in a response
     * status line, the reason phrase value MAY be empty. Implementations MAY
     * choose to return the default RFC 7231 recommended reason phrase (or
     * those
     * listed in the IANA HTTP Status Code Registry) for the response's
     * status code.
     *
     * @see http://tools.ietf.org/html/rfc7231#section-6
     * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
     *
     * @var string
     */
    protected reasonPhrase = "" { get };

    /**
     * Gets the response status code.
     *
     * The status code is a 3-digit integer result code of the server's attempt
     * to understand and satisfy the request.
     *
     * @var int
     */
    protected statusCode = 200 { get };

    /**
     * Response constructor.
     *
     * @param string $body
     * @param int    $code
     * @param array  $headers
     */
    public function __construct(var body = "php://memory", int code = 200, array headers = [])
    {
        this->processCode(code);

        let this->headers = this->processHeaders(headers),
            this->body    = this->processBody(body, "w+b");
    }

    /**
     * Return an instance with the specified status code and, optionally,
     * reason phrase.
     *
     * If no reason phrase is specified, implementations MAY choose to default
     * to the RFC 7231 or IANA recommended reason phrase for the response's
     * status code.
     *
     * This method MUST be implemented in such a way as to retain the
     * immutability of the message, and MUST return an instance that has the
     * updated status and reason phrase.
     *
     * @see http://tools.ietf.org/html/rfc7231#section-6
     * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
     *
     * @param int    $code
     * @param string $reasonPhrase
     *
     * @return Response
     */
    public function withStatus(var code, var reasonPhrase = "") -> <Response>
    {
        var newInstance;

        let newInstance = clone this;

        newInstance->processCode(code, reasonPhrase);

        return newInstance;
    }

    /**
     * Returns the list of status codes available
     */
    protected function getPhrases() -> array
    {
        return [
            // Informational 1xx
            self::STATUS_CONTINUE                             : "Continue",                                           // Information - RFC 7231, 6.2.1
            self::STATUS_SWITCHING_PROTOCOLS                  : "Switching Protocols",                                // Information - RFC 7231, 6.2.2
            self::STATUS_PROCESSING                           : "Processing",                                         // Information - RFC 2518, 10.1
            self::STATUS_EARLY_HINTS                          : "Early Hints",

            // Successful 2xx
            self::STATUS_OK                                   : "OK",                                               // Success - RFC 7231, 6.3.1
            self::STATUS_CREATED                              : "Created",                                          // Success - RFC 7231, 6.3.2
            self::STATUS_ACCEPTED                             : "Accepted",                                         // Success - RFC 7231, 6.3.3
            self::STATUS_NON_AUTHORITATIVE_INFORMATION        : "Non-Authoritative Information",                    // Success - RFC 7231, 6.3.4
            self::STATUS_NO_CONTENT                           : "No Content",                                       // Success - RFC 7231, 6.3.5
            self::STATUS_RESET_CONTENT                        : "Reset Content",                                    // Success - RFC 7231, 6.3.6
            self::STATUS_PARTIAL_CONTENT                      : "Partial Content",                                  // Success - RFC 7233, 4.1
            self::STATUS_MULTI_STATUS                         : "Multi-status",                                     // Success - RFC 4918, 11.1
            self::STATUS_ALREADY_REPORTED                     : "Already Reported",                                 // Success - RFC 5842, 7.1
            self::STATUS_IM_USED                              : "IM Used",                                          // Success - RFC 3229, 10.4.1

            // Redirection 3xx
            self::STATUS_MULTIPLE_CHOICES                     : "Multiple Choices",                                 // Redirection - RFC 7231, 6.4.1
            self::STATUS_MOVED_PERMANENTLY                    : "Moved Permanently",                                // Redirection - RFC 7231, 6.4.2
            self::STATUS_FOUND                                : "Found",                                            // Redirection - RFC 7231, 6.4.3
            self::STATUS_SEE_OTHER                            : "See Other",                                        // Redirection - RFC 7231, 6.4.4
            self::STATUS_NOT_MODIFIED                         : "Not Modified",                                     // Redirection - RFC 7232, 4.1
            self::STATUS_USE_PROXY                            : "Use Proxy",                                        // Redirection - RFC 7231, 6.4.5
            self::STATUS_RESERVED                             : "Switch Proxy",                                     // Redirection - RFC 7231, 6.4.6 (Deprecated)
            self::STATUS_TEMPORARY_REDIRECT                   : "Temporary Redirect",                               // Redirection - RFC 7231, 6.4.7
            self::STATUS_PERMANENT_REDIRECT                   : "Permanent Redirect",                               // Redirection - RFC 7538, 3

            // Client Errors 4xx
            self::STATUS_BAD_REQUEST                          : "Bad Request",                                      // Client Error - RFC 7231, 6.5.1
            self::STATUS_UNAUTHORIZED                         : "Unauthorized",                                     // Client Error - RFC 7235, 3.1
            self::STATUS_PAYMENT_REQUIRED                     : "Payment Required",                                 // Client Error - RFC 7231, 6.5.2
            self::STATUS_FORBIDDEN                            : "Forbidden",                                        // Client Error - RFC 7231, 6.5.3
            self::STATUS_NOT_FOUND                            : "Not Found",                                        // Client Error - RFC 7231, 6.5.4
            self::STATUS_METHOD_NOT_ALLOWED                   : "Method Not Allowed",                               // Client Error - RFC 7231, 6.5.5
            self::STATUS_NOT_ACCEPTABLE                       : "Not Acceptable",                                   // Client Error - RFC 7231, 6.5.6
            self::STATUS_PROXY_AUTHENTICATION_REQUIRED        : "Proxy Authentication Required",                    // Client Error - RFC 7235, 3.2
            self::STATUS_REQUEST_TIMEOUT                      : "Request Time-out",                                 // Client Error - RFC 7231, 6.5.7
            self::STATUS_CONFLICT                             : "Conflict",                                         // Client Error - RFC 7231, 6.5.8
            self::STATUS_GONE                                 : "Gone",                                             // Client Error - RFC 7231, 6.5.9
            self::STATUS_LENGTH_REQUIRED                      : "Length Required",                                  // Client Error - RFC 7231, 6.5.10
            self::STATUS_PRECONDITION_FAILED                  : "Precondition Failed",                              // Client Error - RFC 7232, 4.2
            self::STATUS_PAYLOAD_TOO_LARGE                    : "Request Entity Too Large",                         // Client Error - RFC 7231, 6.5.11
            self::STATUS_URI_TOO_LONG                         : "Request-URI Too Large",                            // Client Error - RFC 7231, 6.5.12
            self::STATUS_UNSUPPORTED_MEDIA_TYPE               : "Unsupported Media Type",                           // Client Error - RFC 7231, 6.5.13
            self::STATUS_RANGE_NOT_SATISFIABLE                : "Requested range not satisfiable",                  // Client Error - RFC 7233, 4.4
            self::STATUS_EXPECTATION_FAILED                   : "Expectation Failed",                               // Client Error - RFC 7231, 6.5.14
            self::STATUS_IM_A_TEAPOT                          : "I'm a teapot",                                     // Client Error - RFC 7168, 2.3.3
            self::STATUS_MISDIRECTED_REQUEST                  : "Misdirected Request",
            self::STATUS_UNPROCESSABLE_ENTITY                 : "Unprocessable Entity",                             // Client Error - RFC 4918, 11.2
            self::STATUS_LOCKED                               : "Locked",                                           // Client Error - RFC 4918, 11.3
            self::STATUS_FAILED_DEPENDENCY                    : "Failed Dependency",                                // Client Error - RFC 4918, 11.4
            self::STATUS_TOO_EARLY                            : "Unordered Collection",
            self::STATUS_UPGRADE_REQUIRED                     : "Upgrade Required",                                 // Client Error - RFC 7231, 6.5.15
            self::STATUS_PRECONDITION_REQUIRED                : "Precondition Required",                            // Client Error - RFC 6585, 3
            self::STATUS_TOO_MANY_REQUESTS                    : "Too Many Requests",                                // Client Error - RFC 6585, 4
            self::STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE      : "Request Header Fields Too Large",                  // Client Error - RFC 6585, 5
            self::STATUS_UNAVAILABLE_FOR_LEGAL_REASONS        : "Unavailable For Legal Reasons",                    // Client Error - RFC 7725, 3

            // Server Errors 5xx
            self::STATUS_INTERNAL_SERVER_ERROR                : "Internal Server Error",                            // Server Error - RFC 7231, 6.6.1
            self::STATUS_NOT_IMPLEMENTED                      : "Not Implemented",                                  // Server Error - RFC 7231, 6.6.2
            self::STATUS_BAD_GATEWAY                          : "Bad Gateway",                                      // Server Error - RFC 7231, 6.6.3
            self::STATUS_SERVICE_UNAVAILABLE                  : "Service Unavailable",                              // Server Error - RFC 7231, 6.6.4
            self::STATUS_GATEWAY_TIMEOUT                      : "Gateway Time-out",                                 // Server Error - RFC 7231, 6.6.5
            self::STATUS_VERSION_NOT_SUPPORTED                : "HTTP Version not supported",                       // Server Error - RFC 7231, 6.6.6
            self::STATUS_VARIANT_ALSO_NEGOTIATES              : "Variant Also Negotiates",                          // Server Error - RFC 2295, 8.1
            self::STATUS_INSUFFICIENT_STORAGE                 : "Insufficient Storage",                             // Server Error - RFC 4918, 11.5
            self::STATUS_LOOP_DETECTED                        : "Loop Detected",                                    // Server Error - RFC 5842, 7.2
            self::STATUS_NOT_EXTENDED                         : "Not Extended",                                     // Server Error - RFC 2774, 7
            self::STATUS_NETWORK_AUTHENTICATION_REQUIRED      : "Network Authentication Required",                  // Server Error - RFC 6585, 6

            // Unofficial
            self::STATUS_THIS_IS_FINE                         : "This is fine",                                     // Unofficial - Apache Web Server
            self::STATUS_PAGE_EXPIRED                         : "Page Expired",                                     // Unofficial - Laravel Framework
            self::STATUS_METHOD_FAILURE                       : "Method Failure",                                   // Unofficial - Spring Framework
            self::STATUS_LOGIN_TIMEOUT                        : "Login Time-out",                                   // Unofficial - IIS
            self::STATUS_NO_RESPONSE                          : "No Response",                                      // Unofficial - nginx
            self::STATUS_RETRY_WITH                           : "Retry With",                                       // Unofficial - IIS
            self::STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS : "Blocked by Windows Parental Controls (Microsoft)", // Unofficial - nginx
            self::STATUS_REQUEST_HEADER_TOO_LARGE             : "Request header too large",                         // Unofficial - nginx
            self::STATUS_SSL_CERTIFICATE_ERROR                : "SSL Certificate Error",                            // Unofficial - nginx
            self::STATUS_SSL_CERTIFICATE_REQUIRED             : "SSL Certificate Required",                         // Unofficial - nginx
            self::STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT      : "HTTP Request Sent to HTTPS Port",                  // Unofficial - nginx
            self::STATUS_INVALID_TOKEN_ESRI                   : "Invalid Token (Esri)",                             // Unofficial - ESRI
            self::STATUS_CLIENT_CLOSED_REQUEST                : "Client Closed Request",                            // Unofficial - nginx
            self::STATUS_BANDWIDTH_LIMIT_EXCEEDED             : "Bandwidth Limit Exceeded",                         // Unofficial - Apache/cPanel
            self::STATUS_UNKNOWN_ERROR                        : "Unknown Error",                                    // Unofficial - Cloudflare
            self::STATUS_WEB_SERVER_IS_DOWN                   : "Web Server Is Down",                               // Unofficial - Cloudflare
            self::STATUS_CONNECTION_TIMEOUT                   : "Connection Timed Out",                             // Unofficial - Cloudflare
            self::STATUS_ORIGIN_IS_UNREACHABLE                : "Origin Is Unreachable",                            // Unofficial - Cloudflare
            self::STATUS_TIMEOUT_OCCURRED                     : "A Timeout Occurred",                               // Unofficial - Cloudflare
            self::STATUS_SSL_HANDSHAKE_FAILED                 : "SSL Handshake Failed",                             // Unofficial - Cloudflare
            self::STATUS_INVALID_SSL_CERTIFICATE              : "Invalid SSL Certificate",                          // Unofficial - Cloudflare
            self::STATUS_RAILGUN_ERROR                        : "Railgun Error",                                    // Unofficial - Cloudflare
            self::STATUS_ORIGIN_DNS_ERROR                     : "Origin DNS Error",                                 // Unofficial - Cloudflare
            self::STATUS_NETWORK_READ_TIMEOUT_ERROR           : "Network read timeout error",                       // Unofficial
            self::STATUS_NETWORK_CONNECT_TIMEOUT_ERROR        : "Network Connect Timeout Error"                     // Unofficial
        ];
    }

    /**
     * Set a valid status code and phrase
     *
     * @param mixed $code
     * @param mixed $phrase
     */
    protected function processCode(var code, var phrase = "") -> void
    {
        var phrases;

        let phrases = this->getPhrases();

        this->checkCodeType(code);

        let code = (int) code;
        this->checkCodeValue(code);

        if unlikely typeof phrase !== "string" {
            throw new InvalidArgumentException("Invalid response reason");
        }

        if likely "" === phrase && isset phrases[code] {
            let phrase = phrases[code];
        }

        let this->statusCode   = code,
            this->reasonPhrase = phrase;
    }

    /**
     * Checks if a code is integer or string
     *
     * @param mixed $code
     */
    private function checkCodeType(var code) -> void
    {
        if unlikely (typeof code !== "int" && typeof code !== "string") {
            throw new InvalidArgumentException(
                "Invalid status code; it must be an integer or string"
            );
        }
    }

    /**
     * Checks if a code is integer or string
     *
     * @param int $code
     */
    private function checkCodeValue(int code) -> void
    {
        if (true !== this->isBetween(code, 100, 599)) {
            throw new InvalidArgumentException(
                "Invalid status code '" . code . "', (allowed values 100-599)"
            );
        }
    }

    /**
     * @todo Remove this when we get traits
     */
    private function isBetween(int value, int from, int to) -> bool
    {
        return value >= from && value <= to;
    }
}
