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

namespace Phalcon\Test\Unit\Service\Locator;

use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Service\Locator :: set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function serviceLocatorSet(UnitTester $I)
    {
        $I->wantToTest('Service\Locator - set()');

        $I->skipTest('Need implementation');
    }
}
