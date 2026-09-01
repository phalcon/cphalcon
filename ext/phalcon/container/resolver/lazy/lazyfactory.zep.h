
extern zend_class_entry *phalcon_container_resolver_lazy_lazyfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_LazyFactory);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, arrayValues);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, call);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, callableGet);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, callableNew);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, csEnv);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, env);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, envDefault);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, functionCall);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, get);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, getCall);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, newCall);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, newInstance);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_LazyFactory, staticCall);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_arrayvalues, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\ArrayValues, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_call, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\Call, 0)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_callableget, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\CallableGet, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_callablenew, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\CallableNew, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_csenv, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\CsEnv, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_env, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\Env, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_envdefault, 0, 2, Phalcon\\Container\\Resolver\\Lazy\\EnvDefault, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_functioncall, 0, 2, Phalcon\\Container\\Resolver\\Lazy\\FunctionCall, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_get, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\Get, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_getcall, 0, 3, Phalcon\\Container\\Resolver\\Lazy\\GetCall, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_newcall, 0, 3, Phalcon\\Container\\Resolver\\Lazy\\NewCall, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_newinstance, 0, 1, Phalcon\\Container\\Resolver\\Lazy\\NewInstance, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazyfactory_staticcall, 0, 3, Phalcon\\Container\\Resolver\\Lazy\\StaticCall, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_lazyfactory_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, arrayValues, arginfo_phalcon_container_resolver_lazy_lazyfactory_arrayvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, call, arginfo_phalcon_container_resolver_lazy_lazyfactory_call, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, callableGet, arginfo_phalcon_container_resolver_lazy_lazyfactory_callableget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, callableNew, arginfo_phalcon_container_resolver_lazy_lazyfactory_callablenew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, csEnv, arginfo_phalcon_container_resolver_lazy_lazyfactory_csenv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, env, arginfo_phalcon_container_resolver_lazy_lazyfactory_env, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, envDefault, arginfo_phalcon_container_resolver_lazy_lazyfactory_envdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, functionCall, arginfo_phalcon_container_resolver_lazy_lazyfactory_functioncall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, get, arginfo_phalcon_container_resolver_lazy_lazyfactory_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, getCall, arginfo_phalcon_container_resolver_lazy_lazyfactory_getcall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, newCall, arginfo_phalcon_container_resolver_lazy_lazyfactory_newcall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, newInstance, arginfo_phalcon_container_resolver_lazy_lazyfactory_newinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_LazyFactory, staticCall, arginfo_phalcon_container_resolver_lazy_lazyfactory_staticcall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
