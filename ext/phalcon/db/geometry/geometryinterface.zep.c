
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
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_GeometryInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db\\Geometry, GeometryInterface, phalcon, db_geometry_geometryinterface, phalcon_db_geometry_geometryinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Db_Geometry_GeometryInterface, getSrid);
ZEPHIR_DOC_METHOD(Phalcon_Db_Geometry_GeometryInterface, getType);
ZEPHIR_DOC_METHOD(Phalcon_Db_Geometry_GeometryInterface, toWkt);
