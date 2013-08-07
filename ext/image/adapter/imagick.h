
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_image_adapter_imagick_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter_Imagick);

PHP_METHOD(Phalcon_Image_Adapter_Imagick, check);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save);
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__reflection, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__watermark, 0, 0, 4)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__render, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_image_adapter_imagick_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Imagick, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, __construct, arginfo_phalcon_image_adapter_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _resize, arginfo_phalcon_image_adapter_imagick__resize, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _crop, arginfo_phalcon_image_adapter_imagick__crop, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _rotate, arginfo_phalcon_image_adapter_imagick__rotate, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _flip, arginfo_phalcon_image_adapter_imagick__flip, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _sharpen, arginfo_phalcon_image_adapter_imagick__sharpen, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _reflection, arginfo_phalcon_image_adapter_imagick__reflection, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _watermark, arginfo_phalcon_image_adapter_imagick__watermark, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _background, arginfo_phalcon_image_adapter_imagick__background, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _save, arginfo_phalcon_image_adapter_imagick__save, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_Imagick, _render, arginfo_phalcon_image_adapter_imagick__render, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};

