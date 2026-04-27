<?php

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

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Provider;

use Phalcon\Container\Container;
use Phalcon\Container\ContainerFactory;
use Phalcon\Container\Provider\Cli;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\DispatcherInterface;
use Phalcon\Cli\Router;
use Phalcon\Cli\RouterInterface;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Filter\Filter;
use Phalcon\Filter\FilterInterface;
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Dispatcher as MvcDispatcher;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\ManagerInterface as ModelsManagerInterface;
use Phalcon\Mvc\Model\MetaData\Memory as MetadataMemory;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\Transaction\ManagerInterface as TransactionManagerInterface;
use Phalcon\Mvc\Router as MvcRouter;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;

final class CliTest extends AbstractUnitTestCase
{
    private Container $container;

    protected function setUp(): void
    {
        $this->container = (new ContainerFactory())
            ->addProvider(new Cli())
            ->newContainer();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliAliasAndInterfaceReturnSameInstance(): void
    {
        $viaAlias     = $this->container->get('router');
        $viaInterface = $this->container->get(RouterInterface::class);
        $this->assertSame($viaAlias, $viaInterface);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliAllServiceNamesResolvable(): void
    {
        $names = [
            'annotations',
            'dispatcher',
            'escaper',
            'eventsManager',
            'filter',
            'helper',
            'modelsManager',
            'modelsMetadata',
            'router',
            'security',
            'settings',
            'storageSerializer',
            'tag',
            'transactionManager',
        ];

        foreach ($names as $name) {
            $this->assertTrue(
                $this->container->has($name),
                "Service '{$name}' should be resolvable"
            );
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliDoesNotRegisterWebOnlyServices(): void
    {
        $this->assertFalse($this->container->has('cookies'));
        $this->assertFalse($this->container->has('crypt'));
        $this->assertFalse($this->container->has('flash'));
        $this->assertFalse($this->container->has('flashSession'));
        $this->assertFalse($this->container->has('request'));
        $this->assertFalse($this->container->has('response'));
        $this->assertFalse($this->container->has('url'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliInterfacesResolvable(): void
    {
        $interfaces = [
            DispatcherInterface::class,
            EscaperInterface::class,
            EventsManagerInterface::class,
            FilterInterface::class,
            MetaDataInterface::class,
            ModelsManagerInterface::class,
            RouterInterface::class,
            TransactionManagerInterface::class,
        ];

        foreach ($interfaces as $interface) {
            $this->assertTrue(
                $this->container->has($interface),
                "Interface '{$interface}' should be resolvable"
            );
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesDispatcher(): void
    {
        $this->assertInstanceOf(
            Dispatcher::class,
            $this->container->get('dispatcher')
        );
        $this->assertInstanceOf(
            DispatcherInterface::class,
            $this->container->get(DispatcherInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesEscaper(): void
    {
        $this->assertInstanceOf(
            Escaper::class,
            $this->container->get('escaper')
        );
        $this->assertInstanceOf(
            EscaperInterface::class,
            $this->container->get(EscaperInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesEventsManager(): void
    {
        $this->assertInstanceOf(
            EventsManager::class,
            $this->container->get('eventsManager')
        );
        $this->assertInstanceOf(
            EventsManagerInterface::class,
            $this->container->get(EventsManagerInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesFilter(): void
    {
        $this->assertInstanceOf(
            Filter::class,
            $this->container->get('filter')
        );
        $this->assertInstanceOf(
            FilterInterface::class,
            $this->container->get(FilterInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesHelper(): void
    {
        $this->assertInstanceOf(
            HelperFactory::class,
            $this->container->get('helper')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesModelsManager(): void
    {
        $this->assertInstanceOf(
            ModelsManager::class,
            $this->container->get('modelsManager')
        );
        $this->assertInstanceOf(
            ModelsManagerInterface::class,
            $this->container->get(ModelsManagerInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesModelsMetadata(): void
    {
        $this->assertInstanceOf(
            MetadataMemory::class,
            $this->container->get('modelsMetadata')
        );
        $this->assertInstanceOf(
            MetaDataInterface::class,
            $this->container->get(MetaDataInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesRouter(): void
    {
        $this->assertInstanceOf(
            Router::class,
            $this->container->get('router')
        );
        $this->assertInstanceOf(
            RouterInterface::class,
            $this->container->get(RouterInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesSecurity(): void
    {
        $this->assertInstanceOf(
            Security::class,
            $this->container->get('security')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesSettings(): void
    {
        $this->assertInstanceOf(
            Settings::class,
            $this->container->get('settings')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesStorageSerializer(): void
    {
        $this->assertInstanceOf(
            SerializerFactory::class,
            $this->container->get('storageSerializer')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliResolvesTag(): void
    {
        $this->assertInstanceOf(
            TagFactory::class,
            $this->container->get('tag')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliRegistersTransactionManager(): void
    {
        $this->assertTrue($this->container->has('transactionManager'));
        $this->assertTrue(
            $this->container->has(TransactionManagerInterface::class)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliServicesAreShared(): void
    {
        $a = $this->container->get('escaper');
        $b = $this->container->get('escaper');
        $this->assertSame($a, $b);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliUsesCliDispatcherNotMvc(): void
    {
        $dispatcher = $this->container->get('dispatcher');
        $this->assertInstanceOf(Dispatcher::class, $dispatcher);
        $this->assertNotInstanceOf(MvcDispatcher::class, $dispatcher);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderCliUsesCliRouterNotMvc(): void
    {
        $router = $this->container->get('router');
        $this->assertInstanceOf(Router::class, $router);
        $this->assertNotInstanceOf(MvcRouter::class, $router);
    }
}
