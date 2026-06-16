
extern zend_class_entry *phalcon_image_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, background);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, blur);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, crop);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, flip);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getHeight);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, mask);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, pixelate);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, reflection);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, render);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, resize);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, rotate);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, save);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, sharpen);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, text);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, watermark);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, checkHighLow);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processBackground);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processBlur);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processCrop);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processFlip);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processMask);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processPixelate);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processReflection);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processRender);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processResize);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processRotate);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processSave);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processSharpen);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processText);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, processWatermark);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, parseColor);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_background, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opacity, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_blur, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_crop, 0, 2, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_flip, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getheight, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getimage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getmime, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getrealpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getwidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_mask, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_pixelate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_reflection, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opacity, IS_LONG, 0, "100")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fadeIn, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_render, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extension, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, quality, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_resize, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, width, IS_LONG, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, height, IS_LONG, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, master, IS_LONG, 0, "4")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_rotate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_save, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, file, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, quality, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_sharpen, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_text, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opacity, IS_LONG, 0, "100")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, color, IS_STRING, 0, "'000000'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, size, IS_LONG, 0, "12")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fontFile, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_watermark, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offsetX, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offsetY, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opacity, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_checkhighlow, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, min, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, max, IS_LONG, 0, "100")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processbackground, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processblur, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processcrop, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processflip, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processmask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processpixelate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processreflection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processrender, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processresize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processrotate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processsave, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processsharpen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processtext, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fontFile, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_processwatermark, 0, 4, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_parsecolor, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, background, arginfo_phalcon_image_adapter_abstractadapter_background, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, blur, arginfo_phalcon_image_adapter_abstractadapter_blur, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, crop, arginfo_phalcon_image_adapter_abstractadapter_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, flip, arginfo_phalcon_image_adapter_abstractadapter_flip, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getHeight, arginfo_phalcon_image_adapter_abstractadapter_getheight, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getImage, arginfo_phalcon_image_adapter_abstractadapter_getimage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getMime, arginfo_phalcon_image_adapter_abstractadapter_getmime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getRealpath, arginfo_phalcon_image_adapter_abstractadapter_getrealpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getType, arginfo_phalcon_image_adapter_abstractadapter_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getWidth, arginfo_phalcon_image_adapter_abstractadapter_getwidth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, mask, arginfo_phalcon_image_adapter_abstractadapter_mask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, pixelate, arginfo_phalcon_image_adapter_abstractadapter_pixelate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, reflection, arginfo_phalcon_image_adapter_abstractadapter_reflection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, render, arginfo_phalcon_image_adapter_abstractadapter_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, resize, arginfo_phalcon_image_adapter_abstractadapter_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, rotate, arginfo_phalcon_image_adapter_abstractadapter_rotate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, save, arginfo_phalcon_image_adapter_abstractadapter_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, sharpen, arginfo_phalcon_image_adapter_abstractadapter_sharpen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, text, arginfo_phalcon_image_adapter_abstractadapter_text, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, watermark, arginfo_phalcon_image_adapter_abstractadapter_watermark, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, checkHighLow, arginfo_phalcon_image_adapter_abstractadapter_checkhighlow, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processBackground, arginfo_phalcon_image_adapter_abstractadapter_processbackground, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processBlur, arginfo_phalcon_image_adapter_abstractadapter_processblur, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processCrop, arginfo_phalcon_image_adapter_abstractadapter_processcrop, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processFlip, arginfo_phalcon_image_adapter_abstractadapter_processflip, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processMask, arginfo_phalcon_image_adapter_abstractadapter_processmask, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processPixelate, arginfo_phalcon_image_adapter_abstractadapter_processpixelate, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processReflection, arginfo_phalcon_image_adapter_abstractadapter_processreflection, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processRender, arginfo_phalcon_image_adapter_abstractadapter_processrender, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processResize, arginfo_phalcon_image_adapter_abstractadapter_processresize, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processRotate, arginfo_phalcon_image_adapter_abstractadapter_processrotate, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processSave, arginfo_phalcon_image_adapter_abstractadapter_processsave, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processSharpen, arginfo_phalcon_image_adapter_abstractadapter_processsharpen, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processText, arginfo_phalcon_image_adapter_abstractadapter_processtext, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, processWatermark, arginfo_phalcon_image_adapter_abstractadapter_processwatermark, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, parseColor, arginfo_phalcon_image_adapter_abstractadapter_parsecolor, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
