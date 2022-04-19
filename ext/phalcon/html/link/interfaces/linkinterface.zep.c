
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * A readable link object.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Interfaces_LinkInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Link\\Interfaces, LinkInterface, phalcon, html_link_interfaces_linkinterface, phalcon_html_link_interfaces_linkinterface_method_entry);

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
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkInterface, getAttributes);
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
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkInterface, getHref);
/**
 * Returns the relationship type(s) of the link.
 *
 * This method returns 0 or more relationship types for a link, expressed
 * as an array of strings.
 *
 * @return string[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkInterface, getRels);
/**
 * Returns whether this is a templated link.
 *
 * @return bool
 *   True if this link object is templated, False otherwise.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkInterface, isTemplated);
