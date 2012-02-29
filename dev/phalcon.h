
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

extern zend_class_entry *phalcon_dispatcher_class_entry;
extern zend_class_entry *phalcon_response_class_entry;
extern zend_class_entry *phalcon_request_class_entry;
extern zend_class_entry *phalcon_controller_front_class_entry;
extern zend_class_entry *phalcon_view_class_entry;
extern zend_class_entry *phalcon_test_class_entry;
extern zend_class_entry *phalcon_utils_class_entry;
extern zend_class_entry *phalcon_db_class_entry;
extern zend_class_entry *phalcon_internal_test_class_entry;
extern zend_class_entry *phalcon_internal_testtemp_class_entry;
extern zend_class_entry *phalcon_internal_testdummy_class_entry;
extern zend_class_entry *phalcon_internal_testparent_class_entry;
extern zend_class_entry *phalcon_tag_exception_class_entry;
extern zend_class_entry *phalcon_router_rewrite_class_entry;
extern zend_class_entry *phalcon_db_exception_class_entry;
extern zend_class_entry *phalcon_db_mysql_class_entry;
extern zend_class_entry *phalcon_db_pool_class_entry;
extern zend_class_entry *phalcon_db_dialect_mysql_class_entry;
extern zend_class_entry *phalcon_db_rawvalue_class_entry;
extern zend_class_entry *phalcon_flash_class_entry;
extern zend_class_entry *phalcon_logger_class_entry;
extern zend_class_entry *phalcon_config_class_entry;
extern zend_class_entry *phalcon_filter_class_entry;
extern zend_class_entry *phalcon_exception_class_entry;
extern zend_class_entry *phalcon_transaction_class_entry;
extern zend_class_entry *phalcon_transaction_failed_class_entry;
extern zend_class_entry *phalcon_transaction_manager_class_entry;
extern zend_class_entry *phalcon_session_class_entry;
extern zend_class_entry *phalcon_config_adapter_ini_class_entry;
extern zend_class_entry *phalcon_config_exception_class_entry;
extern zend_class_entry *phalcon_controller_class_entry;
extern zend_class_entry *phalcon_model_message_class_entry;
extern zend_class_entry *phalcon_model_manager_class_entry;
extern zend_class_entry *phalcon_model_metadata_class_entry;
extern zend_class_entry *phalcon_model_row_class_entry;
extern zend_class_entry *phalcon_model_base_class_entry;
extern zend_class_entry *phalcon_model_metadata_memory_class_entry;
extern zend_class_entry *phalcon_model_resultset_class_entry;
extern zend_class_entry *phalcon_model_exception_class_entry;
extern zend_class_entry *phalcon_view_exception_class_entry;
extern zend_class_entry *phalcon_tag_class_entry;

PHP_METHOD(Phalcon_Dispatcher, __construct);
PHP_METHOD(Phalcon_Dispatcher, setControllersDir);
PHP_METHOD(Phalcon_Dispatcher, getControllersDir);
PHP_METHOD(Phalcon_Dispatcher, setBasePath);
PHP_METHOD(Phalcon_Dispatcher, getBasePath);
PHP_METHOD(Phalcon_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Dispatcher, getControllerName);
PHP_METHOD(Phalcon_Dispatcher, setActionName);
PHP_METHOD(Phalcon_Dispatcher, getActionName);
PHP_METHOD(Phalcon_Dispatcher, setParams);
PHP_METHOD(Phalcon_Dispatcher, getParams);
PHP_METHOD(Phalcon_Dispatcher, dispatch);
PHP_METHOD(Phalcon_Dispatcher, forward);
PHP_METHOD(Phalcon_Dispatcher, getControllers);
PHP_METHOD(Phalcon_Dispatcher, getLastController);
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue);

PHP_METHOD(Phalcon_Response, __construct);
PHP_METHOD(Phalcon_Response, getInstance);

PHP_METHOD(Phalcon_Request, __construct);
PHP_METHOD(Phalcon_Request, getInstance);
PHP_METHOD(Phalcon_Request, setFilter);
PHP_METHOD(Phalcon_Request, getFilter);
PHP_METHOD(Phalcon_Request, getPost);
PHP_METHOD(Phalcon_Request, getQuery);
PHP_METHOD(Phalcon_Request, getServer);
PHP_METHOD(Phalcon_Request, getHeader);
PHP_METHOD(Phalcon_Request, getScheme);
PHP_METHOD(Phalcon_Request, isAjax);
PHP_METHOD(Phalcon_Request, isSoapRequested);
PHP_METHOD(Phalcon_Request, isSecureRequest);
PHP_METHOD(Phalcon_Request, getRawBody);
PHP_METHOD(Phalcon_Request, getServerAddress);
PHP_METHOD(Phalcon_Request, getServerName);
PHP_METHOD(Phalcon_Request, getHttpHost);
PHP_METHOD(Phalcon_Request, getClientAddress);
PHP_METHOD(Phalcon_Request, getMethod);
PHP_METHOD(Phalcon_Request, getUserAgent);
PHP_METHOD(Phalcon_Request, isPost);
PHP_METHOD(Phalcon_Request, isGet);
PHP_METHOD(Phalcon_Request, isPut);
PHP_METHOD(Phalcon_Request, isHead);
PHP_METHOD(Phalcon_Request, isDelete);
PHP_METHOD(Phalcon_Request, isOptions);
PHP_METHOD(Phalcon_Request, hasFiles);
PHP_METHOD(Phalcon_Request, getUploadedFiles);
PHP_METHOD(Phalcon_Request, getHTTPReferer);
PHP_METHOD(Phalcon_Request, getAcceptableContent);
PHP_METHOD(Phalcon_Request, getBestQualityAccept);
PHP_METHOD(Phalcon_Request, getClientCharsets);
PHP_METHOD(Phalcon_Request, getBestQualityCharset);

PHP_METHOD(Phalcon_Controller_Front, __construct);
PHP_METHOD(Phalcon_Controller_Front, getInstance);
PHP_METHOD(Phalcon_Controller_Front, setConfig);
PHP_METHOD(Phalcon_Controller_Front, setDatabaseConfig);
PHP_METHOD(Phalcon_Controller_Front, setControllersDir);
PHP_METHOD(Phalcon_Controller_Front, setModelsDir);
PHP_METHOD(Phalcon_Controller_Front, setViewsDir);
PHP_METHOD(Phalcon_Controller_Front, setRouter);
PHP_METHOD(Phalcon_Controller_Front, getRouter);
PHP_METHOD(Phalcon_Controller_Front, setDispatcher);
PHP_METHOD(Phalcon_Controller_Front, getDispatcher);
PHP_METHOD(Phalcon_Controller_Front, setBaseUri);
PHP_METHOD(Phalcon_Controller_Front, getBaseUri);
PHP_METHOD(Phalcon_Controller_Front, setBasePath);
PHP_METHOD(Phalcon_Controller_Front, getBasePath);
PHP_METHOD(Phalcon_Controller_Front, setRequest);
PHP_METHOD(Phalcon_Controller_Front, setResponse);
PHP_METHOD(Phalcon_Controller_Front, setModelComponent);
PHP_METHOD(Phalcon_Controller_Front, getModelComponent);
PHP_METHOD(Phalcon_Controller_Front, setViewComponent);
PHP_METHOD(Phalcon_Controller_Front, getViewComponent);
PHP_METHOD(Phalcon_Controller_Front, dispatchLoop);

