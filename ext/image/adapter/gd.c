
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
 * Phalcon\Image\\Adapter\GD
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
PHALCON_INIT_CLASS(Phalcon_Image_Adapter_GD){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, GD, image_adapter_gd, "phalcon\\image\\adapter", phalcon_image_adapter_gd_method_entry, 0);
	
	zend_declare_property_long(phalcon_image_adapter_gd_ce, SL("_imageinfo"), 21, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Image constructor
 *
 * @param string $file
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, __construct){

	zval *file, *real_file_path, *imageinfo, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file);

	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "file didn't return a valid string");
		return;
	}

	PHALCON_INIT_VAR(real_file_path);
	phalcon_realpath(real_file_path, file TSRMLS_CC);

	PHALCON_INIT_VAR(imageinfo);
	phalcon_call_func_p1(imageinfo, "getimagesize", real_file_path);
	if (Z_TYPE_P(imageinfo) != IS_ARRAY) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Can't open image file at '", real_file_path, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_image_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_imageinfo"), imageinfo TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Resize the image to the given size. Either the width or the height can
 * be omitted and the image will be resized proportionally.
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $master  master dimension
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter_GD, resize) {
	zval *width = NULL, *height = NULL, *master = NULL;

	phalcon_fetch_params(0, 0, 3, &width, &height, &master);

	PHALCON_MM_GROW();

	PHALCON_MM_RESTORE();
}

