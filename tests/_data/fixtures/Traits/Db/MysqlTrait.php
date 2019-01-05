<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits\Db;

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;

/**
 * Trait MysqlTrait
 *
 * @package Phalcon\Test\Fixtures\Traits\Db
 */
trait MysqlTrait
{
    protected $connection = null;

    /**
     * Constructor
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $this->connection = $this->getService('db');
    }

    /**
     * @inheritdoc
     */
    abstract protected function setNewFactoryDefault();

    /**
     * @inheritdoc
     */
    abstract protected function setDiMysql();

    /**
     * Returns the database schema; MySql does not have a schema
     *
     * @return string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    protected function getSchemaName(): string
    {
        return env('DATA_MYSQL_NAME');
    }

    /**
     * Return the array of expected columns
     *
     * @return array
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    protected function getExpectedColumns(): array
    {
        $result  = [];
        $columns = $this->getColumns();
        foreach ($columns as $index => $array) {
            $result[$index] = Column::__set_state($array);
        }

        return $result;
    }

    /**
     * Return the array of columns
     *
     * @return array
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    protected function getColumns(): array
    {
        return [
            0  => [
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
            ],
            1  => [
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
            ],
            2  => [
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
            ],
            3  => [
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
            ],
            4  => [
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
            ],
            5  => [
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
            ],
            6  => [
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
            ],
            7  => [
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
            ],
            8  => [
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
            ],
            9  => [
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
            ],
            10 => [
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
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            11 => [
                '_columnName'    => 'field_decimal_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_DECIMAL,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 4,
                '_default'       => '14.5678',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_decimal',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            12 => [
                '_columnName'    => 'field_enum',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_ENUM,
                '_isNumeric'     => false,
                '_size'          => "'xs','s','m','l','xl'",
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_decimal_default',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            13 => [
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
                '_after'         => 'field_enum',
                '_bindType'      => Column::BIND_PARAM_INT,
            ],
            14 => [
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
            ],
            15 => [
                '_columnName'    => 'field_json',
                '_schemaName'    => false,
                '_type'          => Column::TYPE_JSON,
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
            ],
            16 => [
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
            ],
            17 => [
                '_columnName'    => 'field_float_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_FLOAT,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 4,
                '_default'       => '14.5678',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_float',
                '_bindType'      => Column::BIND_PARAM_DECIMAL,
            ],
            18 => [
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
            ],
            19 => [
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
            ],
            20 => [
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
            ],
            21 => [
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
            ],
            22 => [
                '_columnName'    => 'field_time',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_TIME,
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
            ],
            23 => [
                '_columnName'    => 'field_time_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_TIME,
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
            ],
            24 => [
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
            ],
            25 => [
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
            ],
            26 => [
                '_columnName'    => 'field_mediumint',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_MEDIUMINTEGER,
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
            ],
            27 => [
                '_columnName'    => 'field_mediumint_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_MEDIUMINTEGER,
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
            ],
            28 => [
                '_columnName'    => 'field_smallint',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_SMALLINTEGER,
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
            ],
            29 => [
                '_columnName'    => 'field_smallint_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_SMALLINTEGER,
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
            ],
            30 => [
                '_columnName'    => 'field_tinyint',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_TINYINTEGER,
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
            ],
            31 => [
                '_columnName'    => 'field_tinyint_default',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_TINYINTEGER,
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
            ],
            32 => [
                '_columnName'    => 'field_longtext',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_LONGTEXT,
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
            ],
            33 => [
                '_columnName'    => 'field_mediumtext',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_MEDIUMTEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_longtext',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            34 => [
                '_columnName'    => 'field_tinytext',
                '_schemaName'    => null,
                '_type'          => Column::TYPE_TINYTEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_mediumtext',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            35 => [
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
                '_after'         => 'field_tinytext',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            36 => [
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
            ],
            37 => [
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
            ],
        ];
    }

    /**
     * Return the array of expected indexes
     *
     * @return array
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    protected function getExpectedIndexes(): array
    {
        return [
            'PRIMARY'                  => Index::__set_state(
                [
                    '_name'    => 'PRIMARY',
                    '_columns' => ['field_primary'],
                    '_type'    => 'PRIMARY',
                ]
            ),
            'dialect_table_unique'     => Index::__set_state(
                [
                    '_name'    => 'dialect_table_unique',
                    '_columns' => ['field_integer'],
                    '_type'    => 'UNIQUE',
                ]
            ),
            'dialect_table_index'      => Index::__set_state(
                [
                    '_name'    => 'dialect_table_index',
                    '_columns' => ['field_bigint'],
                    '_type'    => '',
                ]
            ),
            'dialect_table_two_fields' => Index::__set_state(
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
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
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
                    '_referencedSchema'  => $this->getDatabaseName(),
                    '_onUpdate'          => 'RESTRICT',
                    '_onDelete'          => 'RESTRICT',
                ]
            ),
            'dialect_table_intermediate_remote__fk'  => Reference::__set_state(
                [
                    '_referenceName'     => 'dialect_table_intermediate_remote__fk',
                    '_referencedTable'   => 'dialect_table_remote',
                    '_columns'           => ['field_remote_id'],
                    '_referencedColumns' => ['field_primary'],
                    '_referencedSchema'  => $this->getDatabaseName(),
                    '_onUpdate'          => 'CASCADE',
                    '_onDelete'          => 'SET NULL',
                ]
            ),
        ];
    }

    /**
     * Returns the database name
     *
     * @return string
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-10-26
     */
    protected function getDatabaseName(): string
    {
        return env('DATA_MYSQL_NAME');
    }
}
