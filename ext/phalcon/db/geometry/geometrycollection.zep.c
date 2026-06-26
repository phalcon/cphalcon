
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_GeometryCollection)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Geometry, GeometryCollection, phalcon, db_geometry_geometrycollection, phalcon_db_geometry_abstractgeometry_ce, phalcon_db_geometry_geometrycollection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_geometry_geometrycollection_ce, SL("geometries"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_GeometryCollection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long srid;
	zval *geometries_param = NULL, *srid_param = NULL, _0;
	zval geometries;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&geometries);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(geometries, geometries_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &geometries_param, &srid_param);
	zephir_get_arrval(&geometries, geometries_param);
	if (!srid_param) {
		srid = 0;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("geometries"), &geometries);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval(this_ptr, ZEND_STRL("srid"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Db_Geometry_GeometryCollection, getType)
{

	RETURN_LONG(47);
}

PHP_METHOD(Phalcon_Db_Geometry_GeometryCollection, getGeometries)
{

	RETURN_MEMBER_TYPED(getThis(), "geometries", IS_ARRAY);
}

PHP_METHOD(Phalcon_Db_Geometry_GeometryCollection, toWkt)
{
	zend_bool _4;
	zval geometry, parts, _0, *_1, _3, _6, _2$$3, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&geometry);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("geometries"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Db/Geometry/GeometryCollection.zep", 46);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&geometry);
			ZVAL_COPY(&geometry, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, &geometry, "towkt", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&parts, &_2$$3, PH_SEPARATE, "phalcon/Db/Geometry/GeometryCollection.zep", 43);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&geometry, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, &geometry, "towkt", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&parts, &_5$$4, PH_SEPARATE, "phalcon/Db/Geometry/GeometryCollection.zep", 43);
		}
	}
	ZEPHIR_INIT_NVAR(&geometry);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL(", "), &parts);
	ZEPHIR_CONCAT_SVS(return_value, "GEOMETRYCOLLECTION(", &_6, ")");
	RETURN_MM();
}

