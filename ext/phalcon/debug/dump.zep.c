
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Debug\Dump
 *
 * Dumps information about a variable(s)
 *
 * <code>
 * $foo = 123;
 *
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * </code>
 *
 * <code>
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Debug, Dump, phalcon, debug_dump, phalcon_debug_dump_method_entry, 0);

	/**
	 * @var bool 
	 */
	zend_declare_property_bool(phalcon_debug_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_debug_dump_ce->create_object = zephir_init_properties_Phalcon_Debug_Dump;
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Debug_Dump, getDetailed) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "detailed");

}

/**
 */
PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed_param = NULL, __$true, __$false;
	zend_bool detailed;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &detailed_param);

	detailed = zephir_get_boolval(detailed_param);


	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param bool detailed debug object's private and protected properties
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detailed;
	zval *styles_param = NULL, *detailed_param = NULL, __$true, __$false;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &styles_param, &detailed_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&styles, styles_param);
	}
	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of variables() method
 *
 * @param mixed variable
 * @param ...
 */
PHP_METHOD(Phalcon_Debug_Dump, all) {

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "variables");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set styles for vars type
 */
PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles_param = NULL, defaultStyles, _0;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&styles, styles_param);
	}


	ZEPHIR_INIT_VAR(&defaultStyles);
	zephir_create_array(&defaultStyles, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&defaultStyles, SL("pre"), SL("background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333"));
	add_assoc_stringl_ex(&defaultStyles, SL("arr"), SL("color:red"));
	add_assoc_stringl_ex(&defaultStyles, SL("bool"), SL("color:green"));
	add_assoc_stringl_ex(&defaultStyles, SL("float"), SL("color:fuchsia"));
	add_assoc_stringl_ex(&defaultStyles, SL("int"), SL("color:blue"));
	add_assoc_stringl_ex(&defaultStyles, SL("null"), SL("color:black"));
	add_assoc_stringl_ex(&defaultStyles, SL("num"), SL("color:navy"));
	add_assoc_stringl_ex(&defaultStyles, SL("obj"), SL("color:purple"));
	add_assoc_stringl_ex(&defaultStyles, SL("other"), SL("color:maroon"));
	add_assoc_stringl_ex(&defaultStyles, SL("res"), SL("color:lime"));
	add_assoc_stringl_ex(&defaultStyles, SL("str"), SL("color:teal"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &defaultStyles, &styles TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("styles"), &_0);
	RETURN_MM_MEMBER(getThis(), "styles");

}

/**
 * Returns an JSON string of information about a single variable.
 *
 * <code>
 * $foo = [
 *     "key" => "value",
 * ];
 *
 * echo (new \Phalcon\Debug\Dump())->toJson($foo);
 *
 * $foo = new stdClass();
 * $foo->bar = "buz";
 *
 * echo (new \Phalcon\Debug\Dump())->toJson($foo);
 * </code>
 */
PHP_METHOD(Phalcon_Debug_Dump, toJson) {

	zval *variable, variable_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &variable);



	ZVAL_LONG(&_0, ((128 | 64) | 256));
	zephir_json_encode(return_value, variable, zephir_get_intval(&_0) );
	return;

}

/**
 * Returns an HTML string of information about a single variable.
 *
 * <code>
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * </code>
 */
PHP_METHOD(Phalcon_Debug_Dump, variable) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<pre style=':style'>:output</pre>");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 48, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 * <code>
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * </code>
 *
 * @param mixed variable
 * @param ...
 */
