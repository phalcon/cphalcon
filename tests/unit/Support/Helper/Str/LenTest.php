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

use Phalcon\Support\Helper\Str\Len;
use Phalcon\Tests\AbstractUnitTestCase;

final class LenTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrLen(): void
    {
        $object = new Len();
        $actual = $object('hello');
        $this->assertSame(5, $actual);

        $actual = $object('1234');
        $this->assertSame(4, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrLenMultiBytesEncoding(): void
    {
        $object = new Len();
        $actual = $object('привет мир!');
        $this->assertSame(11, $actual);

        $actual = $object('männer');
        $this->assertSame(6, $actual);
    }
}
