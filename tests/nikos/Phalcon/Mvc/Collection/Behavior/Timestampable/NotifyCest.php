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

namespace Phalcon\Test\Unit\Mvc\Collection\Behavior\Timestampable;

use UnitTester;

/**
 * Class NotifyCest
 */
class NotifyCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Behavior\Timestampable :: notify()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcCollectionBehaviorTimestampableNotify(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection\Behavior\Timestampable - notify()');
        $I->skipTest('Need implementation');
    }
}
