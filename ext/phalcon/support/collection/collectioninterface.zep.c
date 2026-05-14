
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Phalcon\Support\Collection\CollectionInterface
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Support\Collection} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Collection_CollectionInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Support\\Collection, CollectionInterface, phalcon, support_collection_collectioninterface, NULL);

	zend_class_implements(phalcon_support_collection_collectioninterface_ce, 1, phalcon_contracts_support_collection_ce);
	return SUCCESS;
}

