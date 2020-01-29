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

namespace Phalcon\Test\Integration\Db\Adapter\PdoFactory;

use IntegrationTester;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;

use function array_intersect_assoc;

class LoadCest
{
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     */
    public function dbAdapterPdoFactoryLoad(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\PdoFactory - load()');

        $options = $this->config->database;
        $data    = $options->toArray();

        $this->runTests($I, $options, $data);
    }

    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: load() - array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     */
    public function dbAdapterPdoFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\PdoFactory - load() - array');

        $options = $this->arrayConfig['database'];
        $data    = $options;

        $this->runTests($I, $options, $data);
    }

    private function runTests(IntegrationTester $I, $options, array $data)
    {
        /** @var Mysql $database */
        $factory = new PdoFactory();
        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            Mysql::class,
            $adapter
        );

        $expected = array_intersect_assoc(
            $adapter->getDescriptor(),
            $data['options']
        );

        $I->assertEquals(
            $expected,
            $adapter->getDescriptor()
        );
    }
}
