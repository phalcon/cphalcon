<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use DatabaseTester;
use PDO;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function getOptionsMysql;

class ConnectCest
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @param DatabaseTester $I
     *
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: connect() - persistent
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     *
     * @group  mysql
     */
    public function dbAdapterPdoConnectPersistent(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - connect() - supported');

        $options = getOptionsMysql();
        $options['persistent'] = true;
        $options['options']    = [
            PDO::ATTR_EMULATE_PREPARES  => false,
            PDO::ATTR_STRINGIFY_FETCHES => false,
        ];

        $connection = (new PdoFactory())->newInstance('mysql', $options);

        $expected = $options;
        $actual   = $connection->getDescriptor();

        $I->assertEquals($expected, $actual);
    }
}
