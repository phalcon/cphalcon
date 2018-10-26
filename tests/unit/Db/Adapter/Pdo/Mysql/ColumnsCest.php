<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Mysql;

use Helper\Db\Adapter\Pdo\MysqlTrait;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Test\Unit\Db\Adapter\Pdo\ColumnsBase;

class ColumnsCest extends ColumnsBase
{
    use MysqlTrait;

    /**
     * Return the array of expected columns
     *
     * @return array
     * @since 2018-10-26
     */
    protected function getExpectedColumns(): array
    {
        return [
            0  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_primary',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 11,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => true,
                    '_autoIncrement' => true,
                    '_primary'       => true,
                    '_first'         => true,
                    '_after'         => null,
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            1  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_blob',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BLOB,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_primary',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            2  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_bit',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BIT,
                    '_isNumeric'     => false,
                    '_size'          => 1,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_blob',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            3  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_bit_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BIT,
                    '_isNumeric'     => false,
                    '_size'          => 1,
                    '_scale'         => 0,
                    '_default'       => "b'1'",
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_bit',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            4  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_bigint',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BIGINTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 20,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_bit_default',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            5  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_bigint_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BIGINTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 20,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_bigint',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            6  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_boolean',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BOOLEAN,
                    '_isNumeric'     => true,
                    '_size'          => 1,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_bigint_default',
                    '_bindType'      => Column::BIND_PARAM_BOOL,
                ]
            ),
            7  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_boolean_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_BOOLEAN,
                    '_isNumeric'     => true,
                    '_size'          => 1,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_boolean',
                    '_bindType'      => Column::BIND_PARAM_BOOL,
                ]
            ),
            8  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_char',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_CHAR,
                    '_isNumeric'     => false,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_boolean_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            9  =>  Column::__set_state(
                [
                    '_columnName'    => 'field_char_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_CHAR,
                    '_isNumeric'     => false,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 'ABC',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_char',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            10 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_decimal',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_DECIMAL,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 4,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_char_default',
                    '_bindType'      => Column::BIND_PARAM_DECIMAL,
                ]
            ),
            11 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_decimal_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_DECIMAL,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 4,
                    '_default'       => 14.5600,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_decimal',
                    '_bindType'      => Column::BIND_PARAM_DECIMAL,
                ]
            ),
            12 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_integer',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_decimal_default',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            13 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_integer_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_integer',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            14 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_json',
                    '_schemaName'    => false,
                    '_type'          => Column::TYPE_TEXT,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_integer_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            15 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_float',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_FLOAT,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 4,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_json',
                    '_bindType'      => Column::BIND_PARAM_DECIMAL,
                ]
            ),
            16 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_float_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_FLOAT,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 4,
                    '_default'       => floatval(14.5600),
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_float',
                    '_bindType'      => Column::BIND_PARAM_DECIMAL,
                ]
            ),
            17 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_date',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_DATE,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_float_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            18 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_date_default',
                    '_schemaName'    => false,
                    '_type'          => Column::TYPE_DATE,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => '2018-10-01',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_date',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            19 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_datetime',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_DATETIME,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_date_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            20 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_datetime_default',
                    '_schemaName'    => false,
                    '_type'          => Column::TYPE_DATETIME,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => '2018-10-01 12:34:56',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_datetime',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            21 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_time',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_VARCHAR,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_datetime_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            22 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_time_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_VARCHAR,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => '12:34:56',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_time',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            23 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_timestamp',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_TIMESTAMP,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_time_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            24 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_timestamp_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_TIMESTAMP,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => '2018-10-01 12:34:56',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_timestamp',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            25 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_mediumint',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_timestamp_default',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            26 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_mediumint_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_mediumint',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            27 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_smallint',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_mediumint_default',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            28 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_smallint_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_smallint',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            29 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_tinyint',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_smallint_default',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            30 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_tinyint_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_INTEGER,
                    '_isNumeric'     => true,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 1,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_tinyint',
                    '_bindType'      => Column::BIND_PARAM_INT,
                ]
            ),
            31 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_text',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_TEXT,
                    '_isNumeric'     => false,
                    '_size'          => 0,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_tinyint_default',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            32 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_varchar',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_VARCHAR,
                    '_isNumeric'     => false,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => null,
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_text',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
            33 =>  Column::__set_state(
                [
                    '_columnName'    => 'field_varchar_default',
                    '_schemaName'    => null,
                    '_type'          => Column::TYPE_VARCHAR,
                    '_isNumeric'     => false,
                    '_size'          => 10,
                    '_scale'         => 0,
                    '_default'       => 'D',
                    '_unsigned'      => false,
                    '_notNull'       => false,
                    '_autoIncrement' => false,
                    '_primary'       => false,
                    '_first'         => false,
                    '_after'         => 'field_varchar',
                    '_bindType'      => Column::BIND_PARAM_STR,
                ]
            ),
        ];
    }

    /**
     * Return the array of expected indexes
     *
     * @return array
     * @since 2018-10-26
     */
    protected function getExpectedIndexes(): array
    {
        return [
            'PRIMARY'  =>  Index::__set_state(
                [
                    '_name'    => 'PRIMARY',
                    '_columns' => ['field_primary'],
                    '_type'    => 'PRIMARY',
                ]
            ),
            'dialect_table_unique'  =>  Index::__set_state(
                [
                    '_name'    => 'dialect_table_unique',
                    '_columns' => ['field_integer'],
                    '_type'    => 'UNIQUE',
                ]
            ),
            'dialect_table_index'  =>  Index::__set_state(
                [
                    '_name'    => 'dialect_table_index',
                    '_columns' => ['field_bigint'],
                    '_type'    => '',
                ]
            ),
            'dialect_table_two_fields'  =>  Index::__set_state(
                [
                    '_name'    => 'dialect_table_two_fields',
                    '_columns' => ['field_char', 'field_char_default'],
                    '_type'    => '',
                ]
            ),
        ];
    }

    /**
     * Return the array of expected references
     *
     * @return array
     */
    protected function getExpectedReferences(): array
    {
        return [
            'dialect_table_intermediate_primary__fk' => Reference::__set_state(
                [
                    '_referenceName'     => 'dialect_table_intermediate_primary__fk',
                    '_referencedTable'   => 'dialect_table',
                    '_columns'           => ['field_primary_id'],
                    '_referencedColumns' => ['field_primary'],
                    '_referencedSchema'  => $this->databaseName,
                    '_onUpdate'          => 'RESTRICT',
                    '_onDelete'          => 'RESTRICT'
                ]
            ),
            'dialect_table_intermediate_remote__fk' => Reference::__set_state(
                [
                    '_referenceName'     => 'dialect_table_intermediate_remote__fk',
                    '_referencedTable'   => 'dialect_table_remote',
                    '_columns'           => ['field_remote_id'],
                    '_referencedColumns' => ['field_primary'],
                    '_referencedSchema'  => $this->databaseName,
                    '_onUpdate'          => 'CASCADE',
                    '_onDelete'          => 'SET NULL'
                ]
            ),
        ];
    }
}
