<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\FactoryDefault\Cli;

use UnitTester;

class GetDefaultCest
{
    /**
     * Unit Tests Phalcon\Di\FactoryDefault\Cli :: getDefault()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diFactoryDefaultCliGetDefault(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getDefault()');

        $I->skipTest('Need implementation');
    }
}
