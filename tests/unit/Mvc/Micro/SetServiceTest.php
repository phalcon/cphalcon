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
use Phalcon\Http\Request;
use Phalcon\Mvc\Micro;
use Phalcon\Tests\AbstractUnitTestCase;

class SetServiceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroSetService(): void
    {
        $di    = new Di();
        $micro = new Micro($di);
        $micro->setService('myService', function () {
            return new Request();
        });
        $this->assertInstanceOf(Request::class, $micro->getService('myService'));
    }
}
