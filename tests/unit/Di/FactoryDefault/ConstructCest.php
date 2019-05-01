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
use Phalcon\Di\FactoryDefault;
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

        $expected = count($services);
        $actual   = count($container->getServices());
        $I->assertEquals($expected, $actual);
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
                'class'   => \Phalcon\Crypt::class,
            ],

            [
                'service' => 'cookies',
                'class'   => \Phalcon\Http\Response\Cookies::class,
            ],

            [
                'service' => 'dispatcher',
                'class'   => \Phalcon\Mvc\Dispatcher::class,
            ],

            [
                'service' => 'escaper',
                'class'   => \Phalcon\Escaper::class,
            ],

            [
                'service' => 'eventsManager',
                'class'   => \Phalcon\Events\Manager::class,
            ],

            [
                'service' => 'flash',
                'class'   => \Phalcon\Flash\Direct::class,
            ],

            [
                'service' => 'flashSession',
                'class'   => \Phalcon\Flash\Session::class,
            ],

            [
                'service' => 'filter',
                'class'   => \Phalcon\Filter\FilterLocator::class,
            ],

            // [
            //     'service' => 'filter',
            //     'class'   => \Phalcon\Filter::class,
            // ],

            [
                'service' => 'modelsManager',
                'class'   => \Phalcon\Mvc\Model\Manager::class,
            ],

            [
                'service' => 'modelsMetadata',
                'class'   => \Phalcon\Mvc\Model\MetaData\Memory::class,
            ],

            [
                'service' => 'request',
                'class'   => \Phalcon\Http\Request::class,
            ],

            [
                'service' => 'response',
                'class'   => \Phalcon\Http\Response::class,
            ],

            [
                'service' => 'router',
                'class'   => \Phalcon\Mvc\Router::class,
            ],

            [
                'service' => 'security',
                'class'   => \Phalcon\Security::class,
            ],

            [
                'service' => 'tag',
                'class'   => \Phalcon\Tag::class,
            ],

            [
                'service' => 'transactionManager',
                'class'   => \Phalcon\Mvc\Model\Transaction\Manager::class,
            ],

            [
                'service' => 'url',
                'class'   => \Phalcon\Url::class,
            ],
        ];
    }

    /**
     * Tests Phalcon\Di\FactoryDefault :: __construct() - Check services
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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
