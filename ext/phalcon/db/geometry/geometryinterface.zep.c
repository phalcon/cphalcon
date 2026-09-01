
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
 * Phalcon\Db\Geometry\GeometryInterface
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Db\Geometry\Geometry} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_GeometryInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db\\Geometry, GeometryInterface, phalcon, db_geometry_geometryinterface, NULL);

	zend_class_implements(phalcon_db_geometry_geometryinterface_ce, 1, phalcon_contracts_db_geometry_geometry_ce);
	return SUCCESS;
}

