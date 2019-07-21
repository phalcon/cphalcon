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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;

/**
 * Class UpdateCest
 */
class UpdateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: update()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - update()');
        $I->skipTest('Need implementation');
    }
}
