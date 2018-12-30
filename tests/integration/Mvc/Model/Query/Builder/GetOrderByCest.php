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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;

/**
 * Class GetOrderByCest
 */
class GetOrderByCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: getOrderBy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderGetOrderBy(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getOrderBy()');
        $I->skipTest('Need implementation');
    }
}
