
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
 * Interface for Phalcon\Acl\Component
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_ComponentInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, ComponentInterface, phalcon, acl_componentinterface, phalcon_acl_componentinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns component description
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ComponentInterface, getDescription);
/**
 * Returns the component name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ComponentInterface, getName);
/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ComponentInterface, __toString);
