
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
	 */
	public function setEncoding(string encoding);

	/**
	 * Returns the internal encoding used by the escaper
	 */
	public function getEncoding() -> string;

	/**
	 * Sets the HTML quoting type for htmlspecialchars
	 */
	public function setHtmlQuoteType(int quoteType);

	/**
	 * Escapes a HTML string
	 */
	public function escapeHtml(string text) -> string;

	/**
	 * Escapes a HTML attribute string
	 */
	public function escapeHtmlAttr(string text) -> string;

	/**
	 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
	 */
	public function escapeCss(string css) -> string;

	/**
	 * Escape Javascript strings by replacing non-alphanumeric chars by their hexadecimal representation
	 */
	public function escapeJs(string js) -> string;

	/**
	 * Escapes a URL. Internally uses rawurlencode
	 */
	public function escapeUrl(string url) -> string;
}
