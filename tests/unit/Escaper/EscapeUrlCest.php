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

class EscapeUrlCest
{
    /**
     * Tests Phalcon\Escaper :: escapeUrl()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-16
     */
    public function escaperEscapeUrl(UnitTester $I)
    {
        $I->wantToTest('Escaper - escapeUrl()');

        $escaper = new Escaper();

        $I->assertEquals(
            'http%3A%2F%2Fphalcon.io%2Fa.php%3Fc%3Dd%26e%3Df',
            $escaper->escapeUrl('http://phalcon.io/a.php?c=d&e=f')
        );
    }
}
