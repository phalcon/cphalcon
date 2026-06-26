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
final class GetProfilesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Profiler :: getProfiles()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbProfilerGetProfiles(): void
    {
        $profiler = new Profiler();

        $profiler->startProfile('SELECT * FROM robots');
        $profiler->stopProfile();

        $profiler->startProfile('SELECT * FROM robots WHERE id = 1');
        $profiler->stopProfile();

        $profiles = $profiler->getProfiles();

        $this->assertIsArray($profiles);
        $this->assertCount(2, $profiles);
        $this->assertInstanceOf(Item::class, $profiles[0]);
        $this->assertSame(
            'SELECT * FROM robots',
            $profiles[0]->getSqlStatement()
        );
        $this->assertSame(
            'SELECT * FROM robots WHERE id = 1',
            $profiles[1]->getSqlStatement()
        );
    }
}
