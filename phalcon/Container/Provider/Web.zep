
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

use Phalcon\Auth\Access\AccessLocator;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Contracts\Container\Service\Provider;
use Phalcon\Filter\Filter;
use Phalcon\Filter\FilterFactory;

class Web implements Provider
{
    /**
     * Provider for commonly used Web applications
     *
     * @param Collection $services
     *
     * @return void
     */
    public function provide(<Collection> services) -> void
    {
        // --- Interface bindings (bind + alias) ---

        services->bind("Phalcon\\Http\\Response\\CookiesInterface", "Phalcon\\Http\\Response\\Cookies");
        services->setAlias("Phalcon\\Http\\Response\\CookiesInterface", "cookies");

        services->bind("Phalcon\\Encryption\\Crypt\\CryptInterface", "Phalcon\\Encryption\\Crypt");
        services->setAlias("Phalcon\\Encryption\\Crypt\\CryptInterface", "crypt");

        services->bind("Phalcon\\Mvc\\DispatcherInterface", "Phalcon\\Mvc\\Dispatcher");
        services->setAlias("Phalcon\\Mvc\\DispatcherInterface", "dispatcher");

        services->bind("Phalcon\\Html\\Escaper\\EscaperInterface", "Phalcon\\Html\\Escaper");
        services->setAlias("Phalcon\\Html\\Escaper\\EscaperInterface", "escaper");

        services->bind("Phalcon\\Events\\ManagerInterface", "Phalcon\\Events\\Manager");
        services->setAlias("Phalcon\\Events\\ManagerInterface", "eventsManager");

        services->set(
            "Phalcon\\Filter\\FilterInterface",
            function (container) {
                return (new FilterFactory())->newInstance();
            }
        );
        services->setAlias("Phalcon\\Filter\\FilterInterface", "filter");

        services->bind("Phalcon\\Mvc\\Model\\ManagerInterface", "Phalcon\\Mvc\\Model\\Manager");
        services->setAlias("Phalcon\\Mvc\\Model\\ManagerInterface", "modelsManager");

        services->bind("Phalcon\\Mvc\\Model\\MetaDataInterface", "Phalcon\\Mvc\\Model\\MetaData\\Memory");
        services->setAlias("Phalcon\\Mvc\\Model\\MetaDataInterface", "modelsMetadata");

        services->bind("Phalcon\\Http\\RequestInterface", "Phalcon\\Http\\Request");
        services->setAlias("Phalcon\\Http\\RequestInterface", "request");

        services->bind("Phalcon\\Http\\ResponseInterface", "Phalcon\\Http\\Response");
        services->setAlias("Phalcon\\Http\\ResponseInterface", "response");

        services->bind("Phalcon\\Mvc\\RouterInterface", "Phalcon\\Mvc\\Router");
        services->setAlias("Phalcon\\Mvc\\RouterInterface", "router");

        services->bind("Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface", "Phalcon\\Mvc\\Model\\Transaction\\Manager");
        services->setAlias("Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface", "transactionManager");

        services->bind("Phalcon\\Mvc\\Url\\UrlInterface", "Phalcon\\Mvc\\Url");
        services->setAlias("Phalcon\\Mvc\\Url\\UrlInterface", "url");

        // --- FQCN bindings (set + alias) - no unique interface available ---

        services->set(
            "Phalcon\\Auth\\Access\\AccessLocator",
            function (container) {
                return new AccessLocator(container);
            }
        );

        services->set("Phalcon\\Annotations\\Adapter\\Memory", "Phalcon\\Annotations\\Adapter\\Memory");
        services->setAlias("Phalcon\\Annotations\\Adapter\\Memory", "annotationsMemory");

        services->set("Phalcon\\Assets\\Manager", "Phalcon\\Assets\\Manager");
        services->setAlias("Phalcon\\Assets\\Manager", "assets");

        services->set("Phalcon\\Flash\\Direct", "Phalcon\\Flash\\Direct");
        services->setAlias("Phalcon\\Flash\\Direct", "flash");

        services->set("Phalcon\\Support\\HelperFactory", "Phalcon\\Support\\HelperFactory");
        services->setAlias("Phalcon\\Support\\HelperFactory", "helper");

        services->bind("Phalcon\\Contracts\\Encryption\\Security\\Security", "Phalcon\\Encryption\\Security");
        services->setAlias("Phalcon\\Contracts\\Encryption\\Security\\Security", "security");

        services->set("Phalcon\\Storage\\SerializerFactory", "Phalcon\\Storage\\SerializerFactory");
        services->setAlias("Phalcon\\Storage\\SerializerFactory", "storageSerializer");

        services->set("Phalcon\\Flash\\Session", "Phalcon\\Flash\\Session");
        services->setAlias("Phalcon\\Flash\\Session", "flashSession");

        services->set("Phalcon\\Support\\Settings", "Phalcon\\Support\\Settings");
        services->setAlias("Phalcon\\Support\\Settings", "settings");

        services->set("Phalcon\\Html\\TagFactory", "Phalcon\\Html\\TagFactory");
        services->setAlias("Phalcon\\Html\\TagFactory", "tag");
    }
}
