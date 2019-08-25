<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcCollectionConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - __construct()');
        $I->skipTest('Need implementation');
    }
}
