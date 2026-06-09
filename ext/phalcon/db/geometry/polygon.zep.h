
extern zend_class_entry *phalcon_db_geometry_polygon_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Polygon);

PHP_METHOD(Phalcon_Db_Geometry_Polygon, __construct);
PHP_METHOD(Phalcon_Db_Geometry_Polygon, getType);
PHP_METHOD(Phalcon_Db_Geometry_Polygon, getRings);
PHP_METHOD(Phalcon_Db_Geometry_Polygon, toWkt);
PHP_METHOD(Phalcon_Db_Geometry_Polygon, ringsWkt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_geometry_polygon___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rings, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, srid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_polygon_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_polygon_getrings, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_polygon_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_polygon_ringswkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_polygon_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_Polygon, __construct, arginfo_phalcon_db_geometry_polygon___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Geometry_Polygon, getType, arginfo_phalcon_db_geometry_polygon_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Polygon, getRings, arginfo_phalcon_db_geometry_polygon_getrings, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Polygon, toWkt, arginfo_phalcon_db_geometry_polygon_towkt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Polygon, ringsWkt, arginfo_phalcon_db_geometry_polygon_ringswkt, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
