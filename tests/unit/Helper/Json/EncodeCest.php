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

namespace Phalcon\Tests\Unit\Helper\Json;

use InvalidArgumentException;
use Phalcon\Helper\Json;
use UnitTester;

class EncodeCest
{
    /**
     * Tests Phalcon\Helper\Json :: encode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function helperJsonEncode(UnitTester $I)
    {
        $I->wantToTest('Helper\Json - encode()');

        $data     = [
            'one' => 'two',
            'three',
        ];
        $expected = '{"one":"two","0":"three"}';
        $actual   = Json::encode($data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Json :: encode() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function helperJsonEncodeException(UnitTester $I)
    {
        $I->wantToTest('Helper\Json - encode() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                "json_encode error: Malformed UTF-8 characters, " .
                "possibly incorrectly encoded"
            ),
            function () {
                $data   = pack("H*", 'c32e');
                $actual = Json::encode($data);
            }
        );
    }
}
