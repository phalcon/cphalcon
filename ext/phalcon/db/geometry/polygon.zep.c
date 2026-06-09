
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
#include "kernel/array.h"
#include "kernel/string.h"


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
	zephir_update_property_zval(this_ptr, ZEND_STRL("rings"), &rings);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval(this_ptr, ZEND_STRL("srid"), &_0);
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
	zend_bool _10, _5$$3, _14$$6;
	zval ring, point, ringParts, parts, _0, *_1, _9, *_2$$3, _4$$3, _7$$3, _8$$3, _3$$4, _6$$5, *_11$$6, _13$$6, _16$$6, _17$$6, _12$$7, _15$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ring);
	ZVAL_UNDEF(&point);
	ZVAL_UNDEF(&ringParts);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_15$$8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("rings"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Db/Geometry/Polygon.zep", 57);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&ring);
			ZVAL_COPY(&ring, _1);
			ZEPHIR_INIT_NVAR(&ringParts);
			array_init(&ringParts);
			zephir_is_iterable(&ring, 0, "phalcon/Db/Geometry/Polygon.zep", 54);
			if (Z_TYPE_P(&ring) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&ring), _2$$3)
				{
					ZEPHIR_INIT_NVAR(&point);
					ZVAL_COPY(&point, _2$$3);
					ZEPHIR_CALL_METHOD(&_3$$4, &point, "coordswkt", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&ringParts, &_3$$4, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &ring, "rewind", NULL, 0);
				zephir_check_call_status();
				_5$$3 = 1;
				while (1) {
					if (_5$$3) {
						_5$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &ring, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_4$$3, &ring, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&point, &ring, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_6$$5, &point, "coordswkt", NULL, 0);
						zephir_check_call_status();
						zephir_array_append(&ringParts, &_6$$5, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
				}
			}
			ZEPHIR_INIT_NVAR(&point);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_fast_join_str(&_7$$3, SL(", "), &ringParts);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_SVS(&_8$$3, "(", &_7$$3, ")");
			zephir_array_append(&parts, &_8$$3, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 54);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&ring, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&ringParts);
				array_init(&ringParts);
				zephir_is_iterable(&ring, 0, "phalcon/Db/Geometry/Polygon.zep", 54);
				if (Z_TYPE_P(&ring) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&ring), _11$$6)
					{
						ZEPHIR_INIT_NVAR(&point);
						ZVAL_COPY(&point, _11$$6);
						ZEPHIR_CALL_METHOD(&_12$$7, &point, "coordswkt", NULL, 0);
						zephir_check_call_status();
						zephir_array_append(&ringParts, &_12$$7, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &ring, "rewind", NULL, 0);
					zephir_check_call_status();
					_14$$6 = 1;
					while (1) {
						if (_14$$6) {
							_14$$6 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &ring, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_13$$6, &ring, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&point, &ring, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_15$$8, &point, "coordswkt", NULL, 0);
							zephir_check_call_status();
							zephir_array_append(&ringParts, &_15$$8, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 51);
					}
				}
				ZEPHIR_INIT_NVAR(&point);
				ZEPHIR_INIT_NVAR(&_16$$6);
				zephir_fast_join_str(&_16$$6, SL(", "), &ringParts);
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZEPHIR_CONCAT_SVS(&_17$$6, "(", &_16$$6, ")");
				zephir_array_append(&parts, &_17$$6, PH_SEPARATE, "phalcon/Db/Geometry/Polygon.zep", 54);
		}
	}
	ZEPHIR_INIT_NVAR(&ring);
	zephir_fast_join_str(return_value, SL(", "), &parts);
	RETURN_MM();
}

