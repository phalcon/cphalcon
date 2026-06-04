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

use Phalcon\Annotations\Adapter\Memory as AnnotationsMemory;
use Phalcon\Assets\Manager as AssetsManager;
use Phalcon\Container\Container;
use Phalcon\Container\ContainerFactory;
use Phalcon\Container\Provider\Web;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\CryptInterface;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Filter\Filter;
use Phalcon\Filter\FilterInterface;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Session;
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\TagFactory;
use Phalcon\Http\Request;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\ManagerInterface as ModelsManagerInterface;
use Phalcon\Mvc\Model\MetaData\Memory as MetadataMemory;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Mvc\Model\Transaction\ManagerInterface as TransactionManagerInterface;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\Url\UrlInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;

final class WebTest extends AbstractUnitTestCase
{
    private Container $container;

    protected function setUp(): void
    {
        $this->container = (new ContainerFactory())
            ->addProvider(new Web())
            ->newContainer();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebAliasAndInterfaceReturnSameInstance(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $viaAlias     = $this->container->get('router');
        $viaInterface = $this->container->get(RouterInterface::class);
        $this->assertSame($viaAlias, $viaInterface);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebAllServiceNamesResolvable(): void
    {
        $names = [
            'annotationsMemory', 'assets', 'cookies', 'crypt',
            'dispatcher', 'escaper', 'eventsManager', 'filter', 'flash',
            'flashSession', 'helper', 'modelsManager',
            'modelsMetadata', 'request', 'response', 'router', 'security',
            'settings', 'storageSerializer', 'tag', 'transactionManager', 'url',
        ];

        foreach ($names as $name) {
            $this->assertTrue($this->container->has($name), "Service '{$name}' should be resolvable");
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebInterfacesResolvable(): void
    {
        $interfaces = [
            CookiesInterface::class,
            CryptInterface::class,
            DispatcherInterface::class,
            EscaperInterface::class,
            EventsManagerInterface::class,
            FilterInterface::class,
            MetaDataInterface::class,
            ModelsManagerInterface::class,
            RequestInterface::class,
            ResponseInterface::class,
            RouterInterface::class,
            TransactionManagerInterface::class,
            UrlInterface::class,
        ];

        foreach ($interfaces as $interface) {
            $this->assertTrue($this->container->has($interface), "Interface '{$interface}' should be resolvable");
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesCookies(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Cookies::class, $this->container->get('cookies'));
        $this->assertInstanceOf(CookiesInterface::class, $this->container->get(CookiesInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesCrypt(): void
    {
        $this->assertInstanceOf(Crypt::class, $this->container->get('crypt'));
        $this->assertInstanceOf(CryptInterface::class, $this->container->get(CryptInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesDispatcher(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Dispatcher::class, $this->container->get('dispatcher'));
        $this->assertInstanceOf(DispatcherInterface::class, $this->container->get(DispatcherInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesEscaper(): void
    {
        $this->assertInstanceOf(Escaper::class, $this->container->get('escaper'));
        $this->assertInstanceOf(EscaperInterface::class, $this->container->get(EscaperInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesEventsManager(): void
    {
        $this->assertInstanceOf(EventsManager::class, $this->container->get('eventsManager'));
        $this->assertInstanceOf(EventsManagerInterface::class, $this->container->get(EventsManagerInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesFilter(): void
    {
        $this->assertInstanceOf(Filter::class, $this->container->get('filter'));
        $this->assertInstanceOf(FilterInterface::class, $this->container->get(FilterInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesFlash(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Direct::class, $this->container->get('flash'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesFlashSession(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Session::class, $this->container->get('flashSession'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesHelper(): void
    {
        $this->assertInstanceOf(HelperFactory::class, $this->container->get('helper'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesModelsManager(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(ModelsManager::class, $this->container->get('modelsManager'));
        $this->assertInstanceOf(ModelsManagerInterface::class, $this->container->get(ModelsManagerInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesModelsMetadata(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(MetadataMemory::class, $this->container->get('modelsMetadata'));
        $this->assertInstanceOf(MetaDataInterface::class, $this->container->get(MetaDataInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesRequest(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Request::class, $this->container->get('request'));
        $this->assertInstanceOf(RequestInterface::class, $this->container->get(RequestInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesResponse(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Response::class, $this->container->get('response'));
        $this->assertInstanceOf(ResponseInterface::class, $this->container->get(ResponseInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesRouter(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Router::class, $this->container->get('router'));
        $this->assertInstanceOf(RouterInterface::class, $this->container->get(RouterInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesSecurity(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Security::class, $this->container->get('security'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesSettings(): void
    {
        $this->assertInstanceOf(Settings::class, $this->container->get('settings'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesStorageSerializer(): void
    {
        $this->assertInstanceOf(SerializerFactory::class, $this->container->get('storageSerializer'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesTag(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(TagFactory::class, $this->container->get('tag'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebRegistersTransactionManager(): void
    {
        // Resolution requires a Di container internally (hardcoded dependency).
        // Verify registration only until Container replaces Di as the framework container.
        $this->assertTrue($this->container->has('transactionManager'));
        $this->assertTrue($this->container->has(TransactionManagerInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebResolvesUrl(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(Url::class, $this->container->get('url'));
        $this->assertInstanceOf(UrlInterface::class, $this->container->get(UrlInterface::class));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebServicesAreShared(): void
    {
        $a = $this->container->get('escaper');
        $b = $this->container->get('escaper');
        $this->assertSame($a, $b);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerProviderWebTagDependsOnEscaper(): void
    {
        $this->markTestSkipped('Enable after setDI is addressed');

        $this->assertInstanceOf(TagFactory::class, $this->container->get('tag'));
        $this->assertInstanceOf(Escaper::class, $this->container->get('escaper'));
    }
}
