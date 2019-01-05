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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Factory;

use IntegrationTester;
use Phalcon\Config;
use Phalcon\Db\Adapter\Pdo\Factory;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;

/**
 * Class LoadCest
 */
class LoadCest
{
    use FactoryTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - Config
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function dbAdapterPdoFactoryLoadConfig(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Factory - load() - Config");
        $options = $this->config->database;
        $data    = $options->toArray();
        $this->runTests($I, $options, $data);
    }

    /**
     * @param IntegrationTester $I
     * @param Config|Array      $options
     * @param array             $data
     */
    private function runTests(IntegrationTester $I, $options, array $data)
    {
        /** @var Mysql $database */
        $database = Factory::load($options);

        $class  = Mysql::class;
        $actual = $database;
        $I->assertInstanceOf($class, $actual);

        $expected = array_intersect_assoc($database->getDescriptor(), $data);
        $actual   = $database->getDescriptor();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - array
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function dbAdapterPdoFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Factory - load() - array");
        $options = $this->arrayConfig["database"];
        $data    = $options;
        $this->runTests($I, $options, $data);
    }
}
