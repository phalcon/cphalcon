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

namespace Phalcon\Tests\Unit\Events\Manager;

use UnitTester;

class CollectResponsesCest
{
    /**
     * Tests Phalcon\Events\Manager :: collectResponses()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function eventsManagerCollectResponses(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - collectResponses()');

        $I->skipTest('Need implementation');
    }
}
