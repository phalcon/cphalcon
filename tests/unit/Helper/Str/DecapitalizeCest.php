<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class DecapitalizeCest
 */
class DecapitalizeCest
{
    /**
     * Tests Phalcon\Helper\Str :: decapitalize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperStrDecapitalize(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decapitalize()');

        $source   = 'BeetleJuice';
        $expected = 'beetleJuice';
        $actual   = Str::decapitalize($source);
        $I->assertEquals($expected, $actual);

        $source   = 'BeetleJuice';
        $expected = 'bEETLEJUICE';
        $actual   = Str::decapitalize($source, true);
        $I->assertEquals($expected, $actual);
    }
}
