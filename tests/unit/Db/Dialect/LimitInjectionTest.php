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

namespace Phalcon\Tests\Unit\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class LimitInjectionTest extends AbstractUnitTestCase
{
    /**
     * LIMIT/OFFSET must be cast to int so a request-derived pagination value
     * reaching this low-level API cannot inject SQL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testDbDialectLimitCastsToIntBlockingInjection(): void
    {
        $dialect = new Mysql();

        // Array elements are not type-constrained; a request-derived string
        // must be cast to int, not concatenated raw.
        $this->assertSame(
            'SELECT * FROM robots LIMIT 5 OFFSET 20',
            $dialect->limit(
                'SELECT * FROM robots',
                ['5 UNION SELECT password FROM users', '20; DROP TABLE users']
            )
        );

        // Valid integers are unchanged.
        $this->assertSame(
            'SELECT * FROM robots LIMIT 10 OFFSET 50',
            $dialect->limit('SELECT * FROM robots', [10, 50])
        );
    }
}
