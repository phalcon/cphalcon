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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testUnderscoreCall(): void
    {
        $container = new Di();

        $actual = $container->setEscaper(Escaper::class);
        $this->assertNull($actual);

        $actual = $container->getEscaper();
        $this->assertInstanceOf(Escaper::class, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testUnderscoreCallUnknownMethod(): void
    {
        $container = new Di();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Call to undefined method or service 'notARealMethod'"
        );

        $container->notARealMethod();
    }
}
