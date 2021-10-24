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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Codeception\Example;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Di\FactoryDefault\Cli;
use Phalcon\Escaper;
use Phalcon\Filter\Filter;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\Transaction\Manager;
use Phalcon\Security;

class ConstructCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliConstruct(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - __construct()');

        $container = new Cli();
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
                'service' => 'router',
                'class'   => Router::class,
            ],

            [
                'service' => 'security',
                'class'   => Security::class,
            ],

            [
                'service' => 'transactionManager',
                'class'   => Manager::class,
            ],
        ];
    }

    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: __construct() - Check services
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider getServices
     */
    public function diFactoryDefaultCliConstructServices(CliTester $I, Example $example)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - __construct() - Check services');

        $container = new Cli();

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
