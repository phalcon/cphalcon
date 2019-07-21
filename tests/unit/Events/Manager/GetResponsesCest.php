<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Events\Manager;

use UnitTester;

class GetResponsesCest
{
    /**
     * Tests Phalcon\Events\Manager :: getResponses()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function eventsManagerGetResponses(UnitTester $I)
    {
        $I->wantToTest('Events\Manager - getResponses()');

        $I->skipTest('Need implementation');
    }
}
