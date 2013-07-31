
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
 *	$image = new Phalcon\Image\Adapter\GD("'upload/test.jpg'");
 *	$image->resize(200, 200);
 *	$$image->save();
 *</code>
 */


/**
 * Phalcon\Image initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, GD, image_adapter_gd, "phalcon\\image\\adapter", phalcon_image_adapter_gd_method_entry, 0);
	

	zend_declare_property_long(phalcon_image_ce, SL("_driver"), 21, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Image constructor
 *
 * @param string $file
 * @param int $driver
 */
PHP_METHOD(Phalcon_Image, __construct){

	zval *file, *driver = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &file, &driver);
	
	if (driver) {
		if (Z_TYPE_P(driver) != IS_LONG) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_image_exception_ce, "The image driver is not valid");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_driver"), driver TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image, resize) {
	zval *width = NULL, *height = NULL, *master = NULL;

	phalcon_fetch_params(0, 0, 3, &width, &height, &master);

	PHALCON_MM_GROW();

	PHALCON_MM_RESTORE();
}

