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

namespace Phalcon\Tests\Integration\Db\Reference;

use IntegrationTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Db\Reference :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbReferenceConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - __construct()');
        $I->skipTest('Need implementation');
    }
}
