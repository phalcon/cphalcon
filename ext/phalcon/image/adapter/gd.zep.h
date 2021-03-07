
extern zend_class_entry *phalcon_image_adapter_gd_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd);

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct);
PHP_METHOD(Phalcon_Image_Adapter_Gd, check);
PHP_METHOD(Phalcon_Image_Adapter_Gd, getVersion);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processBackground);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processBlur);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processCreate);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processCrop);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processFlip);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processMask);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processPixelate);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processReflection);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processRender);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processResize);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processRotate);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processSave);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processSharpen);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processText);
PHP_METHOD(Phalcon_Image_Adapter_Gd, processWatermark);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processbackground, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processblur, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processcreate, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processcrop, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processflip, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processmask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processpixelate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processreflection, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processrender, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, ext, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processresize, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processrotate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processsave, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processsharpen, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processtext, 0, 0, 9)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processwatermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_gd_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Gd, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, arginfo_phalcon_image_adapter_gd___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_ME(Phalcon_Image_Adapter_Gd, check, arginfo_phalcon_image_adapter_gd_check, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Gd, getVersion, arginfo_phalcon_image_adapter_gd_getversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Gd, processBackground, arginfo_phalcon_image_adapter_gd_processbackground, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processBlur, arginfo_phalcon_image_adapter_gd_processblur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processCreate, arginfo_phalcon_image_adapter_gd_processcreate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processCrop, arginfo_phalcon_image_adapter_gd_processcrop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processFlip, arginfo_phalcon_image_adapter_gd_processflip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processMask, arginfo_phalcon_image_adapter_gd_processmask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processPixelate, arginfo_phalcon_image_adapter_gd_processpixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processReflection, arginfo_phalcon_image_adapter_gd_processreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processRender, arginfo_phalcon_image_adapter_gd_processrender, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processResize, arginfo_phalcon_image_adapter_gd_processresize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processRotate, arginfo_phalcon_image_adapter_gd_processrotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processSave, arginfo_phalcon_image_adapter_gd_processsave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processSharpen, arginfo_phalcon_image_adapter_gd_processsharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processText, arginfo_phalcon_image_adapter_gd_processtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, processWatermark, arginfo_phalcon_image_adapter_gd_processwatermark, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
