
extern zend_class_entry *phalcon_datamapper_query_bind_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_Bind);

PHP_METHOD(Phalcon_DataMapper_Query_Bind, bindInline);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, remove);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, setValue);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, setValues);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, toArray);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, getType);
PHP_METHOD(Phalcon_DataMapper_Query_Bind, inlineArray);
zend_object *zephir_init_properties_Phalcon_DataMapper_Query_Bind(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_bindinline, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_setvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_setvalues, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_gettype, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_query_bind_inlinearray, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_query_bind_zephir_init_properties_phalcon_datamapper_query_bind, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_query_bind_method_entry) {
	PHP_ME(Phalcon_DataMapper_Query_Bind, bindInline, arginfo_phalcon_datamapper_query_bind_bindinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Bind, remove, arginfo_phalcon_datamapper_query_bind_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Bind, setValue, arginfo_phalcon_datamapper_query_bind_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Bind, setValues, arginfo_phalcon_datamapper_query_bind_setvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Bind, toArray, arginfo_phalcon_datamapper_query_bind_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Query_Bind, getType, arginfo_phalcon_datamapper_query_bind_gettype, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_DataMapper_Query_Bind, inlineArray, arginfo_phalcon_datamapper_query_bind_inlinearray, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
