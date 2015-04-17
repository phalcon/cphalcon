
<<<<<<< HEAD:ext/phalcon/image/adapterinterface.zep.h
=======
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_IMAGE_ADAPTERINTERFACE_H
#define PHALCON_IMAGE_ADAPTERINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/image/adapterinterface.h
extern zend_class_entry *phalcon_image_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
<<<<<<< HEAD:ext/phalcon/image/adapterinterface.zep.h
=======
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_liquidrescale, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, rigidity)
>>>>>>> master:ext/image/adapterinterface.h
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_reflection, 0, 0, 1)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_watermark, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_blur, 0, 0, 0)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_pixelate, 0, 0, 0)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/image/adapterinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_image_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, resize, arginfo_phalcon_image_adapterinterface_resize)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, crop, arginfo_phalcon_image_adapterinterface_crop)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, rotate, arginfo_phalcon_image_adapterinterface_rotate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, flip, arginfo_phalcon_image_adapterinterface_flip)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, sharpen, arginfo_phalcon_image_adapterinterface_sharpen)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, reflection, arginfo_phalcon_image_adapterinterface_reflection)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, watermark, arginfo_phalcon_image_adapterinterface_watermark)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, text, arginfo_phalcon_image_adapterinterface_text)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, mask, arginfo_phalcon_image_adapterinterface_mask)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, background, arginfo_phalcon_image_adapterinterface_background)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, blur, arginfo_phalcon_image_adapterinterface_blur)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, pixelate, arginfo_phalcon_image_adapterinterface_pixelate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, save, arginfo_phalcon_image_adapterinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, render, arginfo_phalcon_image_adapterinterface_render)
  PHP_FE_END
};
=======
#endif /* PHALCON_IMAGE_ADAPTERINTERFACE_H */
>>>>>>> master:ext/image/adapterinterface.h
