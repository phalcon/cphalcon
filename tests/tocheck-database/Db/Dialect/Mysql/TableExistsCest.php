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

namespace Phalcon\Tests\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class TableExistsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: tableExists()
     *
     * @dataProvider getTableExistsFixtures
     */
    public function dbDialectMysqlTableExists(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - tableExists()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Mysql();

        $actual = $dialect->tableExists(
            'table',
            $schema
        );

        $I->assertTrue(is_string($actual));

        $I->assertEquals($expected, $actual);
    }

    protected function getTableExistsFixtures(): array
    {
        return [
            [
                null,
                'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` ' .
                "WHERE `TABLE_NAME` = 'table' AND `TABLE_SCHEMA` = DATABASE()",
            ],

            [
                'schema',
                'SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` ' .
                "WHERE `TABLE_NAME`= 'table' AND `TABLE_SCHEMA` = 'schema'",
            ],
        ];
    }
}
