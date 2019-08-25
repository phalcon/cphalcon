<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;

/**
 * Class AppendMessageCest
 */
class AppendMessageCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: appendMessage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcCollectionAppendMessage(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - appendMessage()');
        $I->skipTest('Need implementation');
    }
}
