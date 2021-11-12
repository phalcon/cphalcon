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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use UnitTester;

/**
 * Class GetSetDetailedCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class GetSetDetailedCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: getDetailed()/setDetailed()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpGetSetDetailed(UnitTester $I)
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
