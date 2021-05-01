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

namespace Phalcon\Test\Unit\Support\HelperFactory;

use Phalcon\Support\HelperFactory;
use Phalcon\Support\Helper\Str\Interpolate;
use UnitTester;

class CallCest
{
    /**
     * Tests Phalcon\Support :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperFactoryCall(UnitTester $I)
    {
        $I->wantToTest('Support\HelperFactory - __call()');

        $factory = new HelperFactory();

        $format   = '%date% is the date %level% is the level';
        $expected = '2020-09-09 is the date CRITICAL is the level';
        $context  = [
            'date' => '2020-09-09',
            'level' => 'CRITICAL'
        ];
        $actual   = $factory->interpolate($format, $context);
        $I->assertEquals($expected, $actual);
    }
}
