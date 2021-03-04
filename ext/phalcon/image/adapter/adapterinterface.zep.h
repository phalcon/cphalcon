
extern zend_class_entry *phalcon_image_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AdapterInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_background, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_blur, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_crop, 0, 2, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_flip, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_mask, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_pixelate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_reflection, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_render, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ext, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_resize, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, master, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_rotate, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_save, 0, 0, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_sharpen, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_text, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_adapterinterface_watermark, 0, 1, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, background, arginfo_phalcon_image_adapter_adapterinterface_background)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, blur, arginfo_phalcon_image_adapter_adapterinterface_blur)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, crop, arginfo_phalcon_image_adapter_adapterinterface_crop)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, flip, arginfo_phalcon_image_adapter_adapterinterface_flip)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, mask, arginfo_phalcon_image_adapter_adapterinterface_mask)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, pixelate, arginfo_phalcon_image_adapter_adapterinterface_pixelate)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, reflection, arginfo_phalcon_image_adapter_adapterinterface_reflection)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, render, arginfo_phalcon_image_adapter_adapterinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, resize, arginfo_phalcon_image_adapter_adapterinterface_resize)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, rotate, arginfo_phalcon_image_adapter_adapterinterface_rotate)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, save, arginfo_phalcon_image_adapter_adapterinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, sharpen, arginfo_phalcon_image_adapter_adapterinterface_sharpen)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, text, arginfo_phalcon_image_adapter_adapterinterface_text)
	PHP_ABSTRACT_ME(Phalcon_Image_Adapter_AdapterInterface, watermark, arginfo_phalcon_image_adapter_adapterinterface_watermark)
	PHP_FE_END
};
