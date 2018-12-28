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
 * Class EscapeUrlCest
 */
class EscapeUrlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeUrl()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperEscapeUrl(UnitTester $I)
    {
        $I->wantToTest("Escaper - escapeUrl()");
        $escaper = new Escaper();

        $expected = 'http%3A%2F%2Fphalconphp.com%2Fa.php%3Fc%3Dd%26e%3Df';
        $actual   = $escaper->escapeUrl("http://phalconphp.com/a.php?c=d&e=f");
        $I->assertEquals($expected, $actual);
    }
}
