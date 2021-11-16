
extern zend_class_entry *phalcon_image_imagefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_ImageFactory);

PHP_METHOD(Phalcon_Image_ImageFactory, __construct);
PHP_METHOD(Phalcon_Image_ImageFactory, load);
PHP_METHOD(Phalcon_Image_ImageFactory, newInstance);
PHP_METHOD(Phalcon_Image_ImageFactory, getExceptionClass);
PHP_METHOD(Phalcon_Image_ImageFactory, getServices);
PHP_METHOD(Phalcon_Image_ImageFactory, getArrVal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_imagefactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_imagefactory_load, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_imagefactory_newinstance, 0, 2, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_imagefactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_imagefactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_imagefactory_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_imagefactory_method_entry) {
	PHP_ME(Phalcon_Image_ImageFactory, __construct, arginfo_phalcon_image_imagefactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_ImageFactory, load, arginfo_phalcon_image_imagefactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_ImageFactory, newInstance, arginfo_phalcon_image_imagefactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_ImageFactory, getExceptionClass, arginfo_phalcon_image_imagefactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_ImageFactory, getServices, arginfo_phalcon_image_imagefactory_getservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_ImageFactory, getArrVal, arginfo_phalcon_image_imagefactory_getarrval, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
