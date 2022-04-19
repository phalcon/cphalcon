
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
 * An evolvable link value object.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Link\\Interfaces, EvolvableLinkInterface, phalcon, html_link_interfaces_evolvablelinkinterface, phalcon_html_link_interfaces_evolvablelinkinterface_method_entry);

	zend_class_implements(phalcon_html_link_interfaces_evolvablelinkinterface_ce, 1, phalcon_html_link_interfaces_linkinterface_ce);
	return SUCCESS;
}

/**
 * Returns an instance with the specified href.
 *
 * @param string $href
 *       The href value to include.  It must be one of:
 *       - An absolute URI, as defined by RFC 5988.
 *       - A relative URI, as defined by RFC 5988. The base of the relative
 *       link is assumed to be known based on context by the client.
 *       - A URI template as defined by RFC 6570.
 *       - An object implementing __toString() that produces one of the
 *       above values.
 *
 * An implementing library SHOULD evaluate a passed object to a string
 * immediately rather than waiting for it to be returned later.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withHref);
/**
 * Returns an instance with the specified relationship included.
 *
 * If the specified rel is already present, this method MUST return
 * normally without errors, but without adding the rel a second time.
 *
 * @param string $rel The relationship value to add.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withRel);
/**
 * Returns an instance with the specified relationship excluded.
 *
 * If the specified rel is already not present, this method MUST return
 * normally without errors.
 *
 * @param string $rel The relationship value to exclude.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withoutRel);
/**
 * Returns an instance with the specified attribute added.
 *
 * If the specified attribute is already present, it will be overwritten
 * with the new value.
 *
 * @param string $attribute The attribute to include.
 * @param string $value     The value of the attribute to set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withAttribute);
/**
 * Returns an instance with the specified attribute excluded.
 *
 * If the specified attribute is not present, this method MUST return
 * normally without errors.
 *
 * @param string $attribute The attribute to remove.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withoutAttribute);
