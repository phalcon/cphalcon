
extern zend_class_entry *phalcon_image_exceptions_unsupportedimagetype_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_UnsupportedImageType);

PHP_METHOD(Phalcon_Image_Exceptions_UnsupportedImageType, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_exceptions_unsupportedimagetype___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, format, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_exceptions_unsupportedimagetype_method_entry) {
	PHP_ME(Phalcon_Image_Exceptions_UnsupportedImageType, __construct, arginfo_phalcon_image_exceptions_unsupportedimagetype___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
