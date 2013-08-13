
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

extern zend_class_entry *phalcon_image_adapter_gd_ce;

PHALCON_INIT_CLASS(Phalcon_Image_Adapter_GD);

PHP_METHOD(Phalcon_Image_Adapter_GD, check);
PHP_METHOD(Phalcon_Image_Adapter_GD, __construct);
PHP_METHOD(Phalcon_Image_Adapter_GD, _resize);
PHP_METHOD(Phalcon_Image_Adapter_GD, _liquidRescale);
PHP_METHOD(Phalcon_Image_Adapter_GD, _crop);
PHP_METHOD(Phalcon_Image_Adapter_GD, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_GD, _flip);
PHP_METHOD(Phalcon_Image_Adapter_GD, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_GD, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_GD, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_GD, _mask);
PHP_METHOD(Phalcon_Image_Adapter_GD, _background);
PHP_METHOD(Phalcon_Image_Adapter_GD, _save);
PHP_METHOD(Phalcon_Image_Adapter_GD, _render);
PHP_METHOD(Phalcon_Image_Adapter_GD, _create);
PHP_METHOD(Phalcon_Image_Adapter_GD, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__liquidrescale, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, delta_x)
	ZEND_ARG_INFO(0, rigidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__reflection, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fade_in)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__watermark, 0, 0, 4)
	ZEND_ARG_INFO(0, watermark)
	ZEND_ARG_INFO(0, offset_x)
	ZEND_ARG_INFO(0, offset_y)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__mask, 0, 0, 1)
	ZEND_ARG_INFO(0, mask)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__render, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__create, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_image_adapter_gd_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_GD, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Image_Adapter_GD, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Image_Adapter_GD, _resize, arginfo_phalcon_image_adapter_gd__resize, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _liquidRescale, arginfo_phalcon_image_adapter_gd__liquidrescale, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _crop, arginfo_phalcon_image_adapter_gd__crop, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _rotate, arginfo_phalcon_image_adapter_gd__rotate, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _flip, arginfo_phalcon_image_adapter_gd__flip, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _sharpen, arginfo_phalcon_image_adapter_gd__sharpen, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _reflection, arginfo_phalcon_image_adapter_gd__reflection, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _watermark, arginfo_phalcon_image_adapter_gd__watermark, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _mask, arginfo_phalcon_image_adapter_gd__mask, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _background, arginfo_phalcon_image_adapter_gd__background, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _save, arginfo_phalcon_image_adapter_gd__save, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _render, arginfo_phalcon_image_adapter_gd__render, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, _create, arginfo_phalcon_image_adapter_gd__create, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Image_Adapter_GD, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR) 
	PHP_FE_END
};

