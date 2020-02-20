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

use Phalcon\Events\Manager;
use UnitTester;

class GetEventOptionsCest
{
    /**
     * Tests Phalcon\Events\Manager :: getEventOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsManagerGetEventOptions(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - getEventOptions()');

        $I->skipTest('Need implementation');
    }
}
