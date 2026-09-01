
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
 * Phalcon\Assets\FilterInterface
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Assets\Filter} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, FilterInterface, phalcon, assets_filterinterface, NULL);

	zend_class_implements(phalcon_assets_filterinterface_ce, 1, phalcon_contracts_assets_filter_ce);
	return SUCCESS;
}

