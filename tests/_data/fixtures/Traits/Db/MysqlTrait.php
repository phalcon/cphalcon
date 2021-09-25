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

use Phalcon\Db\Index;
use Phalcon\Db\Reference;

/**
 * Trait MysqlTrait
 *
 * @package Phalcon\Tests\Fixtures\Traits\Db
 */
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
