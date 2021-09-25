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

class DecodeCest
{
    /**
     * Tests Phalcon\Helper\Json :: decode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function helperJsonDecode(UnitTester $I)
    {
        $I->wantToTest('Helper\Json - decode()');

        $data     = '{"one":"two","0":"three"}';
        $expected = [
            'one' => 'two',
            'three',
        ];
        $actual   = Json::decode($data, true);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Json :: decode() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function helperJsonDecodeException(UnitTester $I)
    {
        $I->wantToTest('Helper\Json - decode() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                "json_decode error: Control character error, " .
                "possibly incorrectly encoded"
            ),
            function () {
                $data   = '{"one';
                $actual = Json::decode($data);
            }
        );
    }
}
