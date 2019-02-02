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

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;

/**
 * Class SetPrefixCest
 */
class SetPrefixCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: setPrefix()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGroupSetPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - setPrefix()');
        $I->skipTest('Need implementation');
    }
}
