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

namespace Phalcon\Tests\Database\Db\Index;

use Phalcon\Db\Exception;
use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class GetWhereTest extends AbstractDatabaseTestCase
{
    /**
     * Legacy positional constructor — `getWhere()` is empty.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexGetWhereEmptyByDefault(): void
    {
        $index = new Index('idx_email', ['email']);

        $this->assertSame('', $index->getWhere());
    }

    /**
     * Definition-array `where` is stored verbatim.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexGetWhereStored(): void
    {
        $index = new Index(
            'idx_active',
            [
                'columns' => ['email'],
                'where'   => 'active = true',
            ]
        );

        $this->assertSame('active = true', $index->getWhere());
    }

    /**
     * Non-string `where` throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexWhereMustBeString(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Index definition 'where' key must be a string"
        );

        new Index(
            'idx_bad',
            [
                'columns' => ['email'],
                'where'   => ['not_a_string'],
            ]
        );
    }
}
