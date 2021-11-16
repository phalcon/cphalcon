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

namespace Phalcon\Tests\Unit\Html\Escaper;

use Phalcon\Html\Escaper;
use UnitTester;

/**
 * Class SetDoubleEncodeCest
 *
 * @package Phalcon\Tests\Unit\Html\Escaper
 */
class SetDoubleEncodeCest
{
    /**
     * Tests Phalcon\Escaper :: setDoubleEncode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function escaperSetDoubleEncode(UnitTester $I)
    {
        $I->wantToTest('Escaper - setDoubleEncode()');

        $escaper = new Escaper();

        $source = '<h1>&amp;</h1>';

        $expected = '&lt;h1&gt;&amp;amp;&lt;/h1&gt;';
        $actual   = $escaper->html($source);
        $I->assertEquals($expected, $actual);

        $escaper->setDoubleEncode(false);

        $expected = '&lt;h1&gt;&amp;&lt;/h1&gt;';
        $actual   = $escaper->html($source);
        $I->assertEquals($expected, $actual);
    }
}
