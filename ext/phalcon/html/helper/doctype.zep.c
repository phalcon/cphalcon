
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */
/**
 * Creates Doctype tags
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Doctype)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper, Doctype, phalcon, html_helper_doctype, phalcon_html_helper_doctype_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_html_helper_doctype_ce, SL("delimiter"), ZEND_ACC_PRIVATE);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_html_helper_doctype_ce, SL("flag"), ZEND_ACC_PRIVATE);
	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("HTML32"), 1);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("HTML401_STRICT"), 2);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("HTML401_TRANSITIONAL"), 3);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("HTML401_FRAMESET"), 4);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("HTML5"), 5);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML10_STRICT"), 6);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML10_TRANSITIONAL"), 7);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML10_FRAMESET"), 8);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML11"), 9);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML20"), 10);

	zephir_declare_class_constant_long(phalcon_html_helper_doctype_ce, SL("XHTML5"), 11);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Html_Helper_Doctype, __construct)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("flag"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_EOL");
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Produce a <doctype> tag
 *
 * @param string $flag
 * @param string $delimiter
 */
PHP_METHOD(Phalcon_Html_Helper_Doctype, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval delimiter;
	zval *flag_param = NULL, *delimiter_param = NULL, _0;
	zend_long flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&delimiter);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flag)
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &flag_param, &delimiter_param);
	if (!flag_param) {
		flag = 5;
	} else {
		flag = zephir_get_intval(flag_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "\n");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, flag);
	zephir_update_property_zval(this_ptr, ZEND_STRL("flag"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &delimiter);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Doctype, __toString)
{
	zval _0, _18, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("flag"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", &_1$$3);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", &_2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", &_3$$4);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 3)) {
			zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", &_4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", &_5$$5);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 4)) {
			zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", &_6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", &_7$$6);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 6)) {
			zephir_read_property(&_8$$7, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", &_8$$7, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", &_9$$7);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 7)) {
			zephir_read_property(&_10$$8, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_11$$8, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", &_10$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", &_11$$8);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 8)) {
			zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_13$$9, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", &_12$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", &_13$$9);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 9)) {
			zephir_read_property(&_14$$10, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_15$$10, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", &_14$$10, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", &_15$$10);
			return;
		}
		if (ZEPHIR_IS_LONG(&_0, 10)) {
			zephir_read_property(&_16$$11, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_17$$11, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", &_16$$11, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", &_17$$11);
			return;
		}
	} while(0);

	zephir_read_property(&_18, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_18);
	return;
}
