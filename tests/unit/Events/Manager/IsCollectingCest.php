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

namespace Phalcon\Tests\Unit\Events\Manager;

use Phalcon\Events\Manager;
use UnitTester;

class IsCollectingCest
{
    /**
     * Tests Phalcon\Events\Manager :: isCollecting()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsManagerIsCollecting(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - isCollecting()');

        $manager = new Manager();

        $actual = $manager->isCollecting();
        $I->assertFalse($actual);

        $manager->collectResponses(true);
        $actual = $manager->isCollecting();
        $I->assertTrue($actual);

        $manager->collectResponses(false);
        $actual = $manager->isCollecting();
        $I->assertFalse($actual);
    }
}
