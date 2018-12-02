
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

namespace Phalcon;

/**
 * Phalcon\EscaperInterface
 *
 * Interface for Phalcon\Escaper
 */
interface EscaperInterface
{

	/**
	 * Sets the encoding to be used by the escaper
	 *
	 * @param string encoding
	 */
	public function setEncoding(string encoding) -> void;

	/**
	 * Returns the internal encoding used by the escaper
	 *
	 * @return string
	 */
	public function getEncoding() -> string;

	/**
	 * Sets the HTML quoting type for htmlspecialchars
	 *
	 * @param int quoteType
	 */
	public function setHtmlQuoteType(int quoteType) -> void;

	/**
	 * Escapes a HTML string
	 *
	 * @param string text
	 * @return string
	 */
	public function escapeHtml(string text) -> string;

	/**
	 * Escapes a HTML attribute string
	 *
	 * @param string text
	 * @return string
	 */
	public function escapeHtmlAttr(string text) -> string;

	/**
	 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
	 *
	 * @param string css
	 * @return string
	 */
	public function escapeCss(string css) -> string;

	/**
	 * Escape Javascript strings by replacing non-alphanumeric chars by their hexadecimal representation
	 *
	 * @param string js
	 * @return string
	 */
	public function escapeJs(string js) -> string;

	/**
	 * Escapes a URL. Internally uses rawurlencode
	 *
	 * @param string url
	 * @return string
	 */
	public function escapeUrl(string url) -> string;
}
