
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Polygon)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Geometry, Polygon, phalcon, db_geometry_polygon, phalcon_db_geometry_abstractgeometry_ce, phalcon_db_geometry_polygon_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_geometry_polygon_ce, SL("rings"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_Polygon, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long srid;
	zval *rings_param = NULL, *srid_param = NULL, _0;
	zval rings;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rings);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rings", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("srid", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(rings, rings_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &rings_param, &srid_param);
	zephir_get_arrval(&rings, rings_param);
	if (!srid_param) {
		srid = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 635, &rings);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 636, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Db_Geometry_Polygon, getType)
{

	RETURN_LONG(43);
}

PHP_METHOD(Phalcon_Db_Geometry_Polygon, getRings)
{

	RETURN_MEMBER_TYPED(getThis(), "rings", IS_ARRAY);
}

PHP_METHOD(Phalcon_Db_Geometry_Polygon, toWkt)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "ringswkt", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "POLYGON(", &_0, ")");
	RETURN_MM();
}

PHP_METHOD(Phalcon_Db_Geometry_Polygon, ringsWkt)
{
	zend_bool _14, _9$$3, _20$$6;
	zval ring, point, ringParts, parts, _0, *_1, _2, *_3, _13, *_4$$3, _5$$3, *_6$$3, _8$$3, _11$$3, _12$$3, _7$$4, _10$$5, *_15$$6, _16$$6, *_17$$6, _19$$6, _22$$6, _23$$6, _18$$7, _21$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ring);
	ZVAL_UNDEF(&point);
	ZVAL_UNDEF(&ringParts);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rings", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 635, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Db/Geometry/Polygon.zep", 57);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&ring);
			ZVAL_COPY(&ring, _3);
			ZEPHIR_INIT_NVAR(&ringParts);
			array_init(&ringParts);
			if (Z_TYPE_P(&ring) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$3);
				zephir_string_to_char_array(&_5$$3, &ring);
				_4$$3 = &_5$$3;
			} else {
				_4$$3 = &ring;
			}
			zephir_is_iterable(_4$$3, 0, "phalcon/Db/Geometry/Polygon.zep", 54);
			if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
				{
					ZEPHIR_INIT_NVAR(&point);
					ZVAL_COPY(&point, _6$$3);
					ZEPHIR_CALL_METHOD(&_7$$4, &point, "coordswkt", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&ringParts, &_7$$4, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				_9$$3 = 1;
				while (1) {
					if (_9$$3) {
						_9$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _4$$3, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_8$$3, _4$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&point, _4$$3, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_10$$5, &point, "coordswkt", NULL, 0);
						zephir_check_call_status();
						zephir_array_append(&ringParts, &_10$$5, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
				}
			}
			ZEPHIR_INIT_NVAR(&point);
			ZEPHIR_INIT_NVAR(&_11$$3);
			zephir_fast_join_str(&_11$$3, SL(", "), &ringParts);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZEPHIR_CONCAT_SVS(&_12$$3, "(", &_11$$3, ")");
			zephir_array_append(&parts, &_12$$3, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 54);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&ring, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&ringParts);
				array_init(&ringParts);
				if (Z_TYPE_P(&ring) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_16$$6);
					zephir_string_to_char_array(&_16$$6, &ring);
					_15$$6 = &_16$$6;
				} else {
					_15$$6 = &ring;
				}
				zephir_is_iterable(_15$$6, 0, "phalcon/Db/Geometry/Polygon.zep", 54);
				if (Z_TYPE_P(_15$$6) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15$$6), _17$$6)
					{
						ZEPHIR_INIT_NVAR(&point);
						ZVAL_COPY(&point, _17$$6);
						ZEPHIR_CALL_METHOD(&_18$$7, &point, "coordswkt", NULL, 0);
						zephir_check_call_status();
						zephir_array_append(&ringParts, &_18$$7, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _15$$6, "rewind", NULL, 0);
					zephir_check_call_status();
					_20$$6 = 1;
					while (1) {
						if (_20$$6) {
							_20$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _15$$6, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_19$$6, _15$$6, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_19$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&point, _15$$6, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_21$$8, &point, "coordswkt", NULL, 0);
							zephir_check_call_status();
							zephir_array_append(&ringParts, &_21$$8, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
					}
				}
				ZEPHIR_INIT_NVAR(&point);
				ZEPHIR_INIT_NVAR(&_22$$6);
				zephir_fast_join_str(&_22$$6, SL(", "), &ringParts);
				ZEPHIR_INIT_NVAR(&_23$$6);
				ZEPHIR_CONCAT_SVS(&_23$$6, "(", &_22$$6, ")");
				zephir_array_append(&parts, &_23$$6, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 54);
		}
	}
	ZEPHIR_INIT_NVAR(&ring);
	zephir_fast_join_str(return_value, SL(", "), &parts);
	RETURN_MM();
}

