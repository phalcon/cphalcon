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

class ArePrioritiesEnabledCest
{
    /**
     * Tests Phalcon\Events\Manager :: arePrioritiesEnabled()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-20
     */
    public function eventsManagerArePrioritiesEnabled(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - arePrioritiesEnabled()');

        $manager = new Manager();

        $I->assertFalse(
            $manager->arePrioritiesEnabled()
        );

        $manager->enablePriorities(true);

        $I->assertTrue(
            $manager->arePrioritiesEnabled()
        );

        $manager->enablePriorities(false);

        $I->assertFalse(
            $manager->arePrioritiesEnabled()
        );
    }
}
