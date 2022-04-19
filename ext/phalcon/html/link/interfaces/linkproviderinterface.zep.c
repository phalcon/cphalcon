
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
 * A link provider object.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Interfaces_LinkProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Html\\Link\\Interfaces, LinkProviderInterface, phalcon, html_link_interfaces_linkproviderinterface, phalcon_html_link_interfaces_linkproviderinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns an array of LinkInterface objects.
 *
 * @return LinkInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkProviderInterface, getLinks);
/**
 * Returns an array of LinkInterface objects that have a specific
 * relationship.
 *
 * @return LinkInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Html_Link_Interfaces_LinkProviderInterface, getLinksByRel);
