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

use Phalcon\Support\Helper\Str\Lower;
use Phalcon\Tests\AbstractUnitTestCase;

final class LowerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrLower(): void
    {
        $object = new Lower();

        $expected = 'hello';
        $actual = $object('hello');
        $this->assertSame($expected, $actual);

        $expected = 'hello';
        $actual = $object('HELLO');
        $this->assertSame($expected, $actual);

        $expected = '1234';
        $actual = $object('1234');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function testSupportHelperStrLowerMultiBytesEncoding(): void
    {
        $object = new Lower();

        $expected = 'привет мир!';
        $actual = $object('привет мир!');
        $this->assertSame($expected, $actual);

        $expected = 'привет мир!';
        $actual = $object('ПриВЕт Мир!');
        $this->assertSame($expected, $actual);

        $expected = 'привет мир!';
        $actual = $object('ПРИВЕТ МИР!');
        $this->assertSame($expected, $actual);


        $expected = 'männer';
        $actual = $object('männer');
        $this->assertSame($expected, $actual);

        $expected = 'männer';
        $actual = $object('mÄnnER');
        $this->assertSame($expected, $actual);

        $expected = 'männer';
        $actual = $object('MÄNNER');
        $this->assertSame($expected, $actual);
    }
}
