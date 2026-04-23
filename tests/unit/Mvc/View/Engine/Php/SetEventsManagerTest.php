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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Php;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Tests\AbstractUnitTestCase;

class SetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEnginePhpSetEventsManager(): void
    {
        $view    = new View();
        $engine  = new PhpEngine($view);
        $manager = new EventsManager();

        $engine->setEventsManager($manager);

        $this->assertSame($manager, $engine->getEventsManager());
    }
}
