<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use Codeception\Example;
use Phalcon\Crypt;
use Phalcon\Di\FactoryDefault;
use Phalcon\Escaper;
use Phalcon\Filter\Filter;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Session;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Mvc\Dispatcher;
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
     * @author Phalcon Team <team@phalconphp.com>
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
                'class'   => \Phalcon\Annotations\Adapter\Memory::class,
            ],

            [
                'service' => 'assets',
                'class'   => \Phalcon\Assets\Manager::class,
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
                'class'   => \Phalcon\Events\Manager::class,
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
                'class'   => \Phalcon\Mvc\Model\Manager::class,
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
     * @author       Phalcon Team <team@phalconphp.com>
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
