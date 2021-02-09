
extern zend_class_entry *phalcon_image_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getHeight);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getImage);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getMime);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getRealpath);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getType);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, getWidth);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, background);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, blur);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, crop);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, flip);
PHP_METHOD(Phalcon_Image_Adapter_AbstractAdapter, liquidRescale);
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getheight, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getheight, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getimage, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getmime, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getmime, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getrealpath, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_gettype, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_gettype, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getwidth, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_getwidth, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_background, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_background, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_blur, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_blur, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_crop, 0, 2, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_crop, 0, 2, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_flip, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_flip, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, direction)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_liquidrescale, 0, 2, Phalcon\\Image\\Adapter\\AbstractAdapter, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_liquidrescale, 0, 2, IS_OBJECT, "Phalcon\\Image\\Adapter\\AbstractAdapter", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_mask, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_mask, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_pixelate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_pixelate, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_reflection, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_reflection, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_render, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_render, 0, 0, IS_STRING, NULL, 0)
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_resize, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_resize, 0, 0, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_rotate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_rotate, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_save, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_save, 0, 0, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_sharpen, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_sharpen, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_text, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_text, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_watermark, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_abstractadapter_watermark, 0, 1, IS_OBJECT, "Phalcon\\Image\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
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

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getHeight, arginfo_phalcon_image_adapter_abstractadapter_getheight, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getImage, arginfo_phalcon_image_adapter_abstractadapter_getimage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getMime, arginfo_phalcon_image_adapter_abstractadapter_getmime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getRealpath, arginfo_phalcon_image_adapter_abstractadapter_getrealpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getType, arginfo_phalcon_image_adapter_abstractadapter_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, getWidth, arginfo_phalcon_image_adapter_abstractadapter_getwidth, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, background, arginfo_phalcon_image_adapter_abstractadapter_background, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, blur, arginfo_phalcon_image_adapter_abstractadapter_blur, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, crop, arginfo_phalcon_image_adapter_abstractadapter_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, flip, arginfo_phalcon_image_adapter_abstractadapter_flip, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_AbstractAdapter, liquidRescale, arginfo_phalcon_image_adapter_abstractadapter_liquidrescale, ZEND_ACC_PUBLIC)
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
	PHP_FE_END
};
