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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;

/**
 * Class BindCest
 */
class BindCest
{
    /**
     * Tests Phalcon\Forms\Form :: bind()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormBind(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - bind()');
        $I->skipTest('Need implementation');
    }
}
