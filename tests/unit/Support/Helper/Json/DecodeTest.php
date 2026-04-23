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

namespace Phalcon\Tests\Unit\Support\Helper\Json;

use InvalidArgumentException;
use Phalcon\Support\Helper\Json\Decode;
use Phalcon\Tests\AbstractUnitTestCase;

final class DecodeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperJsonDecode(): void
    {
        $object = new Decode();
        $data = '{"one":"two","0":"three"}';
        $expected = [
            'one' => 'two',
            'three',
        ];
        $actual = $object($data, true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperJsonDecodeException(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            "Control character error, " .
            "possibly incorrectly encoded",
        );
        $this->expectExceptionCode(3);

        $data = '{"one';
        (new Decode())($data);
    }
}
