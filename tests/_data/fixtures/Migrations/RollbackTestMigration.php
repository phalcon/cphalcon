<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Migrations;

/**
 * Class InvoicesMigration
 */
class RollbackTestMigration extends AbstractMigration
{
    protected $table = 'co_rb_test_model';

    protected function getSqlMysql(): array
    {
        return [
            'DROP TABLE IF EXISTS co_rb_test_model;',
            'CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);',
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlPgsql(): array
    {
        return [
            'DROP TABLE IF EXISTS co_rb_test_model;',
            'CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);',
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
