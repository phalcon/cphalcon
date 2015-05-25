
extern zend_class_entry *phalcon_mvc_router_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations);

PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix);
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_addmoduleresource, 0, 0, 2)
	ZEND_ARG_INFO(0, module)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processactionannotation, 0, 0, 5)
	ZEND_ARG_INFO(0, module)
	ZEND_ARG_INFO(0, namespaceName)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_annotations_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Annotations, addResource, arginfo_phalcon_mvc_router_annotations_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, addModuleResource, arginfo_phalcon_mvc_router_annotations_addmoduleresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, handle, arginfo_phalcon_mvc_router_annotations_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processControllerAnnotation, arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processActionAnnotation, arginfo_phalcon_mvc_router_annotations_processactionannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setControllerSuffix, arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setActionSuffix, arginfo_phalcon_mvc_router_annotations_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
