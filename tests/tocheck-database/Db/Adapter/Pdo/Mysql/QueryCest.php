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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Db\Enum;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class QueryCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlQuery(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - query()');

        $connection = $this->getService('db');

        $result = $connection->query('SELECT * FROM personas LIMIT 3');

        $I->assertInternalType('object', $result);

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
        $I->assertInternalType('object', $result);

        while ($row = $result->fetch()) {
            $number++;
        }
        $I->assertEquals(5, $number);


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_NUM);
        $row = $result->fetch();
        $I->assertInternalType('array', $row);
        $I->assertCount(11, $row);
        $I->assertTrue(isset($row[0]));
        $I->assertFalse(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_ASSOC);
        $row = $result->fetch();
        $I->assertInternalType('array', $row);
        $I->assertCount(11, $row);
        $I->assertFalse(isset($row[0]));
        $I->assertTrue(isset($row['cedula']));
        $I->assertFalse(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_OBJ);
        $row = $result->fetch();
        $I->assertInternalType('object', $row);
        $I->assertTrue(isset($row->cedula));


        $result = $connection->query('SELECT * FROM personas LIMIT 5');
        $result->setFetchMode(Enum::FETCH_BOTH);
        $result->dataSeek(4);
        $row = $result->fetch();
        $row = $result->fetch();
        $I->assertEquals($row, false);
    }
}
