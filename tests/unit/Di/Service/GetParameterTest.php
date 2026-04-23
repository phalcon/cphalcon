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

namespace Phalcon\Tests\Unit\Di\Service;

use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetParameterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceGetParameterEmpty(): void
    {
        $service = new Service(
            [
                'className' => Escaper::class,
                'arguments' => [],
            ],
            false
        );

        $actual = $service->getParameter(1);
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiServiceGetParameterInPosition(): void
    {
        $service = new Service(
            [
                'className' => Escaper::class,
                'arguments' => [
                    0 => 1,
                    1 => 'two',
                ],
            ]
        );

        $expected = 1;
        $actual   = $service->getParameter(0);
        $this->assertSame($expected, $actual);

        $expected = 'two';
        $actual   = $service->getParameter(1);
        $this->assertSame($expected, $actual);

        $actual = $service->getParameter(2);
        $this->assertNull($actual);
    }
}
