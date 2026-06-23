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

namespace Phalcon\Tests\Database\Db\Dialect\Sqlite;

use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ListIndexesSqlTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: listIndexesSql()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectSqliteListIndexesSql(): void
    {
        $dialect = new Sqlite();

        $this->assertSame(
            'SELECT sql FROM sqlite_master '
            . 'WHERE type = \'index\' AND tbl_name = "robots" COLLATE NOCASE',
            $dialect->listIndexesSql('robots')
        );

        $this->assertSame(
            'SELECT sql FROM sqlite_master '
            . 'WHERE type = \'index\' AND tbl_name = "robots" COLLATE NOCASE'
            . ' AND name = "idx_robots_name" COLLATE NOCASE',
            $dialect->listIndexesSql('robots', null, 'idx_robots_name')
        );
    }
}
