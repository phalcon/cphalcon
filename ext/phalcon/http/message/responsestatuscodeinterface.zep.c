
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_ResponseStatusCodeInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Message, ResponseStatusCodeInterface, phalcon, http_message_responsestatuscodeinterface, NULL);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_CONTINUE"), 100);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SWITCHING_PROTOCOLS"), 101);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PROCESSING"), 102);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_EARLY_HINTS"), 103);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_OK"), 200);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_CREATED"), 201);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_ACCEPTED"), 202);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NON_AUTHORITATIVE_INFORMATION"), 203);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NO_CONTENT"), 204);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_RESET_CONTENT"), 205);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PARTIAL_CONTENT"), 206);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_MULTI_STATUS"), 207);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_ALREADY_REPORTED"), 208);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_IM_USED"), 226);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_MULTIPLE_CHOICES"), 300);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_MOVED_PERMANENTLY"), 301);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_FOUND"), 302);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SEE_OTHER"), 303);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NOT_MODIFIED"), 304);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_USE_PROXY"), 305);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_RESERVED"), 306);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_TEMPORARY_REDIRECT"), 307);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PERMANENT_REDIRECT"), 308);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_BAD_REQUEST"), 400);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UNAUTHORIZED"), 401);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PAYMENT_REQUIRED"), 402);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_FORBIDDEN"), 403);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NOT_FOUND"), 404);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_METHOD_NOT_ALLOWED"), 405);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NOT_ACCEPTABLE"), 406);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PROXY_AUTHENTICATION_REQUIRED"), 407);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_REQUEST_TIMEOUT"), 408);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_CONFLICT"), 409);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_GONE"), 410);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_LENGTH_REQUIRED"), 411);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PRECONDITION_FAILED"), 412);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PAYLOAD_TOO_LARGE"), 413);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_URI_TOO_LONG"), 414);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UNSUPPORTED_MEDIA_TYPE"), 415);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_RANGE_NOT_SATISFIABLE"), 416);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_EXPECTATION_FAILED"), 417);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_IM_A_TEAPOT"), 418);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_MISDIRECTED_REQUEST"), 421);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UNPROCESSABLE_ENTITY"), 422);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_LOCKED"), 423);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_FAILED_DEPENDENCY"), 424);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_TOO_EARLY"), 425);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UPGRADE_REQUIRED"), 426);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PRECONDITION_REQUIRED"), 428);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_TOO_MANY_REQUESTS"), 429);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE"), 431);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UNAVAILABLE_FOR_LEGAL_REASONS"), 451);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_INTERNAL_SERVER_ERROR"), 500);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NOT_IMPLEMENTED"), 501);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_BAD_GATEWAY"), 502);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SERVICE_UNAVAILABLE"), 503);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_GATEWAY_TIMEOUT"), 504);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_VERSION_NOT_SUPPORTED"), 505);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_VARIANT_ALSO_NEGOTIATES"), 506);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_INSUFFICIENT_STORAGE"), 507);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_LOOP_DETECTED"), 508);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NOT_EXTENDED"), 510);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NETWORK_AUTHENTICATION_REQUIRED"), 511);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_THIS_IS_FINE"), 218);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_PAGE_EXPIRED"), 419);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_METHOD_FAILURE"), 420);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_LOGIN_TIMEOUT"), 440);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NO_RESPONSE"), 444);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_RETRY_WITH"), 449);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS"), 450);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_REQUEST_HEADER_TOO_LARGE"), 494);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SSL_CERTIFICATE_ERROR"), 495);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SSL_CERTIFICATE_REQUIRED"), 496);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT"), 497);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_INVALID_TOKEN_ESRI"), 498);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_CLIENT_CLOSED_REQUEST"), 499);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_BANDWIDTH_LIMIT_EXCEEDED"), 509);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_UNKNOWN_ERROR"), 520);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_WEB_SERVER_IS_DOWN"), 521);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_CONNECTION_TIMEOUT"), 522);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_ORIGIN_IS_UNREACHABLE"), 523);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_TIMEOUT_OCCURRED"), 524);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_SSL_HANDSHAKE_FAILED"), 525);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_INVALID_SSL_CERTIFICATE"), 526);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_RAILGUN_ERROR"), 527);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_ORIGIN_DNS_ERROR"), 530);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NETWORK_READ_TIMEOUT_ERROR"), 598);

	zephir_declare_class_constant_long(phalcon_http_message_responsestatuscodeinterface_ce, SL("STATUS_NETWORK_CONNECT_TIMEOUT_ERROR"), 599);

	return SUCCESS;
}

