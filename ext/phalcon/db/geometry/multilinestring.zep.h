
extern zend_class_entry *phalcon_db_geometry_multilinestring_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_MultiLineString);

PHP_METHOD(Phalcon_Db_Geometry_MultiLineString, __construct);
PHP_METHOD(Phalcon_Db_Geometry_MultiLineString, getType);
PHP_METHOD(Phalcon_Db_Geometry_MultiLineString, getLineStrings);
PHP_METHOD(Phalcon_Db_Geometry_MultiLineString, toWkt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_geometry_multilinestring___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, lineStrings, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, srid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multilinestring_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multilinestring_getlinestrings, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_multilinestring_towkt, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_multilinestring_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_MultiLineString, __construct, arginfo_phalcon_db_geometry_multilinestring___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Geometry_MultiLineString, getType, arginfo_phalcon_db_geometry_multilinestring_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_MultiLineString, getLineStrings, arginfo_phalcon_db_geometry_multilinestring_getlinestrings, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_MultiLineString, toWkt, arginfo_phalcon_db_geometry_multilinestring_towkt, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
