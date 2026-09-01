
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
 * Canonical contract for Phalcon\Db\Geometry value objects.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Geometry_Geometry)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Db\\Geometry, Geometry, phalcon, contracts_db_geometry_geometry, phalcon_contracts_db_geometry_geometry_method_entry);

	return SUCCESS;
}

/**
 * Gets the Spatial Reference System Identifier (SRID).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Geometry_Geometry, getSrid);
/**
 * Gets the geometry type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Geometry_Geometry, getType);
/**
 * Renders the geometry as a Well-Known Text (WKT) string.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Db_Geometry_Geometry, toWkt);
