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

class GetSetEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: getEncoding() / setEncoding()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-16
     */
    public function escaperGetSetEncoding(UnitTester $I)
    {
        $I->wantToTest('Escaper - getEncoding() / setEncoding()');

        $escaper = new Escaper();

        $escaper->setEncoding('UTF-8');

        $expected = 'UTF-8';
        $actual   = $escaper->getEncoding();
        $I->assertEquals($expected, $actual);
    }
}
