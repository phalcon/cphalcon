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

namespace Phalcon\Test\Unit\Events\Provider;

use UnitTester;

class GetListenerCest
{
    /**
     * Tests Phalcon\Events\Provider :: getListener()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function eventsProviderGetListener(UnitTester $I)
    {
        $I->wantToTest('Events\Provider - getListener()');

        $I->skipTest('Need implementation');
    }
}
