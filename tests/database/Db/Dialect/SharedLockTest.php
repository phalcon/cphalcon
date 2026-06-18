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

final class SharedLockTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'SQL-QUERY LOCK IN SHARE MODE',
            ],
            [
                Postgresql::class,
                'SQL-QUERY FOR SHARE',
            ],
            [
                Sqlite::class,
                'SQL-QUERY',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: sharedLock
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    #[DataProvider('getDialects')]
    public function testDbDialectSharedLock(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->sharedLock('SQL-QUERY');
        $this->assertSame($expected, $actual);
    }
}
