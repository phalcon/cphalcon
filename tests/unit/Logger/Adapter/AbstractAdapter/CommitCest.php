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

namespace Phalcon\Test\Unit\Logger\Adapter\AbstractAdapter;

use UnitTester;

/**
 * Class CommitCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\AbstractAdapter :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterAbstractadapterCommit(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\AbstractAdapter - commit()");
        $I->skipTest("Need implementation");
    }
}
