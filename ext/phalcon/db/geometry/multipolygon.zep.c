
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_MultiPolygon)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Geometry, MultiPolygon, phalcon, db_geometry_multipolygon, phalcon_db_geometry_abstractgeometry_ce, phalcon_db_geometry_multipolygon_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_geometry_multipolygon_ce, SL("polygons"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long srid;
	zval *polygons_param = NULL, *srid_param = NULL, _0;
	zval polygons;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&polygons);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("polygons", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("srid", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(polygons, polygons_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &polygons_param, &srid_param);
	zephir_get_arrval(&polygons, polygons_param);
	if (!srid_param) {
		srid = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 629, &polygons);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 630, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, getType)
{

	RETURN_LONG(46);
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, getPolygons)
{

	RETURN_MEMBER_TYPED(getThis(), "polygons", IS_ARRAY);
}

PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, toWkt)
{
	zend_bool _7;
	zval polygon, parts, _0, *_1, _2, *_3, _6, _10, _4$$3, _5$$3, _8$$4, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&polygon);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("polygons", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 629, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Db/Geometry/MultiPolygon.zep", 46);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&polygon);
			ZVAL_COPY(&polygon, _3);
			ZEPHIR_CALL_METHOD(&_4$$3, &polygon, "ringswkt", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_CONCAT_SVS(&_5$$3, "(", &_4$$3, ")");
			zephir_array_append(&parts, &_5$$3, PH_SEPARATE, "phalcon/Db/Geometry/MultiPolygon.zep", 43);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&polygon, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$4, &polygon, "ringswkt", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVS(&_9$$4, "(", &_8$$4, ")");
				zephir_array_append(&parts, &_9$$4, PH_SEPARATE, "phalcon/Db/Geometry/MultiPolygon.zep", 43);
		}
	}
	ZEPHIR_INIT_NVAR(&polygon);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join_str(&_10, SL(", "), &parts);
	ZEPHIR_CONCAT_SVS(return_value, "MULTIPOLYGON(", &_10, ")");
	RETURN_MM();
}

