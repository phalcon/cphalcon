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

namespace Phalcon\Test\Unit\Queue\Beanstalk\Job;

use UnitTester;

/**
 * Class StatsCest
 */
class StatsCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk\Job :: stats()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function queueBeanstalkJobStats(UnitTester $I)
    {
        $I->wantToTest('Queue\Beanstalk\Job - stats()');
        $I->skipTest('Need implementation');
    }
}
