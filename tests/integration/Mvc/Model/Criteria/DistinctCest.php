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
 * Class DistinctCest
 */
class DistinctCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: distinct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaDistinct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - distinct()');
        $I->skipTest('Need implementation');
    }
}
