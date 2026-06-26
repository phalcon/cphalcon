
extern zend_class_entry *phalcon_db_geometry_wkbparser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Geometry_WkbParser);

PHP_METHOD(Phalcon_Db_Geometry_WkbParser, parse);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readGeometry);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readPoint);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readPointList);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readRingList);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, skipExtraOrdinates);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readByte);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readUint32);
PHP_METHOD(Phalcon_Db_Geometry_WkbParser, readDouble);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_parse, 0, 1, Phalcon\\Db\\Geometry\\GeometryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, raw, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readgeometry, 0, 1, Phalcon\\Db\\Geometry\\GeometryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, outerSrid, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readpoint, 0, 4, Phalcon\\Db\\Geometry\\Point, 0)
	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasZ, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasM, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, srid, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readpointlist, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasZ, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasM, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readringlist, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasZ, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasM, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_skipextraordinates, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasZ, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasM, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readbyte, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readuint32, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_geometry_wkbparser_readdouble, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, little, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_geometry_wkbparser_method_entry) {
	PHP_ME(Phalcon_Db_Geometry_WkbParser, parse, arginfo_phalcon_db_geometry_wkbparser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readGeometry, arginfo_phalcon_db_geometry_wkbparser_readgeometry, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readPoint, arginfo_phalcon_db_geometry_wkbparser_readpoint, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readPointList, arginfo_phalcon_db_geometry_wkbparser_readpointlist, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readRingList, arginfo_phalcon_db_geometry_wkbparser_readringlist, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, skipExtraOrdinates, arginfo_phalcon_db_geometry_wkbparser_skipextraordinates, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readByte, arginfo_phalcon_db_geometry_wkbparser_readbyte, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readUint32, arginfo_phalcon_db_geometry_wkbparser_readuint32, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Geometry_WkbParser, readDouble, arginfo_phalcon_db_geometry_wkbparser_readdouble, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
