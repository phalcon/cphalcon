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

class DropForeignKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: dropForeignKey()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getDropForeignKeyFixtures
     */
    public function dbDialectMysqlDropForeignKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - dropForeignKey()');

        $schema    = $example[0];
        $reference = $example[1];
        $expected  = $example[2];

        $dialect = new Mysql();

        $actual = $dialect->dropForeignKey('table', $schema, $reference);

        $I->assertEquals($expected, $actual);
    }

    protected function getDropForeignKeyFixtures(): array
    {
        return [
            [
                '',
                'reference1',
                'ALTER TABLE `table` DROP FOREIGN KEY `reference1`',
            ],
            [
                'schema',
                'reference1',
                'ALTER TABLE `schema`.`table` DROP FOREIGN KEY `reference1`',
            ],
        ];
    }
}