PHP_METHOD(Phalcon_View, __construct);
PHP_METHOD(Phalcon_View, setViewsDir);
PHP_METHOD(Phalcon_View, getViewsDir);
PHP_METHOD(Phalcon_View, setTemplateBefore);
PHP_METHOD(Phalcon_View, setTemplateAfter);
PHP_METHOD(Phalcon_View, setParamToView);
PHP_METHOD(Phalcon_View, getParamsToView);
PHP_METHOD(Phalcon_View, start);
PHP_METHOD(Phalcon_View, render);
PHP_METHOD(Phalcon_View, finish);
PHP_METHOD(Phalcon_View, getContent);
PHP_METHOD(Phalcon_View, url);
PHP_METHOD(Phalcon_View, path);

PHP_METHOD(Phalcon_Test, nice);

PHP_METHOD(Phalcon_Utils, camelize);
PHP_METHOD(Phalcon_Utils, uncamelize);
PHP_METHOD(Phalcon_Utils, getUrl);
PHP_METHOD(Phalcon_Utils, getLocalPath);

PHP_METHOD(Phalcon_Db, __construct);
PHP_METHOD(Phalcon_Db, setLogger);
PHP_METHOD(Phalcon_Db, log);
PHP_METHOD(Phalcon_Db, fetchOne);
PHP_METHOD(Phalcon_Db, fetchAll);
PHP_METHOD(Phalcon_Db, insert);
PHP_METHOD(Phalcon_Db, update);
PHP_METHOD(Phalcon_Db, delete);
PHP_METHOD(Phalcon_Db, begin);
PHP_METHOD(Phalcon_Db, rollback);
PHP_METHOD(Phalcon_Db, commit);
PHP_METHOD(Phalcon_Db, setUnderTransaction);
PHP_METHOD(Phalcon_Db, isUnderTransaction);
PHP_METHOD(Phalcon_Db, getHaveAutoCommit);
PHP_METHOD(Phalcon_Db, getDatabaseName);
PHP_METHOD(Phalcon_Db, getDefaultSchema);
PHP_METHOD(Phalcon_Db, getUsername);
PHP_METHOD(Phalcon_Db, getHostName);
PHP_METHOD(Phalcon_Db, getConnectionId);
PHP_METHOD(Phalcon_Db, factory);

