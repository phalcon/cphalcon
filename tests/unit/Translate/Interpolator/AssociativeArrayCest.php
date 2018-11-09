<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Interpolator;

use Phalcon\Translate\Interpolator\AssociativeArray;
use UnitTester;

class AssociativeArrayCest
{
    public function testIndexedArrayInterpolator(UnitTester $I)
    {
        $interpolator = new AssociativeArray();

        $expected = 'Hello, John D. Doe!';

        $stringFrom = 'Hello, %fname% %mname% %lname%!';
        $actual     = $interpolator->replacePlaceholders(
            $stringFrom,
            [
                'fname' => 'John',
                'lname' => 'Doe',
                'mname' => 'D.',
            ]
        );

        $I->assertEquals($expected, $actual);
    }
}
