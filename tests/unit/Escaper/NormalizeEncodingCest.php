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

namespace Phalcon\Tests\Unit\Escaper;

use Phalcon\Escaper;
use UnitTester;

class NormalizeEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: normalizeEncoding()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-16
     */
    public function escaperNormalizeEncoding(UnitTester $I)
    {
        $I->wantToTest('Escaper - normalizeEncoding()');

        $I->checkExtensionIsLoaded('mbstring');

        $escaper = new Escaper();

        $I->assertEquals(
            mb_convert_encoding('Hello', 'UTF-32', 'UTF-8'),
            $escaper->normalizeEncoding('Hello')
        );
    }
}
