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

namespace Phalcon\Tests\Database\Db\Dialect\Postgresql;

use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SelectTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: select()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectPostgresqlSelect(): void
    {
        $dialect = new Postgresql();

        $definition = [
            'tables'  => ['robots'],
            'columns' => ['*'],
        ];

        $this->assertSame(
            'SELECT * FROM "robots"',
            $dialect->select($definition)
        );
    }
}
