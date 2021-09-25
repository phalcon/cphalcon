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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;

/**
 * Class SharedLockCest
 */
class SharedLockCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: sharedLock()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaSharedLock(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - sharedLock()');

        $criteria = new Criteria();

        $expected = [];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);

        $criteria->sharedLock(true);

        $expected = [
            'shared_lock' => true,
        ];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);
    }
}
