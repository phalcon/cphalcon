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

namespace Phalcon\Test\Unit\Events\Manager;

use UnitTester;

class GetResponsesCest
{
    /**
     * Tests Phalcon\Events\Manager :: getResponses()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsManagerGetResponses(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - getResponses()');

        $I->skipTest('Need implementation');
    }
}
