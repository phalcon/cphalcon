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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class GetColumnDefinitionTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getMysqlData(): array
    {
        return [
            [
                [
                    'type'      => Column::TYPE_BIGINTEGER,
                    'isNumeric' => true,
                    'size'      => 10,
                    'scale'     => null,
                    'unsigned'  => false,
                ],
                'BIGINT(10)',
            ],
            [
                [
                    'type'      => Column::TYPE_BIGINTEGER,
                    'isNumeric' => true,
                    'size'      => 10,
                    'scale'     => null,
                    'unsigned'  => true,
                ],
                'BIGINT(10) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_BIT,
                    'isNumeric' => true,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'BIT(2)',
            ],
            [
                [
                    'type'      => Column::TYPE_BLOB,
                    'isNumeric' => false,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'BLOB',
            ],
            [
                [
                    'type'      => Column::TYPE_BOOLEAN,
                    'isNumeric' => true,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'TINYINT(1)',
            ],
            [
                [
                    'type'      => Column::TYPE_CHAR,
                    'isNumeric' => false,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'CHAR(2)',
            ],
            [
                [
                    'type'      => Column::TYPE_DATE,
                    'isNumeric' => false,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'DATE',
            ],
            [
                [
                    'type'      => Column::TYPE_DATETIME,
                    'isNumeric' => false,
                    'size'      => 2,
                    'unsigned'  => false,
                ],
                'DATETIME(2)',
            ],
            [
                [
                    'type'      => Column::TYPE_DECIMAL,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => false,
                ],
                'DECIMAL(20,2)',
            ],
            [
                [
                    'type'      => Column::TYPE_DECIMAL,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => true,
                ],
                'DECIMAL(20,2) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_DOUBLE,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => false,
                ],
                'DOUBLE(20,2)',
            ],
            [
                [
                    'type'      => Column::TYPE_DOUBLE,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => true,
                ],
                'DOUBLE(20,2) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_ENUM,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'ENUM(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_FLOAT,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => false,
                ],
                'FLOAT(20,2)',
            ],
            [
                [
                    'type'      => Column::TYPE_FLOAT,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => 2,
                    'unsigned'  => true,
                ],
                'FLOAT(20,2) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_INTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => false,
                ],
                'INT(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_INTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => true,
                ],
                'INT(20) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_JSON,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'JSON',
            ],
            [
                [
                    'type'      => Column::TYPE_LONGBLOB,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'LONGBLOB',
            ],
            [
                [
                    'type'      => Column::TYPE_LONGTEXT,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'LONGTEXT',
            ],
            [
                [
                    'type'      => Column::TYPE_MEDIUMBLOB,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'MEDIUMBLOB',
            ],
            [
                [
                    'type'      => Column::TYPE_MEDIUMINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => false,
                ],
                'MEDIUMINT(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_MEDIUMINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => true,
                ],
                'MEDIUMINT(20) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_MEDIUMTEXT,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'MEDIUMTEXT',
            ],
            [
                [
                    'type'      => Column::TYPE_SMALLINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => false,
                ],
                'SMALLINT(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_SMALLINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => true,
                ],
                'SMALLINT(20) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_TEXT,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'TEXT',
            ],
            [
                [
                    'type'      => Column::TYPE_TIME,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'TIME(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_TIMESTAMP,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'TIMESTAMP(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_TINYBLOB,
                    'isNumeric' => true,
                    'size'      => 20,
                    'unsigned'  => true,
                ],
                'TINYBLOB',
            ],
            [
                [
                    'type'      => Column::TYPE_TINYINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => false,
                ],
                'TINYINT(20)',
            ],
            [
                [
                    'type'      => Column::TYPE_TINYINTEGER,
                    'isNumeric' => true,
                    'size'      => 20,
                    'scale'     => null,
                    'unsigned'  => true,
                ],
                'TINYINT(20) UNSIGNED',
            ],
            [
                [
                    'type'      => Column::TYPE_TINYTEXT,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'TINYTEXT',
            ],
            [
                [
                    'type'      => Column::TYPE_VARCHAR,
                    'isNumeric' => false,
                    'size'      => 20,
                    'unsigned'  => false,
                ],
                'VARCHAR(20)',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: getColumnDefinition
     *
     * @dataProvider getMysqlData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectGetColumnDefinition(
        array $definition,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new Mysql();
        $column  = new Column('column_name', $definition);

        $actual = $dialect->getColumnDefinition($column);
        $this->assertSame($expected, $actual);
    }
}
