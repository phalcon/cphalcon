
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Allows images to be resized, cropped, etc.
 *
 *<code>
 * $image = new Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 * $image->resize(200, 200)->rotate(90)->crop(100, 100);
 * if ($image->save()) {
 *     echo 'success';
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, phalcon, image_adapter_imagick, phalcon_image_adapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	zend_declare_property_long(phalcon_image_adapter_imagick_ce, SL("_version"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(phalcon_image_adapter_imagick_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_imagick_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Checks if Imagick is enabled
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *_0, _1, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "imagick", 0);
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded", "phalcon/image/adapter/imagick.zep", 54);
		return;
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "defined", &_4, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "constant", &_6, &_2);
		zephir_check_call_status();
		zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version"), &_5 TSRMLS_CC);
	}
	zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	_7 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_7);

}

/**
 * \Phalcon\Image\Adapter\Imagick constructor
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_bool _20;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL, *_17 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *image = NULL, *_0, *_1, *_2, *_3, *_4 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10, *_11 = NULL, *_13 = NULL, *_14, _15, *_16 = NULL, *_18, *_19, *_21 = NULL, *_22;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}
	if (!width_param) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_image"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_2 TSRMLS_CC) == SUCCESS)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4, "realpath", &_5, _3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _4 TSRMLS_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_realpath"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, _6, "readimage", NULL, _8);
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			ZEPHIR_INIT_VAR(_9);
			object_init_ex(_9, phalcon_image_exception_ce);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_CONCAT_SVS(_11, "Imagick::readImage ", _10, " failed");
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _11);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "phalcon/image/adapter/imagick.zep", 85 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_13, _10, "getimagealphachannel", NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_STRING(&_15, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_16, "constant", &_17, &_15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14, "setimagealphachannel", NULL, _16);
			zephir_check_call_status();
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_10, 1)) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&image, _14, "coalesceimages", NULL);
			zephir_check_call_status();
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _18, "clear", NULL);
			zephir_check_call_status();
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _19, "destroy", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		}
	} else {
		_20 = !width;
		if (!(_20)) {
			_20 = !height;
		}
		if (_20) {
			ZEPHIR_INIT_NVAR(_9);
			object_init_ex(_9, phalcon_image_exception_ce);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SV(_11, "Failed to create image from file ", _3);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _11);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "phalcon/image/adapter/imagick.zep", 101 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_9);
		object_init_ex(_9, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		if (zephir_has_constructor(_9 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_21);
			ZVAL_STRING(_21, "transparent", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_LONG(_21, width);
		ZEPHIR_INIT_VAR(_22);
		ZVAL_LONG(_22, height);
		ZEPHIR_CALL_METHOD(NULL, _6, "newimage", NULL, _21, _22, _9);
		zephir_check_call_status();
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "png", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _8, "setformat", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "png", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10, "setimageformat", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _14 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _4 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _7 TSRMLS_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _8, "getimagetype", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _13 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_16, _18, "getimageformat", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_11);
	ZEPHIR_CONCAT_SV(_11, "image/", _16);
	zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a resize.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zval *width_param = NULL, *height_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_CALL_METHOD(NULL, _2, "scaleimage", NULL, _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _2, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _4, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale) {

	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, *ret = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL;
	int width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &deltaX_param, &rigidity_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	deltaX = zephir_get_intval(deltaX_param);
	rigidity = zephir_get_intval(rigidity_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, deltaX);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, rigidity);
		ZEPHIR_CALL_METHOD(&ret, _2, "liquidrescaleimage", NULL, _1, _3, _4, _5);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed", "phalcon/image/adapter/imagick.zep", 151);
			return;
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, _6, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_7)) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _2, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _7 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _6, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a crop.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_7 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_6 = NULL, *_8 = NULL;
	int width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, _0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, offsetX);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, offsetY);
		ZEPHIR_CALL_METHOD(NULL, image, "cropimage", &_4, _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagepage", &_5, _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, image, "nextimage", &_7);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_6, image, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_8, image, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a rotation.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zval *degrees_param = NULL, *pixel, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6 = NULL, *_7, *_8 = NULL, *_9 = NULL;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	object_init_ex(pixel, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL);
		zephir_check_call_status();
	}
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, degrees);
		ZEPHIR_CALL_METHOD(NULL, _2, "rotateimage", NULL, pixel, _1);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_CALL_METHOD(NULL, _3, "setimagepage", NULL, _4, _5, _1, _6);
		zephir_check_call_status();
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _2, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _8 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _3, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a flip.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction_param = NULL, *func = NULL, *_0, *_1, *_2, *_3, *_4 = NULL;
	int direction, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "flipImage", 1);
	if (direction == 11) {
		ZEPHIR_INIT_NVAR(func);
		ZVAL_STRING(func, "flopImage", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, _2, func, NULL);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4, _3, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a sharpen.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount_param = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	if (amount < 5) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 5);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, amount);
	}
	amount = zephir_get_numberval(_0);
	amount = (long) (zephir_safe_div_long_long(((amount * 3.0)), 100 TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setiteratorindex", NULL, _2);
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, amount);
		ZEPHIR_CALL_METHOD(NULL, _3, "sharpenimage", NULL, _2, _4);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6, _5, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a reflection.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zephir_nts_static zephir_fcall_cache_entry *_15 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_16 = NULL, *_19 = NULL, *_21 = NULL, *_24 = NULL, *_25 = NULL, *_27 = NULL, *_29 = NULL, *_31 = NULL, *_33 = NULL;
	zend_bool fadeIn, _34;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection, *fade, *pseudo = NULL, *image, *pixel, *ret = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL, _14 = zval_used_for_init, *_17 = NULL, *_18 = NULL, *_20 = NULL, *_22, *_23, *_26, *_28, *_30, *_32;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_version") TSRMLS_CC);
	ZEPHIR_INIT_VAR(reflection);
	if (ZEPHIR_GE_LONG(_0, 30100)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		if (zephir_clone(reflection, _1 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "clone", NULL);
		zephir_check_call_status();
		if (zephir_clone(reflection, _2 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(NULL, reflection, "flipimage", &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, reflection, "getimagewidth", &_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "cropimage", &_8, _2, _3, _6, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, reflection, "getimagewidth", &_10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "setimagepage", &_11, _9, _3, _6, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12, reflection, "nextimage", &_13);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_12)) {
			break;
		}
	}
	if (fadeIn) {
		ZEPHIR_INIT_VAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:black-transparent", 1);
	} else {
		ZEPHIR_INIT_NVAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:transparent-black", 1);
	}
	ZEPHIR_INIT_VAR(fade);
	object_init_ex(fade, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(fade TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, fade, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, reflection, "getimagewidth", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, reflection, "getimageheight", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, fade, "newpseudoimage", NULL, _2, _9, pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::COMPOSITE_DSTOUT", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "constant", &_15, &_14);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_CALL_METHOD(&ret, reflection, "compositeimage", &_16, fade, _12, _3, _6);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 287);
			return;
		}
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_17, "constant", &_15, &_14);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_18, "constant", &_15, &_14);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, opacity);
		ZEPHIR_CALL_METHOD(NULL, reflection, "evaluateimage", &_19, _17, _3, _18);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20, reflection, "nextimage", &_21);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_20)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, fade, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(image);
	object_init_ex(image, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(image TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, image, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(pixel);
	object_init_ex(pixel, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getimageheight", NULL);
	zephir_check_call_status();
	height = (zephir_get_numberval(_2) + height);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _22, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_CALL_METHOD(NULL, image, "newimage", &_24, _23, _3, pixel);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "constant", &_15, &_14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagealphachannel", &_25, _9);
		zephir_check_call_status();
		_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12, _26, "getcolorspace", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setcolorspace", &_27, _12);
		zephir_check_call_status();
		_28 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_17, _28, "getimagedelay", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagedelay", &_29, _17);
		zephir_check_call_status();
		_30 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_CALL_FUNCTION(&_18, "constant", &_15, &_14);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_CALL_METHOD(&ret, image, "compositeimage", &_31, _30, _18, _3, _6);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 312);
			return;
		}
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_20, _32, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_20)) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "constant", &_15, &_14);
		zephir_check_call_status();
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(&ret, image, "compositeimage", &_31, reflection, _2, _3, _1);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 327);
			return;
		}
		ZEPHIR_CALL_METHOD(&_9, image, "nextimage", &_33);
		zephir_check_call_status();
		_34 = ZEPHIR_IS_FALSE_IDENTICAL(_9);
		if (!(_34)) {
			ZEPHIR_CALL_METHOD(&_12, reflection, "nextimage", NULL);
			zephir_check_call_status();
			_34 = ZEPHIR_IS_FALSE_IDENTICAL(_12);
		}
		if (_34) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, reflection, "destroy", NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "clear", NULL);
	zephir_check_call_status();
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _23, "destroy", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _26, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _2 TSRMLS_CC);
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _28, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a watermarking.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *watermark, *ret = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, *_8, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(watermark);
	object_init_ex(watermark, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(watermark TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, watermark, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "readimageblob", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, opacity);
	ZEPHIR_CALL_METHOD(NULL, watermark, "setimageopacity", NULL, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "constant", &_6, &_4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, offsetX);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, offsetY);
		ZEPHIR_CALL_METHOD(&ret, _3, "compositeimage", NULL, watermark, _5, _1, _7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 364);
			return;
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9, _8, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_9)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, watermark, "clear", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a text
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL;
	int offsetX, offsetY, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *draw, *color = NULL, *pixel, *gravity = NULL, _0 = zval_used_for_init, _1, _2, _3, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_10, *_11, *_12 = NULL, *_13 = NULL, *_14;
	zval *text = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX_param, &offsetY_param, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(fontfile, fontfile_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(draw);
	object_init_ex(draw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	if (zephir_has_constructor(draw TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, r);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, g);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", &_4, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	object_init_ex(pixel, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL, color);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "setfillcolor", NULL, pixel);
	zephir_check_call_status();
	if (fontfile && Z_STRLEN_P(fontfile)) {
		ZEPHIR_CALL_METHOD(NULL, draw, "setfont", NULL, fontfile);
		zephir_check_call_status();
	}
	if (size) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, size);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfontsize", NULL, _5);
		zephir_check_call_status();
	}
	if (opacity) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, opacity);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfillopacity", NULL, _5);
		zephir_check_call_status();
	}
	if (offsetX < 0) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, offsetX);
		ZEPHIR_CALL_FUNCTION(&_6, "abs", &_7, &_0);
		zephir_check_call_status();
		offsetX = zephir_get_numberval(_6);
		if (offsetY < 0) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, offsetY);
			ZEPHIR_CALL_FUNCTION(&_8, "abs", &_7, &_0);
			zephir_check_call_status();
			offsetY = zephir_get_numberval(_8);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::GRAVITY_SOUTHEAST", 0);
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_9, &_0);
			zephir_check_call_status();
		} else {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::GRAVITY_NORTHEAST", 0);
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_9, &_0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "setgravity", NULL, gravity);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 0);
	ZEPHIR_CALL_METHOD(NULL, _10, "setiteratorindex", NULL, _5);
	zephir_check_call_status();
	while (1) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, offsetX);
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_LONG(_12, offsetY);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 0);
		ZEPHIR_CALL_METHOD(NULL, _11, "annotateimage", NULL, draw, _5, _12, _13, text);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6, _14, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Composite one image onto another
 *
 * @param Adapter $mask mask Image instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *image, *mask, *ret = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, *_4, _5 = zval_used_for_init, *_6 = NULL, *_8 = NULL, *_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	ZEPHIR_INIT_VAR(mask);
	object_init_ex(mask, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(mask TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, mask, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "readimageblob", NULL, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setiteratorindex", NULL, _2);
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_CALL_METHOD(NULL, _3, "setimagematte", NULL, _2);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "Imagick::COMPOSITE_DSTIN", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "constant", &_7, &_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		ZEPHIR_CALL_METHOD(&ret, _4, "compositeimage", NULL, mask, _6, _2, _8);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 453);
			return;
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_10)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, mask, "clear", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a background.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_14 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_24 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color = NULL, *pixel1, *pixel2, *ret = NULL, _0 = zval_used_for_init, _1, _2, _3, *_5 = NULL, *_6, *_7, *_8, *_10 = NULL, *_12 = NULL, *_16 = NULL, *_18, *_19 = NULL, *_21, *_22 = NULL, *_23 = NULL, *_25;
	int r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, r);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, g);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", &_4, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel1);
	object_init_ex(pixel1, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	if (zephir_has_constructor(pixel1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel1, "__construct", NULL, color);
		zephir_check_call_status();
	}
	opacity = (long) (zephir_safe_div_long_long(opacity, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(pixel2);
	object_init_ex(pixel2, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	if (zephir_has_constructor(pixel2 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "transparent", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, pixel2, "__construct", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(background);
	object_init_ex(background, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	if (zephir_has_constructor(background TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, background, "__construct", NULL);
		zephir_check_call_status();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 0);
	ZEPHIR_CALL_METHOD(NULL, _6, "setiteratorindex", NULL, _5);
	zephir_check_call_status();
	while (1) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, background, "newimage", &_9, _7, _8, pixel1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10, background, "getimagealphachannel", &_11);
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "constant", &_13, &_0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, background, "setimagealphachannel", &_14, _12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, background, "setimagebackgroundcolor", &_15, pixel2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "constant", &_13, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_16, "constant", &_13, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, opacity);
		ZEPHIR_CALL_METHOD(NULL, background, "evaluateimage", &_17, _12, _5, _16);
		zephir_check_call_status();
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_19, _18, "getcolorspace", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, background, "setcolorspace", &_20, _19);
		zephir_check_call_status();
		_21 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::COMPOSITE_DISSOLVE", 0);
		ZEPHIR_CALL_FUNCTION(&_22, "constant", &_13, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_LONG(_23, 0);
		ZEPHIR_CALL_METHOD(&ret, background, "compositeimage", &_24, _21, _22, _5, _23);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(ret)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/image/adapter/imagick.zep", 492);
			return;
		}
		_25 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12, _25, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_12)) {
			break;
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _7, "clear", NULL);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _8, "destroy", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zval *radius_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL;
	int radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, radius);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 100);
		ZEPHIR_CALL_METHOD(NULL, _2, "blurimage", NULL, _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate) {

	zval *amount_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7, *_8, *_9, *_10 = NULL;
	int amount, width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	width = (long) (zephir_safe_div_zval_long(_0, amount TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	height = (long) (zephir_safe_div_zval_long(_1, amount TSRMLS_CC));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		ZEPHIR_CALL_METHOD(NULL, _4, "scaleimage", NULL, _3, _5);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6, "scaleimage", NULL, _7, _8);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "nextimage", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_10)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a save.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zend_bool _15;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_12 = NULL, *_18 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext = NULL, *fp = NULL, _0 = zval_used_for_init, *_2, *_3, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_11, *_13, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_19, *_20;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", &_1, file, &_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setformat", NULL, ext);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setimageformat", NULL, ext);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _4, "getimagetype", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "getimageformat", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "image/", _7);
	zephir_update_property_this(this_ptr, SL("_mime"), _8 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "strcasecmp", &_10, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_9, 0)) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _11, "optimizeimagelayers", NULL);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "w", 0);
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", &_12, file, &_0);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _13, "writeimagesfile", NULL, fp);
		zephir_check_call_status();
		zephir_fclose(fp TSRMLS_CC);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_14, "strcasecmp", &_10, ext, &_0);
		zephir_check_call_status();
		_15 = ZEPHIR_IS_LONG(_14, 0);
		if (!(_15)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_16, "strcasecmp", &_10, ext, &_0);
			zephir_check_call_status();
			_15 = ZEPHIR_IS_LONG(_16, 0);
		}
		if (_15) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "constant", &_18, &_0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _11, "setimagecompression", NULL, _17);
			zephir_check_call_status();
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, quality);
		ZEPHIR_CALL_METHOD(NULL, _13, "setimagecompressionquality", NULL, _19);
		zephir_check_call_status();
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _20, "writeimage", NULL, file);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Execute a render.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zend_bool _7;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_11;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);

	zephir_get_strval(extension, extension_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, image, "setformat", NULL, extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, image, "setimageformat", NULL, extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, image, "stripimage", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "getimagetype", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, image, "getimageformat", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "image/", _1);
	zephir_update_property_this(this_ptr, SL("_mime"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "strcasecmp", &_5, extension, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_4, 0)) {
		ZEPHIR_CALL_METHOD(NULL, image, "optimizeimagelayers", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "strcasecmp", &_5, extension, &_3);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_LONG_IDENTICAL(_6, 0);
		if (!(_7)) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_8, "strcasecmp", &_5, extension, &_3);
			zephir_check_call_status();
			_7 = ZEPHIR_IS_LONG_IDENTICAL(_8, 0);
		}
		if (_7) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "constant", &_10, &_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, image, "setimagecompression", NULL, _9);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, quality);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagecompressionquality", NULL, _11);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(image, "getimageblob", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_image"), PH_NOISY_CC);
	if (zephir_instance_of_ev(_0, zephir_get_internal_ce(SS("imagick") TSRMLS_CC) TSRMLS_CC)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "clear", NULL);
		zephir_check_call_status();
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2, "destroy", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get instance
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance) {


	RETURN_MEMBER(this_ptr, "_image");

}

/**
 * Sets the limit for a particular resource in megabytes
 * @param int type Refer to the list of resourcetype constants (@see http://php.net/manual/ru/imagick.constants.php#imagick.constants.resourcetypes.)
 * @param int limit The resource limit. The unit depends on the type of the resource being limited.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit) {

	zval *type_param = NULL, *limit_param = NULL, *_0, *_1, *_2;
	int type, limit, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &limit_param);

	type = zephir_get_intval(type_param);
	limit = zephir_get_intval(limit_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, limit);
	ZEPHIR_CALL_METHOD(NULL, _0, "setresourcelimit", NULL, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

