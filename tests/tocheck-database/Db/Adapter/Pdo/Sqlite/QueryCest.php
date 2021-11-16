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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;
use Phalcon\Db\Enum;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use function is_array;

class QueryCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteQuery(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - query()');

        $connection = $this->getService('db');

        $result = $connection->query('SELECT * FROM personas LIMIT 3');

        $I->assertTrue(is_object($result));

        $I->assertInstanceOf(
            \Phalcon\Db\Result\Pdo::class,
            $result
        );

        for ($i = 0; $i < 3; $i++) {
            $row = $result->fetch();
            $I->assertCount(22, $row);
        }

        $row = $result->fetch();
        $I->assertFalse($row);
        $I->assertEquals(3, $result->numRows());


        $number = 0;
        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $I->assertTrue(is_object($result));

        while ($row = $result->fetch()) {
            $number++;
        }
        $I->assertEquals(5, $number);


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_NUM);
        $row = $result->fetch();
        $I->assertTrue(is_array($row));
        $I->assertCount(11, $row);
        $I->assertTrue(isset($row[0]));
        $I->assertFalse(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_ASSOC);
        $row = $result->fetch();
        $I->assertTrue(is_array($row));
        $I->assertCount(11, $row);
        $I->assertFalse(isset($row[0]));
        $I->assertTrue(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_OBJ);
        $row = $result->fetch();
        $I->assertTrue(is_object($row));
        $I->assertTrue(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_BOTH);
        $result->dataSeek(4);
        $row = $result->fetch();
        $row = $result->fetch();
        $I->assertEquals($row, false);
    }
}
