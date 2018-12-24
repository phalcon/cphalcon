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

namespace Phalcon\Test\Integration\Forms\Manager;

use IntegrationTester;

/**
 * Class CreateCest
 */
class CreateCest
{
    /**
     * Tests Phalcon\Forms\Manager :: create()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsManagerCreate(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Manager - create()');
        $I->skipTest('Need implementation');
    }
}
