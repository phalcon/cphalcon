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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;

/**
 * Class HeadCest
 */
class HeadCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: head()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionHead(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - head()');
        $I->skipTest('Need implementation');
    }
}
