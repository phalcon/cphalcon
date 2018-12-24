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

namespace Phalcon\Test\Unit\Di\Service;

use UnitTester;

/**
 * Class SetSharedInstanceCest
 */
class SetSharedInstanceCest
{
    /**
     * Tests Phalcon\Di\Service :: setSharedInstance()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceSetSharedInstance(UnitTester $I)
    {
        $I->wantToTest('Di\Service - setSharedInstance()');
        $I->skipTest('Need implementation');
    }
}
