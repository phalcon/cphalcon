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

namespace Phalcon\Test\Integration\Mvc\Model\Criteria;

use IntegrationTester;

/**
 * Class LeftJoinCest
 */
class LeftJoinCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: leftJoin()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaLeftJoin(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - leftJoin()');
        $I->skipTest('Need implementation');
    }
}
