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

use Phalcon\Events\Exception;
use Phalcon\Events\Manager;
use Phalcon\Tests\Fixtures\Events\ComponentOne;
use Phalcon\Tests\Fixtures\Listener\OneListener;
use Phalcon\Tests\Fixtures\Listener\TwoListener;
use UnitTester;

class AttachCest
{
    /**
     * Tests Phalcon\Events\Manager :: attach() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsManagerAttachException(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - attach() - exception');

        $I->expectThrowable(
            new Exception('Event handler must be an Object or Callable'),
            function () {
                $manager = new Manager();
                $manager->attach('test:detachable', false);
            }
        );
    }

    /**
     * Tests Phalcon\Events\Manager :: attach() - by name after detatch all
     *
     * @param UnitTester $I
     *
     * @author @author Kamil Skowron <kamil@hedonsoftware.com>
     * @since  2020-09-09
     */
    public function eventsManagerAttachByNameAfterDetatchAll(UnitTester $I)
    {
        $first         = new OneListener();
        $second        = new TwoListener();
        $component     = new ComponentOne();
        $eventsManager = new Manager();

        $component->setEventsManager($eventsManager);

        $eventsManager->attach('log', $first);
        $logListeners = $component->getEventsManager()
                                  ->getListeners('log');
        $I->assertCount(1, $logListeners);

        $expected = OneListener::class;
        $actual   = $logListeners[0];
        $I->assertInstanceOf($expected, $actual);

        $component->getEventsManager()
                  ->attach('log', $second)
        ;
        $logListeners = $component->getEventsManager()
                                  ->getListeners('log');
        $I->assertCount(2, $logListeners);

        $expected = OneListener::class;
        $actual   = $logListeners[0];
        $I->assertInstanceOf($expected, $actual);

        $expected = TwoListener::class;
        $actual   = $logListeners[1];
        $I->assertInstanceOf($expected, $actual);

        $component->getEventsManager()
                  ->detachAll('log')
        ;
        $logListeners = $component->getEventsManager()
                                  ->getListeners('log');
        $I->assertEmpty($logListeners);

        $component->getEventsManager()
                  ->attach('log', $second)
        ;
        $logListeners = $component->getEventsManager()
                                  ->getListeners('log');
        $I->assertCount(1, $logListeners);

        $expected = TwoListener::class;
        $actual   = $logListeners[0];
        $I->assertInstanceOf($expected, $actual);
    }
}
