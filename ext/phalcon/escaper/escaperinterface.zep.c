
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Escaper
 */
ZEPHIR_INIT_CLASS(Phalcon_Escaper_EscaperInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Escaper, EscaperInterface, phalcon, escaper_escaperinterface, phalcon_escaper_escaperinterface_method_entry);

	return SUCCESS;

}

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their
 * hexadecimal representation
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, escapeCss);
/**
 * Escapes a HTML string
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, escapeHtml);
/**
 * Escapes a HTML attribute string
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, escapeHtmlAttr);
/**
 * Escape Javascript strings by replacing non-alphanumeric chars by their
 * hexadecimal representation
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, escapeJs);
/**
 * Escapes a URL. Internally uses rawurlencode
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, escapeUrl);
/**
 * Returns the internal encoding used by the escaper
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, getEncoding);
/**
 * Sets the encoding to be used by the escaper
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, setEncoding);
/**
 * Sets the HTML quoting type for htmlspecialchars
 */
ZEPHIR_DOC_METHOD(Phalcon_Escaper_EscaperInterface, setHtmlQuoteType);
