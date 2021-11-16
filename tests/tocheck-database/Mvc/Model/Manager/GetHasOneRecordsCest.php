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
 * Class GetHasOneRecordsCest
 */
class GetHasOneRecordsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getHasOneRecords()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerGetHasOneRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getHasOneRecords()');
        $I->skipTest('Need implementation');
    }
}
