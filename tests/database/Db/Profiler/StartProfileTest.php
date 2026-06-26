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

namespace Phalcon\Tests\Database\Db\Profiler;

use Phalcon\Db\Profiler;
use Phalcon\Db\Profiler\Item;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class StartProfileTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Profiler :: startProfile()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbProfilerStartProfile(): void
    {
        $profiler = new Profiler();

        $returned = $profiler->startProfile(
            'SELECT * FROM robots WHERE id = ?',
            [1],
            [1]
        );

        $this->assertSame($profiler, $returned);

        $profile = $profiler->getLastProfile();

        $this->assertInstanceOf(Item::class, $profile);
        $this->assertSame(
            'SELECT * FROM robots WHERE id = ?',
            $profile->getSqlStatement()
        );
        $this->assertSame([1], $profile->getSqlVariables());
        $this->assertSame([1], $profile->getSqlBindTypes());
    }
}
