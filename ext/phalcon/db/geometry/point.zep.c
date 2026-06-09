
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Point)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Geometry, Point, phalcon, db_geometry_point, phalcon_db_geometry_abstractgeometry_ce, phalcon_db_geometry_point_method_entry, 0);

	/**
	 * @var float
	 */
	zend_declare_property_null(phalcon_db_geometry_point_ce, SL("x"), ZEND_ACC_PROTECTED);
	/**
	 * @var float
	 */
	zend_declare_property_null(phalcon_db_geometry_point_ce, SL("y"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_Geometry_Point, __construct)
{
	zend_long srid;
	zval *x_param = NULL, *y_param = NULL, *srid_param = NULL, _0;
	double x, y;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(x_param)
		Z_PARAM_ZVAL(y_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(srid)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 1, &x_param, &y_param, &srid_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	if (!srid_param) {
		srid = 0;
	} else {
		}
	ZVAL_UNDEF(&_0);
	ZVAL_DOUBLE(&_0, x);
	zephir_update_property_zval(this_ptr, ZEND_STRL("x"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_DOUBLE(&_0, y);
	zephir_update_property_zval(this_ptr, ZEND_STRL("y"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, srid);
	zephir_update_property_zval(this_ptr, ZEND_STRL("srid"), &_0);
}

PHP_METHOD(Phalcon_Db_Geometry_Point, getType)
{

	RETURN_LONG(41);
}

PHP_METHOD(Phalcon_Db_Geometry_Point, getX)
{

	RETURN_MEMBER_TYPED(getThis(), "x", IS_DOUBLE);
}

PHP_METHOD(Phalcon_Db_Geometry_Point, getY)
{

	RETURN_MEMBER_TYPED(getThis(), "y", IS_DOUBLE);
}

PHP_METHOD(Phalcon_Db_Geometry_Point, toWkt)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "coordswkt", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "POINT(", &_0, ")");
	RETURN_MM();
}

PHP_METHOD(Phalcon_Db_Geometry_Point, coordsWkt)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("x"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("y"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSV(return_value, &_0, " ", &_1);
	return;
}

