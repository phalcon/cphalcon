
extern zend_class_entry *phalcon_firewall_adapter_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Annotations);

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getAnnotationsAdapter);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, setAnnotationsAdapter);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, __construct);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, beforeExecuteRoute);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getDispatcher);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkControllerAnnotationAccess);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkAnnotations);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkActionAnnotationAccess);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getAccessFromCache);
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, handleAnnotation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_setannotationsadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, annotationsAdapter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, annotationsAdapter, Phalcon\\Annotations\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_beforeexecuteroute, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\DispatcherInterface, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_getdispatcher, 0, 0, Phalcon\\Firewall\\Adapter\\Dispatcher, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_getdispatcher, 0, 0, IS_OBJECT, "Phalcon\\Firewall\\Adapter\\Dispatcher", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_checkcontrollerannotationaccess, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerClass)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_checkannotations, 0, 0, 2)
	ZEND_ARG_INFO(0, annotations)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_checkactionannotationaccess, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerClass)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionName)
#endif
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_getaccessfromcache, 0, 1, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_getaccessfromcache, 0, 1, _IS_BOOL, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_ARRAY_INFO(0, originalValues, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleCacheKey, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, roleCacheKey)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_firewall_adapter_annotations_handleannotation, 0, 0, 3)
	ZEND_ARG_INFO(0, annotation)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_firewall_adapter_annotations_method_entry) {
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, getAnnotationsAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, setAnnotationsAdapter, arginfo_phalcon_firewall_adapter_annotations_setannotationsadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, __construct, arginfo_phalcon_firewall_adapter_annotations___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, beforeExecuteRoute, arginfo_phalcon_firewall_adapter_annotations_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, getDispatcher, arginfo_phalcon_firewall_adapter_annotations_getdispatcher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, checkControllerAnnotationAccess, arginfo_phalcon_firewall_adapter_annotations_checkcontrollerannotationaccess, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, checkAnnotations, arginfo_phalcon_firewall_adapter_annotations_checkannotations, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, checkActionAnnotationAccess, arginfo_phalcon_firewall_adapter_annotations_checkactionannotationaccess, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, getAccessFromCache, arginfo_phalcon_firewall_adapter_annotations_getaccessfromcache, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Firewall_Adapter_Annotations, handleAnnotation, arginfo_phalcon_firewall_adapter_annotations_handleannotation, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
