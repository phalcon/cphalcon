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
 * Outputs the MySQL-only preamble that must appear at the top of every
 * generated schema file.  Other drivers need no bootstrap statements.
 */
class BootstrapMigration extends AbstractMigration
{
    protected $table = '';

    protected function getSqlMysql(): array
    {
        return [
            "SET NAMES utf8;",
            "SET FOREIGN_KEY_CHECKS=0;",
            "CREATE DATABASE IF NOT EXISTS `private`;",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "CREATE SCHEMA IF NOT EXISTS private;",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "CREATE SCHEMA IF NOT EXISTS private;",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
