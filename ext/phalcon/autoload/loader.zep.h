
extern zend_class_entry *phalcon_autoload_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Autoload_Loader);

PHP_METHOD(Phalcon_Autoload_Loader, __construct);
PHP_METHOD(Phalcon_Autoload_Loader, addClass);
PHP_METHOD(Phalcon_Autoload_Loader, addDirectory);
PHP_METHOD(Phalcon_Autoload_Loader, addExtension);
PHP_METHOD(Phalcon_Autoload_Loader, addFile);
PHP_METHOD(Phalcon_Autoload_Loader, addNamespace);
PHP_METHOD(Phalcon_Autoload_Loader, autoload);
PHP_METHOD(Phalcon_Autoload_Loader, getCheckedPath);
PHP_METHOD(Phalcon_Autoload_Loader, getClasses);
PHP_METHOD(Phalcon_Autoload_Loader, getDebug);
PHP_METHOD(Phalcon_Autoload_Loader, getDirectories);
PHP_METHOD(Phalcon_Autoload_Loader, getExtensions);
PHP_METHOD(Phalcon_Autoload_Loader, getFiles);
PHP_METHOD(Phalcon_Autoload_Loader, getFoundPath);
PHP_METHOD(Phalcon_Autoload_Loader, getNamespaces);
PHP_METHOD(Phalcon_Autoload_Loader, loadFiles);
PHP_METHOD(Phalcon_Autoload_Loader, register);
PHP_METHOD(Phalcon_Autoload_Loader, setClasses);
PHP_METHOD(Phalcon_Autoload_Loader, setDirectories);
PHP_METHOD(Phalcon_Autoload_Loader, setExtensions);
PHP_METHOD(Phalcon_Autoload_Loader, setFileCheckingCallback);
PHP_METHOD(Phalcon_Autoload_Loader, setFiles);
PHP_METHOD(Phalcon_Autoload_Loader, setNamespaces);
PHP_METHOD(Phalcon_Autoload_Loader, unregister);
PHP_METHOD(Phalcon_Autoload_Loader, requireFile);
PHP_METHOD(Phalcon_Autoload_Loader, addDebug);
PHP_METHOD(Phalcon_Autoload_Loader, addToCollection);
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckClasses);
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckDirectories);
PHP_METHOD(Phalcon_Autoload_Loader, autoloadCheckNamespaces);
PHP_METHOD(Phalcon_Autoload_Loader, checkDirectories);
zend_object *zephir_init_properties_Phalcon_Autoload_Loader(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_autoload_loader___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, isDebug, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_addclass, 0, 2, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_adddirectory, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, directory, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_addextension, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_addfile, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_addnamespace, 0, 2, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, directories)
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_autoload, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getcheckedpath, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getclasses, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getdebug, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getdirectories, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getextensions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getfiles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getfoundpath, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_getnamespaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_loadfiles, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_register, 0, 0, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setclasses, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setdirectories, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, directories, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setextensions, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setfilecheckingcallback, 0, 0, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setfiles, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_setnamespaces, 0, 1, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_unregister, 0, 0, Phalcon\\Autoload\\Loader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_requirefile, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_adddebug, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_autoload_loader_addtocollection, 0, 3, Phalcon\\Autoload\\Loader, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_TYPE_INFO(0, collectionName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_autoloadcheckclasses, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_autoloadcheckdirectories, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, directories, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, isDirectory, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_autoloadchecknamespaces, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_autoload_loader_checkdirectories, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, directories)
	ZEND_ARG_TYPE_INFO(0, dirSeparator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_autoload_loader_zephir_init_properties_phalcon_autoload_loader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_autoload_loader_method_entry) {
	PHP_ME(Phalcon_Autoload_Loader, __construct, arginfo_phalcon_autoload_loader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Autoload_Loader, addClass, arginfo_phalcon_autoload_loader_addclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, addDirectory, arginfo_phalcon_autoload_loader_adddirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, addExtension, arginfo_phalcon_autoload_loader_addextension, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, addFile, arginfo_phalcon_autoload_loader_addfile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, addNamespace, arginfo_phalcon_autoload_loader_addnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, autoload, arginfo_phalcon_autoload_loader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getCheckedPath, arginfo_phalcon_autoload_loader_getcheckedpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getClasses, arginfo_phalcon_autoload_loader_getclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getDebug, arginfo_phalcon_autoload_loader_getdebug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getDirectories, arginfo_phalcon_autoload_loader_getdirectories, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getExtensions, arginfo_phalcon_autoload_loader_getextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getFiles, arginfo_phalcon_autoload_loader_getfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getFoundPath, arginfo_phalcon_autoload_loader_getfoundpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, getNamespaces, arginfo_phalcon_autoload_loader_getnamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, loadFiles, arginfo_phalcon_autoload_loader_loadfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, register, arginfo_phalcon_autoload_loader_register, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setClasses, arginfo_phalcon_autoload_loader_setclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setDirectories, arginfo_phalcon_autoload_loader_setdirectories, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setExtensions, arginfo_phalcon_autoload_loader_setextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setFileCheckingCallback, arginfo_phalcon_autoload_loader_setfilecheckingcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setFiles, arginfo_phalcon_autoload_loader_setfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, setNamespaces, arginfo_phalcon_autoload_loader_setnamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, unregister, arginfo_phalcon_autoload_loader_unregister, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Autoload_Loader, requireFile, arginfo_phalcon_autoload_loader_requirefile, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Autoload_Loader, addDebug, arginfo_phalcon_autoload_loader_adddebug, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Autoload_Loader, addToCollection, arginfo_phalcon_autoload_loader_addtocollection, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Autoload_Loader, autoloadCheckClasses, arginfo_phalcon_autoload_loader_autoloadcheckclasses, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Autoload_Loader, autoloadCheckDirectories, arginfo_phalcon_autoload_loader_autoloadcheckdirectories, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Autoload_Loader, autoloadCheckNamespaces, arginfo_phalcon_autoload_loader_autoloadchecknamespaces, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Autoload_Loader, checkDirectories, arginfo_phalcon_autoload_loader_checkdirectories, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
