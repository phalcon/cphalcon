
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
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. They
 * are copied and re-implemented here because we need to support PHP 8.1.
 * Once we move to min 8.4 and packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
/**
 * [_IocContainerFactory_][] affords obtaining a new instance of
 * [_IocContainer_][].
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Ioc_IocContainerFactory)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Container\\Ioc, IocContainerFactory, phalcon, contracts_container_ioc_ioccontainerfactory, phalcon_contracts_container_ioc_ioccontainerfactory_method_entry);

	return SUCCESS;
}

/**
 * Returns a new instance of [_IocContainer_][].
 *
 * - Notes:
 *
 *     - **Container instantiation logic is not specified.** Implementations
 *       might use providers, configuration files, attribute or annotation
 *       collection, or some other means to create and populate a container.
 *       Implementations might also choose to return a compiled or otherwise
 *       reconstituted container.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Container_Ioc_IocContainerFactory, newContainer);
