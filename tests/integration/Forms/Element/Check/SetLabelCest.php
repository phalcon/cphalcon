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

namespace Phalcon\Test\Integration\Forms\Element\Check;

use IntegrationTester;

/**
 * Class SetLabelCest
 */
class SetLabelCest
{
    /**
     * Tests Phalcon\Forms\Element\Check :: setLabel()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementCheckSetLabel(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Check - setLabel()');
        $I->skipTest('Need implementation');
    }
}
