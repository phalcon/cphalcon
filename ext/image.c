
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

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Phalcon\Image
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 *	$image = new Phalcon\Image\Adapter\GD("upload/test.jpg");
 *	$image->resize(200, 200);
 *	$image->save();
 *</code>
 */
zend_class_entry *phalcon_image_ce;

/**
 * Phalcon\Image initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image){

	PHALCON_REGISTER_CLASS(Phalcon, Image, image, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);
	
	/* Resizing constraints */
	zend_declare_class_constant_long(phalcon_image_ce, SL("NONE"),    PHALCON_IMAGE_NONE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("WIDTH"),   PHALCON_IMAGE_WIDTH TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("HEIGHT"),  PHALCON_IMAGE_HEIGHT TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("AUTO"),    PHALCON_IMAGE_AUTO TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("INVERSE"), PHALCON_IMAGE_INVERSE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("PRECISE"), PHALCON_IMAGE_PRECISE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("TENSILE"), PHALCON_IMAGE_TENSILE TSRMLS_CC);

	/* Flipping directions */
	zend_declare_class_constant_long(phalcon_image_ce, SL("HORIZONTAL"), PHALCON_IMAGE_HORIZONTAL TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("VERTICAL"),   PHALCON_IMAGE_VERTICAL TSRMLS_CC);

	/* Driver: GD, ImageMagick, etc */
	zend_declare_class_constant_long(phalcon_image_ce, SL("GD"),      PHALCON_IMAGE_GD TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("IMAGICK"), PHALCON_IMAGE_IMAGICK TSRMLS_CC);

	return SUCCESS;
}
