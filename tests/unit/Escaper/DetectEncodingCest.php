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

namespace Phalcon\Test\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

/**
 * Class DetectEncodingCest
 */
class DetectEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: detectEncoding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperDetectEncoding(UnitTester $I)
    {
        $I->wantToTest("Escaper - detectEncoding()");
        $escaper = new Escaper();

        $source   = 'ḂḃĊċḊḋḞḟĠġṀṁ';
        $expected = 'UTF-8';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);


        $source   = chr(172) . chr(128) . chr(159) . 'ḂḃĊċḊḋḞḟĠġṀṁ';
        $expected = 'ISO-8859-1';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);

        $source   = '\0\0\0H\0\0\0i';
        $expected = 'UTF-8';
        $actual   = $escaper->detectEncoding($source);
        $I->assertEquals($expected, $actual);
    }
}
