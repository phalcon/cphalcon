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

namespace Phalcon\Test\Unit\Di\FactoryDefault\Cli;

use UnitTester;

/**
 * Class GetSharedCest
 */
class GetSharedCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getShared()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetShared(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getShared()');
        $I->skipTest('Need implementation');
    }
}
