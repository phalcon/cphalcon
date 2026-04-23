<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Events;

use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Events\Fake\ComponentFireManager;
use Phalcon\Tests\Unit\Events\Fake\ComponentWithEvents;

use function method_exists;

final class ComponentManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsComponentManager(): void
    {
        $manager   = new Manager();
        $component = new ComponentWithEvents();

        $actual = method_exists($component, 'getEventsManager');
        $this->assertTrue($actual);
        $actual = method_exists($component, 'setEventsManager');
        $this->assertTrue($actual);

        $component->setEventsManager($manager);
        $actual = $component->getEventsManager();
        $this->assertSame($manager, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testEventsAwareTraitFireManagerEventWithManager(): void
    {
        $called    = false;
        $manager   = new Manager();
        $component = new ComponentFireManager();
        $component->setEventsManager($manager);

        $manager->attach(
            'test:action',
            function () use (&$called) {
                $called = true;

                return 'fired';
            }
        );

        $result = $component->callFireManagerEvent('test:action');
        $this->assertTrue($called);
        $this->assertSame('fired', $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testEventsAwareTraitFireManagerEventNoManagerReturnsTrue(): void
    {
        $component = new ComponentFireManager();

        $result = $component->callFireManagerEvent('test:action');
        $this->assertTrue($result);
    }
}
