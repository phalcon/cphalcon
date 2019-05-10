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

namespace Phalcon\Test\Unit\Mvc\Collection;

use UnitTester;

class AppendMessageCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: appendMessage()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionAppendMessage(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection - appendMessage()');

        $I->skipTest('Need implementation');
    }
}
