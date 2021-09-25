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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsManagerIsCollecting(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - isCollecting()');

        $manager = new Manager();

        $I->assertFalse(
            $manager->isCollecting()
        );

        $manager->collectResponses(true);

        $I->assertTrue(
            $manager->isCollecting()
        );

        $manager->collectResponses(false);

        $I->assertFalse(
            $manager->isCollecting()
        );
    }
}