PHP_METHOD(Phalcon_Debug_Dump, variables) {

	zend_string *_4;
	zend_ulong _3;
	zval key, value, output, _0, *_1, _2, _5$$3, _6$$3, _8$$4, _9$$4;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "phalcon/debug/dump.zep", 169);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_LNVAR(_6$$3);
			ZEPHIR_CONCAT_SV(&_6$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "one", &_7, 0, &value, &_6$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_5$$3 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_9$$4);
				ZEPHIR_CONCAT_SV(&_9$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "one", &_7, 0, &value, &_9$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_8$$4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&output);

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, style, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(&style);
	} else {
		RETURN_MM_STRING("color:gray");
	}

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_class_entry *_78$$18, *_96$$19;
	zend_bool _15$$5, _16$$5, _17$$5, _29$$8, _30$$8, _31$$8, _46$$11;
	zend_string *_7$$4, *_54$$14;
	zend_ulong _6$$4, _53$$14;
	zval _172, _1$$4, _11$$5, _25$$8, _38$$11, _111$$11, _42$$12, _57$$15, _65$$16, _84$$18, _101$$19, _122$$23, _128$$24, _135$$26, _141$$27, _150$$28, _154$$29, _157$$30, _160$$31, _165$$32, _169$$33;
	zephir_fcall_cache_entry *_10 = NULL, *_21 = NULL, *_75 = NULL, *_76 = NULL, *_79 = NULL, *_81 = NULL, *_90 = NULL, *_93 = NULL, *_94 = NULL, *_98 = NULL, *_107 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _153, _173, _174, _2$$4, _3$$4, *_4$$4, _5$$4, _36$$4, _37$$4, _8$$5, _9$$5, _12$$5, _13$$5, _14$$5, _18$$7, _19$$7, _20$$7, _22$$7, _23$$8, _24$$8, _26$$8, _27$$8, _28$$8, _32$$10, _33$$10, _34$$10, _35$$10, _39$$11, _40$$11, _41$$11, _45$$11, _109$$11, _110$$11, _112$$11, _113$$11, _148$$11, _149$$11, _43$$12, _44$$12, _47$$13, _48$$13, _49$$13, _50$$14, *_51$$14, _52$$14, _55$$15, _56$$15, _58$$15, _59$$15, _60$$15, _61$$15, _62$$15, _63$$16, _64$$16, _66$$16, _67$$16, _68$$16, _69$$16, _70$$16, reflect$$17, props$$17, property$$17, _71$$17, *_72$$17, _73$$17, _74$$18, _77$$18, _80$$18, _82$$18, _83$$18, _85$$18, _86$$18, _87$$18, _88$$18, _89$$18, _91$$18, _92$$19, _95$$19, _97$$19, _99$$19, _100$$19, _102$$19, _103$$19, _104$$19, _105$$19, _106$$19, _108$$19, _114$$20, _115$$20, _116$$20, *_117$$21, _118$$21, _145$$21, _146$$21, _147$$21, _119$$22, _120$$23, _121$$23, _123$$23, _124$$23, _125$$23, _126$$24, _127$$24, _129$$24, _130$$24, _131$$24, _132$$25, _133$$26, _134$$26, _136$$26, _137$$26, _138$$26, _139$$27, _140$$27, _142$$27, _143$$27, _144$$27, _151$$28, _152$$28, _155$$29, _156$$29, _158$$30, _159$$30, _161$$31, _162$$31, _163$$31, _164$$31, _166$$32, _167$$32, _168$$32, _170$$33, _171$$33;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_153);
	ZVAL_UNDEF(&_173);
	ZVAL_UNDEF(&_174);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_36$$4);
	ZVAL_UNDEF(&_37$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_109$$11);
	ZVAL_UNDEF(&_110$$11);
	ZVAL_UNDEF(&_112$$11);
	ZVAL_UNDEF(&_113$$11);
	ZVAL_UNDEF(&_148$$11);
	ZVAL_UNDEF(&_149$$11);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_47$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_52$$14);
	ZVAL_UNDEF(&_55$$15);
	ZVAL_UNDEF(&_56$$15);
	ZVAL_UNDEF(&_58$$15);
	ZVAL_UNDEF(&_59$$15);
	ZVAL_UNDEF(&_60$$15);
	ZVAL_UNDEF(&_61$$15);
	ZVAL_UNDEF(&_62$$15);
	ZVAL_UNDEF(&_63$$16);
	ZVAL_UNDEF(&_64$$16);
	ZVAL_UNDEF(&_66$$16);
	ZVAL_UNDEF(&_67$$16);
	ZVAL_UNDEF(&_68$$16);
	ZVAL_UNDEF(&_69$$16);
	ZVAL_UNDEF(&_70$$16);
	ZVAL_UNDEF(&reflect$$17);
	ZVAL_UNDEF(&props$$17);
	ZVAL_UNDEF(&property$$17);
	ZVAL_UNDEF(&_71$$17);
	ZVAL_UNDEF(&_73$$17);
	ZVAL_UNDEF(&_74$$18);
	ZVAL_UNDEF(&_77$$18);
	ZVAL_UNDEF(&_80$$18);
	ZVAL_UNDEF(&_82$$18);
	ZVAL_UNDEF(&_83$$18);
	ZVAL_UNDEF(&_85$$18);
	ZVAL_UNDEF(&_86$$18);
	ZVAL_UNDEF(&_87$$18);
	ZVAL_UNDEF(&_88$$18);
	ZVAL_UNDEF(&_89$$18);
	ZVAL_UNDEF(&_91$$18);
	ZVAL_UNDEF(&_92$$19);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_97$$19);
	ZVAL_UNDEF(&_99$$19);
	ZVAL_UNDEF(&_100$$19);
	ZVAL_UNDEF(&_102$$19);
	ZVAL_UNDEF(&_103$$19);
	ZVAL_UNDEF(&_104$$19);
	ZVAL_UNDEF(&_105$$19);
	ZVAL_UNDEF(&_106$$19);
	ZVAL_UNDEF(&_108$$19);
	ZVAL_UNDEF(&_114$$20);
	ZVAL_UNDEF(&_115$$20);
	ZVAL_UNDEF(&_116$$20);
	ZVAL_UNDEF(&_118$$21);
	ZVAL_UNDEF(&_145$$21);
	ZVAL_UNDEF(&_146$$21);
	ZVAL_UNDEF(&_147$$21);
	ZVAL_UNDEF(&_119$$22);
	ZVAL_UNDEF(&_120$$23);
	ZVAL_UNDEF(&_121$$23);
	ZVAL_UNDEF(&_123$$23);
	ZVAL_UNDEF(&_124$$23);
	ZVAL_UNDEF(&_125$$23);
	ZVAL_UNDEF(&_126$$24);
	ZVAL_UNDEF(&_127$$24);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_130$$24);
	ZVAL_UNDEF(&_131$$24);
	ZVAL_UNDEF(&_132$$25);
	ZVAL_UNDEF(&_133$$26);
	ZVAL_UNDEF(&_134$$26);
	ZVAL_UNDEF(&_136$$26);
	ZVAL_UNDEF(&_137$$26);
	ZVAL_UNDEF(&_138$$26);
	ZVAL_UNDEF(&_139$$27);
	ZVAL_UNDEF(&_140$$27);
	ZVAL_UNDEF(&_142$$27);
	ZVAL_UNDEF(&_143$$27);
	ZVAL_UNDEF(&_144$$27);
	ZVAL_UNDEF(&_151$$28);
	ZVAL_UNDEF(&_152$$28);
	ZVAL_UNDEF(&_155$$29);
	ZVAL_UNDEF(&_156$$29);
	ZVAL_UNDEF(&_158$$30);
	ZVAL_UNDEF(&_159$$30);
	ZVAL_UNDEF(&_161$$31);
	ZVAL_UNDEF(&_162$$31);
	ZVAL_UNDEF(&_163$$31);
	ZVAL_UNDEF(&_164$$31);
	ZVAL_UNDEF(&_166$$32);
	ZVAL_UNDEF(&_167$$32);
	ZVAL_UNDEF(&_168$$32);
	ZVAL_UNDEF(&_170$$33);
	ZVAL_UNDEF(&_171$$33);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_172);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_111$$11);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_57$$15);
	ZVAL_UNDEF(&_65$$16);
	ZVAL_UNDEF(&_84$$18);
	ZVAL_UNDEF(&_101$$19);
	ZVAL_UNDEF(&_122$$23);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_135$$26);
	ZVAL_UNDEF(&_141$$27);
	ZVAL_UNDEF(&_150$$28);
	ZVAL_UNDEF(&_154$$29);
	ZVAL_UNDEF(&_157$$30);
	ZVAL_UNDEF(&_160$$31);
	ZVAL_UNDEF(&_165$$32);
	ZVAL_UNDEF(&_169$$33);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name_param, &tab_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!tab_param) {
		tab = 1;
	} else {
		tab = zephir_get_intval(tab_param);
	}


	ZEPHIR_INIT_VAR(&space);
	ZVAL_STRING(&space, "  ");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VS(&_0$$3, &name, " ");
		ZEPHIR_CPY_WRT(&output, &_0$$3);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "arr");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", NULL, 0, &_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_1$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 48, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "phalcon/debug/dump.zep", 217);
		if (Z_TYPE_P(variable) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _6$$4, _7$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$4);
				} else {
					ZVAL_LONG(&key, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _4$$4);
				ZVAL_LONG(&_8$$5, tab);
				ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 127, &space, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_create_array(&_11$$5, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "arr");
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getstyle", NULL, 0, &_13$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL(":style"), &_12$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "[<span style=':style'>:key</span>] => ");
				ZEPHIR_CALL_FUNCTION(&_12$$5, "strtr", NULL, 48, &_13$$5, &_11$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14$$5);
				ZEPHIR_CONCAT_VV(&_14$$5, &_9$$5, &_12$$5);
				zephir_concat_self(&output, &_14$$5 TSRMLS_CC);
				_15$$5 = tab == 1;
				if (_15$$5) {
					_15$$5 = !ZEPHIR_IS_STRING(&name, "");
				}
				_16$$5 = _15$$5;
				if (_16$$5) {
					_16$$5 = !(Z_TYPE_P(&key) == IS_LONG);
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					_17$$5 = ZEPHIR_IS_EQUAL(&name, &key);
				}
				if (_17$$5) {
					continue;
				} else {
					ZEPHIR_INIT_NVAR(&_19$$7);
					ZVAL_STRING(&_19$$7, "");
					ZVAL_LONG(&_20$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_18$$7, this_ptr, "output", &_21, 166, &value, &_19$$7, &_20$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_22$$7);
					ZEPHIR_CONCAT_VS(&_22$$7, &_18$$7, "\n");
					zephir_concat_self(&output, &_22$$7 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_23$$8, tab);
					ZEPHIR_CALL_FUNCTION(&_24$$8, "str_repeat", &_10, 127, &space, &_23$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$8);
					zephir_create_array(&_25$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_27$$8);
					ZVAL_STRING(&_27$$8, "arr");
					ZEPHIR_CALL_METHOD(&_26$$8, this_ptr, "getstyle", NULL, 0, &_27$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_25$$8, SL(":style"), &_26$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$8, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_27$$8);
					ZVAL_STRING(&_27$$8, "[<span style=':style'>:key</span>] => ");
					ZEPHIR_CALL_FUNCTION(&_26$$8, "strtr", NULL, 48, &_27$$8, &_25$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$8);
					ZEPHIR_CONCAT_VV(&_28$$8, &_24$$8, &_26$$8);
					zephir_concat_self(&output, &_28$$8 TSRMLS_CC);
					_29$$8 = tab == 1;
					if (_29$$8) {
						_29$$8 = !ZEPHIR_IS_STRING(&name, "");
					}
					_30$$8 = _29$$8;
					if (_30$$8) {
						_30$$8 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_31$$8 = _30$$8;
					if (_31$$8) {
						_31$$8 = ZEPHIR_IS_EQUAL(&name, &key);
					}
					if (_31$$8) {
						continue;
					} else {
						ZEPHIR_INIT_NVAR(&_33$$10);
						ZVAL_STRING(&_33$$10, "");
						ZVAL_LONG(&_34$$10, (tab + 1));
						ZEPHIR_CALL_METHOD(&_32$$10, this_ptr, "output", &_21, 166, &value, &_33$$10, &_34$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_35$$10);
						ZEPHIR_CONCAT_VS(&_35$$10, &_32$$10, "\n");
						zephir_concat_self(&output, &_35$$10 TSRMLS_CC);
					}
				ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_36$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_37$$4, "str_repeat", &_10, 127, &space, &_36$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_37$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_38$$11);
		zephir_create_array(&_38$$11, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_40$$11);
		ZVAL_STRING(&_40$$11, "obj");
		ZEPHIR_CALL_METHOD(&_39$$11, this_ptr, "getstyle", NULL, 0, &_40$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_38$$11, SL(":style"), &_39$$11, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_40$$11);
		zephir_get_class(&_40$$11, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_38$$11, SL(":class"), &_40$$11, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_40$$11);
		ZVAL_STRING(&_40$$11, "<b style=':style'>Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_39$$11, "strtr", NULL, 48, &_40$$11, &_38$$11);
		zephir_check_call_status();
		zephir_concat_self(&output, &_39$$11 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_41$$11, "get_parent_class", NULL, 167, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_41$$11)) {
			ZEPHIR_INIT_VAR(&_42$$12);
			zephir_create_array(&_42$$12, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_44$$12);
			ZVAL_STRING(&_44$$12, "obj");
			ZEPHIR_CALL_METHOD(&_43$$12, this_ptr, "getstyle", NULL, 0, &_44$$12);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$12, SL(":style"), &_43$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_43$$12, "get_parent_class", NULL, 167, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$12, SL(":parent"), &_43$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_44$$12);
			ZVAL_STRING(&_44$$12, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_43$$12, "strtr", NULL, 48, &_44$$12, &_42$$12);
			zephir_check_call_status();
			zephir_concat_self(&output, &_43$$12 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_45$$11, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		_46$$11 = !zephir_is_true(&_45$$11);
		if (!(_46$$11)) {
			_46$$11 = zephir_instance_of_ev(variable, zend_standard_class_def TSRMLS_CC);
		}
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZVAL_LONG(&_47$$13, tab);
			ZEPHIR_CALL_FUNCTION(&_48$$13, "str_repeat", &_10, 127, &space, &_47$$13);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_49$$13);
			ZEPHIR_CONCAT_VS(&_49$$13, &_48$$13, "[skipped]\n");
			zephir_concat_self(&output, &_49$$13 TSRMLS_CC);
		} else if (_46$$11) {
			ZEPHIR_CALL_FUNCTION(&_50$$14, "get_object_vars", NULL, 14, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_50$$14, 0, "phalcon/debug/dump.zep", 249);
			if (Z_TYPE_P(&_50$$14) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_50$$14), _53$$14, _54$$14, _51$$14)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_54$$14 != NULL) { 
						ZVAL_STR_COPY(&key, _54$$14);
					} else {
						ZVAL_LONG(&key, _53$$14);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _51$$14);
					ZVAL_LONG(&_55$$15, tab);
					ZEPHIR_CALL_FUNCTION(&_56$$15, "str_repeat", &_10, 127, &space, &_55$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_57$$15);
					zephir_create_array(&_57$$15, 3, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_59$$15);
					ZVAL_STRING(&_59$$15, "obj");
					ZEPHIR_CALL_METHOD(&_58$$15, this_ptr, "getstyle", NULL, 0, &_59$$15);
					zephir_check_call_status();
					zephir_array_update_string(&_57$$15, SL(":style"), &_58$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_57$$15, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					add_assoc_stringl_ex(&_57$$15, SL(":type"), SL("public"));
					ZEPHIR_INIT_NVAR(&_59$$15);
					ZVAL_STRING(&_59$$15, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					ZEPHIR_CALL_FUNCTION(&_58$$15, "strtr", NULL, 48, &_59$$15, &_57$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_60$$15);
					ZEPHIR_CONCAT_VV(&_60$$15, &_56$$15, &_58$$15);
					zephir_concat_self(&output, &_60$$15 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_59$$15);
					ZVAL_STRING(&_59$$15, "");
					ZVAL_LONG(&_55$$15, (tab + 1));
					ZEPHIR_CALL_METHOD(&_61$$15, this_ptr, "output", &_21, 166, &value, &_59$$15, &_55$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_62$$15);
					ZEPHIR_CONCAT_VS(&_62$$15, &_61$$15, "\n");
					zephir_concat_self(&output, &_62$$15 TSRMLS_CC);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_50$$14, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_52$$14, &_50$$14, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_52$$14)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &_50$$14, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &_50$$14, "current", NULL, 0);
					zephir_check_call_status();
						ZVAL_LONG(&_63$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_64$$16, "str_repeat", &_10, 127, &space, &_63$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_65$$16);
						zephir_create_array(&_65$$16, 3, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_67$$16);
						ZVAL_STRING(&_67$$16, "obj");
						ZEPHIR_CALL_METHOD(&_66$$16, this_ptr, "getstyle", NULL, 0, &_67$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_65$$16, SL(":style"), &_66$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_65$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_65$$16, SL(":type"), SL("public"));
						ZEPHIR_INIT_NVAR(&_67$$16);
						ZVAL_STRING(&_67$$16, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_66$$16, "strtr", NULL, 48, &_67$$16, &_65$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_68$$16);
						ZEPHIR_CONCAT_VV(&_68$$16, &_64$$16, &_66$$16);
						zephir_concat_self(&output, &_68$$16 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_67$$16);
						ZVAL_STRING(&_67$$16, "");
						ZVAL_LONG(&_63$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_69$$16, this_ptr, "output", &_21, 166, &value, &_67$$16, &_63$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_70$$16);
						ZEPHIR_CONCAT_VS(&_70$$16, &_69$$16, "\n");
						zephir_concat_self(&output, &_70$$16 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, &_50$$14, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$17);
			object_init_ex(&reflect$$17, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflect$$17, "__construct", NULL, 81, variable);
			zephir_check_call_status();
			ZVAL_LONG(&_71$$17, ((256 | 512) | 1024));
			ZEPHIR_CALL_METHOD(&props$$17, &reflect$$17, "getproperties", NULL, 85, &_71$$17);
			zephir_check_call_status();
			zephir_is_iterable(&props$$17, 0, "phalcon/debug/dump.zep", 269);
			if (Z_TYPE_P(&props$$17) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props$$17), _72$$17)
				{
					ZEPHIR_INIT_NVAR(&property$$17);
					ZVAL_COPY(&property$$17, _72$$17);
					ZVAL_BOOL(&_74$$18, 1);
					ZEPHIR_CALL_METHOD(NULL, &property$$17, "setaccessible", &_75, 0, &_74$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&key, &property$$17, "getname", &_76, 0);
					zephir_check_call_status();
					_78$$18 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
					ZEPHIR_CALL_METHOD(&_80$$18, &property$$17, "getmodifiers", &_81, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_77$$18, _78$$18, "getmodifiernames", &_79, 0, &_80$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_82$$18);
					ZVAL_STRING(&_82$$18, " ");
					ZEPHIR_INIT_NVAR(&type);
					zephir_fast_join(&type, &_82$$18, &_77$$18 TSRMLS_CC);
					ZVAL_LONG(&_74$$18, tab);
					ZEPHIR_CALL_FUNCTION(&_83$$18, "str_repeat", &_10, 127, &space, &_74$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_84$$18);
					zephir_create_array(&_84$$18, 3, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_86$$18);
					ZVAL_STRING(&_86$$18, "obj");
					ZEPHIR_CALL_METHOD(&_85$$18, this_ptr, "getstyle", NULL, 0, &_86$$18);
					zephir_check_call_status();
					zephir_array_update_string(&_84$$18, SL(":style"), &_85$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_84$$18, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_84$$18, SL(":type"), &type, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_86$$18);
					ZVAL_STRING(&_86$$18, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					ZEPHIR_CALL_FUNCTION(&_85$$18, "strtr", NULL, 48, &_86$$18, &_84$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_87$$18);
					ZEPHIR_CONCAT_VV(&_87$$18, &_83$$18, &_85$$18);
					zephir_concat_self(&output, &_87$$18 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_89$$18, &property$$17, "getvalue", &_90, 0, variable);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_86$$18);
					ZVAL_STRING(&_86$$18, "");
					ZVAL_LONG(&_74$$18, (tab + 1));
					ZEPHIR_CALL_METHOD(&_88$$18, this_ptr, "output", &_21, 166, &_89$$18, &_86$$18, &_74$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_91$$18);
					ZEPHIR_CONCAT_VS(&_91$$18, &_88$$18, "\n");
					zephir_concat_self(&output, &_91$$18 TSRMLS_CC);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &props$$17, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_73$$17, &props$$17, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_73$$17)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&property$$17, &props$$17, "current", NULL, 0);
					zephir_check_call_status();
						ZVAL_BOOL(&_92$$19, 1);
						ZEPHIR_CALL_METHOD(NULL, &property$$17, "setaccessible", &_93, 0, &_92$$19);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &property$$17, "getname", &_94, 0);
						zephir_check_call_status();
						_96$$19 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_97$$19, &property$$17, "getmodifiers", &_98, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_95$$19, _96$$19, "getmodifiernames", &_79, 0, &_97$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_99$$19);
						ZVAL_STRING(&_99$$19, " ");
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join(&type, &_99$$19, &_95$$19 TSRMLS_CC);
						ZVAL_LONG(&_92$$19, tab);
						ZEPHIR_CALL_FUNCTION(&_100$$19, "str_repeat", &_10, 127, &space, &_92$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_101$$19);
						zephir_create_array(&_101$$19, 3, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_103$$19);
						ZVAL_STRING(&_103$$19, "obj");
						ZEPHIR_CALL_METHOD(&_102$$19, this_ptr, "getstyle", NULL, 0, &_103$$19);
						zephir_check_call_status();
						zephir_array_update_string(&_101$$19, SL(":style"), &_102$$19, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_101$$19, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_101$$19, SL(":type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_103$$19);
						ZVAL_STRING(&_103$$19, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_102$$19, "strtr", NULL, 48, &_103$$19, &_101$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_104$$19);
						ZEPHIR_CONCAT_VV(&_104$$19, &_100$$19, &_102$$19);
						zephir_concat_self(&output, &_104$$19 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_106$$19, &property$$17, "getvalue", &_107, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_103$$19);
						ZVAL_STRING(&_103$$19, "");
						ZVAL_LONG(&_92$$19, (tab + 1));
						ZEPHIR_CALL_METHOD(&_105$$19, this_ptr, "output", &_21, 166, &_106$$19, &_103$$19, &_92$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_108$$19);
						ZEPHIR_CONCAT_VS(&_108$$19, &_105$$19, "\n");
						zephir_concat_self(&output, &_108$$19 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, &props$$17, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&property$$17);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 168, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_109$$11, tab);
		ZEPHIR_CALL_FUNCTION(&_110$$11, "str_repeat", &_10, 127, &space, &_109$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_111$$11);
		zephir_create_array(&_111$$11, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_40$$11);
		ZVAL_STRING(&_40$$11, "obj");
		ZEPHIR_CALL_METHOD(&_112$$11, this_ptr, "getstyle", NULL, 0, &_40$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$11, SL(":style"), &_112$$11, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_40$$11);
		zephir_get_class(&_40$$11, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_111$$11, SL(":class"), &_40$$11, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_111$$11, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_40$$11);
		ZVAL_STRING(&_40$$11, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_112$$11, "strtr", NULL, 48, &_40$$11, &_111$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_113$$11);
		ZEPHIR_CONCAT_VV(&_113$$11, &_110$$11, &_112$$11);
		zephir_concat_self(&output, &_113$$11 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_40$$11);
		zephir_get_class(&_40$$11, variable, 0 TSRMLS_CC);
		zephir_read_property(&_109$$11, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_40$$11, &_109$$11 TSRMLS_CC)) {
			ZVAL_LONG(&_114$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_115$$20, "str_repeat", &_10, 127, &space, &_114$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_116$$20);
			ZEPHIR_CONCAT_VS(&_116$$20, &_115$$20, "[already listed]\n");
			zephir_concat_self(&output, &_116$$20 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/debug/dump.zep", 286);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _117$$21)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _117$$21);
					ZEPHIR_INIT_NVAR(&_119$$22);
					zephir_get_class(&_119$$22, variable, 0 TSRMLS_CC);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_119$$22);
					ZEPHIR_INIT_NVAR(&_119$$22);
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_120$$23, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_121$$23, "str_repeat", &_10, 127, &space, &_120$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_122$$23);
						zephir_create_array(&_122$$23, 2, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_124$$23);
						ZVAL_STRING(&_124$$23, "obj");
						ZEPHIR_CALL_METHOD(&_123$$23, this_ptr, "getstyle", NULL, 0, &_124$$23);
						zephir_check_call_status();
						zephir_array_update_string(&_122$$23, SL(":style"), &_123$$23, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_122$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_124$$23);
						ZVAL_STRING(&_124$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
						ZEPHIR_CALL_FUNCTION(&_123$$23, "strtr", NULL, 48, &_124$$23, &_122$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_125$$23);
						ZEPHIR_CONCAT_VV(&_125$$23, &_121$$23, &_123$$23);
						zephir_concat_self(&output, &_125$$23 TSRMLS_CC);
					} else {
						ZVAL_LONG(&_126$$24, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_127$$24, "str_repeat", &_10, 127, &space, &_126$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_128$$24);
						zephir_create_array(&_128$$24, 2, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_130$$24);
						ZVAL_STRING(&_130$$24, "obj");
						ZEPHIR_CALL_METHOD(&_129$$24, this_ptr, "getstyle", NULL, 0, &_130$$24);
						zephir_check_call_status();
						zephir_array_update_string(&_128$$24, SL(":style"), &_129$$24, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_128$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_130$$24);
						ZVAL_STRING(&_130$$24, "-><span style=':style'>:method</span>();\n");
						ZEPHIR_CALL_FUNCTION(&_129$$24, "strtr", NULL, 48, &_130$$24, &_128$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_131$$24);
						ZEPHIR_CONCAT_VV(&_131$$24, &_127$$24, &_129$$24);
						zephir_concat_self(&output, &_131$$24 TSRMLS_CC);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_118$$21, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_118$$21)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_132$$25);
						zephir_get_class(&_132$$25, variable, 0 TSRMLS_CC);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_132$$25);
						ZEPHIR_INIT_NVAR(&_132$$25);
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_133$$26, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_134$$26, "str_repeat", &_10, 127, &space, &_133$$26);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_135$$26);
							zephir_create_array(&_135$$26, 2, 0 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&_137$$26);
							ZVAL_STRING(&_137$$26, "obj");
							ZEPHIR_CALL_METHOD(&_136$$26, this_ptr, "getstyle", NULL, 0, &_137$$26);
							zephir_check_call_status();
							zephir_array_update_string(&_135$$26, SL(":style"), &_136$$26, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_135$$26, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_137$$26);
							ZVAL_STRING(&_137$$26, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
							ZEPHIR_CALL_FUNCTION(&_136$$26, "strtr", NULL, 48, &_137$$26, &_135$$26);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_138$$26);
							ZEPHIR_CONCAT_VV(&_138$$26, &_134$$26, &_136$$26);
							zephir_concat_self(&output, &_138$$26 TSRMLS_CC);
						} else {
							ZVAL_LONG(&_139$$27, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_140$$27, "str_repeat", &_10, 127, &space, &_139$$27);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_141$$27);
							zephir_create_array(&_141$$27, 2, 0 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&_143$$27);
							ZVAL_STRING(&_143$$27, "obj");
							ZEPHIR_CALL_METHOD(&_142$$27, this_ptr, "getstyle", NULL, 0, &_143$$27);
							zephir_check_call_status();
							zephir_array_update_string(&_141$$27, SL(":style"), &_142$$27, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_141$$27, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_143$$27);
							ZVAL_STRING(&_143$$27, "-><span style=':style'>:method</span>();\n");
							ZEPHIR_CALL_FUNCTION(&_142$$27, "strtr", NULL, 48, &_143$$27, &_141$$27);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_144$$27);
							ZEPHIR_CONCAT_VV(&_144$$27, &_140$$27, &_142$$27);
							zephir_concat_self(&output, &_144$$27 TSRMLS_CC);
						}
					ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_145$$21, tab);
			ZEPHIR_CALL_FUNCTION(&_146$$21, "str_repeat", &_10, 127, &space, &_145$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_147$$21);
			ZEPHIR_CONCAT_VS(&_147$$21, &_146$$21, ")\n");
			zephir_concat_self(&output, &_147$$21 TSRMLS_CC);
		}
		ZVAL_LONG(&_148$$11, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_149$$11, "str_repeat", &_10, 127, &space, &_148$$11);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_149$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_150$$28);
		zephir_create_array(&_150$$28, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "int");
		ZEPHIR_CALL_METHOD(&_151$$28, this_ptr, "getstyle", NULL, 0, &_152$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_150$$28, SL(":style"), &_151$$28, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_150$$28, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_151$$28, "strtr", NULL, 48, &_152$$28, &_150$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_151$$28);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_153, "is_float", NULL, 169, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_153)) {
		ZEPHIR_INIT_VAR(&_154$$29);
		zephir_create_array(&_154$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_156$$29);
		ZVAL_STRING(&_156$$29, "float");
		ZEPHIR_CALL_METHOD(&_155$$29, this_ptr, "getstyle", NULL, 0, &_156$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$29, SL(":style"), &_155$$29, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_154$$29, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_156$$29);
		ZVAL_STRING(&_156$$29, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_155$$29, "strtr", NULL, 48, &_156$$29, &_154$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_155$$29);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_157$$30);
		zephir_create_array(&_157$$30, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_159$$30);
		ZVAL_STRING(&_159$$30, "num");
		ZEPHIR_CALL_METHOD(&_158$$30, this_ptr, "getstyle", NULL, 0, &_159$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_157$$30, SL(":style"), &_158$$30, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_157$$30, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_157$$30, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_159$$30);
		ZVAL_STRING(&_159$$30, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_158$$30, "strtr", NULL, 48, &_159$$30, &_157$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_158$$30);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_160$$31);
		zephir_create_array(&_160$$31, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_162$$31);
		ZVAL_STRING(&_162$$31, "str");
		ZEPHIR_CALL_METHOD(&_161$$31, this_ptr, "getstyle", NULL, 0, &_162$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$31, SL(":style"), &_161$$31, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_160$$31, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_163$$31, 4);
		ZEPHIR_INIT_NVAR(&_162$$31);
		ZVAL_STRING(&_162$$31, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_161$$31, "htmlentities", NULL, 161, variable, &_163$$31, &_162$$31);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_164$$31, "nl2br", NULL, 170, &_161$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$31, SL(":var"), &_164$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_162$$31);
		ZVAL_STRING(&_162$$31, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_164$$31, "strtr", NULL, 48, &_162$$31, &_160$$31);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_164$$31);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_165$$32);
		zephir_create_array(&_165$$32, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_167$$32);
		ZVAL_STRING(&_167$$32, "bool");
		ZEPHIR_CALL_METHOD(&_166$$32, this_ptr, "getstyle", NULL, 0, &_167$$32);
		zephir_check_call_status();
		zephir_array_update_string(&_165$$32, SL(":style"), &_166$$32, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_168$$32);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_168$$32);
			ZVAL_STRING(&_168$$32, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_168$$32);
			ZVAL_STRING(&_168$$32, "FALSE");
		}
		zephir_array_update_string(&_165$$32, SL(":var"), &_168$$32, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_167$$32);
		ZVAL_STRING(&_167$$32, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_166$$32, "strtr", NULL, 48, &_167$$32, &_165$$32);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_166$$32);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_169$$33);
		zephir_create_array(&_169$$33, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_171$$33);
		ZVAL_STRING(&_171$$33, "null");
		ZEPHIR_CALL_METHOD(&_170$$33, this_ptr, "getstyle", NULL, 0, &_171$$33);
		zephir_check_call_status();
		zephir_array_update_string(&_169$$33, SL(":style"), &_170$$33, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_171$$33);
		ZVAL_STRING(&_171$$33, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_170$$33, "strtr", NULL, 48, &_171$$33, &_169$$33);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_170$$33);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_172);
	zephir_create_array(&_172, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_174);
	ZVAL_STRING(&_174, "other");
	ZEPHIR_CALL_METHOD(&_173, this_ptr, "getstyle", NULL, 0, &_174);
	zephir_check_call_status();
	zephir_array_update_string(&_172, SL(":style"), &_173, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_172, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_174);
	ZVAL_STRING(&_174, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_173, "strtr", NULL, 48, &_174, &_172);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_173);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Debug_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("styles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("methods"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

