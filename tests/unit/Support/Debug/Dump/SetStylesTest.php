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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionException;

final class SetStylesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugDumpGetStyle(): void
    {
        $dump = new Dump(
            [],
            true,
        );

        $expected = 'color:gray';
        $actual = $this->callProtectedMethod($dump, 'getStyle', 'unknown');
        $this->assertSame($expected, $actual);

        $expected = 'color:blue';
        $actual = $this->callProtectedMethod($dump, 'getStyle', 'int');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugDumpSetStyles(): void
    {
        $dump = new Dump(
            [],
            true,
        );

        $expected = 'color:blue';
        $actual = $this->callProtectedMethod($dump, 'getStyle', 'int');
        $this->assertSame($expected, $actual);

        $dump->setStyles(
            [
                'int' => 'color:indigo',
            ],
        );

        $expected = 'color:indigo';
        $actual = $this->callProtectedMethod($dump, 'getStyle', 'int');
        $this->assertSame($expected, $actual);
    }
}
