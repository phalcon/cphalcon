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
use Phalcon\Html\Escaper;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Router;
use Phalcon\Tests\AbstractUnitTestCase;

class OffsetExistsTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcMicroOffsetExists(): void
    {
        $micro = new Micro();
        $di    = new Di();
        $micro->setDi($di);


        $this->assertFalse(
            isset($micro['fake'])
        );

        $this->assertFalse(
            isset($micro['escaper'])
        );

        $this->assertFalse(
            isset($micro['dispatcher'])
        );


        $escaper = new Escaper();
        $micro->setService('escaper', $escaper);

        $this->assertTrue(
            isset($micro['escaper'])
        );

        $dispatcher          = new Dispatcher();
        $micro['dispatcher'] = $dispatcher;

        $this->assertTrue(
            isset($micro['dispatcher'])
        );

        $router = new Router();
        $di->set('router', $router);

        $this->assertTrue(
            isset($micro['router'])
        );
    }
}
