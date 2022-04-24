
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Phalcon\Http\Link\Link
 *
 * @property array  attributes
 * @property string href
 * @property array  rels
 * @property bool   templated
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Link)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Link, Link, phalcon, html_link_link, phalcon_html_link_abstractlink_ce, phalcon_html_link_link_method_entry, 0);

	zend_class_implements(phalcon_html_link_link_ce, 1, phalcon_html_link_interfaces_linkinterface_ce);
	return SUCCESS;
}

/**
 * Returns a list of attributes that describe the target URI.
 *
 * @return array
 *   A key-value list of attributes, where the key is a string and the value
 *  is either a PHP primitive or an array of PHP strings. If no values are
 *  found an empty array MUST be returned.
 */
PHP_METHOD(Phalcon_Html_Link_Link, getAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dogetattributes", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the target of the link.
 *
 * The target link must be one of:
 * - An absolute URI, as defined by RFC 5988.
 * - A relative URI, as defined by RFC 5988. The base of the relative link
 *     is assumed to be known based on context by the client.
 * - A URI template as defined by RFC 6570.
 *
 * If a URI template is returned, isTemplated() MUST return True.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Link_Link, getHref)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dogethref", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the relationship type(s) of the link.
 *
 * This method returns 0 or more relationship types for a link, expressed
 * as an array of strings.
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Html_Link_Link, getRels)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dogetrels", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns whether or not this is a templated link.
 *
 * @return bool True if this link object is templated, False otherwise.
 */
PHP_METHOD(Phalcon_Html_Link_Link, isTemplated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "doistemplated", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

