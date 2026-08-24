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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class EscapeIntrospectionTest extends AbstractDatabaseTestCase
{
    /**
     * @return array<array{class-string}>
     */
    public static function getDialects(): array
    {
        return [
            [Mysql::class],
            [Postgresql::class],
            [Sqlite::class],
        ];
    }

    /**
     * The schema-introspection helpers concatenate the table/schema name into a
     * single-quoted SQL literal, so a quote in the name has to be escaped
     * (doubled) or it breaks out of the literal (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialects')]
    public function testDbDialectIntrospectionEscapesQuotes(string $dialectClass): void
    {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $payload = "a'b";

        $this->assertStringContainsString(
            "a''b",
            $dialect->tableExists($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->viewExists($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->describeColumns($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->describeReferences($payload, $payload)
        );
    }

    /**
     * MySQL treats the backslash as an escape character, so a backslash in the
     * name has to be doubled together with the quote.
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlIntrospectionEscapesBackslash(): void
    {
        $dialect = new Mysql();

        $this->assertStringContainsString(
            "a\\\\b",
            $dialect->tableExists("a\\b")
        );
    }
}
