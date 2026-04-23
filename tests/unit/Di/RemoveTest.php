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

final class RemoveTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiRemove(): void
    {
        $container = new Di();

        $container->set('escaper', Escaper::class);

        $actual = $container->has('escaper');
        $this->assertTrue($actual);

        $container->remove('escaper');

        $actual = $container->has('escaper');
        $this->assertFalse($actual);
    }
}
