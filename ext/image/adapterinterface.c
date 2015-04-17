
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

#include "image/adapterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_image_adapterinterface_ce;

static const zend_function_entry phalcon_image_adapterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, resize,        arginfo_phalcon_image_adapterinterface_resize)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, liquidRescale, arginfo_phalcon_image_adapterinterface_liquidrescale)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, crop,          arginfo_phalcon_image_adapterinterface_crop)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, rotate,        arginfo_phalcon_image_adapterinterface_rotate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, flip,          arginfo_phalcon_image_adapterinterface_flip)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, sharpen,       arginfo_phalcon_image_adapterinterface_sharpen)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, reflection,    arginfo_phalcon_image_adapterinterface_reflection)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, watermark,     arginfo_phalcon_image_adapterinterface_watermark)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, text,          arginfo_phalcon_image_adapterinterface_text)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, mask,          arginfo_phalcon_image_adapterinterface_mask)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, background,    arginfo_phalcon_image_adapterinterface_background)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, blur,          arginfo_phalcon_image_adapterinterface_blur)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, pixelate,      arginfo_phalcon_image_adapterinterface_pixelate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, save,          arginfo_phalcon_image_adapterinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, render,        arginfo_phalcon_image_adapterinterface_render)
	PHP_FE_END
};

/**
 * Phalcon\Image\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Image, AdapterInterface, image_adapterinterface, phalcon_image_adapterinterface_method_entry);

	return SUCCESS;
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
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, resize);

/**
 * Crop an image to the given size. Either the width or the height can be
 * omitted and the current width or height will be used.
 *
 * @param int $width new width
 * @param int $height new height
 * @param int $offset_x  offset from the left
 * @param int $offset_y  offset from the top
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, crop);

/**
 * Rotate the image by a given amount.
 *
 * @param int $degrees  degrees to rotate: -360-360
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, rotate);

/**
 * Flip the image along the horizontal or vertical axis.
 *
 * @param $int $direction  direction: Image::HORIZONTAL, Image::VERTICAL
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, flip);

/**
 * Sharpen the image by a given amount.
 *
 * @param int $amount  amount to sharpen: 1-100
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, sharpen);

/**
 * Add a reflection to an image. The most opaque part of the reflection
 * will be equal to the opacity setting and fade out to full transparent.
 * Alpha transparency is preserved.
 *
 * @param int $height reflection height
 * @param int $opacity reflection opacity: 0-100
 * @param boolean $fade_in TRUE to fade in, FALSE to fade out
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, reflection);

/**
 * Add a watermark to an image with a specified opacity. Alpha transparency
 * will be preserved.
 *
 * @param Phalcon\Image\Adapter $watermark  watermark Image instance
 * @param int $offset_x offset from the left
 * @param int $offset_y offset from the top
 * @param int $opacity opacity of watermark: 1-100
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, watermark);

/**
 * Set the background color of an image. This is only useful for images
 * with alpha transparency.
 *
 * @param string $color hexadecimal color value
 * @param int $opacity background opacity: 0-100
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, background);

/**
 * Save the image. If the filename is omitted, the original image will
 * be overwritten.
 *
 * @param string $file new image path
 * @param int $quality quality of image: 1-100
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, save);

/**
 * Render the image and return the binary string.
 *
 * @param string $type image type to return: png, jpg, gif, etc
 * @param int $quality quality of image: 1-100
 * @return Phalcon\Image\Adapter
 */
PHALCON_DOC_METHOD(Phalcon_Image_AdapterInterface, render);
