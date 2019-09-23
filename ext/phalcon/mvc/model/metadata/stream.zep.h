
extern zend_class_entry *phalcon_mvc_model_metadata_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Stream);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, throwWriteException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_read, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_read, 0, 1, IS_ARRAY, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_write, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_write, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_write, 0, 0, 2)
#define arginfo_phalcon_mvc_model_metadata_stream_write NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_throwwriteexception, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_throwwriteexception, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_stream_throwwriteexception, 0, 0, 1)
#define arginfo_phalcon_mvc_model_metadata_stream_throwwriteexception NULL
#endif

	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_stream_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Stream, __construct, arginfo_phalcon_mvc_model_metadata_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Stream, read, arginfo_phalcon_mvc_model_metadata_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Stream, write, arginfo_phalcon_mvc_model_metadata_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Stream, throwWriteException, arginfo_phalcon_mvc_model_metadata_stream_throwwriteexception, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
