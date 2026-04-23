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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Di\Di;
use Phalcon\Flash\Direct;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetSetDI(): void
    {
        $container = new Di();
        $flash     = new Direct();
        $flash->setDI($container);

        $actual = $flash->getDI();
        $this->assertSame($container, $actual);
        $this->assertInstanceOf(Di::class, $actual);
    }
}
