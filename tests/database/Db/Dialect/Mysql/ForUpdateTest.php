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

namespace Phalcon\Tests\Database\Db\Dialect\Mysql;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ForUpdateTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: forUpdate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectMysqlForUpdate(): void
    {
        $dialect = new Mysql();

        $this->assertSame(
            'SELECT * FROM robots FOR UPDATE',
            $dialect->forUpdate('SELECT * FROM robots')
        );
    }
}
