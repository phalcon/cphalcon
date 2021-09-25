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

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class GetSnapshotDataCest
 */
class GetSnapshotDataCest
{
    /**
     * Tests Phalcon\Mvc\Model :: getSnapshotData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelGetSnapshotData(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - getSnapshotData()');
        $I->skipTest('Need implementation');
    }
}
