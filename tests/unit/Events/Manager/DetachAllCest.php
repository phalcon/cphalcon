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

class DetachAllCest
{
    /**
     * Tests Phalcon\Events\Manager :: detachAll()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsManagerDetachAll(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - detachAll()');

        $eventType = 'some:upload';
        $manager   = new Manager();
        $manager->attach(
            $eventType,
            function () {
                return true;
            }
        );

        $actual = $manager->getListeners($eventType);
        $I->assertCount(1, $actual);

        $manager->detachAll();

        $actual = $manager->hasListeners($eventType);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Events\Manager :: detachAll() - with type
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsManagerDetachAllWithType(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - detachAll() - with type');

        $uploadType   = 'some:upload';
        $downloadType = 'some:download';
        $manager      = new Manager();
        $manager->attach(
            $uploadType,
            function () {
                return true;
            }
        );

        $manager->attach(
            $downloadType,
            function () {
                return true;
            }
        );

        $actual = $manager->hasListeners($uploadType);
        $I->assertTrue($actual);
        $actual = $manager->hasListeners($downloadType);
        $I->assertTrue($actual);

        $manager->detachAll($uploadType);

        $actual = $manager->hasListeners($uploadType);
        $I->assertFalse($actual);
        $actual = $manager->hasListeners($downloadType);
        $I->assertTrue($actual);
    }
}
