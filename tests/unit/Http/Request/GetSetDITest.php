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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Di\Di;
use Phalcon\Http\Request;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetDI(): void
    {
        $request   = new Request();
        $container = new Di();

        $request->setDI($container);

        $class  = Di::class;
        $actual = $request->getDI();
        $this->assertInstanceOf($class, $actual);

        $expected = $container;
        $this->assertSame($expected, $actual);
    }
}
