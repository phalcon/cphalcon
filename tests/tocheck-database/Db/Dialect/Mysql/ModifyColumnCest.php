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
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class ModifyColumnCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: modifyColumn()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getModifyColumnFixtures
     */
    public function dbDialectMysqlModifyColumn(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - modifyColumn()');

        $columns  = $this->getColumns();
        $schema   = $example[0];
        $to       = $columns[$example[1]];
        $from     = $columns[$example[2]] ?? null;
        $expected = $example[3];

        $dialect = new Mysql();

        $actual = $dialect->modifyColumn(
            'table',
            $schema,
            $to,
            $from
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: modifyColumn() - bug 13012
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function testModifyColumn13012(IntegrationTester $I)
    {
        $oldColumn = new Column(
            'old',
            [
                'type' => Column::TYPE_VARCHAR,
            ]
        );

        $newColumn = new Column(
            'new',
            [
                'type' => Column::TYPE_VARCHAR,
            ]
        );

        $dialect = new Mysql();

        $actual = $dialect->modifyColumn(
            'table',
            'database',
            $newColumn,
            $oldColumn
        );

        $I->assertEquals(
            'ALTER TABLE `database`.`table` CHANGE COLUMN `old` `new` VARCHAR(0)',
            $actual
        );
    }

    protected function getModifyColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                null,
                'ALTER TABLE `table` MODIFY `column1` VARCHAR(10)',
            ],

            [
                'schema',
                'column1',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column1` VARCHAR(10)',
            ],

            [
                '',
                'column2',
                null,
                'ALTER TABLE `table` MODIFY `column2` INT(18) UNSIGNED',
            ],

            [
                'schema',
                'column2',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column2` INT(18) UNSIGNED',
            ],

            [
                '',
                'column3',
                null,
                'ALTER TABLE `table` MODIFY `column3` DECIMAL(10,2) NOT NULL',
            ],

            [
                'schema',
                'column3',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column3` DECIMAL(10,2) NOT NULL',
            ],

            [
                '',
                'column4',
                null,
                'ALTER TABLE `table` MODIFY `column4` CHAR(100) NOT NULL',
            ],

            [
                'schema',
                'column4',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column4` CHAR(100) NOT NULL',
            ],

            [
                '',
                'column5',
                null,
                'ALTER TABLE `table` MODIFY `column5` DATE NOT NULL',
            ],

            [
                'schema',
                'column5',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column5` DATE NOT NULL',
            ],

            [
                '',
                'column6',
                null,
                'ALTER TABLE `table` MODIFY `column6` DATETIME NOT NULL',
            ],

            [
                'schema',
                'column6',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column6` DATETIME NOT NULL',
            ],

            [
                '',
                'column7',
                null,
                'ALTER TABLE `table` MODIFY `column7` TEXT NOT NULL',
            ],

            [
                'schema',
                'column7',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column7` TEXT NOT NULL',
            ],

            [
                '',
                'column8',
                null,
                'ALTER TABLE `table` MODIFY `column8` FLOAT(10,2) NOT NULL',
            ],

            [
                'schema',
                'column8',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column8` FLOAT(10,2) NOT NULL',
            ],

            [
                '',
                'column9',
                null,
                'ALTER TABLE `table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"',
            ],

            [
                'schema',
                'column9',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"',
            ],

            [
                '',
                'column10',
                null,
                'ALTER TABLE `table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"',
            ],

            [
                'schema',
                'column10',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"',
            ],

            [
                '',
                'column11',
                null,
                'ALTER TABLE `table` MODIFY `column11` BIGINT(20) UNSIGNED',
            ],

            [
                'schema',
                'column11',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column11` BIGINT(20) UNSIGNED',
            ],

            [
                '',
                'column12',
                null,
                'ALTER TABLE `table` MODIFY `column12` ENUM("A", "B", "C") ' .
                'DEFAULT "A" NOT NULL AFTER `column11`',
            ],

            [
                'schema',
                'column12',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column12` ENUM("A", "B", "C") ' .
                'DEFAULT "A" NOT NULL AFTER `column11`',
            ],

            [
                '',
                'column13',
                null,
                'ALTER TABLE `table` MODIFY `column13` ' .
                'TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],

            [
                'schema',
                'column13',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column13` ' .
                'TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
        ];
    }
}
