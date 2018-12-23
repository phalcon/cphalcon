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

namespace Phalcon\Test\Integration\Forms\Element\TextArea;

use IntegrationTester;

/**
 * Class GetFormCest
 */
class GetFormCest
{
    /**
     * Tests Phalcon\Forms\Element\TextArea :: getForm()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementTextareaGetForm(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\TextArea - getForm()');
        $I->skipTest('Need implementation');
    }
}
