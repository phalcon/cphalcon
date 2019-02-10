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
 * Class ReleaseCest
 */
class ReleaseCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk\Job :: release()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function queueBeanstalkJobRelease(UnitTester $I)
    {
        $I->wantToTest('Queue\Beanstalk\Job - release()');
        $I->skipTest('Need implementation');
    }
}
