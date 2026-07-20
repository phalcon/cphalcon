
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Assets\Manager as AssetsManager;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Filter\FilterFactory;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Session;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Manager as ModelManager;
use Phalcon\Mvc\Model\MetaData\Memory as ModelMetaDataMemory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Url;
use Phalcon\Queue\QueueFactory;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;

/**
 * This is a variant of the standard Phalcon\Di\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the
 * developer does not need to register each service individually providing a
 * full stack framework
 */
class FactoryDefault extends \Phalcon\Di\Di
{
    /**
     * Phalcon\Di\FactoryDefault constructor
     */
    public function __construct()
    {
        var filter;

        parent::__construct();

        let filter = new FilterFactory();

        let this->services = [
            "annotations"        : new Service(AnnotationsMemory::class, true),
            "assets"             : new Service(
                [
                    "className" : AssetsManager::class,
                    "arguments" : [
                        [
                            "type" : "service",
                            "name" : "tag"
                        ]
                    ]
                ],
                true
            ),
            "crypt"              : new Service(Crypt::class, true),
            "cookies"            : new Service(Cookies::class, true),
            "dispatcher"         : new Service(Dispatcher::class, true),
            "escaper"            : new Service(Escaper::class, true),
            "eventsManager"      : new Service(EventsManager::class, true),
            "flash"              : new Service(Direct::class, true),
            "flashSession"       : new Service(Session::class, true),
            "filter"             : new Service(filter->newInstance(), true),
            "helper"             : new Service(HelperFactory::class, true),
            "settings"           : new Service(Settings::class, true),
            "modelsManager"      : new Service(ModelManager::class, true),
            "modelsMetadata"     : new Service(ModelMetaDataMemory::class, true),
            "queueFactory"       : new Service(QueueFactory::class, true),
            "request"            : new Service(Request::class, true),
            "response"           : new Service(Response::class, true),
            "router"             : new Service(Router::class, true),
            "security"           : new Service(Security::class, true),
            "tag"                : new Service(
                [
                    "className" : TagFactory::class,
                    "arguments" : [
                        [
                            "type" : "service",
                            "name" : "escaper"
                        ]
                    ]
                ],
                true
            ),
            "transactionManager" : new Service(TransactionManager::class, true),
            "url"                : new Service(Url::class, true)
        ];

//        this->setShared(
//            "assets",
//            [
//                "className" : "Phalcon\\Assets\\Manager",
//                "arguments" : [
//                    [
//                        "type" : "service",
//                        "name" : "tag"
//                    ]
//                ]
//            ]
//        );
//
//        this->setShared(
//            "tag",
//            [
//                "className" : "Phalcon\\Html\\TagFactory",
//                "arguments" : [
//                    [
//                        "type" : "service",
//                        "name" : "escaper"
//                    ]
//                ]
//            ]
//        );
    }
}
