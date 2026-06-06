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

namespace Phalcon\Tests\Unit\Mvc\Router\Annotations;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsGetEventsManager(): void
    {
        $router  = new Annotations(false);
        $manager = new EventsManager();

        $router->setEventsManager($manager);

        $this->assertSame($manager, $router->getEventsManager());
    }
}
