<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\FactoryDefault\Cli;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Cli\Dispatcher;
use Phalcon\Cli\Router;
use Phalcon\Di\FactoryDefault\Cli;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Model\Manager as ModelManager;
use Phalcon\Mvc\Model\MetaData\Memory as MemoryMedaData;
use Phalcon\Mvc\Model\Transaction\Manager as ManagerTransaction;
use UnitTester;

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault\Cli :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultCliConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - __construct()');

        $di = new Cli();

        $I->assertSame(
            count($this->getServices()),
            count($di->getServices())
        );

        /**
         * @todo filter service throwing an exception when try to get it
         */
        foreach ($this->getServices() as $name => $class) {
            $I->assertTrue($di->has($name));
        }
    }

    /**
     * Default CLI factory services
     */
    private function getServices(): array
    {
        return [
            'annotations'        => Memory::class,
            'dispatcher'         => Dispatcher::class,
            'escaper'            => Escaper::class,
            'eventsManager'      => Manager::class,
            'filter'             => Filter::class,
            'modelsManager'      => ModelManager::class,
            'modelsMetadata'     => MemoryMedaData::class,
            'router'             => Router::class,
            'security'           => Security::class,
            'transactionManager' => ManagerTransaction::class,
        ];
    }
}
