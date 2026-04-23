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

namespace Phalcon\Tests\Unit\Mvc\Application;

use Phalcon\Di\Di;
use Phalcon\Http\Request;
use Phalcon\Mvc\Application;
use Phalcon\Tests\AbstractUnitTestCase;

class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcApplicationUnderscoreGet(): void
    {
        $container = new Di();
        $container->set('request', Request::class);

        $application = new Application($container);

        $this->assertInstanceOf(Request::class, $application->request);
    }
}
