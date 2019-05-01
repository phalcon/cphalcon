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

class GetEncodingCest
{
    /**
     * Tests Phalcon\Escaper :: getEncoding()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-16
     */
    public function escaperGetEncoding(UnitTester $I)
    {
        $I->wantToTest("Escaper - getEncoding()");

        $escaper = new Escaper();

        $escaper->setEncoding('UTF-8');

        $I->assertEquals(
            'UTF-8',
            $escaper->getEncoding()
        );
    }
}
