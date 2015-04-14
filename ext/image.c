
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
  +------------------------------------------------------------------------+
*/

#include "image.h"
#include "image/adapter/gd.h"
#include "image/adapter/imagick.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"

/**
 * Phalcon\Image
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 *	$image = Phalcon\Image::factory("upload/test.jpg");
 *	$image->resize(200, 200);
 *	$image->save();
 *</code>
 */
zend_class_entry *phalcon_image_ce;

PHP_METHOD(Phalcon_Image, factory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_factory, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_image_method_entry[] = {
	PHP_ME(Phalcon_Image, factory, arginfo_phalcon_image_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Image initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image){

	PHALCON_REGISTER_CLASS(Phalcon, Image, image, phalcon_image_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/* Resizing constraints */
	zend_declare_class_constant_long(phalcon_image_ce, SL("NONE"),    PHALCON_IMAGE_NONE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("WIDTH"),   PHALCON_IMAGE_WIDTH TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("HEIGHT"),  PHALCON_IMAGE_HEIGHT TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("AUTO"),    PHALCON_IMAGE_AUTO TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("INVERSE"), PHALCON_IMAGE_INVERSE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("PRECISE"), PHALCON_IMAGE_PRECISE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("TENSILE"), PHALCON_IMAGE_TENSILE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("NARROW"),  PHALCON_IMAGE_NARROW TSRMLS_CC);

	/* Flipping directions */
	zend_declare_class_constant_long(phalcon_image_ce, SL("HORIZONTAL"), PHALCON_IMAGE_HORIZONTAL TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("VERTICAL"),   PHALCON_IMAGE_VERTICAL TSRMLS_CC);

	/* Driver: GD, ImageMagick, etc */
	zend_declare_class_constant_long(phalcon_image_ce, SL("GD"),      PHALCON_IMAGE_GD TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("IMAGICK"), PHALCON_IMAGE_IMAGICK TSRMLS_CC);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Image, factory){
	zval *file, *width = NULL, *height = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &file, &width, &height);

	if (!width) {
		width = PHALCON_GLOBAL(z_null);
	}

	if (!height) {
		height = PHALCON_GLOBAL(z_null);
	}

	if (phalcon_class_exists(SL("imagick"), 0 TSRMLS_CC)) {
		object_init_ex(return_value, phalcon_image_adapter_imagick_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", file, width, height);
	} else {
		object_init_ex(return_value, phalcon_image_adapter_gd_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", file, width, height);
	}

	PHALCON_MM_RESTORE();
}
