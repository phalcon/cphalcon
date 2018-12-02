<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Column;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Db\Column;

class IsAutoIncrementCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement() - Mysql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsAutoIncrementMysql(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isAutoIncrement() - Mysql");
        $I->skipTest("Need implementation");
    }

    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement() - Postgresql
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsAutoIncrementPostgresql(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isAutoIncrement() - Postgresql");

        $column = Column::__set_state(
            [
                '_columnName'    => 'id',
                '_schemaName'    => null,
                '_type'          => 14,
                '_typeReference' => -1,
                '_typeValues'    => null,
                '_isNumeric'     => true,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => "nextval('images_id_seq'::regclass)",
                '_unsigned'      => false,
                '_notNull'       => true,
                '_primary'       => false,
                '_autoIncrement' => true,
                '_first'         => true,
                '_after'         => null,
                '_bindType'      => 1,
            ]
        );

        $I->assertTrue($column->isAutoIncrement());
    }

    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement() - Sqlite
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsAutoIncrementSqlite(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isAutoIncrement() - Sqlite");
        $I->skipTest("Need implementation");
    }
}
