
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http;

/**
 * Phalcon\Http\StatusCode
 *
 * Constants enumerating the HTTP status codes
 */
abstract class StatusCode
{
	// INFORMATIONAL CODES
	const INFO_CONTINUE = 100;
	const INFO_SWITCH_PROTOCOL = 101;
	const INFO_PROCESSING = 102;

	// SUCCESS CODES
	const SUCCESS_CREATED = 201;
	const SUCCESS_ACCEPTED = 202;
	const SUCCESS_NON_AUTHORATIVE_INFORMATION = 203;
	const SUCCESS_NO_CONTENT = 204;
	const SUCCESS_RESET_CONTENT = 205;
	const SUCCESS_PARTIAL_CONTENT = 206;
	const SUCCESS_MULTI_STATUS = 207;
	const SUCCESS_ALREADY_REPORTED = 208;

	// REDIRECTION CODES
	const REDIRECT_MULTIPLE_CHOICES = 300;
	const REDIRECT_MOVED_PERMANENTLY = 301;
	const REDIRECT_FOUND = 302;
	const REDIRECT_SEE_OTHER = 303;
	const REDIRECT_NOT_MODIFIED = 304;
	const REDIRECT_USE_PROXY = 305;
	const REDIRECT_SWITCH_PROXY = 306;
	const REDIRECT_TEMPORARY_REDIRECT = 307;

	// CLIENT ERROR
	const CLIENT_BAD_REQUEST = 400;
	const CLIENT_UNAUTHORIZED = 401;
	const CLIENT_PAYMENT_REQUIRED = 402;
	const CLIENT_FORBIDDEN = 403;
	const CLIENT_NOT_FOUND = 404;
	const CLIENT_METHOD_NOT_ALLOWED = 405;
	const CLIENT_NOT_ACCEPTABLE = 406;
	const CLIENT_PROXY_AUTHENTICATION_REQUIRED = 407;
	const CLIENT_REQUEST_TIMEOUT = 408;
	const CLIENT_CONFLICT = 409;
	const CLIENT_GONE = 410;
	const CLIENT_LENGTH_REQUIRED = 411;
	const CLIENT_PRECONDITION_FAILED = 412;
	const CLIENT_REQUEST_ENTITY_TOO_LARGE = 413;
	const CLIENT_REQUEST_URI_TOO_LONG = 414;
	const CLIENT_UNSUPPORTED_MEDIA_TYPE = 415;
	const CLIENT_REQUESTED_RANGE_NOT_SATISFIABLE = 416;
	const CLIENT_EXPECTATION_FAILED = 417;
	const CLIENT_I_AM_A_TEAPOT = 418;
	const CLIENT_POLICY_NOT_FULFILLED = 420;
	const CLIENT_BAD_MAPPING = 421;
	const CLIENT_UNPROCESSABLE_ENTITY = 422;
	const CLIENT_ENTITY_LOCKED = 423;
	const CLIENT_FAILED_DEPENDENCY = 424;
	const CLIENT_UNORDERED_COLLECTION = 425;
	const CLIENT_UPDATE_REQUIRED = 426;
	const CLIENT_PRECONDITION_REQUIRED = 428;
	const CLIENT_TOO_MANY_REQUESTS = 429;
	const CLIENT_REQUEST_HEADER_FIELDS_TOO_LARGE = 431;

	// SERVER ERROR
	const SERVER_INTERNAL_SERVER_ERROR = 500;
	const SERVER_NOT_IMPLEMENTED = 501;
	const SERVER_BAD_GATEWAY = 502;
	const SERVER_SERVICE_UNAVAILABLE = 503;
	const SERVER_GATEWAY_TIMEOUT = 504;
	const SERVER_HTTP_VERSION_NOT_SUPPORTED = 505;
	const SERVER_VARIANT_ALSO_NEGOTIATES = 506;
	const SERVER_INSUFFICIENT_STORAGE = 507;
	const SERVER_LOOP_DETECTED = 508;
	const SERVER_BANDWIDTH_LIMIT_EXCEEDED = 509;
	const SERVER_NOT_EXTENDED = 510;
	const SERVER_NETWORK_AUTHENTICATION_REQUIRED = 511;

	private static _messages;

	/**
	 * Get the reason phrase for a particular status code
	 *
	 * @param int statusCode
	 * @return string
	 */
	public static function getStatusText(int statusCode)
	{
		if typeof self::_messages != "array" {
			let self::_messages = [
				// INFORMATIONAL CODES
				100 : "Continue",
				101 : "Switching Protocols",
				102 : "Processing",
				// SUCCESS CODES
				200 : "OK",
				201 : "Created",
				202 : "Accepted",
				203 : "Non-Authoritative Information",
				204 : "No Content",
				205 : "Reset Content",
				206 : "Partial Content",
				207 : "Multi-status",
				208 : "Already Reported",
				// REDIRECTION CODES
				300 : "Multiple Choices",
				301 : "Moved Permanently",
				302 : "Found",
				303 : "See Other",
				304 : "Not Modified",
				305 : "Use Proxy",
				306 : "Switch Proxy", // Deprecated
				307 : "Temporary Redirect",
				// CLIENT ERROR
				400 : "Bad Request",
				401 : "Unauthorized",
				402 : "Payment Required",
				403 : "Forbidden",
				404 : "Not Found",
				405 : "Method Not Allowed",
				406 : "Not Acceptable",
				407 : "Proxy Authentication Required",
				408 : "Request Time-out",
				409 : "Conflict",
				410 : "Gone",
				411 : "Length Required",
				412 : "Precondition Failed",
				413 : "Request Entity Too Large",
				414 : "Request-URI Too Large",
				415 : "Unsupported Media Type",
				416 : "Requested range not satisfiable",
				417 : "Expectation Failed",
				418 : "I'm a teapot",
				422 : "Unprocessable Entity",
				423 : "Locked",
				424 : "Failed Dependency",
				425 : "Unordered Collection",
				426 : "Upgrade Required",
				428 : "Precondition Required",
				429 : "Too Many Requests",
				431 : "Request Header Fields Too Large",
				// SERVER ERROR
				500 : "Internal Server Error",
				501 : "Not Implemented",
				502 : "Bad Gateway",
				503 : "Service Unavailable",
				504 : "Gateway Time-out",
				505 : "HTTP Version not supported",
				506 : "Variant Also Negotiates",
				507 : "Insufficient Storage",
				508 : "Loop Detected",
				511 : "Network Authentication Required"
			];
		}

		if (array_key_exists(statusCode, self::_messages)) {
			return self::_messages[statusCode];
		}

		return null;
	}
}
