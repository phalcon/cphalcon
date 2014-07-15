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

#include "image.h"
#include "image/adapter.h"
#include "image/adapterinterface.h"
#include "image/exception.h"

#include <ext/standard/php_math.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Image\Adapter
 *
 * Base class for Phalcon\Image adapters
 */
zend_class_entry *phalcon_image_adapter_ce;

PHP_METHOD(Phalcon_Image_Adapter, getRealPath);
PHP_METHOD(Phalcon_Image_Adapter, getWidth);
PHP_METHOD(Phalcon_Image_Adapter, getHeight);
PHP_METHOD(Phalcon_Image_Adapter, getType);
PHP_METHOD(Phalcon_Image_Adapter, getMime);
PHP_METHOD(Phalcon_Image_Adapter, getImage);
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

static const zend_function_entry phalcon_image_adapter_method_entry[] = {
	PHP_ME(Phalcon_Image_Adapter, getRealPath,    arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getWidth,       arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getHeight,      arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getType,        arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getMime,        arginfo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getImage,       arginfo_empty, ZEND_ACC_PUBLIC)

	PHP_ME(Phalcon_Image_Adapter, resize,         arginfo_phalcon_image_adapterinterface_resize,        ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, liquidRescale,  arginfo_phalcon_image_adapterinterface_liquidrescale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, crop,           arginfo_phalcon_image_adapterinterface_crop,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, rotate,         arginfo_phalcon_image_adapterinterface_rotate,        ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, flip,           arginfo_phalcon_image_adapterinterface_flip,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, sharpen,        arginfo_phalcon_image_adapterinterface_sharpen,       ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, reflection,     arginfo_phalcon_image_adapterinterface_reflection,    ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, watermark,      arginfo_phalcon_image_adapterinterface_watermark,     ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, text,           arginfo_phalcon_image_adapterinterface_text,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, mask,           arginfo_phalcon_image_adapterinterface_mask,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, background,     arginfo_phalcon_image_adapterinterface_background,    ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, blur,           arginfo_phalcon_image_adapterinterface_blur,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, pixelate,       arginfo_phalcon_image_adapterinterface_pixelate,      ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, save,           arginfo_phalcon_image_adapterinterface_save,          ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, render,         arginfo_phalcon_image_adapterinterface_render,        ZEND_ACC_PUBLIC)

	ZEND_FENTRY(_resize,          NULL,           arginfo_phalcon_image_adapter__resize,        ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_liquidRescale,   NULL,           arginfo_phalcon_image_adapter__liquidrescale, ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_crop,            NULL,           arginfo_phalcon_image_adapter__crop,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_rotate,          NULL,           arginfo_phalcon_image_adapter__rotate,        ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_flip,            NULL,           arginfo_phalcon_image_adapter__flip,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_sharpen,         NULL,           arginfo_phalcon_image_adapter__sharpen,       ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_reflection,      NULL,           arginfo_phalcon_image_adapter__reflection,    ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_watermark,       NULL,           arginfo_phalcon_image_adapter__watermark,     ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_text,            NULL,           arginfo_phalcon_image_adapter__text,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_mask,            NULL,           arginfo_phalcon_image_adapter__mask,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_background,      NULL,           arginfo_phalcon_image_adapter__background,    ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_blur,            NULL,           arginfo_phalcon_image_adapter__blur,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_pixelate,        NULL,           arginfo_phalcon_image_adapter__pixelate,      ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_save,            NULL,           arginfo_phalcon_image_adapter__save,          ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	ZEND_FENTRY(_render,          NULL,           arginfo_phalcon_image_adapter__render,        ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)

	PHP_FE_END
};

/**
 * Phalcon\Image\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Image, Adapter, image_adapter, phalcon_image_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_image"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_checked"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_realpath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_width"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_height"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_mime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Returns the real path of the image file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getRealPath){


	RETURN_MEMBER(this_ptr, "_realpath");
}

/**
 * Returns the width of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getWidth){


	RETURN_MEMBER(this_ptr, "_width");
}

/**
 * Returns the height of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getHeight){


	RETURN_MEMBER(this_ptr, "_height");
}

/**
 * Returns the type of images
 *
 * @return int
 */
PHP_METHOD(Phalcon_Image_Adapter, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the mime of images
 *
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, getMime){


	RETURN_MEMBER(this_ptr, "_mime");
}

/**
 * Returns the image of images
 *
 * @return resource
 */
PHP_METHOD(Phalcon_Image_Adapter, getImage){


	RETURN_MEMBER(this_ptr, "_image");
}

/**
 * Resize the image to the given size. Either the width or the height can
 * be omitted and the image will be resized proportionally.
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $master  master dimension, if $master is TENSILE, the width and height must be specified
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, resize){

	zval *width = NULL, *height = NULL, *zmaster = NULL;
	zval *image_width, *image_height;
	long tmp_image_width, tmp_image_height, tmp_width = 0, tmp_height = 0, master;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 3, &width, &height, &zmaster);

	if (!zmaster) {
		master = PHALCON_IMAGE_AUTO;
	} else {
		master = phalcon_get_intval(zmaster);
	}

	if (width) {
		PHALCON_SEPARATE_PARAM(width);
		if (Z_TYPE_P(width) != IS_LONG && Z_TYPE_P(width) != IS_NULL) {
			convert_to_long(width);
		}
	}

	if (height) {
		PHALCON_SEPARATE_PARAM(height);
		if (Z_TYPE_P(height) != IS_LONG && Z_TYPE_P(height) != IS_NULL) {
			convert_to_long(height);
		}
	}

	if (PHALCON_IMAGE_TENSILE == master) {
		if (!width || !height) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "width and height parameters must be specified");
			return;
		}
	} else {
		if (!width) {
			PHALCON_INIT_VAR(width);
		}

		if (!height) {
			PHALCON_INIT_VAR(height);
		}

		image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
		image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

		tmp_image_width  = phalcon_get_intval(image_width);
		tmp_image_height = phalcon_get_intval(image_height);

		if ((master == PHALCON_IMAGE_WIDTH && Z_TYPE_P(width) == IS_LONG) || (master == PHALCON_IMAGE_HEIGHT && Z_TYPE_P(height) == IS_LONG)) {
			master = PHALCON_IMAGE_AUTO;
		}

		if (Z_TYPE_P(width) != IS_LONG) {
			if (master == PHALCON_IMAGE_NONE) {
				tmp_width = tmp_image_width;
			} else {
				master = PHALCON_IMAGE_HEIGHT;
			}
		} else {
			tmp_width = Z_LVAL_P(width);
		}

		if (Z_TYPE_P(height) != IS_LONG) {
			if (master == PHALCON_IMAGE_NONE) {
				tmp_height = tmp_image_height;
			} else {
				master = PHALCON_IMAGE_WIDTH;
			}
		} else {
			tmp_height = Z_LVAL_P(height);
		}

		if (tmp_width <= 0) {
			tmp_width = 1;
		}

		if (tmp_height <= 0) {
			tmp_height = 1;
		}

		switch (master) {
			case PHALCON_IMAGE_AUTO:
				if ((tmp_image_width / tmp_width) > (tmp_image_height / tmp_height)) {
					master = PHALCON_IMAGE_WIDTH;
				} else {
					master = PHALCON_IMAGE_HEIGHT;
				}
				break;

			case PHALCON_IMAGE_INVERSE:
				if ((tmp_image_width / tmp_width) > (tmp_image_height / tmp_height)) {
					master = PHALCON_IMAGE_HEIGHT;
				} else {
					master = PHALCON_IMAGE_WIDTH;
				}
				break;
		}

		if (tmp_image_width <= 0) {
			tmp_image_width = 1;
		}

		if (tmp_image_height <= 0) {
			tmp_image_height = 1;
		}

		switch (master) {
			case PHALCON_IMAGE_WIDTH:
				tmp_height = (int)((tmp_image_height * tmp_width / tmp_image_width) + 0.5);
				break;

			case PHALCON_IMAGE_HEIGHT:
				tmp_width = (int)((tmp_image_width * tmp_height / tmp_image_height) + 0.5);
				break;

			case PHALCON_IMAGE_PRECISE:
				if ((tmp_width / tmp_height) > (tmp_image_width / tmp_image_height)) {
					tmp_height = (int)((tmp_image_height * tmp_width / tmp_image_width) + 0.5);
				} else {
					tmp_width = (int)((tmp_image_width * tmp_height / tmp_image_height) + 0.5);
				}
				break;
		}

		if (tmp_width <= 0) {
			tmp_width = 1;
		}

		if (tmp_height <= 0) {
			tmp_height = 1;
		}

		PHALCON_INIT_NVAR(width);
		ZVAL_LONG(width, tmp_width);

		PHALCON_INIT_NVAR(height);
		ZVAL_LONG(height, tmp_height);
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_resize", width, height);

	RETURN_THIS();
}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $delta_x How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, liquidRescale){

	zval **width, **height, **delta_x = NULL, **rigidity = NULL;

	phalcon_fetch_params_ex(2, 2, &width, &height, &delta_x, &rigidity);

	PHALCON_ENSURE_IS_LONG(width);
	PHALCON_ENSURE_IS_LONG(height);

	PHALCON_MM_GROW();

	if (!delta_x) {
		delta_x = &PHALCON_GLOBAL(z_zero);
	} else {
		PHALCON_ENSURE_IS_LONG(delta_x);
	}

	if (!rigidity) {
		rigidity = &PHALCON_GLOBAL(z_zero);
	} else {
		PHALCON_ENSURE_IS_LONG(rigidity);
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_liquidrescale", *width, *height, *delta_x, *rigidity);

	RETURN_THIS();
}

/**
 * Crop an image to the given size. Either the width or the height can be
 * omitted and the current width or height will be used.
 *
 * @param int $width new width
 * @param int $height new height
 * @param int $offset_x offset from the left, if it's true then will center
 * @param int $offset_y offset from the top, if it's true then will middle
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, crop){

	zval **w, **h, **ofs_x = NULL, **ofs_y = NULL;
	zval *image_width, *image_height;
	zval *width, *height, *offset_x, *offset_y;
	long tmp_max_width, tmp_max_height, tmp_width, tmp_height, tmp_image_width, tmp_image_height, tmp_offset_x, tmp_offset_y;

	phalcon_fetch_params_ex(2, 2, &w, &h, &ofs_x, &ofs_y);

	PHALCON_ENSURE_IS_LONG(w);
	PHALCON_ENSURE_IS_LONG(h);

	PHALCON_MM_GROW();

	image_width  = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	image_height = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);

	SEPARATE_ZVAL_IF_NOT_REF(w);
	if (Z_TYPE_PP(w) != IS_LONG) {
		convert_to_long(*w);
	}

	SEPARATE_ZVAL_IF_NOT_REF(h);
	if (Z_TYPE_PP(h) != IS_LONG) {
		convert_to_long(*h);
	}

	if (ofs_x && Z_TYPE_PP(ofs_x) != IS_NULL && Z_TYPE_PP(ofs_x) != IS_BOOL && Z_TYPE_PP(ofs_x) != IS_LONG) {
		SEPARATE_ZVAL_IF_NOT_REF(ofs_x);
		convert_to_long(*ofs_x);
	}
		
	if (ofs_y && Z_TYPE_PP(ofs_y) != IS_NULL && Z_TYPE_PP(ofs_y) != IS_BOOL && Z_TYPE_PP(ofs_x) != IS_LONG) {
		SEPARATE_ZVAL_IF_NOT_REF(ofs_y);
		convert_to_long(*ofs_y);
	}

	tmp_width        = Z_LVAL_PP(w);
	tmp_height       = Z_LVAL_PP(h);
	tmp_image_width  = phalcon_get_intval(image_width);
	tmp_image_height = phalcon_get_intval(image_height);

	if (tmp_width > tmp_image_width) {
		tmp_width = tmp_image_width;
	}

	if (tmp_height > tmp_image_height) {
		tmp_height = tmp_image_height;
	}

	if (!ofs_x) {
		tmp_offset_x = (int)(((tmp_image_width - tmp_width) / 2) + 0.5);
	} else if (Z_TYPE_PP(ofs_x) == IS_BOOL && PHALCON_IS_TRUE(*ofs_x)) {
		tmp_offset_x = tmp_image_width - tmp_width;
	} else if (Z_TYPE_PP(ofs_x) == IS_LONG) {
		if (Z_LVAL_PP(ofs_x) < 0) {
			tmp_offset_x = (int)(tmp_image_width - tmp_width + Z_LVAL_PP(ofs_x) + 0.5);
		} else {
			tmp_offset_x = Z_LVAL_PP(ofs_x);
		}
	} else {
		tmp_offset_x = (int)(((tmp_image_width - tmp_width) / 2) + 0.5);
	}

	if (!ofs_y) {
		tmp_offset_y = (int)(((tmp_image_height - tmp_height) / 2) + 0.5);
	} else if (Z_TYPE_PP(ofs_x) == IS_BOOL && PHALCON_IS_TRUE(*ofs_y)) {
		tmp_offset_y = tmp_image_height - tmp_height;
	} else if (Z_TYPE_PP(ofs_y) == IS_LONG) {
		if (Z_LVAL_PP(ofs_y) < 0) {
			tmp_offset_y = tmp_image_height - tmp_height + Z_LVAL_PP(ofs_y);
		} else {
			tmp_offset_y = Z_LVAL_PP(ofs_y);
		}
	} else {
		tmp_offset_y = (int)(((tmp_image_height - tmp_height) / 2) + 0.5);
	}

	tmp_max_width  = tmp_image_width  - tmp_offset_x;
	tmp_max_height = tmp_image_height - tmp_offset_y;

	if (tmp_width > tmp_max_width) {
		tmp_width = tmp_max_width;
	}

	if (tmp_height > tmp_max_height) {
		tmp_height = tmp_max_height;
	}

	PHALCON_ALLOC_GHOST_ZVAL(width);
	PHALCON_ALLOC_GHOST_ZVAL(height);
	PHALCON_ALLOC_GHOST_ZVAL(offset_x);
	PHALCON_ALLOC_GHOST_ZVAL(offset_y);

	ZVAL_LONG(width,    tmp_width);
	ZVAL_LONG(height,   tmp_height);
	ZVAL_LONG(offset_x, tmp_offset_x);
	ZVAL_LONG(offset_y, tmp_offset_y);

	PHALCON_CALL_METHOD(NULL, this_ptr, "_crop", width, height, offset_x, offset_y);

	RETURN_THIS();
}

/**
 * Rotate the image by a given amount.
 *
 * @param int $degrees  degrees to rotate: -360-360
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, rotate){

	zval **degrees, *d;
	long tmp_degrees;

	phalcon_fetch_params_ex(1, 0, &degrees);

	PHALCON_ENSURE_IS_LONG(degrees);

	PHALCON_MM_GROW();

	tmp_degrees = Z_LVAL_PP(degrees);

	if (tmp_degrees > 180) {
		tmp_degrees %= 360;
		if (tmp_degrees > 180) {
			tmp_degrees -= 360;
		};
	} else if (tmp_degrees < -180) {
		do {
			tmp_degrees += 360;
		} while (tmp_degrees < -180);
	}

	PHALCON_ALLOC_GHOST_ZVAL(d);
	ZVAL_LONG(d, tmp_degrees);
	PHALCON_CALL_METHOD(NULL, this_ptr, "_rotate", d);

	RETURN_THIS();
}

/**
 * Flip the image along the horizontal or vertical axis.
 *
 * @param $int $direction  direction: Image::HORIZONTAL, Image::VERTICAL
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, flip){

	zval **direction, *dir;

	phalcon_fetch_params_ex(1, 0, &direction);
	PHALCON_ENSURE_IS_LONG(direction);

	PHALCON_MM_GROW();

	PHALCON_ALLOC_GHOST_ZVAL(dir);
	ZVAL_LONG(dir, (Z_LVAL_PP(direction) != 11) ? 12 : 11);

	PHALCON_CALL_METHOD(NULL, this_ptr, "_flip", dir);

	RETURN_THIS();
}

/**
 * Sharpen the image by a given amount.
 *
 * @param int $amount amount to sharpen: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen){

	zval **amount;

	phalcon_fetch_params_ex(1, 0, &amount);

	PHALCON_MM_GROW();

	SEPARATE_ZVAL_IF_NOT_REF(amount);
	if (Z_TYPE_PP(amount) != IS_LONG) {
		convert_to_long(*amount);
	}

	if (Z_LVAL_PP(amount) > 100) {
		ZVAL_LONG(*amount, 100);
	} else if (Z_LVAL_PP(amount) < 1) {
		ZVAL_LONG(*amount, 1);
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_sharpen", *amount);

	RETURN_THIS();
}

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
PHP_METHOD(Phalcon_Image_Adapter, reflection){

	zval **h = NULL, **op = NULL, **fade_in = NULL;
	zval *image_height, *height = NULL, *opacity = NULL;
	long tmp_image_height;

	phalcon_fetch_params_ex(0, 3, &h, &op, &fade_in);

	PHALCON_MM_GROW();

	image_height     = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);
	tmp_image_height = phalcon_get_intval(image_height);

	if (!h || Z_TYPE_PP(h) != IS_LONG || Z_LVAL_PP(h) > tmp_image_height) {
		PHALCON_INIT_VAR(height);
		ZVAL_LONG(height, tmp_image_height);
	} else {
		PHALCON_CPY_WRT_CTOR(height, *h);
	}

	if (!op) {
		PHALCON_INIT_VAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_ENSURE_IS_LONG(op);

		if (Z_LVAL_PP(op) > 100) {
			PHALCON_INIT_VAR(opacity);
			ZVAL_LONG(opacity, 100);
		} else if (Z_LVAL_PP(op) < 0) {
			PHALCON_INIT_VAR(opacity);
			ZVAL_LONG(opacity, 0);
		} else {
			PHALCON_CPY_WRT_CTOR(opacity, *op);
		}
	}

	if (!fade_in) {
		fade_in = &PHALCON_GLOBAL(z_false);
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_reflection", height, opacity, *fade_in);
	RETURN_THIS();
}

/**
 * Add a watermark to an image with a specified opacity. Alpha transparency
 * will be preserved.
 *
 * @param Phalcon\Image\Adapter $watermark  watermark Image instance
 * @param int $offset_x offset from the left, If less than 0 offset from the right, If true right the x offset
 * @param int $offset_y offset from the top, If less than 0 offset from the bottom, If true bottom the Y offset
 * @param int $opacity opacity of watermark: 1-100
 * @return Phalcon\Image\AdapterInterface
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark){

	zval **watermark, **ofs_x = NULL, **ofs_y = NULL, **op = NULL;
	zval *offset_x, *offset_y, *opacity;
	zval *image_width, *image_height, *watermark_width, *watermark_height;
	long tmp_image_width, tmp_image_height, tmp_watermark_width, tmp_watermark_height, tmp_offset_x, tmp_offset_y;

	phalcon_fetch_params_ex(1, 3, &watermark, &ofs_x, &ofs_y, &op);
	PHALCON_VERIFY_INTERFACE_EX(*watermark, phalcon_image_adapterinterface_ce, phalcon_image_exception_ce, 0);

	PHALCON_MM_GROW();

	image_width      = phalcon_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY TSRMLS_CC);
	image_height     = phalcon_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY TSRMLS_CC);
	watermark_width  = phalcon_fetch_nproperty_this(*watermark, SL("_width"), PH_NOISY TSRMLS_CC);
	watermark_height = phalcon_fetch_nproperty_this(*watermark, SL("_height"), PH_NOISY TSRMLS_CC);

	tmp_image_width      = phalcon_get_intval(image_width);
	tmp_image_height     = phalcon_get_intval(image_height);
	tmp_watermark_width  = phalcon_get_intval(watermark_width);
	tmp_watermark_height = phalcon_get_intval(watermark_height);

	if (!ofs_x) {
		tmp_offset_x = (int)(((tmp_image_width - tmp_watermark_width) / 2) + 0.5);
	} else if (Z_TYPE_PP(ofs_x) == IS_LONG) {
		tmp_offset_x = Z_LVAL_PP(ofs_x);
		if (tmp_offset_x < 0) {
			tmp_offset_x = (int)(tmp_image_width - tmp_watermark_width + tmp_offset_x + 0.5);
		}
	} else if (zend_is_true(*ofs_x)) {
		tmp_offset_x = (int)(tmp_image_width - tmp_watermark_width);
	} else {
		tmp_offset_x = (int)(((tmp_image_width - tmp_watermark_width) / 2) + 0.5);
	}

	PHALCON_INIT_VAR(offset_x);
	ZVAL_LONG(offset_x, tmp_offset_x);

	if (!ofs_y) {
		tmp_offset_y = (int)(((tmp_image_height - tmp_watermark_height) / 2) + 0.5);
	} else if (Z_TYPE_PP(ofs_y) == IS_LONG) {
		tmp_offset_y = Z_LVAL_PP(ofs_y);
		if (tmp_offset_y < 0) {
			tmp_offset_y = (int)(tmp_image_height - tmp_watermark_height + tmp_offset_y + 0.5);
		}
	} else if (zend_is_true(*ofs_y)) {
		tmp_offset_y = (int)(tmp_image_height - tmp_watermark_height);
	} else {
		tmp_offset_y = (int)(((tmp_image_height - tmp_watermark_height) / 2) + 0.5);
	}

	PHALCON_INIT_VAR(offset_y);
	ZVAL_LONG(offset_y, tmp_offset_y);

	PHALCON_INIT_VAR(opacity);
	if (!op) {
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_ENSURE_IS_LONG(op);

		if (Z_LVAL_PP(op) < 1) {
			ZVAL_LONG(opacity, 1);
		} else if (Z_LVAL_PP(op) > 100) {
			ZVAL_LONG(opacity, 100);
		} else {
			ZVAL_LONG(opacity, Z_LVAL_PP(op));
		}
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_watermark", *watermark, offset_x, offset_y, opacity);

	RETURN_THIS();
}


/**
 * Add a text to an image with a specified opacity.
 *
 * @param string text
 * @param int $offset_x offset from the left, If less than 0 offset from the right, If true right the x offset
 * @param int $offset_y offset from the top, If less than 0 offset from the bottom, If true bottom the Y offset
 * @param int $opacity opacity of text: 1-100
 * @param string $color hexadecimal color value
 * @param int $size font pointsize
 * @param string $fontfile font path
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, text){

	zval **text, **ofs_x = NULL, **ofs_y = NULL, **op = NULL, **fontcolor = NULL, **fontsize = NULL, **fontfile = NULL;
	zval *offset_x = NULL, *offset_y = NULL, *opacity, *color, *size;
	zval *r, *g, *b;
	char *c;
	zval tmp;

	phalcon_fetch_params_ex(1, 6, &text, &ofs_x, &ofs_y, &op, &fontcolor, &fontsize, &fontfile);

	PHALCON_MM_GROW();

	if (!ofs_x || Z_TYPE_PP(ofs_x) == IS_NULL) {
		PHALCON_INIT_VAR(offset_x);
		ZVAL_FALSE(offset_x);
	}
	else {
		PHALCON_CPY_WRT_CTOR(offset_x, *ofs_x);
	}

	if (!ofs_y || Z_TYPE_PP(ofs_y) == IS_NULL) {
		PHALCON_INIT_VAR(offset_y);
		ZVAL_FALSE(offset_y);
	}
	else {
		PHALCON_CPY_WRT_CTOR(offset_y, *ofs_y);
	}

	PHALCON_INIT_VAR(opacity);
	if (!op || Z_TYPE_PP(op) == IS_NULL) {
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_ENSURE_IS_LONG(op);
		if (Z_LVAL_PP(op) < 1) {
			ZVAL_LONG(opacity, 1);
		} else if (Z_LVAL_PP(op) > 100) {
			ZVAL_LONG(opacity, 100);
		} else {
			ZVAL_LONG(opacity, Z_LVAL_PP(op));
		}
	}

	PHALCON_INIT_VAR(color);
	if (!fontcolor || Z_TYPE_PP(fontcolor) == IS_NULL) {
		ZVAL_STRING(color, "000000", 1);
	}
	else {
		PHALCON_ENSURE_IS_STRING(fontcolor);
		if (Z_STRLEN_PP(fontcolor) > 1 && Z_STRVAL_PP(fontcolor)[0] == '#') {
			phalcon_substr(color, *fontcolor, 1, 0);
		}
		else {
			ZVAL_STRINGL(color, Z_STRVAL_PP(fontcolor), Z_STRLEN_PP(fontcolor), 1);
		}
	}

	PHALCON_INIT_VAR(size);
	if (!fontsize || Z_TYPE_PP(fontsize) == IS_NULL) {
		ZVAL_LONG(size, 12);
	}
	else {
		PHALCON_ENSURE_IS_LONG(fontsize);
		ZVAL_LONG(size, Z_LVAL_PP(fontsize));
	}

	if (!fontfile) {
		fontfile = &PHALCON_GLOBAL(z_null);
	}

	if (Z_STRLEN_P(color) == 3) {
		/* Convert RGB to RRGGBB */
		c = Z_STRVAL_P(color);
		assert(!IS_INTERNED(c));
		STR_REALLOC(c, 7);
		c[6] = '\0';
		c[5] = c[2];
		c[4] = c[2];
		c[3] = c[1];
		c[2] = c[1];
		c[1] = c[0];
		ZVAL_STRING(color, c, 0);
	}

	if (Z_STRLEN_P(color) < 6) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "color is not valid");
		return;
	}

	INIT_ZVAL(tmp);

	Z_TYPE(tmp) = IS_STRING;
	ZVAL_STRINGL(&tmp, Z_STRVAL_P(color), 2, 0);

	PHALCON_INIT_VAR(r);
	_php_math_basetozval(&tmp, 16, r);

	Z_STRVAL(tmp) += 2;
	PHALCON_INIT_VAR(g);
	_php_math_basetozval(&tmp, 16, g);

	Z_STRVAL(tmp) += 2;
	PHALCON_INIT_VAR(b);
	_php_math_basetozval(&tmp, 16, b);

	PHALCON_CALL_METHOD(NULL, this_ptr, "_text", *text, offset_x, offset_y, opacity, r, g, b, size, *fontfile);

	RETURN_THIS();
}

