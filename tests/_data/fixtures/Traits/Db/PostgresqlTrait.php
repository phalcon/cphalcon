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

namespace Phalcon\Tests\Fixtures\Traits\Db;

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use function array_shift;

/**
 * Trait PostgresqlTrait
 *
 * @package Phalcon\Tests\Fixtures\Traits\Db
 */
trait PostgresqlTrait
{
    protected $connection = null;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiPostgresql();

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
    abstract protected function setDiPostgresql();

    /**
     * Returns the database schema;
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getSchemaName(): string
    {
        return env('DATA_POSTGRES_SCHEMA');
    }

    /**
     * Return the array of expected columns
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getExpectedColumns(): array
    {
        $result = [];

        $columns = $this->getColumns();

        foreach ($columns as $index => $array) {
            $name           = array_shift($array);
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
                '_columnName'    => 'field_primary',
                '_type'          => Column::TYPE_INTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
                '_scale'         => 0,
                '_default'       => "nextval('dialect_table_field_primary_seq'::regclass)",
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
                '_type'          => Column::TYPE_TEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_BIT,
                '_isNumeric'     => false,
                '_size'          => null,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_blob',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            3  => [
                '_columnName'    => 'field_bit_default',
                '_type'          => Column::TYPE_BIT,
                '_isNumeric'     => false,
                '_size'          => null,
                '_default'       => "B'1'::\"bit\"",
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_bit',
                '_bindType'      => Column::BIND_PARAM_STR,
            ],
            4  => [
                '_columnName'    => 'field_bigint',
                '_type'          => Column::TYPE_BIGINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_BIGINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_BOOLEAN,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_BOOLEAN,
                '_isNumeric'     => true,
                '_size'          => 0,
                '_default'       => 'true',
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
                '_type'          => Column::TYPE_CHAR,
                '_isNumeric'     => false,
                '_size'          => 10,
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
                '_type'          => Column::TYPE_CHAR,
                '_isNumeric'     => false,
                '_size'          => 10,
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
                '_type'          => Column::TYPE_DECIMAL,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
                '_default'       => null,
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_char_default',
                '_bindType'      => Column::BIND_PARAM_DECIMAL,
            ],
            11 => [
                '_columnName'    => 'field_decimal_default',
                '_type'          => Column::TYPE_DECIMAL,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
                '_default'       => '14.5678',
                '_unsigned'      => false,
                '_notNull'       => false,
                '_autoIncrement' => false,
                '_primary'       => false,
                '_first'         => false,
                '_after'         => 'field_decimal',
                '_bindType'      => Column::BIND_PARAM_DECIMAL,
            ],
            12 => [
                '_columnName'    => 'field_enum',
                '_type'          => Column::TYPE_VARCHAR,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_INTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_INTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_JSON,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_DECIMAL,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
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
                '_type'          => Column::TYPE_DECIMAL,
                '_isNumeric'     => true,
                '_size'          => 10,
                '_scale'         => 0,
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
                '_type'          => Column::TYPE_DATE,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_DATE,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIMESTAMP,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIMESTAMP,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIME,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIME,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIMESTAMP,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TIMESTAMP,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_INTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_INTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_SMALLINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_SMALLINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_SMALLINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_SMALLINTEGER,
                '_isNumeric'     => true,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_TEXT,
                '_isNumeric'     => false,
                '_size'          => 0,
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
                '_type'          => Column::TYPE_VARCHAR,
                '_isNumeric'     => false,
                '_size'          => 10,
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
                '_type'          => Column::TYPE_VARCHAR,
                '_isNumeric'     => false,
                '_size'          => 10,
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-10-26
     */
    protected function getExpectedIndexes(): array
    {
        return [
            'dialect_table_pk'         => new Index('dialect_table_pk', ['field_primary'], ''),
            'dialect_table_unique'     => new Index('dialect_table_unique', ['field_integer'], ''),
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
                    '_referencedTable'   => 'dialect_table',
                    '_columns'           => ['field_primary_id'],
                    '_referencedColumns' => ['field_primary'],
                    '_referencedSchema'  => $this->getDatabaseName(),
                    '_onUpdate'          => 'NO ACTION',
                    '_onDelete'          => 'NO ACTION',
                ]
            ),
            'dialect_table_intermediate_remote__fk'  => new Reference(
                'dialect_table_intermediate_remote__fk',
                [
                    '_referencedTable'   => 'dialect_table_remote',
                    '_columns'           => ['field_remote_id'],
                    '_referencedColumns' => ['field_primary'],
                    '_referencedSchema'  => $this->getDatabaseName(),
                    '_onUpdate'          => 'NO ACTION',
                    '_onDelete'          => 'NO ACTION',
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
        return env('DATA_POSTGRES_NAME');
    }
}
