<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Factory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Factory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use IntegrationTester;

class LoadCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->annotations;
        $data    = $options->toArray();
        $this->runTests($I, $options, $data);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["annotations"];
        $data    = $options;
        $this->runTests($I, $options, $data);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param UnitTester   $I
     * @param Config|array $options
     * @param array        $data
     */
    private function runTests(UnitTester $I, $options, array $data)
    {
        /** @var Mysql $database */
        $database = Factory::load($options);

        $class  = Mysql::class;
        $actual = $database;
        $I->assertInstanceOf($class, $actual);

        $expected = array_intersect_assoc($database->getDescriptor(), $data);
        $actual   = $database->getDescriptor();
        $I->assertInstanceOf($expected, $actual);
    }
}
