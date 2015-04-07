
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;
	zval *version = NULL, *info = NULL, *matches, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5 = NULL, *_6 = NULL, _8, *_10, *_12;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SS("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/image/adapter/gd.zep", 35);
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
		zephir_array_fetch_string(&_4, info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 43 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "/\\d+\\.\\d+(?:\\.\\d+)?/", ZEPHIR_TEMP_PARAM_COPY);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, _5, _4, matches);
		zephir_check_temp_parameter(_5);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 44 TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, ">=", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "version_compare", &_9, version, &_1, &_8);
	zephir_check_call_status();
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_NVAR(_5);
		object_init_ex(_5, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SV(_10, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_11, _10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "phalcon/image/adapter/gd.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	_12 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_12);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _18;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_17 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo = NULL, *_0, *_1, *_2, *_3 = NULL, *_5, *_7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL, *_14 = NULL, *_15, *_16 = NULL, *_19;
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
			zephir_array_fetch_long(&_7, imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 73 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _7 TSRMLS_CC);
			zephir_array_fetch_long(&_8, imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 74 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
			zephir_array_fetch_long(&_9, imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 75 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _9 TSRMLS_CC);
			zephir_array_fetch_string(&_10, imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 76 TSRMLS_CC);
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
				zephir_throw_exception_debug(_14, "phalcon/image/adapter/gd.zep", 97 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 99);
				return;
			}
			break;
		} while(0);

		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_BOOL(_14, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, _12, _14);
		zephir_check_call_status();
	} else {
		_18 = !width;
		if (!(_18)) {
			_18 = !height;
		}
		if (_18) {
			ZEPHIR_INIT_NVAR(_14);
			object_init_ex(_14, phalcon_image_exception_ce);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_16);
			ZEPHIR_CONCAT_SV(_16, "Failed to create image from file ", _2);
			ZEPHIR_CALL_METHOD(NULL, _14, "__construct", &_17, _16);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14, "phalcon/image/adapter/gd.zep", 108 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, width);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, height);
		ZEPHIR_CALL_FUNCTION(&_3, "imagecreatetruecolor", NULL, _14, _19);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), _3 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, _5, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_BOOL(_14, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, _11, _14);
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

	zephir_fcall_cache_entry *_9 = NULL;
	zend_bool _5, _8;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *width_param = NULL, *height_param = NULL, *image = NULL, *pre_width = NULL, *pre_height = NULL, *reduction_width, *reduction_height, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_6, _7, *_10, *_11, *_12, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18, *_19, *_20, *_21 = NULL, *_22 = NULL;
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
			ZEPHIR_INIT_VAR(_13);
			ZVAL_LONG(_13, 0);
			ZEPHIR_INIT_VAR(_14);
			ZVAL_LONG(_14, 0);
			ZEPHIR_INIT_VAR(_15);
			ZVAL_LONG(_15, 0);
			ZEPHIR_INIT_VAR(_16);
			ZVAL_LONG(_16, 0);
			ZEPHIR_CALL_FUNCTION(&_17, "imagecopyresized", NULL, image, _10, _13, _14, _15, _16, pre_width, pre_height, _11, _12);
			zephir_check_call_status();
			if (zephir_is_true(_17)) {
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _18);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, width);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", &_9, _13, _14);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 0);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, 0);
		ZEPHIR_INIT_NVAR(_15);
		ZVAL_LONG(_15, 0);
		ZEPHIR_INIT_NVAR(_16);
		ZVAL_LONG(_16, 0);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, width);
		ZEPHIR_INIT_VAR(_20);
		ZVAL_LONG(_20, height);
		ZEPHIR_CALL_FUNCTION(&_17, "imagecopyresampled", NULL, image, _10, _13, _14, _15, _16, _19, _20, pre_width, pre_height);
		zephir_check_call_status();
		if (zephir_is_true(_17)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _11);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_21, "imagesx", NULL, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _21 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_22, "imagesy", NULL, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _22 TSRMLS_CC);
		}
	} else {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, width);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, _4, _13, _14);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _6);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_17, "imagesx", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _17 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_21, "imagesy", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _21 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *image = NULL, *rect, *_0, _1, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL, *_14, *_15 = NULL, *_16 = NULL;
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
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, offsetX);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_LONG(_8, offsetY);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_LONG(_9, width);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, height);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, width);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, height);
		ZEPHIR_CALL_FUNCTION(&_13, "imagecopyresampled", NULL, image, _6, _4, _5, _7, _8, _9, _10, _11, _12);
		zephir_check_call_status();
		if (zephir_is_true(_13)) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _14);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_15, "imagesx", NULL, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_width"), _15 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_16, "imagesy", NULL, image);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_height"), _16 TSRMLS_CC);
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
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _14);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "imagesx", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _13 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_15, "imagesy", NULL, image);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _15 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, *image = NULL, *transparent = NULL, *width = NULL, *height = NULL, *_0, _1, _2, _3, _4, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10, *_11, *_12 = NULL, *_13;
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
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (360 - degrees));
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, _5, _6, transparent, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, image, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, image);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 100);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecopymerge", NULL, _8, image, _6, _7, _9, _10, width, height, _11);
	zephir_check_call_status();
	if (zephir_is_true(_12)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _13);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *direction_param = NULL, *image = NULL, *_0, _1, *_2 = NULL, *_4, *_5, *_6, *_7, *_8, *_9, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL;
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
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, x);
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_LONG(_11, 0);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, ((zephir_get_numberval(_8) - x) - 1));
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, 0);
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_LONG(_14, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, image, _7, _10, _11, _12, _13, _14, _9);
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
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, 0);
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_LONG(_11, x);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 0);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, ((zephir_get_numberval(_8) - x) - 1));
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_LONG(_14, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, image, _7, _10, _11, _12, _13, _9, _14);
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
			ZEPHIR_INIT_NVAR(_10);
			ZEPHIR_GET_CONSTANT(_10, "IMG_FLIP_HORIZONTAL");
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, _4, _10);
			zephir_check_call_status();
		} else {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_11);
			ZEPHIR_GET_CONSTANT(_11, "IMG_FLIP_VERTICAL");
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, _5, _11);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *_4 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *amount_param = NULL, *matrix, *_0, _1 = zval_used_for_init, *_2 = NULL, *_5 = NULL, *_6, *_7, *_8 = NULL, *_9, *_10 = NULL, *_11, *_12 = NULL;
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
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (amount - 8));
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, _6, matrix, _5, _7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "imagesx", NULL, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_width"), _10 TSRMLS_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "imagesy", NULL, _11);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_height"), _12 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zephir_fcall_cache_entry *_7 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *reflection = NULL, *line = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5, *_6 = NULL, *_8, *_9, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14, *_15, _16 = zval_used_for_init, *_17, *_18, *_19, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23, *_24 = NULL, *_25 = NULL, *_26 = NULL;
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
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, 0);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_LONG(_13, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, reflection, _8, _6, _11, _12, _13, _9, _10);
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
			ZEPHIR_INIT_NVAR(_6);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (opacity + ((stepping * ((height - offset))))));
			zephir_round(_6, &_1, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_6);
		} else {
			ZEPHIR_INIT_NVAR(_11);
			ZEPHIR_SINIT_NVAR(_16);
			ZVAL_LONG(&_16, (opacity + ((stepping * offset))));
			zephir_round(_11, &_16, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(_11);
		}
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_LONG(_12, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", &_7, _17, _12);
		zephir_check_call_status();
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_LONG(_12, 0);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 0);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, 0);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_LONG(_21, src_y);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, line, _18, _12, _13, _20, _21, _19, _22);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_12);
		ZEPHIR_GET_CONSTANT(_12, "IMG_FILTER_COLORIZE");
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 0);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, 0);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_LONG(_21, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", NULL, line, _12, _13, _20, _21, _22);
		zephir_check_call_status();
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 0);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, dst_y);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_LONG(_21, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, 0);
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_LONG(_24, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, reflection, line, _13, _20, _21, _22, _23, _24);
		zephir_check_call_status();
		offset++;
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _14);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_25, "imagesx", NULL, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _25 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_26, "imagesy", NULL, reflection);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _26 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int offsetX, offsetY, opacity, width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *overlay = NULL, *color = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, _4 = zval_used_for_init, *_5 = NULL, _7, _8, _9, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15, *_16, *_17;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, overlay, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "imagesx", NULL, overlay);
	zephir_check_call_status();
	width = zephir_get_intval(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "imagesy", NULL, overlay);
	zephir_check_call_status();
	height = zephir_get_intval(_3);
	if (opacity < 100) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_DOUBLE(&_4, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5, "abs", &_6, &_4);
		zephir_check_call_status();
		zephir_round(_1, _5, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(_1);
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
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_GET_CONSTANT(_10, "IMG_EFFECT_OVERLAY");
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, overlay, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, 0);
		ZEPHIR_INIT_VAR(_13);
		ZVAL_LONG(_13, width);
		ZEPHIR_INIT_VAR(_14);
		ZVAL_LONG(_14, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, overlay, _11, _12, _13, _14, color);
		zephir_check_call_status();
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, _15, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_LONG(_10, offsetX);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, offsetY);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_LONG(_12, 0);
	ZEPHIR_INIT_NVAR(_13);
	ZVAL_LONG(_13, 0);
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_LONG(_14, width);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_LONG(_17, height);
	ZEPHIR_CALL_FUNCTION(&_5, "imagecopy", NULL, _16, overlay, _10, _11, _12, _13, _14, _17);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zephir_fcall_cache_entry *_19 = NULL;
	zend_bool _10, _11, _12;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int offsetX, offsetY, opacity, r, g, b, size, angle, s0 = 0, s1 = 0, s4 = 0, s5 = 0, width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *space = NULL, *color = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9, *_13 = NULL, *_14 = NULL, *_15, _16 = zval_used_for_init, _17 = zval_used_for_init, _18 = zval_used_for_init, *_20, *_21 = NULL, *_22, *_23;
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
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, size);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, _4, _5, fontfile, text);
		zephir_check_call_status();
		if (zephir_array_isset_long(space, 0)) {
			ZEPHIR_OBS_VAR(_6);
			zephir_array_fetch_long(&_6, space, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 347 TSRMLS_CC);
			s0 = zephir_get_intval(_6);
			ZEPHIR_OBS_VAR(_7);
			zephir_array_fetch_long(&_7, space, 1, PH_NOISY, "phalcon/image/adapter/gd.zep", 348 TSRMLS_CC);
			s1 = zephir_get_intval(_7);
			ZEPHIR_OBS_VAR(_8);
			zephir_array_fetch_long(&_8, space, 4, PH_NOISY, "phalcon/image/adapter/gd.zep", 349 TSRMLS_CC);
			s4 = zephir_get_intval(_8);
			ZEPHIR_OBS_VAR(_9);
			zephir_array_fetch_long(&_9, space, 5, PH_NOISY, "phalcon/image/adapter/gd.zep", 350 TSRMLS_CC);
			s5 = zephir_get_intval(_9);
		}
		_10 = !s0;
		if (!(_10)) {
			_10 = !s1;
		}
		_11 = _10;
		if (!(_11)) {
			_11 = !s4;
		}
		_12 = _11;
		if (!(_12)) {
			_12 = !s5;
		}
		if (_12) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/image/adapter/gd.zep", 354);
			return;
		}
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (s4 - s0));
		ZEPHIR_CALL_FUNCTION(&_13, "abs", &_3, &_1);
		zephir_check_call_status();
		width = (zephir_get_numberval(_13) + 10);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_14, "abs", &_3, &_1);
		zephir_check_call_status();
		height = (zephir_get_numberval(_14) + 10);
		if (offsetX < 0) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_15) - width) + offsetX);
		}
		if (offsetY < 0) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_15) - height) + offsetY);
		}
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, r);
		ZEPHIR_SINIT_VAR(_16);
		ZVAL_LONG(&_16, g);
		ZEPHIR_SINIT_VAR(_17);
		ZVAL_LONG(&_17, b);
		ZEPHIR_SINIT_VAR(_18);
		ZVAL_LONG(&_18, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_19, _15, &_1, &_16, &_17, &_18);
		zephir_check_call_status();
		angle = 0;
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, size);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, angle);
		ZEPHIR_INIT_VAR(_21);
		ZVAL_LONG(_21, offsetX);
		ZEPHIR_INIT_VAR(_22);
		ZVAL_LONG(_22, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, _20, _4, _5, _21, _22, color, fontfile, text);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, size);
		ZEPHIR_CALL_FUNCTION(&_13, "imagefontwidth", NULL, _4);
		zephir_check_call_status();
		width = (zephir_get_intval(_13) * zephir_fast_strlen_ev(text));
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, size);
		ZEPHIR_CALL_FUNCTION(&_14, "imagefontheight", NULL, _4);
		zephir_check_call_status();
		height = zephir_get_intval(_14);
		if (offsetX < 0) {
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_20) - width) + offsetX);
		}
		if (offsetY < 0) {
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_15) - height) + offsetY);
		}
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, r);
		ZEPHIR_SINIT_NVAR(_16);
		ZVAL_LONG(&_16, g);
		ZEPHIR_SINIT_NVAR(_17);
		ZVAL_LONG(&_17, b);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_19, _15, &_1, &_16, &_17, &_18);
		zephir_check_call_status();
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, size);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, offsetX);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_LONG(_21, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, _23, _4, _5, _21, text, color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	zend_bool _13;
	zephir_fcall_cache_entry *_10 = NULL, *_23 = NULL, *_24 = NULL;
	int mask_width, mask_height, x, y, alpha, ZEPHIR_LAST_CALL_STATUS;
	zval *mask, *maskImage = NULL, *newimage = NULL, *tempImage = NULL, *color = NULL, *index = NULL, *r = NULL, *g = NULL, *b = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5, _6 = zval_used_for_init, _7 = zval_used_for_init, _8 = zval_used_for_init, _9, *_11 = NULL, *_12, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_25;

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
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, maskImage, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, _4, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, newimage, _3);
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
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, newimage, _3, _11, color);
	zephir_check_call_status();
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_13 = !ZEPHIR_IS_LONG(_12, mask_width);
	if (!(_13)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		_13 = !ZEPHIR_IS_LONG(_14, mask_height);
	}
	if (_13) {
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, _15, _16);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, 0);
		ZEPHIR_INIT_VAR(_20);
		ZVAL_LONG(_20, 0);
		ZEPHIR_INIT_VAR(_21);
		ZVAL_LONG(_21, mask_width);
		ZEPHIR_INIT_VAR(_22);
		ZVAL_LONG(_22, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, tempImage, maskImage, _3, _11, _19, _20, _17, _18, _21, _22);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(maskImage, tempImage);
	}
	x = 0;
	while (1) {
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_15, x))) {
			break;
		}
		y = 0;
		while (1) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_GT_LONG(_16, y))) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, x);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, maskImage, &_6, &_7);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, maskImage, index);
			zephir_check_call_status();
			if (zephir_array_isset_string(color, SS("red"))) {
				zephir_array_fetch_string(&_25, color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 427 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_25, 2 TSRMLS_CC));
				alpha = (127 - zephir_get_intval(&_6));
			}
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, x);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, _17, &_7, &_8);
			zephir_check_call_status();
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, _18, index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(r);
			zephir_array_fetch_string(&r, color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 432 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(g);
			zephir_array_fetch_string(&g, color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 432 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(b);
			zephir_array_fetch_string(&b, color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 432 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", &_10, newimage, r, g, b, &_7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, x);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_LONG(_11, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", NULL, newimage, _3, _11, color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _15);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, maskImage);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background = NULL, *color = NULL, *_0, *_1, _2, _3, _4, _5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL, *_14;
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
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, 0);
	ZEPHIR_CALL_FUNCTION(&_13, "imagecopy", NULL, background, _6, _9, _10, _11, _12, _7, _8);
	zephir_check_call_status();
	if (zephir_is_true(_13)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _14);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zval *radius_param = NULL, *_0, *_1 = NULL;
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
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "IMG_FILTER_GAUSSIAN_BLUR");
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", NULL, _0, _1);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zephir_fcall_cache_entry *_5 = NULL;
	zval *amount_param = NULL, *color = NULL, *_0, *_1, *_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
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
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, x1);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, y1);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, x2);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_LONG(_10, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, _6, _7, _8, _9, _10, color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	zend_bool _9;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_6 = NULL, *_8 = NULL, *_14 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext = NULL, _0 = zval_used_for_init, *_2 = NULL, *_4, *_5 = NULL, *_7, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", &_1, file, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcasecmp", &_3, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_2, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5, "image_type_to_mime_type", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _5 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_8, ext, &_0);
	zephir_check_call_status();
	_9 = ZEPHIR_IS_LONG(_5, 0);
	if (!(_9)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_10, "strcmp", &_8, ext, &_0);
		zephir_check_call_status();
		_9 = ZEPHIR_IS_LONG(_10, 0);
	}
	if (_9) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 2);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _7, file, _12);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_8, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_8, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 15);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "strcmp", &_8, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_5, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 16);
		zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "image_type_to_mime_type", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, _7, file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(_12);
	object_init_ex(_12, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SVS(_13, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", &_14, _13);
	zephir_check_call_status();
	zephir_throw_exception_debug(_12, "phalcon/image/adapter/gd.zep", 533 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _8;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_16 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, _1 = zval_used_for_init, *_2 = NULL, *_4, *_6 = NULL, *_9 = NULL, *_10 = NULL, *_11, *_12 = NULL, *_13 = NULL, *_14 = NULL;
	zval *ext = NULL, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcasecmp", &_3, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_2, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "jpg", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", &_7, ext, &_1);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_LONG(_6, 0);
	if (!(_8)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "jpeg", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "strcmp", &_7, ext, &_1);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_LONG(_9, 0);
	}
	if (_8) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_NULL(_10);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _4, _10, _11);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "png", 0);
	ZEPHIR_CALL_FUNCTION(&_12, "strcmp", &_7, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_12, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "wbmp", 0);
	ZEPHIR_CALL_FUNCTION(&_13, "strcmp", &_7, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_13, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, _4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "xbm", 0);
	ZEPHIR_CALL_FUNCTION(&_14, "strcmp", &_7, ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_14, 0)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_NULL(_10);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, _4, _10);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_10);
	object_init_ex(_10, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_CONCAT_SVS(_15, "Installed GD does not support '", ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_16, _15);
	zephir_check_call_status();
	zephir_throw_exception_debug(_10, "phalcon/image/adapter/gd.zep", 560 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, *image = NULL, *_0 = NULL, *_1;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, image, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, image, _0);
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

