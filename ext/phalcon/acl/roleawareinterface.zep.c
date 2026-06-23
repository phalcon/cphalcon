
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
 * Interface for classes which could be used in allow method as ROLE
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Acl\RoleAware} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleAwareInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, RoleAwareInterface, phalcon, acl_roleawareinterface, NULL);

	zend_class_implements(phalcon_acl_roleawareinterface_ce, 1, phalcon_contracts_acl_roleaware_ce);
	return SUCCESS;
}

