
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
 * An evolvable link provider value object.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Interfaces_EvolvableLinkProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Link\\Interfaces, EvolvableLinkProviderInterface, phalcon, html_link_interfaces_evolvablelinkproviderinterface, phalcon_html_link_interfaces_evolvablelinkproviderinterface_method_entry);

	zend_class_implements(phalcon_html_link_interfaces_evolvablelinkproviderinterface_ce, 1, phalcon_html_link_interfaces_linkproviderinterface_ce);
	return SUCCESS;
}

/**
 * Returns an instance with the specified link included.
 *
 * If the specified link is already present, this method MUST return
 * normally without errors. The link is present if $link is === identical
 * to a link object already in the collection.
 *
 * @param LinkInterface $link A link object that should be included in this collection.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkProviderInterface, withLink);
/**
 * Returns an instance with the specifed link removed.
 *
 * If the specified link is not present, this method MUST return normally
 * without errors. The link is present if $link is === identical to a link
 * object already in the collection.
 *
 * @param LinkInterface $link The link to remove.
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_EvolvableLinkProviderInterface, withoutLink);
