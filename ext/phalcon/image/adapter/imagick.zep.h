
extern zend_class_entry *phalcon_image_adapter_imagick_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick);

PHP_METHOD(Phalcon_Image_Adapter_Imagick, check);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_check, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_check, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
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
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__resize, 0, 0, 2)
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
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__liquidrescale, 0, 0, 4)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__crop, 0, 0, 4)
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
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offsetX)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, offsetY)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__rotate, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__flip, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, direction)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__sharpen, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__reflection, 0, 0, 3)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__watermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__text, 0, 0, 9)
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
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, r)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, g)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, b)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, size)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fontfile)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__background, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, r)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, g)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, b)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__blur, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__pixelate, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, amount)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__save, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick__render, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick__render, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, extension)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, quality)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_imagick_getinternaliminstance, 0, 0, Imagick, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_imagick_getinternaliminstance, 0, 0, IS_OBJECT, "Imagick", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_setresourcelimit, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_imagick_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Imagick, check, arginfo_phalcon_image_adapter_imagick_check, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __construct, arginfo_phalcon_image_adapter_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _resize, arginfo_phalcon_image_adapter_imagick__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _liquidRescale, arginfo_phalcon_image_adapter_imagick__liquidrescale, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _crop, arginfo_phalcon_image_adapter_imagick__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _rotate, arginfo_phalcon_image_adapter_imagick__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _flip, arginfo_phalcon_image_adapter_imagick__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _sharpen, arginfo_phalcon_image_adapter_imagick__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _reflection, arginfo_phalcon_image_adapter_imagick__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _watermark, arginfo_phalcon_image_adapter_imagick__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _text, arginfo_phalcon_image_adapter_imagick__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _mask, arginfo_phalcon_image_adapter_imagick__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _background, arginfo_phalcon_image_adapter_imagick__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _blur, arginfo_phalcon_image_adapter_imagick__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _pixelate, arginfo_phalcon_image_adapter_imagick__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _save, arginfo_phalcon_image_adapter_imagick__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _render, arginfo_phalcon_image_adapter_imagick__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, getInternalImInstance, arginfo_phalcon_image_adapter_imagick_getinternaliminstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, setResourceLimit, arginfo_phalcon_image_adapter_imagick_setresourcelimit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
