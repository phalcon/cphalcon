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
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class CreateTableTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'CREATE TABLE `schema`.`table` (
	`field_primary` INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`field_timestamp` VARCHAR(10) NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`field_int` INT(10) UNSIGNED NOT NULL DEFAULT 13,
	`field_double` DOUBLE(10,2) NOT NULL DEFAULT 13.34,
	`field_string` VARCHAR(10) NOT NULL DEFAULT "test",
	`field_null` VARCHAR(10) NOT NULL DEFAULT NULL,
	`field_comment` VARCHAR(10) NOT NULL DEFAULT "test" COMMENT \'This is a comment\',
	PRIMARY KEY (`field_primary`),
	KEY `field1` (`field_field1`),
	UNIQUE KEY `field2` (`field_field2`),
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`),
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`) ON DELETE ONDELETESQL,
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`) ON UPDATE ONUPDATESQL
)',
            ],
            //            [
            //                Postgresql::class,
            //                '1'
            //            ],
            [
                Sqlite::class,
                'CREATE TABLE "schema"."table" (
	`field_primary` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	`field_timestamp` VARCHAR(10) DEFAULT CURRENT_TIMESTAMP NOT NULL,
	`field_int` INTEGER DEFAULT "13" NOT NULL,
	`field_double` DOUBLE DEFAULT "13.34" NOT NULL,
	`field_string` VARCHAR(10) DEFAULT "test" NOT NULL,
	`field_null` VARCHAR(10) DEFAULT "NULL" NOT NULL,
	`field_comment` VARCHAR(10) DEFAULT "test" NOT NULL,
	UNIQUE ("field_field2"),
	CONSTRAINT `fk_field_primary` FOREIGN KEY ("field_primary") REFERENCES `other_table`("id"),
	CONSTRAINT `fk_field_primary` FOREIGN KEY ("field_primary") REFERENCES `other_table`("id") ON DELETE ONDELETESQL,
	CONSTRAINT `fk_field_primary` FOREIGN KEY ("field_primary") REFERENCES `other_table`("id") ON UPDATE ONUPDATESQL
)',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsException(): array
    {
        return [
            [
                Mysql::class,

            ],
            [
                Postgresql::class,
                '3',
            ],
            [
                Sqlite::class,
                '4',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsTemporary(): array
    {
        return [
            [
                Mysql::class,
                'CREATE TEMPORARY TABLE `schema`.`table` (
	`field_primary` INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`field_timestamp` VARCHAR(10) NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`field_int` INT(10) UNSIGNED NOT NULL DEFAULT 13,
	`field_double` DOUBLE(10,2) NOT NULL DEFAULT 13.34,
	`field_string` VARCHAR(10) NOT NULL DEFAULT "test",
	`field_null` VARCHAR(10) NOT NULL DEFAULT NULL,
	`field_comment` VARCHAR(10) NOT NULL DEFAULT "test" COMMENT \'This is a comment\',
	PRIMARY KEY (`field_primary`),
	KEY `field1` (`field_field1`),
	UNIQUE KEY `field2` (`field_field2`),
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`),
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`) ON DELETE ONDELETESQL,
	CONSTRAINT `fk_field_primary` FOREIGN KEY (`field_primary`) REFERENCES `other_table` (`id`) ON UPDATE ONUPDATESQL
) ENGINE=InnoDB AUTO_INCREMENT=1000 DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci',
            ],
            //            [Postgresql::class],
            //            [Sqlite::class],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: createTable
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectCreateTable(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $definition = $this->getDefinition();

        $actual = $dialect->createTable(
            'table',
            'schema',
            $definition
        );
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: createTable - exception
     *
     * @dataProvider getDialectsException
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectCreateTableException(
        string $dialectClass
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "The index 'columns' is required in the definition array"
        );

        $dialect->createTable('table', 'schema', []);
    }

    /**
     * Tests Phalcon\Db\Dialect :: createTable
     *
     * @dataProvider getDialectsTemporary
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectCreateTableTemporary(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $definition            = $this->getDefinition();
        $definition['options'] = [
            'temporary'       => true,
            'ENGINE'          => 'InnoDB',
            'AUTO_INCREMENT'  => 1000,
            'TABLE_COLLATION' => 'utf8_general_ci',
        ];

        $actual = $dialect->createTable(
            'table',
            'schema',
            $definition
        );
        $this->assertSame($expected, $actual);
    }

    /**
     * @return array<string, array>
     * @throws Exception
     */
    private function getDefinition(): array
    {
        return [
            'columns'    => [
                new Column(
                    'field_primary',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'isNumeric'     => true,
                        'size'          => 11,
                        'scale'         => 0,
                        'default'       => null,
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => true,
                        'primary'       => true,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                new Column(
                    'field_timestamp',
                    [
                        'type'          => Column::TYPE_VARCHAR,
                        'isNumeric'     => false,
                        'size'          => 10,
                        'default'       => 'CURRENT_TIMESTAMP',
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_STR,
                    ]
                ),
                new Column(
                    'field_int',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'isNumeric'     => true,
                        'size'          => 10,
                        'scale'         => 0,
                        'default'       => 13,
                        'unsigned'      => true,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                new Column(
                    'field_double',
                    [
                        'type'          => Column::TYPE_DOUBLE,
                        'isNumeric'     => true,
                        'size'          => 10,
                        'scale'         => 2,
                        'default'       => 13.34,
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_DECIMAL,
                    ]
                ),
                new Column(
                    'field_string',
                    [
                        'type'          => Column::TYPE_VARCHAR,
                        'isNumeric'     => false,
                        'size'          => 10,
                        'default'       => 'test',
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => false,
                        'after'         => 'field_double',
                        'bindType'      => Column::BIND_PARAM_STR,
                    ]
                ),
                new Column(
                    'field_null',
                    [
                        'type'          => Column::TYPE_VARCHAR,
                        'isNumeric'     => false,
                        'size'          => 10,
                        'default'       => 'NULL',
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_STR,
                    ]
                ),
                new Column(
                    'field_comment',
                    [
                        'type'          => Column::TYPE_VARCHAR,
                        'isNumeric'     => false,
                        'size'          => 10,
                        'default'       => 'test',
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => false,
                        'after'         => null,
                        'comment'       => 'This is a comment',
                        'bindType'      => Column::BIND_PARAM_STR,
                    ]
                ),
            ],
            'indexes'    => [
                new Index('PRIMARY', ['field_primary']),
                new Index('field1', ['field_field1']),
                new Index('field2', ['field_field2'], 'UNIQUE'),
            ],
            'references' => [
                new Reference(
                    'fk_field_primary',
                    [
                        'referencedTable'   => 'other_table',
                        'columns'           => ['field_primary'],
                        'referencedColumns' => ['id'],
                    ]
                ),
                new Reference(
                    'fk_field_primary',
                    [
                        'referencedTable'   => 'other_table',
                        'columns'           => ['field_primary'],
                        'referencedColumns' => ['id'],
                        'onDelete'          => 'ONDELETESQL',
                    ]
                ),
                new Reference(
                    'fk_field_primary',
                    [
                        'referencedTable'   => 'other_table',
                        'columns'           => ['field_primary'],
                        'referencedColumns' => ['id'],
                        'onUpdate'          => 'ONUPDATESQL',
                    ]
                ),
            ],
        ];
    }
}
