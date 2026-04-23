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
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class OffsetUnsetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiOffsetUnset(): void
    {
        $container = new Di();
        $escaper   = new Escaper();

        $container->set('escaper', $escaper);

        $actual = $container->has('escaper');
        $this->assertTrue($actual);

        unset($container['escaper']);

        $actual = $container->has('escaper');
        $this->assertFalse($actual);
    }
}
