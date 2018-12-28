
extern zend_class_entry *phalcon_mvc_collection_document_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Document);

PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet);
PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Collection_Document, toArray);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_readattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_writeattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_document_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_collection_document_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_document_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetExists, arginfo_phalcon_mvc_collection_document_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetGet, arginfo_phalcon_mvc_collection_document_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetSet, arginfo_phalcon_mvc_collection_document_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetUnset, arginfo_phalcon_mvc_collection_document_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, readAttribute, arginfo_phalcon_mvc_collection_document_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, writeAttribute, arginfo_phalcon_mvc_collection_document_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, toArray, arginfo_phalcon_mvc_collection_document_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
