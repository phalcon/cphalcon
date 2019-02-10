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

namespace Phalcon\Test\Unit\Image\Exception;

use UnitTester;

/**
 * Class WakeupCest
 */
class WakeupCest
{
    /**
     * Tests Phalcon\Image\Exception :: __wakeup()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function imageExceptionWakeup(UnitTester $I)
    {
        $I->wantToTest('Image\Exception - __wakeup()');
        $I->skipTest('Need implementation');
    }
}
