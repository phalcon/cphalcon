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

namespace Phalcon\Test\Unit\Mvc\Model\Behavior;

use UnitTester;

class MissingMethodCest
{
    /**
     * Tests Phalcon\Mvc\Model\Behavior :: missingMethod()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcModelBehaviorMissingMethod(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Behavior - missingMethod()');

        $I->skipTest('Need implementation');
    }
}
