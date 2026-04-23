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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

class GetSetEventsManagerTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltGetEventsManager(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('view');

        $view = $this->getService('view');

        $eventsManager = $this->newService('eventsManager');
        $engine        = new Volt($view, $this->container);

        $this->assertNull(
            $engine->getEventsManager()
        );

        $engine->setEventsManager($eventsManager);

        $this->assertSame(
            $eventsManager,
            $engine->getEventsManager()
        );
    }
}
