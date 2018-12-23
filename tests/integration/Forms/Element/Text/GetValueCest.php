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

namespace Phalcon\Test\Integration\Forms\Element\Text;

use IntegrationTester;

/**
 * Class GetValueCest
 */
class GetValueCest
{
    /**
     * Tests Phalcon\Forms\Element\Text :: getValue()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementTextGetValue(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Text - getValue()');
        $I->skipTest('Need implementation');
    }
}
