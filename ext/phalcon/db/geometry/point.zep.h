
extern zend_class_entry *phalcon_db_geometry_point_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Point);

PHP_METHOD(Phalcon_Db_Geometry_Point, __construct);
PHP_METHOD(Phalcon_Db_Geometry_Point, getType);
PHP_METHOD(Phalcon_Db_Geometry_Point, getX);
PHP_METHOD(Phalcon_Db_Geometry_Point, getY);
PHP_METHOD(Phalcon_Db_Geometry_Point, toWkt);
PHP_METHOD(Phalcon_Db_Geometry_Point, coordsWkt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_geometry_point___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, srid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_point_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_point_getx, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_point_gety, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_point_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_point_coordswkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_point_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_Point, __construct, arginfo_phalcon_db_geometry_point___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Geometry_Point, getType, arginfo_phalcon_db_geometry_point_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Point, getX, arginfo_phalcon_db_geometry_point_getx, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Point, getY, arginfo_phalcon_db_geometry_point_gety, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Point, toWkt, arginfo_phalcon_db_geometry_point_towkt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Point, coordsWkt, arginfo_phalcon_db_geometry_point_coordswkt, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
