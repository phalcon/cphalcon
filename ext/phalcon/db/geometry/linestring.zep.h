
extern zend_class_entry *phalcon_db_geometry_linestring_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_LineString);

PHP_METHOD(Phalcon_Db_Geometry_LineString, __construct);
PHP_METHOD(Phalcon_Db_Geometry_LineString, getType);
PHP_METHOD(Phalcon_Db_Geometry_LineString, getPoints);
PHP_METHOD(Phalcon_Db_Geometry_LineString, toWkt);
PHP_METHOD(Phalcon_Db_Geometry_LineString, pointsWkt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_geometry_linestring___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, points, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, srid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_linestring_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_linestring_getpoints, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_linestring_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_linestring_pointswkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_linestring_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_LineString, __construct, arginfo_phalcon_db_geometry_linestring___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Geometry_LineString, getType, arginfo_phalcon_db_geometry_linestring_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_LineString, getPoints, arginfo_phalcon_db_geometry_linestring_getpoints, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_LineString, toWkt, arginfo_phalcon_db_geometry_linestring_towkt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_LineString, pointsWkt, arginfo_phalcon_db_geometry_linestring_pointswkt, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
