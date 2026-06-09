
extern zend_class_entry *phalcon_db_geometry_multipolygon_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_MultiPolygon);

PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, __construct);
PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, getType);
PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, getPolygons);
PHP_METHOD(Phalcon_Db_Geometry_MultiPolygon, toWkt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_geometry_multipolygon___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, polygons, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, srid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multipolygon_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multipolygon_getpolygons, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multipolygon_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_multipolygon_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_MultiPolygon, __construct, arginfo_phalcon_db_geometry_multipolygon___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Geometry_MultiPolygon, getType, arginfo_phalcon_db_geometry_multipolygon_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_MultiPolygon, getPolygons, arginfo_phalcon_db_geometry_multipolygon_getpolygons, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_MultiPolygon, toWkt, arginfo_phalcon_db_geometry_multipolygon_towkt, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
