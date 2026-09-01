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

namespace Phalcon\Tests\Support\Migrations;

use Phalcon\Talon\Database\Schema\AbstractSchema;

class RollbackTestMigration extends AbstractSchema
{
    protected string $table = 'co_rb_test_model';

    protected function getStatementsMysql(): array
    {
        return [
            'CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);',
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
            'CREATE TABLE co_rb_test_model (id integer, name text not null);',
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            'CREATE TABLE co_rb_test_model (id SMALLINT, name VARCHAR(10) NOT NULL);',
        ];
    }
}
