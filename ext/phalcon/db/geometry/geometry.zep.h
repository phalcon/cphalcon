
extern zend_class_entry *phalcon_db_geometry_geometry_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_Geometry);

PHP_METHOD(Phalcon_Db_Geometry_Geometry, getType);
PHP_METHOD(Phalcon_Db_Geometry_Geometry, toWkt);
PHP_METHOD(Phalcon_Db_Geometry_Geometry, getSrid);
PHP_METHOD(Phalcon_Db_Geometry_Geometry, __toString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_geometry_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_geometry_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_geometry_getsrid, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_geometry___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_geometry_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_Geometry, getType, arginfo_phalcon_db_geometry_geometry_gettype, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Geometry, toWkt, arginfo_phalcon_db_geometry_geometry_towkt, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Geometry, getSrid, arginfo_phalcon_db_geometry_geometry_getsrid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_Geometry, __toString, arginfo_phalcon_db_geometry_geometry___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
