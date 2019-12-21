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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class FireEventCest
 */
class FireEventCest
{
    /**
     * Tests Phalcon\Mvc\Model :: fireEvent()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFireEvent(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - fireEvent()');
        $I->skipTest('Need implementation');
    }
}
