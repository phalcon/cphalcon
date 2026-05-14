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

use const JSON_THROW_ON_ERROR;

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
            "json_decode error: Control character error, " .
            "possibly incorrectly encoded",
        );
        $this->expectExceptionCode(3);

        $data = '{"one';
        (new Decode())($data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-14
     */
    public function testSupportHelperJsonDecodeExceptionWithThrowOnError(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            "json_decode error: Control character error, " .
            "possibly incorrectly encoded",
        );
        $this->expectExceptionCode(3);

        $data = '{"one';
        (new Decode())($data, false, 512, JSON_THROW_ON_ERROR);
    }
}