/**
 * Composite one image onto another
 *
 * @param Phalcon\Image\Adapter $mask  mask Image instance
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, mask){

	zval *mask;

	phalcon_fetch_params(0, 1, 0, &mask);
	PHALCON_CALL_METHODW(NULL, this_ptr, "_mask", mask);
	RETURN_THISW();
}

/**
 * Set the background color of an image. This is only useful for images
 * with alpha transparency.
 *
 * @param string $color hexadecimal color value
 * @param int $opacity background opacity: 0-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, background){

	zval *color, *opacity = NULL;
	zval *tmp_color = NULL, *r = NULL, *g = NULL, *b = NULL;
	long i;
	char *c;
	zval tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &color, &opacity);

	if (Z_TYPE_P(color) != IS_STRING) {
		PHALCON_SEPARATE_PARAM(color);
		convert_to_string(color);
	}

	c = Z_STRVAL_P(color);

	if (Z_STRLEN_P(color) > 0 && c[0] == '#') {
		PHALCON_INIT_NVAR(tmp_color);
		phalcon_substr(tmp_color, color, 1, 0);
	} else {
		PHALCON_CPY_WRT_CTOR(tmp_color, color);
	}

	if (Z_STRLEN_P(tmp_color) == 3) {
		/* Convert RGB to RRGGBB */
		c = Z_STRVAL_P(tmp_color);
		if (!IS_INTERNED(c)) {
			STR_REALLOC(c, 7);
		}
		else {
			char* tmp = ecalloc(7, 1);
			memcpy(tmp, c, Z_STRLEN_P(tmp_color));
			c = tmp;
		}

		c[6] = '\0';
		c[5] = c[2];
		c[4] = c[2];
		c[3] = c[1];
		c[2] = c[1];
		c[1] = c[0];
		ZVAL_STRING(tmp_color, c, 0);
	}

	if (Z_STRLEN_P(tmp_color) < 6) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Color is not valid");
		return;
	}

	INIT_ZVAL(tmp);

	Z_TYPE(tmp) = IS_STRING;
	ZVAL_STRINGL(&tmp, Z_STRVAL_P(tmp_color), 2, 0);

	PHALCON_INIT_NVAR(r);
	_php_math_basetozval(&tmp, 16, r);

	Z_STRVAL(tmp) += 2;
	PHALCON_INIT_NVAR(g);
	_php_math_basetozval(&tmp, 16, g);

	Z_STRVAL(tmp) += 2;
	PHALCON_INIT_NVAR(b);
	_php_math_basetozval(&tmp, 16, b);

	if (!opacity) {
		PHALCON_INIT_NVAR(opacity);
		ZVAL_LONG(opacity, 100);
	} else {
		PHALCON_SEPARATE_PARAM(opacity);

		i = phalcon_get_intval(opacity);

		if (i < 1) {
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 1);
		} else if (i > 100) {
			PHALCON_INIT_NVAR(opacity);
			ZVAL_LONG(opacity, 100);
		}
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_background", r, g, b, opacity);

	RETURN_THIS();
}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, blur){

	zval *radius = NULL;
	long r;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &radius);

	if (!radius) {
		PHALCON_INIT_VAR(radius);
		ZVAL_LONG(radius, 1);
	} else if (Z_TYPE_P(radius) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(radius);

		PHALCON_INIT_NVAR(radius);
		ZVAL_LONG(radius, 1);
	} else {
		r = phalcon_get_intval(radius);
		if (r < 1) {
			PHALCON_SEPARATE_PARAM(radius);
			PHALCON_INIT_NVAR(radius);
			ZVAL_LONG(radius, 1);
		} else if (r > 100) {
			PHALCON_SEPARATE_PARAM(radius);
			PHALCON_INIT_NVAR(radius);
			ZVAL_LONG(radius, 100);
		}
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_blur", radius);

	RETURN_THIS();
}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, pixelate){

	zval **amount = NULL, *amt;

	phalcon_fetch_params_ex(0, 1, &amount);

	PHALCON_MM_GROW();

	PHALCON_ALLOC_GHOST_ZVAL(amt);
	if (!amount || Z_TYPE_PP(amount) != IS_LONG) {
		ZVAL_LONG(amt, 10);
	} else {
		PHALCON_ENSURE_IS_LONG(amount);
		if (Z_LVAL_PP(amount) < 2) {
			ZVAL_LONG(amt, 2);
		} else {
			ZVAL_LONG(amt, Z_LVAL_PP(amount));
		}
	}

	PHALCON_CALL_METHOD(NULL, this_ptr, "_pixelate", amt);

	RETURN_THIS();
}

