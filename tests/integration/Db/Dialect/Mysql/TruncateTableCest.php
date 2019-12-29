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

class TruncateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: truncateTable()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getTruncateTableFixtures
     */
    public function dbDialectMysqlTruncateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - truncateTable()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Mysql();

        $actual = $dialect->truncateTable('table', $schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getTruncateTableFixtures(): array
    {
        return [
            [
                '',
                'TRUNCATE TABLE `table`',
            ],
            [
                'schema',
                'TRUNCATE TABLE `schema`.`table`',
            ],
        ];
    }
}
