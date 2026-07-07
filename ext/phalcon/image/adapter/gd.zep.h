
extern zend_class_entry *phalcon_image_adapter_gd_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd);

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct);
PHP_METHOD(Phalcon_Image_Adapter_Gd, create);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, check);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFclose);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFgetCsv);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFileExists);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFileGetContents);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFilePutContents);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFopen);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFwrite);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpIsWritable);
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, width, IS_LONG, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, height, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_image_adapter_gd_create, 0, 2, Phalcon\\Image\\Adapter\\AbstractAdapter, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processbackground, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processblur, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processcreate, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processcrop, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processflip, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processmask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processpixelate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processreflection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd_processrender, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, extension, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processresize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processrotate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processsave, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processsharpen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processtext, 0, 8, IS_VOID, 0)

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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_processwatermark, 0, 4, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_check, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_image_adapter_gd_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_image_adapter_gd_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_image_adapter_gd_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_image_adapter_gd_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_gd_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Gd, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, arginfo_phalcon_image_adapter_gd___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Image_Adapter_Gd, create, arginfo_phalcon_image_adapter_gd_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Gd, getVersion, arginfo_phalcon_image_adapter_gd_getversion, ZEND_ACC_PUBLIC)
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
	PHP_ME(Phalcon_Image_Adapter_Gd, check, arginfo_phalcon_image_adapter_gd_check, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFclose, arginfo_phalcon_image_adapter_gd_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFgetCsv, arginfo_phalcon_image_adapter_gd_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFileExists, arginfo_phalcon_image_adapter_gd_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFileGetContents, arginfo_phalcon_image_adapter_gd_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFilePutContents, arginfo_phalcon_image_adapter_gd_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFopen, arginfo_phalcon_image_adapter_gd_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpFwrite, arginfo_phalcon_image_adapter_gd_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpIsWritable, arginfo_phalcon_image_adapter_gd_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, phpUnlink, arginfo_phalcon_image_adapter_gd_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
