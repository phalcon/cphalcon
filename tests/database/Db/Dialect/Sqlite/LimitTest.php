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
final class LimitTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: limit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectSqliteLimit(): void
    {
        $dialect = new Sqlite();

        $this->assertSame(
            'SELECT * FROM robots LIMIT 10',
            $dialect->limit('SELECT * FROM robots', 10)
        );

        $this->assertSame(
            'SELECT * FROM robots LIMIT 10 OFFSET 50',
            $dialect->limit('SELECT * FROM robots', [10, 50])
        );
    }
}
