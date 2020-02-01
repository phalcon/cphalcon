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

namespace Phalcon\Test\Database\Mvc\Model\Criteria;

use DatabaseTester;

/**
 * Class FromInputCest
 */
class FromInputCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelCriteriaFromInput(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - fromInput()');
        $I->skipTest('Need implementation');
    }
}
