
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

namespace Phalcon\Container\Provider;

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\DispatcherInterface;
use Phalcon\Cli\Router;
use Phalcon\Cli\RouterInterface;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Contracts\Container\Service\Provider;
use Phalcon\Contracts\Encryption\Security\Security as SecurityContract;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Filter\FilterFactory;
use Phalcon\Filter\FilterInterface;
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Model\Manager as ModelManager;
use Phalcon\Mvc\Model\ManagerInterface as ModelManagerInterface;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\MetaData\Memory as ModelMetaDataMemory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Mvc\Model\Transaction\ManagerInterface as TransactionManagerInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;

class Cli implements Provider
{
    /**
     * Provider for commonly used CLI applications
     *
     * @param Collection $services
     *
     * @return void
     */
    public function provide(<Collection> services) -> void
    {
        // --- Interface bindings (bind + alias) ---

        services->bind(DispatcherInterface::class, Dispatcher::class);
        services->setAlias(DispatcherInterface::class, "dispatcher");

        services->bind(EscaperInterface::class, Escaper::class);
        services->setAlias(EscaperInterface::class, "escaper");

        services->bind(EventsManagerInterface::class, EventsManager::class);
        services->setAlias(EventsManagerInterface::class, "eventsManager");

        services->set(
            FilterInterface::class,
            function (container) {
                return (new FilterFactory())->newInstance();
            }
        );
        services->setAlias(FilterInterface::class, "filter");

        services->bind(ModelManagerInterface::class, ModelManager::class);
        services->setAlias(ModelManagerInterface::class, "modelsManager");

        services->bind(MetaDataInterface::class, ModelMetaDataMemory::class);
        services->setAlias(MetaDataInterface::class, "modelsMetadata");

        services->bind(RouterInterface::class, Router::class);
        services->setAlias(RouterInterface::class, "router");

        services->bind(TransactionManagerInterface::class, TransactionManager::class);
        services->setAlias(TransactionManagerInterface::class, "transactionManager");

        // --- FQCN bindings (set + alias) - no unique interface available ---

        services->set(
            AccessLocator::class,
            function (container) {
                return new AccessLocator(container);
            }
        );

        services->set(AnnotationsMemory::class, AnnotationsMemory::class);
        services->setAlias(AnnotationsMemory::class, "annotationsMemory");

        services->set(HelperFactory::class, HelperFactory::class);
        services->setAlias(HelperFactory::class, "helper");

        services->bind(SecurityContract::class, Security::class);
        services->setAlias(SecurityContract::class, "security");

        services->set(SerializerFactory::class, SerializerFactory::class);
        services->setAlias(SerializerFactory::class, "storageSerializer");

        services->set(Settings::class, Settings::class);
        services->setAlias(Settings::class, "settings");

        services->set(TagFactory::class, TagFactory::class);
        services->setAlias(TagFactory::class, "tag");
    }
}
