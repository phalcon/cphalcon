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
 * Class SetModelNameCest
 */
class SetModelNameCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: setModelName()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaSetModelName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - setModelName()');
        $I->skipTest('Need implementation');
    }
}
