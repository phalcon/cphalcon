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
 * Class NormalizeEncodingCest
 *
 * @package Phalcon\Tests\Unit\Html\Escaper
 */
class NormalizeEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: normalizeEncoding()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function escaperNormalizeEncoding(UnitTester $I)
    {
        $I->wantToTest('Escaper - normalizeEncoding()');

        $I->checkExtensionIsLoaded('mbstring');

        $escaper = new Escaper();

        $expected = mb_convert_encoding('Hello', 'UTF-32', 'UTF-8');
        $actual   = $escaper->normalizeEncoding('Hello');
        $I->assertEquals($expected, $actual);
    }
}
