
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

use Phalcon\EscaperInterface;
use Phalcon\Escaper\Exception;

/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you may
 * prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled with UTF-8 support.
 *
 *<code>
 *	$escaper = new \Phalcon\Escaper();
 *	$escaped = $escaper->escapeCss("font-family: <Verdana>");
 *	echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *</code>
 */
class Escaper implements EscaperInterface
{

	protected _encoding = "utf-8";

	protected _htmlEscapeMap = null;

	protected _htmlQuoteType = 3;

	/**
	 * Sets the encoding to be used by the escaper
	 *
	 *<code>
	 * $escaper->setEncoding('utf-8');
	 *</code>
	 */
	public function setEncoding(string encoding) -> void
	{
		let this->_encoding = encoding;
	}

	/**
	 * Returns the internal encoding used by the escaper
	 */
	public function getEncoding() -> string
	{
		return this->_encoding;
	}

	/**
	 * Sets the HTML quoting type for htmlspecialchars
	 *
	 *<code>
	 * $escaper->setHtmlQuoteType(ENT_XHTML);
	 *</code>
	 */
	public function setHtmlQuoteType(int quoteType) -> void
	{
		let this->_htmlQuoteType = quoteType;
	}

	/**
	 * Detect the character encoding of a string to be handled by an encoder
	 * Special-handling for chr(172) and chr(128) to chr(159) which fail to be detected by mb_detect_encoding()
	 */
	public final function detectEncoding(string str) -> string | null
	{
		var charset;

		/**
		* Check if charset is ASCII or ISO-8859-1
		*/
		let charset = phalcon_is_basic_charset(str);
		if typeof charset == "string" {
			return charset;
		}

		/**
		* We require mbstring extension here
		*/
		if !function_exists("mb_detect_encoding") {
			return null;
		}

		/**
		 * Strict encoding detection with fallback to non-strict detection.
		 * Check encoding
		 */
		for charset in ["UTF-32", "UTF-8", "ISO-8859-1", "ASCII"] {
			if mb_detect_encoding(str, charset, true) {
				return charset;
			}
		}

		/**
		 * Fallback to global detection
		 */
		return mb_detect_encoding(str);
	}

	/**
	 * Utility to normalize a string's encoding to UTF-32.
	 */
	public final function normalizeEncoding(string str) -> string
	{
		/**
		 * mbstring is required here
		 */
		if !function_exists("mb_convert_encoding") {
			throw new Exception("Extension 'mbstring' is required");
		}

		/**
		 * Convert to UTF-32 (4 byte characters, regardless of actual number of bytes in
		 * the character).
		 */
		return mb_convert_encoding(str, "UTF-32", this->detectEncoding(str));
	}

	/**
	 * Escapes a HTML string. Internally uses htmlspecialchars
	 */
	public function escapeHtml(string text) -> string
	{
		return htmlspecialchars(text, this->_htmlQuoteType, this->_encoding);
	}

	/**
	 * Escapes a HTML attribute string
	 */
	public function escapeHtmlAttr(string attribute) -> string
	{
		return htmlspecialchars(attribute, ENT_QUOTES, this->_encoding);
	}

	/**
	 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
	 */
	public function escapeCss(string css) -> string
	{
		/**
		 * Normalize encoding to UTF-32
		 * Escape the string
		 */
		return phalcon_escape_css(this->normalizeEncoding(css));
	}

	/**
	 * Escape javascript strings by replacing non-alphanumeric chars by their hexadecimal escaped representation
	 */
	public function escapeJs(string js) -> string
	{
		/**
		 * Normalize encoding to UTF-32
		 * Escape the string
		 */
		return phalcon_escape_js(this->normalizeEncoding(js));
	}

	/**
	 * Escapes a URL. Internally uses rawurlencode
	 */
	public function escapeUrl(string url) -> string
	{
		return rawurlencode(url);
	}
}
