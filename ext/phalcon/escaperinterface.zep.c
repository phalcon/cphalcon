
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
/**
 * Phalcon\EscaperInterface
 *
 * Interface for Phalcon\Escaper
 */
ZEPHIR_INIT_CLASS(Phalcon_EscaperInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, EscaperInterface, phalcon, escaperinterface, phalcon_escaperinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the encoding to be used by the escaper
 *
 * @param string encoding
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, setEncoding);

/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, getEncoding);

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 * @param int quoteType
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, setHtmlQuoteType);

/**
 * Escapes a HTML string
 *
 * @param string text
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, escapeHtml);

/**
 * Escapes a HTML attribute string
 *
 * @param string text
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, escapeHtmlAttr);

/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
 *
 * @param string css
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, escapeCss);

/**
 * Escape Javascript strings by replacing non-alphanumeric chars by their hexadecimal representation
 *
 * @param string js
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, escapeJs);

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string url
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_EscaperInterface, escapeUrl);

