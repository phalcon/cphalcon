
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
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_MultiPoint)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Geometry, MultiPoint, phalcon, db_geometry_multipoint, phalcon_db_geometry_abstractgeometry_ce, phalcon_db_geometry_multipoint_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_geometry_multipoint_ce, SL("points"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPoint, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long srid;
	zval *points_param = NULL, *srid_param = NULL, _0;
	zval points;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&points);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(points, points_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &points_param, &srid_param);
	zephir_get_arrval(&points, points_param);
	if (!srid_param) {
		srid = 0;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("points"), &points);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval(this_ptr, ZEND_STRL("srid"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPoint, getType)
{

	RETURN_LONG(44);
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPoint, getPoints)
{

	RETURN_MEMBER_TYPED(getThis(), "points", IS_ARRAY);
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPoint, toWkt)
{
	zend_bool _4;
	zval point, parts, _0, *_1, _3, _6, _2$$3, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&point);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("points"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Db/Geometry/MultiPoint.zep", 46);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&point);
			ZVAL_COPY(&point, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, &point, "coordswkt", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&parts, &_2$$3, PH_SEPARATE, "phalcon/Db/Geometry/MultiPoint.zep", 43);
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
			ZEPHIR_CALL_METHOD(&point, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, &point, "coordswkt", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&parts, &_5$$4, PH_SEPARATE, "phalcon/Db/Geometry/MultiPoint.zep", 43);
		}
	}
	ZEPHIR_INIT_NVAR(&point);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL(", "), &parts);
	ZEPHIR_CONCAT_SVS(return_value, "MULTIPOINT(", &_6, ")");
	RETURN_MM();
}

