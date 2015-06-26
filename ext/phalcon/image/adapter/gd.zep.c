
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *version = NULL, *info = NULL, *matches, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3 = NULL, *_4, _5, _6, *_7 = NULL, *_8, *_9;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SS("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/image/adapter/gd.zep", 39);
		return;
	}
	ZEPHIR_INIT_VAR(version);
	ZVAL_NULL(version);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "GD_VERSION", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 206, &_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(version);
		ZEPHIR_GET_CONSTANT(version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 231);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(_3);
		zephir_array_fetch_string(&_4, info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 47 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/\\d+\\.\\d+(?:\\.\\d+)?/", 0);
		zephir_preg_match(_3, &_1, _4, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 48 TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, ">=", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "version_compare", NULL, 232, version, &_5, &_6);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalcon/image/adapter/gd.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	_9 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_9);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _16;
	zephir_fcall_cache_entry *_15 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11 = NULL, *_12 = NULL, *_13, *_14 = NULL, _17, _18;
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


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "realpath", NULL, 25, _2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _3 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", NULL, 233, _4);
		zephir_check_call_status();
		if (zephir_is_true(imageinfo)) {
			zephir_array_fetch_long(&_5, imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 77 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
			zephir_array_fetch_long(&_6, imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 78 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _6 TSRMLS_CC);
			zephir_array_fetch_long(&_7, imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 79 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _7 TSRMLS_CC);
			zephir_array_fetch_string(&_8, imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 80 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_mime"), _8 TSRMLS_CC);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(_9, 1)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "imagecreatefromgif", NULL, 234, _10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9, 2)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "imagecreatefromjpeg", NULL, 235, _10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9, 3)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "imagecreatefrompng", NULL, 236, _10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9, 15)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "imagecreatefromwbmp", NULL, 237, _10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_9, 16)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "imagecreatefromxbm", NULL, 238, _10);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _11 TSRMLS_CC);
				break;
			}
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
			if (zephir_is_true(_10)) {
				ZEPHIR_INIT_VAR(_12);
				object_init_ex(_12, phalcon_image_exception_ce);
				_13 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_14);
				ZEPHIR_CONCAT_SVS(_14, "Installed GD does not support ", _13, " images");
				ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 2, _14);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12, "phalcon/image/adapter/gd.zep", 101 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 103);
				return;
			}
			break;
		} while(0);

		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_15, 239, _10, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	} else {
		_16 = !width;
		if (!(_16)) {
			_16 = !height;
		}
		if (_16) {
			ZEPHIR_INIT_NVAR(_12);
			object_init_ex(_12, phalcon_image_exception_ce);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_14);
			ZEPHIR_CONCAT_SV(_14, "Failed to create image from file ", _2);
			ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 2, _14);
			zephir_check_call_status();
			zephir_throw_exception_debug(_12, "phalcon/image/adapter/gd.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_17);
		ZVAL_LONG(&_17, width);
		ZEPHIR_SINIT_VAR(_18);
		ZVAL_LONG(&_18, height);
		ZEPHIR_CALL_FUNCTION(&_3, "imagecreatetruecolor", NULL, 240, &_17, &_18);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), _3 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 241, _4, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_15, 239, _9, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _10 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_13);
		ZVAL_LONG(_13, width);
		zephir_update_property_this(this_ptr, SL("_width"), _13 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_13);
		ZVAL_LONG(_13, height);
		zephir_update_property_this(this_ptr, SL("_height"), _13 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_13);
		ZVAL_LONG(_13, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _13 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_13);
		ZVAL_STRING(_13, "image/png", 1);
		zephir_update_property_this(this_ptr, SL("_mime"), _13 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zephir_fcall_cache_entry *_8 = NULL, *_18 = NULL, *_23 = NULL, *_25 = NULL;
	zend_bool _4, _7;
	zval *width_param = NULL, *height_param = NULL, *image = NULL, *pre_width = NULL, *pre_height = NULL, *reduction_width, *reduction_height, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, *_5, _6 = zval_used_for_init, *_9, *_10, *_11, _12 = zval_used_for_init, _13 = zval_used_for_init, _14 = zval_used_for_init, _15 = zval_used_for_init, *_16 = NULL, *_17, *_19, *_20, _21, *_22 = NULL, *_24 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 232, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_OBS_VAR(pre_width);
		zephir_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(pre_height);
		zephir_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4 = width > (zephir_safe_div_zval_long(_3, 2 TSRMLS_CC));
		if (_4) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			_4 = height > (zephir_safe_div_zval_long(_5, 2 TSRMLS_CC));
		}
		if (_4) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (width * 1.1));
			ZEPHIR_INIT_VAR(reduction_width);
			zephir_round(reduction_width, &_1, NULL, NULL TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_6);
			ZVAL_LONG(&_6, (height * 1.1));
			ZEPHIR_INIT_VAR(reduction_height);
			zephir_round(reduction_height, &_6, NULL, NULL TSRMLS_CC);
			while (1) {
				_7 = ZEPHIR_LT_LONG(reduction_width, zephir_safe_div_zval_long(pre_width, 2 TSRMLS_CC));
				if (_7) {
					_7 = ZEPHIR_LT_LONG(reduction_height, zephir_safe_div_zval_long(pre_height, 2 TSRMLS_CC));
				}
				if (!(_7)) {
					break;
				}
				ZEPHIR_INIT_NVAR(pre_width);
				ZVAL_DOUBLE(pre_width, 2);
				ZEPHIR_INIT_NVAR(pre_height);
				ZVAL_DOUBLE(pre_height, 2);
			}
			ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_8, 0, pre_width, pre_height);
			zephir_check_call_status();
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_12);
			ZVAL_LONG(&_12, 0);
			ZEPHIR_SINIT_VAR(_13);
			ZVAL_LONG(&_13, 0);
			ZEPHIR_SINIT_VAR(_14);
			ZVAL_LONG(&_14, 0);
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_LONG(&_15, 0);
			ZEPHIR_CALL_FUNCTION(&_16, "imagecopyresized", NULL, 242, image, _9, &_12, &_13, &_14, &_15, pre_width, pre_height, _10, _11);
			zephir_check_call_status();
			if (zephir_is_true(_16)) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_18, 243, _17);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, width);
		ZEPHIR_INIT_VAR(_20);
		ZVAL_LONG(_20, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_8, 0, _19, _20);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 0);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 0);
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_LONG(&_14, 0);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, width);
		ZEPHIR_SINIT_VAR(_21);
		ZVAL_LONG(&_21, height);
		ZEPHIR_CALL_FUNCTION(&_16, "imagecopyresampled", NULL, 244, image, _9, &_6, &_12, &_13, &_14, &_15, &_21, pre_width, pre_height);
		zephir_check_call_status();
		if (zephir_is_true(_16)) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_18, 243, _10);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_22, "imagesx", &_23, 245, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _22 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_24, "imagesy", &_25, 246, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _24 TSRMLS_CC);
		}
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, width);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, 247, _3, &_6, &_12);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_18, 243, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_16, "imagesx", &_23, 245, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _16 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_22, "imagesy", &_25, 246, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _22 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zephir_fcall_cache_entry *_15 = NULL, *_17 = NULL, *_19 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image = NULL, *rect, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3 = NULL, *_4, *_5, _6, _7, _8, _9, _10, _11, _12, *_13 = NULL, *_14, *_16 = NULL, *_18 = NULL;
	int width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 232, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, _3, _4);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, offsetX);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, offsetY);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, width);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_LONG(&_10, height);
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_LONG(&_11, width);
		ZEPHIR_SINIT_VAR(_12);
		ZVAL_LONG(&_12, height);
		ZEPHIR_CALL_FUNCTION(&_13, "imagecopyresampled", NULL, 244, image, _5, &_1, &_6, &_7, &_8, &_9, &_10, &_11, &_12);
		zephir_check_call_status();
		if (zephir_is_true(_13)) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_15, 243, _14);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_16, "imagesx", &_17, 245, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _16 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_18, "imagesy", &_19, 246, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _18 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(rect);
		zephir_create_array(rect, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, offsetX);
		zephir_array_update_string(&rect, SL("x"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, offsetY);
		zephir_array_update_string(&rect, SL("y"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		zephir_array_update_string(&rect, SL("width"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		zephir_array_update_string(&rect, SL("height"), &_3, PH_COPY | PH_SEPARATE);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 248, _5, rect);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_15, 243, _14);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "imagesx", &_17, 245, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _13 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_16, "imagesy", &_19, 246, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _16 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, *image = NULL, *transparent = NULL, *width = NULL, *height = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5, *_6, _7, *_8 = NULL, *_9;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 249, _0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (360 - degrees));
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 250, _5, &_1, transparent, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 239, image, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 245, image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 246, image);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 251, _6, image, &_1, &_2, &_3, &_4, width, height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL;
	zval *direction_param = NULL, *image = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, *_4, *_5, *_6, *_7, *_8, _9 = zval_used_for_init, _10 = zval_used_for_init, _11 = zval_used_for_init, _12 = zval_used_for_init, *_14 = NULL, *_15 = NULL;
	int direction, x, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 232, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, _3, _4);
		zephir_check_call_status();
		if (direction == 11) {
			x = 0;
			while (1) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_5, x))) {
					break;
				}
				x++;
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, x);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 0);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, 0);
				ZEPHIR_SINIT_NVAR(_12);
				ZVAL_LONG(&_12, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 252, image, _6, &_1, &_9, &_10, &_11, &_12, _8);
				zephir_check_call_status();
			}
		} else {
			x = 0;
			while (1) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_5, x))) {
					break;
				}
				x++;
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, x);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, 0);
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_SINIT_NVAR(_12);
				ZVAL_LONG(&_12, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 252, image, _6, &_1, &_9, &_10, &_11, _8, &_12);
				zephir_check_call_status();
			}
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_14, "imagesx", NULL, 245, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _14 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_15, "imagesy", NULL, 246, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _15 TSRMLS_CC);
	} else {
		if (direction == 11) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_16, 253, _3, &_1);
			zephir_check_call_status();
		} else {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_16, 253, _4, &_1);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *_3 = NULL;
	zval *amount_param = NULL, *matrix, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, _6, _7, *_8 = NULL, *_9, *_10 = NULL, *_11, *_12 = NULL;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 166, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	zephir_round(_0, _2, &_1, NULL TSRMLS_CC);
	amount = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(matrix);
	zephir_create_array(matrix, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, amount);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (amount - 8));
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, 254, _5, matrix, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "imagesx", NULL, 245, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _10 TSRMLS_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "imagesy", NULL, 246, _11);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _12 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL, *_23 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection = NULL, *line = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, *_4, *_5 = NULL, *_7, *_8, *_9, _10 = zval_used_for_init, _11 = zval_used_for_init, _12 = zval_used_for_init, *_14, *_15, *_16 = NULL, *_17, *_18, *_19, _20 = zval_used_for_init, _21 = zval_used_for_init, _22 = zval_used_for_init, *_24, *_25 = NULL, *_26 = NULL;
	int height, opacity, stepping, offset, src_y, dst_y, dst_opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 166, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height TSRMLS_CC));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height TSRMLS_CC));
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_4) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "_create", &_6, 0, _3, _5);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 252, reflection, _7, &_1, &_10, &_11, &_12, _8, _9);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		src_y = ((zephir_get_numberval(_14) - offset) - 1);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		dst_y = (zephir_get_numberval(_15) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (opacity + ((stepping * ((height - offset))))));
			zephir_round(_5, &_1, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_5);
		} else {
			ZEPHIR_INIT_NVAR(_16);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, (opacity + ((stepping * offset))));
			zephir_round(_16, &_10, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_16);
		}
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_16);
		ZVAL_LONG(_16, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", &_6, 0, _17, _16);
		zephir_check_call_status();
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, 0);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 0);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, src_y);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 252, line, _18, &_11, &_12, &_20, &_21, _19, &_22);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, 4);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 0);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 0);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_23, 255, line, &_11, &_12, &_20, &_21, &_22);
		zephir_check_call_status();
		_24 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, 0);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, dst_y);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 0);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_13, 252, reflection, line, &_11, &_12, &_20, &_21, _24, &_22);
		zephir_check_call_status();
		offset++;
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, _14);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_25, "imagesx", NULL, 245, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _25 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_26, "imagesy", NULL, 246, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _26 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	int offsetX, offsetY, opacity, width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *overlay = NULL, *color = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, _4 = zval_used_for_init, *_5 = NULL, _6 = zval_used_for_init, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9, *_10, _11, _12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 256, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 239, overlay, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 245, overlay);
	zephir_check_call_status();
	width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 246, overlay);
	zephir_check_call_status();
	height = zephir_get_intval(_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_DOUBLE(&_4, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5, "abs", NULL, 166, &_4);
		zephir_check_call_status();
		zephir_round(_3, _5, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(_3);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 127);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 127);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 127);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 249, overlay, &_4, &_6, &_7, &_8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 257, overlay, &_4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, width);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 258, overlay, &_4, &_6, &_7, &_8, color);
		zephir_check_call_status();
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 241, _9, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, offsetX);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, offsetY);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, width);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, height);
	ZEPHIR_CALL_FUNCTION(&_5, "imagecopy", NULL, 252, _10, overlay, &_4, &_6, &_7, &_8, &_11, &_12);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zend_bool _9, _10, _11;
	zephir_fcall_cache_entry *_3 = NULL, *_17 = NULL;
	int offsetX, offsetY, opacity, r, g, b, size, angle, s0 = 0, s1 = 0, s4 = 0, s5 = 0, width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *space = NULL, *color = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, _4 = zval_used_for_init, *_5, *_6, *_7, *_8, *_12 = NULL, *_13 = NULL, *_14, _15 = zval_used_for_init, _16 = zval_used_for_init, *_18, *_19;
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


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, 166, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (fontfile && Z_STRLEN_P(fontfile)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 259, &_1, &_4, fontfile, text);
		zephir_check_call_status();
		if (zephir_array_isset_long(space, 0)) {
			ZEPHIR_OBS_VAR(_5);
			zephir_array_fetch_long(&_5, space, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 351 TSRMLS_CC);
			s0 = zephir_get_intval(_5);
			ZEPHIR_OBS_VAR(_6);
			zephir_array_fetch_long(&_6, space, 1, PH_NOISY, "phalcon/image/adapter/gd.zep", 352 TSRMLS_CC);
			s1 = zephir_get_intval(_6);
			ZEPHIR_OBS_VAR(_7);
			zephir_array_fetch_long(&_7, space, 4, PH_NOISY, "phalcon/image/adapter/gd.zep", 353 TSRMLS_CC);
			s4 = zephir_get_intval(_7);
			ZEPHIR_OBS_VAR(_8);
			zephir_array_fetch_long(&_8, space, 5, PH_NOISY, "phalcon/image/adapter/gd.zep", 354 TSRMLS_CC);
			s5 = zephir_get_intval(_8);
		}
		_9 = !s0;
		if (!(_9)) {
			_9 = !s1;
		}
		_10 = _9;
		if (!(_10)) {
			_10 = !s4;
		}
		_11 = _10;
		if (!(_11)) {
			_11 = !s5;
		}
		if (_11) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/image/adapter/gd.zep", 358);
			return;
		}
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (s4 - s0));
		ZEPHIR_CALL_FUNCTION(&_12, "abs", &_3, 166, &_1);
		zephir_check_call_status();
		width = (zephir_get_numberval(_12) + 10);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_13, "abs", &_3, 166, &_1);
		zephir_check_call_status();
		height = (zephir_get_numberval(_13) + 10);
		if (offsetX < 0) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_14) - width) + offsetX);
		}
		if (offsetY < 0) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_14) - height) + offsetY);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, r);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, g);
		ZEPHIR_SINIT_VAR(_15);
		ZVAL_LONG(&_15, b);
		ZEPHIR_SINIT_VAR(_16);
		ZVAL_LONG(&_16, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_17, 249, _14, &_1, &_4, &_15, &_16);
		zephir_check_call_status();
		angle = 0;
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, angle);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, offsetX);
		ZEPHIR_SINIT_NVAR(_16);
		ZVAL_LONG(&_16, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 260, _18, &_1, &_4, &_15, &_16, color, fontfile, text);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_CALL_FUNCTION(&_12, "imagefontwidth", NULL, 261, &_1);
		zephir_check_call_status();
		width = (zephir_get_intval(_12) * zephir_fast_strlen_ev(text));
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_CALL_FUNCTION(&_13, "imagefontheight", NULL, 262, &_1);
		zephir_check_call_status();
		height = zephir_get_intval(_13);
		if (offsetX < 0) {
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_18) - width) + offsetX);
		}
		if (offsetY < 0) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_14) - height) + offsetY);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, r);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, g);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, b);
		ZEPHIR_SINIT_NVAR(_16);
		ZVAL_LONG(&_16, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_17, 249, _14, &_1, &_4, &_15, &_16);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, offsetX);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 263, _19, &_1, &_4, &_15, text, color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	zend_bool _12;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_24 = NULL;
	int mask_width, mask_height, x, y, alpha, ZEPHIR_LAST_CALL_STATUS;
	zval *mask, *maskImage = NULL, *newimage = NULL, *tempImage = NULL, *color = NULL, *index = NULL, *r = NULL, *g = NULL, *b = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4, *_5, _6 = zval_used_for_init, _7 = zval_used_for_init, _8 = zval_used_for_init, _9 = zval_used_for_init, *_11, *_13, *_14, *_15, *_16, *_17, _18, _19, *_23;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 256, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 245, maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 246, maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 239, maskImage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, 0, _4, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, 239, newimage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 249, newimage, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 264, newimage, &_6, &_7, color);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_12 = !ZEPHIR_IS_LONG(_11, mask_width);
	if (!(_12)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		_12 = !ZEPHIR_IS_LONG(_13, mask_height);
	}
	if (_12) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 240, _14, _15);
		zephir_check_call_status();
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, 0);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_VAR(_18);
		ZVAL_LONG(&_18, mask_width);
		ZEPHIR_SINIT_VAR(_19);
		ZVAL_LONG(&_19, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 244, tempImage, maskImage, &_6, &_7, &_8, &_9, _16, _17, &_18, &_19);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, 243, maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(maskImage, tempImage);
	}
	x = 0;
	while (1) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_14, x))) {
			break;
		}
		y = 0;
		while (1) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_GT_LONG(_15, y))) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, x);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, 265, maskImage, &_6, &_7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, 266, maskImage, index);
			zephir_check_call_status();
			if (zephir_array_isset_string(color, SS("red"))) {
				zephir_array_fetch_string(&_23, color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 431 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_23, 2 TSRMLS_CC));
				alpha = (127 - zephir_get_intval(&_6));
			}
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, x);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, 265, _16, &_7, &_8);
			zephir_check_call_status();
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, 266, _17, index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(r);
			zephir_array_fetch_string(&r, color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(g);
			zephir_array_fetch_string(&g, color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(b);
			zephir_array_fetch_string(&b, color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, 249, newimage, r, g, b, &_7);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, x);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_24, 267, newimage, &_7, &_8, color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, 243, _14);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, 243, maskImage);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background = NULL, *color = NULL, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, _5 = zval_used_for_init, *_6, *_7, *_8, *_9 = NULL, *_10;
	int r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "_create", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 249, background, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 241, background, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopy", NULL, 252, background, _6, &_2, &_3, &_4, &_5, _7, _8);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, _10);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, *_0, _1 = zval_used_for_init;
	int radius, i, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!(i < radius)) {
			break;
		}
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 255, _0, &_1);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zval *amount_param = NULL, *color = NULL, *_0, *_1, *_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_6, _7 = zval_used_for_init, _8 = zval_used_for_init;
	int amount, x, y, x1, y1, x2, y2, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_GT_LONG(_1, y))) {
				break;
			}
			x1 = (x + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			y1 = (y + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, x1);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_5, 265, _2, &_3, &_4);
			zephir_check_call_status();
			x2 = (x + amount);
			y2 = (y + amount);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, x1);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, y1);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, x2);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_9, 258, _6, &_3, &_4, &_7, &_8, color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	zend_bool _8;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *_4, *_5 = NULL, *_7, *_9 = NULL, *_10 = NULL, *_11, *_12;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&_1, "pathinfo", NULL, 207, file, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(ext);
	zephir_fast_strtolower(ext, _1);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", &_3, 268, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_2, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5, "image_type_to_mime_type", &_6, 269, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _5 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 270, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_3, 268, ext, &_0);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_LONG(_5, 0);
	if (!(_8)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_3, 268, ext, &_0);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_LONG(_9, 0);
	}
	if (_8) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 2);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "image_type_to_mime_type", &_6, 269, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _10 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 271, _7, file, &_0);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_3, 268, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "image_type_to_mime_type", &_6, 269, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _10 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 272, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_3, 268, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 15);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "image_type_to_mime_type", &_6, 269, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _10 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 273, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_3, 268, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 16);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "image_type_to_mime_type", &_6, 269, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _10 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 274, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_11);
	object_init_ex(_11, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SVS(_12, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, 2, _12);
	zephir_check_call_status();
	zephir_throw_exception_debug(_11, "phalcon/image/adapter/gd.zep", 537 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _7;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12;
	zval *ext = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, ext);
	zephir_get_strval(ext, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", &_3, 268, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_2, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 270, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 275);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_3, 268, ext, &_1);
	zephir_check_call_status();
	_7 = ZEPHIR_IS_LONG(_6, 0);
	if (!(_7)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "strcmp", &_3, 268, ext, &_1);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_LONG(_8, 0);
	}
	if (_7) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 271, _4, ZEPHIR_GLOBAL(global_null), &_1);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 275);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_3, 268, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_9, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 272, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 275);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_10, "strcmp", &_3, 268, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_10, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 273, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 275);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_3, 268, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_11, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 274, _4, ZEPHIR_GLOBAL(global_null));
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5, 275);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_12);
	object_init_ex(_12, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SVS(_13, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 2, _13);
	zephir_check_call_status();
	zephir_throw_exception_debug(_12, "phalcon/image/adapter/gd.zep", 565 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, *image = NULL, _0, _1;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, width);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 240, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 241, image, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 239, image, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_CCTOR(image);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *image;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	if (Z_TYPE_P(image) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 243, image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

