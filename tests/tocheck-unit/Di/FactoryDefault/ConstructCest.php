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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use Codeception\Example;
use Phalcon\Annotations\Adapter\Memory as MemoryAnnotations;
use Phalcon\Assets\Manager as ManagerAssets;
use Phalcon\Crypt;
use Phalcon\Di\FactoryDefault;
use Phalcon\Escaper;
use Phalcon\Events\Manager as ManagerEvents;
use Phalcon\Filter;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Session;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Manager as ManagerModel;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Mvc\Router;
use Phalcon\Security;
use Phalcon\Tag;
use Phalcon\Url;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactoryDefaultConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - __construct()');

        $container = new FactoryDefault();
        $services  = $this->getServices();

        $I->assertEquals(
            count($services),
            count($container->getServices())
        );
    }

    private function getServices(): array
    {
        return [
            [
                'service' => 'annotations',
                'class'   => MemoryAnnotations::class,
            ],

            [
                'service' => 'assets',
                'class'   => ManagerAssets::class,
            ],

            [
                'service' => 'crypt',
                'class'   => Crypt::class,
            ],

            [
                'service' => 'cookies',
                'class'   => Cookies::class,
            ],

            [
                'service' => 'dispatcher',
                'class'   => Dispatcher::class,
            ],

            [
                'service' => 'escaper',
                'class'   => Escaper::class,
            ],

            [
                'service' => 'eventsManager',
                'class'   => ManagerEvents::class,
            ],

            [
                'service' => 'flash',
                'class'   => Direct::class,
            ],

            [
                'service' => 'flashSession',
                'class'   => Session::class,
            ],

            [
                'service' => 'filter',
                'class'   => Filter::class,
            ],

            [
                'service' => 'modelsManager',
                'class'   => ManagerModel::class,
            ],

            [
                'service' => 'modelsMetadata',
                'class'   => Memory::class,
            ],

            [
                'service' => 'request',
                'class'   => Request::class,
            ],

            [
                'service' => 'response',
                'class'   => Response::class,
            ],

            [
                'service' => 'router',
                'class'   => Router::class,
            ],

            [
                'service' => 'security',
                'class'   => Security::class,
            ],

            [
                'service' => 'tag',
                'class'   => Tag::class,
            ],

            [
                'service' => 'transactionManager',
                'class'   => Manager::class,
            ],

            [
                'service' => 'url',
                'class'   => Url::class,
            ],
        ];
    }

    /**
     * Tests Phalcon\Di\FactoryDefault :: __construct() - Check services
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider getServices
     */
    public function diFactoryDefaultConstructServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Di\FactoryDefault - __construct() - Check services');

        $container = new FactoryDefault();

        if ('sessionBag' === $example['service']) {
            $params = ['someName'];
        } else {
            $params = null;
        }

        $I->assertInstanceOf(
            $example['class'],
            $container->get(
                $example['service'],
                $params
            )
        );
    }
}
