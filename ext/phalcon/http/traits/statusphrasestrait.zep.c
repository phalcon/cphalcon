
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"


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
/**
 * Status Phrases trait
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Traits_StatusPhrasesTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Http\\Traits, StatusPhrasesTrait, phalcon, http_traits_statusphrasestrait, phalcon_http_traits_statusphrasestrait_method_entry);

	return SUCCESS;
}

/**
 * Returns the list of status codes available
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Http_Traits_StatusPhrasesTrait, getPhrases)
{

	zephir_create_array(return_value, 89, 0);
	add_index_stringl(return_value, 100, SL("Continue"));
	add_index_stringl(return_value, 101, SL("Switching Protocols"));
	add_index_stringl(return_value, 102, SL("Processing"));
	add_index_stringl(return_value, 103, SL("Early Hints"));
	add_index_stringl(return_value, 200, SL("OK"));
	add_index_stringl(return_value, 201, SL("Created"));
	add_index_stringl(return_value, 202, SL("Accepted"));
	add_index_stringl(return_value, 203, SL("Non-Authoritative Information"));
	add_index_stringl(return_value, 204, SL("No Content"));
	add_index_stringl(return_value, 205, SL("Reset Content"));
	add_index_stringl(return_value, 206, SL("Partial Content"));
	add_index_stringl(return_value, 207, SL("Multi-status"));
	add_index_stringl(return_value, 208, SL("Already Reported"));
	add_index_stringl(return_value, 226, SL("IM Used"));
	add_index_stringl(return_value, 300, SL("Multiple Choices"));
	add_index_stringl(return_value, 301, SL("Moved Permanently"));
	add_index_stringl(return_value, 302, SL("Found"));
	add_index_stringl(return_value, 303, SL("See Other"));
	add_index_stringl(return_value, 304, SL("Not Modified"));
	add_index_stringl(return_value, 305, SL("Use Proxy"));
	add_index_stringl(return_value, 306, SL("Switch Proxy"));
	add_index_stringl(return_value, 307, SL("Temporary Redirect"));
	add_index_stringl(return_value, 308, SL("Permanent Redirect"));
	add_index_stringl(return_value, 400, SL("Bad Request"));
	add_index_stringl(return_value, 401, SL("Unauthorized"));
	add_index_stringl(return_value, 402, SL("Payment Required"));
	add_index_stringl(return_value, 403, SL("Forbidden"));
	add_index_stringl(return_value, 404, SL("Not Found"));
	add_index_stringl(return_value, 405, SL("Method Not Allowed"));
	add_index_stringl(return_value, 406, SL("Not Acceptable"));
	add_index_stringl(return_value, 407, SL("Proxy Authentication Required"));
	add_index_stringl(return_value, 408, SL("Request Time-out"));
	add_index_stringl(return_value, 409, SL("Conflict"));
	add_index_stringl(return_value, 410, SL("Gone"));
	add_index_stringl(return_value, 411, SL("Length Required"));
	add_index_stringl(return_value, 412, SL("Precondition Failed"));
	add_index_stringl(return_value, 413, SL("Request Entity Too Large"));
	add_index_stringl(return_value, 414, SL("Request-URI Too Large"));
	add_index_stringl(return_value, 415, SL("Unsupported Media Type"));
	add_index_stringl(return_value, 416, SL("Requested range not satisfiable"));
	add_index_stringl(return_value, 417, SL("Expectation Failed"));
	add_index_stringl(return_value, 418, SL("I'm a teapot"));
	add_index_stringl(return_value, 421, SL("Misdirected Request"));
	add_index_stringl(return_value, 422, SL("Unprocessable Entity"));
	add_index_stringl(return_value, 423, SL("Locked"));
	add_index_stringl(return_value, 424, SL("Failed Dependency"));
	add_index_stringl(return_value, 425, SL("Unordered Collection"));
	add_index_stringl(return_value, 426, SL("Upgrade Required"));
	add_index_stringl(return_value, 428, SL("Precondition Required"));
	add_index_stringl(return_value, 429, SL("Too Many Requests"));
	add_index_stringl(return_value, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(return_value, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(return_value, 500, SL("Internal Server Error"));
	add_index_stringl(return_value, 501, SL("Not Implemented"));
	add_index_stringl(return_value, 502, SL("Bad Gateway"));
	add_index_stringl(return_value, 503, SL("Service Unavailable"));
	add_index_stringl(return_value, 504, SL("Gateway Time-out"));
	add_index_stringl(return_value, 505, SL("HTTP Version not supported"));
	add_index_stringl(return_value, 506, SL("Variant Also Negotiates"));
	add_index_stringl(return_value, 507, SL("Insufficient Storage"));
	add_index_stringl(return_value, 508, SL("Loop Detected"));
	add_index_stringl(return_value, 510, SL("Not Extended"));
	add_index_stringl(return_value, 511, SL("Network Authentication Required"));
	add_index_stringl(return_value, 218, SL("This is fine"));
	add_index_stringl(return_value, 419, SL("Page Expired"));
	add_index_stringl(return_value, 420, SL("Method Failure"));
	add_index_stringl(return_value, 440, SL("Login Time-out"));
	add_index_stringl(return_value, 444, SL("No Response"));
	add_index_stringl(return_value, 449, SL("Retry With"));
	add_index_stringl(return_value, 450, SL("Blocked by Windows Parental Controls (Microsoft)"));
	add_index_stringl(return_value, 494, SL("Request header too large"));
	add_index_stringl(return_value, 495, SL("SSL Certificate Error"));
	add_index_stringl(return_value, 496, SL("SSL Certificate Required"));
	add_index_stringl(return_value, 497, SL("HTTP Request Sent to HTTPS Port"));
	add_index_stringl(return_value, 498, SL("Invalid Token (Esri)"));
	add_index_stringl(return_value, 499, SL("Client Closed Request"));
	add_index_stringl(return_value, 509, SL("Bandwidth Limit Exceeded"));
	add_index_stringl(return_value, 520, SL("Unknown Error"));
	add_index_stringl(return_value, 521, SL("Web Server Is Down"));
	add_index_stringl(return_value, 522, SL("Connection Timed Out"));
	add_index_stringl(return_value, 523, SL("Origin Is Unreachable"));
	add_index_stringl(return_value, 524, SL("A Timeout Occurred"));
	add_index_stringl(return_value, 525, SL("SSL Handshake Failed"));
	add_index_stringl(return_value, 526, SL("Invalid SSL Certificate"));
	add_index_stringl(return_value, 527, SL("Railgun Error"));
	add_index_stringl(return_value, 530, SL("Origin DNS Error"));
	add_index_stringl(return_value, 598, SL("Network read timeout error"));
	add_index_stringl(return_value, 599, SL("Network Connect Timeout Error"));
	return;
}

