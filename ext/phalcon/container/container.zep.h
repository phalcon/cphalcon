
extern zend_class_entry *phalcon_container_container_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Container);

PHP_METHOD(Phalcon_Container_Container, __construct);
PHP_METHOD(Phalcon_Container_Container, bind);
PHP_METHOD(Phalcon_Container_Container, callableGet);
PHP_METHOD(Phalcon_Container_Container, callableNew);
PHP_METHOD(Phalcon_Container_Container, extend);
PHP_METHOD(Phalcon_Container_Container, get);
PHP_METHOD(Phalcon_Container_Container, getAlias);
PHP_METHOD(Phalcon_Container_Container, getByTag);
PHP_METHOD(Phalcon_Container_Container, getDefinition);
PHP_METHOD(Phalcon_Container_Container, getInstance);
PHP_METHOD(Phalcon_Container_Container, getParameter);
PHP_METHOD(Phalcon_Container_Container, getResolver);
PHP_METHOD(Phalcon_Container_Container, getService);
PHP_METHOD(Phalcon_Container_Container, has);
PHP_METHOD(Phalcon_Container_Container, hasAlias);
PHP_METHOD(Phalcon_Container_Container, hasDefinition);
PHP_METHOD(Phalcon_Container_Container, hasInstance);
PHP_METHOD(Phalcon_Container_Container, hasParameter);
PHP_METHOD(Phalcon_Container_Container, hasService);
PHP_METHOD(Phalcon_Container_Container, isAutowireEnabled);
PHP_METHOD(Phalcon_Container_Container, new);
PHP_METHOD(Phalcon_Container_Container, newDefinition);
PHP_METHOD(Phalcon_Container_Container, set);
PHP_METHOD(Phalcon_Container_Container, setAlias);
PHP_METHOD(Phalcon_Container_Container, setAutowire);
PHP_METHOD(Phalcon_Container_Container, setDefinition);
PHP_METHOD(Phalcon_Container_Container, setInstance);
PHP_METHOD(Phalcon_Container_Container, setParameter);
PHP_METHOD(Phalcon_Container_Container, setTag);
PHP_METHOD(Phalcon_Container_Container, unsetAlias);
PHP_METHOD(Phalcon_Container_Container, unsetDefinition);
PHP_METHOD(Phalcon_Container_Container, unsetInstance);
PHP_METHOD(Phalcon_Container_Container, unsetInstances);
PHP_METHOD(Phalcon_Container_Container, unsetParameter);
PHP_METHOD(Phalcon_Container_Container, detectCircularAlias);
PHP_METHOD(Phalcon_Container_Container, findProcessor);
PHP_METHOD(Phalcon_Container_Container, resolve);
PHP_METHOD(Phalcon_Container_Container, resolveAlias);
PHP_METHOD(Phalcon_Container_Container, resolveParameter);
zend_object *zephir_init_properties_Phalcon_Container_Container(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_container___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_bind, 0, 2, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, interfaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, concrete, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_callableget, 0, 1, Closure, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_callablenew, 0, 1, Closure, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_extend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_getalias, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_getbytag, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_getdefinition, 0, 1, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_getinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_getparameter, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_getresolver, 0, 0, Phalcon\\Container\\Resolver\\Resolver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_getservice, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_hasalias, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_hasdefinition, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_hasinstance, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_hasparameter, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_hasservice, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_isautowireenabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_new, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_newdefinition, 0, 1, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_set, 0, 2, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_setalias, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_setautowire, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_setdefinition, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, definition, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_setinstance, 0, 3, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, instance)
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_container_setparameter, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_settag, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_unsetalias, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_unsetdefinition, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_unsetinstance, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_unsetinstances, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, lifetime, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_unsetparameter, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_detectcircularalias, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_container_findprocessor, 0, 1, Phalcon\\Container\\Definition\\Processor\\Processor, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_resolve, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, cache, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_resolvealias, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_container_resolveparameter, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_container_zephir_init_properties_phalcon_container_container, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_container_method_entry) {
PHP_ME(Phalcon_Container_Container, __construct, arginfo_phalcon_container_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Container, bind, arginfo_phalcon_container_container_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, callableGet, arginfo_phalcon_container_container_callableget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, callableNew, arginfo_phalcon_container_container_callablenew, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, extend, arginfo_phalcon_container_container_extend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, get, arginfo_phalcon_container_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getAlias, arginfo_phalcon_container_container_getalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getByTag, arginfo_phalcon_container_container_getbytag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getDefinition, arginfo_phalcon_container_container_getdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getInstance, arginfo_phalcon_container_container_getinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getParameter, arginfo_phalcon_container_container_getparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getResolver, arginfo_phalcon_container_container_getresolver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, getService, arginfo_phalcon_container_container_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, has, arginfo_phalcon_container_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, hasAlias, arginfo_phalcon_container_container_hasalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, hasDefinition, arginfo_phalcon_container_container_hasdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, hasInstance, arginfo_phalcon_container_container_hasinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, hasParameter, arginfo_phalcon_container_container_hasparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, hasService, arginfo_phalcon_container_container_hasservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, isAutowireEnabled, arginfo_phalcon_container_container_isautowireenabled, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, new, arginfo_phalcon_container_container_new, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, newDefinition, arginfo_phalcon_container_container_newdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, set, arginfo_phalcon_container_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setAlias, arginfo_phalcon_container_container_setalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setAutowire, arginfo_phalcon_container_container_setautowire, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setDefinition, arginfo_phalcon_container_container_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setInstance, arginfo_phalcon_container_container_setinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setParameter, arginfo_phalcon_container_container_setparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, setTag, arginfo_phalcon_container_container_settag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, unsetAlias, arginfo_phalcon_container_container_unsetalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, unsetDefinition, arginfo_phalcon_container_container_unsetdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, unsetInstance, arginfo_phalcon_container_container_unsetinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, unsetInstances, arginfo_phalcon_container_container_unsetinstances, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, unsetParameter, arginfo_phalcon_container_container_unsetparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Container, detectCircularAlias, arginfo_phalcon_container_container_detectcircularalias, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Container_Container, findProcessor, arginfo_phalcon_container_container_findprocessor, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Container_Container, resolve, arginfo_phalcon_container_container_resolve, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Container_Container, resolveAlias, arginfo_phalcon_container_container_resolvealias, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Container_Container, resolveParameter, arginfo_phalcon_container_container_resolveparameter, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
