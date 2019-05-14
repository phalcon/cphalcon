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

class LoadCest
{
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - Config
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
     * @param Config|array $options
     */
    private function runTests(IntegrationTester $I, $options, array $data)
    {
        /** @var Mysql $database */
        $database = Factory::load($options);

        $I->assertInstanceOf(
            Mysql::class,
            $database
        );

        $expected = array_intersect_assoc(
            $database->getDescriptor(),
            $data
        );

        $I->assertEquals(
            $expected,
            $database->getDescriptor()
        );
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function dbAdapterPdoFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Factory - load() - array");

        $options = $this->arrayConfig['database'];
        $data    = $options;

        $this->runTests($I, $options, $data);
    }
}
