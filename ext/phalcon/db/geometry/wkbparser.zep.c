
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Decodes a spatial column value into a geometry value object.
 *
 * Handles MySQL's internal format (4-byte little-endian SRID prefix followed
 * by standard OGC WKB) and PostGIS EWKB returned as a hex string. 2D only:
 * any Z/M ordinates are read past and discarded.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_WkbParser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db\\Geometry, WkbParser, phalcon, db_geometry_wkbparser, phalcon_db_geometry_wkbparser_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_geometry_wkbparser_ce, SL("buffer"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_geometry_wkbparser_ce, SL("length"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_geometry_wkbparser_ce, SL("position"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, parse)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, srid;
	zval raw_zv, body, arr, _1, _8, _2$$5, _3$$5, _4$$5, _5$$5, _6$$5, _7$$5;
	zend_string *raw = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw_zv);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("buffer", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("length", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("position", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&raw_zv);
	ZVAL_STR_COPY(&raw_zv, raw);
	srid = 0;
	if (ZEPHIR_IS_STRING_IDENTICAL(&raw_zv, "")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "empty value", "phalcon/Db/Geometry/WkbParser.zep", 42);
		return;
	}
	_0 = zephir_safe_mod_long_long(zephir_fast_strlen_ev(&raw_zv), 2) == 0;
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "ctype_xdigit", NULL, 0, &raw_zv);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&body, "hex2bin", NULL, 36, &raw_zv);
		zephir_check_call_status();
	} else {
		if (zephir_fast_strlen_ev(&raw_zv) < 5) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "buffer too short for MySQL prefix", "phalcon/Db/Geometry/WkbParser.zep", 55);
			return;
		}
		ZVAL_LONG(&_2$$5, 0);
		ZVAL_LONG(&_3$$5, 4);
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_substr(&_4$$5, &raw_zv, 0 , 4 , 0);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "V");
		ZEPHIR_CALL_FUNCTION(&arr, "unpack", NULL, 0, &_5$$5, &_4$$5);
		zephir_check_call_status();
		zephir_memory_observe(&_6$$5);
		zephir_array_fetch_long(&_6$$5, &arr, 1, PH_NOISY, "phalcon/Db/Geometry/WkbParser.zep", 59);
		srid = zephir_get_intval(&_6$$5);
		ZVAL_LONG(&_7$$5, 4);
		ZEPHIR_INIT_NVAR(&body);
		zephir_substr(&body, &raw_zv, 4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 651, &body);
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, zephir_fast_strlen_ev(&body));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 652, &_8);
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 653, &_8);
	ZVAL_LONG(&_8, srid);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "readGeometry", NULL, 0, &_8);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readGeometry)
{
	zend_bool little = 0, hasZ = 0, hasM = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zval *outerSrid_param = NULL, *depth_param = NULL, byteOrder, typeWord, geomCode, baseType, srid, count, items, _0, _1$$4, _2$$5, _3$$6, _4$$7, _5$$9, _6$$9, _7$$9, _8$$10, _9$$10, _10$$10, _11$$10, _12$$11, _13$$11, _14$$11, _15$$11, _16$$12, _17$$13, _18$$13, _20$$17, _21$$17;
	zend_long outerSrid, depth, ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&byteOrder);
	ZVAL_UNDEF(&typeWord);
	ZVAL_UNDEF(&geomCode);
	ZVAL_UNDEF(&baseType);
	ZVAL_UNDEF(&srid);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(outerSrid)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &outerSrid_param, &depth_param);
	if (!depth_param) {
		depth = 0;
	} else {
		}
	if (depth > 32) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "geometry nesting exceeds the maximum supported depth", "phalcon/Db/Geometry/WkbParser.zep", 83);
		return;
	}
	ZEPHIR_CALL_METHOD(&byteOrder, this_ptr, "readByte", NULL, 0);
	zephir_check_call_status();
	little = (ZEPHIR_IS_LONG_IDENTICAL(&byteOrder, 1));
	if (little) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&typeWord, this_ptr, "readUint32", NULL, 0, &_0);
	zephir_check_call_status();
	hasZ = ((zephir_get_intval(&typeWord) & 0x80000000)) != 0;
	hasM = ((zephir_get_intval(&typeWord) & 0x40000000)) != 0;
	ZEPHIR_INIT_VAR(&srid);
	ZVAL_LONG(&srid, outerSrid);
	ZEPHIR_INIT_VAR(&geomCode);
	ZVAL_LONG(&geomCode, (zephir_get_intval(&typeWord) & 0x0FFFFFFF));
	if (((zephir_get_intval(&typeWord) & 0x20000000)) != 0) {
		if (little) {
			ZVAL_BOOL(&_1$$4, 1);
		} else {
			ZVAL_BOOL(&_1$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&srid, this_ptr, "readUint32", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	if (ZEPHIR_GE_LONG(&geomCode, 3000)) {
		hasZ = 1;
		hasM = 1;
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_LONG(&_2$$5, 3000);
		ZEPHIR_INIT_VAR(&baseType);
		zephir_sub_function(&baseType, &geomCode, &_2$$5);
	} else if (ZEPHIR_GE_LONG(&geomCode, 2000)) {
		hasM = 1;
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_LONG(&_3$$6, 2000);
		ZEPHIR_INIT_NVAR(&baseType);
		zephir_sub_function(&baseType, &geomCode, &_3$$6);
	} else if (ZEPHIR_GE_LONG(&geomCode, 1000)) {
		hasZ = 1;
		ZEPHIR_INIT_VAR(&_4$$7);
		ZVAL_LONG(&_4$$7, 1000);
		ZEPHIR_INIT_NVAR(&baseType);
		zephir_sub_function(&baseType, &geomCode, &_4$$7);
	} else {
		ZEPHIR_CPY_WRT(&baseType, &geomCode);
	}
	if (ZEPHIR_IS_LONG(&baseType, 1)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&baseType, 2)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&baseType, 3)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&baseType, 4)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&baseType, 5)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&baseType, 6)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&baseType, 7)) { goto zephir_switch_0_clause_6; }
	goto zephir_switch_0_clause_7;
	zephir_switch_0_clause_0: ;
		if (little) {
			ZVAL_BOOL(&_5$$9, 1);
		} else {
			ZVAL_BOOL(&_5$$9, 0);
		}
		if (hasZ) {
			ZVAL_BOOL(&_6$$9, 1);
		} else {
			ZVAL_BOOL(&_6$$9, 0);
		}
		if (hasM) {
			ZVAL_BOOL(&_7$$9, 1);
		} else {
			ZVAL_BOOL(&_7$$9, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "readPoint", NULL, 0, &_5$$9, &_6$$9, &_7$$9, &srid);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		object_init_ex(return_value, phalcon_db_geometry_linestring_ce);
		if (little) {
			ZVAL_BOOL(&_9$$10, 1);
		} else {
			ZVAL_BOOL(&_9$$10, 0);
		}
		if (hasZ) {
			ZVAL_BOOL(&_10$$10, 1);
		} else {
			ZVAL_BOOL(&_10$$10, 0);
		}
		if (hasM) {
			ZVAL_BOOL(&_11$$10, 1);
		} else {
			ZVAL_BOOL(&_11$$10, 0);
		}
		ZEPHIR_CALL_METHOD(&_8$$10, this_ptr, "readPointList", NULL, 0, &_9$$10, &_10$$10, &_11$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_8$$10, &srid);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_2: ;
		object_init_ex(return_value, phalcon_db_geometry_polygon_ce);
		if (little) {
			ZVAL_BOOL(&_13$$11, 1);
		} else {
			ZVAL_BOOL(&_13$$11, 0);
		}
		if (hasZ) {
			ZVAL_BOOL(&_14$$11, 1);
		} else {
			ZVAL_BOOL(&_14$$11, 0);
		}
		if (hasM) {
			ZVAL_BOOL(&_15$$11, 1);
		} else {
			ZVAL_BOOL(&_15$$11, 0);
		}
		ZEPHIR_CALL_METHOD(&_12$$11, this_ptr, "readRingList", NULL, 0, &_13$$11, &_14$$11, &_15$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_12$$11, &srid);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
	zephir_switch_0_clause_5: ;
	zephir_switch_0_clause_6: ;
		if (little) {
			ZVAL_BOOL(&_16$$12, 1);
		} else {
			ZVAL_BOOL(&_16$$12, 0);
		}
		ZEPHIR_CALL_METHOD(&count, this_ptr, "readUint32", NULL, 0, &_16$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&items);
		array_init(&items);
		i = 0;
		while (1) {
			if (!(ZEPHIR_GT_LONG(&count, i))) {
				break;
			}
			ZVAL_LONG(&_18$$13, (depth + 1));
			ZEPHIR_CALL_METHOD(&_17$$13, this_ptr, "readGeometry", &_19, 0, &srid, &_18$$13);
			zephir_check_call_status();
			zephir_array_append(&items, &_17$$13, PH_SEPARATE, "phalcon/Db/Geometry/WkbParser.zep", 129);
			i = (i + 1);
		}
		if (ZEPHIR_IS_LONG_IDENTICAL(&baseType, 4)) {
			object_init_ex(return_value, phalcon_db_geometry_multipoint_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &items, &srid);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG_IDENTICAL(&baseType, 5)) {
			object_init_ex(return_value, phalcon_db_geometry_multilinestring_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &items, &srid);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG_IDENTICAL(&baseType, 6)) {
			object_init_ex(return_value, phalcon_db_geometry_multipolygon_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &items, &srid);
			zephir_check_call_status();
			RETURN_MM();
		}
		object_init_ex(return_value, phalcon_db_geometry_geometrycollection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &items, &srid);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_7: ;
		ZEPHIR_INIT_VAR(&_20$$17);
		object_init_ex(&_20$$17, phalcon_db_exceptions_invalidwkb_ce);
		ZEPHIR_INIT_VAR(&_21$$17);
		ZEPHIR_CONCAT_SV(&_21$$17, "unknown geometry type ", &baseType);
		ZEPHIR_CALL_METHOD(NULL, &_20$$17, "__construct", NULL, 0, &_21$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_20$$17, "phalcon/Db/Geometry/WkbParser.zep", 148);
		ZEPHIR_MM_RESTORE();
		return;

}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readPoint)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long srid, ZEPHIR_LAST_CALL_STATUS;
	zval *little_param = NULL, *hasZ_param = NULL, *hasM_param = NULL, *srid_param = NULL, x, y, _0, _1, _2, _3, _4, _5;
	zend_bool little, hasZ, hasM;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_BOOL(little)
		Z_PARAM_BOOL(hasZ)
		Z_PARAM_BOOL(hasM)
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &little_param, &hasZ_param, &hasM_param, &srid_param);
	if (little) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&x, this_ptr, "readDouble", NULL, 0, &_0);
	zephir_check_call_status();
	if (little) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(&y, this_ptr, "readDouble", NULL, 0, &_1);
	zephir_check_call_status();
	if (little) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (hasZ) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	if (hasM) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipExtraOrdinates", NULL, 0, &_2, &_3, &_4);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_db_geometry_point_ce);
	ZVAL_LONG(&_5, srid);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &x, &y, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-return list<Point>
 */
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readPointList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *little_param = NULL, *hasZ_param = NULL, *hasM_param = NULL, count, x, y, points, _0, _1$$3, _3$$3, _4$$3, _5$$3, _6$$3, _8$$3;
	zend_bool little, hasZ, hasM;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&points);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_BOOL(little)
		Z_PARAM_BOOL(hasZ)
		Z_PARAM_BOOL(hasM)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &little_param, &hasZ_param, &hasM_param);
	ZEPHIR_INIT_VAR(&points);
	array_init(&points);
	if (little) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&count, this_ptr, "readUint32", NULL, 0, &_0);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&count, i))) {
			break;
		}
		if (little) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_CALL_METHOD(&x, this_ptr, "readDouble", &_2, 0, &_1$$3);
		zephir_check_call_status();
		if (little) {
			ZVAL_BOOL(&_3$$3, 1);
		} else {
			ZVAL_BOOL(&_3$$3, 0);
		}
		ZEPHIR_CALL_METHOD(&y, this_ptr, "readDouble", &_2, 0, &_3$$3);
		zephir_check_call_status();
		if (little) {
			ZVAL_BOOL(&_4$$3, 1);
		} else {
			ZVAL_BOOL(&_4$$3, 0);
		}
		if (hasZ) {
			ZVAL_BOOL(&_5$$3, 1);
		} else {
			ZVAL_BOOL(&_5$$3, 0);
		}
		if (hasM) {
			ZVAL_BOOL(&_6$$3, 1);
		} else {
			ZVAL_BOOL(&_6$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipExtraOrdinates", &_7, 0, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$3);
		object_init_ex(&_8$$3, phalcon_db_geometry_point_ce);
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", &_9, 0, &x, &y);
		zephir_check_call_status();
		zephir_array_append(&points, &_8$$3, PH_SEPARATE, "phalcon/Db/Geometry/WkbParser.zep", 180);
		i = (i + 1);
	}
	RETURN_CCTOR(&points);
}