PHP_METHOD(Phalcon_Internal_Test, __construct);
PHP_METHOD(Phalcon_Internal_Test, e1);
PHP_METHOD(Phalcon_Internal_Test, e2);
PHP_METHOD(Phalcon_Internal_Test, e3);
PHP_METHOD(Phalcon_Internal_Test, e4);
PHP_METHOD(Phalcon_Internal_Test, e5);
PHP_METHOD(Phalcon_Internal_Test, e6);
PHP_METHOD(Phalcon_Internal_Test, e7);
PHP_METHOD(Phalcon_Internal_Test, e9);
PHP_METHOD(Phalcon_Internal_Test, e10);
PHP_METHOD(Phalcon_Internal_Test, e13);
PHP_METHOD(Phalcon_Internal_Test, e14);
PHP_METHOD(Phalcon_Internal_Test, o1);
PHP_METHOD(Phalcon_Internal_Test, o2);
PHP_METHOD(Phalcon_Internal_Test, o3);
PHP_METHOD(Phalcon_Internal_Test, o4);
PHP_METHOD(Phalcon_Internal_Test, o5);
PHP_METHOD(Phalcon_Internal_Test, o6);
PHP_METHOD(Phalcon_Internal_Test, o7);
PHP_METHOD(Phalcon_Internal_Test, o8);
PHP_METHOD(Phalcon_Internal_Test, o9);
PHP_METHOD(Phalcon_Internal_Test, o10);
PHP_METHOD(Phalcon_Internal_Test, o11);
PHP_METHOD(Phalcon_Internal_Test, o12);
PHP_METHOD(Phalcon_Internal_Test, o13);
PHP_METHOD(Phalcon_Internal_Test, o14);
PHP_METHOD(Phalcon_Internal_Test, o15);
PHP_METHOD(Phalcon_Internal_Test, o16);
PHP_METHOD(Phalcon_Internal_Test, o17);
PHP_METHOD(Phalcon_Internal_Test, o18);
PHP_METHOD(Phalcon_Internal_Test, o19);
PHP_METHOD(Phalcon_Internal_Test, o20);
PHP_METHOD(Phalcon_Internal_Test, o21);
PHP_METHOD(Phalcon_Internal_Test, o22);
PHP_METHOD(Phalcon_Internal_Test, o23);
PHP_METHOD(Phalcon_Internal_Test, a0);
PHP_METHOD(Phalcon_Internal_Test, a1);
PHP_METHOD(Phalcon_Internal_Test, a2);
PHP_METHOD(Phalcon_Internal_Test, a3);
PHP_METHOD(Phalcon_Internal_Test, a4);
PHP_METHOD(Phalcon_Internal_Test, a5);
PHP_METHOD(Phalcon_Internal_Test, a6);
PHP_METHOD(Phalcon_Internal_Test, a7);
PHP_METHOD(Phalcon_Internal_Test, a10);
PHP_METHOD(Phalcon_Internal_Test, a11);
PHP_METHOD(Phalcon_Internal_Test, a12);
PHP_METHOD(Phalcon_Internal_Test, a13);
PHP_METHOD(Phalcon_Internal_Test, a14);
PHP_METHOD(Phalcon_Internal_Test, a15);
PHP_METHOD(Phalcon_Internal_Test, a16);
PHP_METHOD(Phalcon_Internal_Test, a17);
PHP_METHOD(Phalcon_Internal_Test, a18);
PHP_METHOD(Phalcon_Internal_Test, a19);
PHP_METHOD(Phalcon_Internal_Test, a20);
PHP_METHOD(Phalcon_Internal_Test, a21);
PHP_METHOD(Phalcon_Internal_Test, a22);
PHP_METHOD(Phalcon_Internal_Test, a23);
PHP_METHOD(Phalcon_Internal_Test, a24);
PHP_METHOD(Phalcon_Internal_Test, a25);
PHP_METHOD(Phalcon_Internal_Test, sa0);
PHP_METHOD(Phalcon_Internal_Test, sa1);
PHP_METHOD(Phalcon_Internal_Test, sa2);
PHP_METHOD(Phalcon_Internal_Test, sa3);
PHP_METHOD(Phalcon_Internal_Test, sa4);
PHP_METHOD(Phalcon_Internal_Test, sa5);
PHP_METHOD(Phalcon_Internal_Test, sa6);
PHP_METHOD(Phalcon_Internal_Test, sa7);
PHP_METHOD(Phalcon_Internal_Test, c1);
PHP_METHOD(Phalcon_Internal_Test, c2);
PHP_METHOD(Phalcon_Internal_Test, c3);
PHP_METHOD(Phalcon_Internal_Test, c4);
PHP_METHOD(Phalcon_Internal_Test, c5);
PHP_METHOD(Phalcon_Internal_Test, c6);
PHP_METHOD(Phalcon_Internal_Test, c7);
PHP_METHOD(Phalcon_Internal_Test, c8);
PHP_METHOD(Phalcon_Internal_Test, c9);
PHP_METHOD(Phalcon_Internal_Test, c10);
PHP_METHOD(Phalcon_Internal_Test, c11);
PHP_METHOD(Phalcon_Internal_Test, f1);
PHP_METHOD(Phalcon_Internal_Test, f2);
PHP_METHOD(Phalcon_Internal_Test, f3);
PHP_METHOD(Phalcon_Internal_Test, f4);
PHP_METHOD(Phalcon_Internal_Test, f5);
PHP_METHOD(Phalcon_Internal_Test, f6);
PHP_METHOD(Phalcon_Internal_Test, f7);
PHP_METHOD(Phalcon_Internal_Test, f8);
PHP_METHOD(Phalcon_Internal_Test, f9);
PHP_METHOD(Phalcon_Internal_Test, f10);
PHP_METHOD(Phalcon_Internal_Test, m1);
PHP_METHOD(Phalcon_Internal_Test, m2);
PHP_METHOD(Phalcon_Internal_Test, m3);
PHP_METHOD(Phalcon_Internal_Test, m4);
PHP_METHOD(Phalcon_Internal_Test, m5);
PHP_METHOD(Phalcon_Internal_Test, m6);
PHP_METHOD(Phalcon_Internal_Test, m7);
PHP_METHOD(Phalcon_Internal_Test, m8);
PHP_METHOD(Phalcon_Internal_Test, m9);
PHP_METHOD(Phalcon_Internal_Test, m10);
PHP_METHOD(Phalcon_Internal_Test, m11);
PHP_METHOD(Phalcon_Internal_Test, m12);
PHP_METHOD(Phalcon_Internal_Test, m13);
PHP_METHOD(Phalcon_Internal_Test, m14);
PHP_METHOD(Phalcon_Internal_Test, m15);
PHP_METHOD(Phalcon_Internal_Test, mp3);
PHP_METHOD(Phalcon_Internal_Test, mp4);
PHP_METHOD(Phalcon_Internal_Test, mp5);
PHP_METHOD(Phalcon_Internal_Test, mp6);
PHP_METHOD(Phalcon_Internal_Test, sm1);
PHP_METHOD(Phalcon_Internal_Test, sm2);
PHP_METHOD(Phalcon_Internal_Test, sm3);
PHP_METHOD(Phalcon_Internal_Test, sm4);
PHP_METHOD(Phalcon_Internal_Test, sm5);
PHP_METHOD(Phalcon_Internal_Test, sm6);
PHP_METHOD(Phalcon_Internal_Test, sm7);
PHP_METHOD(Phalcon_Internal_Test, sm8);
PHP_METHOD(Phalcon_Internal_Test, sm9);
PHP_METHOD(Phalcon_Internal_Test, sm10);
PHP_METHOD(Phalcon_Internal_Test, sm11);
PHP_METHOD(Phalcon_Internal_Test, smp2);
PHP_METHOD(Phalcon_Internal_Test, smp4);
PHP_METHOD(Phalcon_Internal_Test, smp5);
PHP_METHOD(Phalcon_Internal_Test, p1);
PHP_METHOD(Phalcon_Internal_Test, p2);
PHP_METHOD(Phalcon_Internal_Test, p3);
PHP_METHOD(Phalcon_Internal_Test, p4);
PHP_METHOD(Phalcon_Internal_Test, p5);
PHP_METHOD(Phalcon_Internal_Test, p6);
PHP_METHOD(Phalcon_Internal_Test, p7);
PHP_METHOD(Phalcon_Internal_Test, p8);
PHP_METHOD(Phalcon_Internal_Test, p9);
PHP_METHOD(Phalcon_Internal_Test, p10);
PHP_METHOD(Phalcon_Internal_Test, p11);
PHP_METHOD(Phalcon_Internal_Test, p12);
PHP_METHOD(Phalcon_Internal_Test, p13);
PHP_METHOD(Phalcon_Internal_Test, p14);
PHP_METHOD(Phalcon_Internal_Test, p15);
PHP_METHOD(Phalcon_Internal_Test, p16);
PHP_METHOD(Phalcon_Internal_Test, p17);
PHP_METHOD(Phalcon_Internal_Test, p18);
PHP_METHOD(Phalcon_Internal_Test, p19);
PHP_METHOD(Phalcon_Internal_Test, p20);
PHP_METHOD(Phalcon_Internal_Test, p21);
PHP_METHOD(Phalcon_Internal_Test, p22);
PHP_METHOD(Phalcon_Internal_Test, p23);
PHP_METHOD(Phalcon_Internal_Test, p24);
PHP_METHOD(Phalcon_Internal_Test, p25);
PHP_METHOD(Phalcon_Internal_Test, p26);
PHP_METHOD(Phalcon_Internal_Test, p27);
PHP_METHOD(Phalcon_Internal_Test, p28);
PHP_METHOD(Phalcon_Internal_Test, p29);
PHP_METHOD(Phalcon_Internal_Test, p30);
PHP_METHOD(Phalcon_Internal_Test, p31);
PHP_METHOD(Phalcon_Internal_Test, sp1);
PHP_METHOD(Phalcon_Internal_Test, sp2);
PHP_METHOD(Phalcon_Internal_Test, sp3);
PHP_METHOD(Phalcon_Internal_Test, sp4);
PHP_METHOD(Phalcon_Internal_Test, sp5);
PHP_METHOD(Phalcon_Internal_Test, sp6);
PHP_METHOD(Phalcon_Internal_Test, sp7);
PHP_METHOD(Phalcon_Internal_Test, sp8);
PHP_METHOD(Phalcon_Internal_Test, sp9);
PHP_METHOD(Phalcon_Internal_Test, sp10);
PHP_METHOD(Phalcon_Internal_Test, sp11);
PHP_METHOD(Phalcon_Internal_Test, cc1);
PHP_METHOD(Phalcon_Internal_Test, cc2);
PHP_METHOD(Phalcon_Internal_Test, cc3);
PHP_METHOD(Phalcon_Internal_Test, cc4);
PHP_METHOD(Phalcon_Internal_Test, cc5);
PHP_METHOD(Phalcon_Internal_Test, cc6);
PHP_METHOD(Phalcon_Internal_Test, is1);
PHP_METHOD(Phalcon_Internal_Test, is2);
PHP_METHOD(Phalcon_Internal_Test, is3);
PHP_METHOD(Phalcon_Internal_Test, is4);
PHP_METHOD(Phalcon_Internal_Test, is5);
PHP_METHOD(Phalcon_Internal_Test, is6);
PHP_METHOD(Phalcon_Internal_Test, is7);
PHP_METHOD(Phalcon_Internal_Test, is8);
PHP_METHOD(Phalcon_Internal_Test, is9);
PHP_METHOD(Phalcon_Internal_Test, is10);
PHP_METHOD(Phalcon_Internal_Test, is11);
PHP_METHOD(Phalcon_Internal_Test, is12);
PHP_METHOD(Phalcon_Internal_Test, un1);
PHP_METHOD(Phalcon_Internal_Test, un2);
PHP_METHOD(Phalcon_Internal_Test, un3);
PHP_METHOD(Phalcon_Internal_Test, iof1);
PHP_METHOD(Phalcon_Internal_Test, iof2);
PHP_METHOD(Phalcon_Internal_Test, iof3);
PHP_METHOD(Phalcon_Internal_Test, t1);
PHP_METHOD(Phalcon_Internal_Test, t2);
PHP_METHOD(Phalcon_Internal_Test, t3);
PHP_METHOD(Phalcon_Internal_Test, t4);
PHP_METHOD(Phalcon_Internal_Test, t5);
PHP_METHOD(Phalcon_Internal_Test, t6);
PHP_METHOD(Phalcon_Internal_Test, t7);
PHP_METHOD(Phalcon_Internal_Test, t8);
PHP_METHOD(Phalcon_Internal_Test, t9);
PHP_METHOD(Phalcon_Internal_Test, t10);
PHP_METHOD(Phalcon_Internal_Test, t11);
PHP_METHOD(Phalcon_Internal_Test, t12);

PHP_METHOD(Phalcon_Internal_TestTemp, e5a);
PHP_METHOD(Phalcon_Internal_TestTemp, e9a);
PHP_METHOD(Phalcon_Internal_TestTemp, e10a);
PHP_METHOD(Phalcon_Internal_TestTemp, e13a);
PHP_METHOD(Phalcon_Internal_TestTemp, e13b);
PHP_METHOD(Phalcon_Internal_TestTemp, e13c);
PHP_METHOD(Phalcon_Internal_TestTemp, e13d);
PHP_METHOD(Phalcon_Internal_TestTemp, e14);

