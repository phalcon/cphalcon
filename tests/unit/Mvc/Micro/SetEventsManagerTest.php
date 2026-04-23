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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\Di;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;

class SetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroSetEventsManager(): void
    {
        $di      = new Di();
        $micro   = new Micro($di);
        $manager = new EventsManager();
        $micro->setEventsManager($manager);
        $this->assertSame($manager, $micro->getEventsManager());
    }
}
