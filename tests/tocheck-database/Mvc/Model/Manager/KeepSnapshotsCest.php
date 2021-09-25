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

namespace Phalcon\Tests\Integration\Mvc\Model\Manager;

use IntegrationTester;

/**
 * Class KeepSnapshotsCest
 */
class KeepSnapshotsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: keepSnapshots()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerKeepSnapshots(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - keepSnapshots()');
        $I->skipTest('Need implementation');
    }
}
