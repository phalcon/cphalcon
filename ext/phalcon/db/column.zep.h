
extern zend_class_entry *phalcon_db_column_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Column);

PHP_METHOD(Phalcon_Db_Column, getDefault);
PHP_METHOD(Phalcon_Db_Column, getName);
PHP_METHOD(Phalcon_Db_Column, getComment);
PHP_METHOD(Phalcon_Db_Column, getScale);
PHP_METHOD(Phalcon_Db_Column, getSize);
PHP_METHOD(Phalcon_Db_Column, getType);
PHP_METHOD(Phalcon_Db_Column, getTypeReference);
PHP_METHOD(Phalcon_Db_Column, getTypeValues);
PHP_METHOD(Phalcon_Db_Column, __construct);
PHP_METHOD(Phalcon_Db_Column, getAfterPosition);
PHP_METHOD(Phalcon_Db_Column, getBindType);
PHP_METHOD(Phalcon_Db_Column, hasDefault);
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement);
PHP_METHOD(Phalcon_Db_Column, isFirst);
PHP_METHOD(Phalcon_Db_Column, isNotNull);
PHP_METHOD(Phalcon_Db_Column, isNumeric);
PHP_METHOD(Phalcon_Db_Column, isPrimary);
PHP_METHOD(Phalcon_Db_Column, isUnsigned);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column_getdefault, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_getcomment, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_getscale, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column_getsize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_gettypereference, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column_gettypevalues, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_getafterposition, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_getbindtype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_hasdefault, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isautoincrement, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isfirst, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isnotnull, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isnumeric, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isprimary, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_column_isunsigned, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_column_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Db_Column, getDefault, arginfo_phalcon_db_column_getdefault, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Db_Column, getDefault, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Db_Column, getName, arginfo_phalcon_db_column_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getComment, arginfo_phalcon_db_column_getcomment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getScale, arginfo_phalcon_db_column_getscale, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Db_Column, getSize, arginfo_phalcon_db_column_getsize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Db_Column, getSize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Db_Column, getType, arginfo_phalcon_db_column_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getTypeReference, arginfo_phalcon_db_column_gettypereference, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Db_Column, getTypeValues, arginfo_phalcon_db_column_gettypevalues, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Db_Column, getTypeValues, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Db_Column, __construct, arginfo_phalcon_db_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Column, getAfterPosition, arginfo_phalcon_db_column_getafterposition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getBindType, arginfo_phalcon_db_column_getbindtype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, hasDefault, arginfo_phalcon_db_column_hasdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isAutoIncrement, arginfo_phalcon_db_column_isautoincrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isFirst, arginfo_phalcon_db_column_isfirst, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNotNull, arginfo_phalcon_db_column_isnotnull, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNumeric, arginfo_phalcon_db_column_isnumeric, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isPrimary, arginfo_phalcon_db_column_isprimary, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isUnsigned, arginfo_phalcon_db_column_isunsigned, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
