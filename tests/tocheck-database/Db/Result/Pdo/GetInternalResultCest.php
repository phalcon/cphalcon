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

namespace Phalcon\Tests\Integration\Db\Result\Pdo;

use IntegrationTester;

class GetInternalResultCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: getInternalResult()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbResultPdoGetInternalResult(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - getInternalResult()');
        $I->skipTest('Need implementation');
    }
}
