
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


ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL, *_11 = NULL;
	zval *version = NULL, *info = NULL, *matches, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, _6, _7, *_8 = NULL, *_10, *_12;

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
	ZEPHIR_CALL_FUNCTION(&_2, "defined", &_3, &_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(version);
		ZEPHIR_GET_CONSTANT(version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(_4);
		zephir_array_fetch_string(&_5, info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 47 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/\\d+\\.\\d+(?:\\.\\d+)?/", 0);
		zephir_preg_match(_4, &_1, _5, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_4)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 48 TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, ">=", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "version_compare", &_9, version, &_6, &_7);
	zephir_check_call_status();
	if (!(zephir_is_true(_8))) {
		ZEPHIR_INIT_NVAR(_4);
		object_init_ex(_4, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SV(_10, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_11, _10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalcon/image/adapter/gd.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	_12 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_12);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _19;
	zephir_fcall_cache_entry *_18 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_17 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo = NULL, *_0, *_1, *_2, *_3 = NULL, *_5, *_7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL, *_14 = NULL, *_15, *_16 = NULL, _20, _21;
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
		ZEPHIR_CALL_SELF(NULL, "check", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "realpath", &_4, _2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _3 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", &_6, _5);
		zephir_check_call_status();
		if (zephir_is_true(imageinfo)) {
			zephir_array_fetch_long(&_7, imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 77 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _7 TSRMLS_CC);
			zephir_array_fetch_long(&_8, imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 78 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
			zephir_array_fetch_long(&_9, imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 79 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _9 TSRMLS_CC);
			zephir_array_fetch_string(&_10, imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 80 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_mime"), _10 TSRMLS_CC);
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(_11, 1)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "imagecreatefromgif", NULL, _12);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_11, 2)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "imagecreatefromjpeg", NULL, _12);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_11, 3)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "imagecreatefrompng", NULL, _12);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_11, 15)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "imagecreatefromwbmp", NULL, _12);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_11, 16)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "imagecreatefromxbm", NULL, _12);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), _13 TSRMLS_CC);
				break;
			}
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
			if (zephir_is_true(_12)) {
				ZEPHIR_INIT_VAR(_14);
				object_init_ex(_14, phalcon_image_exception_ce);
				_15 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_16);
				ZEPHIR_CONCAT_SVS(_16, "Installed GD does not support ", _15, " images");
				ZEPHIR_CALL_METHOD(NULL, _14, "__construct", &_17, _16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14, "phalcon/image/adapter/gd.zep", 101 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 103);
				return;
			}
			break;
		} while(0);

		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_18, _12, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	} else {
		_19 = !width;
		if (!(_19)) {
			_19 = !height;
		}
		if (_19) {
			ZEPHIR_INIT_NVAR(_14);
			object_init_ex(_14, phalcon_image_exception_ce);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_16);
			ZEPHIR_CONCAT_SV(_16, "Failed to create image from file ", _2);
			ZEPHIR_CALL_METHOD(NULL, _14, "__construct", &_17, _16);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14, "phalcon/image/adapter/gd.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_20);
		ZVAL_LONG(&_20, width);
		ZEPHIR_SINIT_VAR(_21);
		ZVAL_LONG(&_21, height);
		ZEPHIR_CALL_FUNCTION(&_3, "imagecreatetruecolor", NULL, &_20, &_21);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), _3 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, _5, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_18, _11, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _12 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_15);
		ZVAL_LONG(_15, width);
		zephir_update_property_this(this_ptr, SL("_width"), _15 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_15);
		ZVAL_LONG(_15, height);
		zephir_update_property_this(this_ptr, SL("_height"), _15 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_15);
		ZVAL_LONG(_15, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _15 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_15);
		ZVAL_STRING(_15, "image/png", 1);
		zephir_update_property_this(this_ptr, SL("_mime"), _15 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zephir_fcall_cache_entry *_9 = NULL, *_19 = NULL, *_24 = NULL, *_26 = NULL;
	zend_bool _5, _8;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *width_param = NULL, *height_param = NULL, *image = NULL, *pre_width = NULL, *pre_height = NULL, *reduction_width, *reduction_height, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_6, _7 = zval_used_for_init, *_10, *_11, *_12, _13 = zval_used_for_init, _14 = zval_used_for_init, _15 = zval_used_for_init, _16 = zval_used_for_init, *_17 = NULL, *_18, *_20, *_21, _22, *_23 = NULL, *_25 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", &_3, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_OBS_VAR(pre_width);
		zephir_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(pre_height);
		zephir_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_5 = width > (zephir_safe_div_zval_long(_4, 2 TSRMLS_CC));
		if (_5) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			_5 = height > (zephir_safe_div_zval_long(_6, 2 TSRMLS_CC));
		}
		if (_5) {
			ZEPHIR_INIT_VAR(reduction_width);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (width * 1.1));
			zephir_round(reduction_width, &_1, NULL, NULL TSRMLS_CC);
			ZEPHIR_INIT_VAR(reduction_height);
			ZEPHIR_SINIT_VAR(_7);
			ZVAL_LONG(&_7, (height * 1.1));
			zephir_round(reduction_height, &_7, NULL, NULL TSRMLS_CC);
			while (1) {
				_8 = ZEPHIR_LT_LONG(reduction_width, zephir_safe_div_zval_long(pre_width, 2 TSRMLS_CC));
				if (_8) {
					_8 = ZEPHIR_LT_LONG(reduction_height, zephir_safe_div_zval_long(pre_height, 2 TSRMLS_CC));
				}
				if (!(_8)) {
					break;
				}
				ZEPHIR_INIT_NVAR(pre_width);
				ZVAL_DOUBLE(pre_width, 2);
				ZEPHIR_INIT_NVAR(pre_height);
				ZVAL_DOUBLE(pre_height, 2);
			}
			ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, pre_width, pre_height);
			zephir_check_call_status();
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_13);
			ZVAL_LONG(&_13, 0);
			ZEPHIR_SINIT_VAR(_14);
			ZVAL_LONG(&_14, 0);
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_LONG(&_15, 0);
			ZEPHIR_SINIT_VAR(_16);
			ZVAL_LONG(&_16, 0);
			ZEPHIR_CALL_FUNCTION(&_17, "imagecopyresized", NULL, image, _10, &_13, &_14, &_15, &_16, pre_width, pre_height, _11, _12);
			zephir_check_call_status();
			if (zephir_is_true(_17)) {
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, _18);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_VAR(_20);
		ZVAL_LONG(_20, width);
		ZEPHIR_INIT_VAR(_21);
		ZVAL_LONG(_21, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, _20, _21);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 0);
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_LONG(&_14, 0);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, 0);
		ZEPHIR_SINIT_NVAR(_16);
		ZVAL_LONG(&_16, width);
		ZEPHIR_SINIT_VAR(_22);
		ZVAL_LONG(&_22, height);
		ZEPHIR_CALL_FUNCTION(&_17, "imagecopyresampled", NULL, image, _10, &_7, &_13, &_14, &_15, &_16, &_22, pre_width, pre_height);
		zephir_check_call_status();
		if (zephir_is_true(_17)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, _11);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_23, "imagesx", &_24, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _23 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_25, "imagesy", &_26, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _25 TSRMLS_CC);
		}
	} else {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, width);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, _4, &_7, &_13);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_19, _6);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_17, "imagesx", &_24, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _17 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_23, "imagesy", &_26, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _23 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_20 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image = NULL, *rect, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, *_6, _7, _8, _9, _10, _11, _12, _13, *_14 = NULL, *_15, *_17 = NULL, *_19 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", &_3, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, width);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, _4, _5);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, offsetX);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, offsetY);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_LONG(&_10, width);
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_LONG(&_11, height);
		ZEPHIR_SINIT_VAR(_12);
		ZVAL_LONG(&_12, width);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_LONG(&_13, height);
		ZEPHIR_CALL_FUNCTION(&_14, "imagecopyresampled", NULL, image, _6, &_1, &_7, &_8, &_9, &_10, &_11, &_12, &_13);
		zephir_check_call_status();
		if (zephir_is_true(_14)) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, _15);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_17, "imagesx", &_18, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _17 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_19, "imagesy", &_20, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _19 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(rect);
		zephir_create_array(rect, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, offsetX);
		zephir_array_update_string(&rect, SL("x"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, offsetY);
		zephir_array_update_string(&rect, SL("y"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, width);
		zephir_array_update_string(&rect, SL("width"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, height);
		zephir_array_update_string(&rect, SL("height"), &_4, PH_COPY | PH_SEPARATE);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, _6, rect);
		zephir_check_call_status();
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_16, _15);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_14, "imagesx", &_18, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _14 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_17, "imagesy", &_20, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _17 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, _0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (360 - degrees));
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, _5, &_1, transparent, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, image, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, image);
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
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, _6, image, &_1, &_2, &_3, &_4, width, height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_fcall_cache_entry *_14 = NULL, *_17 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *direction_param = NULL, *image = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5, *_6, *_7, *_8, *_9, _10 = zval_used_for_init, _11 = zval_used_for_init, _12 = zval_used_for_init, _13 = zval_used_for_init, *_15 = NULL, *_16 = NULL;
	int direction, x, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", &_3, _0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_2, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, _4, _5);
		zephir_check_call_status();
		if (direction == 11) {
			x = 0;
			while (1) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_6, x))) {
					break;
				}
				x++;
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, x);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, 0);
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, ((zephir_get_numberval(_8) - x) - 1));
				ZEPHIR_SINIT_NVAR(_12);
				ZVAL_LONG(&_12, 0);
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, image, _7, &_1, &_10, &_11, &_12, &_13, _9);
				zephir_check_call_status();
			}
		} else {
			x = 0;
			while (1) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				if (!(ZEPHIR_GT_LONG(_6, x))) {
					break;
				}
				x++;
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, x);
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, 0);
				ZEPHIR_SINIT_NVAR(_12);
				ZVAL_LONG(&_12, ((zephir_get_numberval(_8) - x) - 1));
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, image, _7, &_1, &_10, &_11, &_12, _9, &_13);
				zephir_check_call_status();
			}
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _6);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_15, "imagesx", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _15 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_16, "imagesy", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _16 TSRMLS_CC);
	} else {
		if (direction == 11) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_17, _4, &_1);
			zephir_check_call_status();
		} else {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", &_17, _5, &_1);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *_4 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *amount_param = NULL, *matrix, *_0, _1 = zval_used_for_init, *_2 = NULL, *_5 = NULL, *_6, _7, _8, *_9 = NULL, *_10, *_11 = NULL, *_12, *_13 = NULL;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	zephir_round(_0, _2, &_1, NULL TSRMLS_CC);
	amount = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(matrix);
	zephir_create_array(matrix, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	zephir_array_fast_append(matrix, _4);
	ZEPHIR_INIT_NVAR(_4);
	zephir_create_array(_4, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, amount);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	zephir_array_fast_append(matrix, _4);
	ZEPHIR_INIT_NVAR(_4);
	zephir_create_array(_4, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, -1);
	zephir_array_fast_append(_4, _5);
	zephir_array_fast_append(matrix, _4);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, (amount - 8));
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "imageconvolution", NULL, _6, matrix, &_7, &_8);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "imagesx", NULL, _10);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _11 TSRMLS_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "imagesy", NULL, _12);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _13 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zephir_fcall_cache_entry *_7 = NULL, *_14 = NULL, *_24 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection = NULL, *line = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5, *_6 = NULL, *_8, *_9, *_10, _11 = zval_used_for_init, _12 = zval_used_for_init, _13 = zval_used_for_init, *_15, *_16, *_17 = NULL, *_18, *_19, *_20, _21 = zval_used_for_init, _22 = zval_used_for_init, _23 = zval_used_for_init, *_25, *_26 = NULL, *_27 = NULL;
	int height, opacity, stepping, offset, src_y, dst_y, dst_opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height TSRMLS_CC));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height TSRMLS_CC));
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(_5) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "_create", &_7, _4, _6);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, reflection, _8, &_1, &_11, &_12, &_13, _9, _10);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		src_y = ((zephir_get_numberval(_15) - offset) - 1);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		dst_y = (zephir_get_numberval(_16) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(_6);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (opacity + ((stepping * ((height - offset))))));
			zephir_round(_6, &_1, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_6);
		} else {
			ZEPHIR_INIT_NVAR(_17);
			ZEPHIR_SINIT_NVAR(_11);
			ZVAL_LONG(&_11, (opacity + ((stepping * offset))));
			zephir_round(_17, &_11, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_17);
		}
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_17);
		ZVAL_LONG(_17, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", &_7, _18, _17);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 0);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 0);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, src_y);
		ZEPHIR_SINIT_NVAR(_23);
		ZVAL_LONG(&_23, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, line, _19, &_12, &_13, &_21, &_22, _20, &_23);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 4);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 0);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, 0);
		ZEPHIR_SINIT_NVAR(_23);
		ZVAL_LONG(&_23, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_24, line, &_12, &_13, &_21, &_22, &_23);
		zephir_check_call_status();
		_25 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, 0);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, dst_y);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 0);
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, 0);
		ZEPHIR_SINIT_NVAR(_23);
		ZVAL_LONG(&_23, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, reflection, line, &_12, &_13, &_21, &_22, _25, &_23);
		zephir_check_call_status();
		offset++;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _15);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_26, "imagesx", NULL, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _26 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_27, "imagesy", NULL, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _27 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int offsetX, offsetY, opacity, width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *overlay = NULL, *color = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, _4 = zval_used_for_init, *_5 = NULL, _7 = zval_used_for_init, _8 = zval_used_for_init, _9 = zval_used_for_init, *_10, *_11, _12, _13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, overlay, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, overlay);
	zephir_check_call_status();
	width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, overlay);
	zephir_check_call_status();
	height = zephir_get_intval(_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_DOUBLE(&_4, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5, "abs", &_6, &_4);
		zephir_check_call_status();
		zephir_round(_3, _5, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(_3);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 127);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 127);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, 127);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, overlay, &_4, &_7, &_8, &_9);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, overlay, &_4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, width);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, overlay, &_4, &_7, &_8, &_9, color);
		zephir_check_call_status();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, _10, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, offsetX);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, offsetY);
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, width);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, height);
	ZEPHIR_CALL_FUNCTION(&_5, "imagecopy", NULL, _11, overlay, &_4, &_7, &_8, &_9, &_12, &_13);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zephir_fcall_cache_entry *_17 = NULL;
	zend_bool _9, _10, _11;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_2, "abs", &_3, &_1);
	zephir_check_call_status();
	zephir_round(_0, _2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(_0);
	if (fontfile && Z_STRLEN_P(fontfile)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, &_1, &_4, fontfile, text);
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
		ZEPHIR_CALL_FUNCTION(&_12, "abs", &_3, &_1);
		zephir_check_call_status();
		width = (zephir_get_numberval(_12) + 10);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_13, "abs", &_3, &_1);
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
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_17, _14, &_1, &_4, &_15, &_16);
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
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, _18, &_1, &_4, &_15, &_16, color, fontfile, text);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_CALL_FUNCTION(&_12, "imagefontwidth", NULL, &_1);
		zephir_check_call_status();
		width = (zephir_get_intval(_12) * zephir_fast_strlen_ev(text));
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_CALL_FUNCTION(&_13, "imagefontheight", NULL, &_1);
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
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_17, _14, &_1, &_4, &_15, &_16);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, size);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, offsetX);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, _19, &_1, &_4, &_15, text, color);
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



	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, maskImage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, _4, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", &_3, newimage, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, newimage, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, newimage, &_6, &_7, color);
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
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, _14, _15);
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
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, tempImage, maskImage, &_6, &_7, &_8, &_9, _16, _17, &_18, &_19);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, maskImage);
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
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, maskImage, &_6, &_7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, maskImage, index);
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
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, _16, &_7, &_8);
			zephir_check_call_status();
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, _17, index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(r);
			zephir_array_fetch_string(&r, color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(g);
			zephir_array_fetch_string(&g, color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(b);
			zephir_array_fetch_string(&b, color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 436 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, newimage, r, g, b, &_7);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, x);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_24, newimage, &_7, &_8, color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, _14);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, maskImage);
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
	ZEPHIR_CALL_METHOD(&background, this_ptr, "_create", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, background, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, background, ZEPHIR_GLOBAL(global_true));
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
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopy", NULL, background, _6, &_2, &_3, &_4, &_5, _7, _8);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _10);
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
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, _0, &_1);
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
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_5, _2, &_3, &_4);
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
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_9, _6, &_3, &_4, &_7, &_8, color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	zend_bool _9;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_7 = NULL, *_14 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_5, *_6 = NULL, *_8, *_10 = NULL, *_11 = NULL, *_12, *_13;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(ext);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&_1, "pathinfo", &_2, file, &_0);
	zephir_check_call_status();
	zephir_fast_strtolower(ext, _1);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", &_4, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6, "image_type_to_mime_type", &_7, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _6 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, _8, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_4, ext, &_0);
	zephir_check_call_status();
	_9 = ZEPHIR_IS_LONG(_6, 0);
	if (!(_9)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_10, "strcmp", &_4, ext, &_0);
		zephir_check_call_status();
		_9 = ZEPHIR_IS_LONG(_10, 0);
	}
	if (_9) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 2);
		zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_7, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _8, file, &_0);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_4, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_6, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_7, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, _8, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_4, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_6, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 15);
		zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_7, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, _8, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_4, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_6, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 16);
		zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_7, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, _8, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_12);
	object_init_ex(_12, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SVS(_13, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", &_14, _13);
	zephir_check_call_status();
	zephir_throw_exception_debug(_12, "phalcon/image/adapter/gd.zep", 537 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _8;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_6 = NULL, *_15 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _2 = zval_used_for_init, *_3 = NULL, *_5, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13;
	zval *ext = NULL, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, ext);
	zephir_get_strval(ext, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", &_4, ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_3, 0)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "strcmp", &_4, ext, &_2);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_LONG(_7, 0);
	if (!(_8)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_4, ext, &_2);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_LONG(_9, 0);
	}
	if (_8) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _5, ZEPHIR_GLOBAL(global_null), &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_10, "strcmp", &_4, ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_10, 0)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "strcmp", &_4, ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_11, 0)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_12, "strcmp", &_4, ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_12, 0)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, _5, ZEPHIR_GLOBAL(global_null));
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_13);
	object_init_ex(_13, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVS(_14, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_15, _14);
	zephir_check_call_status();
	zephir_throw_exception_debug(_13, "phalcon/image/adapter/gd.zep", 565 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, image, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, image, ZEPHIR_GLOBAL(global_true));
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
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

