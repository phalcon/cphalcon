<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Db\Dialect\Fake;

use Phalcon\Db\ColumnInterface;
use Phalcon\Db\Dialect;
use Phalcon\Db\IndexInterface;
use Phalcon\Db\ReferenceInterface;

/**
 * A dialect that does not set an escape character
 */
class FakeDialect extends Dialect
{
    public function addColumn(string $tableName, string $schemaName, ColumnInterface $column): string
    {
        return '';
    }

    public function addForeignKey(string $tableName, string $schemaName, ReferenceInterface $reference): string
    {
        return '';
    }

    public function addIndex(string $tableName, string $schemaName, IndexInterface $index): string
    {
        return '';
    }

    public function addPrimaryKey(string $tableName, string $schemaName, IndexInterface $index): string
    {
        return '';
    }

    public function createTable(string $tableName, string $schemaName, array $definition): string
    {
        return '';
    }

    public function createView(string $viewName, array $definition, ?string $schemaName = null): string
    {
        return '';
    }

    public function describeColumns(string $table, ?string $schema = null): string
    {
        return '';
    }

    public function describeIndexes(string $table, ?string $schema = null): string
    {
        return '';
    }

    public function describeReferences(string $table, ?string $schema = null): string
    {
        return '';
    }

    public function dropColumn(string $tableName, string $schemaName, string $columnName): string
    {
        return '';
    }

    public function dropForeignKey(string $tableName, string $schemaName, string $referenceName): string
    {
        return '';
    }

    public function dropIndex(string $tableName, string $schemaName, string $indexName): string
    {
        return '';
    }

    public function dropPrimaryKey(string $tableName, string $schemaName): string
    {
        return '';
    }

    public function dropTable(string $tableName, string $schemaName, bool $ifExists = true): string
    {
        return '';
    }

    public function dropView(string $viewName, ?string $schemaName = null, bool $ifExists = true): string
    {
        return '';
    }

    public function getColumnDefinition(ColumnInterface $column): string
    {
        return '';
    }

    public function listTables(?string $schemaName = null): string
    {
        return '';
    }

    public function modifyColumn(
        string $tableName,
        string $schemaName,
        ColumnInterface $column,
        ?ColumnInterface $currentColumn = null
    ): string {
        return '';
    }

    public function sharedLock(string $sqlQuery, string $modifier = ''): string
    {
        return '';
    }

    public function tableExists(string $tableName, ?string $schemaName = null): string
    {
        return '';
    }

    public function tableOptions(string $table, ?string $schema = null): string
    {
        return '';
    }

    public function viewExists(string $viewName, ?string $schemaName = null): string
    {
        return '';
    }
}
