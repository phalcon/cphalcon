
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
 * Phalcon\Db\ReferenceInterface
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Db\Reference} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ReferenceInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ReferenceInterface, phalcon, db_referenceinterface, NULL);

	zend_class_implements(phalcon_db_referenceinterface_ce, 1, phalcon_contracts_db_reference_ce);
	return SUCCESS;
}

