
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
	public function setEncoding(encoding);

	/**
	 * Returns the internal encoding used by the escaper
	 *
	 * @return string
	 */
	public function getEncoding();

	/**
     * Sets the HTML quoting type for htmlspecialchars
     *
     * @param int quoteType
     */
	public function setHtmlQuoteType(quoteType);

	/**
     * Escapes a HTML string
     *
     * @param string text
     * @return string
     */
	public function escapeHtml(text);

	/**
     * Escapes a HTML attribute string
     *
     * @param string text
     * @return string
     */
	public function escapeHtmlAttr(text);

	/**
	 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
	 *
	 * @param string css
	 * @return string
	 */
	public function escapeCss(css);

	/**
	 * Escape Javascript strings by replacing non-alphanumeric chars by their hexadecimal representation
	 *
	 * @param string js
	 * @return string
	 */
	public function escapeJs(js);

	/**
     * Escapes a URL. Internally uses rawurlencode
     *
     * @param string url
     * @return string
     */
	public function escapeUrl(url);
}
