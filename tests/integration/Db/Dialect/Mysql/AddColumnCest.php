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
use Phalcon\Test\Fixtures\Traits\DiTrait;

class AddColumnCest
{
    use DiTrait;
    use DialectTrait;

    /**
     * Tests Dialect::addColumn
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddColumnFixtures
     */
    public function testAddColumn(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $column   = $example[1];
        $expected = $example[2];

        $columns = $this->getColumns();
        $dialect = new Mysql();

        $actual = $dialect->addColumn('table', $schema, $columns[$column]);

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::addColumn
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-12-23
     */
    public function dbDialectAddColumnDateFractal(IntegrationTester $I)
    {
        $dialect = new Mysql();

        $options = [
            "type"    => Column::TYPE_DATETIME,
            "notNull" => false,
            "size"    => 2,
        ];
        $column  = new Column('ftest', $options);
        $actual  = $dialect->addColumn('fractal_dates', "", $column);
        $I->assertEquals(
            "ALTER TABLE `fractal_dates` ADD `ftest` DATETIME(2)",
            $actual
        );

        $options = [
            "type"    => Column::TYPE_TIME,
            "notNull" => false,
            "size"    => 2,
        ];
        $column  = new Column('ftest', $options);
        $actual  = $dialect->addColumn('fractal_dates', "", $column);
        $I->assertEquals(
            "ALTER TABLE `fractal_dates` ADD `ftest` TIME(2)",
            $actual
        );

        $options = [
            "type"    => Column::TYPE_TIMESTAMP,
            "notNull" => false,
            "size"    => 2,
        ];
        $column  = new Column('ftest', $options);
        $actual  = $dialect->addColumn('fractal_dates', "", $column);
        $I->assertEquals(
            "ALTER TABLE `fractal_dates` ADD `ftest` TIMESTAMP(2)",
            $actual
        );
    }


    protected function getAddColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE `table` ADD `column1` VARCHAR(10)',
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE `schema`.`table` ADD `column1` VARCHAR(10)',
            ],
            [
                '',
                'column2',
                'ALTER TABLE `table` ADD `column2` INT(18) UNSIGNED',
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE `schema`.`table` ADD `column2` INT(18) UNSIGNED',
            ],
            [
                '',
                'column3',
                'ALTER TABLE `table` ADD `column3` DECIMAL(10,2) NOT NULL',
            ],
            [
                'schema',
                'column3',
                'ALTER TABLE `schema`.`table` ADD `column3` DECIMAL(10,2) NOT NULL',
            ],
            [
                '',
                'column4',
                'ALTER TABLE `table` ADD `column4` CHAR(100) NOT NULL',
            ],
            [
                'schema',
                'column4',
                'ALTER TABLE `schema`.`table` ADD `column4` CHAR(100) NOT NULL',
            ],
            [
                '',
                'column5',
                'ALTER TABLE `table` ADD `column5` DATE NOT NULL',
            ],
            [
                'schema',
                'column5',
                'ALTER TABLE `schema`.`table` ADD `column5` DATE NOT NULL',
            ],
            [
                '',
                'column6',
                'ALTER TABLE `table` ADD `column6` DATETIME NOT NULL',
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE `schema`.`table` ADD `column6` DATETIME NOT NULL',
            ],
            [
                '',
                'column7',
                'ALTER TABLE `table` ADD `column7` TEXT NOT NULL',
            ],
            [
                'schema',
                'column7',
                'ALTER TABLE `schema`.`table` ADD `column7` TEXT NOT NULL',
            ],
            [
                '',
                'column8',
                'ALTER TABLE `table` ADD `column8` FLOAT(10,2) NOT NULL',
            ],
            [
                'schema',
                'column8',
                'ALTER TABLE `schema`.`table` ADD `column8` FLOAT(10,2) NOT NULL',
            ],
            [
                '',
                'column9',
                'ALTER TABLE `table` ADD `column9` VARCHAR(10) DEFAULT "column9"',
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE `schema`.`table` ADD `column9` VARCHAR(10) DEFAULT "column9"',
            ],
            [
                '',
                'column10',
                'ALTER TABLE `table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"',
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE `schema`.`table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"',
            ],
            [
                '',
                'column11',
                'ALTER TABLE `table` ADD `column11` BIGINT(20) UNSIGNED',
            ],
            [
                'schema',
                'column11',
                'ALTER TABLE `schema`.`table` ADD `column11` BIGINT(20) UNSIGNED',
            ],
            [
                '',
                'column12',
                'ALTER TABLE `table` ADD `column12` ENUM("A", "B", "C") DEFAULT "A" NOT NULL AFTER `column11`',
            ],
            [
                'schema',
                'column12',
                'ALTER TABLE `schema`.`table` ADD `column12` ENUM("A", "B", "C") DEFAULT "A" NOT NULL AFTER `column11`',
            ],
            [
                '',
                'column13',
                'ALTER TABLE `table` ADD `column13` TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
            [
                'schema',
                'column13',
                'ALTER TABLE `schema`.`table` ADD `column13` TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
        ];
    }
}
