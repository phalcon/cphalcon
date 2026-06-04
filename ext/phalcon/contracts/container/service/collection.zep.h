
extern zend_class_entry *phalcon_contracts_container_service_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Service_Collection);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_getalias, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_hasalias, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_setalias, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_unsetalias, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_getdefinition, 0, 1, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_hasdefinition, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_newdefinition, 0, 1, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_setdefinition, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, definition, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_unsetdefinition, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_getinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_hasinstance, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_setinstance, 0, 3, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, instance)
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_unsetinstance, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_unsetinstances, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, lifetime, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_getparameter, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_hasparameter, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_setparameter, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_unsetparameter, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_bind, 0, 2, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, interfaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, concrete, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_callableget, 0, 1, Closure, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_callablenew, 0, 1, Closure, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_extend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_getbytag, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_getresolver, 0, 0, Phalcon\\Container\\Resolver\\Resolver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_isautowireenabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_collection_new, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_container_service_collection_set, 0, 2, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_service_collection_setautowire, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_container_service_collection_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getAlias, arginfo_phalcon_contracts_container_service_collection_getalias)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, hasAlias, arginfo_phalcon_contracts_container_service_collection_hasalias)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, setAlias, arginfo_phalcon_contracts_container_service_collection_setalias)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, unsetAlias, arginfo_phalcon_contracts_container_service_collection_unsetalias)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getDefinition, arginfo_phalcon_contracts_container_service_collection_getdefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, hasDefinition, arginfo_phalcon_contracts_container_service_collection_hasdefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, newDefinition, arginfo_phalcon_contracts_container_service_collection_newdefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, setDefinition, arginfo_phalcon_contracts_container_service_collection_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, unsetDefinition, arginfo_phalcon_contracts_container_service_collection_unsetdefinition)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getInstance, arginfo_phalcon_contracts_container_service_collection_getinstance)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, hasInstance, arginfo_phalcon_contracts_container_service_collection_hasinstance)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, setInstance, arginfo_phalcon_contracts_container_service_collection_setinstance)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, unsetInstance, arginfo_phalcon_contracts_container_service_collection_unsetinstance)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, unsetInstances, arginfo_phalcon_contracts_container_service_collection_unsetinstances)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getParameter, arginfo_phalcon_contracts_container_service_collection_getparameter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, hasParameter, arginfo_phalcon_contracts_container_service_collection_hasparameter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, setParameter, arginfo_phalcon_contracts_container_service_collection_setparameter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, unsetParameter, arginfo_phalcon_contracts_container_service_collection_unsetparameter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, bind, arginfo_phalcon_contracts_container_service_collection_bind)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, callableGet, arginfo_phalcon_contracts_container_service_collection_callableget)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, callableNew, arginfo_phalcon_contracts_container_service_collection_callablenew)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, extend, arginfo_phalcon_contracts_container_service_collection_extend)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, get, arginfo_phalcon_contracts_container_service_collection_get)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getByTag, arginfo_phalcon_contracts_container_service_collection_getbytag)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, getResolver, arginfo_phalcon_contracts_container_service_collection_getresolver)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, has, arginfo_phalcon_contracts_container_service_collection_has)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, isAutowireEnabled, arginfo_phalcon_contracts_container_service_collection_isautowireenabled)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, new, arginfo_phalcon_contracts_container_service_collection_new)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, set, arginfo_phalcon_contracts_container_service_collection_set)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Collection, setAutowire, arginfo_phalcon_contracts_container_service_collection_setautowire)
	PHP_FE_END
};
