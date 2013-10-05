
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you may
 * prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled with UTF-8 support.
 *
 *<code>
 *	$escaper = new Phalcon\Escaper();
 *	$escaped = $escaper->escapeCss("font-family: <Verdana>");
 *	echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *</code>
 */
class Escaper //implements Phalcon\EscaperInterface
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
	 *
	 * @param string encoding
	 */
	public function setEncoding(string encoding)
	{
		let this->_encoding = encoding;
	}

	/**
	 * Returns the internal encoding used by the escaper
	 *
	 * @return string
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
	 *
	 * @param int quoteType
	 */
	public function setHtmlQuoteType(int quoteType)
	{
		let this->_htmlQuoteType = quoteType;
	}

}
