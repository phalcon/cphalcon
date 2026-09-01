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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

use function in_array;

/**
 * A `false` from a `dispatch:beforeExecuteRoute` listener is final: a later
 * listener returning `true` cannot re-open the route.
 */
final class BeforeExecuteRouteDenyTest extends BaseDispatcher
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcDispatcherBeforeExecuteRouteDenyIsFinal(): void
    {
        $dispatcher = $this->getDispatcher();
        $manager    = $dispatcher->getEventsManager();

        $manager->attach('dispatch:beforeExecuteRoute', function () {
            return false;
        });
        $manager->attach('dispatch:beforeExecuteRoute', function () {
            return true;
        });

        $dispatcher->dispatch();

        $trace = $this->getDispatcherListener()->getTrace();

        $this->assertTrue(in_array('beforeExecuteRoute', $trace, true));
        $this->assertFalse(in_array('beforeExecuteRoute-method', $trace, true));
        $this->assertFalse(in_array('indexAction', $trace, true));
    }
}
