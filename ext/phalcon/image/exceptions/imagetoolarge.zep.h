
extern zend_class_entry *phalcon_image_exceptions_imagetoolarge_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_ImageTooLarge);

PHP_METHOD(Phalcon_Image_Exceptions_ImageTooLarge, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_exceptions_imagetoolarge___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxPixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_exceptions_imagetoolarge_method_entry) {
	PHP_ME(Phalcon_Image_Exceptions_ImageTooLarge, __construct, arginfo_phalcon_image_exceptions_imagetoolarge___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
