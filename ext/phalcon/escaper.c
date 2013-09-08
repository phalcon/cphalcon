
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Escaper) {

	ZEPHIR_REGISTER_CLASS(Phalcon, phalcon, Escaper, escaper, phalcon_escaper_method_entry, 0);

	zend_declare_property_null(phalcon_escaper_ce, SL("_encoding"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_escaper_ce, SL("_htmlEscapeMap"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_long(phalcon_escaper_ce, SL("_htmlQuoteType"), 3, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the encoding to be used by the escaper
 *
 *<code>
 * $escaper->setEncoding('utf-8');
 *</code>
 *
 * @param string encoding
 */
PHP_METHOD(Phalcon_Escaper, setEncoding) {

	zval *encoding;

	zephir_fetch_params(0, 1, 0, &encoding);



	if (Z_TYPE_P(encoding) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_escaper_exception_ce, "The character set must be string");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_encoding"), encoding TSRMLS_CC);

}

/**
 * Returns the internal encoding used by the escaper
 *
 * @return string
 */
PHP_METHOD(Phalcon_Escaper, getEncoding) {


	RETURN_MEMBER(this_ptr, "_encoding");

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
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType) {

	zval *quoteType;

	zephir_fetch_params(0, 1, 0, &quoteType);



	if (Z_TYPE_P(quoteType) != IS_LONG) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_escaper_exception_ce, "The quoting type is not valid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_htmlQuoteType"), quoteType TSRMLS_CC);

}

