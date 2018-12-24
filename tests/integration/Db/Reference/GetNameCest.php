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

namespace Phalcon\Test\Integration\Db\Reference;

use IntegrationTester;

/**
 * Class GetNameCest
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Db\Reference :: getName()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbReferenceGetName(IntegrationTester $I)
    {
        $I->wantToTest('Db\Reference - getName()');
        $I->skipTest('Need implementation');
    }
}
