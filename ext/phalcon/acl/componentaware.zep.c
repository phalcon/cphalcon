
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
 * Interface for classes which could be used in allow method as RESOURCE
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_ComponentAware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, ComponentAware, phalcon, acl_componentaware, phalcon_acl_componentaware_method_entry);

	return SUCCESS;
}

/**
 * Returns component name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_ComponentAware, getComponentName);
