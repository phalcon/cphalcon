
extern zend_class_entry *phalcon_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Loader);

PHP_METHOD(Phalcon_Loader, autoLoad);
PHP_METHOD(Phalcon_Loader, getCheckedPath);
PHP_METHOD(Phalcon_Loader, getClasses);
PHP_METHOD(Phalcon_Loader, getDirs);
PHP_METHOD(Phalcon_Loader, getEventsManager);
PHP_METHOD(Phalcon_Loader, getExtensions);
PHP_METHOD(Phalcon_Loader, getFiles);
PHP_METHOD(Phalcon_Loader, getFoundPath);
PHP_METHOD(Phalcon_Loader, getNamespaces);
PHP_METHOD(Phalcon_Loader, loadFiles);
PHP_METHOD(Phalcon_Loader, register);
PHP_METHOD(Phalcon_Loader, registerClasses);
PHP_METHOD(Phalcon_Loader, registerDirs);
PHP_METHOD(Phalcon_Loader, registerFiles);
PHP_METHOD(Phalcon_Loader, registerNamespaces);
PHP_METHOD(Phalcon_Loader, setEventsManager);
PHP_METHOD(Phalcon_Loader, setExtensions);
PHP_METHOD(Phalcon_Loader, setFileCheckingCallback);
PHP_METHOD(Phalcon_Loader, unregister);
PHP_METHOD(Phalcon_Loader, prepareNamespace);
zend_object *zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_autoload, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getcheckedpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getclasses, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getdirs, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getextensions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getfiles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getfoundpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_getnamespaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_loadfiles, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_register, 0, 0, Phalcon\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_registerclasses, 0, 1, Phalcon\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_registerdirs, 0, 1, Phalcon\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, directories, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_registerfiles, 0, 1, Phalcon\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_registernamespaces, 0, 1, Phalcon\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_setextensions, 0, 1, Phalcon\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_setfilecheckingcallback, 0, 0, Phalcon\\Loader, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_loader_unregister, 0, 0, Phalcon\\Loader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_loader_preparenamespace, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, namespaceName, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_zephir_init_properties_phalcon_loader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_loader_method_entry) {
	PHP_ME(Phalcon_Loader, autoLoad, arginfo_phalcon_loader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getCheckedPath, arginfo_phalcon_loader_getcheckedpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getClasses, arginfo_phalcon_loader_getclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getDirs, arginfo_phalcon_loader_getdirs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getEventsManager, arginfo_phalcon_loader_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getExtensions, arginfo_phalcon_loader_getextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getFiles, arginfo_phalcon_loader_getfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getFoundPath, arginfo_phalcon_loader_getfoundpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getNamespaces, arginfo_phalcon_loader_getnamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, loadFiles, arginfo_phalcon_loader_loadfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, register, arginfo_phalcon_loader_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerClasses, arginfo_phalcon_loader_registerclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerDirs, arginfo_phalcon_loader_registerdirs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerFiles, arginfo_phalcon_loader_registerfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerNamespaces, arginfo_phalcon_loader_registernamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setEventsManager, arginfo_phalcon_loader_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setExtensions, arginfo_phalcon_loader_setextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setFileCheckingCallback, arginfo_phalcon_loader_setfilecheckingcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, unregister, arginfo_phalcon_loader_unregister, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, prepareNamespace, arginfo_phalcon_loader_preparenamespace, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
