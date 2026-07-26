
extern zend_class_entry *phalcon_mvc_model_eager_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Eager_Loader);

PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, apply);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildKey);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, loadResultset);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildMap);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildNode);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, buildThroughNode);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, collectKeys);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, fetchReferenced);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, normalizeFields);
PHP_METHOD(Phalcon_Mvc_Model_Eager_Loader, recordKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_eager_loader___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_apply, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, record)
	ZEND_ARG_ARRAY_INFO(0, eagerMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_buildkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_loadresultset, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, resultset, Phalcon\\Mvc\\Model\\Resultset\\Simple, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, tree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_buildmap, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, parents, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, tree, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_buildnode, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, parents, 0)
	ZEND_ARG_ARRAY_INFO(0, node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_buildthroughnode, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, parents, 0)
	ZEND_ARG_ARRAY_INFO(0, node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_collectkeys, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, parents, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_fetchreferenced, 0, 4, Phalcon\\Mvc\\Model\\Resultset\\Simple, 0)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_normalizefields, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_eager_loader_recordkey, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_eager_loader_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, __construct, arginfo_phalcon_mvc_model_eager_loader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, apply, arginfo_phalcon_mvc_model_eager_loader_apply, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, buildKey, arginfo_phalcon_mvc_model_eager_loader_buildkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, loadResultset, arginfo_phalcon_mvc_model_eager_loader_loadresultset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, buildMap, arginfo_phalcon_mvc_model_eager_loader_buildmap, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, buildNode, arginfo_phalcon_mvc_model_eager_loader_buildnode, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, buildThroughNode, arginfo_phalcon_mvc_model_eager_loader_buildthroughnode, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, collectKeys, arginfo_phalcon_mvc_model_eager_loader_collectkeys, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, fetchReferenced, arginfo_phalcon_mvc_model_eager_loader_fetchreferenced, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, normalizeFields, arginfo_phalcon_mvc_model_eager_loader_normalizefields, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Eager_Loader, recordKey, arginfo_phalcon_mvc_model_eager_loader_recordkey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
