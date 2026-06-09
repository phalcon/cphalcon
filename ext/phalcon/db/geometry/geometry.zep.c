
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Geometry)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Geometry, Geometry, phalcon, db_geometry_geometry, phalcon_db_geometry_geometry_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(phalcon_db_geometry_geometry_ce, SL("srid"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_db_geometry_geometry_ce, 1, phalcon_db_geometry_geometryinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_Geometry, getType)
{
}

PHP_METHOD(Phalcon_Db_Geometry_Geometry, toWkt)
{
}

PHP_METHOD(Phalcon_Db_Geometry_Geometry, getSrid)
{

	RETURN_MEMBER_TYPED(getThis(), "srid", IS_LONG);
}

PHP_METHOD(Phalcon_Db_Geometry_Geometry, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "towkt", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

