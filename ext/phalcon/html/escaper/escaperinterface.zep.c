
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
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Interface for Phalcon\Html\Escaper.
 *
 * This declares the stable context-escaping surface. The concrete
 * {@see \Phalcon\Html\Escaper} facade also exposes members that are not part
 * of this contract - `setDoubleEncode()`, `getFlags()`, and the per-context
 * sub-escaper getters/setters (`getHtmlEscaper()`, `setAttributeEscaper()`,
 * and the rest). Type against the concrete class to reach those.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_EscaperInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Escaper, EscaperInterface, phalcon, html_escaper_escaperinterface, phalcon_html_escaper_escaperinterface_method_entry);

	return SUCCESS;
}

/**
 * Escapes a HTML attribute string.
 *
 * The concrete {@see \Phalcon\Html\Escaper} also accepts an array of
 * attribute pairs and tolerates `null`: an array is rendered as escaped
 * `key="value"` pairs, `null` and `false` values are skipped, and `true`
 * renders as a bare key. Callers typed against this interface pass a
 * string. The widened signature lands in the next major.
 *
 * @param string $input
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, attributes);
/**
 * Escape CSS strings by replacing non-alphanumeric chars by their
 * hexadecimal representation
 *
 * @param string $input
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, css);
/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, getEncoding);
/**
 * Escapes a HTML string.
 *
 * The concrete {@see \Phalcon\Html\Escaper} tolerates `null`, returning an
 * empty string for it. The nullable signature lands in the next major.
 *
 * @param string $input
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, html);
/**
 * Escape Javascript strings by replacing non-alphanumeric chars by their
 * hexadecimal representation
 *
 * @param string $input
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, js);
/**
 * Sets the encoding to be used by the escaper
 *
 * @param string $encoding
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, setEncoding);
/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 * @param int $flags
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, setFlags);
/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $input
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Escaper_EscaperInterface, url);
