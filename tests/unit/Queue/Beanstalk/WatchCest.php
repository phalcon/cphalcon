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

namespace Phalcon\Test\Unit\Queue\Beanstalk;

use UnitTester;

/**
 * Class WatchCest
 */
class WatchCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: watch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkWatch(UnitTester $I)
    {
        $I->wantToTest('Queue\Beanstalk - watch()');
        $I->skipTest('Need implementation');
    }
}
