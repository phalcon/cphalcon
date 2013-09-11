
extern zend_class_entry *phalcon_mvc_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setconnectionservice, 0, 0, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_readattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_writeattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 0, 0)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, document)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_appendmessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, __construct, arginfo_phalcon_mvc_collectioninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setId, arginfo_phalcon_mvc_collectioninterface_setid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getReservedAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setConnectionService, arginfo_phalcon_mvc_collectioninterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, readAttribute, arginfo_phalcon_mvc_collectioninterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, writeAttribute, arginfo_phalcon_mvc_collectioninterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, cloneResult, arginfo_phalcon_mvc_collectioninterface_cloneresult)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEvent, arginfo_phalcon_mvc_collectioninterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEventCancel, arginfo_phalcon_mvc_collectioninterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, appendMessage, arginfo_phalcon_mvc_collectioninterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, save, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, findById, arginfo_phalcon_mvc_collectioninterface_findbyid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, findFirst, arginfo_phalcon_mvc_collectioninterface_findfirst)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, find, arginfo_phalcon_mvc_collectioninterface_find)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, count, arginfo_phalcon_mvc_collectioninterface_count)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, delete, NULL)
	PHP_FE_END
};
