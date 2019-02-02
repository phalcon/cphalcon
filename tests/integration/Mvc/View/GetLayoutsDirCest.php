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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;

/**
 * Class GetLayoutsDirCest
 */
class GetLayoutsDirCest
{
    /**
     * Tests Phalcon\Mvc\View :: getLayoutsDir()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewGetLayoutsDir(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getLayoutsDir()');
        $I->skipTest('Need implementation');
    }
}
