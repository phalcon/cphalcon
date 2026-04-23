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

namespace Phalcon\Tests\Unit\Mvc\Url;

use Phalcon\Di\Di;
use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcUrlGetSetDI(): void
    {
        $url       = new Url();
        $container = new Di();

        $url->setDI($container);

        $actual = $url->getDI();

        $this->assertInstanceOf(
            Di::class,
            $actual
        );

        $this->assertEquals($container, $actual);
    }
}
