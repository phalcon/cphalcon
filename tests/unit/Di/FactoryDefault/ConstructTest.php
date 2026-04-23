<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di\FactoryDefault;

use Phalcon\Annotations\Adapter\Memory as MemoryAnnotations;
use Phalcon\Assets\Manager as ManagerAssets;
use Phalcon\Di\FactoryDefault;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Security;
use Phalcon\Events\Manager as ManagerEvents;
use Phalcon\Filter\Filter;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Session;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Url;
use Phalcon\Support\HelperFactory;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getServices(): array
    {
        return [
            [
                'annotations',
                MemoryAnnotations::class,
            ],
            [
                'assets',
                ManagerAssets::class,
            ],
            [
                'crypt',
                Crypt::class,
            ],
            [
                'cookies',
                Cookies::class,
            ],
            [
                'dispatcher',
                Dispatcher::class,
            ],
            [
                'escaper',
                Escaper::class,
            ],
            [
                'eventsManager',
                ManagerEvents::class,
            ],
            [
                'flash',
                Direct::class,
            ],
            [
                'flashSession',
                Session::class,
            ],
            [
                'filter',
                Filter::class,
            ],
            [
                'helper',
                HelperFactory::class,
            ],
            [
                'settings',
                Settings::class,
            ],
            [
                'modelsManager',
                ModelsManager::class,
            ],
            [
                'modelsMetadata',
                Memory::class,
            ],
            [
                'request',
                Request::class,
            ],
            [
                'response',
                Response::class,
            ],
            [
                'router',
                Router::class,
            ],
            [
                'security',
                Security::class,
            ],
            [
                'tag',
                TagFactory::class,
            ],
            [
                'transactionManager',
                TransactionManager::class,
            ],
            [
                'url',
                Url::class,
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactoryDefaultConstruct(): void
    {
        $container = new FactoryDefault();

        $expected = 21;
        $actual   = count($container->getServices());
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getServices
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactoryDefaultConstructServices(
        string $service,
        string $class
    ): void {
        $container = new FactoryDefault();

        if ('sessionBag' === $service) {
            $params = ['someName'];
        } else {
            $params = null;
        }

        $actual = $container->get($service, $params);
        $this->assertInstanceOf($class, $actual);
    }
}
