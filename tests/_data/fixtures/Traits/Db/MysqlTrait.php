<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits\Db;

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use function array_flip;
use function array_shift;

trait MysqlTrait
{
    protected $connection = null;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $this->connection = $this->getService('db');
    }

    public function _after()
    {
        $this->connection->close();
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getSchemaName(): string
    {
        return env('DATA_MYSQL_NAME');
    }

    /**
     * Return the array of expected columns
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getExpectedColumns(): array
    {
        $result  = [];

        $columns = $this->getColumns();

        foreach ($columns as $index => $array) {
            $name = array_shift($array);
            $result[$index] = new Column($name, $array);
        }

        return $result;
    }

    /**
     * Return the array of columns
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getColumns(): array
    {
        return [
            0  => [
                'columnName'    => 'field_primary',
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
            ],
            1  => [
                'columnName'    => 'field_blob',
                'type'          => Column::TYPE_BLOB,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_primary',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            2  => [
                'columnName'    => 'field_bit',
                'type'          => Column::TYPE_BIT,
                'isNumeric'     => false,
                'size'          => 1,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_blob',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            3  => [
                'columnName'    => 'field_bit_default',
                'type'          => Column::TYPE_BIT,
                'isNumeric'     => false,
                'size'          => 1,
                'default'       => "b'1'",
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_bit',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            4  => [
                'columnName'    => 'field_bigint',
                'type'          => Column::TYPE_BIGINTEGER,
                'isNumeric'     => true,
                'size'          => 20,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_bit_default',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            5  => [
                'columnName'    => 'field_bigint_default',
                'type'          => Column::TYPE_BIGINTEGER,
                'isNumeric'     => true,
                'size'          => 20,
                'scale'         => 0,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_bigint',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            6  => [
                'columnName'    => 'field_boolean',
                'type'          => Column::TYPE_BOOLEAN,
                'isNumeric'     => true,
                'size'          => 1,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_bigint_default',
                'bindType'      => Column::BIND_PARAM_BOOL,
            ],
            7  => [
                'columnName'    => 'field_boolean_default',
                'type'          => Column::TYPE_BOOLEAN,
                'isNumeric'     => true,
                'size'          => 1,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_boolean',
                'bindType'      => Column::BIND_PARAM_BOOL,
            ],
            8  => [
                'columnName'    => 'field_char',
                'type'          => Column::TYPE_CHAR,
                'isNumeric'     => false,
                'size'          => 10,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_boolean_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            9  => [
                'columnName'    => 'field_char_default',
                'type'          => Column::TYPE_CHAR,
                'isNumeric'     => false,
                'size'          => 10,
                'default'       => 'ABC',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_char',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            10 => [
                'columnName'    => 'field_decimal',
                'type'          => Column::TYPE_DECIMAL,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 4,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_char_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            11 => [
                'columnName'    => 'field_decimal_default',
                'type'          => Column::TYPE_DECIMAL,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 4,
                'default'       => '14.5678',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_decimal',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            12 => [
                'columnName'    => 'field_enum',
                'type'          => Column::TYPE_ENUM,
                'isNumeric'     => false,
                'size'          => "'xs','s','m','l','xl','internal'",
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_decimal_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            13 => [
                'columnName'    => 'field_integer',
                'type'          => Column::TYPE_INTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_enum',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            14 => [
                'columnName'    => 'field_integer_default',
                'type'          => Column::TYPE_INTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_integer',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            15 => [
                'columnName'    => 'field_json',
                'type'          => Column::TYPE_JSON,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_integer_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            16 => [
                'columnName'    => 'field_float',
                'type'          => Column::TYPE_FLOAT,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 4,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_json',
                'bindType'      => Column::BIND_PARAM_DECIMAL,
            ],
            17 => [
                'columnName'    => 'field_float_default',
                'type'          => Column::TYPE_FLOAT,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 4,
                'default'       => '14.5678',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_float',
                'bindType'      => Column::BIND_PARAM_DECIMAL,
            ],
            18 => [
                'columnName'    => 'field_date',
                'type'          => Column::TYPE_DATE,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_float_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            19 => [
                'columnName'    => 'field_date_default',
                'type'          => Column::TYPE_DATE,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => '2018-10-01',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_date',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            20 => [
                'columnName'    => 'field_datetime',
                'type'          => Column::TYPE_DATETIME,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_date_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            21 => [
                'columnName'    => 'field_datetime_default',
                'type'          => Column::TYPE_DATETIME,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => '2018-10-01 12:34:56',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_datetime',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            22 => [
                'columnName'    => 'field_time',
                'type'          => Column::TYPE_TIME,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_datetime_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            23 => [
                'columnName'    => 'field_time_default',
                'type'          => Column::TYPE_TIME,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => '12:34:56',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_time',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            24 => [
                'columnName'    => 'field_timestamp',
                'type'          => Column::TYPE_TIMESTAMP,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_time_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            25 => [
                'columnName'    => 'field_timestamp_default',
                'type'          => Column::TYPE_TIMESTAMP,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => '2018-10-01 12:34:56',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_timestamp',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            26 => [
                'columnName'    => 'field_mediumint',
                'type'          => Column::TYPE_MEDIUMINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_timestamp_default',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            27 => [
                'columnName'    => 'field_mediumint_default',
                'type'          => Column::TYPE_MEDIUMINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_mediumint',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            28 => [
                'columnName'    => 'field_smallint',
                'type'          => Column::TYPE_SMALLINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_mediumint_default',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            29 => [
                'columnName'    => 'field_smallint_default',
                'type'          => Column::TYPE_SMALLINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_smallint',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            30 => [
                'columnName'    => 'field_tinyint',
                'type'          => Column::TYPE_TINYINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_smallint_default',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            31 => [
                'columnName'    => 'field_tinyint_default',
                'type'          => Column::TYPE_TINYINTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => 0,
                'default'       => 1,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_tinyint',
                'bindType'      => Column::BIND_PARAM_INT,
            ],
            32 => [
                'columnName'    => 'field_longtext',
                'type'          => Column::TYPE_LONGTEXT,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_tinyint_default',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            33 => [
                'columnName'    => 'field_mediumtext',
                'type'          => Column::TYPE_MEDIUMTEXT,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_longtext',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            34 => [
                'columnName'    => 'field_tinytext',
                'type'          => Column::TYPE_TINYTEXT,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_mediumtext',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            35 => [
                'columnName'    => 'field_text',
                'type'          => Column::TYPE_TEXT,
                'isNumeric'     => false,
                'size'          => 0,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_tinytext',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            36 => [
                'columnName'    => 'field_varchar',
                'type'          => Column::TYPE_VARCHAR,
                'isNumeric'     => false,
                'size'          => 10,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_text',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
            37 => [
                'columnName'    => 'field_varchar_default',
                'type'          => Column::TYPE_VARCHAR,
                'isNumeric'     => false,
                'size'          => 10,
                'default'       => 'D',
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_varchar',
                'bindType'      => Column::BIND_PARAM_STR,
            ],
        ];
    }

    /**
     * Return the array of expected indexes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getExpectedIndexes(): array
    {
        return [
            'PRIMARY'                  => new Index('PRIMARY', ['field_primary'], 'PRIMARY'),
            'dialect_table_unique'     => new Index('dialect_table_unique', ['field_integer'], 'UNIQUE'),
            'dialect_table_index'      => new Index('dialect_table_index', ['field_bigint'], ''),
            'dialect_table_two_fields' => new Index('dialect_table_two_fields', ['field_char', 'field_char_default'], ''),
        ];
    }

    /**
     * Return the array of expected references
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getExpectedReferences(): array
    {
        return [
            'dialect_table_intermediate_primary__fk' => new Reference(
                'dialect_table_intermediate_primary__fk',
                [
                    'referencedTable'   => 'dialect_table',
                    'columns'           => ['field_primary_id'],
                    'referencedColumns' => ['field_primary'],
                    'referencedSchema'  => $this->getDatabaseName(),
                    'onUpdate'          => 'RESTRICT',
                    'onDelete'          => 'RESTRICT',
                ]
            ),
            'dialect_table_intermediate_remote__fk'  => new Reference(
                'dialect_table_intermediate_remote__fk',
                [
                    'referencedTable'   => 'dialect_table_remote',
                    'columns'           => ['field_remote_id'],
                    'referencedColumns' => ['field_primary'],
                    'referencedSchema'  => $this->getDatabaseName(),
                    'onUpdate'          => 'CASCADE',
                    'onDelete'          => 'SET NULL',
                ]
            ),
        ];
    }

    /**
     * Returns the database name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getDatabaseName(): string
    {
        return env('DATA_MYSQL_NAME');
    }
}
