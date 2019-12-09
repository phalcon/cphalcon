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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class SetOldSnapshotDataCest
 */
class SetOldSnapshotDataCest
{
    /**
     * Tests Phalcon\Mvc\Model :: setOldSnapshotData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelSetOldSnapshotData(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - setOldSnapshotData()');
        $I->skipTest('Need implementation');
    }
}
