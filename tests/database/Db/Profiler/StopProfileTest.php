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
final class StopProfileTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Profiler :: stopProfile()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbProfilerStopProfile(): void
    {
        $profiler = new Profiler();

        $profiler->startProfile('SELECT * FROM robots');
        $returned = $profiler->stopProfile();

        $this->assertSame($profiler, $returned);
        $this->assertSame(1, $profiler->getNumberTotalStatements());

        $profile = $profiler->getLastProfile();

        $this->assertInstanceOf(Item::class, $profile);
        $this->assertGreaterThan(0, $profile->getFinalTime());
    }
}
