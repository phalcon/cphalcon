<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Db;

use IntegrationTester;

class SetupCest
{
    /**
     * Tests Phalcon\Db :: setup()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbSetup(IntegrationTester $I)
    {
        $I->wantToTest('Db - setup()');

        $I->skipTest('Need implementation');
    }
}
