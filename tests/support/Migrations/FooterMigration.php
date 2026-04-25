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

/**
 * Outputs the MySQL-only epilogue that must appear at the bottom of every
 * generated schema file, re-enabling foreign key checks after all tables
 * have been created.  Other drivers need no footer statements.
 */
class FooterMigration extends AbstractMigration
{
    protected $table = '';

    protected function getSqlMysql(): array
    {
        return [
            "SET FOREIGN_KEY_CHECKS=1;",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}

