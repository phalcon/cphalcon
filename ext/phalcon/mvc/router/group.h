
extern zend_class_entry *phalcon_mvc_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group);

PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch);

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_group_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
