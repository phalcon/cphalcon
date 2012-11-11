
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\EscaperInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_EscaperInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon, EscaperInterface, escaperinterface, phalcon_escaperinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the encoding to be used by the escaper
 *
 * @param string $encoding
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, setEnconding);
/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, getEncoding);
/**
 * Sets the HTML quoting type for htmlspecialchars
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, setHtmlQuoteType);
/**
 * Escapes a HTML string
 *
 * @param string $text
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeHtml);
/**
 * Escapes a HTML attribute string
 *
 * @param string $text
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeHtmlAttr);
/**
 * Escape CSS strings by replacing non-alphanumeric chars by their hexadecimal representation
 *
 * @param string $css
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeCss);
/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $url
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeUrl);
