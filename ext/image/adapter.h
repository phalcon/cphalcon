
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
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_image_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter);

PHP_METHOD(Phalcon_Image_Adapter, __construct);
PHP_METHOD(Phalcon_Image_Adapter, getRealPath);
PHP_METHOD(Phalcon_Image_Adapter, getWidth);
PHP_METHOD(Phalcon_Image_Adapter, getHeight);
PHP_METHOD(Phalcon_Image_Adapter, getType);
PHP_METHOD(Phalcon_Image_Adapter, getMime);
PHP_METHOD(Phalcon_Image_Adapter, getImage);
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
PHP_METHOD(Phalcon_Image_Adapter, save);
PHP_METHOD(Phalcon_Image_Adapter, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_liquidrescale, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, rigidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_reflection, 0, 0, 0)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_render, 0, 0, 0)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_image_adapter_method_entry){
	PHP_ME(Phalcon_Image_Adapter, __construct, arginfo_phalcon_image_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Image_Adapter, getRealPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, getWidth, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, getHeight, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, getMime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, getImage, NULL, ZEND_ACC_PUBLIC) 
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
	PHP_ME(Phalcon_Image_Adapter, save, arginfo_phalcon_image_adapter_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Image_Adapter, render, arginfo_phalcon_image_adapter_render, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

