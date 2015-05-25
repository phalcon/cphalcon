
extern zend_class_entry *phalcon_assets_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager);

PHP_METHOD(Phalcon_Assets_Manager, __construct);
PHP_METHOD(Phalcon_Assets_Manager, setOptions);
PHP_METHOD(Phalcon_Assets_Manager, getOptions);
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
PHP_METHOD(Phalcon_Assets_Manager, addCss);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss);
PHP_METHOD(Phalcon_Assets_Manager, addJs);
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs);
PHP_METHOD(Phalcon_Assets_Manager, addResourceByType);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType);
PHP_METHOD(Phalcon_Assets_Manager, addResource);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode);
PHP_METHOD(Phalcon_Assets_Manager, set);
PHP_METHOD(Phalcon_Assets_Manager, get);
PHP_METHOD(Phalcon_Assets_Manager, getCss);
PHP_METHOD(Phalcon_Assets_Manager, getJs);
PHP_METHOD(Phalcon_Assets_Manager, collection);
PHP_METHOD(Phalcon_Assets_Manager, output);
PHP_METHOD(Phalcon_Assets_Manager, outputInline);
PHP_METHOD(Phalcon_Assets_Manager, outputCss);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss);
PHP_METHOD(Phalcon_Assets_Manager, outputJs);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitOutput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresourcebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecodebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresource, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecode, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinline, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinlinecss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinlinejs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_manager_method_entry) {
	PHP_ME(Phalcon_Assets_Manager, __construct, arginfo_phalcon_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addCss, arginfo_phalcon_assets_manager_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCss, arginfo_phalcon_assets_manager_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addJs, arginfo_phalcon_assets_manager_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineJs, arginfo_phalcon_assets_manager_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResourceByType, arginfo_phalcon_assets_manager_addresourcebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCodeByType, arginfo_phalcon_assets_manager_addinlinecodebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResource, arginfo_phalcon_assets_manager_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCode, arginfo_phalcon_assets_manager_addinlinecode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, get, arginfo_phalcon_assets_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, collection, arginfo_phalcon_assets_manager_collection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, output, arginfo_phalcon_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInline, arginfo_phalcon_assets_manager_outputinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineCss, arginfo_phalcon_assets_manager_outputinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineJs, arginfo_phalcon_assets_manager_outputinlinejs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