PHP_METHOD(Phalcon_Internal_TestDummy, __construct);
PHP_METHOD(Phalcon_Internal_TestDummy, f1);

PHP_METHOD(Phalcon_Internal_TestParent, mp1);
PHP_METHOD(Phalcon_Internal_TestParent, mp2);
PHP_METHOD(Phalcon_Internal_TestParent, mp7);
PHP_METHOD(Phalcon_Internal_TestParent, smp1);
PHP_METHOD(Phalcon_Internal_TestParent, smp3);
PHP_METHOD(Phalcon_Internal_TestParent, smp6);

PHP_METHOD(Phalcon_Tag_Exception, __construct);

PHP_METHOD(Phalcon_Router_Rewrite, __construct);
PHP_METHOD(Phalcon_Router_Rewrite, _getRewriteUri);
PHP_METHOD(Phalcon_Router_Rewrite, setBaseUri);
PHP_METHOD(Phalcon_Router_Rewrite, handle);
PHP_METHOD(Phalcon_Router_Rewrite, getControllerName);
PHP_METHOD(Phalcon_Router_Rewrite, getActionName);
PHP_METHOD(Phalcon_Router_Rewrite, getParams);

PHP_METHOD(Phalcon_Db_Exception, __construct);

PHP_METHOD(Phalcon_Db_Mysql, __construct);
PHP_METHOD(Phalcon_Db_Mysql, connect);
PHP_METHOD(Phalcon_Db_Mysql, query);
PHP_METHOD(Phalcon_Db_Mysql, close);
PHP_METHOD(Phalcon_Db_Mysql, fetchArray);
PHP_METHOD(Phalcon_Db_Mysql, numRows);
PHP_METHOD(Phalcon_Db_Mysql, dataSeek);
PHP_METHOD(Phalcon_Db_Mysql, affectedRows);
PHP_METHOD(Phalcon_Db_Mysql, setFetchMode);
PHP_METHOD(Phalcon_Db_Mysql, error);
PHP_METHOD(Phalcon_Db_Mysql, noError);
PHP_METHOD(Phalcon_Db_Mysql, lastInsertId);
PHP_METHOD(Phalcon_Db_Mysql, limit);
PHP_METHOD(Phalcon_Db_Mysql, tableExists);
PHP_METHOD(Phalcon_Db_Mysql, viewExists);
PHP_METHOD(Phalcon_Db_Mysql, describeTable);
PHP_METHOD(Phalcon_Db_Mysql, getDateUsingFormat);

PHP_METHOD(Phalcon_Db_Pool, hasDefaultDescriptor);
PHP_METHOD(Phalcon_Db_Pool, setDefaultDescriptor);
PHP_METHOD(Phalcon_Db_Pool, getConnection);

PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeTable);

PHP_METHOD(Phalcon_Db_RawValue, __construct);
PHP_METHOD(Phalcon_Db_RawValue, getValue);
PHP_METHOD(Phalcon_Db_RawValue, __toString);

PHP_METHOD(Phalcon_Flash, _showMessage);
PHP_METHOD(Phalcon_Flash, error);
PHP_METHOD(Phalcon_Flash, notice);
PHP_METHOD(Phalcon_Flash, success);
PHP_METHOD(Phalcon_Flash, warning);

PHP_METHOD(Phalcon_Logger, __construct);
PHP_METHOD(Phalcon_Logger, setFormat);

PHP_METHOD(Phalcon_Config, __construct);

PHP_METHOD(Phalcon_Filter, sanitize);
PHP_METHOD(Phalcon_Filter, _sanitize);

PHP_METHOD(Phalcon_Exception, __construct);

PHP_METHOD(Phalcon_Transaction, __construct);
PHP_METHOD(Phalcon_Transaction, setTransactionManager);
PHP_METHOD(Phalcon_Transaction, begin);
PHP_METHOD(Phalcon_Transaction, commit);
PHP_METHOD(Phalcon_Transaction, rollback);
PHP_METHOD(Phalcon_Transaction, getConnection);
PHP_METHOD(Phalcon_Transaction, setIsNewTransaction);
PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort);
PHP_METHOD(Phalcon_Transaction, isManaged);
PHP_METHOD(Phalcon_Transaction, setDependencyPointer);
PHP_METHOD(Phalcon_Transaction, attachDependency);
PHP_METHOD(Phalcon_Transaction, save);
PHP_METHOD(Phalcon_Transaction, getMessages);
PHP_METHOD(Phalcon_Transaction, isValid);
PHP_METHOD(Phalcon_Transaction, setRollbackedRecord);

PHP_METHOD(Phalcon_Transaction_Failed, __construct);
PHP_METHOD(Phalcon_Transaction_Failed, getRecordMessages);
PHP_METHOD(Phalcon_Transaction_Failed, getRecord);

PHP_METHOD(Phalcon_Transaction_Manager, has);
PHP_METHOD(Phalcon_Transaction_Manager, get);
PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent);
PHP_METHOD(Phalcon_Transaction_Manager, commit);
PHP_METHOD(Phalcon_Transaction_Manager, rollback);
PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback);
PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit);
PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction);
PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions);
PHP_METHOD(Phalcon_Transaction_Manager, isAutomatic);
PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic);

PHP_METHOD(Phalcon_Session, start);
PHP_METHOD(Phalcon_Session, setOptions);
PHP_METHOD(Phalcon_Session, get);
PHP_METHOD(Phalcon_Session, set);
PHP_METHOD(Phalcon_Session, getId);

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);

PHP_METHOD(Phalcon_Config_Exception, __construct);

PHP_METHOD(Phalcon_Controller, __construct);
PHP_METHOD(Phalcon_Controller, _forward);
PHP_METHOD(Phalcon_Controller, __get);

PHP_METHOD(Phalcon_Model_Message, __construct);
PHP_METHOD(Phalcon_Model_Message, setType);
PHP_METHOD(Phalcon_Model_Message, getType);
PHP_METHOD(Phalcon_Model_Message, setMessage);
PHP_METHOD(Phalcon_Model_Message, getMessage);
PHP_METHOD(Phalcon_Model_Message, setField);
PHP_METHOD(Phalcon_Model_Message, getField);
PHP_METHOD(Phalcon_Model_Message, __toString);
PHP_METHOD(Phalcon_Model_Message, __set_state);

PHP_METHOD(Phalcon_Model_Manager, __construct);
PHP_METHOD(Phalcon_Model_Manager, setMetaData);
PHP_METHOD(Phalcon_Model_Manager, getMetaData);
PHP_METHOD(Phalcon_Model_Manager, setModelsDir);
PHP_METHOD(Phalcon_Model_Manager, getModelsDir);
PHP_METHOD(Phalcon_Model_Manager, isModel);
PHP_METHOD(Phalcon_Model_Manager, load);
PHP_METHOD(Phalcon_Model_Manager, getModel);
PHP_METHOD(Phalcon_Model_Manager, getSource);
PHP_METHOD(Phalcon_Model_Manager, getConnection);
PHP_METHOD(Phalcon_Model_Manager, addHasOne);
PHP_METHOD(Phalcon_Model_Manager, addBelongsTo);
PHP_METHOD(Phalcon_Model_Manager, addHasMany);
PHP_METHOD(Phalcon_Model_Manager, existsBelongsTo);
PHP_METHOD(Phalcon_Model_Manager, existsHasMany);
PHP_METHOD(Phalcon_Model_Manager, existsHasOne);
PHP_METHOD(Phalcon_Model_Manager, _getRelationRecords);
PHP_METHOD(Phalcon_Model_Manager, getBelongsToRecords);
PHP_METHOD(Phalcon_Model_Manager, getHasManyRecords);
PHP_METHOD(Phalcon_Model_Manager, getHasOneRecords);
PHP_METHOD(Phalcon_Model_Manager, autoload);

