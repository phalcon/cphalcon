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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class ListViewsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: listViews()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getListViewFixtures
     */
    public function dbDialectMysqlListViews(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - listViews()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Mysql();

        $actual = $dialect->listViews($schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getListViewFixtures(): array
    {
        return [
            [
                null,
                'SELECT `TABLE_NAME` AS view_name ' .
                'FROM `INFORMATION_SCHEMA`.`VIEWS` ' .
                'WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name',
            ],

            [
                'schema',
                "SELECT `TABLE_NAME` AS view_name " .
                "FROM `INFORMATION_SCHEMA`.`VIEWS` " .
                "WHERE `TABLE_SCHEMA` = 'schema' ORDER BY view_name",
            ],
        ];
    }
}
