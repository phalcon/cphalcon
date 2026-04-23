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

namespace Phalcon\Tests\Unit\Mvc\Controller;

use Phalcon\Http\Request;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Controllers\ViewRequestController;
use Phalcon\Tests\Support\Traits\DiTrait;

class UnderscoreGetTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcControllerUnderscoreGet(): void
    {
        $di = $this->newService('factoryDefault');

        $controller = new ViewRequestController();
        $controller->setDI($di);

        $this->assertInstanceOf(Request::class, $controller->request);
    }
}
