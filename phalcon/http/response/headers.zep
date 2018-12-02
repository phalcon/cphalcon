
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http\Response;

use Phalcon\Http\Response\HeadersInterface;

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
class Headers implements HeadersInterface
{
	protected _headers = [];

	/**
	 * Sets a header to be sent at the end of the request
	 */
	public function set(string name, string value)
	{
		let this->_headers[name] = value;
	}

	/**
	 * Gets a header value from the internal bag
	 */
	public function get(string name) -> string | boolean
	{
		var headers, headerValue;
		let headers = this->_headers;

		if fetch headerValue, headers[name] {
			return headerValue;
		}

		return false;
	}

	/**
	 * Sets a raw header to be sent at the end of the request
	 */
	public function setRaw(string header)
	{
		let this->_headers[header] = null;
	}

	/**
	 * Removes a header to be sent at the end of the request
	 */
	public function remove(string header)
	{
		var headers;

		let headers = this->_headers;
		unset headers[header];
		let this->_headers = headers;
	}

	/**
	 * Sends the headers to the client
	 */
	public function send() -> boolean
	{
		var header, value;
		if !headers_sent() {
			for header, value in this->_headers {
				if value !== null {
					header(header . ": " . value, true);
				} else {
					if memstr(header, ":") || substr(header, 0, 5) == "HTTP/" {
						header(header, true);
					} else {
						header(header . ": ", true);
					}
				}
			}
			return true;
		}
		return false;
	}

	/**
	 * Reset set headers
	 */
	public function reset()
	{
		let this->_headers = [];
	}

	/**
	 * Returns the current headers as an array
	 */
	public function toArray() -> array
	{
		return this->_headers;
	}

	/**
	 * Restore a \Phalcon\Http\Response\Headers object
	 */
	public static function __set_state(array! data) -> <HeadersInterface>
	{
		var headers, key, value, dataHeaders;
		let headers = new self();
		if fetch dataHeaders, data["_headers"] {
			for key, value in dataHeaders {
				headers->set(key, value);
			}
		}
		return headers;
	}
}
