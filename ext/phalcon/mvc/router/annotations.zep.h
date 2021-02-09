
extern zend_class_entry *phalcon_mvc_router_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations);

PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionPreformatCallback);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getActionPreformatCallback);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix);
zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_annotations_addmoduleresource, 0, 2, Phalcon\\Mvc\\Router\\Annotations, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_addmoduleresource, 0, 2, IS_OBJECT, "Phalcon\\Mvc\\Router\\Annotations", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, module, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, module)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, handler, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, handler)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_annotations_addresource, 0, 1, Phalcon\\Mvc\\Router\\Annotations, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_addresource, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Router\\Annotations", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, handler, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, handler)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_getresources, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_getresources, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_handle, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_annotations_handle, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_handle, 0, 0, 1)
#define arginfo_phalcon_mvc_router_annotations_handle NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processactionannotation, 0, 0, 5)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, module, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, module)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, namespaceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controller, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controller)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, action)
#endif
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, handler, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, handler)
#endif
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setactionsuffix, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionSuffix)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setactionpreformatcallback, 0, 0, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_getactionpreformatcallback, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerSuffix)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_zephir_init_properties_phalcon_mvc_router_annotations, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_annotations_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Annotations, addModuleResource, arginfo_phalcon_mvc_router_annotations_addmoduleresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, addResource, arginfo_phalcon_mvc_router_annotations_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, getResources, arginfo_phalcon_mvc_router_annotations_getresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, handle, arginfo_phalcon_mvc_router_annotations_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processActionAnnotation, arginfo_phalcon_mvc_router_annotations_processactionannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processControllerAnnotation, arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setActionSuffix, arginfo_phalcon_mvc_router_annotations_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setActionPreformatCallback, arginfo_phalcon_mvc_router_annotations_setactionpreformatcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, getActionPreformatCallback, arginfo_phalcon_mvc_router_annotations_getactionpreformatcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setControllerSuffix, arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
