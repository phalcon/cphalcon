<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\DialectInterface;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Unit\Db\Dialect\Helper\DialectBase;

class MysqlCest extends DialectBase
{
    /**
     * @var string
     */
    protected $adapter = 'Mysql';

    /**
     * @return array
     */
    protected function getAddColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE `table` ADD `column1` VARCHAR(10)'
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE `schema`.`table` ADD `column1` VARCHAR(10)'
            ],
            [
                '',
                'column2',
                'ALTER TABLE `table` ADD `column2` INT(18) UNSIGNED'
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE `schema`.`table` ADD `column2` INT(18) UNSIGNED'
            ],
            [
                '',
                'column3',
                'ALTER TABLE `table` ADD `column3` DECIMAL(10,2) NOT NULL'
            ],
            [
                'schema',
                'column3',
                'ALTER TABLE `schema`.`table` ADD `column3` DECIMAL(10,2) NOT NULL'
            ],
            [
                '',
                'column4',
                'ALTER TABLE `table` ADD `column4` CHAR(100) NOT NULL'
            ],
            [
                'schema',
                'column4',
                'ALTER TABLE `schema`.`table` ADD `column4` CHAR(100) NOT NULL'
            ],
            [
                '',
                'column5',
                'ALTER TABLE `table` ADD `column5` DATE NOT NULL'
            ],
            [
                'schema',
                'column5',
                'ALTER TABLE `schema`.`table` ADD `column5` DATE NOT NULL'
            ],
            [
                '',
                'column6',
                'ALTER TABLE `table` ADD `column6` DATETIME NOT NULL'
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE `schema`.`table` ADD `column6` DATETIME NOT NULL'
            ],
            [
                '',
                'column7',
                'ALTER TABLE `table` ADD `column7` TEXT NOT NULL'
            ],
            [
                'schema',
                'column7',
                'ALTER TABLE `schema`.`table` ADD `column7` TEXT NOT NULL'
            ],
            [
                '',
                'column8',
                'ALTER TABLE `table` ADD `column8` FLOAT(10,2) NOT NULL'
            ],
            [
                'schema',
                'column8',
                'ALTER TABLE `schema`.`table` ADD `column8` FLOAT(10,2) NOT NULL'
            ],
            [
                '',
                'column9',
                'ALTER TABLE `table` ADD `column9` VARCHAR(10) DEFAULT "column9"'
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE `schema`.`table` ADD `column9` VARCHAR(10) DEFAULT "column9"'
            ],
            [
                '',
                'column10',
                'ALTER TABLE `table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"'
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE `schema`.`table` ADD `column10` INT(18) UNSIGNED DEFAULT "10"'
            ],
            [
                '',
                'column11',
                'ALTER TABLE `table` ADD `column11` BIGINT(20) UNSIGNED'
            ],
            [
                'schema',
                'column11',
                'ALTER TABLE `schema`.`table` ADD `column11` BIGINT(20) UNSIGNED'
            ],
            [
                '',
                'column12',
                'ALTER TABLE `table` ADD `column12` ENUM("A", "B", "C") DEFAULT "A" NOT NULL AFTER `column11`'
            ],
            [
                'schema',
                'column12',
                'ALTER TABLE `schema`.`table` ADD `column12` ENUM("A", "B", "C") DEFAULT "A" NOT NULL AFTER `column11`'
            ],
            [
                '',
                'column13',
                'ALTER TABLE `table` ADD `column13` TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
            [
                'schema',
                'column13',
                'ALTER TABLE `schema`.`table` ADD `column13` TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getAddForeignKeyFixtures(): array
    {
        return [
            [
                '',
                'fk1',
                'ALTER TABLE `table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)'
            ],
            [
                'schema',
                'fk1',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)'
            ],
            [
                '',
                'fk2',
                'ALTER TABLE `table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)'
            ],
            [
                'schema',
                'fk2',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)'
            ],
            [
                '',
                'fk3',
                'ALTER TABLE `table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE'
            ],
            [
                'schema',
                'fk3',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE'
            ],
            [
                '',
                'fk4',
                'ALTER TABLE `table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL'
            ],
            [
                'schema',
                'fk4',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL'
            ],
            [
                '',
                'fk5',
                'ALTER TABLE `table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION'
            ],
            [
                'schema',
                'fk5',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION'
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['',       'index1',  'ALTER TABLE `table` ADD INDEX `index1` (`column1`)'],
            ['schema', 'index1',  'ALTER TABLE `schema`.`table` ADD INDEX `index1` (`column1`)'],
            ['',       'index2',  'ALTER TABLE `table` ADD INDEX `index2` (`column1`, `column2`)'],
            ['schema', 'index2',  'ALTER TABLE `schema`.`table` ADD INDEX `index2` (`column1`, `column2`)'],
            ['',       'PRIMARY', 'ALTER TABLE `table` ADD INDEX `PRIMARY` (`column3`)'],
            ['schema', 'PRIMARY', 'ALTER TABLE `schema`.`table` ADD INDEX `PRIMARY` (`column3`)'],
            ['',       'index4',  'ALTER TABLE `table` ADD UNIQUE INDEX `index4` (`column4`)'],
            ['schema', 'index4',  'ALTER TABLE `schema`.`table` ADD UNIQUE INDEX `index4` (`column4`)'],
        ];
    }

    /**
     * @return array
     */
    protected function getAddPrimaryKeyFixtures(): array
    {
        return [
            ['',       'PRIMARY', 'ALTER TABLE `table` ADD PRIMARY KEY (`column3`)'],
            ['schema', 'PRIMARY', 'ALTER TABLE `schema`.`table` ADD PRIMARY KEY (`column3`)'],
        ];
    }

    /**
     * @return array
     */
    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1',  'VARCHAR(10)'],
            ['column2',  'INT(18) UNSIGNED'],
            ['column3',  'DECIMAL(10,2)'],
            ['column4',  'CHAR(100)'],
            ['column5',  'DATE'],
            ['column6',  'DATETIME'],
            ['column7',  'TEXT'],
            ['column8',  'FLOAT(10,2)'],
            ['column9',  'VARCHAR(10)'],
            ['column10', 'INT(18) UNSIGNED'],
            ['column11', 'BIGINT(20) UNSIGNED'],
            ['column12', 'ENUM("A", "B", "C")'],
            ['column13', 'TIMESTAMP'],
        ];
    }

    /**
     * @return array
     */
    protected function getColumnListFixtures(): array
    {
        return [
            [
                ['column1', 'column2', 'column3'],
                '`column1`, `column2`, `column3`'
            ],
            [
                ['foo'],
                '`foo`',
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getCreateTableFixtures(): array
    {
        return [
            'example1' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10
                            ]
                        ),
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false
                            ]
                        ),
                    ]
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/mysql/example1.sql')),
            ],
            'example2' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false
                            ]
                        ),
                        new Column(
                            'column3',
                            [
                                'type'     => Column::TYPE_DECIMAL,
                                'size'     => 10,
                                'scale'    => 2,
                                'unsigned' => false,
                                'notNull'  => true
                            ]
                        ),
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10
                            ]
                        ),
                    ],
                    'indexes' => [
                        new Index('PRIMARY', ['column3']),
                    ]
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/mysql/example2.sql')),
            ],
            'example3' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false
                            ]
                        ),
                        new Column(
                            'column3',
                            [
                                'type'     => Column::TYPE_DECIMAL,
                                'size'     => 10,
                                'scale'    => 2,
                                'unsigned' => false,
                                'notNull'  => true
                            ]
                        ),
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10
                            ]
                        ),
                    ],
                    'indexes' => [
                        new Index('PRIMARY', ['column3']),
                    ],
                    'references' => [
                        new Reference('fk3', [
                            'referencedTable'   => 'ref_table',
                            'columns'           => ['column1'],
                            'referencedColumns' => ['column2'],
                            'onDelete'          => 'CASCADE',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/mysql/example3.sql')),
            ],
            'example4' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column9',
                            [
                                'type'    => Column::TYPE_VARCHAR,
                                'size'    => 10,
                                'default' => 'column9'
                            ]
                        ),
                        new Column(
                            'column10',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false,
                                'default'  => 10,
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/mysql/example4.sql')),
            ],
            'example5' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column11',
                            [
                                'type'          => 'BIGINT',
                                'typeReference' => Column::TYPE_INTEGER,
                                'size'          => 20,
                                'unsigned'      => true,
                                'notNull'       => false
                            ]
                        ),
                        new Column(
                            'column12',
                            [
                                'type'       => 'ENUM',
                                'typeValues' => ['A', 'B', 'C'],
                                'notNull'    => true,
                                'default'    => 'A',
                                'after'      => 'column11'
                            ]
                        ),
                        new Column(
                            'column13',
                            [
                                'type'    => Column::TYPE_TIMESTAMP,
                                'notNull' => true,
                                'default' => 'CURRENT_TIMESTAMP',
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/mysql/example5.sql')),
            ],
        ];
    }

    /**
     * @return string
     */
    protected function getCreateSavepointSql(): string
    {
        return 'SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return array
     */
    protected function getCreateViewFixtures(): array
    {
        return [
            [['sql' => 'SELECT 1'],  null,    'CREATE VIEW `test_view` AS SELECT 1'],
            [['sql' => 'SELECT 1'], 'schema', 'CREATE VIEW `schema`.`test_view` AS SELECT 1'],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeColumnsFixtures(): array
    {
        return [
            [
                'schema.name.with.dots',
                'DESCRIBE `schema.name.with.dots`.`table`'
            ],
            [
                null,
                'DESCRIBE `table`'
            ],
            [
                'schema',
                'DESCRIBE `schema`.`table`'
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeReferencesFixtures()
    {
        return [
            [
                null,
                "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, " .
                "KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, " .
                "KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, " .
                "RC.UPDATE_RULE, RC.DELETE_RULE " .
                "FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU " .
                "LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC " .
                "ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND " .
                "RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA " .
                "WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND " .
                "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = 'table'"
            ],
            [
                'schema',
                "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, " .
                "KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, " .
                "KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, " .
                "RC.UPDATE_RULE, RC.DELETE_RULE " .
                "FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU " .
                "LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC " .
                "ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND " .
                "RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA " .
                "WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND " .
                "KCU.CONSTRAINT_SCHEMA = 'schema' AND KCU.TABLE_NAME = 'table'"
            ]
        ];
    }

    /**
     * @return array
     */
    protected function getDropColumnFixtures(): array
    {
        return [
            ['',       'column1', 'ALTER TABLE `table` DROP COLUMN `column1`'],
            ['schema', 'column1', 'ALTER TABLE `schema`.`table` DROP COLUMN `column1`'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropForeignKeyFixtures(): array
    {
        return [
            ['',       'fk1', 'ALTER TABLE `table` DROP FOREIGN KEY `fk1`'],
            ['schema', 'fk1', 'ALTER TABLE `schema`.`table` DROP FOREIGN KEY `fk1`'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropIndexFixtures()
    {
        return [
            ['',       'index1', 'ALTER TABLE `table` DROP INDEX `index1`'],
            ['schema', 'index1', 'ALTER TABLE `schema`.`table` DROP INDEX `index1`'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropPrimaryKeyFixtures(): array
    {
        return [
            ['',       'ALTER TABLE `table` DROP PRIMARY KEY'],
            ['schema', 'ALTER TABLE `schema`.`table` DROP PRIMARY KEY'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropTableFixtures(): array
    {
        return [
            ['',       true,  'DROP TABLE IF EXISTS `table`'],
            ['schema', true,  'DROP TABLE IF EXISTS `schema`.`table`'],
            ['',       false, 'DROP TABLE `table`'],
            ['schema', false, 'DROP TABLE `schema`.`table`'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropViewFixtures(): array
    {
        return [
            [null,     false, 'DROP VIEW `test_view`'],
            [null,     true,  'DROP VIEW IF EXISTS `test_view`'],
            ['schema', false, 'DROP VIEW `schema`.`test_view`'],
            ['schema', true,  'DROP VIEW IF EXISTS `schema`.`test_view`'],
        ];
    }

    /**
     * @return array
     */
    protected function getListViewFixtures(): array
    {
        return  [
            [
                null,
                'SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ' .
                'WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name',
            ],
            [
                'schema',
                "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` " .
                "WHERE `TABLE_SCHEMA` = 'schema' ORDER BY view_name",
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getModifyColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                null,
                'ALTER TABLE `table` MODIFY `column1` VARCHAR(10)'
            ],
            [
                'schema',
                'column1',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column1` VARCHAR(10)'
            ],
            [
                '',
                'column2',
                null,
                'ALTER TABLE `table` MODIFY `column2` INT(18) UNSIGNED'
            ],
            [
                'schema',
                'column2',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column2` INT(18) UNSIGNED'
            ],
            [
                '',
                'column3',
                null,
                'ALTER TABLE `table` MODIFY `column3` DECIMAL(10,2) NOT NULL'
            ],
            [
                'schema',
                'column3',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column3` DECIMAL(10,2) NOT NULL'
            ],
            [
                '',
                'column4',
                null,
                'ALTER TABLE `table` MODIFY `column4` CHAR(100) NOT NULL'
            ],
            [
                'schema',
                'column4',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column4` CHAR(100) NOT NULL'
            ],
            [
                '',
                'column5',
                null,
                'ALTER TABLE `table` MODIFY `column5` DATE NOT NULL'
            ],
            [
                'schema',
                'column5',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column5` DATE NOT NULL'
            ],
            [
                '',
                'column6',
                null,
                'ALTER TABLE `table` MODIFY `column6` DATETIME NOT NULL'
            ],
            [
                'schema',
                'column6',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column6` DATETIME NOT NULL'
            ],
            [
                '',
                'column7',
                null,
                'ALTER TABLE `table` MODIFY `column7` TEXT NOT NULL'
            ],
            [
                'schema',
                'column7',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column7` TEXT NOT NULL'
            ],
            [
                '',
                'column8',
                null,
                'ALTER TABLE `table` MODIFY `column8` FLOAT(10,2) NOT NULL'
            ],
            [
                'schema',
                'column8',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column8` FLOAT(10,2) NOT NULL'
            ],
            [
                '',
                'column9',
                null,
                'ALTER TABLE `table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"'
            ],
            [
                'schema',
                'column9',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column9` VARCHAR(10) DEFAULT "column9"'
            ],
            [
                '',
                'column10',
                null,
                'ALTER TABLE `table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"'
            ],
            [
                'schema',
                'column10',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column10` INT(18) UNSIGNED DEFAULT "10"'
            ],
            [
                '',
                'column11',
                null,
                'ALTER TABLE `table` MODIFY `column11` BIGINT(20) UNSIGNED'
            ],
            [
                'schema',
                'column11',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column11` BIGINT(20) UNSIGNED'
            ],
            [
                '',
                'column12',
                null,
                'ALTER TABLE `table` MODIFY `column12` ENUM("A", "B", "C") ' .
                'DEFAULT "A" NOT NULL AFTER `column11`'
            ],
            [
                'schema',
                'column12',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column12` ENUM("A", "B", "C") ' .
                'DEFAULT "A" NOT NULL AFTER `column11`'
            ],
            [
                '',
                'column13',
                null,
                'ALTER TABLE `table` MODIFY `column13` ' .
                'TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
            [
                'schema',
                'column13',
                null,
                'ALTER TABLE `schema`.`table` MODIFY `column13` ' .
                'TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getModifyColumnFixtures13012(): array
    {
        return [
            new Column('old', ['type' => Column::TYPE_VARCHAR]),
            new Column('new', ['type' => Column::TYPE_VARCHAR]),
        ];
    }

    /**
     * @return string
     */
    protected function getModifyColumnSql(): string
    {
        return 'ALTER TABLE `database`.`table` CHANGE COLUMN `old` `new` VARCHAR(0)';
    }

    /**
     * @return string
     */
    protected function getReleaseSavepointSql(): string
    {
        return 'RELEASE SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return string
     */
    protected function getRollbackSavepointSql(): string
    {
        return 'ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return array
     */
    protected function getTableExistsFixtures(): array
    {
        return [
            [
                null,
                "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` " .
                "WHERE `TABLE_NAME` = 'table' AND `TABLE_SCHEMA` = DATABASE()"
            ],
            [
                'schema',
                "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` " .
                "WHERE `TABLE_NAME`= 'table' AND `TABLE_SCHEMA` = 'schema'"
            ]
        ];
    }

    /**
     * @return array
     */
    protected function getTruncateTableFixtures(): array
    {
        return [
            ['',       'TRUNCATE TABLE `table`'],
            ['schema', 'TRUNCATE TABLE `schema`.`table`'],
        ];
    }

    /**
     * @return array
     */
    protected function getViewExistsFixtures(): array
    {
        return [
            [
                null,
                "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` " .
                "WHERE `TABLE_NAME`='view' AND `TABLE_SCHEMA` = DATABASE()"
            ],
            [
                'schema',
                "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` " .
                "WHERE `TABLE_NAME`= 'view' AND `TABLE_SCHEMA`='schema'"
            ]
        ];
    }






//    protected function addForeignKey($foreignKeyName = '', $onUpdate = '', $onDelete = '')
//    {
//        $sql = 'ALTER TABLE `foreign_key_child` ADD';
//        if ($foreignKeyName) {
//            $sql .= ' CONSTRAINT `' . $foreignKeyName . '`';
//        }
//        $sql .= ' FOREIGN KEY (`child_int`) REFERENCES `foreign_key_parent`(`refer_int`)';
//
//        if ($onDelete) {
//            $sql .= ' ON DELETE ' . $onDelete;
//        }
//        if ($onUpdate) {
//            $sql .= ' ON UPDATE ' . $onUpdate;
//        }
//
//        return $sql;
//    }
//    protected function getForeignKey($foreignKeyName)
//    {
//        $sql = "SELECT
//                COUNT(`CONSTRAINT_NAME`)
//            FROM information_schema.REFERENTIAL_CONSTRAINTS
//            WHERE TABLE_NAME = 'foreign_key_child' AND
//                `UPDATE_RULE` = 'CASCADE' AND
//                `DELETE_RULE` = 'RESTRICT' AND
//                `CONSTRAINT_NAME` = '$foreignKeyName'";
//
//        return $sql;
//    }
//    protected function dropForeignKey($foreignKeyName)
//    {
//        $sql = "ALTER TABLE `foreign_key_child` DROP FOREIGN KEY $foreignKeyName";
//
//        return $sql;
//    }
}
