
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

extern zend_class_entry *phalcon_image_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Image_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_reflection, 0, 0, 0)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_image_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, resize, arginfo_phalcon_image_adapterinterface_resize)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, crop, arginfo_phalcon_image_adapterinterface_crop)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, rotate, arginfo_phalcon_image_adapterinterface_rotate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, flip, arginfo_phalcon_image_adapterinterface_flip)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, sharpen, arginfo_phalcon_image_adapterinterface_sharpen)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, reflection, arginfo_phalcon_image_adapterinterface_reflection)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, watermark, arginfo_phalcon_image_adapterinterface_watermark)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, background, arginfo_phalcon_image_adapterinterface_background)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, save, arginfo_phalcon_image_adapterinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, render, arginfo_phalcon_image_adapterinterface_render)
	PHP_FE_END
};

