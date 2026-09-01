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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Listener\OneListener;
use Phalcon\Tests\Support\Listener\ThreeListener;
use Phalcon\Tests\Support\Listener\TwoListener;
use Phalcon\Tests\Unit\Events\Fake\ComponentOne;
use stdClass;

final class FireTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerFire(): void
    {
        $manager = new Manager();
        $one     = new OneListener();
        $two     = new TwoListener();
        $three   = new ThreeListener();

        $manager->enablePriorities(false);
        $manager->collectResponses(true);

        $manager->attach('ab', $three, 10);
        $manager->attach('ab', $two, 20);
        $manager->attach('ab:beforeAction', $one, 30);

        $component = new ComponentOne();
        $component->setEventsManager($manager);

        $component->doAction();

        $expected = ['three', 'two', 'one'];
        $actual   = $component->getEventsManager()
                              ->getResponses()
        ;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerFireException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Invalid event type unknown');

        $manager = new Manager();
        $manager->attach(
            'someEvent',
            function () {
                return true;
            }
        );

        $manager->fire('unknown', new stdClass());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerFireNoEvents(): void
    {
        $manager = new Manager();
        $actual  = $manager->fire('someEvent', new stdClass());
        $this->assertNull($actual);
    }

    /**
     * The fifth fire() argument overrides setStopOnFalse() for one call:
     * `true` makes a listener's `false` final, `false` keeps last-wins.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testEventsManagerFireStopOnFalsePerCall(): void
    {
        $manager = new Manager();
        $source  = new stdClass();

        $manager->attach('auth:check', function () {
            return false;
        });
        $manager->attach('auth:check', function () {
            return true;
        });

        // Manager default: last non-null wins.
        $this->assertTrue($manager->fire('auth:check', $source));
        // Per-call stop-on-false: the denial is final.
        $this->assertFalse($manager->fire('auth:check', $source, null, true, true));

        // The override works both ways.
        $manager->setStopOnFalse(true);
        $this->assertFalse($manager->fire('auth:check', $source));
        $this->assertTrue($manager->fire('auth:check', $source, null, true, false));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerFireWithPriorities(): void
    {
        $manager = new Manager();
        $one     = new OneListener();
        $two     = new TwoListener();
        $three   = new ThreeListener();

        $manager->enablePriorities(true);
        $manager->collectResponses(true);

        $manager->attach('ab', $three, 10);
        $manager->attach('ab', $two, 20);
        $manager->attach('ab', $one, 30);

        $component = new ComponentOne();
        $component->setEventsManager($manager);

        $component->doAction();

        $expected = ['one', 'two', 'three'];
        $actual   = $component->getEventsManager()
                              ->getResponses()
        ;
        $this->assertSame($expected, $actual);
    }
}
