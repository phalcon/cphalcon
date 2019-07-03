<?php
declare(strict_types=1);

$baseDir   = dirname(dirname(__DIR__));
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
            'Acl.zep',
            'Acl/Adapter.zep',
            'Acl/AdapterInterface.zep',
            'Acl/Adapter/Memory.zep',
            'Acl/Component.zep',
            'Acl/ComponentAware.zep',
            'Acl/ComponentInterface.zep',
            'Acl/Exception.zep',
            'Acl/Role.zep',
            'Acl/RoleAware.zep',
            'Acl/RoleInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Annotations',
        'docs'   => [
            'Annotations/Adapter/AbstractAdapter.zep',
            'Annotations/Adapter/AdapterInterface.zep',
            'Annotations/Adapter/Apcu.zep',
            'Annotations/Adapter/Memory.zep',
            'Annotations/Adapter/Stream.zep',
            'Annotations/Annotation.zep',
            'Annotations/AnnotationsFactory.zep',
            'Annotations/Collection.zep',
            'Annotations/Exception.zep',
            'Annotations/Reader.zep',
            'Annotations/ReaderInterface.zep',
            'Annotations/Reflection.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Application',
        'docs'   => [
            'Application.zep',
            'Application/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Assets',
        'docs'   => [
            'Assets/Asset.zep',
            'Assets/Asset/Css.zep',
            'Assets/Asset/Js.zep',
            'Assets/AssetInterface.zep',
            'Assets/Collection.zep',
            'Assets/Exception.zep',
            'Assets/FilterInterface.zep',
            'Assets/Filters/CssMin.zep',
            'Assets/Filters/JsMin.zep',
            'Assets/Filters/None.zep',
            'Assets/Inline.zep',
            'Assets/Inline/Css.zep',
            'Assets/Inline/Js.zep',
            'Assets/Manager.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Cache',
        'docs'   => [
            'Cache/Adapter/AdapterInterface.zep',
            'Cache/Adapter/Apcu.zep',
            'Cache/Adapter/Libmemcached.zep',
            'Cache/Adapter/Memory.zep',
            'Cache/Adapter/Redis.zep',
            'Cache/Adapter/Stream.zep',
            'Cache/AdapterFactory.zep',
            'Cache/Cache.zep',
            'Cache/CacheFactory.zep',
            'Cache/Exception/Exception.zep',
            'Cache/Exception/InvalidArgumentException.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Cli',
        'docs'   => [
            'Cli/Console.zep',
            'Cli/Console/Exception.zep',
            'Cli/Dispatcher.zep',
            'Cli/Dispatcher/Exception.zep',
            'Cli/DispatcherInterface.zep',
            'Cli/Router.zep',
            'Cli/Router/Exception.zep',
            'Cli/Router/Route.zep',
            'Cli/Router/RouteInterface.zep',
            'Cli/RouterInterface.zep',
            'Cli/Task.zep',
            'Cli/TaskInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Collection',
        'docs'   => [
            'Collection/Collection.zep',
            'Collection/Exception.zep',
            'Collection/ReadCollection.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Config',
        'docs'   => [
            'Config/Adapter/Grouped.zep',
            'Config/Adapter/Ini.zep',
            'Config/Adapter/Json.zep',
            'Config/Adapter/Php.zep',
            'Config/Adapter/Yaml.zep',
            'Config/Config.zep',
            'Config/ConfigFactory.zep',
            'Config/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Container',
        'docs'   => [
            'Container.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Crypt',
        'docs'   => [
            'Crypt.zep',
            'Crypt/Exception.zep',
            'Crypt/Mismatch.zep',
            'CryptInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Db',
        'docs'   => [
            'Db.zep',
            'Db/Adapter.zep',
            'Db/Adapter/Pdo.zep',
            'Db/Adapter/Pdo/Mysql.zep',
            'Db/Adapter/Pdo/Postgresql.zep',
            'Db/Adapter/Pdo/Sqlite.zep',
            'Db/Adapter/PdoFactory.zep',
            'Db/AdapterInterface.zep',
            'Db/Column.zep',
            'Db/ColumnInterface.zep',
            'Db/Dialect.zep',
            'Db/Dialect/Mysql.zep',
            'Db/Dialect/Postgresql.zep',
            'Db/Dialect/Sqlite.zep',
            'Db/DialectInterface.zep',
            'Db/Exception.zep',
            'Db/Index.zep',
            'Db/IndexInterface.zep',
            'Db/Profiler.zep',
            'Db/Profiler/Item.zep',
            'Db/RawValue.zep',
            'Db/Reference.zep',
            'Db/ReferenceInterface.zep',
            'Db/Result/Pdo.zep',
            'Db/ResultInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Debug',
        'docs'   => [
            'Debug.zep',
            'Debug/Dump.zep',
            'Debug/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Di',
        'docs'   => [
            'Di.zep',
            'Di/Exception.zep',
            'Di/Exception/ServiceResolutionException.zep',
            'Di/FactoryDefault.zep',
            'Di/FactoryDefault/Cli.zep',
            'Di/Injectable.zep',
            'Di/InjectionAwareInterface.zep',
            'Di/Service.zep',
            'Di/Service/Builder.zep',
            'Di/ServiceInterface.zep',
            'Di/ServiceProviderInterface.zep',
            'DiInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Dispatcher',
        'docs'   => [
            'Dispatcher.zep',
            'DispatcherInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Domain',
        'docs'   => [
            'Domain/Payload/Payload.zep',
            'Domain/Payload/PayloadFactory.zep',
            'Domain/Payload/PayloadInterface.zep',
            'Domain/Payload/ReadableInterface.zep',
            'Domain/Payload/Status.zep',
            'Domain/Payload/WriteableInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Escaper',
        'docs'   => [
            'Escaper.zep',
            'Escaper/Exception.zep',
            'EscaperInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Events',
        'docs'   => [
            'Events/Event.zep',
            'Events/EventInterface.zep',
            'Events/EventsAwareInterface.zep',
            'Events/Exception.zep',
            'Events/Manager.zep',
            'Events/ManagerInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Exception',
        'docs'   => [
            'Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Factory',
        'docs'   => [
            'Factory/AbstractFactory.zep',
            'Factory/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Filter',
        'docs'   => [
            'Filter/Exception.zep',
            'Filter/Filter.zep',
            'Filter/FilterFactory.zep',
            'Filter/FilterInterface.zep',
            'Filter/Sanitize/AbsInt.zep',
            'Filter/Sanitize/Alnum.zep',
            'Filter/Sanitize/Alpha.zep',
            'Filter/Sanitize/BoolVal.zep',
            'Filter/Sanitize/Email.zep',
            'Filter/Sanitize/FloatVal.zep',
            'Filter/Sanitize/IntVal.zep',
            'Filter/Sanitize/Lower.zep',
            'Filter/Sanitize/LowerFirst.zep',
            'Filter/Sanitize/Regex.zep',
            'Filter/Sanitize/Remove.zep',
            'Filter/Sanitize/Replace.zep',
            'Filter/Sanitize/Special.zep',
            'Filter/Sanitize/SpecialFull.zep',
            'Filter/Sanitize/StringVal.zep',
            'Filter/Sanitize/Striptags.zep',
            'Filter/Sanitize/Trim.zep',
            'Filter/Sanitize/Upper.zep',
            'Filter/Sanitize/UpperFirst.zep',
            'Filter/Sanitize/UpperWords.zep',
            'Filter/Sanitize/Url.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Firewall',
        'docs'   => [
            'Firewall/Adapter.zep',
            'Firewall/Adapter/Acl.zep',
            'Firewall/Adapter/Annotations.zep',
            'Firewall/Adapter/Micro/Acl.zep',
            'Firewall/AdapterInterface.zep',
            'Firewall/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Flash',
        'docs'   => [
            'Flash.zep',
            'Flash/Direct.zep',
            'Flash/Exception.zep',
            'Flash/Session.zep',
            'FlashInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Forms',
        'docs'   => [
            'Forms/Element.zep',
            'Forms/Element/Check.zep',
            'Forms/Element/Date.zep',
            'Forms/Element/Email.zep',
            'Forms/Element/File.zep',
            'Forms/Element/Hidden.zep',
            'Forms/Element/Numeric.zep',
            'Forms/Element/Password.zep',
            'Forms/Element/Radio.zep',
            'Forms/Element/Select.zep',
            'Forms/Element/Submit.zep',
            'Forms/Element/Text.zep',
            'Forms/Element/TextArea.zep',
            'Forms/ElementInterface.zep',
            'Forms/Exception.zep',
            'Forms/Form.zep',
            'Forms/Manager.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Helper',
        'docs'   => [
            'Helper/Arr.zep',
            'Helper/Exception.zep',
            'Helper/Number.zep',
            'Helper/Str.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Html',
        'docs'   => [
            'Html/Attributes.zep',
            'Html/Attributes/AttributesInterface.zep',
            'Html/Attributes/RenderInterface.zep',
            'Html/Breadcrumbs.zep',
            'Html/Exception.zep',
            'Html/Helper/AbstractHelper.zep',
            'Html/Helper/Anchor.zep',
            'Html/Helper/AnchorRaw.zep',
            'Html/Helper/Body.zep',
            'Html/Helper/Button.zep',
            'Html/Helper/Close.zep',
            'Html/Helper/Element.zep',
            'Html/Helper/ElementRaw.zep',
            'Html/Helper/Form.zep',
            'Html/Helper/Img.zep',
            'Html/Helper/Label.zep',
            'Html/Helper/TextArea.zep',
            'Html/Tag.zep',
            'Html/TagFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Http',
        'docs'   => [
            'Http/Cookie.zep',
            'Http/Cookie/Exception.zep',
            'Http/CookieInterface.zep',
            'Http/Message/AbstractCommon.zep',
            'Http/Message/AbstractMessage.zep',
            'Http/Message/AbstractRequest.zep',
            'Http/Message/Exception/InvalidArgumentException.zep',
            'Http/Message/Request.zep',
            'Http/Message/RequestFactory.zep',
            'Http/Message/Response.zep',
            'Http/Message/ResponseFactory.zep',
            'Http/Message/ServerRequest.zep',
            'Http/Message/ServerRequestFactory.zep',
            'Http/Message/Stream.zep',
            'Http/Message/Stream/Input.zep',
            'Http/Message/Stream/Memory.zep',
            'Http/Message/Stream/Temp.zep',
            'Http/Message/StreamFactory.zep',
            'Http/Message/UploadedFile.zep',
            'Http/Message/UploadedFileFactory.zep',
            'Http/Message/Uri.zep',
            'Http/Message/UriFactory.zep',
            'Http/Request.zep',
            'Http/Request/Exception.zep',
            'Http/Request/File.zep',
            'Http/Request/FileInterface.zep',
            'Http/RequestInterface.zep',
            'Http/Response.zep',
            'Http/Response/Cookies.zep',
            'Http/Response/CookiesInterface.zep',
            'Http/Response/Exception.zep',
            'Http/Response/Headers.zep',
            'Http/Response/HeadersInterface.zep',
            'Http/ResponseInterface.zep',
            'Http/Server/AbstractMiddleware.zep',
            'Http/Server/AbstractRequestHandler.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Image',
        'docs'   => [
            'Image.zep',
            'Image/Adapter/AbstractAdapter.zep',
            'Image/Adapter/AdapterInterface.zep',
            'Image/Adapter/Gd.zep',
            'Image/Adapter/Imagick.zep',
            'Image/Exception.zep',
            'Image/ImageFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Kernel',
        'docs'   => [
            'Kernel.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Loader',
        'docs'   => [
            'Loader.zep',
            'Loader/Exception.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Logger',
        'docs'   => [
            'Logger/Adapter/AbstractAdapter.zep',
            'Logger/Adapter/AdapterInterface.zep',
            'Logger/Adapter/Noop.zep',
            'Logger/Adapter/Stream.zep',
            'Logger/Adapter/Syslog.zep',
            'Logger/AdapterFactory.zep',
            'Logger/Exception.zep',
            'Logger/Formatter/AbstractFormatter.zep',
            'Logger/Formatter/FormatterInterface.zep',
            'Logger/Formatter/Json.zep',
            'Logger/Formatter/Line.zep',
            'Logger/Formatter/Syslog.zep',
            'Logger/Item.zep',
            'Logger/Logger.zep',
            'Logger/LoggerFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Messages',
        'docs'   => [
            'Messages/Exception.zep',
            'Messages/Message.zep',
            'Messages/MessageInterface.zep',
            'Messages/Messages.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Mvc',
        'docs'   => [
            'Mvc/Application.zep',
            'Mvc/Application/Exception.zep',
            'Mvc/Collection.zep',
            'Mvc/Collection/Behavior.zep',
            'Mvc/Collection/Behavior/SoftDelete.zep',
            'Mvc/Collection/Behavior/Timestampable.zep',
            'Mvc/Collection/BehaviorInterface.zep',
            'Mvc/Collection/Document.zep',
            'Mvc/Collection/Exception.zep',
            'Mvc/Collection/Manager.zep',
            'Mvc/Collection/ManagerInterface.zep',
            'Mvc/CollectionInterface.zep',
            'Mvc/Controller.zep',
            'Mvc/Controller/BindModelInterface.zep',
            'Mvc/ControllerInterface.zep',
            'Mvc/Dispatcher.zep',
            'Mvc/Dispatcher/Exception.zep',
            'Mvc/DispatcherInterface.zep',
            'Mvc/EntityInterface.zep',
            'Mvc/Micro.zep',
            'Mvc/Micro/Collection.zep',
            'Mvc/Micro/CollectionInterface.zep',
            'Mvc/Micro/Exception.zep',
            'Mvc/Micro/LazyLoader.zep',
            'Mvc/Micro/MiddlewareInterface.zep',
            'Mvc/Model.zep',
            'Mvc/Model/Behavior.zep',
            'Mvc/Model/Behavior/SoftDelete.zep',
            'Mvc/Model/Behavior/Timestampable.zep',
            'Mvc/Model/BehaviorInterface.zep',
            'Mvc/Model/Binder.zep',
            'Mvc/Model/Binder/BindableInterface.zep',
            'Mvc/Model/BinderInterface.zep',
            'Mvc/Model/Criteria.zep',
            'Mvc/Model/CriteriaInterface.zep',
            'Mvc/Model/Exception.zep',
            'Mvc/Model/Manager.zep',
            'Mvc/Model/ManagerInterface.zep',
            'Mvc/Model/MetaData.zep',
            'Mvc/Model/MetaData/Apcu.zep',
            'Mvc/Model/MetaData/Libmemcached.zep',
            'Mvc/Model/MetaData/Memory.zep',
            'Mvc/Model/MetaData/Redis.zep',
            'Mvc/Model/MetaData/Strategy/Annotations.zep',
            'Mvc/Model/MetaData/Strategy/Introspection.zep',
            'Mvc/Model/MetaData/StrategyInterface.zep',
            'Mvc/Model/MetaData/Stream.zep',
            'Mvc/Model/MetaDataInterface.zep',
            'Mvc/Model/Query.zep',
            'Mvc/Model/Query/Builder.zep',
            'Mvc/Model/Query/BuilderInterface.zep',
            'Mvc/Model/Query/Lang.zep',
            'Mvc/Model/Query/Status.zep',
            'Mvc/Model/Query/StatusInterface.zep',
            'Mvc/Model/QueryInterface.zep',
            'Mvc/Model/Relation.zep',
            'Mvc/Model/RelationInterface.zep',
            'Mvc/Model/ResultInterface.zep',
            'Mvc/Model/Resultset.zep',
            'Mvc/Model/Resultset/Complex.zep',
            'Mvc/Model/Resultset/Simple.zep',
            'Mvc/Model/ResultsetInterface.zep',
            'Mvc/Model/Row.zep',
            'Mvc/Model/Transaction.zep',
            'Mvc/Model/Transaction/Exception.zep',
            'Mvc/Model/Transaction/Failed.zep',
            'Mvc/Model/Transaction/Manager.zep',
            'Mvc/Model/Transaction/ManagerInterface.zep',
            'Mvc/Model/TransactionInterface.zep',
            'Mvc/Model/ValidationFailed.zep',
            'Mvc/ModelInterface.zep',
            'Mvc/ModuleDefinitionInterface.zep',
            'Mvc/Router.zep',
            'Mvc/Router/Annotations.zep',
            'Mvc/Router/Exception.zep',
            'Mvc/Router/Group.zep',
            'Mvc/Router/GroupInterface.zep',
            'Mvc/Router/Route.zep',
            'Mvc/Router/RouteInterface.zep',
            'Mvc/RouterInterface.zep',
            'Mvc/View.zep',
            'Mvc/View/Engine.zep',
            'Mvc/View/Engine/Php.zep',
            'Mvc/View/Engine/Volt.zep',
            'Mvc/View/Engine/Volt/Compiler.zep',
            'Mvc/View/Engine/Volt/Exception.zep',
            'Mvc/View/EngineInterface.zep',
            'Mvc/View/Exception.zep',
            'Mvc/View/Simple.zep',
            'Mvc/ViewBaseInterface.zep',
            'Mvc/ViewInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Paginator',
        'docs'   => [
            'Paginator/Adapter/AbstractAdapter.zep',
            'Paginator/Adapter/AdapterInterface.zep',
            'Paginator/Adapter/Model.zep',
            'Paginator/Adapter/NativeArray.zep',
            'Paginator/Adapter/QueryBuilder.zep',
            'Paginator/Exception.zep',
            'Paginator/PaginatorFactory.zep',
            'Paginator/Repository.zep',
            'Paginator/RepositoryInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Plugin',
        'docs'   => [
            'Plugin.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Registry',
        'docs'   => [
            'Registry.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Security',
        'docs'   => [
            'Security.zep',
            'Security/Exception.zep',
            'Security/Random.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Session',
        'docs'   => [
            'Session/Adapter/AbstractAdapter.zep',
            'Session/Adapter/Libmemcached.zep',
            'Session/Adapter/Noop.zep',
            'Session/Adapter/Redis.zep',
            'Session/Adapter/Stream.zep',
            'Session/Bag.zep',
            'Session/Exception.zep',
            'Session/Manager.zep',
            'Session/ManagerInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Storage',
        'docs'   => [
            'Storage/Adapter/AbstractAdapter.zep',
            'Storage/Adapter/AdapterInterface.zep',
            'Storage/Adapter/Apcu.zep',
            'Storage/Adapter/Libmemcached.zep',
            'Storage/Adapter/Memory.zep',
            'Storage/Adapter/Redis.zep',
            'Storage/Adapter/Stream.zep',
            'Storage/AdapterFactory.zep',
            'Storage/Exception.zep',
            'Storage/Serializer/AbstractSerializer.zep',
            'Storage/Serializer/Base64.zep',
            'Storage/Serializer/Igbinary.zep',
            'Storage/Serializer/Json.zep',
            'Storage/Serializer/Msgpack.zep',
            'Storage/Serializer/None.zep',
            'Storage/Serializer/Php.zep',
            'Storage/Serializer/SerializerInterface.zep',
            'Storage/SerializerFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Tag',
        'docs'   => [
            'Tag.zep',
            'Tag/Exception.zep',
            'Tag/Select.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Text',
        'docs'   => [
            'Text.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Translate',
        'docs'   => [
            'Translate/Adapter/AbstractAdapter.zep',
            'Translate/Adapter/AdapterInterface.zep',
            'Translate/Adapter/Csv.zep',
            'Translate/Adapter/Gettext.zep',
            'Translate/Adapter/NativeArray.zep',
            'Translate/Exception.zep',
            'Translate/Interpolator/AssociativeArray.zep',
            'Translate/Interpolator/IndexedArray.zep',
            'Translate/Interpolator/InterpolatorInterface.zep',
            'Translate/InterpolatorFactory.zep',
            'Translate/TranslateFactory.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Url',
        'docs'   => [
            'Url.zep',
            'Url/Exception.zep',
            'UrlInterface.zep',
        ],
    ],
    [
        'title'  => 'Phalcon\Validation',
        'docs'   => [
            'Validation.zep',
            'Validation/CombinedFieldsValidator.zep',
            'Validation/Exception.zep',
            'Validation/Validator.zep',
            'Validation/Validator/Alnum.zep',
            'Validation/Validator/Alpha.zep',
            'Validation/Validator/Between.zep',
            'Validation/Validator/Callback.zep',
            'Validation/Validator/Confirmation.zep',
            'Validation/Validator/CreditCard.zep',
            'Validation/Validator/Date.zep',
            'Validation/Validator/Digit.zep',
            'Validation/Validator/Email.zep',
            'Validation/Validator/Exception.zep',
            'Validation/Validator/ExclusionIn.zep',
            'Validation/Validator/File.zep',
            'Validation/Validator/File/FileAbstract.zep',
            'Validation/Validator/File/MimeType.zep',
            'Validation/Validator/File/Resolution',
            'Validation/Validator/File/Resolution/Equal.zep',
            'Validation/Validator/File/Resolution/Max.zep',
            'Validation/Validator/File/Resolution/Min.zep',
            'Validation/Validator/File/Size/Equal.zep',
            'Validation/Validator/File/Size/Max.zep',
            'Validation/Validator/File/Size/Min.zep',
            'Validation/Validator/Identical.zep',
            'Validation/Validator/InclusionIn.zep',
            'Validation/Validator/Ip.zep',
            'Validation/Validator/Numericality.zep',
            'Validation/Validator/PresenceOf.zep',
            'Validation/Validator/Regex.zep',
            'Validation/Validator/StringLength',
            'Validation/Validator/StringLength.zep',
            'Validation/Validator/StringLength/Max.zep',
            'Validation/Validator/StringLength/Min.zep',
            'Validation/Validator/Uniqueness.zep',
            'Validation/Validator/Url.zep',
            'Validation/ValidatorComposite.zep',
            'Validation/ValidatorCompositeInterface.zep',
            'Validation/ValidatorFactory.zep',
            'Validation/ValidatorInterface.zep',
            'ValidationInterface.zep',
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
    foreach ($document['docs'] as $file) {
        $link   = str_replace(['.zep', '/'], ['', '\\'], $file);
        $href   = str_replace(['Phalcon\\', '\\'], ['', '-'], strtolower($link));
        $output .= "
* [Phalcon\\{$link}](#$href)";
    }

    $outputDoc = str_replace('\\', '_', $document['title']) . '.md';
    foreach ($document['docs'] as $file) {
        echo '    - ' . $file . PHP_EOL;
        $github = strtolower($file);
        $href   = str_replace(['.zep', '/'], ['', '-'], $github);
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
            }
            if (1 === ($item['abstract'] ?? 0)) {
                $signature .= ' Abstract';
            }

            $signature           .= ('class' === $type) ? ' Class ' : ' Interface ';
            $signature           .= $return['namespace'] . '\\' . $item['name'];
            $return['signature'] = ltrim(str_replace('Phalcon\\', '', $signature));

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