/**
 * @phpstan-return list<list<Point>>
 */
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readRingList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *little_param = NULL, *hasZ_param = NULL, *hasM_param = NULL, count, rings, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_bool little, hasZ, hasM;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&rings);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_BOOL(little)
		Z_PARAM_BOOL(hasZ)
		Z_PARAM_BOOL(hasM)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &little_param, &hasZ_param, &hasM_param);
	ZEPHIR_INIT_VAR(&rings);
	array_init(&rings);
	if (little) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&count, this_ptr, "readUint32", NULL, 0, &_0);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&count, i))) {
			break;
		}
		if (little) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		if (hasZ) {
			ZVAL_BOOL(&_3$$3, 1);
		} else {
			ZVAL_BOOL(&_3$$3, 0);
		}
		if (hasM) {
			ZVAL_BOOL(&_4$$3, 1);
		} else {
			ZVAL_BOOL(&_4$$3, 0);
		}
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "readPointList", &_5, 0, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_array_append(&rings, &_1$$3, PH_SEPARATE, "phalcon/Db/Geometry/WkbParser.zep", 198);
		i = (i + 1);
	}
	RETURN_CCTOR(&rings);
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, skipExtraOrdinates)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *little_param = NULL, *hasZ_param = NULL, *hasM_param = NULL, _0$$3, _1$$4;
	zend_bool little, hasZ, hasM;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_BOOL(little)
		Z_PARAM_BOOL(hasZ)
		Z_PARAM_BOOL(hasM)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &little_param, &hasZ_param, &hasM_param);
	if (hasZ) {
		if (little) {
			ZVAL_BOOL(&_0$$3, 1);
		} else {
			ZVAL_BOOL(&_0$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "readDouble", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	if (hasM) {
		if (little) {
			ZVAL_BOOL(&_1$$4, 1);
		} else {
			ZVAL_BOOL(&_1$$4, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "readDouble", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readByte)
{
	zval arr, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("length", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("buffer", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_add_function(&_2, &_0, &_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 652, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT(&_2, &_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "truncated buffer", "phalcon/Db/Geometry/WkbParser.zep", 221);
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 651, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, zephir_get_intval(&_4), 1 , 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "C");
	ZEPHIR_CALL_FUNCTION(&arr, "unpack", NULL, 0, &_7, &_6);
	zephir_check_call_status();
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&_9);
	zephir_add_function(&_9, &_8, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 653, &_9);
	zephir_memory_observe(&_10);
	zephir_array_fetch_long(&_10, &arr, 1, PH_NOISY, "phalcon/Db/Geometry/WkbParser.zep", 227);
	RETURN_MM_LONG(zephir_get_intval(&_10));
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readUint32)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *little_param = NULL, fmt, arr, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_bool little;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fmt);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("length", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("buffer", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(little)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &little_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_INIT_VAR(&_2);
	zephir_add_function(&_2, &_0, &_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 652, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT(&_2, &_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "truncated buffer", "phalcon/Db/Geometry/WkbParser.zep", 235);
		return;
	}
	if (little) {
		ZEPHIR_INIT_VAR(&fmt);
		ZVAL_STRING(&fmt, "V");
	} else {
		ZEPHIR_INIT_NVAR(&fmt);
		ZVAL_STRING(&fmt, "N");
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 651, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 4);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, zephir_get_intval(&_4), 4 , 0);
	ZEPHIR_CALL_FUNCTION(&arr, "unpack", NULL, 0, &fmt, &_6);
	zephir_check_call_status();
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_INIT_VAR(&_8);
	zephir_add_function(&_8, &_7, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 653, &_8);
	zephir_memory_observe(&_9);
	zephir_array_fetch_long(&_9, &arr, 1, PH_NOISY, "phalcon/Db/Geometry/WkbParser.zep", 242);
	RETURN_MM_LONG(zephir_get_intval(&_9));
}

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readDouble)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *little_param = NULL, fmt, arr, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_bool little;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fmt);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("length", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("buffer", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(little)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &little_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_INIT_VAR(&_2);
	zephir_add_function(&_2, &_0, &_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 652, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT(&_2, &_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_invalidwkb_ce, "truncated buffer", "phalcon/Db/Geometry/WkbParser.zep", 250);
		return;
	}
	if (little) {
		ZEPHIR_INIT_VAR(&fmt);
		ZVAL_STRING(&fmt, "e");
	} else {
		ZEPHIR_INIT_NVAR(&fmt);
		ZVAL_STRING(&fmt, "E");
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 651, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 8);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, zephir_get_intval(&_4), 8 , 0);
	ZEPHIR_CALL_FUNCTION(&arr, "unpack", NULL, 0, &fmt, &_6);
	zephir_check_call_status();
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 653, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_INIT_VAR(&_8);
	zephir_add_function(&_8, &_7, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 653, &_8);
	zephir_memory_observe(&_9);
	zephir_array_fetch_long(&_9, &arr, 1, PH_NOISY, "phalcon/Db/Geometry/WkbParser.zep", 257);
	RETURN_MM_DOUBLE(zephir_get_doubleval(&_9));
}

