
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
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Acl\ComponentAware} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_ComponentAwareInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, ComponentAwareInterface, phalcon, acl_componentawareinterface, NULL);

	zend_class_implements(phalcon_acl_componentawareinterface_ce, 1, phalcon_contracts_acl_componentaware_ce);
	return SUCCESS;
}

