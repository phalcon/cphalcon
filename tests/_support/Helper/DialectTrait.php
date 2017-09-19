<?php

namespace Helper;

use Phalcon\Db\Index;
use Phalcon\Db\Column;
use Phalcon\Db\Reference;

/**
 * \Helper\DialectTrait
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
trait DialectTrait
{
    /**
     * @return Column[]
     */
    protected function getColumns()
    {
        return [
            'column1'  => new Column('column1', [
                'type' => Column::TYPE_VARCHAR,
                'size' => 10
            ]),
            'column2'  => new Column('column2', [
                'type'     => Column::TYPE_INTEGER,
                'size'     => 18,
                'unsigned' => true,
                'notNull'  => false
            ]),
            'column3'  => new Column('column3', [
                'type'     => Column::TYPE_DECIMAL,
                'size'     => 10,
                'scale'    => 2,
                'unsigned' => false,
                'notNull'  => true
            ]),
            'column4'  => new Column('column4', [
                'type'    => Column::TYPE_CHAR,
                'size'    => 100,
                'notNull' => true
            ]),
            'column5'  => new Column('column5', [
                'type'    => Column::TYPE_DATE,
                'notNull' => true
            ]),
            'column6'  => new Column('column6', [
                'type'    => Column::TYPE_DATETIME,
                'notNull' => true
            ]),
            'column7'  => new Column('column7', [
                'type'    => Column::TYPE_TEXT,
                'notNull' => true
            ]),
            'column8'  => new Column('column8', [
                'type'     => Column::TYPE_FLOAT,
                'size'     => 10,
                'scale'    => 2,
                'unsigned' => false,
                'notNull'  => true
            ]),
            'column9'  => new Column('column9', [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 10,
                'default' => 'column9'
            ]),
            'column10' => new Column('column10', [
                'type'     => Column::TYPE_INTEGER,
                'size'     => 18,
                'unsigned' => true,
                'notNull'  => false,
                'default'  => 10,
            ]),
            'column11' => new Column('column11', [
                'type'          => 'BIGINT',
                'typeReference' => Column::TYPE_INTEGER,
                'size'          => 20,
                'unsigned'      => true,
                'notNull'       => false
            ]),
            'column12' => new Column('column12', [
                'type'       => 'ENUM',
                'typeValues' => ['A', 'B', 'C'],
                'notNull'    => true,
                'default'    => 'A',
                'after'      => 'column11'
            ]),
            'column13' => new Column('column13', [
                'type'    => Column::TYPE_TIMESTAMP,
                'notNull' => true,
                'default' => 'CURRENT_TIMESTAMP',
            ]),
            'column14' => new Column('column14', [
                'type'    => Column::TYPE_TINYBLOB,
                'notNull' => true
            ]),
            'column15' => new Column('column15', [
                'type'    => Column::TYPE_MEDIUMBLOB,
                'notNull' => true
            ]),
            'column16' => new Column('column16', [
                'type'    => Column::TYPE_BLOB,
                'notNull' => true
            ]),
            'column17' => new Column('column17', [
                'type'    => Column::TYPE_LONGBLOB,
                'notNull' => true
            ]),
            'column18' => new Column('column18', [
                'type' => Column::TYPE_BOOLEAN,
            ]),
            'column19' => new Column('column19', [
                'type' => Column::TYPE_DOUBLE,
            ]),
            'column20' => new Column('column20', [
                'type'     => Column::TYPE_DOUBLE,
                'unsigned' => true
            ]),
            'column21' => new Column('column21', [
                'type'          => Column::TYPE_BIGINTEGER,
                'autoIncrement' => true,
            ]),
            'column22' => new Column('column22', [
                'type'          => Column::TYPE_BIGINTEGER,
                'autoIncrement' => false,
            ]),
            'column23' => new Column('column23', [
                'type'          => Column::TYPE_INTEGER,
                'autoIncrement' => true,
            ]),
        ];
    }

    /**
     * @return Index[]
     */
    protected function getIndexes()
    {
        return [
            'index1'  => new Index('index1', ['column1']),
            'index2'  => new Index('index2', ['column1', 'column2']),
            'PRIMARY' => new Index('PRIMARY', ['column3']),
            'index4'  => new Index('index4', ['column4'], 'UNIQUE'),
            'index5'  => new Index('index5', ['column7'], 'FULLTEXT'),
        ];
    }

    /**
     * @return Reference[]
     */
    protected function getReferences()
    {
        return [
            'fk1' => new Reference('fk1', [
                'referencedTable'   => 'ref_table',
                'columns'           => ['column1'],
                'referencedColumns' => ['column2']
            ]),
            'fk2' => new Reference('fk2', [
                'referencedTable'   => 'ref_table',
                'columns'           => ['column3', 'column4'],
                'referencedColumns' => ['column5', 'column6']
            ]),
            'fk3' => new Reference('fk3', [
                'referencedTable'   => 'ref_table',
                'columns'           => ['column1'],
                'referencedColumns' => ['column2'],
                'onDelete'          => 'CASCADE',
            ]),
            'fk4' => new Reference('fk4', [
                'referencedTable'   => 'ref_table',
                'columns'           => ['column1'],
                'referencedColumns' => ['column2'],
                'onUpdate'          => 'SET NULL',
            ]),
            'fk5' => new Reference('fk5', [
                'referencedTable'   => 'ref_table',
                'columns'           => ['column1'],
                'referencedColumns' => ['column2'],
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'NO ACTION',
            ]),
        ];
    }
}
