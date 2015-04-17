
<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
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

#ifndef PHALCON_IMAGE_ADAPTER_H
#define PHALCON_IMAGE_ADAPTER_H

#include "php_phalcon.h"

>>>>>>> master:ext/image/adapter.h
extern zend_class_entry *phalcon_image_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter);

<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_resize, 0, 0, 0)
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__resize, 0, 0, 2)
>>>>>>> master:ext/image/adapter.h
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__liquidrescale, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
	ZEND_ARG_INFO(0, deltaX)
	ZEND_ARG_INFO(0, rigidity)
=======
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, regidity)
>>>>>>> master:ext/image/adapter.h
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_reflection, 0, 0, 1)
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__reflection, 0, 0, 3)
>>>>>>> master:ext/image/adapter.h
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_watermark, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__watermark, 0, 0, 4)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
>>>>>>> master:ext/image/adapter.h
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__text, 0, 0, 9)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_pixelate, 0, 0, 1)
=======
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__pixelate, 0, 0, 1)
>>>>>>> master:ext/image/adapter.h
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter__render, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/image/adapter.zep.h
ZEPHIR_INIT_FUNCS(phalcon_image_adapter_method_entry) {
	PHP_ME(Phalcon_Image_Adapter, getImage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getRealpath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getWidth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getHeight, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getMime, NULL, ZEND_ACC_PUBLIC)
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
=======
#endif /* PHALCON_IMAGE_ADAPTER_H */
>>>>>>> master:ext/image/adapter.h
