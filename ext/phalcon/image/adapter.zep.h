
extern zend_class_entry *phalcon_image_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter);

PHP_METHOD(Phalcon_Image_Adapter, getImage);
PHP_METHOD(Phalcon_Image_Adapter, getRealpath);
PHP_METHOD(Phalcon_Image_Adapter, getWidth);
PHP_METHOD(Phalcon_Image_Adapter, getHeight);
PHP_METHOD(Phalcon_Image_Adapter, getType);
PHP_METHOD(Phalcon_Image_Adapter, getMime);
PHP_METHOD(Phalcon_Image_Adapter, resize);
PHP_METHOD(Phalcon_Image_Adapter, liquidRescale);
PHP_METHOD(Phalcon_Image_Adapter, crop);
PHP_METHOD(Phalcon_Image_Adapter, rotate);
PHP_METHOD(Phalcon_Image_Adapter, flip);
PHP_METHOD(Phalcon_Image_Adapter, sharpen);
PHP_METHOD(Phalcon_Image_Adapter, reflection);
PHP_METHOD(Phalcon_Image_Adapter, watermark);
PHP_METHOD(Phalcon_Image_Adapter, text);
PHP_METHOD(Phalcon_Image_Adapter, mask);
PHP_METHOD(Phalcon_Image_Adapter, background);
PHP_METHOD(Phalcon_Image_Adapter, blur);
PHP_METHOD(Phalcon_Image_Adapter, pixelate);
PHP_METHOD(Phalcon_Image_Adapter, save);
PHP_METHOD(Phalcon_Image_Adapter, render);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getwidth, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getwidth, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getheight, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getheight, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gettype, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gettype, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getmime, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_getmime, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_resize, 0, 0, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_resize, 0, 0, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, width)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, height)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, master, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, master)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_liquidrescale, 0, 2, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_liquidrescale, 0, 2, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, width)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, height)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, deltaX, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, deltaX)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rigidity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, rigidity)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_crop, 0, 2, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_crop, 0, 2, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, width)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, height)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, offsetX)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, offsetY)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_rotate, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_rotate, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_flip, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_flip, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, direction)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_sharpen, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_sharpen, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_reflection, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_reflection, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, height)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, opacity)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, fadeIn)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_watermark, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_watermark, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offsetX)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offsetY)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_text, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_text, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, opacity)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, color)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, size)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, fontfile)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_mask, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_mask, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_background, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_background, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, color)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_blur, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_blur, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_pixelate, 0, 1, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_pixelate, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_save, 0, 0, Phalcon\\Image\\Adapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_save, 0, 0, IS_OBJECT, "Phalcon\\Image\\Adapter", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, file)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, quality)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_render, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_render, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ext, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, ext)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, quality)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_method_entry) {
	PHP_ME(Phalcon_Image_Adapter, getImage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getRealpath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getWidth, arginfo_phalcon_image_adapter_getwidth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getHeight, arginfo_phalcon_image_adapter_getheight, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getType, arginfo_phalcon_image_adapter_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getMime, arginfo_phalcon_image_adapter_getmime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, resize, arginfo_phalcon_image_adapter_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, liquidRescale, arginfo_phalcon_image_adapter_liquidrescale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, crop, arginfo_phalcon_image_adapter_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, rotate, arginfo_phalcon_image_adapter_rotate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, flip, arginfo_phalcon_image_adapter_flip, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, sharpen, arginfo_phalcon_image_adapter_sharpen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, reflection, arginfo_phalcon_image_adapter_reflection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, watermark, arginfo_phalcon_image_adapter_watermark, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, text, arginfo_phalcon_image_adapter_text, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, mask, arginfo_phalcon_image_adapter_mask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, background, arginfo_phalcon_image_adapter_background, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, blur, arginfo_phalcon_image_adapter_blur, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, pixelate, arginfo_phalcon_image_adapter_pixelate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, save, arginfo_phalcon_image_adapter_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, render, arginfo_phalcon_image_adapter_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
