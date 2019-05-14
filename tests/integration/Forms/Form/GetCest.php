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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;

/**
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Forms\Form :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsFormGet(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - get()');
        $I->skipTest('Need implementation');
    }
}