/**
 * Save the image. If the filename is omitted, the original image will
 * be overwritten.
 *
 * @param string $file new image path
 * @param int $quality quality of image: 1-100
 * @return boolean
 */
PHP_METHOD(Phalcon_Image_Adapter, save){

	zval **fname = NULL, **q = NULL;
	zval *file, *quality;
	zval *ret = NULL, *dir, *constant;

	phalcon_fetch_params_ex(0, 2, &fname, &q);

	PHALCON_MM_GROW();

	if (!fname) {
		PHALCON_OBS_VAR(file);
		phalcon_read_property_this(&file, this_ptr, SL("_realpath"), PH_NOISY TSRMLS_CC);
		convert_to_string_ex(&file);
	}
	else {
		PHALCON_ENSURE_IS_STRING(fname);
		file = *fname;
	}

	PHALCON_INIT_VAR(quality);
	if (!q || Z_TYPE_PP(q) != IS_LONG) {
		ZVAL_LONG(quality, 100);
	} else if (Z_LVAL_PP(q) > 100) {
		ZVAL_LONG(quality, 100);
	} else if (Z_LVAL_PP(q) < 1) {
		ZVAL_LONG(quality, 1);
	} else {
		ZVAL_LONG(quality, Z_LVAL_PP(q));
	}

	PHALCON_CALL_FUNCTION(&ret, "is_file", file);

	if (zend_is_true(ret)) {
		PHALCON_CALL_FUNCTION(&ret, "is_writable", file);
		if (!zend_is_true(ret)) {
			zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "File must be writable: '%s'", Z_STRVAL_P(file));
			RETURN_MM();
		}
	} else {
		PHALCON_INIT_VAR(constant);
		if (!zend_get_constant(SL("PATHINFO_DIRNAME"), constant TSRMLS_CC)) {
			RETURN_MM();
		}

		PHALCON_CALL_FUNCTION(&ret, "pathinfo", file, constant);

		PHALCON_INIT_VAR(dir);
		phalcon_realpath(dir, ret TSRMLS_CC);
		convert_to_string(dir);

		PHALCON_INIT_NVAR(ret);
		phalcon_is_dir(ret, dir TSRMLS_CC);

		if (!zend_is_true(ret)) {
			zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Directory must be writable: '%s'", Z_STRVAL_P(dir));
			RETURN_MM();
		}

		PHALCON_CALL_FUNCTION(&ret, "is_writable", dir);
		if (!zend_is_true(ret)) {
			zend_throw_exception_ex(phalcon_image_exception_ce, 0 TSRMLS_CC, "Directory must be writable: '%s'", Z_STRVAL_P(dir));
			RETURN_MM();
		}
	}

	PHALCON_RETURN_CALL_METHOD(this_ptr, "_save", file, quality);
	RETURN_MM();
}

/**
 * Render the image and return the binary string.
 *
 * @param string $ext image type to return: png, jpg, gif, etc
 * @param int $quality quality of image: 1-100
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, render){

	zval *ext = NULL, *quality = NULL, *constant, *file;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &ext, &quality);

	if (!ext) {
		file = phalcon_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(constant);
		if (!zend_get_constant(SL("PATHINFO_EXTENSION"), constant TSRMLS_CC)) {
			RETURN_MM();
		}

		ext = NULL;
		PHALCON_CALL_FUNCTION(&ext, "pathinfo", file, constant);

		if (!PHALCON_IS_NOT_EMPTY(ext)) {
			ZVAL_STRING(ext, "png", 1);
		}
	}

	if (!quality) {
		PHALCON_INIT_VAR(quality);
		ZVAL_LONG(quality, 100);
	} else {
        if (Z_TYPE_P(quality) != IS_LONG) {
            PHALCON_SEPARATE_PARAM(quality);
            convert_to_long(quality);
        }
    }

	PHALCON_RETURN_CALL_METHOD(this_ptr, "_render", ext, quality);

	RETURN_MM();
}
