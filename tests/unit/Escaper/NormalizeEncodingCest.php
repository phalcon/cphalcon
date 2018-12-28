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
 * Class NormalizeEncodingCest
 */
class NormalizeEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: normalizeEncoding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperNormalizeEncoding(UnitTester $I)
    {
        $I->wantToTest("Escaper - normalizeEncoding()");
        $I->checkExtensionIsLoaded('mbstring');

        $escaper = new Escaper();

        $expected = mb_convert_encoding('Hello', 'UTF-32', 'UTF-8');
        $actual   = $escaper->normalizeEncoding('Hello');

        $I->assertEquals($expected, $actual);
    }
}
