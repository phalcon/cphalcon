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

namespace Phalcon\Test\Unit\Validation\Validator\Exception;

use UnitTester;

/**
 * Class WakeupCest
 */
class WakeupCest
{
    /**
     * Tests Phalcon\Validation\Validator\Exception :: __wakeup()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function validationValidatorExceptionWakeup(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\Exception - __wakeup()');
        $I->skipTest('Need implementation');
    }
}
