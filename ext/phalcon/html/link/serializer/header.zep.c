
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
	zend_string *_6$$3, *_27$$17;
	zend_ulong _5$$3, _26$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *links_param = NULL, attributes, key, link, rels, result, subValue, value, *_0, _20, _1$$3, _2$$3, _3$$3, *_4$$3, _12$$3, _18$$3, _19$$3, *_7$$6, _9$$6, _8$$7, _10$$8, _11$$9, *_13$$12, _15$$12, _14$$13, _16$$14, _17$$15, _21$$17, _22$$17, _23$$17, _24$$17, *_25$$17, _33$$17, _39$$17, _40$$17, *_28$$20, _30$$20, _29$$21, _31$$22, _32$$23, *_34$$26, _36$$26, _35$$27, _37$$28, _38$$29;
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
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$29);
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
							while (1) {
								ZEPHIR_CALL_METHOD(&_9$$6, &value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_9$$6)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_10$$8);
									ZEPHIR_CONCAT_VSVS(&_10$$8, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_10$$8, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&subValue);
						continue;
					}
					if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZEPHIR_CONCAT_VSVS(&_11$$9, &key, "=\"", &value, "\"");
						zephir_array_append(&parts, &_11$$9, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
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
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$3, &attributes, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _13$$12)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _13$$12);
									ZEPHIR_INIT_NVAR(&_14$$13);
									ZEPHIR_CONCAT_VSVS(&_14$$13, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_14$$13, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_15$$12, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_15$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_16$$14);
										ZEPHIR_CONCAT_VSVS(&_16$$14, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_16$$14, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							ZEPHIR_INIT_NVAR(&_17$$15);
							ZEPHIR_CONCAT_VSVS(&_17$$15, &key, "=\"", &value, "\"");
							zephir_array_append(&parts, &_17$$15, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
							continue;
						}
						if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
							zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
							continue;
						}
					ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
			ZEPHIR_CALL_METHOD(&_18$$3, &link, "gethref", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_19$$3);
			zephir_fast_join_str(&_19$$3, SL("; "), &parts);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SVSV(&_3$$3, "<", &_18$$3, ">", &_19$$3);
			zephir_array_append(&elements, &_3$$3, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_20, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&link, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_21$$17, &link, "istemplated", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_21$$17)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&attributes, &link, "getattributes", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&rels, &link, "getrels", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$17);
				zephir_create_array(&_22$$17, 2, 0);
				ZEPHIR_INIT_NVAR(&_23$$17);
				ZVAL_STRING(&_23$$17, "");
				zephir_array_fast_append(&_22$$17, &_23$$17);
				ZEPHIR_INIT_NVAR(&_23$$17);
				zephir_fast_join_str(&_23$$17, SL(" "), &rels);
				ZEPHIR_INIT_NVAR(&_24$$17);
				ZEPHIR_CONCAT_SVS(&_24$$17, "rel=\"", &_23$$17, "\"");
				zephir_array_fast_append(&_22$$17, &_24$$17);
				ZEPHIR_CPY_WRT(&parts, &_22$$17);
				zephir_is_iterable(&attributes, 0, "phalcon/Html/Link/Serializer/Header.zep", 64);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _26$$17, _27$$17, _25$$17)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_27$$17 != NULL) { 
							ZVAL_STR_COPY(&key, _27$$17);
						} else {
							ZVAL_LONG(&key, _26$$17);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _25$$17);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _28$$20)
								{
									ZEPHIR_INIT_NVAR(&subValue);
									ZVAL_COPY(&subValue, _28$$20);
									ZEPHIR_INIT_NVAR(&_29$$21);
									ZEPHIR_CONCAT_VSVS(&_29$$21, &key, "=\"", &subValue, "\"");
									zephir_array_append(&parts, &_29$$21, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_30$$20, &value, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_30$$20)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_31$$22);
										ZEPHIR_CONCAT_VSVS(&_31$$22, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_31$$22, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&subValue);
							continue;
						}
						if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
							ZEPHIR_INIT_NVAR(&_32$$23);
							ZEPHIR_CONCAT_VSVS(&_32$$23, &key, "=\"", &value, "\"");
							zephir_array_append(&parts, &_32$$23, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
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
					while (1) {
						ZEPHIR_CALL_METHOD(&_33$$17, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_33$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								zephir_is_iterable(&value, 0, "phalcon/Html/Link/Serializer/Header.zep", 50);
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&value), _34$$26)
									{
										ZEPHIR_INIT_NVAR(&subValue);
										ZVAL_COPY(&subValue, _34$$26);
										ZEPHIR_INIT_NVAR(&_35$$27);
										ZEPHIR_CONCAT_VSVS(&_35$$27, &key, "=\"", &subValue, "\"");
										zephir_array_append(&parts, &_35$$27, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_36$$26, &value, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_36$$26)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&subValue, &value, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_37$$28);
											ZEPHIR_CONCAT_VSVS(&_37$$28, &key, "=\"", &subValue, "\"");
											zephir_array_append(&parts, &_37$$28, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 48);
										ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&subValue);
								continue;
							}
							if (((Z_TYPE_P(&value) == IS_TRUE || Z_TYPE_P(&value) == IS_FALSE) != 1)) {
								ZEPHIR_INIT_NVAR(&_38$$29);
								ZEPHIR_CONCAT_VSVS(&_38$$29, &key, "=\"", &value, "\"");
								zephir_array_append(&parts, &_38$$29, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 54);
								continue;
							}
							if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
								zephir_array_append(&parts, &key, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 59);
								continue;
							}
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				ZEPHIR_CALL_METHOD(&_39$$17, &link, "gethref", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$17);
				zephir_fast_join_str(&_40$$17, SL("; "), &parts);
				ZEPHIR_INIT_NVAR(&_24$$17);
				ZEPHIR_CONCAT_SVSV(&_24$$17, "<", &_39$$17, ">", &_40$$17);
				zephir_array_append(&elements, &_24$$17, PH_SEPARATE, "phalcon/Html/Link/Serializer/Header.zep", 67);
			ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&link);
	if (zephir_fast_count_int(&elements) > 0) {
		ZEPHIR_INIT_NVAR(&result);
		zephir_fast_join_str(&result, SL(","), &elements);
	}
	RETURN_CCTOR(&result);
}

