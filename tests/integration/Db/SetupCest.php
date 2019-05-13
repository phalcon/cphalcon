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

namespace Phalcon\Test\Integration\Db;

use IntegrationTester;

/**
 * Class SetupCest
 */
class SetupCest
{
    /**
     * Tests Phalcon\Db :: setup()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbSetup(IntegrationTester $I)
    {
        $I->wantToTest('Db - setup()');
        $I->skipTest('Need implementation');
    }
}
