
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "escaperinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_escaperinterface_ce;

static const zend_function_entry phalcon_escaperinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setEncoding, arginfo_phalcon_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeCss, arginfo_phalcon_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeJs, arginfo_phalcon_escaperinterface_escapejs)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl)
	PHP_FE_END
};

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
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, setEncoding);

/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, getEncoding);

/**
 * Sets the HTML quoting type for htmlspecialchars
 *
 * @param int $quoteType
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
 * Escape Javascript strings by replacing non-alphanumeric chars by their hexadecimal representation
 *
 * @param string $js
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeJs);

/**
 * Escapes a URL. Internally uses rawurlencode
 *
 * @param string $url
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_EscaperInterface, escapeUrl);
