
extern zend_class_entry *phalcon_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Loader);

PHP_METHOD(Phalcon_Loader, setFileCheckingCallback);
PHP_METHOD(Phalcon_Loader, setEventsManager);
PHP_METHOD(Phalcon_Loader, getEventsManager);
PHP_METHOD(Phalcon_Loader, setExtensions);
PHP_METHOD(Phalcon_Loader, getExtensions);
PHP_METHOD(Phalcon_Loader, registerNamespaces);
PHP_METHOD(Phalcon_Loader, prepareNamespace);
PHP_METHOD(Phalcon_Loader, getNamespaces);
PHP_METHOD(Phalcon_Loader, registerDirs);
PHP_METHOD(Phalcon_Loader, getDirs);
PHP_METHOD(Phalcon_Loader, registerFiles);
PHP_METHOD(Phalcon_Loader, getFiles);
PHP_METHOD(Phalcon_Loader, registerClasses);
PHP_METHOD(Phalcon_Loader, getClasses);
PHP_METHOD(Phalcon_Loader, register);
PHP_METHOD(Phalcon_Loader, unregister);
PHP_METHOD(Phalcon_Loader, loadFiles);
PHP_METHOD(Phalcon_Loader, autoLoad);
PHP_METHOD(Phalcon_Loader, getFoundPath);
PHP_METHOD(Phalcon_Loader, getCheckedPath);
zend_object_value zephir_init_properties_Phalcon_Loader(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_setfilecheckingcallback, 0, 0, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_setextensions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registernamespaces, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_preparenamespace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerdirs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, directories, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerclasses, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_register, 0, 0, 0)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_loader_method_entry) {
	PHP_ME(Phalcon_Loader, setFileCheckingCallback, arginfo_phalcon_loader_setfilecheckingcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setEventsManager, arginfo_phalcon_loader_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setExtensions, arginfo_phalcon_loader_setextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getExtensions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerNamespaces, arginfo_phalcon_loader_registernamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, prepareNamespace, arginfo_phalcon_loader_preparenamespace, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Loader, getNamespaces, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerDirs, arginfo_phalcon_loader_registerdirs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getDirs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerFiles, arginfo_phalcon_loader_registerfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerClasses, arginfo_phalcon_loader_registerclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getClasses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, register, arginfo_phalcon_loader_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, loadFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, autoLoad, arginfo_phalcon_loader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getFoundPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getCheckedPath, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
