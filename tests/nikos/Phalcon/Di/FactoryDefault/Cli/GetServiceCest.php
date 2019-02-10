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
 * Class GetServiceCest
 */
class GetServiceCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getService()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function diFactoryDefaultCliGetService(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getService()');
        $I->skipTest('Need implementation');
    }
}
