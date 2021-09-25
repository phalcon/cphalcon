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

class AttachCest
{
    /**
     * Tests Phalcon\Events\Manager :: attach()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsManagerAttach(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - attach()');

        $I->skipTest('Need implementation');
    }
}
