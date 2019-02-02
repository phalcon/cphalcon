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
 * Class BindCest
 */
class BindCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: bind()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaBind(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - bind()');
        $I->skipTest('Need implementation');
    }
}
