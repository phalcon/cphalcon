
extern zend_class_entry *phalcon_html_link_interfaces_evolvablelinkinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withhref, 0, 1, Phalcon\\Html\\Link\\Interfaces\\EvolvableLinkInterface, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withrel, 0, 1, Phalcon\\Html\\Link\\Interfaces\\EvolvableLinkInterface, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withoutrel, 0, 1, Phalcon\\Html\\Link\\Interfaces\\EvolvableLinkInterface, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withattribute, 0, 2, Phalcon\\Html\\Link\\Interfaces\\EvolvableLinkInterface, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withoutattribute, 0, 1, Phalcon\\Html\\Link\\Interfaces\\EvolvableLinkInterface, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_interfaces_evolvablelinkinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withHref, arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withhref)
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withRel, arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withrel)
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withoutRel, arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withoutrel)
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withAttribute, arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withattribute)
	PHP_ABSTRACT_ME(Phalcon_Html_Link_Interfaces_EvolvableLinkInterface, withoutAttribute, arginfo_phalcon_html_link_interfaces_evolvablelinkinterface_withoutattribute)
	PHP_FE_END
};