PHP_METHOD(Phalcon_Model_MetaData, __construct);
PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData);
PHP_METHOD(Phalcon_Model_MetaData, getAttributes);
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes);
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes);
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric);

PHP_METHOD(Phalcon_Model_Row, __construct);
PHP_METHOD(Phalcon_Model_Row, setConnection);
PHP_METHOD(Phalcon_Model_Row, getConnection);
PHP_METHOD(Phalcon_Model_Row, dumpResult);
PHP_METHOD(Phalcon_Model_Row, readAttribute);
PHP_METHOD(Phalcon_Model_Row, sleep);

PHP_METHOD(Phalcon_Model_Base, __construct);
PHP_METHOD(Phalcon_Model_Base, _connect);
PHP_METHOD(Phalcon_Model_Base, _getAttributes);
PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes);
PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric);
PHP_METHOD(Phalcon_Model_Base, _getDataTypes);
PHP_METHOD(Phalcon_Model_Base, dump);
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti);
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne);
PHP_METHOD(Phalcon_Model_Base, _createResultset);
PHP_METHOD(Phalcon_Model_Base, setManager);
PHP_METHOD(Phalcon_Model_Base, getManager);
PHP_METHOD(Phalcon_Model_Base, setTransaction);
PHP_METHOD(Phalcon_Model_Base, isView);
PHP_METHOD(Phalcon_Model_Base, setSource);
PHP_METHOD(Phalcon_Model_Base, getSource);
PHP_METHOD(Phalcon_Model_Base, setSchema);
PHP_METHOD(Phalcon_Model_Base, getSchema);
PHP_METHOD(Phalcon_Model_Base, setConnection);
PHP_METHOD(Phalcon_Model_Base, getConnection);
PHP_METHOD(Phalcon_Model_Base, dumpResult);
PHP_METHOD(Phalcon_Model_Base, find);
PHP_METHOD(Phalcon_Model_Base, findFirst);
PHP_METHOD(Phalcon_Model_Base, exists);
PHP_METHOD(Phalcon_Model_Base, _exists);
PHP_METHOD(Phalcon_Model_Base, _getGroupResult);
PHP_METHOD(Phalcon_Model_Base, count);
PHP_METHOD(Phalcon_Model_Base, _callEvent);
PHP_METHOD(Phalcon_Model_Base, _cancelOperation);
PHP_METHOD(Phalcon_Model_Base, appendMessage);
PHP_METHOD(Phalcon_Model_Base, getMessages);
PHP_METHOD(Phalcon_Model_Base, save);
PHP_METHOD(Phalcon_Model_Base, delete);
PHP_METHOD(Phalcon_Model_Base, readAttribute);
PHP_METHOD(Phalcon_Model_Base, writeAttribute);
PHP_METHOD(Phalcon_Model_Base, hasOne);
PHP_METHOD(Phalcon_Model_Base, belongsTo);
PHP_METHOD(Phalcon_Model_Base, hasMany);
PHP_METHOD(Phalcon_Model_Base, __call);


PHP_METHOD(Phalcon_Model_Resultset, __construct);
PHP_METHOD(Phalcon_Model_Resultset, valid);
PHP_METHOD(Phalcon_Model_Resultset, current);
PHP_METHOD(Phalcon_Model_Resultset, next);
PHP_METHOD(Phalcon_Model_Resultset, key);
PHP_METHOD(Phalcon_Model_Resultset, rewind);
PHP_METHOD(Phalcon_Model_Resultset, seek);
PHP_METHOD(Phalcon_Model_Resultset, count);
PHP_METHOD(Phalcon_Model_Resultset, offsetExists);
PHP_METHOD(Phalcon_Model_Resultset, offsetGet);
PHP_METHOD(Phalcon_Model_Resultset, offsetSet);
PHP_METHOD(Phalcon_Model_Resultset, offsetUnset);
PHP_METHOD(Phalcon_Model_Resultset, getFirst);
PHP_METHOD(Phalcon_Model_Resultset, getLast);
PHP_METHOD(Phalcon_Model_Resultset, getModel);



