
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Phalcon\Http\Link\Serializer\Header
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Serializer_Header)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link\\Serializer, Header, phalcon, html_link_serializer_header, phalcon_html_link_serializer_header_method_entry, 0);

	zend_class_implements(phalcon_html_link_serializer_header_ce, 1, phalcon_html_link_serializer_serializerinterface_ce);
	return SUCCESS;
}

/**
 * Serializes all the passed links to a HTTP link header
 */
PHP_METHOD(Phalcon_Html_Link_Serializer_Header, serialize)
{
	zend_string *_6$$3, *_31$$17;
	zend_ulong _5$$3, _30$$17;
	zend_bool _24, _14$$3, _10$$6, _18$$12, _39$$17, _35$$20, _43$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, attributes, key, link, rels, result, subValue, value, *_0, _23, _1$$3, _2$$3, _3$$3, *_4$$3, _13$$3, _21$$3, _22$$3, *_7$$6, _9$$6, _8$$7, _11$$8, _12$$9, *_15$$12, _17$$12, _16$$13, _19$$14, _20$$15, _25$$17, _26$$17, _27$$17, _28$$17, *_29$$17, _38$$17, _46$$17, _47$$17, *_32$$20, _34$$20, _33$$21, _36$$22, _37$$23, *_40$$26, _42$$26, _41$$27, _44$$28, _45$$29;
	zval links, elements, parts;

	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&rels);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_44$$28);
	ZVAL_UNDEF(&_45$$29);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(links, links_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &links_param);
	zephir_get_arrval(&links, links_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_NULL(&result);
	ZEPHIR_INIT_VAR(&elements);
	array_init(&elements);
	zephir_is_iterable(&links, 0, "phalcon/Html/Link/Serializer/Header.zep", 70);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&links), _0)
		{
			ZEPHIR_INIT_NVAR(&link);
			ZVAL_COPY(&link, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, &link, "istemplated", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&parts);
			zephir_create_array(&parts, 2, 0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "");
			zephir_array_fast_append(&parts, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_fast_join_str(&_2$$3, SL(" "), &rels);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVS(&_3$$3, "rel=\"", &_2$$3, "\"");
			zephir_array_fast_append(&parts, &_3$$3);
			zephir_is_iterable(&attributes, 0, "phalcon/Html/Link/Serializer/Header.zep", 64);
			if (Z_TYPE_P(&attributes) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _5$$3, _6$$3, _4$$3)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_6$$3 != NULL) { 
						ZVAL_STR_COPY(&key, _6$$3);
					} else {
						ZVAL_LONG(&key, _5$$3);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _4$$3);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _7$$6)
							{
								ZEPHIR_INIT_NVAR(&subValue);
								ZVAL_COPY(&subValue, _7$$6);
								ZEPHIR_INIT_NVAR(&_8$$7);
								ZEPHIR_CONCAT_VSVS(&_8$$7, &key, "=\"", &subValue, "\"");
								zephir_array_append(&parts, &_8$$7, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
							zephir_check_call_status();
							_10$$6 = 1;
							while (1) {
								if (_10$$6) {
									_10$$6 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_9$$6, &value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_9$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_11$$8);
									ZEPHIR_CONCAT_VSVS(&_11$$8, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_11$$8, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
							}
						}
						ZEPHIR_INIT_NVAR(&subValue);
						continue;
					}
					if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
						ZEPHIR_INIT_NVAR(&_12$$9);
						ZEPHIR_CONCAT_VSVS(&_12$$9, &key, "=\"", &value, "\"");
						zephir_array_append(&parts, &_12$$9, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
						continue;
					}
					if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
						zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
						continue;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$3 = 1;
				while (1) {
					if (_14$$3) {
						_14$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$3, &attributes, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _15$$12)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _15$$12);
									ZEPHIR_INIT_NVAR(&_16$$13);
									ZEPHIR_CONCAT_VSVS(&_16$$13, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_16$$13, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								_18$$12 = 1;
								while (1) {
									if (_18$$12) {
										_18$$12 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_17$$12, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_17$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_19$$14);
										ZEPHIR_CONCAT_VSVS(&_19$$14, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_19$$14, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							ZEPHIR_INIT_NVAR(&_20$$15);
							ZEPHIR_CONCAT_VSVS(&_20$$15, &key, "=\"", &value, "\"");
							zephir_array_append(&parts, &_20$$15, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
							continue;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CALL_METHOD(&_21$$3, &link, "gethref", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_22$$3);
			zephir_fast_join_str(&_22$$3, SL("; "), &parts);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVSV(&_3$$3, "<", &_21$$3, ">", &_22$$3);
			zephir_array_append(&elements, &_3$$3, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$17, &link, "istemplated", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_25$$17)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_26$$17);
				zephir_create_array(&_26$$17, 2, 0);
				ZEPHIR_INIT_NVAR(&_27$$17);
				ZVAL_STRING(&_27$$17, "");
				zephir_array_fast_append(&_26$$17, &_27$$17);
				ZEPHIR_INIT_NVAR(&_27$$17);
				zephir_fast_join_str(&_27$$17, SL(" "), &rels);
				ZEPHIR_INIT_NVAR(&_28$$17);
				ZEPHIR_CONCAT_SVS(&_28$$17, "rel=\"", &_27$$17, "\"");
				zephir_array_fast_append(&_26$$17, &_28$$17);
				ZEPHIR_CPY_WRT(&parts, &_26$$17);
				zephir_is_iterable(&attributes, 0, "phalcon/Html/Link/Serializer/Header.zep", 64);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _30$$17, _31$$17, _29$$17)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_31$$17 != NULL) { 
							ZVAL_STR_COPY(&key, _31$$17);
						} else {
							ZVAL_LONG(&key, _30$$17);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _29$$17);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _32$$20)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _32$$20);
									ZEPHIR_INIT_NVAR(&_33$$21);
									ZEPHIR_CONCAT_VSVS(&_33$$21, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_33$$21, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								_35$$20 = 1;
								while (1) {
									if (_35$$20) {
										_35$$20 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_34$$20, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_34$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_36$$22);
										ZEPHIR_CONCAT_VSVS(&_36$$22, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_36$$22, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							ZEPHIR_INIT_NVAR(&_37$$23);
							ZEPHIR_CONCAT_VSVS(&_37$$23, &key, "=\"", &value, "\"");
							zephir_array_append(&parts, &_37$$23, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
							continue;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
					zephir_check_call_status();
					_39$$17 = 1;
					while (1) {
						if (_39$$17) {
							_39$$17 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_38$$17, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_38$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _40$$26)
									{
										ZEPHIR_INIT_NVAR(&subValue);
										ZVAL_COPY(&subValue, _40$$26);
										ZEPHIR_INIT_NVAR(&_41$$27);
										ZEPHIR_CONCAT_VSVS(&_41$$27, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_41$$27, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
									zephir_check_call_status();
									_43$$26 = 1;
									while (1) {
										if (_43$$26) {
											_43$$26 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_42$$26, &value, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_42$$26)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_44$$28);
											ZEPHIR_CONCAT_VSVS(&_44$$28, &key, "=\"", &subValue, "\"");
											zephir_array_append(&parts, &_44$$28, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									}
								}
								ZEPHIR_INIT_NVAR(&subValue);
								continue;
							}
							if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
								ZEPHIR_INIT_NVAR(&_45$$29);
								ZEPHIR_CONCAT_VSVS(&_45$$29, &key, "=\"", &value, "\"");
								zephir_array_append(&parts, &_45$$29, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								continue;
							}
							if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
								zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
								continue;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CALL_METHOD(&_46$$17, &link, "gethref", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_47$$17);
				zephir_fast_join_str(&_47$$17, SL("; "), &parts);
				ZEPHIR_INIT_NVAR(&_28$$17);
				ZEPHIR_CONCAT_SVSV(&_28$$17, "<", &_46$$17, ">", &_47$$17);
				zephir_array_append(&elements, &_28$$17, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	if (zephir_fast_count_int(&elements) > 0) {
		ZEPHIR_INIT_NVAR(&result);
		zephir_fast_join_str(&result, SL(","), &elements);
	}
	RETURN_CCTOR(&result);
}

