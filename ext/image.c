
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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
 *	$$image->save();
 *</code>
 */


/**
 * Phalcon\Image initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image){

	PHALCON_REGISTER_CLASS(Phalcon, Image, image, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);
	
	// Resizing constraints
	zend_declare_class_constant_long(phalcon_image_ce, SL("NONE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("WIDTH"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("HEIGHT"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("AUTO"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("INVERSE"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("PRECISE"), 6 TSRMLS_CC);

	// Flipping directions
	zend_declare_class_constant_long(phalcon_image_ce, SL("HORIZONTAL"), 11 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("VERTICAL"), 12 TSRMLS_CC);

	// Driver: GD, ImageMagick, etc
	zend_declare_class_constant_long(phalcon_image_ce, SL("GD"), 21 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_image_ce, SL("IMAGICK"), 22 TSRMLS_CC);

	return SUCCESS;
}