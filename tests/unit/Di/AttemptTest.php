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
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class AttemptTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiAttempt(): void
    {
        $container = new Di();

        $actual = $container->attempt('escaper', Escaper::class);
        $this->assertInstanceOf(Service::class, $actual);

        $actual = $container->attempt('escaper', Escaper::class);
        $this->assertFalse($actual);
    }
}
