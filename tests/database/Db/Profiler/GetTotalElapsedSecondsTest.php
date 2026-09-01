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
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetTotalElapsedSecondsTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Profiler :: getTotalElapsedSeconds()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbProfilerGetTotalElapsedSeconds(): void
    {
        $profiler = new Profiler();

        $profiler->startProfile('SELECT * FROM robots');
        $profiler->stopProfile();

        $elapsed = $profiler->getTotalElapsedSeconds();

        $this->assertIsFloat($elapsed);
        $this->assertGreaterThan(0, $elapsed);
    }
}