PHP_METHOD(Phalcon_Tag, setDispatcher);
PHP_METHOD(Phalcon_Tag, _getDispatcher);
PHP_METHOD(Phalcon_Tag, displayTo);
PHP_METHOD(Phalcon_Tag, _getValueFromAction);
PHP_METHOD(Phalcon_Tag, linkTo);
PHP_METHOD(Phalcon_Tag, textField);
PHP_METHOD(Phalcon_Tag, submitButton);
PHP_METHOD(Phalcon_Tag, selectStatic);
PHP_METHOD(Phalcon_Tag, select);
PHP_METHOD(Phalcon_Tag, textArea);
PHP_METHOD(Phalcon_Tag, form);
PHP_METHOD(Phalcon_Tag, endForm);
PHP_METHOD(Phalcon_Tag, setTitle);
PHP_METHOD(Phalcon_Tag, appendTitle);
PHP_METHOD(Phalcon_Tag, prependTitle);
PHP_METHOD(Phalcon_Tag, getTitle);
PHP_METHOD(Phalcon_Tag, stylesheetLink);
PHP_METHOD(Phalcon_Tag, image);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setcontrollersdir, 0, 0, 1)
	ZEND_ARG_INFO(0, controllersDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, request)
	ZEND_ARG_INFO(0, response)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_request_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_request_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_request_getquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_request_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_request_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setdatabaseconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, database)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setcontrollersdir, 0, 0, 1)
	ZEND_ARG_INFO(0, controllersDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setmodelsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, modelsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setrouter, 0, 0, 1)
	ZEND_ARG_INFO(0, router)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setdispatcher, 0, 0, 1)
	ZEND_ARG_INFO(0, dispatcher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setmodelcomponent, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller_front_setviewcomponent, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_url, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_view_path, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_test_nice, 0, 0, 1)
	ZEND_ARG_INFO(0, word)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_geturl, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_getlocalpath, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_setlogger, 0, 0, 1)
	ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_log, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, automaticQuotes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, automaticQuotes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_setundertransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, underTransaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_getconnectionid, 0, 0, 0)
	ZEND_ARG_INFO(0, asString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_factory, 0, 0, 2)
	ZEND_ARG_INFO(0, adapterName)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, persistent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_e6, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_e7, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_e14, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o1, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o2, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o3, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o4, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o5, 0, 0, 2)
	ZEND_ARG_INFO(0, num1)
	ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o6, 0, 0, 2)
	ZEND_ARG_INFO(0, num1)
	ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o7, 0, 0, 2)
	ZEND_ARG_INFO(0, num1)
	ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o8, 0, 0, 2)
	ZEND_ARG_INFO(0, num1)
	ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o9, 0, 0, 2)
	ZEND_ARG_INFO(0, num1)
	ZEND_ARG_INFO(0, num2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_o20, 0, 0, 1)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_a24, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_c11, 0, 0, 3)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m6, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m7, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m8, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m9, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m10, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m11, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m12, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m13, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m14, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_m15, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_mp4, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_mp6, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sm6, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sm7, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sm8, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sm9, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sm10, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_smp4, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_smp5, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_p14, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_p22, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_p23, 0, 0, 1)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sp9, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sp10, 0, 0, 3)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_sp11, 0, 0, 3)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t1, 0, 0, 2)
	ZEND_ARG_INFO(0, k)
	ZEND_ARG_INFO(0, a)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t3, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t4, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t5, 0, 0, 3)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t6, 0, 0, 3)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t7, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t8, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_test_t12, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testtemp_e14, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testdummy___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, p1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testdummy_f1, 0, 0, 1)
	ZEND_ARG_INFO(0, p1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testparent_mp2, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testparent_smp3, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_internal_testparent_smp6, 0, 0, 4)
	ZEND_ARG_INFO(0, o)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_exception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_router_rewrite_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_exception___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, showTrace)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
	ZEND_ARG_INFO(0, persistent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
	ZEND_ARG_INFO(0, persistent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_fetcharray, 0, 0, 0)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_numrows, 0, 0, 0)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_affectedrows, 0, 0, 0)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_error, 0, 0, 0)
	ZEND_ARG_INFO(0, errorString)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_noerror, 0, 0, 0)
	ZEND_ARG_INFO(0, resultQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, primaryKey)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_describetable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_mysql_getdateusingformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_pool_setdefaultdescriptor, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_pool_getconnection, 0, 0, 0)
	ZEND_ARG_INFO(0, newConnection)
	ZEND_ARG_INFO(0, renovate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describetable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash__showmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, classes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, arrayConfig)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter__sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_exception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, errorCode)
	ZEND_ARG_INFO(0, showTrace)
	ZEND_ARG_INFO(0, backtrace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_setdependencypointer, 0, 0, 1)
	ZEND_ARG_INFO(0, pointer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_attachdependency, 0, 0, 2)
	ZEND_ARG_INFO(0, pointer)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_failed___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_manager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_manager_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_manager_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_manager_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_transaction_manager__collecttransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_start, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_exception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, dispatcher)
	ZEND_ARG_INFO(0, request)
	ZEND_ARG_INFO(0, response)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller__forward, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_controller___get, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_message___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_setmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, metadata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_setmodelsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, modelsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_ismodel, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_load, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_getmodel, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_getsource, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_addhasone, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_addbelongsto, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_addhasmany, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager__getrelationrecords, 0, 0, 3)
	ZEND_ARG_INFO(0, relation)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_manager_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata__initializemetadata, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getdatatypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_metadata_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_row_setconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_row_dumpresult, 0, 0, 1)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_row_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__createsqlselectmulti, 0, 0, 4)
	ZEND_ARG_INFO(0, manager)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__createsqlselectone, 0, 0, 4)
	ZEND_ARG_INFO(0, manager)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, select)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__createresultset, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, select)
	ZEND_ARG_INFO(0, resultResource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_setmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_settransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_setschema, 0, 0, 1)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_setconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_dumpresult, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_find, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, wherePk)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__exists, 0, 0, 0)
	ZEND_ARG_INFO(0, wherePk)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__getgroupresult, 0, 0, 4)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, selectStatement)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_count, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base__callevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_hasone, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_belongsto, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base_hasmany, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_base___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, resultResource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_model_resultset_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdispatcher, 0, 0, 1)
	ZEND_ARG_INFO(0, dispatcher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_displayto, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag__getvaluefromaction, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_linkto, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textfield, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_submitbutton, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_selectstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textarea, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_form, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_stylesheetlink, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_image, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

static const function_entry phalcon_dispatcher_functions[] = {
	PHP_ME(Phalcon_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Dispatcher, setControllersDir, arginfo_phalcon_dispatcher_setcontrollersdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getControllersDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setBasePath, arginfo_phalcon_dispatcher_setbasepath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getBasePath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setControllerName, arginfo_phalcon_dispatcher_setcontrollername, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setActionName, arginfo_phalcon_dispatcher_setactionname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setParams, arginfo_phalcon_dispatcher_setparams, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, dispatch, arginfo_phalcon_dispatcher_dispatch, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, forward, arginfo_phalcon_dispatcher_forward, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getControllers, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getLastController, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_response_functions[] = {
	PHP_ME(Phalcon_Response, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Response, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_request_functions[] = {
	PHP_ME(Phalcon_Request, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Request, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Request, setFilter, arginfo_phalcon_request_setfilter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getFilter, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Request, getPost, arginfo_phalcon_request_getpost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getQuery, arginfo_phalcon_request_getquery, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getServer, arginfo_phalcon_request_getserver, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getHeader, arginfo_phalcon_request_getheader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getScheme, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isAjax, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isSoapRequested, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isSecureRequest, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getRawBody, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getServerAddress, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getServerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getHttpHost, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getClientAddress, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getMethod, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isPost, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isGet, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isPut, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isHead, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isDelete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, isOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, hasFiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getUploadedFiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getHTTPReferer, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getAcceptableContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getBestQualityAccept, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getClientCharsets, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Request, getBestQualityCharset, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_controller_front_functions[] = {
	PHP_ME(Phalcon_Controller_Front, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Controller_Front, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Controller_Front, setConfig, arginfo_phalcon_controller_front_setconfig, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setDatabaseConfig, arginfo_phalcon_controller_front_setdatabaseconfig, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setControllersDir, arginfo_phalcon_controller_front_setcontrollersdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setModelsDir, arginfo_phalcon_controller_front_setmodelsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setViewsDir, arginfo_phalcon_controller_front_setviewsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setRouter, arginfo_phalcon_controller_front_setrouter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getRouter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setDispatcher, arginfo_phalcon_controller_front_setdispatcher, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getDispatcher, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setBaseUri, arginfo_phalcon_controller_front_setbaseuri, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getBaseUri, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setBasePath, arginfo_phalcon_controller_front_setbasepath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getBasePath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setRequest, arginfo_phalcon_controller_front_setrequest, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setResponse, arginfo_phalcon_controller_front_setresponse, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setModelComponent, arginfo_phalcon_controller_front_setmodelcomponent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getModelComponent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, setViewComponent, arginfo_phalcon_controller_front_setviewcomponent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, getViewComponent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Controller_Front, dispatchLoop, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_view_functions[] = {
	PHP_ME(Phalcon_View, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_View, setViewsDir, arginfo_phalcon_view_setviewsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, getViewsDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, setTemplateBefore, arginfo_phalcon_view_settemplatebefore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, setTemplateAfter, arginfo_phalcon_view_settemplateafter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, setParamToView, arginfo_phalcon_view_setparamtoview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, getParamsToView, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, render, arginfo_phalcon_view_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, finish, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, url, arginfo_phalcon_view_url, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_View, path, arginfo_phalcon_view_path, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_test_functions[] = {
	PHP_ME(Phalcon_Test, nice, arginfo_phalcon_test_nice, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_utils_functions[] = {
	PHP_ME(Phalcon_Utils, camelize, arginfo_phalcon_utils_camelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils, uncamelize, arginfo_phalcon_utils_uncamelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils, getUrl, arginfo_phalcon_utils_geturl, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Utils, getLocalPath, arginfo_phalcon_utils_getlocalpath, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_functions[] = {
	PHP_ME(Phalcon_Db, __construct, arginfo_phalcon_db___construct, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db, setLogger, arginfo_phalcon_db_setlogger, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, log, arginfo_phalcon_db_log, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Db, fetchOne, arginfo_phalcon_db_fetchone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, fetchAll, arginfo_phalcon_db_fetchall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, insert, arginfo_phalcon_db_insert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, update, arginfo_phalcon_db_update, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, delete, arginfo_phalcon_db_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, rollback, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, setUnderTransaction, arginfo_phalcon_db_setundertransaction, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Db, isUnderTransaction, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getHaveAutoCommit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getDatabaseName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getDefaultSchema, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getUsername, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getHostName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, getConnectionId, arginfo_phalcon_db_getconnectionid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db, factory, arginfo_phalcon_db_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_internal_test_functions[] = {
	PHP_ME(Phalcon_Internal_Test, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Internal_Test, e1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e6, arginfo_phalcon_internal_test_e6, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e7, arginfo_phalcon_internal_test_e7, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e13, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, e14, arginfo_phalcon_internal_test_e14, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o1, arginfo_phalcon_internal_test_o1, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o2, arginfo_phalcon_internal_test_o2, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o3, arginfo_phalcon_internal_test_o3, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o4, arginfo_phalcon_internal_test_o4, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o5, arginfo_phalcon_internal_test_o5, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o6, arginfo_phalcon_internal_test_o6, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o7, arginfo_phalcon_internal_test_o7, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o8, arginfo_phalcon_internal_test_o8, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o9, arginfo_phalcon_internal_test_o9, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o11, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o12, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o13, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o14, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o15, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o16, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o17, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o18, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o19, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o20, arginfo_phalcon_internal_test_o20, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o21, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o22, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, o23, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a0, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a11, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a12, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a13, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a14, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a15, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a16, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a17, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a18, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a19, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a20, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a21, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a22, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a23, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a24, arginfo_phalcon_internal_test_a24, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, a25, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa0, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sa7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c8, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, c11, arginfo_phalcon_internal_test_c11, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f8, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, f10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m1, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, m2, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Internal_Test, m3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m6, arginfo_phalcon_internal_test_m6, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, m7, arginfo_phalcon_internal_test_m7, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m8, arginfo_phalcon_internal_test_m8, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m9, arginfo_phalcon_internal_test_m9, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, m10, arginfo_phalcon_internal_test_m10, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Internal_Test, m11, arginfo_phalcon_internal_test_m11, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m12, arginfo_phalcon_internal_test_m12, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m13, arginfo_phalcon_internal_test_m13, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, m14, arginfo_phalcon_internal_test_m14, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, m15, arginfo_phalcon_internal_test_m15, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, mp3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, mp4, arginfo_phalcon_internal_test_mp4, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, mp5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, mp6, arginfo_phalcon_internal_test_mp6, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sm1, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm2, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm3, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm4, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm5, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm6, arginfo_phalcon_internal_test_sm6, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm7, arginfo_phalcon_internal_test_sm7, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm8, arginfo_phalcon_internal_test_sm8, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm9, arginfo_phalcon_internal_test_sm9, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm10, arginfo_phalcon_internal_test_sm10, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, sm11, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, smp2, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, smp4, arginfo_phalcon_internal_test_smp4, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, smp5, arginfo_phalcon_internal_test_smp5, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_Test, p1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p8, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p11, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p12, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p13, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p14, arginfo_phalcon_internal_test_p14, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, p15, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p16, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, p17, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p18, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p19, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p20, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p21, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p22, arginfo_phalcon_internal_test_p22, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p23, arginfo_phalcon_internal_test_p23, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p24, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p25, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p26, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p27, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p28, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p29, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p30, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, p31, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp8, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp9, arginfo_phalcon_internal_test_sp9, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp10, arginfo_phalcon_internal_test_sp10, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, sp11, arginfo_phalcon_internal_test_sp11, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, cc6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is4, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is5, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is6, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is8, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is11, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, is12, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, un1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, un2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, un3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, iof1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, iof2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, iof3, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t1, arginfo_phalcon_internal_test_t1, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, t2, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t3, arginfo_phalcon_internal_test_t3, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Internal_Test, t4, arginfo_phalcon_internal_test_t4, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Internal_Test, t5, arginfo_phalcon_internal_test_t5, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t6, arginfo_phalcon_internal_test_t6, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t7, arginfo_phalcon_internal_test_t7, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t8, arginfo_phalcon_internal_test_t8, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t9, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t10, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t11, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_Test, t12, arginfo_phalcon_internal_test_t12, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_internal_testtemp_functions[] = {
	PHP_ME(Phalcon_Internal_TestTemp, e5a, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e9a, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e10a, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e13a, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e13b, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e13c, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e13d, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestTemp, e14, arginfo_phalcon_internal_testtemp_e14, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_internal_testdummy_functions[] = {
	PHP_ME(Phalcon_Internal_TestDummy, __construct, arginfo_phalcon_internal_testdummy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Internal_TestDummy, f1, arginfo_phalcon_internal_testdummy_f1, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_internal_testparent_functions[] = {
	PHP_ME(Phalcon_Internal_TestParent, mp1, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestParent, mp2, arginfo_phalcon_internal_testparent_mp2, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestParent, mp7, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Internal_TestParent, smp1, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_TestParent, smp3, arginfo_phalcon_internal_testparent_smp3, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Internal_TestParent, smp6, arginfo_phalcon_internal_testparent_smp6, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_tag_exception_functions[] = {
	PHP_ME(Phalcon_Tag_Exception, __construct, arginfo_phalcon_tag_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_router_rewrite_functions[] = {
	PHP_ME(Phalcon_Router_Rewrite, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Router_Rewrite, _getRewriteUri, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Router_Rewrite, setBaseUri, arginfo_phalcon_router_rewrite_setbaseuri, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Router_Rewrite, handle, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Router_Rewrite, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Router_Rewrite, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Router_Rewrite, getParams, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_exception_functions[] = {
	PHP_ME(Phalcon_Db_Exception, __construct, arginfo_phalcon_db_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_mysql_functions[] = {
	PHP_ME(Phalcon_Db_Mysql, __construct, arginfo_phalcon_db_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Mysql, connect, arginfo_phalcon_db_mysql_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, query, arginfo_phalcon_db_mysql_query, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, fetchArray, arginfo_phalcon_db_mysql_fetcharray, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, numRows, arginfo_phalcon_db_mysql_numrows, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, dataSeek, arginfo_phalcon_db_mysql_dataseek, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, affectedRows, arginfo_phalcon_db_mysql_affectedrows, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, setFetchMode, arginfo_phalcon_db_mysql_setfetchmode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, error, arginfo_phalcon_db_mysql_error, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, noError, arginfo_phalcon_db_mysql_noerror, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, lastInsertId, arginfo_phalcon_db_mysql_lastinsertid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, limit, arginfo_phalcon_db_mysql_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, tableExists, arginfo_phalcon_db_mysql_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, viewExists, arginfo_phalcon_db_mysql_viewexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, describeTable, arginfo_phalcon_db_mysql_describetable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Mysql, getDateUsingFormat, arginfo_phalcon_db_mysql_getdateusingformat, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_pool_functions[] = {
	PHP_ME(Phalcon_Db_Pool, hasDefaultDescriptor, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Db_Pool, setDefaultDescriptor, arginfo_phalcon_db_pool_setdefaultdescriptor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Db_Pool, getConnection, arginfo_phalcon_db_pool_getconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_dialect_mysql_functions[] = {
	PHP_ME(Phalcon_Db_Dialect_Mysql, tableExists, arginfo_phalcon_db_dialect_mysql_tableexists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeTable, arginfo_phalcon_db_dialect_mysql_describetable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_db_rawvalue_functions[] = {
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_flash_functions[] = {
	PHP_ME(Phalcon_Flash, _showMessage, arginfo_phalcon_flash__showmessage, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flash_error, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flash_notice, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flash_success, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flash_warning, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_logger_functions[] = {
	PHP_ME(Phalcon_Logger, __construct, arginfo_phalcon_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger, setFormat, arginfo_phalcon_logger_setformat, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_config_functions[] = {
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_filter_functions[] = {
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filter_sanitize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Filter, _sanitize, arginfo_phalcon_filter__sanitize, ZEND_ACC_PRIVATE) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_exception_functions[] = {
	PHP_ME(Phalcon_Exception, __construct, arginfo_phalcon_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_transaction_functions[] = {
	PHP_ME(Phalcon_Transaction, __construct, arginfo_phalcon_transaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Transaction, setTransactionManager, arginfo_phalcon_transaction_settransactionmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, rollback, arginfo_phalcon_transaction_rollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, setIsNewTransaction, arginfo_phalcon_transaction_setisnewtransaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, setRollbackOnAbort, arginfo_phalcon_transaction_setrollbackonabort, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, isManaged, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, setDependencyPointer, arginfo_phalcon_transaction_setdependencypointer, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, attachDependency, arginfo_phalcon_transaction_attachdependency, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, save, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, isValid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction, setRollbackedRecord, arginfo_phalcon_transaction_setrollbackedrecord, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_transaction_failed_functions[] = {
	PHP_ME(Phalcon_Transaction_Failed, __construct, arginfo_phalcon_transaction_failed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Transaction_Failed, getRecordMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Transaction_Failed, getRecord, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_transaction_manager_functions[] = {
	PHP_ME(Phalcon_Transaction_Manager, has, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, get, arginfo_phalcon_transaction_manager_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, rollbackPendent, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, commit, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, rollback, arginfo_phalcon_transaction_manager_rollback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, notifyRollback, arginfo_phalcon_transaction_manager_notifyrollback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, notifyCommit, arginfo_phalcon_transaction_manager_notifycommit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, _collectTransaction, arginfo_phalcon_transaction_manager__collecttransaction, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, collectTransactions, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, isAutomatic, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Transaction_Manager, getAutomatic, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_session_functions[] = {
	PHP_ME(Phalcon_Session, start, arginfo_phalcon_session_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Session, setOptions, arginfo_phalcon_session_setoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Session, get, arginfo_phalcon_session_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session, set, arginfo_phalcon_session_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session, getId, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_config_adapter_ini_functions[] = {
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_config_exception_functions[] = {
	PHP_ME(Phalcon_Config_Exception, __construct, arginfo_phalcon_config_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_controller_functions[] = {
	PHP_ME(Phalcon_Controller, __construct, arginfo_phalcon_controller___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Controller, _forward, arginfo_phalcon_controller__forward, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Controller, __get, arginfo_phalcon_controller___get, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_message_functions[] = {
	PHP_ME(Phalcon_Model_Message, __construct, arginfo_phalcon_model_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_Message, setType, arginfo_phalcon_model_message_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, setMessage, arginfo_phalcon_model_message_setmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, getMessage, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, setField, arginfo_phalcon_model_message_setfield, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, getField, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Message, __set_state, arginfo_phalcon_model_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_manager_functions[] = {
	PHP_ME(Phalcon_Model_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_Manager, setMetaData, arginfo_phalcon_model_manager_setmetadata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getMetaData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, setModelsDir, arginfo_phalcon_model_manager_setmodelsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getModelsDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, isModel, arginfo_phalcon_model_manager_ismodel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, load, arginfo_phalcon_model_manager_load, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getModel, arginfo_phalcon_model_manager_getmodel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getSource, arginfo_phalcon_model_manager_getsource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, addHasOne, arginfo_phalcon_model_manager_addhasone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, addBelongsTo, arginfo_phalcon_model_manager_addbelongsto, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, addHasMany, arginfo_phalcon_model_manager_addhasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, existsBelongsTo, arginfo_phalcon_model_manager_existsbelongsto, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, existsHasMany, arginfo_phalcon_model_manager_existshasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, existsHasOne, arginfo_phalcon_model_manager_existshasone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, _getRelationRecords, arginfo_phalcon_model_manager__getrelationrecords, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Manager, getBelongsToRecords, arginfo_phalcon_model_manager_getbelongstorecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getHasManyRecords, arginfo_phalcon_model_manager_gethasmanyrecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, getHasOneRecords, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Manager, autoload, arginfo_phalcon_model_manager_autoload, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_metadata_functions[] = {
	PHP_ME(Phalcon_Model_MetaData, __construct, arginfo_phalcon_model_metadata___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_MetaData, _initializeMetaData, arginfo_phalcon_model_metadata__initializemetadata, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_MetaData, getAttributes, arginfo_phalcon_model_metadata_getattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_MetaData, getPrimaryKeyAttributes, arginfo_phalcon_model_metadata_getprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes, arginfo_phalcon_model_metadata_getnonprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_MetaData, getNotNullAttributes, arginfo_phalcon_model_metadata_getnotnullattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_MetaData, getDataTypes, arginfo_phalcon_model_metadata_getdatatypes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_MetaData, getDataTypesNumeric, arginfo_phalcon_model_metadata_getdatatypesnumeric, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_row_functions[] = {
	PHP_ME(Phalcon_Model_Row, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_Row, setConnection, arginfo_phalcon_model_row_setconnection, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Row, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Row, dumpResult, arginfo_phalcon_model_row_dumpresult, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Row, readAttribute, arginfo_phalcon_model_row_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Row, sleep, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_base_functions[] = {
	PHP_ME(Phalcon_Model_Base, __construct, arginfo_phalcon_model_base___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_Base, _connect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, _getAttributes, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getPrimaryKeyAttributes, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getNonPrimaryKeyAttributes, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getNotNullAttributes, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getDataTypesNumeric, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getDataTypes, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, dump, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, _createSQLSelectMulti, arginfo_phalcon_model_base__createsqlselectmulti, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, _createSQLSelectOne, arginfo_phalcon_model_base__createsqlselectone, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, _createResultset, arginfo_phalcon_model_base__createresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, setManager, arginfo_phalcon_model_base_setmanager, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, getManager, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, setTransaction, arginfo_phalcon_model_base_settransaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, isView, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, setSource, arginfo_phalcon_model_base_setsource, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, setSchema, arginfo_phalcon_model_base_setschema, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, getSchema, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, setConnection, arginfo_phalcon_model_base_setconnection, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, dumpResult, arginfo_phalcon_model_base_dumpresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, find, arginfo_phalcon_model_base_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, findFirst, arginfo_phalcon_model_base_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, exists, arginfo_phalcon_model_base_exists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, _exists, arginfo_phalcon_model_base__exists, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _getGroupResult, arginfo_phalcon_model_base__getgroupresult, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, count, arginfo_phalcon_model_base_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Model_Base, _callEvent, arginfo_phalcon_model_base__callevent, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, _cancelOperation, NULL, ZEND_ACC_PRIVATE) 
	PHP_ME(Phalcon_Model_Base, appendMessage, arginfo_phalcon_model_base_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, save, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, readAttribute, arginfo_phalcon_model_base_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, writeAttribute, arginfo_phalcon_model_base_writeattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Base, hasOne, arginfo_phalcon_model_base_hasone, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, belongsTo, arginfo_phalcon_model_base_belongsto, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, hasMany, arginfo_phalcon_model_base_hasmany, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Model_Base, __call, arginfo_phalcon_model_base___call, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_metadata_memory_functions[] = {
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_resultset_functions[] = {
	PHP_ME(Phalcon_Model_Resultset, __construct, arginfo_phalcon_model_resultset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Model_Resultset, valid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, current, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, next, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, key, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, rewind, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, seek, arginfo_phalcon_model_resultset_seek, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, count, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, offsetExists, arginfo_phalcon_model_resultset_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, offsetGet, arginfo_phalcon_model_resultset_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, offsetSet, arginfo_phalcon_model_resultset_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, offsetUnset, arginfo_phalcon_model_resultset_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, getLast, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Model_Resultset, getModel, NULL, ZEND_ACC_PUBLIC) 
	{NULL, NULL, NULL}
};

static const function_entry phalcon_model_exception_functions[] = {
	{NULL, NULL, NULL}
};

static const function_entry phalcon_view_exception_functions[] = {
	{NULL, NULL, NULL}
};

static const function_entry phalcon_tag_functions[] = {
	PHP_ME(Phalcon_Tag, setDispatcher, arginfo_phalcon_tag_setdispatcher, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, _getDispatcher, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, displayTo, arginfo_phalcon_tag_displayto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, _getValueFromAction, arginfo_phalcon_tag__getvaluefromaction, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_textfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_submitbutton, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getTitle, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	{NULL, NULL, NULL}
};

static function_entry main_functions[] = {
        {NULL, NULL, NULL}
};

