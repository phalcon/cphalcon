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

namespace Phalcon\Test\Unit\Queue\Beanstalk\Exception;

use UnitTester;

/**
 * Class GetMessageCest
 */
class GetMessageCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk\Exception :: getMessage()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function queueBeanstalkExceptionGetMessage(UnitTester $I)
    {
        $I->wantToTest('Queue\Beanstalk\Exception - getMessage()');
        $I->skipTest('Need implementation');
    }
}
