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

namespace Phalcon\Test\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Db\Column;
use Phalcon\Test\Fixtures\Migrations\ComplexDefaultMigration;
use Phalcon\Test\Fixtures\Migrations\DialectMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DescribeColumnsCest
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
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns() - supported
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     *
     * @group  mysql
     */
    public function dbAdapterPdoDescribeColumnsSupported(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns() - supported');

        $db        = $this->container->get('db');
        $migration = new DialectMigration($I->getConnection());
        $columns   = $db->describeColumns($migration->getTable());

        $expected = 40;
        $I->assertCount($expected, $columns);

        $expected = Column::class;
        $actual = $columns[1];
        $I->assertInstanceOf($expected, $actual);

        foreach ($columns as $index => $column) {
            $expected = $this->getExpected($index);
            $actual   = $this->getActual($column);

            $I->assertEquals($expected, $actual);
        }

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-02
     *
     * @group  mysql
     */
    public function dbAdapterPdoDescribeColumnsOnUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns()');

        $db  = $this->container->get('db');
        $now = date('Y-m-d H:i:s');
        $migration = new ComplexDefaultMigration($I->getConnection());
        $migration->insert(1, $now, $now);

        $columns = $db->describeColumns($migration->getTable());

        $I->assertSame('CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP', $columns[2]->getDefault());
        $I->assertSame('NULL on update CURRENT_TIMESTAMP', $columns[3]->getDefault());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeColumns()
     *
     * @param DatabaseTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-03-09
     *
     * @group  pgsql
     */
    public function dbAdapterPdoDescribeColumnsDefaultPostgres(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - describeColumns() - CheckPostgres Default value');

        $db  = $this->container->get('db');
        $now = date('Y-m-d H:i:s');
        $migration = new ComplexDefaultMigration($I->getConnection());
        $migration->insert(1, $now, $now);

        $columns = $db->describeColumns($migration->getTable());

        $I->assertRegexp('/CURRENT_TIMESTAMP|now\(\)/i', $columns[1]->getDefault());
        $I->assertRegexp('/CURRENT_TIMESTAMP|now\(\)/i', $columns[2]->getDefault());
    }

    /**
     * @param Column $column
     *
     * @return array
     */
    private function getActual(Column $column): array
    {
        return [
            $column->getAfterPosition(),
            $column->getBindType(),
            $column->hasDefault(),
            $column->isAutoIncrement(),
            $column->isFirst(),
            $column->isNotNull(),
            $column->isNumeric(),
            $column->isPrimary(),
            $column->isUnsigned(),
        ];
    }

    private function getExpected(int $index): array
    {
        $metadata = [
            // field_primary           int auto_increment primary key,
            0  => [
                0 => null,
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => true,
                4 => true,
                5 => true,
                6 => true,
                7 => true,
                8 => false,
            ],
            // field_blob               blob                                        null,
            1  => [
                0 => 'field_primary',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_binary             binary(10)                                  null,
            2  => [
                0 => 'field_blob',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_bit                bit(10)                                     null,
            3  => [
                0 => 'field_binary',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_bit_default        bit(10)       default b'1'                  null,
            4  => [
                0 => 'field_bit',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_bigint             bigint        unsigned                      null,
            5  => [
                0 => 'field_bit_default',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => true,
            ],
            // field_bigint_default     bigint        default 1                     null,
            6  => [
                0 => 'field_bigint',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_boolean            tinyint(1)    unsigned                      null,
            7  => [
                0 => 'field_bigint_default',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => true,
            ],
            // field_boolean_default    tinyint(1)    default 1                     null,
            8  => [
                0 => 'field_boolean',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_char               char(10)                                    null,
            9  => [
                0 => 'field_boolean_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_char_default       char(10)      default 'ABC'                 null,
            10 => [
                0 => 'field_char',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_decimal            decimal(10,4)                               null,
            11 => [
                0 => 'field_char_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_decimal_default    decimal(10,4) default 14.5678               null,
            12 => [
                0 => 'field_decimal',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_enum               enum('xs', 's', 'm', 'l', 'xl', 'internal') null,
            13 => [
                0 => 'field_decimal_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_integer            int(10)                                     null,
            14 => [
                0 => 'field_enum',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_integer_default    int(10)       default 1                     null,
            15 => [
                0 => 'field_integer',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_json               json                                        null,
            16 => [
                0 => 'field_integer_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_float              float(10,4)                                 null,
            17 => [
                0 => 'field_json',
                1 => Column::BIND_PARAM_DECIMAL,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_float_default      float(10,4)   default 14.5678               null,
            18 => [
                0 => 'field_float',
                1 => Column::BIND_PARAM_DECIMAL,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_date               date                                        null,
            19 => [
                0 => 'field_float_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_date_default       date          default '2018-10-01'          null,
            20 => [
                0 => 'field_date',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_datetime           datetime                                    null,
            21 => [
                0 => 'field_date_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_datetime_default   datetime      default '2018-10-01 12:34:56' null,
            22 => [
                0 => 'field_datetime',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_time               time                                        null,
            23 => [
                0 => 'field_datetime_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_time_default       time          default '12:34:56'            null,
            24 => [
                0 => 'field_time',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_timestamp          timestamp                                   null,
            25 => [
                0 => 'field_time_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_timestamp_default  timestamp     default '2018-10-01 12:34:56' null,
            26 => [
                0 => 'field_timestamp',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_mediumint          mediumint(10) unsigned                      null,
            27 => [
                0 => 'field_timestamp_default',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => true,
            ],
            // field_mediumint_default  mediumint(10) default 1                     null,
            28 => [
                0 => 'field_mediumint',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_smallint           smallint(10)  unsigned                      null,
            29 => [
                0 => 'field_mediumint_default',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => true,
            ],
            // field_smallint_default   smallint(10)  default 1                     null,
            30 => [
                0 => 'field_smallint',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_tinyint            tinyint(10)   unsigned                      null,
            31 => [
                0 => 'field_smallint_default',
                1 => Column::BIND_PARAM_INT,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => true,
            ],
            // field_tinyint_default    tinyint(10)   default 1                     null,
            32 => [
                0 => 'field_tinyint',
                1 => Column::BIND_PARAM_INT,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => true,
                7 => false,
                8 => false,
            ],
            // field_longtext           longtext                                    null,
            33 => [
                0 => 'field_tinyint_default',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_mediumtext         mediumtext                                  null,
            34 => [
                0 => 'field_longtext',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_tinytext           tinytext                                    null,
            35 => [
                0 => 'field_mediumtext',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_text               text                                        null,
            36 => [
                0 => 'field_tinytext',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_varbinary          varbinary(10)                               null,
            37 => [
                0 => 'field_text',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_varchar            varchar(10)                                 null,
            38 => [
                0 => 'field_varbinary',
                1 => Column::BIND_PARAM_STR,
                2 => false,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
            // field_varchar_default    varchar(10)   default 'D'                   null,
            39 => [
                0 => 'field_varchar',
                1 => Column::BIND_PARAM_STR,
                2 => true,
                3 => false,
                4 => false,
                5 => false,
                6 => false,
                7 => false,
                8 => false,
            ],
        ];

        return $metadata[$index] ?? [];
    }
}
