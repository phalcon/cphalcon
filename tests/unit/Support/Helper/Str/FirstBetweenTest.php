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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\FirstBetween;
use Phalcon\Tests\AbstractUnitTestCase;

final class FirstBetweenTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrFirstBetween(): void
    {
        $object = new FirstBetween();
        $source = 'This is a [custom] string';
        $expected = 'custom';
        $actual = $object($source, '[', ']');
        $this->assertSame($expected, $actual);
    }
}
