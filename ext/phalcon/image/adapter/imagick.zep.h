
extern zend_class_entry *phalcon_image_adapter_imagick_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick);

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBackground);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBlur);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processCrop);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processFlip);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processLiquidRescale);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processMask);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processPixelate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processReflection);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processRender);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processResize);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processRotate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSave);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSharpen);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processText);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processWatermark);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_imagick_getinternaliminstance, 0, 0, Imagick, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_setresourcelimit, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processbackground, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processblur, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processcrop, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processflip, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processliquidrescale, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, deltaX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rigidity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processmask, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processpixelate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processreflection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processrender, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processresize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processrotate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_processsave, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_processsharpen, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_processtext, 0, 0, 9)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_processwatermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_imagick_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Imagick, __construct, arginfo_phalcon_image_adapter_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Image_Adapter_Imagick, __destruct, arginfo_phalcon_image_adapter_imagick___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Phalcon_Image_Adapter_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_ME(Phalcon_Image_Adapter_Imagick, check, arginfo_phalcon_image_adapter_imagick_check, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, getInternalImInstance, arginfo_phalcon_image_adapter_imagick_getinternaliminstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, setResourceLimit, arginfo_phalcon_image_adapter_imagick_setresourcelimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processBackground, arginfo_phalcon_image_adapter_imagick_processbackground, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processBlur, arginfo_phalcon_image_adapter_imagick_processblur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processCrop, arginfo_phalcon_image_adapter_imagick_processcrop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processFlip, arginfo_phalcon_image_adapter_imagick_processflip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processLiquidRescale, arginfo_phalcon_image_adapter_imagick_processliquidrescale, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processMask, arginfo_phalcon_image_adapter_imagick_processmask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processPixelate, arginfo_phalcon_image_adapter_imagick_processpixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processReflection, arginfo_phalcon_image_adapter_imagick_processreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processRender, arginfo_phalcon_image_adapter_imagick_processrender, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processResize, arginfo_phalcon_image_adapter_imagick_processresize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processRotate, arginfo_phalcon_image_adapter_imagick_processrotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processSave, arginfo_phalcon_image_adapter_imagick_processsave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processSharpen, arginfo_phalcon_image_adapter_imagick_processsharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processText, arginfo_phalcon_image_adapter_imagick_processtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, processWatermark, arginfo_phalcon_image_adapter_imagick_processwatermark, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
