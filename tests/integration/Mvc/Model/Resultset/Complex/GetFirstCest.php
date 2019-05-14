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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Complex;

use IntegrationTester;

/**
 * Class GetFirstCest
 */
class GetFirstCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Complex :: getFirst()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetComplexGetFirst(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Complex - getFirst()');
        $I->skipTest('Need implementation');
    }
}
