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
use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Tests\AbstractUnitTestCase;

use const JSON_HEX_TAG;

final class EncodeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperJsonEncode(): void
    {
        $object = new Encode();
        $data = [
            'one' => 'two',
            'three',
        ];
        $expected = '{"one":"two","0":"three"}';
        $actual = $object($data);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperJsonEncodeExceptionDefaultOptions(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            "Malformed UTF-8 characters, possibly incorrectly encoded",
        );
        $data = pack("H*", 'c32e');
        (new Encode())($data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperJsonEncodeExceptionNoOptions(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage(
            "Malformed UTF-8 characters, possibly incorrectly encoded",
        );
        $data = pack("H*", 'c32e');
        (new Encode())($data, JSON_HEX_TAG);
    }
}
