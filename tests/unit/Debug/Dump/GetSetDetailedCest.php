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

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use UnitTester;

/**
 * Class GetSetDetailedCest
 */
class GetSetDetailedCest
{
    /**
     * Tests Phalcon\Debug\Dump :: getDetailed()/setDetailed()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpGetSetDetailed(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - getDetailed()/setDetailed()');
        $dump = new Dump([], false);

        $actual = $dump->getDetailed();
        $I->assertFalse($actual);

        $dump->setDetailed(true);
        $actual = $dump->getDetailed();
        $I->assertTrue($actual);
    }
}
