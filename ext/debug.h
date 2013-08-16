
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_debug_ce;

PHALCON_INIT_CLASS(Phalcon_Debug);

PHP_METHOD(Phalcon_Debug, setUri);
PHP_METHOD(Phalcon_Debug, setShowBackTrace);
PHP_METHOD(Phalcon_Debug, setShowFiles);
PHP_METHOD(Phalcon_Debug, setShowFileFragment);
PHP_METHOD(Phalcon_Debug, listen);
PHP_METHOD(Phalcon_Debug, listenExceptions);
PHP_METHOD(Phalcon_Debug, listenLowSeverity);
PHP_METHOD(Phalcon_Debug, debugVar);
PHP_METHOD(Phalcon_Debug, clearVars);
PHP_METHOD(Phalcon_Debug, _escapeString);
PHP_METHOD(Phalcon_Debug, _getArrayDump);
PHP_METHOD(Phalcon_Debug, _getVarDump);
PHP_METHOD(Phalcon_Debug, getMajorVersion);
PHP_METHOD(Phalcon_Debug, getVersion);
PHP_METHOD(Phalcon_Debug, getCssSources);
PHP_METHOD(Phalcon_Debug, getJsSources);
PHP_METHOD(Phalcon_Debug, showTraceItem);
PHP_METHOD(Phalcon_Debug, onUncaughtException);
PHP_METHOD(Phalcon_Debug, getCharset);
PHP_METHOD(Phalcon_Debug, setCharset);
PHP_METHOD(Phalcon_Debug, getLinesBeforeContext);
PHP_METHOD(Phalcon_Debug, setLinesBeforeContext);
PHP_METHOD(Phalcon_Debug, getLinesAfterContext);
PHP_METHOD(Phalcon_Debug, setLinesAfterContext);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowbacktrace, 0, 0, 1)
	ZEND_ARG_INFO(0, showBackTrace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, showFiles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfilefragment, 0, 0, 1)
	ZEND_ARG_INFO(0, showFileFragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_listen, 0, 0, 0)
	ZEND_ARG_INFO(0, exceptions)
	ZEND_ARG_INFO(0, lowSeverity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_debugvar, 0, 0, 1)
	ZEND_ARG_INFO(0, var)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_onuncaughtexception, 0, 0, 1)
	ZEND_ARG_INFO(0, exception)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setcharset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setlines, 0, 0, 1)
	ZEND_ARG_INFO(0, lines)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_debug_method_entry){
	PHP_ME(Phalcon_Debug, setUri, arginfo_phalcon_debug_seturi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, setShowBackTrace, arginfo_phalcon_debug_setshowbacktrace, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, setShowFiles, arginfo_phalcon_debug_setshowfiles, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, setShowFileFragment, arginfo_phalcon_debug_setshowfilefragment, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, listen, arginfo_phalcon_debug_listen, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, listenExceptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, listenLowSeverity, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, debugVar, arginfo_phalcon_debug_debugvar, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, clearVars, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, _escapeString, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Debug, _getArrayDump, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Debug, _getVarDump, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Debug, getMajorVersion, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, getVersion, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, getCssSources, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, getJsSources, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, showTraceItem, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Debug, onUncaughtException, arginfo_phalcon_debug_onuncaughtexception, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Debug, getCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setCharset, arginfo_phalcon_debug_setcharset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getLinesBeforeContext, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setLinesBeforeContext, arginfo_phalcon_debug_setlines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getLinesAfterContext, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setLinesAfterContext, arginfo_phalcon_debug_setlines, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
