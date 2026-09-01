
extern zend_class_entry *phalcon_image_exceptions_versionmismatch_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_VersionMismatch);

PHP_METHOD(Phalcon_Image_Exceptions_VersionMismatch, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_exceptions_versionmismatch___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_exceptions_versionmismatch_method_entry) {
	PHP_ME(Phalcon_Image_Exceptions_VersionMismatch, __construct, arginfo_phalcon_image_exceptions_versionmismatch___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
