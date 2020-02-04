
extern zend_class_entry *phalcon_html_helper_meta_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Meta);

PHP_METHOD(Phalcon_Html_Helper_Meta, add);
PHP_METHOD(Phalcon_Html_Helper_Meta, addHttp);
PHP_METHOD(Phalcon_Html_Helper_Meta, addName);
PHP_METHOD(Phalcon_Html_Helper_Meta, addProperty);
PHP_METHOD(Phalcon_Html_Helper_Meta, getTag);
PHP_METHOD(Phalcon_Html_Helper_Meta, addElement);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_meta_add, 0, 0, Phalcon\\Html\\Helper\\Meta, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_add, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\Meta", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_meta_addhttp, 0, 2, Phalcon\\Html\\Helper\\Meta, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_addhttp, 0, 2, IS_OBJECT, "Phalcon\\Html\\Helper\\Meta", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpEquiv, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, httpEquiv)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_meta_addname, 0, 2, Phalcon\\Html\\Helper\\Meta, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_addname, 0, 2, IS_OBJECT, "Phalcon\\Html\\Helper\\Meta", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_meta_addproperty, 0, 2, Phalcon\\Html\\Helper\\Meta, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_addproperty, 0, 2, IS_OBJECT, "Phalcon\\Html\\Helper\\Meta", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_gettag, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_gettag, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_meta_addelement, 0, 3, Phalcon\\Html\\Helper\\Meta, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_meta_addelement, 0, 3, IS_OBJECT, "Phalcon\\Html\\Helper\\Meta", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_meta_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Meta, add, arginfo_phalcon_html_helper_meta_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Meta, addHttp, arginfo_phalcon_html_helper_meta_addhttp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Meta, addName, arginfo_phalcon_html_helper_meta_addname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Meta, addProperty, arginfo_phalcon_html_helper_meta_addproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Meta, getTag, arginfo_phalcon_html_helper_meta_gettag, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Meta, addElement, arginfo_phalcon_html_helper_meta_addelement, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
