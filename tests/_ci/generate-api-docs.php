<?php
declare(strict_types=1);

$baseDir   = dirname(dirname(dirname(__FILE__)));
$sourceDir = $baseDir . '/phalcon/';
$outputDir = $baseDir . '/nikos/api/';

if (!is_dir($outputDir)) {
    mkdir($outputDir, 0777, true);
}


//$results = [];
//$classes = get_declared_classes();
//foreach ($classes as $class) {
//    if ('Phalcon\\' === substr($class, 0, 8)) {
//        $results[] = $class;
//    }
//}
//
//$classes = get_declared_interfaces();
//foreach ($classes as $class) {
//    if ('Phalcon\\' === substr($class, 0, 8)) {
//        $results[] = $class;
//    }
//}
//asort($results);
//foreach ($results as $class) {
//    echo $class . PHP_EOL;
//}
//die();


$documents = [
    [
        'title' => 'Phalcon\Acl',
        'docs'  => [
            'Acl'                    => 'Acl.zep',
            'Acl_Adapter'            => 'Acl/Adapter.zep',
            'Acl_AdapterInterface'   => 'Acl/AdapterInterface.zep',
            'Acl_Adapter_Memory'     => 'Acl/Adapter/Memory.zep',
            'Acl_Component'          => 'Acl/Component.zep',
            'Acl_ComponentAware'     => 'Acl/ComponentAware.zep',
            'Acl_ComponentInterface' => 'Acl/ComponentInterface.zep',
            'Acl_Exception'          => 'Acl/Exception.zep',
            'Acl_Role'               => 'Acl/Role.zep',
            'Acl_RoleAware'          => 'Acl/RoleAware.zep',
            'Acl_RoleInterface'      => 'Acl/RoleInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Annotations',
        'docs'   => [
            'Annotations_Adapter_AbstractAdapter'             => 'Annotations/Adapter/AbstractAdapter.zep',
            'Annotations_Adapter_AdapterInterface'            => 'Annotations/Adapter/AdapterInterface.zep',
            'Annotations_Adapter_Apcu'                        => 'Annotations/Adapter/Apcu.zep',
            'Annotations_Adapter_Memory'                      => 'Annotations/Adapter/Memory.zep',
            'Annotations_Adapter_Stream'                      => 'Annotations/Adapter/Stream.zep',
            'Annotations_Annotation'                          => 'Annotations/Annotation.zep',
            'Annotations_AnnotationsFactory'                  => 'Annotations/AnnotationsFactory.zep',
            'Annotations_Collection'                          => 'Annotations/Collection.zep',
            'Annotations_Exception'                           => 'Annotations/Exception.zep',
            'Annotations_Reader'                              => 'Annotations/Reader.zep',
            'Annotations_ReaderInterface'                     => 'Annotations/ReaderInterface.zep',
            'Annotations_Reflection'                          => 'Annotations/Reflection.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Application',
        'docs'   => [
            'Application'                                     => 'Application.zep',
            'Application_Exception'                           => 'Application/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Assets',
        'docs'   => [
            'Assets_Asset'                                    => 'Assets/Asset.zep',
            'Assets_Asset_Css'                                => 'Assets/Asset/Css.zep',
            'Assets_Asset_Js'                                 => 'Assets/Asset/Js.zep',
            'Assets_AssetInterface'                           => 'Assets/AssetInterface.zep',
            'Assets_Collection'                               => 'Assets/Collection.zep',
            'Assets_Exception'                                => 'Assets/Exception.zep',
            'Assets_FilterInterface'                          => 'Assets/FilterInterface.zep',
            'Assets_Filters_CssMin'                           => 'Assets/Filters/CssMin.zep',
            'Assets_Filters_JsMin'                            => 'Assets/Filters/JsMin.zep',
            'Assets_Filters_None'                             => 'Assets/Filters/None.zep',
            'Assets_Inline'                                   => 'Assets/Inline.zep',
            'Assets_Inline_Css'                               => 'Assets/Inline/Css.zep',
            'Assets_Inline_Js'                                => 'Assets/Inline/Js.zep',
            'Assets_Manager'                                  => 'Assets/Manager.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Cache',
        'docs'   => [
            'Cache_Adapter_AdapterInterface'                  => 'Cache/Adapter/AdapterInterface.zep',
            'Cache_Adapter_Apcu'                              => 'Cache/Adapter/Apcu.zep',
            'Cache_Adapter_Libmemcached'                      => 'Cache/Adapter/Libmemcached.zep',
            'Cache_Adapter_Memory'                            => 'Cache/Adapter/Memory.zep',
            'Cache_Adapter_Redis'                             => 'Cache/Adapter/Redis.zep',
            'Cache_Adapter_Stream'                            => 'Cache/Adapter/Stream.zep',
            'Cache_AdapterFactory'                            => 'Cache/AdapterFactory.zep',
            'Cache_Cache'                                     => 'Cache/Cache.zep',
            'Cache_CacheFactory'                              => 'Cache/CacheFactory.zep',
            'Cache_Exception_Exception'                       => 'Cache/Exception/Exception.zep',
            'Cache_Exception_InvalidArgumentException'        => 'Cache/Exception/InvalidArgumentException.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Cli',
        'docs'   => [
            'Cli_Console'                                     => 'Cli/Console.zep',
            'Cli_Console_Exception'                           => 'Cli/Console/Exception.zep',
            'Cli_Dispatcher'                                  => 'Cli/Dispatcher.zep',
            'Cli_Dispatcher_Exception'                        => 'Cli/Dispatcher/Exception.zep',
            'Cli_DispatcherInterface'                         => 'Cli/DispatcherInterface.zep',
            'Cli_Router'                                      => 'Cli/Router.zep',
            'Cli_Router_Exception'                            => 'Cli/Router/Exception.zep',
            'Cli_Router_Route'                                => 'Cli/Router/Route.zep',
            'Cli_Router_RouteInterface'                       => 'Cli/Router/RouteInterface.zep',
            'Cli_RouterInterface'                             => 'Cli/RouterInterface.zep',
            'Cli_Task'                                        => 'Cli/Task.zep',
            'Cli_TaskInterface'                               => 'Cli/TaskInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Collection',
        'docs'   => [
            'Collection_Collection'                           => 'Collection/Collection.zep',
            'Collection_Exception'                            => 'Collection/Exception.zep',
            'Collection_ReadCollection'                       => 'Collection/ReadCollection.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Config',
        'docs'   => [
            'Config_Adapter_Grouped'                          => 'Config/Adapter/Grouped.zep',
            'Config_Adapter_Ini'                              => 'Config/Adapter/Ini.zep',
            'Config_Adapter_Json'                             => 'Config/Adapter/Json.zep',
            'Config_Adapter_Php'                              => 'Config/Adapter/Php.zep',
            'Config_Adapter_Yaml'                             => 'Config/Adapter/Yaml.zep',
            'Config_Config'                                   => 'Config/Config.zep',
            'Config_ConfigFactory'                            => 'Config/ConfigFactory.zep',
            'Config_Exception'                                => 'Config/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Container',
        'docs'   => [
            'Container'                                       => 'Container.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Crypt',
        'docs'   => [
            'Crypt'                                           => 'Crypt.zep',
            'Crypt_Exception'                                 => 'Crypt/Exception.zep',
            'Crypt_Mismatch'                                  => 'Crypt/Mismatch.zep',
            'CryptInterface'                                  => 'CryptInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Db',
        'docs'   => [
            'Db'                                              => 'Db.zep',
            'Db_Adapter'                                      => 'Db/Adapter.zep',
            'Db_Adapter_Pdo'                                  => 'Db/Adapter/Pdo.zep',
            'Db_Adapter_Pdo_Mysql'                            => 'Db/Adapter/Pdo/Mysql.zep',
            'Db_Adapter_Pdo_Postgresql'                       => 'Db/Adapter/Pdo/Postgresql.zep',
            'Db_Adapter_Pdo_Sqlite'                           => 'Db/Adapter/Pdo/Sqlite.zep',
            'Db_Adapter_PdoFactory'                           => 'Db/Adapter/PdoFactory.zep',
            'Db_AdapterInterface'                             => 'Db/AdapterInterface.zep',
            'Db_Column'                                       => 'Db/Column.zep',
            'Db_ColumnInterface'                              => 'Db/ColumnInterface.zep',
            'Db_Dialect'                                      => 'Db/Dialect.zep',
            'Db_Dialect_Mysql'                                => 'Db/Dialect/Mysql.zep',
            'Db_Dialect_Postgresql'                           => 'Db/Dialect/Postgresql.zep',
            'Db_Dialect_Sqlite'                               => 'Db/Dialect/Sqlite.zep',
            'Db_DialectInterface'                             => 'Db/DialectInterface.zep',
            'Db_Exception'                                    => 'Db/Exception.zep',
            'Db_Index'                                        => 'Db/Index.zep',
            'Db_IndexInterface'                               => 'Db/IndexInterface.zep',
            'Db_Profiler'                                     => 'Db/Profiler.zep',
            'Db_Profiler_Item'                                => 'Db/Profiler/Item.zep',
            'Db_RawValue'                                     => 'Db/RawValue.zep',
            'Db_Reference'                                    => 'Db/Reference.zep',
            'Db_ReferenceInterface'                           => 'Db/ReferenceInterface.zep',
            'Db_Result_Pdo'                                   => 'Db/Result/Pdo.zep',
            'Db_ResultInterface'                              => 'Db/ResultInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Debug',
        'docs'   => [
            'Debug'                                           => 'Debug.zep',
            'Debug_Dump'                                      => 'Debug/Dump.zep',
            'Debug_Exception'                                 => 'Debug/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Di',
        'docs'   => [
            'Di'                                              => 'Di.zep',
            'Di_Exception'                                    => 'Di/Exception.zep',
            'Di_Exception_ServiceResolutionException'         => 'Di/Exception/ServiceResolutionException.zep',
            'Di_FactoryDefault'                               => 'Di/FactoryDefault.zep',
            'Di_FactoryDefault_Cli'                           => 'Di/FactoryDefault/Cli.zep',
            'Di_Injectable'                                   => 'Di/Injectable.zep',
            'Di_InjectionAwareInterface'                      => 'Di/InjectionAwareInterface.zep',
            'Di_Service'                                      => 'Di/Service.zep',
            'Di_Service_Builder'                              => 'Di/Service/Builder.zep',
            'Di_ServiceInterface'                             => 'Di/ServiceInterface.zep',
            'Di_ServiceProviderInterface'                     => 'Di/ServiceProviderInterface.zep',
            'DiInterface'                                     => 'DiInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Dispatcher',
        'docs'   => [
            'Dispatcher'                                      => 'Dispatcher.zep',
            'DispatcherInterface'                             => 'DispatcherInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Domain',
        'docs'   => [
            'Domain_Payload_Payload'                          => 'Domain/Payload/Payload.zep',
            'Domain_Payload_PayloadFactory'                   => 'Domain/Payload/PayloadFactory.zep',
            'Domain_Payload_PayloadInterface'                 => 'Domain/Payload/PayloadInterface.zep',
            'Domain_Payload_ReadableInterface'                => 'Domain/Payload/ReadableInterface.zep',
            'Domain_Payload_Status'                           => 'Domain/Payload/Status.zep',
            'Domain_Payload_WriteableInterface'               => 'Domain/Payload/WriteableInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Escaper',
        'docs'   => [
            'Escaper'                                         => 'Escaper.zep',
            'Escaper_Exception'                               => 'Escaper/Exception.zep',
            'EscaperInterface'                                => 'EscaperInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Events',
        'docs'   => [
            'Events_Event'                                    => 'Events/Event.zep',
            'Events_EventInterface'                           => 'Events/EventInterface.zep',
            'Events_EventsAwareInterface'                     => 'Events/EventsAwareInterface.zep',
            'Events_Exception'                                => 'Events/Exception.zep',
            'Events_Manager'                                  => 'Events/Manager.zep',
            'Events_ManagerInterface'                         => 'Events/ManagerInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Exception',
        'docs'   => [
            'Exception'                                       => 'Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Factory',
        'docs'   => [
            'Factory_AbstractFactory'                         => 'Factory/AbstractFactory.zep',
            'Factory_Exception'                               => 'Factory/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Filter',
        'docs'   => [
            'Filter_Exception'                                => 'Filter/Exception.zep',
            'Filter_Filter'                                   => 'Filter/Filter.zep',
            'Filter_FilterFactory'                            => 'Filter/FilterFactory.zep',
            'Filter_FilterInterface'                          => 'Filter/FilterInterface.zep',
            'Filter_Sanitize_AbsInt'                          => 'Filter/Sanitize/AbsInt.zep',
            'Filter_Sanitize_Alnum'                           => 'Filter/Sanitize/Alnum.zep',
            'Filter_Sanitize_Alpha'                           => 'Filter/Sanitize/Alpha.zep',
            'Filter_Sanitize_BoolVal'                         => 'Filter/Sanitize/BoolVal.zep',
            'Filter_Sanitize_Email'                           => 'Filter/Sanitize/Email.zep',
            'Filter_Sanitize_FloatVal'                        => 'Filter/Sanitize/FloatVal.zep',
            'Filter_Sanitize_IntVal'                          => 'Filter/Sanitize/IntVal.zep',
            'Filter_Sanitize_Lower'                           => 'Filter/Sanitize/Lower.zep',
            'Filter_Sanitize_LowerFirst'                      => 'Filter/Sanitize/LowerFirst.zep',
            'Filter_Sanitize_Regex'                           => 'Filter/Sanitize/Regex.zep',
            'Filter_Sanitize_Remove'                          => 'Filter/Sanitize/Remove.zep',
            'Filter_Sanitize_Replace'                         => 'Filter/Sanitize/Replace.zep',
            'Filter_Sanitize_Special'                         => 'Filter/Sanitize/Special.zep',
            'Filter_Sanitize_SpecialFull'                     => 'Filter/Sanitize/SpecialFull.zep',
            'Filter_Sanitize_StringVal'                       => 'Filter/Sanitize/StringVal.zep',
            'Filter_Sanitize_Striptags'                       => 'Filter/Sanitize/Striptags.zep',
            'Filter_Sanitize_Trim'                            => 'Filter/Sanitize/Trim.zep',
            'Filter_Sanitize_Upper'                           => 'Filter/Sanitize/Upper.zep',
            'Filter_Sanitize_UpperFirst'                      => 'Filter/Sanitize/UpperFirst.zep',
            'Filter_Sanitize_UpperWords'                      => 'Filter/Sanitize/UpperWords.zep',
            'Filter_Sanitize_Url'                             => 'Filter/Sanitize/Url.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Firewall',
        'docs'   => [
            'Firewall_Adapter'                                => 'Firewall/Adapter.zep',
            'Firewall_Adapter_Acl'                            => 'Firewall/Adapter/Acl.zep',
            'Firewall_Adapter_Annotations'                    => 'Firewall/Adapter/Annotations.zep',
            'Firewall_Adapter_Micro_Acl'                      => 'Firewall/Adapter/Micro/Acl.zep',
            'Firewall_AdapterInterface'                       => 'Firewall/AdapterInterface.zep',
            'Firewall_Exception'                              => 'Firewall/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Flash',
        'docs'   => [
            'Flash'                                           => 'Flash.zep',
            'Flash_Direct'                                    => 'Flash/Direct.zep',
            'Flash_Exception'                                 => 'Flash/Exception.zep',
            'Flash_Session'                                   => 'Flash/Session.zep',
            'FlashInterface'                                  => 'FlashInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Forms',
        'docs'   => [
            'Forms_Element'                                   => 'Forms/Element.zep',
            'Forms_Element_Check'                             => 'Forms/Element/Check.zep',
            'Forms_Element_Date'                              => 'Forms/Element/Date.zep',
            'Forms_Element_Email'                             => 'Forms/Element/Email.zep',
            'Forms_Element_File'                              => 'Forms/Element/File.zep',
            'Forms_Element_Hidden'                            => 'Forms/Element/Hidden.zep',
            'Forms_Element_Numeric'                           => 'Forms/Element/Numeric.zep',
            'Forms_Element_Password'                          => 'Forms/Element/Password.zep',
            'Forms_Element_Radio'                             => 'Forms/Element/Radio.zep',
            'Forms_Element_Select'                            => 'Forms/Element/Select.zep',
            'Forms_Element_Submit'                            => 'Forms/Element/Submit.zep',
            'Forms_Element_Text'                              => 'Forms/Element/Text.zep',
            'Forms_Element_TextArea'                          => 'Forms/Element/TextArea.zep',
            'Forms_ElementInterface'                          => 'Forms/ElementInterface.zep',
            'Forms_Exception'                                 => 'Forms/Exception.zep',
            'Forms_Form'                                      => 'Forms/Form.zep',
            'Forms_Manager'                                   => 'Forms/Manager.zep',
            'Helper_Arr'                                      => 'Helper/Arr.zep',
            'Helper_Exception'                                => 'Helper/Exception.zep',
            'Helper_Number'                                   => 'Helper/Number.zep',
            'Helper_Str'                                      => 'Helper/Str.zep',
            'Html_Attributes'                                 => 'Html/Attributes.zep',
            'Html_Attributes_AttributesInterface'             => 'Html/Attributes/AttributesInterface.zep',
            'Html_Attributes_RenderInterface'                 => 'Html/Attributes/RenderInterface.zep',
            'Html_Breadcrumbs'                                => 'Html/Breadcrumbs.zep',
            'Html_Exception'                                  => 'Html/Exception.zep',
            'Html_Helper_AbstractHelper'                      => 'Html/Helper/AbstractHelper.zep',
            'Html_Helper_Anchor'                              => 'Html/Helper/Anchor.zep',
            'Html_Helper_AnchorRaw'                           => 'Html/Helper/AnchorRaw.zep',
            'Html_Helper_Body'                                => 'Html/Helper/Body.zep',
            'Html_Helper_Button'                              => 'Html/Helper/Button.zep',
            'Html_Helper_Close'                               => 'Html/Helper/Close.zep',
            'Html_Helper_Element'                             => 'Html/Helper/Element.zep',
            'Html_Helper_ElementRaw'                          => 'Html/Helper/ElementRaw.zep',
            'Html_Helper_Form'                                => 'Html/Helper/Form.zep',
            'Html_Helper_Img'                                 => 'Html/Helper/Img.zep',
            'Html_Helper_Label'                               => 'Html/Helper/Label.zep',
            'Html_Helper_TextArea'                            => 'Html/Helper/TextArea.zep',
            'Html_Tag'                                        => 'Html/Tag.zep',
            'Html_TagFactory'                                 => 'Html/TagFactory.zep',
            'Http_Cookie'                                     => 'Http/Cookie.zep',
            'Http_Cookie_Exception'                           => 'Http/Cookie/Exception.zep',
            'Http_CookieInterface'                            => 'Http/CookieInterface.zep',
            'Http_Message_AbstractCommon'                     => 'Http/Message/AbstractCommon.zep',
            'Http_Message_AbstractMessage'                    => 'Http/Message/AbstractMessage.zep',
            'Http_Message_AbstractRequest'                    => 'Http/Message/AbstractRequest.zep',
            'Http_Message_Exception_InvalidArgumentException' => 'Http/Message/Exception/InvalidArgumentException.zep',
            'Http_Message_Request'                            => 'Http/Message/Request.zep',
            'Http_Message_RequestFactory'                     => 'Http/Message/RequestFactory.zep',
            'Http_Message_Response'                           => 'Http/Message/Response.zep',
            'Http_Message_ResponseFactory'                    => 'Http/Message/ResponseFactory.zep',
            'Http_Message_ServerRequest'                      => 'Http/Message/ServerRequest.zep',
            'Http_Message_ServerRequestFactory'               => 'Http/Message/ServerRequestFactory.zep',
            'Http_Message_Stream'                             => 'Http/Message/Stream.zep',
            'Http_Message_Stream_Input'                       => 'Http/Message/Stream/Input.zep',
            'Http_Message_Stream_Memory'                      => 'Http/Message/Stream/Memory.zep',
            'Http_Message_Stream_Temp'                        => 'Http/Message/Stream/Temp.zep',
            'Http_Message_StreamFactory'                      => 'Http/Message/StreamFactory.zep',
            'Http_Message_UploadedFile'                       => 'Http/Message/UploadedFile.zep',
            'Http_Message_UploadedFileFactory'                => 'Http/Message/UploadedFileFactory.zep',
            'Http_Message_Uri'                                => 'Http/Message/Uri.zep',
            'Http_Message_UriFactory'                         => 'Http/Message/UriFactory.zep',
            'Http_Request'                                    => 'Http/Request.zep',
            'Http_Request_Exception'                          => 'Http/Request/Exception.zep',
            'Http_Request_File'                               => 'Http/Request/File.zep',
            'Http_Request_FileInterface'                      => 'Http/Request/FileInterface.zep',
            'Http_RequestInterface'                           => 'Http/RequestInterface.zep',
            'Http_Response'                                   => 'Http/Response.zep',
            'Http_Response_Cookies'                           => 'Http/Response/Cookies.zep',
            'Http_Response_CookiesInterface'                  => 'Http/Response/CookiesInterface.zep',
            'Http_Response_Exception'                         => 'Http/Response/Exception.zep',
            'Http_Response_Headers'                           => 'Http/Response/Headers.zep',
            'Http_Response_HeadersInterface'                  => 'Http/Response/HeadersInterface.zep',
            'Http_ResponseInterface'                          => 'Http/ResponseInterface.zep',
            'Http_Server_AbstractMiddleware'                  => 'Http/Server/AbstractMiddleware.zep',
            'Http_Server_AbstractRequestHandler'              => 'Http/Server/AbstractRequestHandler.zep',
            'Image'                                           => 'Image.zep',
            'Image_Adapter_AbstractAdapter'                   => 'Image/Adapter/AbstractAdapter.zep',
            'Image_Adapter_AdapterInterface'                  => 'Image/Adapter/AdapterInterface.zep',
            'Image_Adapter_Gd'                                => 'Image/Adapter/Gd.zep',
            'Image_Adapter_Imagick'                           => 'Image/Adapter/Imagick.zep',
            'Image_Exception'                                 => 'Image/Exception.zep',
            'Image_ImageFactory'                              => 'Image/ImageFactory.zep',
            'Kernel'                                          => 'Kernel.zep',
            'Loader'                                          => 'Loader.zep',
            'Loader_Exception'                                => 'Loader/Exception.zep',
            'Logger_Adapter_AbstractAdapter'                  => 'Logger/Adapter/AbstractAdapter.zep',
            'Logger_Adapter_AdapterInterface'                 => 'Logger/Adapter/AdapterInterface.zep',
            'Logger_Adapter_Noop'                             => 'Logger/Adapter/Noop.zep',
            'Logger_Adapter_Stream'                           => 'Logger/Adapter/Stream.zep',
            'Logger_Adapter_Syslog'                           => 'Logger/Adapter/Syslog.zep',
            'Logger_AdapterFactory'                           => 'Logger/AdapterFactory.zep',
            'Logger_Exception'                                => 'Logger/Exception.zep',
            'Logger_Formatter_AbstractFormatter'              => 'Logger/Formatter/AbstractFormatter.zep',
            'Logger_Formatter_FormatterInterface'             => 'Logger/Formatter/FormatterInterface.zep',
            'Logger_Formatter_Json'                           => 'Logger/Formatter/Json.zep',
            'Logger_Formatter_Line'                           => 'Logger/Formatter/Line.zep',
            'Logger_Formatter_Syslog'                         => 'Logger/Formatter/Syslog.zep',
            'Logger_Item'                                     => 'Logger/Item.zep',
            'Logger_Logger'                                   => 'Logger/Logger.zep',
            'Logger_LoggerFactory'                            => 'Logger/LoggerFactory.zep',
            'Messages_Exception'                              => 'Messages/Exception.zep',
            'Messages_Message'                                => 'Messages/Message.zep',
            'Messages_MessageInterface'                       => 'Messages/MessageInterface.zep',
            'Messages_Messages'                               => 'Messages/Messages.zep',
            'Mvc_Application'                                 => 'Mvc/Application.zep',
            'Mvc_Application_Exception'                       => 'Mvc/Application/Exception.zep',
            'Mvc_Collection'                                  => 'Mvc/Collection.zep',
            'Mvc_Collection_Behavior'                         => 'Mvc/Collection/Behavior.zep',
            'Mvc_Collection_Behavior_SoftDelete'              => 'Mvc/Collection/Behavior/SoftDelete.zep',
            'Mvc_Collection_Behavior_Timestampable'           => 'Mvc/Collection/Behavior/Timestampable.zep',
            'Mvc_Collection_BehaviorInterface'                => 'Mvc/Collection/BehaviorInterface.zep',
            'Mvc_Collection_Document'                         => 'Mvc/Collection/Document.zep',
            'Mvc_Collection_Exception'                        => 'Mvc/Collection/Exception.zep',
            'Mvc_Collection_Manager'                          => 'Mvc/Collection/Manager.zep',
            'Mvc_Collection_ManagerInterface'                 => 'Mvc/Collection/ManagerInterface.zep',
            'Mvc_CollectionInterface'                         => 'Mvc/CollectionInterface.zep',
            'Mvc_Controller'                                  => 'Mvc/Controller.zep',
            'Mvc_Controller_BindModelInterface'               => 'Mvc/Controller/BindModelInterface.zep',
            'Mvc_ControllerInterface'                         => 'Mvc/ControllerInterface.zep',
            'Mvc_Dispatcher'                                  => 'Mvc/Dispatcher.zep',
            'Mvc_Dispatcher_Exception'                        => 'Mvc/Dispatcher/Exception.zep',
            'Mvc_DispatcherInterface'                         => 'Mvc/DispatcherInterface.zep',
            'Mvc_EntityInterface'                             => 'Mvc/EntityInterface.zep',
            'Mvc_Micro'                                       => 'Mvc/Micro.zep',
            'Mvc_Micro_Collection'                            => 'Mvc/Micro/Collection.zep',
            'Mvc_Micro_CollectionInterface'                   => 'Mvc/Micro/CollectionInterface.zep',
            'Mvc_Micro_Exception'                             => 'Mvc/Micro/Exception.zep',
            'Mvc_Micro_LazyLoader'                            => 'Mvc/Micro/LazyLoader.zep',
            'Mvc_Micro_MiddlewareInterface'                   => 'Mvc/Micro/MiddlewareInterface.zep',
            'Mvc_Model'                                       => 'Mvc/Model.zep',
            'Mvc_Model_Behavior'                              => 'Mvc/Model/Behavior.zep',
            'Mvc_Model_Behavior_SoftDelete'                   => 'Mvc/Model/Behavior/SoftDelete.zep',
            'Mvc_Model_Behavior_Timestampable'                => 'Mvc/Model/Behavior/Timestampable.zep',
            'Mvc_Model_BehaviorInterface'                     => 'Mvc/Model/BehaviorInterface.zep',
            'Mvc_Model_Binder'                                => 'Mvc/Model/Binder.zep',
            'Mvc_Model_Binder_BindableInterface'              => 'Mvc/Model/Binder/BindableInterface.zep',
            'Mvc_Model_BinderInterface'                       => 'Mvc/Model/BinderInterface.zep',
            'Mvc_Model_Criteria'                              => 'Mvc/Model/Criteria.zep',
            'Mvc_Model_CriteriaInterface'                     => 'Mvc/Model/CriteriaInterface.zep',
            'Mvc_Model_Exception'                             => 'Mvc/Model/Exception.zep',
            'Mvc_Model_Manager'                               => 'Mvc/Model/Manager.zep',
            'Mvc_Model_ManagerInterface'                      => 'Mvc/Model/ManagerInterface.zep',
            'Mvc_Model_MetaData'                              => 'Mvc/Model/MetaData.zep',
            'Mvc_Model_MetaData_Apcu'                         => 'Mvc/Model/MetaData/Apcu.zep',
            'Mvc_Model_MetaData_Libmemcached'                 => 'Mvc/Model/MetaData/Libmemcached.zep',
            'Mvc_Model_MetaData_Memory'                       => 'Mvc/Model/MetaData/Memory.zep',
            'Mvc_Model_MetaData_Redis'                        => 'Mvc/Model/MetaData/Redis.zep',
            'Mvc_Model_MetaData_Strategy_Annotations'         => 'Mvc/Model/MetaData/Strategy/Annotations.zep',
            'Mvc_Model_MetaData_Strategy_Introspection'       => 'Mvc/Model/MetaData/Strategy/Introspection.zep',
            'Mvc_Model_MetaData_StrategyInterface'            => 'Mvc/Model/MetaData/StrategyInterface.zep',
            'Mvc_Model_MetaData_Stream'                       => 'Mvc/Model/MetaData/Stream.zep',
            'Mvc_Model_MetaDataInterface'                     => 'Mvc/Model/MetaDataInterface.zep',
            'Mvc_Model_Query'                                 => 'Mvc/Model/Query.zep',
            'Mvc_Model_Query_Builder'                         => 'Mvc/Model/Query/Builder.zep',
            'Mvc_Model_Query_BuilderInterface'                => 'Mvc/Model/Query/BuilderInterface.zep',
            'Mvc_Model_Query_Lang'                            => 'Mvc/Model/Query/Lang.zep',
            'Mvc_Model_Query_Status'                          => 'Mvc/Model/Query/Status.zep',
            'Mvc_Model_Query_StatusInterface'                 => 'Mvc/Model/Query/StatusInterface.zep',
            'Mvc_Model_QueryInterface'                        => 'Mvc/Model/QueryInterface.zep',
            'Mvc_Model_Relation'                              => 'Mvc/Model/Relation.zep',
            'Mvc_Model_RelationInterface'                     => 'Mvc/Model/RelationInterface.zep',
            'Mvc_Model_ResultInterface'                       => 'Mvc/Model/ResultInterface.zep',
            'Mvc_Model_Resultset'                             => 'Mvc/Model/Resultset.zep',
            'Mvc_Model_Resultset_Complex'                     => 'Mvc/Model/Resultset/Complex.zep',
            'Mvc_Model_Resultset_Simple'                      => 'Mvc/Model/Resultset/Simple.zep',
            'Mvc_Model_ResultsetInterface'                    => 'Mvc/Model/ResultsetInterface.zep',
            'Mvc_Model_Row'                                   => 'Mvc/Model/Row.zep',
            'Mvc_Model_Transaction'                           => 'Mvc/Model/Transaction.zep',
            'Mvc_Model_Transaction_Exception'                 => 'Mvc/Model/Transaction/Exception.zep',
            'Mvc_Model_Transaction_Failed'                    => 'Mvc/Model/Transaction/Failed.zep',
            'Mvc_Model_Transaction_Manager'                   => 'Mvc/Model/Transaction/Manager.zep',
            'Mvc_Model_Transaction_ManagerInterface'          => 'Mvc/Model/Transaction/ManagerInterface.zep',
            'Mvc_Model_TransactionInterface'                  => 'Mvc/Model/TransactionInterface.zep',
            'Mvc_Model_ValidationFailed'                      => 'Mvc/Model/ValidationFailed.zep',
            'Mvc_ModelInterface'                              => 'Mvc/ModelInterface.zep',
            'Mvc_ModuleDefinitionInterface'                   => 'Mvc/ModuleDefinitionInterface.zep',
            'Mvc_Router'                                      => 'Mvc/Router.zep',
            'Mvc_Router_Annotations'                          => 'Mvc/Router/Annotations.zep',
            'Mvc_Router_Exception'                            => 'Mvc/Router/Exception.zep',
            'Mvc_Router_Group'                                => 'Mvc/Router/Group.zep',
            'Mvc_Router_GroupInterface'                       => 'Mvc/Router/GroupInterface.zep',
            'Mvc_Router_Route'                                => 'Mvc/Router/Route.zep',
            'Mvc_Router_RouteInterface'                       => 'Mvc/Router/RouteInterface.zep',
            'Mvc_RouterInterface'                             => 'Mvc/RouterInterface.zep',
            'Mvc_View'                                        => 'Mvc/View.zep',
            'Mvc_View_Engine'                                 => 'Mvc/View/Engine.zep',
            'Mvc_View_Engine_Php'                             => 'Mvc/View/Engine/Php.zep',
            'Mvc_View_Engine_Volt'                            => 'Mvc/View/Engine/Volt.zep',
            'Mvc_View_Engine_Volt_Compiler'                   => 'Mvc/View/Engine/Volt/Compiler.zep',
            'Mvc_View_Engine_Volt_Exception'                  => 'Mvc/View/Engine/Volt/Exception.zep',
            'Mvc_View_EngineInterface'                        => 'Mvc/View/EngineInterface.zep',
            'Mvc_View_Exception'                              => 'Mvc/View/Exception.zep',
            'Mvc_View_Simple'                                 => 'Mvc/View/Simple.zep',
            'Mvc_ViewBaseInterface'                           => 'Mvc/ViewBaseInterface.zep',
            'Mvc_ViewInterface'                               => 'Mvc/ViewInterface.zep',
            'Paginator_Adapter_AbstractAdapter'               => 'Paginator/Adapter/AbstractAdapter.zep',
            'Paginator_Adapter_AdapterInterface'              => 'Paginator/Adapter/AdapterInterface.zep',
            'Paginator_Adapter_Model'                         => 'Paginator/Adapter/Model.zep',
            'Paginator_Adapter_NativeArray'                   => 'Paginator/Adapter/NativeArray.zep',
            'Paginator_Adapter_QueryBuilder'                  => 'Paginator/Adapter/QueryBuilder.zep',
            'Paginator_Exception'                             => 'Paginator/Exception.zep',
            'Paginator_PaginatorFactory'                      => 'Paginator/PaginatorFactory.zep',
            'Paginator_Repository'                            => 'Paginator/Repository.zep',
            'Paginator_RepositoryInterface'                   => 'Paginator/RepositoryInterface.zep',
            'Plugin'                                          => 'Plugin.zep',
            'Registry'                                        => 'Registry.zep',
            'Security'                                        => 'Security.zep',
            'Security_Exception'                              => 'Security/Exception.zep',
            'Security_Random'                                 => 'Security/Random.zep',
            'Session_Adapter_AbstractAdapter'                 => 'Session/Adapter/AbstractAdapter.zep',
            'Session_Adapter_Libmemcached'                    => 'Session/Adapter/Libmemcached.zep',
            'Session_Adapter_Noop'                            => 'Session/Adapter/Noop.zep',
            'Session_Adapter_Redis'                           => 'Session/Adapter/Redis.zep',
            'Session_Adapter_Stream'                          => 'Session/Adapter/Stream.zep',
            'Session_Bag'                                     => 'Session/Bag.zep',
            'Session_Exception'                               => 'Session/Exception.zep',
            'Session_Manager'                                 => 'Session/Manager.zep',
            'Session_ManagerInterface'                        => 'Session/ManagerInterface.zep',
            'Storage_Adapter_AbstractAdapter'                 => 'Storage/Adapter/AbstractAdapter.zep',
            'Storage_Adapter_AdapterInterface'                => 'Storage/Adapter/AdapterInterface.zep',
            'Storage_Adapter_Apcu'                            => 'Storage/Adapter/Apcu.zep',
            'Storage_Adapter_Libmemcached'                    => 'Storage/Adapter/Libmemcached.zep',
            'Storage_Adapter_Memory'                          => 'Storage/Adapter/Memory.zep',
            'Storage_Adapter_Redis'                           => 'Storage/Adapter/Redis.zep',
            'Storage_Adapter_Stream'                          => 'Storage/Adapter/Stream.zep',
            'Storage_AdapterFactory'                          => 'Storage/AdapterFactory.zep',
            'Storage_Exception'                               => 'Storage/Exception.zep',
            'Storage_Serializer_AbstractSerializer'           => 'Storage/Serializer/AbstractSerializer.zep',
            'Storage_Serializer_Base64'                       => 'Storage/Serializer/Base64.zep',
            'Storage_Serializer_Igbinary'                     => 'Storage/Serializer/Igbinary.zep',
            'Storage_Serializer_Json'                         => 'Storage/Serializer/Json.zep',
            'Storage_Serializer_Msgpack'                      => 'Storage/Serializer/Msgpack.zep',
            'Storage_Serializer_None'                         => 'Storage/Serializer/None.zep',
            'Storage_Serializer_Php'                          => 'Storage/Serializer/Php.zep',
            'Storage_Serializer_SerializerInterface'          => 'Storage/Serializer/SerializerInterface.zep',
            'Storage_SerializerFactory'                       => 'Storage/SerializerFactory.zep',
            'Tag'                                             => 'Tag.zep',
            'Tag_Exception'                                   => 'Tag/Exception.zep',
            'Tag_Select'                                      => 'Tag/Select.zep',
            'Text'                                            => 'Text.zep',
            'Translate_Adapter_AbstractAdapter'               => 'Translate/Adapter/AbstractAdapter.zep',
            'Translate_Adapter_AdapterInterface'              => 'Translate/Adapter/AdapterInterface.zep',
            'Translate_Adapter_Csv'                           => 'Translate/Adapter/Csv.zep',
            'Translate_Adapter_Gettext'                       => 'Translate/Adapter/Gettext.zep',
            'Translate_Adapter_NativeArray'                   => 'Translate/Adapter/NativeArray.zep',
            'Translate_Exception'                             => 'Translate/Exception.zep',
            'Translate_Interpolator_AssociativeArray'         => 'Translate/Interpolator/AssociativeArray.zep',
            'Translate_Interpolator_IndexedArray'             => 'Translate/Interpolator/IndexedArray.zep',
            'Translate_Interpolator_InterpolatorInterface'    => 'Translate/Interpolator/InterpolatorInterface.zep',
            'Translate_InterpolatorFactory'                   => 'Translate/InterpolatorFactory.zep',
            'Translate_TranslateFactory'                      => 'Translate/TranslateFactory.zep',
            'Url'                                             => 'Url.zep',
            'Url_Exception'                                   => 'Url/Exception.zep',
            'UrlInterface'                                    => 'UrlInterface.zep',
            'Validation'                                      => 'Validation.zep',
            'Validation_CombinedFieldsValidator'              => 'Validation/CombinedFieldsValidator.zep',
            'Validation_Exception'                            => 'Validation/Exception.zep',
            'Validation_Validator'                            => 'Validation/Validator.zep',
            'Validation_Validator_Alnum'                      => 'Validation/Validator/Alnum.zep',
            'Validation_Validator_Alpha'                      => 'Validation/Validator/Alpha.zep',
            'Validation_Validator_Between'                    => 'Validation/Validator/Between.zep',
            'Validation_Validator_Callback'                   => 'Validation/Validator/Callback.zep',
            'Validation_Validator_Confirmation'               => 'Validation/Validator/Confirmation.zep',
            'Validation_Validator_CreditCard'                 => 'Validation/Validator/CreditCard.zep',
            'Validation_Validator_Date'                       => 'Validation/Validator/Date.zep',
            'Validation_Validator_Digit'                      => 'Validation/Validator/Digit.zep',
            'Validation_Validator_Email'                      => 'Validation/Validator/Email.zep',
            'Validation_Validator_Exception'                  => 'Validation/Validator/Exception.zep',
            'Validation_Validator_ExclusionIn'                => 'Validation/Validator/ExclusionIn.zep',
            'Validation_Validator_File'                       => 'Validation/Validator/File.zep',
            'Validation_Validator_File_FileAbstract'          => 'Validation/Validator/File/FileAbstract.zep',
            'Validation_Validator_File_MimeType'              => 'Validation/Validator/File/MimeType.zep',
            'Validation_Validator_File_Resolu'                => 'Validation/Validator/File/Resolution',
            'Validation_Validator_File_Resolution_Equal'      => 'Validation/Validator/File/Resolution/Equal.zep',
            'Validation_Validator_File_Resolution_Max'        => 'Validation/Validator/File/Resolution/Max.zep',
            'Validation_Validator_File_Resolution_Min'        => 'Validation/Validator/File/Resolution/Min.zep',
            'Validation_Validator_File_Size_Equal'            => 'Validation/Validator/File/Size/Equal.zep',
            'Validation_Validator_File_Size_Max'              => 'Validation/Validator/File/Size/Max.zep',
            'Validation_Validator_File_Size_Min'              => 'Validation/Validator/File/Size/Min.zep',
            'Validation_Validator_Identical'                  => 'Validation/Validator/Identical.zep',
            'Validation_Validator_InclusionIn'                => 'Validation/Validator/InclusionIn.zep',
            'Validation_Validator_Ip'                         => 'Validation/Validator/Ip.zep',
            'Validation_Validator_Numericality'               => 'Validation/Validator/Numericality.zep',
            'Validation_Validator_PresenceOf'                 => 'Validation/Validator/PresenceOf.zep',
            'Validation_Validator_Regex'                      => 'Validation/Validator/Regex.zep',
            'Validation_Validator_StringLe'                   => 'Validation/Validator/StringLength',
            'Validation_Validator_StringLength'               => 'Validation/Validator/StringLength.zep',
            'Validation_Validator_StringLength_Max'           => 'Validation/Validator/StringLength/Max.zep',
            'Validation_Validator_StringLength_Min'           => 'Validation/Validator/StringLength/Min.zep',
            'Validation_Validator_Uniqueness'                 => 'Validation/Validator/Uniqueness.zep',
            'Validation_Validator_Url'                        => 'Validation/Validator/Url.zep',
            'Validation_ValidatorComposite'                   => 'Validation/ValidatorComposite.zep',
            'Validation_ValidatorCompositeInterface'          => 'Validation/ValidatorCompositeInterface.zep',
            'Validation_ValidatorFactory'                     => 'Validation/ValidatorFactory.zep',
            'Validation_ValidatorInterface'                   => 'Validation/ValidatorInterface.zep',
            'ValidationInterface'                             => 'ValidationInterface.zep',
            'Version'                                         => 'Version.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Forms',
        'docs'   => [
            'Forms_Element'                                   => 'Forms/Element.zep',
            'Forms_Element_Check'                             => 'Forms/Element/Check.zep',
            'Forms_Element_Date'                              => 'Forms/Element/Date.zep',
            'Forms_Element_Email'                             => 'Forms/Element/Email.zep',
            'Forms_Element_File'                              => 'Forms/Element/File.zep',
            'Forms_Element_Hidden'                            => 'Forms/Element/Hidden.zep',
            'Forms_Element_Numeric'                           => 'Forms/Element/Numeric.zep',
            'Forms_Element_Password'                          => 'Forms/Element/Password.zep',
            'Forms_Element_Radio'                             => 'Forms/Element/Radio.zep',
            'Forms_Element_Select'                            => 'Forms/Element/Select.zep',
            'Forms_Element_Submit'                            => 'Forms/Element/Submit.zep',
            'Forms_Element_Text'                              => 'Forms/Element/Text.zep',
            'Forms_Element_TextArea'                          => 'Forms/Element/TextArea.zep',
            'Forms_ElementInterface'                          => 'Forms/ElementInterface.zep',
            'Forms_Exception'                                 => 'Forms/Exception.zep',
            'Forms_Form'                                      => 'Forms/Form.zep',
            'Forms_Manager'                                   => 'Forms/Manager.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Helper',
        'docs'   => [
            'Helper_Arr'                                      => 'Helper/Arr.zep',
            'Helper_Exception'                                => 'Helper/Exception.zep',
            'Helper_Number'                                   => 'Helper/Number.zep',
            'Helper_Str'                                      => 'Helper/Str.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Html',
        'docs'   => [
            'Html_Attributes'                                 => 'Html/Attributes.zep',
            'Html_Attributes_AttributesInterface'             => 'Html/Attributes/AttributesInterface.zep',
            'Html_Attributes_RenderInterface'                 => 'Html/Attributes/RenderInterface.zep',
            'Html_Breadcrumbs'                                => 'Html/Breadcrumbs.zep',
            'Html_Exception'                                  => 'Html/Exception.zep',
            'Html_Helper_AbstractHelper'                      => 'Html/Helper/AbstractHelper.zep',
            'Html_Helper_Anchor'                              => 'Html/Helper/Anchor.zep',
            'Html_Helper_AnchorRaw'                           => 'Html/Helper/AnchorRaw.zep',
            'Html_Helper_Body'                                => 'Html/Helper/Body.zep',
            'Html_Helper_Button'                              => 'Html/Helper/Button.zep',
            'Html_Helper_Close'                               => 'Html/Helper/Close.zep',
            'Html_Helper_Element'                             => 'Html/Helper/Element.zep',
            'Html_Helper_ElementRaw'                          => 'Html/Helper/ElementRaw.zep',
            'Html_Helper_Form'                                => 'Html/Helper/Form.zep',
            'Html_Helper_Img'                                 => 'Html/Helper/Img.zep',
            'Html_Helper_Label'                               => 'Html/Helper/Label.zep',
            'Html_Helper_TextArea'                            => 'Html/Helper/TextArea.zep',
            'Html_Tag'                                        => 'Html/Tag.zep',
            'Html_TagFactory'                                 => 'Html/TagFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Http',
        'docs'   => [
            'Http_Cookie'                                     => 'Http/Cookie.zep',
            'Http_Cookie_Exception'                           => 'Http/Cookie/Exception.zep',
            'Http_CookieInterface'                            => 'Http/CookieInterface.zep',
            'Http_Message_AbstractCommon'                     => 'Http/Message/AbstractCommon.zep',
            'Http_Message_AbstractMessage'                    => 'Http/Message/AbstractMessage.zep',
            'Http_Message_AbstractRequest'                    => 'Http/Message/AbstractRequest.zep',
            'Http_Message_Exception_InvalidArgumentException' => 'Http/Message/Exception/InvalidArgumentException.zep',
            'Http_Message_Request'                            => 'Http/Message/Request.zep',
            'Http_Message_RequestFactory'                     => 'Http/Message/RequestFactory.zep',
            'Http_Message_Response'                           => 'Http/Message/Response.zep',
            'Http_Message_ResponseFactory'                    => 'Http/Message/ResponseFactory.zep',
            'Http_Message_ServerRequest'                      => 'Http/Message/ServerRequest.zep',
            'Http_Message_ServerRequestFactory'               => 'Http/Message/ServerRequestFactory.zep',
            'Http_Message_Stream'                             => 'Http/Message/Stream.zep',
            'Http_Message_Stream_Input'                       => 'Http/Message/Stream/Input.zep',
            'Http_Message_Stream_Memory'                      => 'Http/Message/Stream/Memory.zep',
            'Http_Message_Stream_Temp'                        => 'Http/Message/Stream/Temp.zep',
            'Http_Message_StreamFactory'                      => 'Http/Message/StreamFactory.zep',
            'Http_Message_UploadedFile'                       => 'Http/Message/UploadedFile.zep',
            'Http_Message_UploadedFileFactory'                => 'Http/Message/UploadedFileFactory.zep',
            'Http_Message_Uri'                                => 'Http/Message/Uri.zep',
            'Http_Message_UriFactory'                         => 'Http/Message/UriFactory.zep',
            'Http_Request'                                    => 'Http/Request.zep',
            'Http_Request_Exception'                          => 'Http/Request/Exception.zep',
            'Http_Request_File'                               => 'Http/Request/File.zep',
            'Http_Request_FileInterface'                      => 'Http/Request/FileInterface.zep',
            'Http_RequestInterface'                           => 'Http/RequestInterface.zep',
            'Http_Response'                                   => 'Http/Response.zep',
            'Http_Response_Cookies'                           => 'Http/Response/Cookies.zep',
            'Http_Response_CookiesInterface'                  => 'Http/Response/CookiesInterface.zep',
            'Http_Response_Exception'                         => 'Http/Response/Exception.zep',
            'Http_Response_Headers'                           => 'Http/Response/Headers.zep',
            'Http_Response_HeadersInterface'                  => 'Http/Response/HeadersInterface.zep',
            'Http_ResponseInterface'                          => 'Http/ResponseInterface.zep',
            'Http_Server_AbstractMiddleware'                  => 'Http/Server/AbstractMiddleware.zep',
            'Http_Server_AbstractRequestHandler'              => 'Http/Server/AbstractRequestHandler.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Image',
        'docs'   => [
            'Image'                                           => 'Image.zep',
            'Image_Adapter_AbstractAdapter'                   => 'Image/Adapter/AbstractAdapter.zep',
            'Image_Adapter_AdapterInterface'                  => 'Image/Adapter/AdapterInterface.zep',
            'Image_Adapter_Gd'                                => 'Image/Adapter/Gd.zep',
            'Image_Adapter_Imagick'                           => 'Image/Adapter/Imagick.zep',
            'Image_Exception'                                 => 'Image/Exception.zep',
            'Image_ImageFactory'                              => 'Image/ImageFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Kernel',
        'docs'   => [
            'Kernel'                                          => 'Kernel.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Loader',
        'docs'   => [
            'Loader'                                          => 'Loader.zep',
            'Loader_Exception'                                => 'Loader/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Logger',
        'docs'   => [
            'Logger_Adapter_AbstractAdapter'                  => 'Logger/Adapter/AbstractAdapter.zep',
            'Logger_Adapter_AdapterInterface'                 => 'Logger/Adapter/AdapterInterface.zep',
            'Logger_Adapter_Noop'                             => 'Logger/Adapter/Noop.zep',
            'Logger_Adapter_Stream'                           => 'Logger/Adapter/Stream.zep',
            'Logger_Adapter_Syslog'                           => 'Logger/Adapter/Syslog.zep',
            'Logger_AdapterFactory'                           => 'Logger/AdapterFactory.zep',
            'Logger_Exception'                                => 'Logger/Exception.zep',
            'Logger_Formatter_AbstractFormatter'              => 'Logger/Formatter/AbstractFormatter.zep',
            'Logger_Formatter_FormatterInterface'             => 'Logger/Formatter/FormatterInterface.zep',
            'Logger_Formatter_Json'                           => 'Logger/Formatter/Json.zep',
            'Logger_Formatter_Line'                           => 'Logger/Formatter/Line.zep',
            'Logger_Formatter_Syslog'                         => 'Logger/Formatter/Syslog.zep',
            'Logger_Item'                                     => 'Logger/Item.zep',
            'Logger_Logger'                                   => 'Logger/Logger.zep',
            'Logger_LoggerFactory'                            => 'Logger/LoggerFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Messages',
        'docs'   => [
            'Messages_Exception'                              => 'Messages/Exception.zep',
            'Messages_Message'                                => 'Messages/Message.zep',
            'Messages_MessageInterface'                       => 'Messages/MessageInterface.zep',
            'Messages_Messages'                               => 'Messages/Messages.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Mvc',
        'docs'   => [
            'Mvc_Application'                                 => 'Mvc/Application.zep',
            'Mvc_Application_Exception'                       => 'Mvc/Application/Exception.zep',
            'Mvc_Collection'                                  => 'Mvc/Collection.zep',
            'Mvc_Collection_Behavior'                         => 'Mvc/Collection/Behavior.zep',
            'Mvc_Collection_Behavior_SoftDelete'              => 'Mvc/Collection/Behavior/SoftDelete.zep',
            'Mvc_Collection_Behavior_Timestampable'           => 'Mvc/Collection/Behavior/Timestampable.zep',
            'Mvc_Collection_BehaviorInterface'                => 'Mvc/Collection/BehaviorInterface.zep',
            'Mvc_Collection_Document'                         => 'Mvc/Collection/Document.zep',
            'Mvc_Collection_Exception'                        => 'Mvc/Collection/Exception.zep',
            'Mvc_Collection_Manager'                          => 'Mvc/Collection/Manager.zep',
            'Mvc_Collection_ManagerInterface'                 => 'Mvc/Collection/ManagerInterface.zep',
            'Mvc_CollectionInterface'                         => 'Mvc/CollectionInterface.zep',
            'Mvc_Controller'                                  => 'Mvc/Controller.zep',
            'Mvc_Controller_BindModelInterface'               => 'Mvc/Controller/BindModelInterface.zep',
            'Mvc_ControllerInterface'                         => 'Mvc/ControllerInterface.zep',
            'Mvc_Dispatcher'                                  => 'Mvc/Dispatcher.zep',
            'Mvc_Dispatcher_Exception'                        => 'Mvc/Dispatcher/Exception.zep',
            'Mvc_DispatcherInterface'                         => 'Mvc/DispatcherInterface.zep',
            'Mvc_EntityInterface'                             => 'Mvc/EntityInterface.zep',
            'Mvc_Micro'                                       => 'Mvc/Micro.zep',
            'Mvc_Micro_Collection'                            => 'Mvc/Micro/Collection.zep',
            'Mvc_Micro_CollectionInterface'                   => 'Mvc/Micro/CollectionInterface.zep',
            'Mvc_Micro_Exception'                             => 'Mvc/Micro/Exception.zep',
            'Mvc_Micro_LazyLoader'                            => 'Mvc/Micro/LazyLoader.zep',
            'Mvc_Micro_MiddlewareInterface'                   => 'Mvc/Micro/MiddlewareInterface.zep',
            'Mvc_Model'                                       => 'Mvc/Model.zep',
            'Mvc_Model_Behavior'                              => 'Mvc/Model/Behavior.zep',
            'Mvc_Model_Behavior_SoftDelete'                   => 'Mvc/Model/Behavior/SoftDelete.zep',
            'Mvc_Model_Behavior_Timestampable'                => 'Mvc/Model/Behavior/Timestampable.zep',
            'Mvc_Model_BehaviorInterface'                     => 'Mvc/Model/BehaviorInterface.zep',
            'Mvc_Model_Binder'                                => 'Mvc/Model/Binder.zep',
            'Mvc_Model_Binder_BindableInterface'              => 'Mvc/Model/Binder/BindableInterface.zep',
            'Mvc_Model_BinderInterface'                       => 'Mvc/Model/BinderInterface.zep',
            'Mvc_Model_Criteria'                              => 'Mvc/Model/Criteria.zep',
            'Mvc_Model_CriteriaInterface'                     => 'Mvc/Model/CriteriaInterface.zep',
            'Mvc_Model_Exception'                             => 'Mvc/Model/Exception.zep',
            'Mvc_Model_Manager'                               => 'Mvc/Model/Manager.zep',
            'Mvc_Model_ManagerInterface'                      => 'Mvc/Model/ManagerInterface.zep',
            'Mvc_Model_MetaData'                              => 'Mvc/Model/MetaData.zep',
            'Mvc_Model_MetaData_Apcu'                         => 'Mvc/Model/MetaData/Apcu.zep',
            'Mvc_Model_MetaData_Libmemcached'                 => 'Mvc/Model/MetaData/Libmemcached.zep',
            'Mvc_Model_MetaData_Memory'                       => 'Mvc/Model/MetaData/Memory.zep',
            'Mvc_Model_MetaData_Redis'                        => 'Mvc/Model/MetaData/Redis.zep',
            'Mvc_Model_MetaData_Strategy_Annotations'         => 'Mvc/Model/MetaData/Strategy/Annotations.zep',
            'Mvc_Model_MetaData_Strategy_Introspection'       => 'Mvc/Model/MetaData/Strategy/Introspection.zep',
            'Mvc_Model_MetaData_StrategyInterface'            => 'Mvc/Model/MetaData/StrategyInterface.zep',
            'Mvc_Model_MetaData_Stream'                       => 'Mvc/Model/MetaData/Stream.zep',
            'Mvc_Model_MetaDataInterface'                     => 'Mvc/Model/MetaDataInterface.zep',
            'Mvc_Model_Query'                                 => 'Mvc/Model/Query.zep',
            'Mvc_Model_Query_Builder'                         => 'Mvc/Model/Query/Builder.zep',
            'Mvc_Model_Query_BuilderInterface'                => 'Mvc/Model/Query/BuilderInterface.zep',
            'Mvc_Model_Query_Lang'                            => 'Mvc/Model/Query/Lang.zep',
            'Mvc_Model_Query_Status'                          => 'Mvc/Model/Query/Status.zep',
            'Mvc_Model_Query_StatusInterface'                 => 'Mvc/Model/Query/StatusInterface.zep',
            'Mvc_Model_QueryInterface'                        => 'Mvc/Model/QueryInterface.zep',
            'Mvc_Model_Relation'                              => 'Mvc/Model/Relation.zep',
            'Mvc_Model_RelationInterface'                     => 'Mvc/Model/RelationInterface.zep',
            'Mvc_Model_ResultInterface'                       => 'Mvc/Model/ResultInterface.zep',
            'Mvc_Model_Resultset'                             => 'Mvc/Model/Resultset.zep',
            'Mvc_Model_Resultset_Complex'                     => 'Mvc/Model/Resultset/Complex.zep',
            'Mvc_Model_Resultset_Simple'                      => 'Mvc/Model/Resultset/Simple.zep',
            'Mvc_Model_ResultsetInterface'                    => 'Mvc/Model/ResultsetInterface.zep',
            'Mvc_Model_Row'                                   => 'Mvc/Model/Row.zep',
            'Mvc_Model_Transaction'                           => 'Mvc/Model/Transaction.zep',
            'Mvc_Model_Transaction_Exception'                 => 'Mvc/Model/Transaction/Exception.zep',
            'Mvc_Model_Transaction_Failed'                    => 'Mvc/Model/Transaction/Failed.zep',
            'Mvc_Model_Transaction_Manager'                   => 'Mvc/Model/Transaction/Manager.zep',
            'Mvc_Model_Transaction_ManagerInterface'          => 'Mvc/Model/Transaction/ManagerInterface.zep',
            'Mvc_Model_TransactionInterface'                  => 'Mvc/Model/TransactionInterface.zep',
            'Mvc_Model_ValidationFailed'                      => 'Mvc/Model/ValidationFailed.zep',
            'Mvc_ModelInterface'                              => 'Mvc/ModelInterface.zep',
            'Mvc_ModuleDefinitionInterface'                   => 'Mvc/ModuleDefinitionInterface.zep',
            'Mvc_Router'                                      => 'Mvc/Router.zep',
            'Mvc_Router_Annotations'                          => 'Mvc/Router/Annotations.zep',
            'Mvc_Router_Exception'                            => 'Mvc/Router/Exception.zep',
            'Mvc_Router_Group'                                => 'Mvc/Router/Group.zep',
            'Mvc_Router_GroupInterface'                       => 'Mvc/Router/GroupInterface.zep',
            'Mvc_Router_Route'                                => 'Mvc/Router/Route.zep',
            'Mvc_Router_RouteInterface'                       => 'Mvc/Router/RouteInterface.zep',
            'Mvc_RouterInterface'                             => 'Mvc/RouterInterface.zep',
            'Mvc_View'                                        => 'Mvc/View.zep',
            'Mvc_View_Engine'                                 => 'Mvc/View/Engine.zep',
            'Mvc_View_Engine_Php'                             => 'Mvc/View/Engine/Php.zep',
            'Mvc_View_Engine_Volt'                            => 'Mvc/View/Engine/Volt.zep',
            'Mvc_View_Engine_Volt_Compiler'                   => 'Mvc/View/Engine/Volt/Compiler.zep',
            'Mvc_View_Engine_Volt_Exception'                  => 'Mvc/View/Engine/Volt/Exception.zep',
            'Mvc_View_EngineInterface'                        => 'Mvc/View/EngineInterface.zep',
            'Mvc_View_Exception'                              => 'Mvc/View/Exception.zep',
            'Mvc_View_Simple'                                 => 'Mvc/View/Simple.zep',
            'Mvc_ViewBaseInterface'                           => 'Mvc/ViewBaseInterface.zep',
            'Mvc_ViewInterface'                               => 'Mvc/ViewInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Paginator',
        'docs'   => [
            'Paginator_Adapter_AbstractAdapter'               => 'Paginator/Adapter/AbstractAdapter.zep',
            'Paginator_Adapter_AdapterInterface'              => 'Paginator/Adapter/AdapterInterface.zep',
            'Paginator_Adapter_Model'                         => 'Paginator/Adapter/Model.zep',
            'Paginator_Adapter_NativeArray'                   => 'Paginator/Adapter/NativeArray.zep',
            'Paginator_Adapter_QueryBuilder'                  => 'Paginator/Adapter/QueryBuilder.zep',
            'Paginator_Exception'                             => 'Paginator/Exception.zep',
            'Paginator_PaginatorFactory'                      => 'Paginator/PaginatorFactory.zep',
            'Paginator_Repository'                            => 'Paginator/Repository.zep',
            'Paginator_RepositoryInterface'                   => 'Paginator/RepositoryInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Plugin',
        'docs'   => [
            'Plugin'                                          => 'Plugin.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Registry',
        'docs'   => [
            'Registry'                                        => 'Registry.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Security',
        'docs'   => [
            'Security'                                        => 'Security.zep',
            'Security_Exception'                              => 'Security/Exception.zep',
            'Security_Random'                                 => 'Security/Random.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Session',
        'docs'   => [
            'Session_Adapter_AbstractAdapter'                 => 'Session/Adapter/AbstractAdapter.zep',
            'Session_Adapter_Libmemcached'                    => 'Session/Adapter/Libmemcached.zep',
            'Session_Adapter_Noop'                            => 'Session/Adapter/Noop.zep',
            'Session_Adapter_Redis'                           => 'Session/Adapter/Redis.zep',
            'Session_Adapter_Stream'                          => 'Session/Adapter/Stream.zep',
            'Session_Bag'                                     => 'Session/Bag.zep',
            'Session_Exception'                               => 'Session/Exception.zep',
            'Session_Manager'                                 => 'Session/Manager.zep',
            'Session_ManagerInterface'                        => 'Session/ManagerInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Storage',
        'docs'   => [
            'Storage_Adapter_AbstractAdapter'                 => 'Storage/Adapter/AbstractAdapter.zep',
            'Storage_Adapter_AdapterInterface'                => 'Storage/Adapter/AdapterInterface.zep',
            'Storage_Adapter_Apcu'                            => 'Storage/Adapter/Apcu.zep',
            'Storage_Adapter_Libmemcached'                    => 'Storage/Adapter/Libmemcached.zep',
            'Storage_Adapter_Memory'                          => 'Storage/Adapter/Memory.zep',
            'Storage_Adapter_Redis'                           => 'Storage/Adapter/Redis.zep',
            'Storage_Adapter_Stream'                          => 'Storage/Adapter/Stream.zep',
            'Storage_AdapterFactory'                          => 'Storage/AdapterFactory.zep',
            'Storage_Exception'                               => 'Storage/Exception.zep',
            'Storage_Serializer_AbstractSerializer'           => 'Storage/Serializer/AbstractSerializer.zep',
            'Storage_Serializer_Base64'                       => 'Storage/Serializer/Base64.zep',
            'Storage_Serializer_Igbinary'                     => 'Storage/Serializer/Igbinary.zep',
            'Storage_Serializer_Json'                         => 'Storage/Serializer/Json.zep',
            'Storage_Serializer_Msgpack'                      => 'Storage/Serializer/Msgpack.zep',
            'Storage_Serializer_None'                         => 'Storage/Serializer/None.zep',
            'Storage_Serializer_Php'                          => 'Storage/Serializer/Php.zep',
            'Storage_Serializer_SerializerInterface'          => 'Storage/Serializer/SerializerInterface.zep',
            'Storage_SerializerFactory'                       => 'Storage/SerializerFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Tag',
        'docs'   => [
            'Tag'                                             => 'Tag.zep',
            'Tag_Exception'                                   => 'Tag/Exception.zep',
            'Tag_Select'                                      => 'Tag/Select.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Text',
        'docs'   => [
            'Text'                                            => 'Text.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Translate',
        'docs'   => [
            'Translate_Adapter_AbstractAdapter'               => 'Translate/Adapter/AbstractAdapter.zep',
            'Translate_Adapter_AdapterInterface'              => 'Translate/Adapter/AdapterInterface.zep',
            'Translate_Adapter_Csv'                           => 'Translate/Adapter/Csv.zep',
            'Translate_Adapter_Gettext'                       => 'Translate/Adapter/Gettext.zep',
            'Translate_Adapter_NativeArray'                   => 'Translate/Adapter/NativeArray.zep',
            'Translate_Exception'                             => 'Translate/Exception.zep',
            'Translate_Interpolator_AssociativeArray'         => 'Translate/Interpolator/AssociativeArray.zep',
            'Translate_Interpolator_IndexedArray'             => 'Translate/Interpolator/IndexedArray.zep',
            'Translate_Interpolator_InterpolatorInterface'    => 'Translate/Interpolator/InterpolatorInterface.zep',
            'Translate_InterpolatorFactory'                   => 'Translate/InterpolatorFactory.zep',
            'Translate_TranslateFactory'                      => 'Translate/TranslateFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Url',
        'docs'   => [
            'Url'                                             => 'Url.zep',
            'Url_Exception'                                   => 'Url/Exception.zep',
            'UrlInterface'                                    => 'UrlInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Validation',
        'docs'   => [
            'Validation'                                      => 'Validation.zep',
            'Validation_CombinedFieldsValidator'              => 'Validation/CombinedFieldsValidator.zep',
            'Validation_Exception'                            => 'Validation/Exception.zep',
            'Validation_Validator'                            => 'Validation/Validator.zep',
            'Validation_Validator_Alnum'                      => 'Validation/Validator/Alnum.zep',
            'Validation_Validator_Alpha'                      => 'Validation/Validator/Alpha.zep',
            'Validation_Validator_Between'                    => 'Validation/Validator/Between.zep',
            'Validation_Validator_Callback'                   => 'Validation/Validator/Callback.zep',
            'Validation_Validator_Confirmation'               => 'Validation/Validator/Confirmation.zep',
            'Validation_Validator_CreditCard'                 => 'Validation/Validator/CreditCard.zep',
            'Validation_Validator_Date'                       => 'Validation/Validator/Date.zep',
            'Validation_Validator_Digit'                      => 'Validation/Validator/Digit.zep',
            'Validation_Validator_Email'                      => 'Validation/Validator/Email.zep',
            'Validation_Validator_Exception'                  => 'Validation/Validator/Exception.zep',
            'Validation_Validator_ExclusionIn'                => 'Validation/Validator/ExclusionIn.zep',
            'Validation_Validator_File'                       => 'Validation/Validator/File.zep',
            'Validation_Validator_File_FileAbstract'          => 'Validation/Validator/File/FileAbstract.zep',
            'Validation_Validator_File_MimeType'              => 'Validation/Validator/File/MimeType.zep',
            'Validation_Validator_File_Resolu'                => 'Validation/Validator/File/Resolution',
            'Validation_Validator_File_Resolution_Equal'      => 'Validation/Validator/File/Resolution/Equal.zep',
            'Validation_Validator_File_Resolution_Max'        => 'Validation/Validator/File/Resolution/Max.zep',
            'Validation_Validator_File_Resolution_Min'        => 'Validation/Validator/File/Resolution/Min.zep',
            'Validation_Validator_File_Size_Equal'            => 'Validation/Validator/File/Size/Equal.zep',
            'Validation_Validator_File_Size_Max'              => 'Validation/Validator/File/Size/Max.zep',
            'Validation_Validator_File_Size_Min'              => 'Validation/Validator/File/Size/Min.zep',
            'Validation_Validator_Identical'                  => 'Validation/Validator/Identical.zep',
            'Validation_Validator_InclusionIn'                => 'Validation/Validator/InclusionIn.zep',
            'Validation_Validator_Ip'                         => 'Validation/Validator/Ip.zep',
            'Validation_Validator_Numericality'               => 'Validation/Validator/Numericality.zep',
            'Validation_Validator_PresenceOf'                 => 'Validation/Validator/PresenceOf.zep',
            'Validation_Validator_Regex'                      => 'Validation/Validator/Regex.zep',
            'Validation_Validator_StringLe'                   => 'Validation/Validator/StringLength',
            'Validation_Validator_StringLength'               => 'Validation/Validator/StringLength.zep',
            'Validation_Validator_StringLength_Max'           => 'Validation/Validator/StringLength/Max.zep',
            'Validation_Validator_StringLength_Min'           => 'Validation/Validator/StringLength/Min.zep',
            'Validation_Validator_Uniqueness'                 => 'Validation/Validator/Uniqueness.zep',
            'Validation_Validator_Url'                        => 'Validation/Validator/Url.zep',
            'Validation_ValidatorComposite'                   => 'Validation/ValidatorComposite.zep',
            'Validation_ValidatorCompositeInterface'          => 'Validation/ValidatorCompositeInterface.zep',
            'Validation_ValidatorFactory'                     => 'Validation/ValidatorFactory.zep',
            'Validation_ValidatorInterface'                   => 'Validation/ValidatorInterface.zep',
            'ValidationInterface'                             => 'ValidationInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Version',
        'docs'   => [
            'Version'                                         => 'Version.zep',
        ],
    ],
];

foreach ($documents as $document) {
    echo 'Processing: ' . $document['title'] . PHP_EOL;
    $output = "---
layout: default
language: 'en'
version: '4.0'
title: '{$document['title']}'
---
";
    foreach ($document['docs'] as $href => $file) {
        $link   = str_replace(['.zep', '/'], ['', '\\'], $file);
        $output .= "
* [Phalcon\\{$link}](#$href)";
    }

    $outputDoc = str_replace('\\', '_', $document['title']) . '.md';
    foreach ($document['docs'] as $href => $file) {
        echo '    - ' . $file . PHP_EOL;
        $github = strtolower($file);
        $file   = $sourceDir . $file;

        $data = processDocument($file);

        $classComment = $data['comment'] ?? '';
        $namespace    = $data['namespace'] ?? '';
        $uses         = $data['uses'] ?? '';
        $signature    = $data['signature'] ?? '';
        $extends      = $data['extends'] ?? '';
        $implements   = $data['implements'] ?? '';
        $constants    = $data['constants'] ?? [];
        $temp         = $data['properties'] ?? [];
        $properties   = $temp['properties'] ?? [];
        $shortcuts    = $temp['shortcuts'] ?? [];
        $methods      = $data['methods'] ?? [];
        $methods      = array_merge($shortcuts, $methods);
        $methods      = orderMethods($methods);

        $output .= "
        
<h1 id=\"{$href}\">{$signature}</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/{$github})
";

        if (!empty($namespace)) {
            $output .= "
| Namespace  | {$namespace} |";
        }

        if (!empty($uses)) {
            $uses   = implode(', ', $uses);
            $output .= "
| Uses       | {$uses} |";
        }

        if (!empty($extends)) {
            $output .= "
| Extends    | {$extends} |";
        }

        if (!empty($implements)) {
            $implements = implode(', ', $implements);
            $output     .= "
| Implements | {$implements} |";
        }

        $output .= "

{$classComment}
";

        if (count($constants) > 0) {
            $constants = implode(PHP_EOL, $constants);
            $output    .= "
## Constants
```php
{$constants}
```
";
        }

        if (count($properties) > 0) {
            $properties = implode(PHP_EOL, $properties);
            $output     .= "
## Properties
```php
{$properties}
```
";
        }

        if (count($methods) > 0) {
            $elements = [];
            foreach ($methods as $method) {
                $elements[] = '```php' . PHP_EOL
                    . $method['signature'] . PHP_EOL
                    . '```' . PHP_EOL
                    . $method['comment'] . PHP_EOL;
            }
            $signature = implode(PHP_EOL, $elements);
            $output    .= "
## Methods
{$signature}
";
        }

    }

    file_put_contents(
        $outputDir . $outputDoc,
        $output
    );
}

/**
 * Read the file and parse it
 *
 * @param string $file
 *
 * @return array
 */
function processDocument(string $file): array
{
    $return   = [];
    $contents = file_get_contents($file);
    $parse    = zephir_parse_file($contents, '(eval code)');

    foreach ($parse as $item) {
        $type = $item['type'] ?? '';

        if ('namespace' === $type) {
            $return['namespace'] = $item['name'];
            continue;
        }

        if ('comment' === $type) {
            $return['comment'] = getDocblockMethod($item['value']);
            continue;
        }

        if ('use' === $type) {
            $uses    = $return['uses'] ?? [];
            $aliases = $item['aliases'];
            foreach ($aliases as $alias) {
                $uses[] = $alias['name'];
            }

            $return['uses'] = $uses;
        }

        if ('class' === $type || 'interface' === $type) {
            $signature = '';
            if (1 === ($item['final'] ?? 0)) {
                $signature .= ' Final';
            };
            if (1 === ($item['abstract'] ?? 0)) {
                $signature .= ' Abstract';
            };

            $signature           .= ('class' === $type) ? ' Class ' : ' Interface ';
            $signature           .= $return['namespace'] . '\\' . $item['name'];
            $return['signature'] = ltrim($signature);

            $return['extends'] = $item['extends'] ?? '';

            $implements = $item['implements'] ?? [];
            if (count($implements) > 0) {
                foreach ($implements as $implement) {
                    $return['implements'][] = $implement['value'];
                }
            }

            $definition           = $item['definition'] ?? [];
            $return['constants']  = parseConstants($definition);
            $return['properties'] = parseProperties($definition);
            $return['methods']    = parseMethods($definition);
        }
    }

    return $return;
}

function parseConstants(array $item): array
{
    $constants = $item['constants'] ?? [];
    $return    = [];
    foreach ($constants as $constant) {
        if ('const' === $constant['type']) {
            $signature = 'const ' . $constant['name'];
            if (isset($constant['default']['value'])) {
                $signature .= ' = ' . $constant['default']['value'];
            }

            $return[$constant['name']] = $signature . ';';
        }
    }

    ksort($return);

    return $return;
}

function parseMethods(array $item): array
{
    $methods = $item['methods'] ?? [];
    $return  = [];

    foreach ($methods as $method) {
        $line = $method['docblock'] ?? '';
        $line = getDocblockMethod($line);

        $signature  = '';
        $visibility = $method['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' function ' . $method['name'] . '(';

        $params  = $method['parameters'] ?? [];
        $counter = 1;
        $count   = count($params);
        foreach ($params as $param) {
            if ('parameter' === $param['type']) {
                $type      = transformType($param['data-type']);
                $signature .= ' ' . $type . ' $' . $param['name'];
                // Default value
                $retVal = $param['default']['type'] ?? '';
                $retVal = transformType($retVal);
                if (!empty($retVal)) {
                    $signature .= ' = ' . $retVal;
                }

                if ($counter < $count) {
                    $signature .= ',';
                }

                $counter++;
            }
        }

        $signature .= ($count > 0 ? ' ' : '') . ')';

        // Return
        $retType = $method['return-type'] ?? [];
        if (1 === ($retType['void'] ?? 0)) {
            $signature .= ': void';
        } else {
            $list = $retType['list'] ?? [];
            if (count($list) > 0) {
                $retTypes = [];
                foreach ($list as $li) {
                    $cast = $li['cast'] ?? [];
                    if (count($cast) > 0) {
                        $rt = transformType($cast['value']);
                        if (1 === $li['collection']) {
                            $rt .= '[]';
                        }

                        $retTypes[] = $rt;
                    } else {
                        $retTypes[] = transformType($li['data-type']);
                    }
                }

                $signature .= ': ' . implode(' | ', $retTypes);
            }
        }

        $return[$method['name']] = [
            'comment'   => $line,
            'signature' => ltrim($signature) . ';',
        ];
    }

    return $return;
}

function parseProperties(array $item): array
{
    $properties = $item['properties'] ?? [];
    $return     = [];
    $sigReturn  = [];

    foreach ($properties as $property) {
        $line = $property['docblock'] ?? '';
        $line = getDocblock($line);

        $signature = '';

        $visibility = $property['visibility'] ?? [];
        foreach ($visibility as $vis) {
            $signature .= ' ' . $vis;
        }

        $signature .= ' ' . $property['name'];

        if (isset($property['default']['value'])) {
            $signature .= ' = ' . $property['default']['value'];
        }

        $retVal = '';
        $temp   = explode(PHP_EOL, $line);
        foreach ($temp as $li) {
            if (strpos($li, '@var') > 0) {
                $retVal = str_replace(' * @var ', '', $li);
                break;
            }
        }

        $shortcuts = $property['shortcuts'] ?? [];
        foreach ($shortcuts as $shortcut) {
            $stub = $shortcut['name'];
            if ('get' === $stub) {
                $name             = 'get' . ucfirst($property['name']);
                $sigReturn[$name] = [
                    'comment'   => '',
                    'signature' => 'public function ' . $name .
                        '()' . (!empty($retVal) ? ': ' . $retVal : ''),
                ];
            } elseif ('set' === $stub) {
                $name             = 'set' . ucfirst($property['name']);
                $sigReturn[$name] = [
                    'comment'   => '',
                    'signature' => 'public function ' . $name .
                        '( ' . (!empty($retVal) ? $retVal . ' ' : '') .
                        '$' . $property['name'] .
                        ' )',
                ];
            } elseif ('__toString' === $stub) {
                $sigReturn['__toString'] = [
                    'comment'   => '',
                    'signature' => 'public function __toString(): string',
                ];
            }
        }

        $return[$property['name']] = $line . PHP_EOL .
            ltrim($signature) . ';' . PHP_EOL;
    }

    return [
        'properties' => $return,
        'shortcuts'  => $sigReturn,
    ];
}

function getDocblockMethod(string $source): string
{
    $doc = getDocblock($source);

    return str_replace(
        [
            '/**' . PHP_EOL,
            '/**',
            ' */' . PHP_EOL,
            ' */',
            ' * ',
            ' *',
        ],
        [
            '',
            '',
            '',
            '',
            '',
            '',
        ],
        $doc
    );
}

function getDocblock(string $source): string
{
    $linesArray = [];
    $lines      = explode("\n", trim($source));

    foreach ($lines as $line) {
        $linesArray[] = str_replace(
            [
                '    /*',
                '     *',
            ],
            [
                '/*',
                ' *',
            ],
            $line
        );
    }

    $doc = implode(PHP_EOL, $linesArray);

    return '/' . $doc . '/';
}

function orderMethods($methods): array
{
    if (is_array($methods)) {
        $public    = [];
        $reserved  = [];
        $protected = [];

        foreach ($methods as $name => $method) {
            if (substr($name, 0, 2) === '__') {
                $reserved[$name] = $method;
                continue;
            }

            if (strpos($method['signature'], 'public function') !== false) {
                $public[$name] = $method;
                continue;
            }

            if (strpos($method['signature'], 'protected function') !== false) {
                $protected[$name] = $method;
                continue;
            }
        }

        ksort($reserved);
        ksort($public);
        ksort($protected);

        return array_merge($reserved, $public, $protected);
    } else {
        return $methods;
    }
}

function transformType(string $type): string
{
    switch ($type) {
        case 'variable':
            return 'mixed';
        case 'empty-array':
            return '[]';
        default:
            return $type;
    }
}
