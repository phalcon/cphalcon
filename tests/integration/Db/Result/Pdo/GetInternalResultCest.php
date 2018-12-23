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

namespace Phalcon\Test\Integration\Db\Result\Pdo;

use IntegrationTester;

/**
 * Class GetInternalResultCest
 */
class GetInternalResultCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: getInternalResult()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbResultPdoGetInternalResult(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - getInternalResult()');
        $I->skipTest('Need implementation');
    }
}
