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

use Phalcon\Di\Di;
use Phalcon\Http\Request;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Tests\AbstractUnitTestCase;

class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEnginePhpUnderscoreGet(): void
    {
        $di      = new Di();
        $request = new Request();
        $di->setShared('request', $request);

        $view   = new View();
        $engine = new PhpEngine($view, $di);

        $this->assertInstanceOf(Request::class, $engine->request);
    }
}
