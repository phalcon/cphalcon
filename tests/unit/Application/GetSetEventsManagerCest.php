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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Application\ApplicationFixture;
use UnitTester;

use function spl_object_hash;

/**
 * Class GetSetEventsManagerCest
 *
 * @package Phalcon\Tests\Unit\Application
 */
class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Application\* :: getEventsManager()/setEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function applicationGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Application - getEventsManager()/setEventsManager()');

        $manager     = new Manager();
        $application = new ApplicationFixture();

        $actual = $application->getEventsManager();
        $I->assertNull($actual);

        $application->setEventsManager($manager);
        $actual = $application->getEventsManager();
        $I->assertEquals(spl_object_hash($manager), spl_object_hash($actual));
    }
}
