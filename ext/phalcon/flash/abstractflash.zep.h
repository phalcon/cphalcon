
extern zend_class_entry *phalcon_flash_abstractflash_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_AbstractFlash);

PHP_METHOD(Phalcon_Flash_AbstractFlash, __construct);
PHP_METHOD(Phalcon_Flash_AbstractFlash, clear);
PHP_METHOD(Phalcon_Flash_AbstractFlash, error);
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutoescape);
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCustomTemplate);
PHP_METHOD(Phalcon_Flash_AbstractFlash, getEscaperService);
PHP_METHOD(Phalcon_Flash_AbstractFlash, notice);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutoescape);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutomaticHtml);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssClasses);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCustomTemplate);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setEscaperService);
PHP_METHOD(Phalcon_Flash_AbstractFlash, setImplicitFlush);
PHP_METHOD(Phalcon_Flash_AbstractFlash, success);
PHP_METHOD(Phalcon_Flash_AbstractFlash, outputMessage);
PHP_METHOD(Phalcon_Flash_AbstractFlash, warning);
PHP_METHOD(Phalcon_Flash_AbstractFlash, getTemplate);
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareEscapedMessage);
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareHtmlMessage);
zend_object *zephir_init_properties_Phalcon_Flash_AbstractFlash(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_abstractflash___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Escaper\\EscaperInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_error, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_error, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_getautoescape, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_getautoescape, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_getcustomtemplate, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_getcustomtemplate, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_getescaperservice, 0, 0, Phalcon\\Escaper\\EscaperInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_getescaperservice, 0, 0, IS_OBJECT, "Phalcon\\Escaper\\EscaperInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_notice, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_notice, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setautoescape, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setautoescape, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoescape, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoescape)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setautomatichtml, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setautomatichtml, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, automaticHtml, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, automaticHtml)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setcssclasses, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setcssclasses, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, cssClasses, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setcustomtemplate, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setcustomtemplate, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, customTemplate, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, customTemplate)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setescaperservice, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setescaperservice, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, escaperService, Phalcon\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_abstractflash_setimplicitflush, 0, 1, Phalcon\\Flash\\FlashInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_setimplicitflush, 0, 1, IS_OBJECT, "Phalcon\\Flash\\FlashInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, implicitFlush, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, implicitFlush)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_success, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_success, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_abstractflash_outputmessage, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_warning, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_warning, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_gettemplate, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_gettemplate, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cssClassses, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cssClassses)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_prepareescapedmessage, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_prepareescapedmessage, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_preparehtmlmessage, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_abstractflash_preparehtmlmessage, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_abstractflash_method_entry) {
	PHP_ME(Phalcon_Flash_AbstractFlash, __construct, arginfo_phalcon_flash_abstractflash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Flash_AbstractFlash, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, error, arginfo_phalcon_flash_abstractflash_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, getAutoescape, arginfo_phalcon_flash_abstractflash_getautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, getCustomTemplate, arginfo_phalcon_flash_abstractflash_getcustomtemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, getEscaperService, arginfo_phalcon_flash_abstractflash_getescaperservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, notice, arginfo_phalcon_flash_abstractflash_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setAutoescape, arginfo_phalcon_flash_abstractflash_setautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setAutomaticHtml, arginfo_phalcon_flash_abstractflash_setautomatichtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setCssClasses, arginfo_phalcon_flash_abstractflash_setcssclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setCustomTemplate, arginfo_phalcon_flash_abstractflash_setcustomtemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setEscaperService, arginfo_phalcon_flash_abstractflash_setescaperservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, setImplicitFlush, arginfo_phalcon_flash_abstractflash_setimplicitflush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, success, arginfo_phalcon_flash_abstractflash_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, outputMessage, arginfo_phalcon_flash_abstractflash_outputmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, warning, arginfo_phalcon_flash_abstractflash_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_AbstractFlash, getTemplate, arginfo_phalcon_flash_abstractflash_gettemplate, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Flash_AbstractFlash, prepareEscapedMessage, arginfo_phalcon_flash_abstractflash_prepareescapedmessage, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Flash_AbstractFlash, prepareHtmlMessage, arginfo_phalcon_flash_abstractflash_preparehtmlmessage, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
